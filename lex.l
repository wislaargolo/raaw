%{
  #include <stdio.h>
  #include "y.tab.h"

  extern int yyerror (char *msg);  
%}

%%

[ \r?\n\t]                          ;


"if"                                { return(IF); }
"else"                              { return(ELSE); }
else[ \r?\n\t]+if                   { return(ELSEIF); }
"switch"                            { return(SWITCH); }
"case"                              { return(CASE); }
"default"                           { return(DEFAULT); }

"do"                                { return(DO); }
"while"                             { return(WHILE); }
"for"                               { return(FOR); }
"break"                             { return(BREAK);}
"continue"                          { return(CONTINUE); }
"return"                            { return(RETURN); }

"new"                               { return(NEW); }
"delete"                            { return(DELETE); }
"ref"                               { return(REF); }
"val"                               { return(VAL); }

int|long|float|double|boolean|char|string|file { yylval.sValue = strdup(yytext); return (PRIM_TYPE); }

"const"                             { return(CONST); }
"void"                              { return(VOID); }
"struct"                            { return(STRUCT); }
"enum"                              { return(ENUM); }
"ptr"                               { return(PTR); }
"list"                              { return(LIST); }
"map"                               { return(MAP); }
"type"                              { return(TYPE); }

"("                                 { return(LPAREN); }
")"                                 { return(RPAREN); }
"{"                                 { return(LBRACE); }
"}"                                 { return(RBRACE); }
"["                                 { return(LBRACKET); }
"]"                                 { return(RBRACKET); }
";"                                 { return(SEMICOLON); }
":"                                 { return(COLON); }
","                                 { return(COMMA); }
"."                                 { return(DOT); }

"=="                                { return(EQUALITY); }
"!="                                { return(DIFFERENCE); }
"<"                                 { return(ABRACKET_OPEN); }
">"                                 { return(ABRACKET_CLOSE); }
"<="                                { return(LESS_THAN_EQUALS); }
">="                                { return(MORE_THAN_EQUALS); }

"="                                 { return(ASSIGNMENT); }
"*="                                { return(ASSIGNMENT_MUL); }
"/="                                { return(ASSIGNMENT_DIV); }
"%="                                { return(ASSIGNMENT_MOD); }
"+="                                { return(ASSIGNMENT_ADD); }
"-="                                { return(ASSIGNMENT_SUB); }

"&&"                                { return(AND); }
"and"                               { return(ANDC); }
"||"                                { return(OR); }
"or"                                { return(ORC); }
"!"                                 { return(NOT); }

"+"                                 { return(PLUS); }
"-"                                 { return(MINUS); }
"*"                                 { return(TIMES); }
"/"                                 { return(SLASH); }
"%"                                 { return(MOD); }

true|false                          { yylval.sValue = strdup(yytext); return(BOOL); }
[0-9]+\.[0-9]+                      { yylval.sValue = strdup(yytext); return(REAL); }
[0-9]+                              { yylval.sValue = strdup(yytext); return(INTEGER); }
\'.\'                               { yylval.cValue = yytext[0]; return(CHAR); }
\"(?:(?:[^"\\\n\r]|\\.)*[^\\])?\"   { yylval.sValue = strdup(yytext); return(STRING); }

[a-zA-Z][a-zA-Z0-9\_]*	            { yylval.sValue = strdup(yytext); return (ID); }
"//".*                              { /* ignora comentário de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* ignora comentário de bloco */ }

.                                   { yyerror("Invalid character"); }

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif