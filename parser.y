%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "./lib/record.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;

char *cat(int, ...);

char* type_name;
%}

%union {
	char * sValue;      /* string value */
     struct record * rec;
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
            command jump statement const_declaration parameter type user_type type_compound subprogram subprograms
            struct_vars struct_type enum_list enum_type ptr_type list_type map_type initialization
            initialization_list declaration declaration_term declaration_line declaration_item
            declarations program

%start program


%%
program : declarations subprograms   { 
                                        fprintf(yyout, "%s\n%s", $1->code, $2->code);
                                        free_record($1);
                                        free_record($2);
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
                                                       free_record($1);
                                                       free_record($2);
                                                       $$ = create_record(s, "");
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

type_declaration : TYPE ID { type_name = strdup($2); } ASSIGNMENT type_compound SEMICOLON {
                                                                                               char* s = cat(5, "typedef ", $5->code, " ", $2, ";\n");
                                                                                               free($2);
                                                                                               free_record($5);
                                                                                               $$ = create_record(s, "");
                                                                                               free(s); 
                                                                                          }
                 ;

declaration_line : declaration_item                                                                 { $$ = $1; }
                 | declaration_line COMMA declaration_item  { 
                                                                 char *s = cat(3, $1->code, ",", $3->code);
                                                                 free_record($1);
                                                                 free_record($3);
                                                                 $$ = create_record(s, "");
                                                                 free(s);
                                                            }
                 ;

declaration_item : declaration_term                                                                 { $$ = $1; }
                 | declaration_term ASSIGNMENT initialization    { 
                                                                      char *s = cat(3, $1->code, " = ", $3->code);
                                                                      free_record($1);
                                                                      free_record($3);
                                                                      $$ = create_record(s, "");
                                                                      free(s);
                                                                 }
                 ;

declaration_term : ID                                       {    
                                                                 $$ = create_record($1, ""); 
                                                                 free($1);
                                                            }
                 | declaration_term LBRACKET expr RBRACKET  {
                                                                 char *s = cat(4, $1->code, "[", $3->code,"]");
                                                                 free_record($1);
                                                                 free_record($3);
                                                                 $$ = create_record(s, "");
                                                                 free(s);
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
                                                  free_record($2);
                                                  free_record($4);
                                                  $$ = create_record(s, ""); 
                                                  free(s);
                                             }
           ;

type_compound : type                                                                                { $$ = $1; }
              | user_type                                                                           { $$ = $1; }
              ;

type : PRIM_TYPE    {    
                         $$ = create_record($1, ""); 
                         free($1);
                    }
     | ptr_type                                                                                     { $$ = $1; }
     | map_type     { $$ = $1; }
     | list_type    { $$ = $1; }
     | ID { 
               $$ = create_record($1, ""); 
               free($1);
          }
     ;

user_type : enum_type    { $$ = $1; }               
          | struct_type  { $$ = $1; }    
          ;

ptr_type : PTR ABRACKET_OPEN type ABRACKET_CLOSE       {
                                                            char *s = cat(2, $3->code, "*");
                                                            free_record($3);
                                                            $$ = create_record(s, "");
                                                            free(s);
                                                       }
         ;

map_type : MAP ABRACKET_OPEN type COMMA type ABRACKET_CLOSE  {
                                                                 char *s = cat(5, "map <", $3->code, ", ", $5->code, ">");
                                                                 free_record($3);
                                                                 free_record($5);
                                                                 $$ = create_record(s, "");
                                                                 free(s);
                                                             }
         ;

list_type : LIST ABRACKET_OPEN type ABRACKET_CLOSE {
                                                       char *s = cat(4, "list <", $3->code, ">");
                                                       free_record($3);
                                                       $$ = create_record(s, "");
                                                       free(s);
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

struct_type : STRUCT LBRACE struct_vars RBRACE {
                                                       char *s = cat(5, "struct ", type_name, " {", $3->code, "}\n");
                                                       free_record($3);
                                                       $$ = create_record(s, "");
                                                       free(s);
                                               }
            ;

struct_vars : var_declaration             { $$ = $1; }
            | struct_vars var_declaration {
                                             char *s = cat(2, $1->code, $2->code);
                                             free_record($1);
                                             free_record($2);
                                             $$ = create_record(s, "");
                                             free(s);
                                          }
            ;

subprograms : subprogram                {
                                             char* s = cat(2, $1->code, "\n");
                                             free_record($1);
                                             $$ = create_record(s, "");
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

subprogram : type ID LPAREN parameters RPAREN LBRACE statements RBRACE     {
                                                                                char *s = cat(8, $1->code, " ", $2, "(", $4->code, ") {\n", $7->code, "\n}\n");
                                                                                free_record($1);
                                                                                free($2);
                                                                                free_record($4);
                                                                                free_record($7);
                                                                                $$ = create_record(s, "");
                                                                                free(s);
                                                                           }
           | VOID ID LPAREN parameters RPAREN LBRACE statements RBRACE     {
                                                                                char *s = cat(7, "void ", $2, "(", $4->code, ") {\n", $7->code, "\n}\n");
                                                                                free($2);
                                                                                free_record($4);
                                                                                free_record($7);
                                                                                $$ = create_record(s, "");
                                                                                free(s);
                                                                           }
           | type ID LPAREN RPAREN LBRACE statements RBRACE                {
                                                                                char *s = cat(5, $1->code, $2, "() {\n", $6->code, "\n}\n");
                                                                                free_record($1);
                                                                                free($2);
                                                                                free_record($6);
                                                                                $$ = create_record(s, "");
                                                                                free(s);
                                                                           }
           | VOID ID LPAREN RPAREN LBRACE statements RBRACE                {
                                                                                char *s = cat(5, "void ", $2, "() {\n", $6->code, "\n}\n");
                                                                                free($2);
                                                                                free_record($6);
                                                                                $$ = create_record(s, "");
                                                                                free(s);
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
                         char *s = cat(3, $1->code, " ", $2);
                         free_record($1);
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

jump : CONTINUE                                                                                     { $$ = create_record("continue", ""); }
     | BREAK                                                                                        { $$ = create_record("break", ""); }
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

if : IF LPAREN expr RPAREN LBRACE statements RBRACE else_ifs_opt else_opt  {
                                                                                char *s = cat(7, "if (", $3->code, ") {", $6->code, "}\n", $8->code, $9->code);
                                                                                free_record($3);
                                                                                free_record($6);
                                                                                free_record($8);
                                                                                free_record($9);
                                                                                $$ = create_record(s, "");
                                                                                free(s);
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

else_if : ELSEIF LPAREN expr RPAREN LBRACE statements RBRACE     {
                                                                      char *s = cat(5, " else if (", $3->code, ") {\n", $6->code, "\n}");
                                                                      free_record($3);
                                                                      free_record($6);
                                                                      $$ = create_record(s, "");
                                                                      free(s);
                                                                 }

else_opt :          { $$ = create_record("", ""); }
         | else     { $$ = $1; }
         ;

else : ELSE LBRACE statements RBRACE    {
                                             char *s = cat(3, " else {\n", $3->code, "}\n");
                                             free_record($3);
                                             $$ = create_record(s, "");
                                             free(s);
                                        }
     ;

while : WHILE LPAREN expr RPAREN LBRACE statements RBRACE {
                                                                 char *s = cat(5, "while (", $3->code, ") {", $6->code, "}\n");
                                                                 free_record($3);
                                                                 free_record($6);
                                                                 $$ = create_record(s, "");
                                                                 free(s);              
                                                          }
      ;

do_while : DO LBRACE statements RBRACE WHILE LPAREN expr RPAREN  {                                          
                                                                      char *s = cat(8, "do {", $3->code, "} while (", $7->code, ");");
                                                                      free_record($3);
                                                                      free_record($7);
                                                                      $$ = create_record(s, "");
                                                                      free(s);              
                                                                 }
         ;

for : FOR LPAREN for_init expr SEMICOLON assignment RPAREN LBRACE statements RBRACE  {
                                                                                          char *s = cat(8, "for (", $3->code, $4->code, ";", $6->code, ") {\n", $9->code, "\n}\n");
                                                                                          free_record($3);
                                                                                          free_record($4);
                                                                                          free_record($6);
                                                                                          free_record($9);
                                                                                          $$ = create_record(s, "");
                                                                                          free(s);
                                                                                     }
    ;

for_init : assignment_command                                                                       { $$ = $1; }
         | var_declaration                                                                          { $$ = $1; }
         ;

switch : SWITCH LPAREN expr RPAREN LBRACE cases RBRACE                {
                                                                           char *s = cat(7, "switch", "(", $3->code, ")", "{", $6->code, "}\n");
                                                                           free_record($3);
                                                                           free_record($6);
                                                                           $$ = create_record(s, "");
                                                                           free(s);
                                                                      }
       | SWITCH LPAREN expr RPAREN LBRACE cases default RBRACE        {
                                                                           char *s = cat(8, "switch", "(", $3->code, ")", "{", $6->code, $7->code, "}\n");
                                                                           free_record($3);
                                                                           free_record($6);
                                                                           free_record($7);
                                                                           $$ = create_record(s, "");
                                                                           free(s);
                                                                      }
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

     yyin = fopen(argv[1], "r");
     yyout = fopen(argv[2], "w");

     codigo = yyparse();

     fclose(yyin);
     fclose(yyout);

     return codigo;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}


char *cat(int count, ...) {
     va_list args;
     int tam_total = 0;

     va_start(args, count);

     for (int i = 0; i < count; i++) {
          char *str = va_arg(args, char *);
          tam_total += strlen(str);
     }

     va_end(args);

     char *result = malloc(tam_total + 1);
     if (!result) {
          printf("Allocation problem. Closing application...\n");
          exit(0);
     }

     char *current = result;
     va_start(args, count);

     for (int i = 0; i < count; i++) {
          char *str = va_arg(args, char *);
          if (str) {
               int len = strlen(str);
               memcpy(current, str, len);
               current += len;
          }
     }

     va_end(args);

     *current = '\0';

     return result;
}
