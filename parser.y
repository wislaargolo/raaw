%{
#include <stdio.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;

%}

%union {
	char   cValue; 	/* char value */
	char * sValue;      /* string value */
	};

%token <sValue> ID PRIM_TYPE INTEGER STRING BOOL REAL
%token <cValue> CHAR
%token IF ELSE ELSEIF SWITCH CASE DEFAULT
       DO WHILE FOR BREAK CONTINUE RETURN
       NEW DELETE REF VAL CONST VOID
       STRUCT ENUM PTR LIST MAP TYPE
       LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COLON COMMA DOT
       EQUALITY DIFFERENCE ABRACKET_OPEN ABRACKET_CLOSE LESS_THAN_EQUALS MORE_THAN_EQUALS
       ASSIGNMENT ASSIGNMENT_MUL ASSIGNMENT_DIV ASSIGNMENT_MOD ASSIGNMENT_ADD ASSIGNMENT_SUB
       AND ANDC OR ORC NOT PLUS MINUS TIMES SLASH MOD
%type <sValue> type

%start program


%%
program : declarations subprograms                                                                  {}
        ;


declarations :                                                                                      {}
             | declarations declaration                                                             {}
             ;

declaration : var_declaration                                                                       {}
            | const_declaration                                                                     {}
            | type_declaration                                                                      {}
            ;

var_declaration : type declaration_line SEMICOLON                                                   {}
               ;

const_declaration : CONST var_declaration                                                           {}
              ;

type_declaration : TYPE ID ASSIGNMENT type SEMICOLON                                                {}

declaration_line : declaration_item                                                                 {}
                 | declaration_line COMMA declaration_item                                          {}
                 ;

declaration_item : declaration_term                                                                 {}
                 | declaration_term ASSIGNMENT initialization                                       {}
                 ;

declaration_term : ID                                                                               {}
                 | declaration_term LBRACKET expr RBRACKET                                          {}
                 ;

initialization : expr                                                                               {}
               | LBRACE initialization_list RBRACE                                                  {}
               | allocation                                                                         {}
               ;

initialization_list : initialization                                                                {}
                    | initialization_list COMMA initialization                                      {}
                    ;

allocation : NEW type LBRACKET expr RBRACKET                                                        {}
           ;


type : PRIM_TYPE                                                                                    {}
     | ptr_type                                                                                     {}
     | enum_type                                                                                    {}
     | struct_type                                                                                  {}
     | map_type                                                                                     {}
     | list_type                                                                                    {}
     | ID                                                                                           {}
     ;

ptr_type : PTR ABRACKET_OPEN type ABRACKET_CLOSE                                                    {}
         ;

map_type : MAP ABRACKET_OPEN type COMMA type ABRACKET_CLOSE                                         {}
         ;

list_type : LIST ABRACKET_OPEN type ABRACKET_CLOSE                                                  {}
          ;

enum_type : ENUM LBRACE enum_list RBRACE                                                            {}
          ;

enum_list : ID                                                                                      {}
          | enum_list COMMA ID                                                                      {}
          ;

struct_type : STRUCT LBRACE struct_vars RBRACE                                                      {}
            ;

struct_vars : var_declaration                                                                       {}
            | struct_vars var_declaration                                                           {}
            ;

subprograms : subprogram                                                                            {}
            | subprograms subprogram                                                                {}
            ;

subprogram : type ID LPAREN parameters RPAREN LBRACE statements RBRACE                              {}
           | VOID ID LPAREN parameters RPAREN LBRACE statements RBRACE                              {}
           | type ID LPAREN RPAREN LBRACE statements RBRACE                                         {}
           | VOID ID LPAREN RPAREN LBRACE statements RBRACE                                         {}
           ;

parameters : parameter                                                                              {}
           | parameters COMMA parameter                                                             {}
           ;

parameter : type ID                                                                                 {}
          ;

statements : statement                                                                              {}
           | statements statement                                                                   {}
           ;

statement : var_declaration                                                                         {}
          | const_declaration                                                                       {}
          | command                                                                                 {}
          | assignment_command                                                                      {}
          ;

command : if                                                                                        {}
        | while                                                                                     {}
        | do_while                                                                                  {}
        | for                                                                                       {}
        | switch                                                                                    {}
        | function_call SEMICOLON                                                                   {}
        | jump SEMICOLON                                                                            {}
        | deletion                                                                                  {}
        ;

jump : CONTINUE                                                                                     {}
     | BREAK                                                                                        {}
     | return                                                                                       {}
      ;

return : RETURN return_value                                                                        {}
       ;

return_value :                                                                                      {}
             | expr                                                                                 {}
             ;

if : IF LPAREN expr RPAREN LBRACE statements RBRACE else_ifs_opt else_opt                           {}
   ;

else_ifs_opt :                                                                                      {}
             | else_ifs                                                                             {}
             ;

else_ifs : else_if                                                                                  {}
         | else_ifs else_if                                                                         {}
         ;

else_if : ELSEIF LPAREN expr RPAREN LBRACE statements RBRACE                                        {}

else_opt :                                                                                          {}
         | else                                                                                     {}
         ;

else : ELSE LBRACE statements RBRACE                                                                {}
     ;

while : WHILE LPAREN expr RPAREN LBRACE statements RBRACE                                           {}
      ;

do_while : DO LBRACE statements RBRACE WHILE LPAREN expr RPAREN                                     {}
         ;

for : FOR LPAREN for_init expr SEMICOLON assignment RPAREN LBRACE statements RBRACE                 {}
    ;

for_init : assignment_command                                                                       {}
         | var_declaration                                                                          {}
         ;

switch : SWITCH LPAREN expr RPAREN LBRACE cases RBRACE                                              {}
       | SWITCH LPAREN expr RPAREN LBRACE cases default RBRACE                                      {}
       ;

cases : case                                                                                        {}
      | cases case                                                                                  {}
      ;

case : CASE case_item                                                                               {}
     ;

default : DEFAULT COLON statements                                                                  {}
        ;

case_item : expr COLON statements                                                                   {}
          ;


function_call : ID LPAREN RPAREN                                                                    {}
              | ID LPAREN parameters_call RPAREN                                                    {}
              ;

parameters_call : expr                                                                              {}
                | parameters_call COMMA expr                                                        {}
                ;

assignment : assignable assignment_operator assignment_expr                                         {}
           ;

assignment_command : assignment SEMICOLON                                                           {}
                   ;

assignable : identifier_ref                                                                         {}
            | val                                                                                   {}
            ;

val : VAL LPAREN target RPAREN                                                                      {}
    ;

assignment_operator : ASSIGNMENT                                                                    {}
                    | ASSIGNMENT_MUL                                                                {}
                    | ASSIGNMENT_DIV                                                                {}
                    | ASSIGNMENT_MOD                                                                {}
                    | ASSIGNMENT_ADD                                                                {}
                    | ASSIGNMENT_SUB                                                                {}
                    ;

assignment_expr : expr                                                                              {}
                | allocation                                                                        {}
                ;

deletion : DELETE LPAREN identifier_ref RPAREN SEMICOLON                                            {}
         ;

identifier_ref : ID                                                                                 {}
               | identifier_ref LBRACKET expr RBRACKET                                              {}
               | identifier_ref DOT ID                                                              {}
               ;

expr : or_expr                                                                                      {}
     ;

or_expr : and_expr                                                                                  {}
        | or_expr or_operator and_expr                                                              {}
        ;

or_operator : OR                                                                                    {}
            | ORC                                                                                   {}
            ;

and_expr : eq_expr                                                                                  {}
               | and_expr and_operator eq_expr                                                      {}
               ;

and_operator : AND                                                                                  {}
             | ANDC                                                                                 {}
             ;

eq_expr : relational_expr                                                                           {}
              | eq_expr eq_operator relational_expr                                                 {}
              ;

eq_operator : EQUALITY                                                                              {}
            | DIFFERENCE                                                                            {}
            ;

relational_expr : arithmetic_expr                                                                   {}
                | relational_expr ineq_operator arithmetic_expr                                     {}
                ;

ineq_operator : ABRACKET_OPEN                                                                       {}
              | MORE_THAN_EQUALS                                                                    {}
              | ABRACKET_CLOSE                                                                      {}
              | LESS_THAN_EQUALS                                                                    {}
              ;

arithmetic_expr : term                                                                              {}
                | arithmetic_expr add_operator term                                                 {}
                ;

add_operator : PLUS                                                                                 {}
             | MINUS                                                                                {}
             ;

term : prefix_expr                                                                                  {}
     | term mult_operator prefix_expr                                                               {}
     ;

mult_operator : TIMES                                                                               {}
              | SLASH                                                                               {}
              | MOD                                                                                 {}
              ;

prefix_expr : postfix_expr                                                                          {}
            | unary_operator postfix_expr                                                           {}
            | REF LPAREN identifier_ref RPAREN                                                      {}
            | cast 
            ;

cast : LPAREN PRIM_TYPE RPAREN postfix_expr                                                         {}
     ;

unary_operator : PLUS                                                                               {}
               | MINUS                                                                              {}
               | NOT                                                                                {}
               ;

postfix_expr : target                                                                               {}                               
             | literal                                                                              {}
             ;

base : ID                                                                                           {}
     | val                                                                                          {}
     | LPAREN expr RPAREN                                                                           {}        
     ;

target : base                                                                                       {}
       | function_call                                                                              {}
       | target LBRACKET expr RBRACKET                                                              {}
       | target DOT ID                                                                              {}
       ;
     

literal : INTEGER                                                                                   {}
        | CHAR                                                                                      {}
        | STRING                                                                                    {}
        | REAL                                                                                      {}
        | BOOL                                                                                      {}
        ;

%%

int main (void) {
	return yyparse ( );
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
