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
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;


char* type_name;
int ptr_count = 0;
function_data *current_fd = NULL;
int const_mode = 0;
int inside_struct = 0;

Stack* stack = NULL;
%}

%union {
	char * sValue;      /* string value */
     struct record * rec;
     struct declaration_term_record* decl_term;
     struct type_record* type_rec;
     struct parameter_record* param;
};


%token <sValue> ID PRIM_TYPE INTEGER STRING BOOL REAL CHAR
%token IF ELSE ELSEIF SWITCH CASE DEFAULT
       DO WHILE FOR BREAK CONTINUE RETURN
       NEW DELETE REF VAL CONST VOID
       STRUCT ENUM PTR LIST MAP TYPE
       LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COLON COMMA DOT
       EQUALITY DIFFERENCE ABRACKET_OPEN ABRACKET_CLOSE LESS_THAN_EQUALS MORE_THAN_EQUALS
       ASSIGNMENT ASSIGNMENT_MUL ASSIGNMENT_DIV ASSIGNMENT_MOD ASSIGNMENT_ADD ASSIGNMENT_SUB
       AND ANDC OR ORC NOT PLUS MINUS TIMES SLASH MOD


%type <sValue> unary_operator mult_operator add_operator ineq_operator eq_operator
               and_operator or_operator assignment_operator

%type <rec> literal target base expr val function_call postfix_expr cast prefix_expr term
            identifier_ref arithmetic_expr relational_expr eq_expr and_expr or_expr deletion
            assignment_expr assignment_command allocation assignment assignable
            assignment_expr assignment_command allocation assignment assignable
            parameters cases case case_item default statements switch for_init for var_declaration type_declaration
            do_while while else else_opt else_if else_ifs else_ifs_opt if return return_value
            command jump statement const_declaration parameter user_type type_compound subprogram subprograms
            struct_vars struct_type enum_list enum_type initialization
            initialization_list declaration struct_var_declaration
            declarations program default_opt const_parameter parameter_type

%type <decl_term> declaration_term declaration_line declaration_item struct_declaration_line

%type <type_rec> type ptr_type list_type map_type

%type <param> parameters_call

%start program


%%
program : { stack = create_stack(); } declarations subprograms   {
                                                                      fprintf(yyout,"#include \"./raaw/header.h\"\n\n%s%s", $2->code, $3->code);
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
                                                       char *s = cat(4, $1->code, " ", $2->code, ";");

                                                       declaration_term_record* decl = $2;

                                                       while (decl != NULL) {
                                                            char* type = strdup($1->name);

                                                            for (int i = 0; i < decl->dimension; i++) {
                                                                 char* aux = type;
                                                                 type = cat(3, "ptr<", aux, ">");
                                                                 free(aux);
                                                            }

                                                            if(insert_variable(stack, decl->name, type, const_mode) == 1) {
                                                                 yyerror(cat(4, "Variable '", decl->name, "' already declared in scope ", stack->top->name));
                                                            }

                                                            free(decl->name);
                                                            free(decl->code);
                                                            decl = decl->next;
                                                       }

                                                       $$ = create_record(s, "");
                                                       free($1->code);
                                                       free($1->name);
                                                       //free($2);
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
                                   }
                                   type_name = strdup($2);
                              }
                   ASSIGNMENT type_compound SEMICOLON  {
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
                 | declaration_line COMMA declaration_item  {
                                                                 char *s = cat(3, $1->code, ", ", $3->code);
                                                                 free($3->code);
                                                                 $$ = $3;
                                                                 $$->code = s;
                                                                 $$->next = $1;
                                                            }
                 ;

declaration_item : declaration_term                              { $$ = $1; }
                 | declaration_term ASSIGNMENT initialization    {
                                                                      char *s = cat(3, $1->code, " = ", $3->code);
                                                                      free($1->code);
                                                                      free_record($3);
                                                                      $$ = $1;
                                                                      $$->code = s;
                                                                 }
                 ;

declaration_term : ID                                       {
                                                                 $$ = (declaration_term_record*) malloc((sizeof(declaration_term_record)));
                                                                 $$->code = strdup($1);
                                                                 $$->name = strdup($1);
                                                                 $$->dimension = 0;
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
                                                            }
                 ;

initialization : expr                                                                               { $$ = $1; }
               | LBRACE initialization_list RBRACE  {
                         char *s = cat(3, "{", $2->code, "}\n");
                         free_record($2);
                         $$ = create_record(s, "");
                         free(s);
                    }
               | allocation                                                                         { $$ = $1; }
               ;

initialization_list : initialization                                                                { $$ = $1; }
                    | initialization_list COMMA initialization   {
                                                                      char *s = cat(3, $1->code, ", ", $3->code);
                                                                      free_record($1);
                                                                      free_record($3);
                                                                      $$ = create_record(s, "");
                                                                      free(s);
                                                                 }
                    ;

allocation : NEW type LBRACKET expr RBRACKET {
                                                  char *s = cat(7,
                                                       "(", $2->code, "*) malloc(sizeof(", $2->code, ") * ", $4->code, ")"
                                                  );
                                                  free($2->code);
                                                  free_record($4);
                                                  $$ = create_record(s, "");
                                                  free(s);
                                             }
           ;

type_compound : type     {
                              insert_alias_type(type_name, $1->name);
                              $$ = create_record($1->code, "");
                              free($1->code);
                         }
              | user_type                                                                           { $$ = $1; }
              ;

type : PRIM_TYPE    {
                         $$ = (type_record*) malloc(sizeof(type_record));
                         $$->code = strdup($1);
                         $$->name = strdup($1);
                         free($1);
                    }
     | ptr_type                                                                                     { $$ = $1; }
     | map_type     { $$ = $1; }
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

map_type : MAP ABRACKET_OPEN type COMMA type ABRACKET_CLOSE  {
                                                                 $$ = (type_record*) malloc(sizeof(type_record));
                                                                 $$->code = strdup("map");
                                                                 $$->name = strdup("");
                                                                 free($3->code);
                                                                 free($3->name);
                                                                 free($5->code);
                                                                 free($5->name);
                                                             }
         ;

list_type : LIST ABRACKET_OPEN type ABRACKET_CLOSE {
                                                       $$ = (type_record*) malloc(sizeof(type_record));
                                                       $$->code = strdup("list");
                                                       $$->name = cat(4, "list<", $3->name, ">");
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

struct_type : STRUCT { insert_struct_type(type_name); inside_struct = 1; } LBRACE struct_vars RBRACE {
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
                                                                 type = cat(3, "ptr<", aux, ">");
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

subprogram : type ID LPAREN   {    push_subprogram(stack, $2);
                                   if(insert_function($2, $1->code, &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already bean declareted."));
                                   }

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
                                   push_subprogram(stack, $2);
                                   if(insert_function($2, strdup("void"), &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already bean declareted."));
                                   }
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
                              push_subprogram(stack, $2);
                              if(insert_function($2, $1->code, &current_fd) == 1) {
                                   yyerror(cat(3, "Function ", $2, " has already bean declareted."));
                              }
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
                                   push_subprogram(stack, $2);
                                   if(insert_function($2, strdup("void"), &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already bean declareted."));
                                   }
                              } RPAREN LBRACE statements RBRACE  {
                                   char *s = cat(5, "void ", $2, "() {\n", $7->code, "\n}\n");
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
parameter_type : parameter                   { $$ = $1; }
               | const_parameter             { $$ = $1; }
               ;

parameter : type ID {

                         if(insert_variable(stack, $2, $1->name, const_mode) == 1) {
                              yyerror(cat(3, "Variable ", $2, " already declared on scope."));
                         }



                         new_param(current_fd, $1->name);
                         //  parametro pode ser constante
                         char *s = cat(3, $1->code, " ", $2);
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
                                   free_record($2);
                                   $$ = create_record(s, "");
                                   free(s);
                              }
       ;

return_value :                                                                                      { $$ = create_record("", ""); }
             | expr                                                                                 { $$ = $1; }
             ;

if : IF LPAREN expr RPAREN LBRACE  {
                                        push(stack, 0, 0);
                                        ScopeNode* top = stack->top;
                                        top->if_end_label = cat(2, top->name, "_end");
                                   } statements RBRACE else_ifs_opt else_opt  {

                                        ScopeNode* top = stack->top;
                                        char* next_else = cat(2, top->name, "_else");
                                        char* else_chain = cat(2, $9->code, $10->code);

                                        char* final_code;

                                        if (strlen(else_chain) > 0) {
                                             final_code = cat(17,
                                                  "if (!(", $3->code, ")) goto ", next_else, ";\n",
                                                  "{", $7->code, "\n}\n",
                                                  "goto ", top->if_end_label, ";\n",
                                                  next_else, ":\n",
                                                  else_chain, "\n",
                                                  top->if_end_label, ":"
                                             );
                                        } else {
                                             final_code = cat(10,
                                                  "if (!(", $3->code, ")) goto ", top->if_end_label, ";\n",
                                                   "{", $7->code, "\n}\n",
                                                  top->if_end_label, ":"
                                             );
                                        }

                                        free_record($3);
                                        free_record($7);
                                        free_record($9);
                                        free_record($10);
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

else_if : ELSEIF LPAREN expr RPAREN LBRACE { push(stack, 0, 0); } statements RBRACE       {
                                                                                               ScopeNode* top = stack->top;
                                                                                               char* next_else = cat(2, top->name, "_next");

                                                                                               char* s = cat(13,
                                                                                                    "if (!(", $3->code, ")) goto ", next_else, ";\n",
                                                                                                    "{", $7->code, "\n}\n",
                                                                                                    "goto ", top->if_end_label, ";\n",
                                                                                                    next_else, ":"
                                                                                               );
                                                                                               free_record($3);
                                                                                               free_record($7);
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

while : WHILE LPAREN expr RPAREN LBRACE {
                                             push(stack, 1, 0);
                                             ScopeNode* top = stack->top;
                                             top->break_label = cat(2, top->name, "_end");
                                             top->continue_label = strdup(top->name);

                                        } statements RBRACE {

                                             ScopeNode* top = stack->top;
                                             char* s = cat(16,
                                                  "\n", top->name, ":\n",
                                                  "if (!(", $3->code, ")) goto ", top->break_label, ";\n",
                                                  "{", $7->code, "\n",
                                                  "goto ", top->name, ";\n}\n",
                                                  top->break_label, ":"
                                             );
                                             free_record($3);
                                             free_record($7);
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

               } for_init expr SEMICOLON assignment RPAREN LBRACE statements RBRACE  {

                    ScopeNode* top = stack->top;

                    char* s = cat(20,"\n{\n",
                         $4->code, "\n",
                         top->name, ":\n",
                         "if (!(", $5->code, ")) goto ", top->break_label, ";\n",
                         $10->code,
                         top->continue_label, ":\n",
                         $7->code, ";\n",
                         "goto ", top->name, ";\n}\n",
                         top->break_label, ":"
                    );

                    free_record($4);
                    free_record($5);
                    free_record($7);
                    free_record($10);
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

case_item : expr COLON statements       {
                                             char *s = cat(3, $1->code, ":", $3->code);
                                             free_record($1);
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
          ;


function_call : ID LPAREN RPAREN   {

                                        if (!strcmp($1,"print") || !strcmp($1,"printLine")) {
                                             $$ = build_printf(NULL, !strcmp($1,"printLine"));
                                        } else {
                                             $$ = build_function_call($1, NULL);
                                             $$->type = get_function_return_type($1);
                                        }




                                   }
              | ID LPAREN parameters_call RPAREN  {

                                                       if (!strcmp($1,"print") || !strcmp($1,"printLine")) {
                                                            $$ = build_printf($3, !strcmp($1,"printLine"));
                                                       } else {
                                                            $$ = build_function_call($1, $3);
                                                            $$->type = get_function_return_type($1);
                                                       }

                                                       free($1);
                                                  }
              ;

parameters_call : expr                                       {
                                                                 $$ = create_param($1->code, strdup("int"));
                                                                 free_record($1);
                                                             }
                | parameters_call COMMA expr                 {
                                                                 $$ = add_param($1, create_param($3->code, strdup("int")));
                                                                 free_record($3);
                                                             }
                ;

assignment : assignable assignment_operator assignment_expr  {
                                                                char * s_code;
                                                                char * assigned_type = strdup($1->type);

                                                                if (strcmp(assigned_type, "string") == 0) {

                                                                    if (strcmp($2, " = ") == 0) {

                                                                        if (strcmp($3->type, "string") == 0) {

                                                                            s_code = cat(5, $1->code, " = raaw_str_concat(", $3->code, ", \"\")");
                                                                        } else {
                                                                            yyerror(cat(3, "Atribuição inválida: não é possível atribuir '", $3->type, "' a uma variável 'string'."));
                                                                            s_code = strdup("");
                                                                        }
                                                                    }

                                                                    else if (strcmp($2, " += ") == 0) {

                                                                        if (strcmp($3->type, "string") == 0) {
                                                                            s_code = cat(5, $1->code, " = raaw_str_concat(", $1->code, ", ", $3->code, ")");
                                                                        } else {
                                                                            yyerror(cat(3, "Atribuição inválida: não é possível concatenar '", $3->type, "' a uma variável 'string'."));
                                                                            s_code = strdup("");
                                                                        }
                                                                    }
                                                                    else {
                                                                        yyerror(cat(3, "Operador '", $2, "' inválido para atribuição de string."));
                                                                        s_code = strdup("");
                                                                    }
                                                                }
                                                                else {
                                                                    s_code = cat(3, $1->code, $2, $3->code);
                                                                }

                                                                $$ = create_record(s_code, assigned_type);
                                                                free_record($1);
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

assignable : identifier_ref                                                                         { $$ = $1; }
            | val                                                                                   { $$ = $1; }
            ;

val : VAL LPAREN target RPAREN     {
                                        char *s = cat(3, "*(", $3->code, ")");

                                        char* type = $3->type;

                                        if(!is_ptr(type)) {
                                             yyerror(cat(2, "Invalid type: expected ptr, received ", type));
                                        } else {
                                             type = get_ptr_type(type);
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
                                                                 char * s = cat(5, "free", "(,", $3->code, ")", ";");
                                                                 free_record($3);
                                                                 $$ = create_record(s, "");
                                                                 free(s);
                                                            }
         ;

identifier_ref : ID                                    {
                                                            if (!exists_scope_parent(stack, $1)) {
                                                                 yyerror(cat(3, "Variable '", $1, "' is not declared"));
                                                            }
                                                            print_variable_table();
                                                            $$ = create_record($1, get_variable(stack, $1).type);
                                                            free($1);
                                                       }
               | identifier_ref LBRACKET expr RBRACKET {
                                                            printf("var: %s - %s\n", $1->type, $1->code);
                                                            if (!is_ptr($1->type)) {
                                                                 yyerror(cat(2, "Invalid type: expected ptr, received ", $3->type));
                                                            }
                                                            char * s = cat(4, $1->code, "[", $3->code, "]");
                                                            $$ = create_record(s, get_ptr_type($3->type));
                                                            free_record($1);
                                                            free_record($3);
                                                            free(s);
                                                       }
               | identifier_ref DOT ID  {
                                             char * s = cat(3, $1->code, ".", $3);
                                             free_record($1);
                                             free($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
               ;

expr : or_expr  {
                  $$ = $1;
                }
     ;

or_expr : and_expr                                                                                  {$$ = $1;}
        | or_expr or_operator and_expr {
                                             char * s = cat(3, $1->code, $2, $3->code);
                                             free_record($1);
                                             free($2);
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
        ;

or_operator : OR                                                                                    {$$ = strdup(" | ");}
            | ORC                                                                                   {$$ = strdup(" || ");}
            ;

and_expr : eq_expr                                {$$ = $1;}
         | and_expr and_operator eq_expr    {
                                                  char * s = cat(3, $1->code, $2, $3->code);
                                                  free_record($1);
                                                  free($2);
                                                  free_record($3);
                                                  $$ = create_record(s, "");
                                                  free(s);
                                             }
          ;

and_operator : AND                                                                                  {$$ = strdup(" & ");}
             | ANDC                                                                                 {$$ = strdup(" && ");}
             ;

eq_expr : relational_expr                                                                           {$$ = $1;}
        | eq_expr eq_operator relational_expr     {
                                                        char *s;

                                                        if (is_string($1->type) == 0 && is_string(($3->type) == 0)) {

                                                            if (strcmp($2, " == ") == 0) {
                                                                s = cat(4, "isEquals(", $1->code, ", ", $3->code, ")");
                                                                $$ = create_record(s, "boolean");

                                                            } else if (strcmp($2, " != ") == 0) {
                                                                s = cat(5, "!", "isEquals(", $1->code, ", ", $3->code, ")");
                                                                $$ = create_record(s, "boolean");

                                                            } else {
                                                                yyerror(cat(2, "Operador inválido para comparação de strings: ", $2));
                                                            }
                                                        } else {

                                                            s = cat(3, $1->code, $2, $3->code);
                                                            $$ = create_record(s, "boolean");
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
                                                                      char * s = cat(3, $1->code, $2, $3->code);
                                                                      free_record($1);
                                                                      free($2);
                                                                      free_record($3);
                                                                      $$ = create_record(s, "");
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

                                                        if (strcmp($1->type, "string") == 0 && strcmp($3->type, "string") == 0 && strcmp($2, " + ") == 0) {
                                                            s_code = cat(4, "raaw_str_concat(", $1->code, ", ", $3->code, ")");
                                                        } else {
                                                            s_code = cat(3, $1->code, $2, $3->code);
                                                        }

                                                        $$ = create_record(s_code, result_type);
                                                        free_record($1);
                                                        free($2);
                                                        free_record($3);
                                                        free(s_code);
                                                    }
                ;

term : prefix_expr                                                                               { $$ = $1; }
     | term mult_operator prefix_expr   {
                                             char * s = cat(3, $1->code, $2, $3->code);
                                             free_record($1);
                                             free($2);
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
     ;

mult_operator : TIMES    { $$ = strdup(" * "); }
              | SLASH    { $$ = strdup(" / "); }
              | MOD      { $$ = strdup(" % "); }
              ;

prefix_expr : postfix_expr                                                                          { $$ = $1; }
            | unary_operator postfix_expr         {
                                                       char * s = cat(2, $1, $2->code);
                                                       free($1);
                                                       free_record($2);
                                                       $$ = create_record(s, "");
                                                       free(s);
                                                  }
            | REF LPAREN identifier_ref RPAREN   {
                                                       char * s = cat(4,"&","(", $3->code,")");
                                                       free_record($3);
                                                       $$ = create_record(s, "");
                                                       free(s);
                                                  }
            | cast                                                                                    { $$ = $1; }
            ;

cast : LPAREN PRIM_TYPE RPAREN postfix_expr  {
                                                  char * s = cat(4,"(", $2,")", $4->code);
                                                  free($2);
                                                  free_record($4);
                                                  $$ = create_record(s, "");
                                                  free(s);
                                             }
     ;

unary_operator : add_operator { $$ = $1; }
               | NOT          { $$ = strdup("!"); }
               ;

add_operator : PLUS      { $$ = strdup(" + "); }
             | MINUS     { $$ = strdup(" - "); }
             ;

postfix_expr : target    { $$ = $1; }
             | literal   { $$ = $1; }
             ;

base : ID                     {
                                   if (is_enum($1)) {
                                        char* type = cat(3, "enum_group<", $1, ">");

                                        $$ = create_record($1, type);
                                        free(type);
                                   } else if (!exists_scope_parent(stack, $1)) {
                                        yyerror(cat(3, "Variable '", $1, "' is not declared"));
                                   } else {
                                        char* type = get_variable_type(stack, $1);

                                        $$ = create_record($1, type);
                                        free(type);
                                   }

                                   free($1);
                              }
     | val                    { $$ = $1; }
     | LPAREN expr RPAREN     {
                                   printf("em (expr) %s", $2->code);
                                   char * s = cat(3,"(", $2->code,")");
                                   free_record($2);
                                   $$ = create_record(s, "");
                                   free(s);
                              }
     ;


target : base                           { $$ = $1; }
       | function_call                  { $$ = $1; }
       | target LBRACKET expr RBRACKET  {
                                             char * s = cat(4, $1->code, "[", $3->code,"]");
                                             free_record($1);
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
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
                                             } else if(struct_has_attr($1->type, $3)) {
                                                  yyerror(cat(2, "Invalid: struct não tem esse atributo", $1->type));
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
     return 0;
}
