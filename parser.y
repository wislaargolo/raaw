%{
#include <stdio.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;

%}

%union {
	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	};

%token <sValue> ID PRIM_TYPE
%token <iValue> INTEGER
%token CONST IF ELSE ELSEIF SWITCH CASE DEFAULT WHILE FOR ASSIGNMENT VOID LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COLON COMMA DOT PLUS MINUS TYPE

%start program


%%
program : declarations                                  {}
	    ;

declarations : declaration                              {}
             | declarations declaration                 {}
             ;

declaration : var_declaration                           {}             
            | type_declaration                          {} 
            ;

var_declaration : var_specifier type ID SEMICOLON       {}
                ;

var_specifier :                                         {}
              | CONST                                   {} 
              ;

type_declaration : TYPE ID ASSIGNMENT type SEMICOLON    {}
                 ;

type : PRIM_TYPE                                        {}	
     | ID                                               {}
     ;



%%

int main (void) {
	return yyparse ( );
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}