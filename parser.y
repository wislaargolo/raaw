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
function_data *current_fd = NULL;
int const_mode = 0;


Stack* stack = NULL;
%}

%union {
	char * sValue;      /* string value */
     struct record * rec;
     struct declaration_term_record* decl_term;
     struct type_record* type_rec;
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
            assignment_expr assignment_command allocation assignment assignable parameters_call
            parameters cases case case_item default statements switch for_init for var_declaration type_declaration
            do_while while else else_opt else_if else_ifs else_ifs_opt if return return_value
            command jump statement const_declaration parameter user_type type_compound subprogram subprograms
            struct_vars struct_type enum_list enum_type initialization
            initialization_list declaration struct_var_declaration
            declarations program default_opt

%type <decl_term> declaration_term declaration_line declaration_item struct_declaration_line

%type <type_rec> type ptr_type list_type map_type

%start program


%%
program : { stack = create_stack(); } declarations subprograms   {
                                                                      fprintf(yyout,"#include \"./lib/header.h\"\n\n%s%s", $2->code, $3->code);
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

                                                            // TO-DO: insert in variables table

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

const_declaration : CONST var_declaration {

                                             char *s = cat(2, "const ", $2->code);
                                             free_record($2);
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
                                                                 char *s = cat(3, $1->code, ", ", $3->code);
                                                                 free($1->code);
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
                                                                 printf(" -- TERMO -------: %i", $$->dimension);
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
                                                  free($4->code);
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
               if (!has_type($1)) {
                    yyerror(cat(3, "Type '", $1, "' not declared"));
               }
               $$ = (type_record*) malloc(sizeof(type_record));
               $$->code = strdup($1);
               $$->name = strdup($1);
               free($1);
          }
     ;

user_type : enum_type    { $$ = $1; }
          | struct_type  { $$ = $1; }
          ;

ptr_type : PTR ABRACKET_OPEN type ABRACKET_CLOSE       {
                                                            $$ = (type_record*) malloc(sizeof(type_record));
                                                            $$->code = cat(2, $3->code, "*");
                                                            $$->name = cat(3, "ptr<", $3->name, ">");
                                                            free($3->code);
                                                            free($3->name);
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

enum_type : ENUM LBRACE enum_list RBRACE     {
                                                  char *s = cat(5, "enum ", type_name," {", $3->code, "}\n");
                                                  free_record($3);
                                                  $$ = create_record(s, "");
                                                  free(s);
                                             }
          ;

enum_list : ID {
                    $$ = create_record($1, "");
                    free($1);
               }

          | enum_list COMMA ID  {
                                   char *s = cat(3, $1->code, ",", $3);
                                   free_record($1);
                                   free($3);
                                   $$ = create_record(s, "");
                                   free(s);
                                }
          ;

struct_type : STRUCT { insert_struct_type(type_name); } LBRACE struct_vars RBRACE {
                                                       char *s = cat(5, "struct ", type_name, " {", $4->code, "}\n");
                                                       free_record($4);
                                                       $$ = create_record(s, "");
                                                       free(s);
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

subprogram : type ID LPAREN   {    push_subprogram(stack, $2, $1->code);
                                   if(insert_function($2, $1->code, &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already bean declareted."));
                              }

                              } parameters RPAREN LBRACE statements RBRACE {
                                   char *s = cat(8, $1->code, " ", $2, "(", $5->code, ") {\n", $8->code, "\n}\n");
                                   free($1->code);
                                   free($1->name);
                                   free($2);
                                   free_record($5);
                                   free_record($8);
                                   $$ = create_record(s, "");
                                   free(s);
                                   remove_scope_variables(stack);
                                   pop(stack);
                              }
           | VOID ID LPAREN   {
                                   push_subprogram(stack, $2, "void");
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
                                   remove_scope_variables(stack);
                                   pop(stack);
                              }
           | type ID LPAREN   {
                              push_subprogram(stack, $2, $1->code);
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
                                   remove_scope_variables(stack);
                                   pop(stack);
                              }
           | VOID ID LPAREN   {
                                   push_subprogram(stack, $2, "void");
                                   if(insert_function($2, strdup("void"), &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", $2, " has already bean declareted."));
                                   }
                              } RPAREN LBRACE statements RBRACE  {
                                   char *s = cat(5, "void ", $2, "() {\n", $7->code, "\n}\n");
                                   free($2);
                                   free_record($7);
                                   $$ = create_record(s, "");
                                   free(s);
                                   remove_scope_variables(stack);
                                   pop(stack);
                              }
           ;

parameters : parameter                  { $$ = $1; }
           | parameters COMMA parameter {
                                             char *s = cat(3, $1->code, ", ", $3->code);
                                             free_record($1);
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
           ;

parameter : type ID {
                         new_param(current_fd, $1->code);
                         if(insert_variable(stack, $2, $1->code, 0) == 1) {
                              yyerror(cat(3, "Variable ", $2, " already declared on scope."));
                         }
                         //  parametro pode ser constante
                         char *s = cat(3, $1->code, " ", $2);
                         free($1->code);
                         free($1->name);
                         free($2);
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
                                                                                                              s = cat(3, "goto ", top->continue_label, ";");
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
                                                                                                              s = cat(3, "goto ", top->break_label, ";");
                                                                                                         }
                                                                                                         $$ = create_record(s, "");
                                                                                                         free(s);
                                                                                                    }
     | return                                                                                       { $$ = $1; }
      ;

return : RETURN return_value {
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
                                             final_code = cat(15,
                                                  "if (!(", $3->code, ")) goto ", next_else, ";\n",
                                                  $7->code,
                                                  "goto ", top->if_end_label, ";\n",
                                                  next_else, ":\n",
                                                  else_chain, "\n",
                                                  top->if_end_label, ":"
                                             );
                                        } else {
                                             final_code = cat(8,
                                                  "if (!(", $3->code, ")) goto ", top->if_end_label, ";\n",
                                                  $7->code,
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

                                                                                               char* s = cat(11,
                                                                                                    "if (!(", $3->code, ")) goto ", next_else, ";\n",
                                                                                                    $7->code,
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
                                             $$ = create_record($4->code, "");
                                             free_record($4);
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
                                             char* s = cat(14,
                                                  top->name, ":\n",
                                                  "if (!(", $3->code, ")) goto ", top->break_label, ";\n",
                                                  $7->code, "\n",
                                                  "goto ", top->name, ";\n",
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
                         char *s = cat(11,
                              top->name, ":\n",
                              $4->code, "\n",
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

for : FOR LPAREN for_init expr SEMICOLON assignment RPAREN LBRACE     {
                                                                           push(stack, 1, 0);
                                                                           ScopeNode* top = stack->top;
                                                                           top->break_label = cat(2, top->name, "_end");
                                                                           top->continue_label = cat(2, top->name, "_continue");

                                                                      } statements RBRACE  {

                                                                           ScopeNode* top = stack->top;

                                                                           char* s = cat(19,
                                                                                $3->code,
                                                                                top->name, ":\n",
                                                                                "if (!(", $4->code, ")) goto ", top->break_label, ";\n",
                                                                                $10->code, "\n",
                                                                                top->continue_label, ":\n",
                                                                                $6->code, ";\n",
                                                                                "goto ", top->name, ";\n",
                                                                                top->break_label, ":"
                                                                           );

                                                                           free_record($3);
                                                                           free_record($4);
                                                                           free_record($6);
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
                                        char *s = cat(3, $1, "(", ")");
                                        free($1);
                                        $$ = create_record(s, "");
                                        free(s);
                                   }
              | ID LPAREN parameters_call RPAREN  {
                                                       char *s = cat(4, $1, "(", $3->code, ")");
                                                       free($1);
                                                       free_record($3);
                                                       $$ = create_record(s, "");
                                                       free(s);
                                                  }
              ;

parameters_call : expr                                       { $$ = $1; }
                | parameters_call COMMA expr                 {
                                                                 char *s = cat(3, $1->code, ", ", $3->code);
                                                                 free_record($1);
                                                                 free_record($3);
                                                                 $$ = create_record(s, "");
                                                                 free(s);
                                                             }
                ;

assignment : assignable assignment_operator assignment_expr  {
                                                                 char *s = cat(3, $1->code, $2, $3->code);
                                                                 free_record($1);
                                                                 free($2);
                                                                 free_record($3);
                                                                 $$ = create_record(s, "");
                                                                 free(s);
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
                                        free_record($3);
                                        $$ = create_record(s, "");
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
                                                            $$ = create_record($1, "");
                                                            free($1);
                                                       }
               | identifier_ref LBRACKET expr RBRACKET {
                                                            char * s = cat(4, $1->code, "[", $3->code, "]");
                                                            free_record($1);
                                                            free_record($3);
                                                            $$ = create_record(s, "");
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
                                                       char * s = cat(3, $1->code, $2, $3->code);
                                                       free_record($1);
                                                       free($2);
                                                       free_record($3);
                                                       $$ = create_record(s, "");
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
                                                       char * s = cat(3, $1->code, $2, $3->code);
                                                       free_record($1);
                                                       free($2);
                                                       free_record($3);
                                                       $$ = create_record(s, "");
                                                       free(s);
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
                                   $$ = create_record($1, "");
                                   free($1);
                              }
     | val                    { $$ = $1; }
     | LPAREN expr RPAREN     {
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
                                             char * s = cat(3, $1->code, ".", $3);
                                             free_record($1);
                                             free($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
       ;


literal : INTEGER   {
                         $$ = create_record($1, "long");
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
                         $$ = create_record($1, "double");
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

     print_function_table();

     fclose(yyin);
     fclose(yyout);
     free_function_table();

     return codigo;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
     exit(0);
     return 0;
}
