%{
  #include <stdio.h>
%}

%%

[ \t\n]               ;
[0-9]+                {printf("NUMBER(%s)\n",yytext);}
"while"               {printf("WHILE\n");}
"begin"               {printf("BEGIN\n");}
"end"                 {printf("END\n");}
"do"                  {printf("DO\n");}
[iI][fF]              {printf("IF\n");}
"then"                {printf("THEN\n");}
"else"                {printf("ELSE\n");}
";"                   {printf("SEMICOLON\n");}
":="                  {printf("ASSIGNMENT\n");}
[a-zA-Z][a-zA-Z0-9]*  {printf("ID(%s)\n",yytext);}
.                     {printf("Invalid character(%s).\n", yytext);}

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif

int main(void)
{
  yylex();
  return 0;
}