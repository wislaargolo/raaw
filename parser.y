%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./lib/record.h"
#include "./lib/stack.h"
#include "./lib/functions.h"
#include "./lib/variables.h"
#include "./lib/aux_functions.h"
#include "./lib/types.h"


int yylex(void);
int yyerror(char *s);
void non_constant_expr(char* name);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;


char* type_name;
int ptr_count = 0;
function_data *current_fd = NULL;
int const_mode = 0;
int inside_struct = 0;

char* switch_type = NULL;

Stack* stack = NULL;

int has_error = 0;
%}

%union {
	char * sValue;      /* string value */
     struct record * rec;
     struct declaration_term_record* decl_term;
     struct type_record* type_rec;
     struct parameter_record* param;
     struct dimensional_record* dimensional_rec;
     struct identifier_ref_record* identifier_ref_rec;
};


%token <sValue> ID PRIM_TYPE INTEGER STRING BOOL REAL CHAR
%token IF ELSE ELSEIF SWITCH CASE DEFAULT
       DO WHILE FOR BREAK CONTINUE RETURN
       NEW DELETE REF VAL CONST VOID
       STRUCT ENUM PTR LIST TYPE
       LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COLON COMMA DOT
       EQUALITY DIFFERENCE ABRACKET_OPEN ABRACKET_CLOSE LESS_THAN_EQUALS MORE_THAN_EQUALS
       ASSIGNMENT ASSIGNMENT_MUL ASSIGNMENT_DIV ASSIGNMENT_MOD ASSIGNMENT_ADD ASSIGNMENT_SUB
       AND ANDC OR ORC NOT PLUS MINUS TIMES SLASH MOD NULLISH


%type <sValue> unary_operator mult_operator add_operator ineq_operator eq_operator
               and_operator or_operator assignment_operator

%type <rec> literal target base expr val function_call postfix_expr cast prefix_expr term
          arithmetic_expr relational_expr eq_expr and_expr or_expr deletion
            assignment_expr assignment_command allocation assignment
            parameters cases case case_item default statements switch for_init for var_declaration type_declaration
            do_while while else else_opt else_if else_ifs else_ifs_opt if return return_value
            command jump statement const_declaration parameter user_type subprogram subprograms
            struct_vars struct_type enum_list enum_type declaration struct_var_declaration
            declarations program default_opt const_parameter parameter_type

%type <dimensional_rec> initialization initialization_list

%type <identifier_ref_rec> identifier_ref assignable

%type <decl_term> declaration_term declaration_line declaration_item struct_declaration_line

%type <type_rec> type ptr_type list_type

%type <param> parameters_call

%start program


%%
program : { stack = create_stack(); } declarations subprograms   {
                                                                      if(!has_function("main")) {
                                                                           yyerror("Program must define a ‘main’ function as its entry point");
                                                                      }

                                                                      if (!has_error) {
                                                                           fprintf(yyout,"#include \"./raaw/header.h\"\n\n%s%s", $2->code, $3->code);
                                                                      }

                                                                      free_record($2);
                                                                      free_record($3);
                                                                      free_stack(stack);
                                                                 }
        ;


declarations :                           { $$ = create_record("", ""); }
             | declarations declaration  {
                                             char *s = cat(2, $1->code, $2->code);
                                             free_record($1);
                                             free_record($2);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
             ;

declaration : var_declaration                                                                       { $$ = $1; }
            | const_declaration                                                                     { $$ = $1; }
            | type_declaration                                                                      { $$ = $1; }
            ;

var_declaration : type declaration_line SEMICOLON  {
                                                       char *s = strdup("");

                                                       declaration_term_record* decl = $2;
                                                       char* type = strdup($1->name);
                                                       while (decl != NULL) {

                                                            if ($2->init_type != NULL && !type_check(type, $2->init_type)) {
                                                                 yyerror(cat(4, "Invalid type: expected ", type, ", received ", $2->init_type));
                                                            }

                                                            for (int i = 0; i < decl->dimension; i++) {
                                                                 char* aux = type;
                                                                 type = cat(2, aux, "[]");
                                                                 free(aux);
                                                            }

                                                            if(strcmp(stack->top->name, "") == 0 && has_type(decl->name)) {
                                                                 yyerror(cat(3, "Type ", decl->name, " has already been declared."));
                                                            }

                                                            if(insert_variable(stack, decl->name, type, const_mode) == 1) {
                                                                 yyerror(cat(4, "Variable '", decl->name, "' already declared in scope ", stack->top->name));
                                                            }

                                                            char* aux = s;
                                                            s = cat(5, $1->code, " ", decl->code, ";\n", aux);
                                                            free(aux);

                                                            free(decl->name);
                                                            free(decl->code);
                                                            decl = decl->next;
                                                       }

                                                       $$ = create_record(s, type);
                                                       free($1->code);
                                                       free($1->name);
                                                       free(s);
                                                       const_mode = 0;
                                                  }
               ;

const_declaration : CONST { const_mode = 1; } var_declaration {

                                             char *s = cat(2, "const ", $3->code);
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
              ;

type_declaration : TYPE ID    {
                                   if (has_type($2)) {
                                        yyerror(cat(3, "Type '", $2, "' already declared"));
                                   } else if(exists_in_scope(stack, $2) == 1) {
                                        yyerror(cat(3, "Variable '", $2, "' already declared"));
                                   }
                                   type_name = strdup($2);
                              }
                   ASSIGNMENT user_type SEMICOLON  {
                                                            char* s = cat(5, "typedef ", $5->code, " ", $2, ";\n");
                                                            free($2);
                                                            free_record($5);
                                                            $$ = create_record(s, "");
                                                            free(s);
                                                            free(type_name);
                                                            type_name = NULL;
                                                       }
                 ;

declaration_line : declaration_item                         { $$ = $1; }
                 | declaration_line COMMA declaration_item  {
                                                                 $$ = $3;
                                                                 $$->next = $1;
                                                            }
                 ;

declaration_item : declaration_term                              { $$ = $1; }
                 | declaration_term ASSIGNMENT initialization    {
                                                                      if ($1->dimension != $3->dimension) {
                                                                           yyerror("Invalid dimension in variable initialization");
                                                                      }

                                                                      char *s = cat(3, $1->code, " = ", $3->code);
                                                                      free($1->code);
                                                                      $$ = $1;
                                                                      $$->code = s;
                                                                      $$->init_type = strdup($3->type);
                                                                      free($3->code);
                                                                      free($3->type);
                                                                 }
                 ;

declaration_term : ID                                       {
                                                                 $$ = (declaration_term_record*) malloc((sizeof(declaration_term_record)));
                                                                 $$->code = strdup($1);
                                                                 $$->name = strdup($1);
                                                                 $$->dimension = 0;
                                                                 $$->init_type = NULL;
                                                                 $$->next = NULL;
                                                                 free($1);
                                                            }
                 | declaration_term LBRACKET expr RBRACKET  {
                                                                 char *s = cat(4, $1->code, "[", $3->code,"]");
                                                                 free($1->code);
                                                                 free_record($3);
                                                                 $$ = $1;
                                                                 $$->dimension++;
                                                                 $$->code = s;
                                                                 $$->init_type = NULL;
                                                            }
                 ;

initialization : expr    {
                              $$ = (dimensional_record*) malloc(sizeof(dimensional_record));
                              $$->type = strdup($1->type);
                              $$->dimension = 0;

                              if (strcmp($1->type, "string") == 0) {
                                   $$->code = cat(3, "strDup(", $1->code, ")");
                              } else {
                                   $$->code = strdup($1->code);
                              }

                              free_record($1);
                         }
               | LBRACE initialization_list RBRACE  {
                         $$ = (dimensional_record*) malloc(sizeof(dimensional_record));
                         char *s = cat(3, "{", $2->code, "}\n");
                         $$->code = s;
                         $$->type = strdup($2->type);
                         $$->dimension = $2->dimension + 1;
                         free($2->code);
                         free($2->type);
                    }
               | allocation                                                                         {
                    non_constant_expr("allocation");
                    $$ = (dimensional_record*) malloc(sizeof(dimensional_record));
                    $$->code = strdup($1->code);
                    $$->type = strdup($1->type);
                    $$->dimension = 0;
                    free_record($1);
               }
               ;

initialization_list : initialization                                                                { $$ = $1; }
                    | initialization_list COMMA initialization   {
                                                                      if (!type_check($1->type, $3->type)) {
                                                                           yyerror(cat(4, "Invalid type: expected ", $1->type, ", received ", $3->type));
                                                                      }

                                                                      if ($1->dimension != $3->dimension) {
                                                                           yyerror("Invalid dimension in variable initialization");
                                                                      }

                                                                      $$ = (dimensional_record*) malloc(sizeof(dimensional_record));
                                                                      char *s = cat(3, $1->code, ", ", $3->code);
                                                                      $$->code = s;
                                                                      $$->type = strdup($1->type);
                                                                      $$->dimension = $1->dimension;
                                                                      free($1->code);
                                                                      free($1->type);
                                                                      free($3->code);
                                                                      free($3->type);
                                                                 }
                    ;

allocation : NEW type LBRACKET expr RBRACKET {
                                                  char *s = cat(7,
                                                       "(", $2->code, "*) malloc(sizeof(", $2->code, ") * ", $4->code, ")"
                                                  );
                                                  char *type = cat(3, "ptr<", $2->code, ">");
                                                  free($2->code);
                                                  free_record($4);
                                                  $$ = create_record(s, type);
                                                  free(s);
                                                  free(type);
                                             }
           ;

type : PRIM_TYPE    {
                         $$ = (type_record*) malloc(sizeof(type_record));
                         if (strcmp($1, "file") == 0) {
                              $$->code = strdup("FILE*");
                              $$->name = strdup("file");
                         } else if (strcmp($1, "string") == 0) {
                              $$->code = strdup("char*");
                              $$->name = strdup("string");
                         } else {
                              /* demais primitivos continuam iguais */
                              $$->code = strdup($1);
                              $$->name = strdup($1);
                         }
                         free($1);
                    }
     | ptr_type     { $$ = $1; }
     | list_type    { $$ = $1; }
     | ID {
               if (type_name != NULL && strcmp(type_name, $1) == 0) {
                    if (!inside_struct) {
                         yyerror(cat(3, "Forbidden recursive reference outside struct on type '", $1, "'"));
                    } else if (ptr_count == 0) {
                         yyerror(cat(3, "Forbidden recursive reference without ptr on type '", $1, "'"));
                    }

                    $$ = (type_record*) malloc(sizeof(type_record));
                    $$->code = cat(2, "struct ", $1);
                    $$->name = strdup($1);
               } else {
                    if (!has_type($1)) {
                         yyerror(cat(3, "Type '", $1, "' not declared"));
                    }

                    $$ = (type_record*) malloc(sizeof(type_record));
                    $$->code = strdup($1);
                    $$->name = strdup($1);
               }

               free($1);
          }
     ;

user_type : enum_type    { $$ = $1; }
          | struct_type  { $$ = $1; }
          ;

ptr_type : PTR { ptr_count += 1; } ABRACKET_OPEN type ABRACKET_CLOSE       {
                                                            $$ = (type_record*) malloc(sizeof(type_record));
                                                            $$->code = cat(2, $4->code, "*");
                                                            $$->name = cat(3, "ptr<", $4->name, ">");
                                                            free($4->code);
                                                            free($4->name);
                                                            ptr_count -= 1;
                                                       }
         ;

list_type : LIST ABRACKET_OPEN type ABRACKET_CLOSE {
                                                       $$ = (type_record*) malloc(sizeof(type_record));
                                                       $$->code = strdup("list");
                                                       $$->name = cat(3, "list<", $3->name, ">");
                                                       free($3->code);
                                                       free($3->name);
                                                  }
          ;

enum_type : ENUM { insert_enum_type(type_name); } LBRACE enum_list RBRACE     {
                                                  char *s = cat(5, "enum ", type_name," {", $4->code, "}\n");
                                                  free_record($4);
                                                  $$ = create_record(s, "");
                                                  free(s);
                                             }
          ;

enum_list : ID {
                    insert_enum_attr(type_name, $1);
                    char* s = cat(3, type_name, "__", $1);
                    $$ = create_record(s, "");
                    free(s);
                    free($1);
               }

          | enum_list COMMA ID  {
                                   insert_enum_attr(type_name, $3);
                                   char *s = cat(5, $1->code, ", ", type_name, "__", $3);
                                   free_record($1);
                                   free($3);
                                   $$ = create_record(s, "");
                                   free(s);
                                }
          ;

struct_type : STRUCT {

                         insert_struct_type(type_name);
                         inside_struct = 1;

                    } LBRACE struct_vars RBRACE {
                                                  char *s = cat(5, "struct ", type_name, " {", $4->code, "}\n");
                                                  free_record($4);
                                                  $$ = create_record(s, "");
                                                  free(s);
                                                  inside_struct = 0;
                                               }
            ;

struct_vars : struct_var_declaration             { $$ = $1; }
            | struct_vars struct_var_declaration {
                                             char *s = cat(2, $1->code, $2->code);
                                             free_record($1);
                                             free_record($2);
                                             $$ = create_record(s, "");
                                             free(s);
                                          }
            ;

struct_var_declaration : type struct_declaration_line SEMICOLON  {
                                                       char *s = cat(4, $1->code, " ", $2->code, ";");

                                                       declaration_term_record* decl = $2;

                                                       while (decl != NULL) {
                                                            char* type = strdup($1->name);

                                                            for (int i = 0; i < decl->dimension; i++) {
                                                                 char* aux = type;
                                                                 type = cat(2, aux, "[]");
                                                                 free(aux);
                                                            }

                                                            if (struct_has_attr(type_name, decl->name)) {
                                                                 yyerror(cat(3, "Attribute '", decl->name, "' declared twice or more in struct"));
                                                            }

                                                            insert_struct_attr(type_name, decl->name, type);

                                                            free(decl->name);
                                                            free(decl->code);
                                                            decl = decl->next;
                                                       }

                                                       $$ = create_record(s, "");
                                                       free($1->code);
                                                       free($1->name);
                                                       free(s);
                                                  }
               ;

struct_declaration_line : declaration_term                         { $$ = $1; }
                 | declaration_term COMMA declaration_term  {
                                                                 char *s = cat(3, $1->code, ", ", $3->code);
                                                                 free($1->code);
                                                                 free($3->code);
                                                                 $$ = $3;
                                                                 $$->code = s;
                                                                 $$->next = $1;
                                                            }
                 ;

subprograms : subprogram                {
                                             char* s = cat(2, $1->code, "\n");
                                             free_record($1);
                                             $$ = create_record(s, "");
                                             current_fd = NULL;
                                             free(s);
                                        }
            | subprograms subprogram    {
                                             char *s = cat(3, $1->code, "\n", $2->code);
                                             free_record($1);
                                             free_record($2);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
            ;

subprogram : type ID LPAREN   {
                                   if(exists_in_scope(stack, $2)) {
                                        yyerror(cat(3, "Variable ", $2, " has already been declared."));
                                   } else if(has_type($2)) {
                                        yyerror(cat(3, "Type ", $2, " has already been declared."));
                                   }

                                   if(insert_function($2, $1->name, &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already been declared."));
                                   } else if (strcmp($2, "main") == 0) {
                                        yyerror("Main function must return void and not have parameters");
                                   }
                                   push_subprogram(stack, $2);

                              } parameters RPAREN LBRACE statements RBRACE {

                                   char *s = cat(8, $1->code, " ", $2, "(", $5->code, ") {\n", $8->code, "\n}\n");
                                   free($1->code);
                                   free($1->name);
                                   //free($1);
                                   free($2);
                                   free_record($5);
                                   free_record($8);
                                   $$ = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
           | VOID ID LPAREN   {
                                   if(exists_in_scope(stack, $2)) {
                                        yyerror(cat(3, "Variable ", $2, " has already been declared."));
                                   } else if(has_type($2)) {
                                        yyerror(cat(3, "Type ", $2, " has already been declared."));
                                   }

                                   if(insert_function($2, strdup("void"), &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already been declared."));
                                   } else if (strcmp($2, "main") == 0) {
                                        yyerror("Main function must not have parameters");
                                   }
                                   push_subprogram(stack, $2);
                              } parameters RPAREN LBRACE statements RBRACE {
                                   char *s = cat(7, "void ", $2, "(", $5->code, ") {\n", $8->code, "\n}\n");
                                   free($2);
                                   free_record($5);
                                   free_record($8);
                                   $$ = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
           | type ID LPAREN   {

                              if(exists_in_scope(stack, $2)) {
                                   yyerror(cat(3, "Variable ", $2, " has already been declared."));
                              } else if(has_type($2)) {
                                   yyerror(cat(3, "Type ", $2, " has already been declared."));
                              }

                              if(insert_function($2, $1->name, &current_fd) == 1) {
                                   yyerror(cat(3, "Function ", $2, " has already been declared."));
                              } else if (strcmp($2, "main") == 0) {
                                   yyerror("Main function must return void");
                              }

                              push_subprogram(stack, $2);
                              } RPAREN LBRACE statements RBRACE  {
                                   char *s = cat(6, $1->code, " ", $2, "() {\n", $7->code, "\n}\n");
                                   free($1->code);
                                   free($1->name);
                                   free($2);
                                   free_record($7);
                                   $$ = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
           | VOID ID LPAREN   {
                                   if(exists_in_scope(stack, $2)) {
                                        yyerror(cat(3, "Variable ", $2, " has already been declared."));
                                   } else if(has_type($2)) {
                                        yyerror(cat(3, "Type ", $2, " has already been declared."));
                                   }

                                   if(insert_function($2, strdup("void"), &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already been declared."));
                                   }

                                   push_subprogram(stack, $2);
                              } RPAREN LBRACE statements RBRACE  {
                                   char *s;

                                   if (strcmp($2, "main") == 0) {
                                        s = cat(5, "int ", $2, "() {\n", $7->code, "\nreturn 0;\n}\n");
                                   } else {
                                        s = cat(5, "void ", $2, "() {\n", $7->code, "\n}\n");
                                   }

                                   free($2);
                                   free_record($7);
                                   $$ = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
           ;

parameters : parameter_type                  { $$ = $1; }
           | parameters COMMA parameter_type {
                                             char *s = cat(3, $1->code, ", ", $3->code);
                                             free_record($1);
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
           ;

parameter_type : parameter                   { $$ = $1; }
               | const_parameter             { $$ = $1; }
               ;

parameter : type ID {
                         if(has_type($2)) {
                              yyerror(cat(3, "Type ", $2, " has already been declared."));
                         }

                         if(insert_variable(stack, $2, $1->name, const_mode) == 1) {
                              yyerror(cat(3, "Variable ", $2, " already declared on scope."));
                         }

                         new_param(current_fd, $1->name);
                         //  parametro pode ser constante
                         char *s = cat(3, $1->code, " ", $2);
                         free($1->code);
                         free($1->name);
                         //free($1);
                         free($2);
                         $$ = create_record(s, "");
                         const_mode = 0;
                         free(s);
                    }
          ;
          ;

const_parameter : CONST {const_mode = 1; } parameter  {
                                                            char *s = cat(2, "const ", $3->code);
                                                            free($3->code);
                                                            $$ = create_record(s, "");
                                                            free(s);
                                                       }
                ;

statements : statement   {
                              char *s = cat(3, "\n", $1->code, "\n");
                              free_record($1);
                              $$ = create_record(s, "");
                              free(s);
                         }
           | statements statement {
                                        char *s = cat(3, $1->code, "\n", $2->code);
                                        free_record($1);
                                        free_record($2);
                                        $$ = create_record(s, "");
                                        free(s);
                                   }
           ;

statement : var_declaration                                                                         { $$ = $1; }
          | const_declaration                                                                       { $$ = $1; }
          | command                                                                                 { $$ = $1; }
          | assignment_command                                                                      { $$ = $1; }
          ;

command : if                                                                                        { $$ = $1; }
        | while                                                                                     { $$ = $1; }
        | do_while                                                                                  { $$ = $1; }
        | for                                                                                       { $$ = $1; }
        | switch                                                                                    { $$ = $1; }
        | function_call SEMICOLON {
                                        char *s = cat(2, $1->code, ";");
                                        free_record($1);
                                        $$ = create_record(s, "");
                                        free(s);
                                  }
        | jump SEMICOLON          {
                                        char *s = cat(2, $1->code, ";");
                                        free_record($1);
                                        $$ = create_record(s, "");
                                        free(s);
                                  }
        | deletion                                                                                  { $$ = $1; }
        ;

jump : CONTINUE                                                                                     {
                                                                                                         ScopeNode* top = stack->top;
                                                                                                         char *s;
                                                                                                         if (!top->is_loop || top->continue_label == NULL) {
                                                                                                              s = "";
                                                                                                              yyerror("Invalid continue outside loop");
                                                                                                         } else {
                                                                                                              s = cat(2, "goto ", top->continue_label);
                                                                                                         }
                                                                                                         $$ = create_record(s, "");
                                                                                                         free(s);
                                                                                                    }
     | BREAK                                                                                        {
                                                                                                         ScopeNode* top = stack->top;
                                                                                                         char *s;
                                                                                                         if ((!top->is_loop && !top->is_switch) || top->break_label == NULL) {
                                                                                                              s = "";
                                                                                                              yyerror("Invalid break outside loop or switch");
                                                                                                         } else {
                                                                                                              s = cat(2, "goto ", top->break_label);
                                                                                                         }
                                                                                                         $$ = create_record(s, "");
                                                                                                         free(s);
                                                                                                    }
     | return                                                                                       { $$ = $1; }
     ;

return : RETURN return_value  {
                                   char *s = cat(2, "return ", $2->code);
                                   if (current_fd == NULL) {
                                        yyerror("'return' statement outside a function.");
                                   } else {
                                        char* expected_type = current_fd->return_type;
                                        char* actual_type = $2->type;

                                        if (type_check(expected_type, "void")) {
                                            if (!type_check(actual_type, "void")) {
                                                yyerror("Function declared as 'void' should not return a value.");
                                            }
                                        } else {
                                            if (type_check(actual_type, "void")) {
                                                yyerror(cat(3, "Function returning '", expected_type, "' requires a return value, but none was provided."));
                                            } else if (!type_check(actual_type, expected_type)) {
                                                yyerror(cat(5, "Incompatible return type. Expected '", expected_type, "', found '", actual_type, "'."));
                                            }
                                        }
                                   }
                                   free_record($2);
                                   $$ = create_record(s, "");
                                   free(s);
                              }
       ;

return_value :                                                                                      { $$ = create_record("", "void"); }
             | expr                                                                                 { $$ = $1; }
             ;

if : IF LPAREN expr {
                         if (!type_check($3->type, "boolean")) {
                              yyerror(cat(3, "Condition 'if' requires boolean type, but '",  $3->type, "' was found."));
                         }
                    } RPAREN LBRACE  {
                                        push(stack, 0, 0);
                                        ScopeNode* top = stack->top;
                                        top->if_end_label = cat(2, top->name, "_end");
                                   } statements RBRACE else_ifs_opt else_opt  {

                                        ScopeNode* top = stack->top;
                                        char* next_else = cat(2, top->name, "_else");
                                        char* else_chain = cat(2, $10->code, $11->code);

                                        char* final_code;

                                        if (strlen(else_chain) > 0) {
                                             final_code = cat(17,
                                                  "if (!(", $3->code, ")) goto ", next_else, ";\n",
                                                  "{", $8->code, "\n}\n",
                                                  "goto ", top->if_end_label, ";\n",
                                                  next_else, ":\n",
                                                  else_chain, "\n",
                                                  top->if_end_label, ":"
                                             );
                                        } else {
                                             final_code = cat(10,
                                                  "if (!(", $3->code, ")) goto ", top->if_end_label, ";\n",
                                                   "{", $8->code, "\n}\n",
                                                  top->if_end_label, ":"
                                             );
                                        }

                                        free_record($3);
                                        free_record($8);
                                        free_record($10);
                                        free_record($11);
                                        free(next_else);
                                        free(else_chain);
                                        $$ = create_record(final_code, "");
                                        free(final_code);
                                        pop(stack);
                                   }
   ;

else_ifs_opt :                                                                                      { $$ = create_record("", ""); }
             | else_ifs                                                                             { $$ = $1; }
             ;

else_ifs : else_if                                                                                  { $$ = $1; }
         | else_ifs else_if   {
                                   char *s = cat(3, $1->code, " ", $2->code);
                                   free_record($1);
                                   free_record($2);
                                   $$ = create_record(s, "");
                                   free(s);
                              }
         ;

else_if : ELSEIF LPAREN expr {

                                   if (!type_check($3->type, "boolean")) {
                                        yyerror(cat(3, "Condition 'else if' requires boolean type, but '", $3->type, "' was found."));
                                   }
                             } RPAREN LBRACE { push(stack, 0, 0); } statements RBRACE       {
                                                                                               ScopeNode* top = stack->top;
                                                                                               char* next_else = cat(2, top->name, "_next");

                                                                                               char* s = cat(13,
                                                                                                    "if (!(", $3->code, ")) goto ", next_else, ";\n",
                                                                                                    "{", $8->code, "\n}\n",
                                                                                                    "goto ", top->if_end_label, ";\n",
                                                                                                    next_else, ":"
                                                                                               );
                                                                                               free_record($3);
                                                                                               free_record($8);
                                                                                               free(next_else);
                                                                                               $$ = create_record(s, "");
                                                                                               free(s);
                                                                                               pop(stack);
                                                                                          }

else_opt :          { $$ = create_record("", ""); }
         | else     { $$ = $1; }
         ;

else : ELSE LBRACE { push(stack, 0, 0); } statements RBRACE    {
                                             char* s = cat(3, "{", $4->code, "\n}\n");
                                             free_record($4);
                                             $$ = create_record(s, "");
                                             free(s);
                                             pop(stack);
                                        }
     ;

while : WHILE LPAREN expr {
                              if (!type_check($3->type, "boolean")) {
                                   yyerror(cat(3, "Condition 'while' requires boolean type, but '", $3->type, "' was found."));
                              }
                         } RPAREN LBRACE {
                                             push(stack, 1, 0);
                                             ScopeNode* top = stack->top;
                                             top->break_label = cat(2, top->name, "_end");
                                             top->continue_label = strdup(top->name);

                                        } statements RBRACE {

                                             ScopeNode* top = stack->top;
                                             char* s = cat(16,
                                                  "\n", top->name, ":\n",
                                                  "if (!(", $3->code, ")) goto ", top->break_label, ";\n",
                                                  "{", $8->code, "\n",
                                                  "goto ", top->name, ";\n}\n",
                                                  top->break_label, ":"
                                             );
                                             free_record($3);
                                             free_record($8);
                                             $$ = create_record(s, "");
                                             free(s);
                                             pop(stack);
                                        }
      ;

do_while : DO LBRACE  {
                         push(stack, 1, 0);
                         ScopeNode* top = stack->top;
                         top->break_label = cat(2, top->name, "_end");
                         top->continue_label = strdup(top->name);
                    } statements RBRACE WHILE LPAREN expr RPAREN  {
                         if (!type_check($8->type, "boolean")) {
                             yyerror(cat(3, "Condition 'do-while' requires boolean type, but '", $8->type, "' was found."));
                         }

                         ScopeNode* top = stack->top;
                         char *s = cat(13,
                              "\n", top->name, ":\n",
                              "{", $4->code, "\n}\n",
                              "if (", $8->code, ") goto ", top->name, ";\n",
                              top->break_label, ":"
                         );

                         free_record($4);
                         free_record($8);
                         $$ = create_record(s, "");
                         free(s);
                         pop(stack);
                    }
         ;

for : FOR LPAREN {
                    push(stack, 1, 0);
                    ScopeNode* top = stack->top;
                    top->break_label = cat(2, top->name, "_end");
                    top->continue_label = cat(2, top->name, "_continue");

               } for_init expr {
                    if (!type_check($5->type, "boolean")) {
                        yyerror(cat(3, "Condition 'for' requires boolean type, but '", $5->type, "' was found."));
                    }
               } SEMICOLON assignment RPAREN LBRACE statements RBRACE  {
                    ScopeNode* top = stack->top;

                    char* s = cat(20,"\n{\n",
                         $4->code, "\n",
                         top->name, ":\n",
                         "if (!(", $5->code, ")) goto ", top->break_label, ";\n",
                         $11->code,
                         top->continue_label, ":\n",
                         $8->code, ";\n",
                         "goto ", top->name, ";\n}\n",
                         top->break_label, ":"
                    );

                    free_record($4);
                    free_record($5);
                    free_record($8);
                    free_record($11);
                    $$ = create_record(s, "");
                    free(s);
                    pop(stack);
               }
    ;

for_init : assignment_command                                                                       { $$ = $1; }
         | var_declaration                                                                          { $$ = $1; }
         ;

switch : SWITCH LPAREN expr RPAREN LBRACE {
                                             push(stack, 0, 1);
                                             ScopeNode* top = stack->top;
                                             top->break_label = cat(2, top->name, "_end");
                                             switch_type = strdup($3->type);

                                        } cases default_opt RBRACE   {
                                             ScopeNode* top = stack->top;
                                             char *s = cat(10,
                                                  "switch (", $3->code, ") {\n",
                                                  $7->code, "\n",
                                                  $8->code, "\n",
                                                  "}\n",
                                                  top->break_label, ":"
                                             );
                                             free_record($3);
                                             free_record($7);
                                             free_record($8);
                                             $$ = create_record(s, "");
                                             free(s);
                                             pop(stack);
                                             free(switch_type);
                                             switch_type = NULL;
                                        }
       ;

default_opt :          { $$ = create_record("", ""); }
            | default  { $$ = $1; }
            ;

cases : case        { $$ = $1; }
      | cases case  {
                         char *s = cat(3, $1->code, "\n", $2->code);
                         free_record($1);
                         free_record($2);
                         $$ = create_record(s, "");
                         free(s);
                    }
      ;

case : CASE case_item    {
                              char *s = cat(2, "case ", $2->code);
                              free_record($2);
                              $$ = create_record(s, "");
                              free(s);
                         }
     ;

default : DEFAULT COLON statements {
                                        char *s = cat(2,"default: ", $3->code);
                                        free_record($3);
                                        $$ = create_record(s, "");
                                        free(s);
                                   }
        ;

case_item : literal                          {if (strcmp($1->type, switch_type) != 0) {
                                                  yyerror("Literal type in case does not match switch type");
                                             }

                                             } COLON statements    {
                                             char *s = cat(3, $1->code, ":", $4->code);
                                             free_record($1);
                                             free_record($4);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
          ;


function_call : ID LPAREN RPAREN   {
                                        if(!has_function($1)) {
                                             char *s = cat(2, $1, "()");
                                             yyerror(cat(3, "Invalid call: ", $1, " is not declared"));
                                             $$ = create_record(s, "");
                                             free(s);
                                        } else {
                                             if (!strcmp($1,"print") || !strcmp($1,"printLine")) {
                                                  $$ = build_printf(NULL, !strcmp($1,"printLine"));
                                             } else {
                                                  $$ = build_function_call($1, NULL);
                                                  $$->type = get_function_return_type($1);
                                             }
                                        }

                                        free($1);

                                   }
              | ID LPAREN parameters_call RPAREN  {
                                                  if(!has_function($1)) {
                                                       char *s = cat(4, $1, "(", $3->code, ")");
                                                       yyerror(cat(3, "Invalid call: ", $1, " is not declared"));
                                                       $$ = create_record(s, "");
                                                       free(s);
                                                  } else {
                                                       if (!strcmp($1,"print") || !strcmp($1,"printLine")) {
                                                            $$ = build_printf($3, !strcmp($1,"printLine"));
                                                       } else {
                                                            int is_gen_list_function = is_list_function($1, $3);
                                                            char* gen_type = NULL;

                                                            if (is_gen_list_function) {
                                                                 gen_type = get_list_type($3->type);
                                                            }

                                                            function_data fdata = get_function($1);

                                                            if (fdata.num_params != num_params($3)) {
                                                                 yyerror(cat(3, "Invalid call: incompatible number of arguments for function ", $1, "."));
                                                            } else {
                                                                 function_param* formal = fdata.params;
                                                                 parameter_record* curr = $3;
                                                                 int pos = 0;

                                                                 while(formal != NULL && curr != NULL) {
                                                                      char pos_str[12];
                                                                      sprintf(pos_str, "%d", pos);
                                                                      char* formal_type = formal->type;

                                                                      if (gen_type != NULL && strcmp(formal_type, "_") == 0) {
                                                                           formal_type = gen_type;
                                                                      }

                                                                      if(!type_check(formal_type, curr->type)) {
                                                                           yyerror(cat(8, "Invalid call: argument ", pos_str,  " of function ", $1, " expected ", formal_type, ", received ", curr->type));
                                                                      }
                                                                      formal = formal->next;
                                                                      curr = curr->next;
                                                                      pos++;
                                                                 }
                                                            }


                                                            $$ = build_function_call($1, $3);
                                                            $$->type = get_function_return_type($1);

                                                            free(gen_type);
                                                       }
                                                  }
                                                  free($1);
                                                  if ($3) free_param($3);


                                                  }
              ;

parameters_call : expr                                       {
                                                                 $$ = create_param($1->code, $1->type);
                                                                 free_record($1);
                                                             }
                | parameters_call COMMA expr                 {
                                                                 $$ = add_param($1, create_param($3->code, $3->type));
                                                                 free_record($3);
                                                             }
                ;

assignment : assignable assignment_operator assignment_expr  {
                                                                char * s_code;
                                                                char * assigned_type = strdup($1->type);

                                                                if(is_const_variable(stack, $1->code)) {
                                                                      yyerror(cat(3, "Invalid operator: cannot assign to constant variable ", $1->code, "."));
                                                                      s_code = strdup("");
                                                                }

                                                                if (type_check(assigned_type, "string")) {

                                                                    if (strcmp($2, " = ") == 0) {
                                                                      s_code = cat(5, $1->code, $2, "strDup(", $3->code, ")");
                                                                    }

                                                                    else if (strcmp($2, " += ") == 0) {
                                                                      s_code = cat(6, $1->code, " = strConcat(", $1->code, ", ", $3->code, ")");
                                                                    }
                                                                    else {
                                                                      yyerror(cat(3, "Invalid operator '", $2, "' for string assignment."));
                                                                      s_code = strdup("");
                                                                    }
                                                                } else {
                                                                    if (strcmp($2, " = ") != 0) {
                                                                      if (!type_check(assigned_type, "int") && !type_check(assigned_type, "float")) {
                                                                           yyerror(cat(2, "Invalid type: expected int or float, received ", $1->type));
                                                                      }
                                                                      s_code = cat(3, $1->code, $2, $3->code);
                                                                    } else if ($1->setter_code != NULL) {
                                                                      s_code = cat(5, $1->setter_code, $3->code, ", ", translate_type($3->type), ")");
                                                                      free($1->setter_code);
                                                                    } else {
                                                                      s_code = cat(3, $1->code, $2, $3->code);
                                                                    }
                                                                }

                                                                if (!type_check($1->type, $3->type)) {
                                                                      yyerror(cat(4, "Invalid type: expected ", $1->type , " , received ", $3->type));
                                                                 }

                                                                $$ = create_record(s_code, assigned_type);
                                                                free($1->code);
                                                                free($1->type);
                                                                free($2);
                                                                free_record($3);
                                                                free(s_code);
                                                                free(assigned_type);
                                                             }
           ;

assignment_command : assignment SEMICOLON {
                                             char *s = cat(2, $1->code, ";");
                                             free_record($1);
                                             $$ = create_record(s, "");
                                             free(s);
                                          }
                   ;

assignable : identifier_ref        {
                                         $$ = $1;

                                        if ($1->ref_code != NULL) {
                                             free($$->ref_code);
                                        }

                                         if (is_array($1->type)) {
                                              yyerror("Invalid assignment to array");
                                         }
                                   }

            ;

val : VAL LPAREN expr RPAREN     {
                                        char *s = cat(3, "(*", $3->code, ")");

                                        char* type;

                                        if(!is_ptr($3->type)) {
                                             yyerror(cat(2, "Invalid type: expected ptr, received ", $3->type));
                                             type = strdup("_");
                                        } else {
                                             type = get_ptr_type($3->type);
                                        }

                                        $$ = create_record(s, type);
                                        free_record($3);
                                        free(s);
                                   }
    ;

assignment_operator : ASSIGNMENT                                                                    {$$ = strdup(" = ");}
               | ASSIGNMENT_MUL                                                                     {$$ = strdup(" *= ");}
               | ASSIGNMENT_DIV                                                                     {$$ = strdup(" /= ");}
               | ASSIGNMENT_MOD                                                                     {$$ = strdup(" %= ");}
               | ASSIGNMENT_ADD                                                                     {$$ = strdup(" += ");}
               | ASSIGNMENT_SUB                                                                     {$$ = strdup(" -= ");}
                    ;

assignment_expr : expr                                                                              { $$ = $1; }
                | allocation                                                                        { $$ = $1; }
                ;

deletion : DELETE LPAREN identifier_ref RPAREN SEMICOLON    {

                                                                 if(!is_ptr($3->type)) {
                                                                      yyerror(cat(2, "Invalid type: expected ptr, received ", $3->type));
                                                                 }

                                                                 char * s = cat(5, "free", "(", $3->code, ")", ";");
                                                                 free($3->code);
                                                                 free($3->type);
                                                                 $$ = create_record(s, "");
                                                                 free(s);
                                                            }
         ;

identifier_ref : val                                   {
                                                            $$ = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                                            $$->code = strdup($1->code);
                                                            $$->type = strdup($1->type);
                                                            $$->ref_code = NULL;
                                                            $$->setter_code = NULL;
                                                            free_record($1);
                                                       }
               | ID                                    {
                                                            char* type;
                                                            if (!exists_scope_parent(stack, $1)) {
                                                                 yyerror(cat(3, "Variable '", $1, "' is not declared"));
                                                                 type = strdup("_");
                                                            } else {
                                                                 variable_data var = get_variable(stack, $1);
                                                                 type = strdup(var.type);
                                                            }

                                                            $$ = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                                            $$->code = strdup($1);
                                                            $$->type = type;
                                                            $$->setter_code = NULL;
                                                            $$->ref_code = NULL;
                                                            free($1);
                                                       }
               | identifier_ref LBRACKET expr RBRACKET {
                                                            char* s;
                                                            char* setter_code = NULL;
                                                            char* ref_code = NULL;
                                                            char* type;
                                                            if (is_list($1->type)) {
                                                                 s = cat(5, "_listGet(", $1->code, ", ", $3->code, ")");
                                                                 setter_code = cat(5, "_listSet(&", $1->code, ", ", $3->code, ", ");
                                                                 type = get_list_type($1->type);
                                                                 char* translated_type = translate_type(type);
                                                                 ref_code = cat(7, "((", translated_type, "*)", $1->code, ".data[", $3->code, "])");
                                                                 free(translated_type);
                                                            } else if (is_ptr($1->type)) {
                                                                 s = cat(4, $1->code, "[", $3->code, "]");
                                                                 type = get_ptr_type($1->type);
                                                            } else if (is_array($1->type)) {
                                                                 s = cat(4, $1->code, "[", $3->code, "]");
                                                                 type = get_array_type($1->type);
                                                            } else {
                                                                 yyerror(cat(2, "Invalid type: expected ptr or list, received ", $3->type));
                                                                 type = strdup("_");
                                                            }
                                                            $$ = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                                            $$->code = s;
                                                            $$->setter_code = setter_code;
                                                            $$->ref_code = ref_code;
                                                            $$->type = type;
                                                            free($1->code);
                                                            free($1->type);
                                                            free_record($3);
                                                       }
               | identifier_ref DOT ID  {
                                             char * s = cat(3, $1->code, ".", $3);
                                             char * type;

                                             if(!is_struct($1->type)) {
                                                  yyerror(cat(2, "Invalid type: expected struct, received ", $1->type));
                                                  type = strdup("_");
                                             } else if(!struct_has_attr($1->type, $3)) {
                                                  yyerror(cat(2, "Invalid: struct does not have the attribute ", $1->type));
                                                  type = strdup("_");
                                             } else {
                                                  type = get_struct_attr_type($1->type, $3);
                                             }

                                             $$ = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                             $$->code = s;
                                             $$->type = type;
                                             $$->setter_code = NULL;
                                             $$->ref_code = NULL;

                                             free($1->code);
                                             free($1->type);
                                             free($3);
                                        }
               ;

expr : or_expr  { $$ = $1;}
     ;

or_expr : and_expr                     { $$ = $1;}
        | or_expr or_operator and_expr {
                                             if (!type_check($1->type, "boolean")) {
                                                  yyerror(cat(2, "Invalid type: expected boolean, received ", $1->type));
                                             }

                                             if (!type_check($1->type, $3->type)) {
                                                  yyerror(cat(4, "Invalid type: expected ", $1->type , " , received ", $3->type));
                                             }

                                             char * s = cat(3, $1->code, $2, $3->code);
                                             free_record($1);
                                             free($2);
                                             free_record($3);
                                             $$ = create_record(s, "boolean");
                                             free(s);
                                        }
        ;

or_operator : OR                                                                                    {$$ = strdup(" | ");}
            | ORC                                                                                   {$$ = strdup(" || ");}
            ;

and_expr : eq_expr                                {$$ = $1;}
         | and_expr and_operator eq_expr    {
                                                  if (!type_check($1->type, "boolean")) {
                                                       yyerror(cat(2, "Invalid type: expected boolean, received ", $1->type));
                                                  }

                                                  if (!type_check($1->type, $3->type)) {
                                                       yyerror(cat(4, "Invalid type: expected ", $1->type , " , received ", $3->type));
                                                  }

                                                  char * s = cat(3, $1->code, $2, $3->code);
                                                  free_record($1);
                                                  free($2);
                                                  free_record($3);
                                                  $$ = create_record(s, "boolean");
                                                  free(s);
                                             }
          ;

and_operator : AND                                                                                  {$$ = strdup(" & ");}
             | ANDC                                                                                 {$$ = strdup(" && ");}
             ;

eq_expr : relational_expr                                                                           {$$ = $1;}
        | eq_expr eq_operator relational_expr     {
                                                        char *s;

                                                        if (type_check($1->type, "string")) {

                                                            if (strcmp($2, " == ") == 0) {
                                                                s = cat(5, "isEquals(", $1->code, ", ", $3->code, ")");
                                                                $$ = create_record(s, "boolean");

                                                            } else if (strcmp($2, " != ") == 0) {
                                                                s = cat(6, "!", "isEquals(", $1->code, ", ", $3->code, ")");
                                                                $$ = create_record(s, "boolean");

                                                            }
                                                        } else {

                                                            s = cat(3, $1->code, $2, $3->code);
                                                            $$ = create_record(s, "boolean");
                                                        }

                                                       if (!type_check($1->type, $3->type)) {
                                                            yyerror(cat(4, "Invalid type: expected ", $1->type , " , received ", $3->type));
                                                       }

                                                        free_record($1);
                                                        free($2);
                                                        free_record($3);
                                                        free(s);
                                                  }
          ;

eq_operator : EQUALITY                                                                              {$$ = strdup(" == ");}
            | DIFFERENCE                                                                            {$$ = strdup(" != ");}
            ;

relational_expr : arithmetic_expr                               { $$ = $1; }
                | relational_expr ineq_operator arithmetic_expr {

                                                                      if (!type_check($1->type, "int") && !type_check($1->type, "float")) {
                                                                           yyerror(cat(2, "Invalid type: expected int or float, received ", $1->type));
                                                                      }
                                                                       if (!type_check($1->type, $3->type)) {
                                                                           yyerror(cat(4, "Invalid type: expected ", $1->type , " , received ", $3->type));
                                                                      }

                                                                      char * s = cat(3, $1->code, $2, $3->code);
                                                                      free_record($1);
                                                                      free($2);
                                                                      free_record($3);
                                                                      $$ = create_record(s, "boolean");
                                                                      free(s);
                                                                 }
                ;

ineq_operator : ABRACKET_OPEN                   { $$ = strdup(" < "); }
              | MORE_THAN_EQUALS                { $$ = strdup(" >= "); }
              | ABRACKET_CLOSE                  { $$ = strdup(" > "); }
              | LESS_THAN_EQUALS                { $$ = strdup(" <= "); }
              ;

arithmetic_expr : term                                                                              { $$ = $1; }
                | arithmetic_expr add_operator term {
                                                        char * s_code;
                                                        char * result_type = strdup($1->type);

                                                        if (type_check($1->type, "string") && strcmp($2, " + ") == 0) {
                                                            s_code = cat(5, "strConcat(", $1->code, ", ", $3->code, ")");
                                                        } else if (type_check($1->type, "int") || type_check($1->type, "float")) {
                                                            s_code = cat(3, $1->code, $2, $3->code);
                                                        } else {
                                                            yyerror(cat(2, "Invalid type: expected int or float, received ", $1->type));
                                                            s_code = strdup("_");
                                                        }

                                                        if (!type_check($1->type, $3->type)) {
                                                            yyerror(cat(4, "Invalid type: expected ", $1->type , " , received ", $3->type));
                                                            s_code = strdup("_");
                                                        }

                                                        $$ = create_record(s_code, result_type);
                                                        free_record($1);
                                                        free($2);
                                                        free_record($3);
                                                        free(s_code);
                                                        free(result_type);
                                                    }
                ;

term : prefix_expr                                                                               { $$ = $1; }
     | term mult_operator prefix_expr   {
                                             if (strcmp($2, " * ") == 0 || strcmp($2, " / ") == 0) {
                                                  if (!type_check($1->type, "int") && !type_check($1->type, "float")) {
                                                       yyerror(cat(2, "Invalid type: expected int or float, received ", $1->type));
                                                  }
                                             } else {
                                                  if (!type_check($1->type, "int")) {
                                                       yyerror(cat(2, "Invalid type: expected int, received ", $1->type));
                                                  }
                                             }

                                             if (!type_check($1->type, $3->type)) {
                                                  yyerror(cat(4, "Invalid type: expected ", $1->type , " , received ", $3->type));
                                             }

                                             char * s = cat(3, $1->code, $2, $3->code);
                                             $$ = create_record(s, $1->type);
                                             free_record($1);
                                             free($2);
                                             free_record($3);
                                             free(s);
                                        }
     ;

mult_operator : TIMES    { $$ = strdup(" * "); }
              | SLASH    { $$ = strdup(" / "); }
              | MOD      { $$ = strdup(" % "); }
              ;

prefix_expr : postfix_expr                        { $$ = $1; }
            | unary_operator postfix_expr         {
                                                       if (strcmp($1, " + ") == 0 || strcmp($1, " - ") == 0) {
                                                            if (!type_check($2->type, "int") && !type_check($2->type, "float")) {
                                                                 yyerror(cat(2, "Invalid type: expected int or float, received ", $2->type));
                                                            }
                                                       } else {
                                                            if (!type_check($2->type, "boolean")) {
                                                                 yyerror(cat(2, "Invalid type: expected boolean, received ", $2->type));
                                                            }
                                                       }

                                                       char * s = cat(2, $1, $2->code);
                                                       $$ = create_record(s, $2->type);
                                                       free($1);
                                                       free_record($2);
                                                       free(s);
                                                  }
            | REF LPAREN identifier_ref RPAREN   {
                                                       non_constant_expr("reference");
                                                       if(is_const_variable(stack, $3->code)) {
                                                            yyerror(cat(3, "Invalid operator: cannot assign to constant variable ", $3->code, "."));
                                                       }

                                                       char * s;

                                                       if ($3->ref_code != NULL) {
                                                            s = strdup($3->ref_code);
                                                            free($3->ref_code);
                                                       } else {
                                                            s = cat(4,"&","(", $3->code,")");
                                                       }

                                                       if ($3->setter_code != NULL) {
                                                            free($3->setter_code);
                                                       }

                                                       char* type = cat(3, "ptr<", $3->type, ">");
                                                       free($3->code);
                                                       free($3->type);
                                                       $$ = create_record(s, type);
                                                       free(s);
                                                       free(type);
                                                  }
            | cast                                                                                    { $$ = $1; }
            ;

cast : LPAREN PRIM_TYPE RPAREN postfix_expr  {
                                                  if (type_check($2, "float")) {
                                                       if (!type_check($4->type, "int") && !type_check($4->type, "float")) {
                                                            yyerror(cat(3, "Invalid cast from ", $4->type, " to float"));
                                                       }
                                                  } else {
                                                       yyerror(cat(2, "Invalid cast to ", $2));
                                                  }

                                                  char* s = cat(4, "(", translate_type($2), ") ", $4->code);
                                                  $$ = create_record(s, $2);

                                                  free($2);
                                                  free_record($4);
                                             }
     ;

unary_operator : add_operator { $$ = $1; }
               | NOT          { $$ = strdup("!"); }
               ;

add_operator : PLUS      { $$ = strdup(" + "); }
             | MINUS     { $$ = strdup(" - "); }
             ;

postfix_expr : target    {
                              if (is_enum_group($1->type)) {
                                   yyerror("Invalid enum expression");
                              }
                              $$ = $1;
                         }
             | literal   { $$ = $1; }
             ;

base : ID                     {
                                   non_constant_expr("variable access");
                                   if (is_enum($1) & !exists_scope_parent(stack, $1)) {
                                        char* type = cat(3, "enum_group<", $1, ">");

                                        $$ = create_record($1, type);
                                        free(type);
                                   } else if (!exists_scope_parent(stack, $1)) {
                                        yyerror(cat(3, "Variable '", $1, "' is not declared"));
                                        $$ = create_record($1, "_");
                                   } else {
                                        char* type = get_variable_type(stack, $1);

                                        $$ = create_record($1, type);
                                        free(type);
                                   }

                                   free($1);
                              }
     | val                    {
                                   $$ = $1;
                              }
     | LPAREN expr RPAREN     {
                                   char * s = cat(3,"(", $2->code,")");
                                   $$ = create_record(s, $2->type);
                                   free_record($2);
                                   free(s);
                              }
     ;


target : base                           { $$ = $1; }
       | function_call                  {
                                             non_constant_expr("function call");
                                             $$ = $1;
                                        }
       | target LBRACKET expr RBRACKET  {
                                             char* s;
                                             char* type;

                                             if (!type_check($3->type, "int")) {
                                                  yyerror(cat(2, "Invalid type: expected int, received ", $1->type));
                                             }

                                             if (is_list($1->type)) {
                                                 type = get_list_type($1->type);
                                                 s = cat(7, "_listGet(&", $1->code, ", ", $3->code, ", ", translate_type(type), ")");
                                             } else if (type_check($1->type, "string")) {
                                                  s = cat(4, $1->code, "[", $3->code,"]");
                                                  type = strdup("char");
                                             } else if (is_ptr($1->type)) {
                                                  s = cat(4, $1->code, "[", $3->code,"]");
                                                  type = get_ptr_type($1->type);
                                             } else if (is_array($1->type)) {
                                                  s = cat(4, $1->code, "[", $3->code,"]");
                                                  type = get_array_type($1->type);
                                             } else {
                                                  s = cat(4, $1->code, "[", $3->code,"]");
                                                  type = strdup("_");
                                                  yyerror(cat(2, "Invalid type: expected ptr, list, or string, received ", $1->type));
                                             }

                                             $$ = create_record(s, type);
                                             free(s);
                                             free(type);
                                             free_record($1);
                                             free_record($3);

                                        }
       | target DOT ID                  {
                                             if (is_enum_group($1->type)) {
                                                  char* type = get_enum_group_name($1->type);

                                                  if (!enum_has_attr(type, $3)) {
                                                       yyerror(cat(5, "Invalid enum value '", $3, "' for enum '", type, "'"));
                                                  }

                                                  char* s = cat(3, type, "__", $3);

                                                  $$ = create_record(s, type);

                                                  free(type);

                                                  free(s);
                                             } else if(!is_struct($1->type)) {
                                                  yyerror(cat(2, "Invalid type: expected struct, received ", $1->type));
                                             } else if(!struct_has_attr($1->type, $3)) {
                                                  yyerror(cat(2, "Invalid: struct does not have the attribute ", $1->type));
                                             } else {
                                                  char * s = cat(3, $1->code, ".", $3);

                                                  $$ = create_record(s, get_struct_attr_type($1->type, $3));

                                                  free(s);
                                             }

                                             free_record($1);
                                             free($3);

                                        }
       ;


literal : INTEGER   {
                         $$ = create_record($1, "int");
                         free($1);
                    }
        | CHAR      {
                         $$ = create_record($1, "char");
                         free($1);
                    }
        | STRING    {
                         $$ = create_record($1, "string");
                         free($1);
                    }
        | REAL      {
                         $$ = create_record($1, "float");
                         free($1);
                    }
        | BOOL      {
                         $$ = create_record($1, "boolean");
                         free($1);
                    }
        | NULLISH   {
                         $$ = create_record("NULL", "ptr<_>");
                    }
        ;

%%

int main (int argc, char ** argv) {

     int codigo;

     if (argc != 3) {
          printf("Usage: $./compiler input.txt output.txt\nClosing application...\n");
          exit(0);
     }

     init_types_table();
     init_function_table();
     init_variables_table();

     yyin = fopen(argv[1], "r");
     yyout = fopen(argv[2], "w");

     codigo = yyparse();

     fclose(yyin);
     fclose(yyout);
     free_function_table();
     free_variables_table();

     return codigo;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    // exit(0);
    has_error = 1;
     return 0;
}


void non_constant_expr(char* name) {
     if (strcmp(stack->top->name, "") == 0) {
          yyerror(cat(2, "Non constant expression at global scope: ", name));
     }
}
