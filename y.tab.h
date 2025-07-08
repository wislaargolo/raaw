/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    PRIM_TYPE = 259,               /* PRIM_TYPE  */
    INTEGER = 260,                 /* INTEGER  */
    STRING = 261,                  /* STRING  */
    BOOL = 262,                    /* BOOL  */
    REAL = 263,                    /* REAL  */
    CHAR = 264,                    /* CHAR  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    ELSEIF = 267,                  /* ELSEIF  */
    SWITCH = 268,                  /* SWITCH  */
    CASE = 269,                    /* CASE  */
    DEFAULT = 270,                 /* DEFAULT  */
    DO = 271,                      /* DO  */
    WHILE = 272,                   /* WHILE  */
    FOR = 273,                     /* FOR  */
    BREAK = 274,                   /* BREAK  */
    CONTINUE = 275,                /* CONTINUE  */
    RETURN = 276,                  /* RETURN  */
    NEW = 277,                     /* NEW  */
    DELETE = 278,                  /* DELETE  */
    REF = 279,                     /* REF  */
    VAL = 280,                     /* VAL  */
    CONST = 281,                   /* CONST  */
    VOID = 282,                    /* VOID  */
    STRUCT = 283,                  /* STRUCT  */
    ENUM = 284,                    /* ENUM  */
    PTR = 285,                     /* PTR  */
    LIST = 286,                    /* LIST  */
    MAP = 287,                     /* MAP  */
    TYPE = 288,                    /* TYPE  */
    LPAREN = 289,                  /* LPAREN  */
    RPAREN = 290,                  /* RPAREN  */
    LBRACE = 291,                  /* LBRACE  */
    RBRACE = 292,                  /* RBRACE  */
    LBRACKET = 293,                /* LBRACKET  */
    RBRACKET = 294,                /* RBRACKET  */
    SEMICOLON = 295,               /* SEMICOLON  */
    COLON = 296,                   /* COLON  */
    COMMA = 297,                   /* COMMA  */
    DOT = 298,                     /* DOT  */
    EQUALITY = 299,                /* EQUALITY  */
    DIFFERENCE = 300,              /* DIFFERENCE  */
    ABRACKET_OPEN = 301,           /* ABRACKET_OPEN  */
    ABRACKET_CLOSE = 302,          /* ABRACKET_CLOSE  */
    LESS_THAN_EQUALS = 303,        /* LESS_THAN_EQUALS  */
    MORE_THAN_EQUALS = 304,        /* MORE_THAN_EQUALS  */
    ASSIGNMENT = 305,              /* ASSIGNMENT  */
    ASSIGNMENT_MUL = 306,          /* ASSIGNMENT_MUL  */
    ASSIGNMENT_DIV = 307,          /* ASSIGNMENT_DIV  */
    ASSIGNMENT_MOD = 308,          /* ASSIGNMENT_MOD  */
    ASSIGNMENT_ADD = 309,          /* ASSIGNMENT_ADD  */
    ASSIGNMENT_SUB = 310,          /* ASSIGNMENT_SUB  */
    AND = 311,                     /* AND  */
    ANDC = 312,                    /* ANDC  */
    OR = 313,                      /* OR  */
    ORC = 314,                     /* ORC  */
    NOT = 315,                     /* NOT  */
    PLUS = 316,                    /* PLUS  */
    MINUS = 317,                   /* MINUS  */
    TIMES = 318,                   /* TIMES  */
    SLASH = 319,                   /* SLASH  */
    MOD = 320,                     /* MOD  */
    NULLISH = 321                  /* NULLISH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

	char * sValue;      /* string value */
     struct record * rec;
     struct declaration_term_record* decl_term;
     struct type_record* type_rec;
     struct parameter_record* param;
     struct dimensional_record* dimensional_rec;
     struct identifier_ref_record* identifier_ref_rec;

#line 140 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
