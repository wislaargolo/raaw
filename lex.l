%{
  #include <stdio.h>
%}

%%

[ \r?\n\t]            ;

"if"                  { printf("IF\n"); }
"else"                { printf("ELSE\n"); }
"switch"              { printf("SWITCH\n"); }
"case"                { printf("CASE\n"); }
"default"             { printf("DEFAULT\n"); }

"do"                  { printf("DO\n"); }
"while"               { printf("WHILE\n"); }
"for"                 { printf("FOR\n"); }
"break"               { printf("BREAK\n");}
"continue"            { printf("CONTINUE\n"); }
"return"              { printf("RETURN\n"); }

"new"                 { printf("NEW\n"); }
"delete"              { printf("DELETE\n"); }
"ref"                 { printf("REF\n"); }
"val"                 { printf("VAL\n"); }

int|long|float|double|boolean|char|string|file { printf("PRIM_TYPE(%s)\n", yytext); }
"const"               { printf("CONST\n"); }
"void"                { printf("VOID\n"); }
"struct"              { printf("STRUCT_TYPE\n"); }
"enum"                { printf("ENUM_TYPE\n"); }
"ptr"                 { printf("PTR_TYPE\n"); }
"list"                { printf("LIST_TYPE\n"); }
"map"                 { printf("MAP_TYPE\n"); }
"type"                { printf("TYPE\n"); }

"("                   { printf("LPAREN\n"); }
")"                   { printf("RPAREN\n"); }
"{"                   { printf("LBRACE\n"); }
"}"                   { printf("RBRACE\n"); }
"["                   { printf("LBRACKET\n"); }
"]"                   { printf("RBRACKET\n"); }
";"                   { printf("SEMICOLON\n"); }
":"                   { printf("COLON\n"); }
","                   { printf("COMMA\n"); }

"=="                  { printf("EQUALITY\n"); }
"!="                  { printf("DIFFERENCE\n"); }
"<"                   { printf("ABRACKET_OPEN\n"); }
">"                   { printf("ABRACKET_CLOSE\n"); }
"<="                  { printf("LESS_THAN_EQUALS\n"); }
">="                  { printf("MORE_THAN_EQUALS\n"); }

"="                   { printf("ASSIGNMENT\n"); }
"*="                  { printf("ASSIGNMENT_MUL\n"); }
"/="                  { printf("ASSIGNMENT_DIV\n"); }
"%="                  { printf("ASSIGNMENT_MOD\n"); }
"+="                  { printf("ASSIGNMENT_ADD\n"); }
"-="                  { printf("ASSIGNMENT_SUB\n"); }

"&&"                  { printf("AND\n"); }
"and"                 { printf("ANDC\n"); }
"||"                  { printf("OR\n"); }
"or"                  { printf("ORC\n"); }
"!"                   { printf("NOT\n"); }

"+"                   { printf("PLUS\n"); }
"-"                   { printf("MINUS\n"); }
"*"                   { printf("STAR\n"); }
"/"                   { printf("SLASH\n"); }
"%"                   { printf("MOD\n"); }

true|false                  { printf("BOOL(%s)\n", yytext); }
[0-9]+\.[0-9]+              { printf("REAL(%s)\n", yytext); }
[0-9]+                      { printf("INTEGER(%s)\n", yytext); }
\'.\'                       { printf("CHAR(%s)\n", yytext); }
\"(?:(?:[^"\\\n\r]|\\.)*[^\\])?\"  { printf("STRING(%s)\n", yytext); }

[a-zA-Z][a-zA-Z0-9\_]*	      { printf("ID(%s)\n",yytext); }
"//".*                        { /* ignora comentário de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/"    { /* ignora comentário de bloco */ }
.                             { printf("Invalid character\n"); }

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif

int main(void)
{
  yylex();
  return 0;
}
