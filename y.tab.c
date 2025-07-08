/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

Stack* stack = NULL;

#line 101 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 227 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_PRIM_TYPE = 4,                  /* PRIM_TYPE  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_REAL = 8,                       /* REAL  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 12,                    /* ELSEIF  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_NEW = 22,                       /* NEW  */
  YYSYMBOL_DELETE = 23,                    /* DELETE  */
  YYSYMBOL_REF = 24,                       /* REF  */
  YYSYMBOL_VAL = 25,                       /* VAL  */
  YYSYMBOL_CONST = 26,                     /* CONST  */
  YYSYMBOL_VOID = 27,                      /* VOID  */
  YYSYMBOL_STRUCT = 28,                    /* STRUCT  */
  YYSYMBOL_ENUM = 29,                      /* ENUM  */
  YYSYMBOL_PTR = 30,                       /* PTR  */
  YYSYMBOL_LIST = 31,                      /* LIST  */
  YYSYMBOL_MAP = 32,                       /* MAP  */
  YYSYMBOL_TYPE = 33,                      /* TYPE  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 36,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 37,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 38,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 39,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_DOT = 43,                       /* DOT  */
  YYSYMBOL_EQUALITY = 44,                  /* EQUALITY  */
  YYSYMBOL_DIFFERENCE = 45,                /* DIFFERENCE  */
  YYSYMBOL_ABRACKET_OPEN = 46,             /* ABRACKET_OPEN  */
  YYSYMBOL_ABRACKET_CLOSE = 47,            /* ABRACKET_CLOSE  */
  YYSYMBOL_LESS_THAN_EQUALS = 48,          /* LESS_THAN_EQUALS  */
  YYSYMBOL_MORE_THAN_EQUALS = 49,          /* MORE_THAN_EQUALS  */
  YYSYMBOL_ASSIGNMENT = 50,                /* ASSIGNMENT  */
  YYSYMBOL_ASSIGNMENT_MUL = 51,            /* ASSIGNMENT_MUL  */
  YYSYMBOL_ASSIGNMENT_DIV = 52,            /* ASSIGNMENT_DIV  */
  YYSYMBOL_ASSIGNMENT_MOD = 53,            /* ASSIGNMENT_MOD  */
  YYSYMBOL_ASSIGNMENT_ADD = 54,            /* ASSIGNMENT_ADD  */
  YYSYMBOL_ASSIGNMENT_SUB = 55,            /* ASSIGNMENT_SUB  */
  YYSYMBOL_AND = 56,                       /* AND  */
  YYSYMBOL_ANDC = 57,                      /* ANDC  */
  YYSYMBOL_OR = 58,                        /* OR  */
  YYSYMBOL_ORC = 59,                       /* ORC  */
  YYSYMBOL_NOT = 60,                       /* NOT  */
  YYSYMBOL_PLUS = 61,                      /* PLUS  */
  YYSYMBOL_MINUS = 62,                     /* MINUS  */
  YYSYMBOL_TIMES = 63,                     /* TIMES  */
  YYSYMBOL_SLASH = 64,                     /* SLASH  */
  YYSYMBOL_MOD = 65,                       /* MOD  */
  YYSYMBOL_NULLISH = 66,                   /* NULLISH  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_program = 68,                   /* program  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_declarations = 70,              /* declarations  */
  YYSYMBOL_declaration = 71,               /* declaration  */
  YYSYMBOL_var_declaration = 72,           /* var_declaration  */
  YYSYMBOL_const_declaration = 73,         /* const_declaration  */
  YYSYMBOL_74_2 = 74,                      /* $@2  */
  YYSYMBOL_type_declaration = 75,          /* type_declaration  */
  YYSYMBOL_76_3 = 76,                      /* $@3  */
  YYSYMBOL_declaration_line = 77,          /* declaration_line  */
  YYSYMBOL_declaration_item = 78,          /* declaration_item  */
  YYSYMBOL_declaration_term = 79,          /* declaration_term  */
  YYSYMBOL_initialization = 80,            /* initialization  */
  YYSYMBOL_initialization_list = 81,       /* initialization_list  */
  YYSYMBOL_allocation = 82,                /* allocation  */
  YYSYMBOL_type = 83,                      /* type  */
  YYSYMBOL_user_type = 84,                 /* user_type  */
  YYSYMBOL_ptr_type = 85,                  /* ptr_type  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_map_type = 87,                  /* map_type  */
  YYSYMBOL_list_type = 88,                 /* list_type  */
  YYSYMBOL_enum_type = 89,                 /* enum_type  */
  YYSYMBOL_90_5 = 90,                      /* $@5  */
  YYSYMBOL_enum_list = 91,                 /* enum_list  */
  YYSYMBOL_struct_type = 92,               /* struct_type  */
  YYSYMBOL_93_6 = 93,                      /* $@6  */
  YYSYMBOL_struct_vars = 94,               /* struct_vars  */
  YYSYMBOL_struct_var_declaration = 95,    /* struct_var_declaration  */
  YYSYMBOL_struct_declaration_line = 96,   /* struct_declaration_line  */
  YYSYMBOL_subprograms = 97,               /* subprograms  */
  YYSYMBOL_subprogram = 98,                /* subprogram  */
  YYSYMBOL_99_7 = 99,                      /* $@7  */
  YYSYMBOL_100_8 = 100,                    /* $@8  */
  YYSYMBOL_101_9 = 101,                    /* $@9  */
  YYSYMBOL_102_10 = 102,                   /* $@10  */
  YYSYMBOL_parameters = 103,               /* parameters  */
  YYSYMBOL_parameter_type = 104,           /* parameter_type  */
  YYSYMBOL_parameter = 105,                /* parameter  */
  YYSYMBOL_const_parameter = 106,          /* const_parameter  */
  YYSYMBOL_107_11 = 107,                   /* $@11  */
  YYSYMBOL_statements = 108,               /* statements  */
  YYSYMBOL_statement = 109,                /* statement  */
  YYSYMBOL_command = 110,                  /* command  */
  YYSYMBOL_jump = 111,                     /* jump  */
  YYSYMBOL_return = 112,                   /* return  */
  YYSYMBOL_return_value = 113,             /* return_value  */
  YYSYMBOL_if = 114,                       /* if  */
  YYSYMBOL_115_12 = 115,                   /* $@12  */
  YYSYMBOL_else_ifs_opt = 116,             /* else_ifs_opt  */
  YYSYMBOL_else_ifs = 117,                 /* else_ifs  */
  YYSYMBOL_else_if = 118,                  /* else_if  */
  YYSYMBOL_119_13 = 119,                   /* $@13  */
  YYSYMBOL_else_opt = 120,                 /* else_opt  */
  YYSYMBOL_else = 121,                     /* else  */
  YYSYMBOL_122_14 = 122,                   /* $@14  */
  YYSYMBOL_while = 123,                    /* while  */
  YYSYMBOL_124_15 = 124,                   /* $@15  */
  YYSYMBOL_do_while = 125,                 /* do_while  */
  YYSYMBOL_126_16 = 126,                   /* $@16  */
  YYSYMBOL_for = 127,                      /* for  */
  YYSYMBOL_128_17 = 128,                   /* $@17  */
  YYSYMBOL_for_init = 129,                 /* for_init  */
  YYSYMBOL_switch = 130,                   /* switch  */
  YYSYMBOL_131_18 = 131,                   /* $@18  */
  YYSYMBOL_default_opt = 132,              /* default_opt  */
  YYSYMBOL_cases = 133,                    /* cases  */
  YYSYMBOL_case = 134,                     /* case  */
  YYSYMBOL_default = 135,                  /* default  */
  YYSYMBOL_case_item = 136,                /* case_item  */
  YYSYMBOL_function_call = 137,            /* function_call  */
  YYSYMBOL_parameters_call = 138,          /* parameters_call  */
  YYSYMBOL_assignment = 139,               /* assignment  */
  YYSYMBOL_assignment_command = 140,       /* assignment_command  */
  YYSYMBOL_assignable = 141,               /* assignable  */
  YYSYMBOL_val = 142,                      /* val  */
  YYSYMBOL_assignment_operator = 143,      /* assignment_operator  */
  YYSYMBOL_assignment_expr = 144,          /* assignment_expr  */
  YYSYMBOL_deletion = 145,                 /* deletion  */
  YYSYMBOL_identifier_ref = 146,           /* identifier_ref  */
  YYSYMBOL_expr = 147,                     /* expr  */
  YYSYMBOL_or_expr = 148,                  /* or_expr  */
  YYSYMBOL_or_operator = 149,              /* or_operator  */
  YYSYMBOL_and_expr = 150,                 /* and_expr  */
  YYSYMBOL_and_operator = 151,             /* and_operator  */
  YYSYMBOL_eq_expr = 152,                  /* eq_expr  */
  YYSYMBOL_eq_operator = 153,              /* eq_operator  */
  YYSYMBOL_relational_expr = 154,          /* relational_expr  */
  YYSYMBOL_ineq_operator = 155,            /* ineq_operator  */
  YYSYMBOL_arithmetic_expr = 156,          /* arithmetic_expr  */
  YYSYMBOL_term = 157,                     /* term  */
  YYSYMBOL_mult_operator = 158,            /* mult_operator  */
  YYSYMBOL_prefix_expr = 159,              /* prefix_expr  */
  YYSYMBOL_cast = 160,                     /* cast  */
  YYSYMBOL_unary_operator = 161,           /* unary_operator  */
  YYSYMBOL_add_operator = 162,             /* add_operator  */
  YYSYMBOL_postfix_expr = 163,             /* postfix_expr  */
  YYSYMBOL_base = 164,                     /* base  */
  YYSYMBOL_target = 165,                   /* target  */
  YYSYMBOL_literal = 166                   /* literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   659

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  184
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  336

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    79,    88,    89,    98,    99,   100,   103,
     143,   143,   152,   152,   171,   172,   181,   182,   197,   206,
     217,   224,   233,   243,   244,   265,   278,   284,   285,   286,
     287,   312,   313,   316,   316,   326,   337,   346,   346,   354,
     362,   372,   372,   386,   387,   396,   428,   429,   439,   446,
     455,   455,   478,   478,   496,   496,   517,   517,   537,   538,
     547,   548,   551,   574,   574,   582,   588,   597,   598,   599,
     600,   603,   604,   605,   606,   607,   608,   614,   620,   623,
     635,   647,   650,   676,   677,   680,   680,   726,   727,   730,
     731,   740,   740,   762,   763,   766,   766,   775,   775,   802,
     802,   829,   829,   863,   864,   867,   867,   890,   891,   894,
     895,   904,   912,   921,   931,   949,  1007,  1011,  1017,  1067,
    1075,  1086,  1097,  1115,  1116,  1117,  1118,  1119,  1120,  1123,
    1124,  1127,  1136,  1156,  1186,  1216,  1219,  1220,  1238,  1239,
    1242,  1243,  1261,  1262,  1265,  1266,  1297,  1298,  1301,  1302,
    1320,  1321,  1322,  1323,  1326,  1327,  1354,  1355,  1379,  1380,
    1381,  1384,  1385,  1402,  1428,  1431,  1451,  1452,  1455,  1456,
    1459,  1465,  1468,  1487,  1490,  1500,  1501,  1505,  1534,  1568,
    1572,  1576,  1580,  1584,  1588
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "PRIM_TYPE",
  "INTEGER", "STRING", "BOOL", "REAL", "CHAR", "IF", "ELSE", "ELSEIF",
  "SWITCH", "CASE", "DEFAULT", "DO", "WHILE", "FOR", "BREAK", "CONTINUE",
  "RETURN", "NEW", "DELETE", "REF", "VAL", "CONST", "VOID", "STRUCT",
  "ENUM", "PTR", "LIST", "MAP", "TYPE", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COLON", "COMMA", "DOT",
  "EQUALITY", "DIFFERENCE", "ABRACKET_OPEN", "ABRACKET_CLOSE",
  "LESS_THAN_EQUALS", "MORE_THAN_EQUALS", "ASSIGNMENT", "ASSIGNMENT_MUL",
  "ASSIGNMENT_DIV", "ASSIGNMENT_MOD", "ASSIGNMENT_ADD", "ASSIGNMENT_SUB",
  "AND", "ANDC", "OR", "ORC", "NOT", "PLUS", "MINUS", "TIMES", "SLASH",
  "MOD", "NULLISH", "$accept", "program", "$@1", "declarations",
  "declaration", "var_declaration", "const_declaration", "$@2",
  "type_declaration", "$@3", "declaration_line", "declaration_item",
  "declaration_term", "initialization", "initialization_list",
  "allocation", "type", "user_type", "ptr_type", "$@4", "map_type",
  "list_type", "enum_type", "$@5", "enum_list", "struct_type", "$@6",
  "struct_vars", "struct_var_declaration", "struct_declaration_line",
  "subprograms", "subprogram", "$@7", "$@8", "$@9", "$@10", "parameters",
  "parameter_type", "parameter", "const_parameter", "$@11", "statements",
  "statement", "command", "jump", "return", "return_value", "if", "$@12",
  "else_ifs_opt", "else_ifs", "else_if", "$@13", "else_opt", "else",
  "$@14", "while", "$@15", "do_while", "$@16", "for", "$@17", "for_init",
  "switch", "$@18", "default_opt", "cases", "case", "default", "case_item",
  "function_call", "parameters_call", "assignment", "assignment_command",
  "assignable", "val", "assignment_operator", "assignment_expr",
  "deletion", "identifier_ref", "expr", "or_expr", "or_operator",
  "and_expr", "and_operator", "eq_expr", "eq_operator", "relational_expr",
  "ineq_operator", "arithmetic_expr", "term", "mult_operator",
  "prefix_expr", "cast", "unary_operator", "add_operator", "postfix_expr",
  "base", "target", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-229)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -229,    35,  -229,  -229,   100,  -229,  -229,  -229,    30,  -229,
       4,    13,    76,  -229,  -229,  -229,  -229,    87,  -229,  -229,
    -229,   113,  -229,    62,    65,    61,    62,    62,  -229,    80,
     -33,  -229,   -16,   122,  -229,  -229,   131,   111,    62,   101,
     130,   127,   148,  -229,   131,   317,   239,    80,  -229,   190,
     150,   140,  -229,    62,    93,   190,   161,  -229,   165,  -229,
    -229,  -229,  -229,  -229,   170,   171,   303,  -229,  -229,  -229,
    -229,  -229,  -229,   176,    92,    97,   126,   112,   141,   103,
    -229,  -229,   350,  -229,  -229,  -229,    68,  -229,    62,   239,
    -229,  -229,  -229,  -229,   207,    -5,  -229,  -229,  -229,   187,
    -229,   178,  -229,  -229,   191,  -229,  -229,    33,   194,   310,
     230,    29,   203,   208,  -229,  -229,  -229,   317,  -229,  -229,
     317,  -229,  -229,   317,  -229,  -229,  -229,  -229,   317,   317,
    -229,  -229,  -229,   317,   317,  -229,   317,   231,   211,  -229,
      73,    62,  -229,   217,   190,   627,  -229,   220,   221,  -229,
     222,   627,  -229,    34,  -229,  -229,   -12,    42,   350,  -229,
      97,   126,   112,   141,   103,  -229,   227,  -229,   317,  -229,
     239,  -229,   627,  -229,    15,   236,   240,   224,   248,   249,
    -229,  -229,   317,   250,  -229,  -229,   377,  -229,  -229,   225,
    -229,  -229,  -229,  -229,  -229,  -229,   251,   252,  -229,   226,
    -229,  -229,    86,    62,   268,   627,   402,  -229,   317,  -229,
     317,   285,  -229,  -229,  -229,   254,  -229,   427,   317,   317,
    -229,   317,  -229,  -229,  -229,   230,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,    36,   131,    25,
    -229,  -229,    99,   452,  -229,  -229,   256,  -229,  -229,  -229,
     255,   261,   627,   263,   237,    70,  -229,  -229,  -229,    40,
     262,  -229,  -229,  -229,   286,  -229,  -229,   267,   278,   477,
     293,   301,  -229,   317,  -229,   281,   131,  -229,  -229,  -229,
    -229,   313,  -229,   291,  -229,   294,   627,   319,   302,   627,
       2,   502,     7,   199,  -229,   317,   527,   304,   326,  -229,
     299,   305,   306,  -229,  -229,   312,  -229,   314,   315,   337,
     326,  -229,   627,   627,  -229,  -229,   627,   317,   316,  -229,
    -229,  -229,   627,   627,   552,   325,  -229,  -229,   318,   627,
    -229,   577,   627,  -229,   602,  -229
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     4,     1,     0,    30,    26,    10,     0,    33,
       0,     0,     0,     5,     6,     7,     8,     0,    27,    28,
      29,     3,    48,     0,     0,     0,     0,     0,    12,    18,
       0,    14,    16,     0,    49,    11,     0,    52,     0,     0,
       0,     0,    50,     9,     0,     0,     0,     0,    18,     0,
       0,     0,    36,     0,     0,     0,     0,    15,   172,   179,
     181,   183,   182,   180,     0,     0,     0,   167,   168,   169,
     184,   176,   173,     0,   135,   136,   140,   144,   148,   154,
     156,   164,     0,   166,   161,   175,   170,   171,     0,     0,
      17,    22,    20,    63,     0,     0,    58,    60,    61,     0,
      34,     0,    41,    37,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,    19,   138,   139,     0,   142,   143,
       0,   146,   147,     0,   150,   152,   153,   151,     0,     0,
     158,   159,   160,     0,     0,   162,     0,     0,     0,    23,
       0,     0,    62,     0,     0,     0,    35,     0,     0,    13,
       0,     0,   114,     0,   116,   132,     0,     0,     0,   174,
     137,   141,   145,   149,   155,   157,     0,   178,     0,    21,
       0,    64,     0,    59,   132,     0,     0,     0,     0,     0,
      80,    79,    83,     0,    67,    68,     0,    65,    69,     0,
      81,    71,    72,    73,    74,    75,     0,     0,    70,     0,
     121,    78,   120,     0,     0,     0,     0,   115,     0,   163,
       0,     0,   122,   165,   177,     0,    24,     0,     0,     0,
      99,     0,   101,    82,    84,     0,    57,    66,    77,    76,
     119,   123,   124,   125,   126,   127,   128,     0,     0,     0,
      43,    39,     0,     0,    55,   117,     0,   134,    25,    53,
       0,     0,     0,     0,     0,     0,   130,   118,   129,    46,
       0,    42,    44,    38,     0,    51,   133,     0,     0,     0,
       0,   132,   104,     0,   103,     0,     0,    45,    40,    85,
     105,     0,    97,     0,   131,    47,     0,     0,     0,     0,
       0,     0,     0,   107,   109,     0,     0,     0,    87,   111,
       0,     0,     0,   110,   108,     0,    98,     0,     0,    93,
      88,    89,     0,     0,   106,   100,     0,     0,     0,    86,
      94,    90,   113,   112,     0,     0,    95,   102,     0,     0,
      91,     0,     0,    96,     0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,  -229,  -229,  -229,    -3,   357,  -229,  -229,  -229,
    -229,   322,  -228,   -83,  -229,   125,    -2,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,   128,  -229,
    -229,   347,  -229,  -229,  -229,  -229,   327,   229,   233,  -229,
    -229,   -77,   -37,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,    75,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,    95,  -229,  -229,
    -105,  -229,    96,   135,  -229,  -134,  -229,  -229,  -229,  -106,
     -45,  -229,  -229,   274,  -229,   272,  -229,   276,  -229,   273,
     275,  -229,   277,  -229,  -229,   -75,   -74,  -229,   300,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     4,    13,   184,   185,    23,    16,    41,
      30,    31,    32,    90,   140,    91,    36,   104,    18,    25,
      19,    20,   105,   148,   242,   106,   147,   239,   240,   260,
      21,    22,    55,    49,    56,    50,    95,    96,    97,    98,
     141,   186,   187,   188,   189,   190,   223,   191,   286,   309,
     310,   311,   332,   319,   320,   329,   192,   289,   193,   252,
     194,   254,   273,   195,   287,   302,   293,   294,   304,   299,
      71,   153,   197,   198,   199,    72,   237,   257,   201,   202,
      92,    74,   117,    75,   120,    76,   123,    77,   128,    78,
      79,   133,    80,    81,    82,    83,    84,    85,    86,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    14,    17,   129,   156,   155,   139,    43,   135,    44,
     259,   200,    59,    60,    61,    62,    63,   200,   -30,    33,
      35,   113,    45,   209,    39,    40,   210,    65,     5,     6,
     143,   211,    58,    24,    46,     3,    51,   144,   200,    58,
     196,    59,    60,    61,    62,    63,   196,    94,   285,   109,
      26,   101,   200,    94,    65,     9,    10,    11,    88,    27,
      64,    65,   261,   134,   154,     5,     6,   196,   150,   207,
      66,   200,   200,    70,   206,   144,   208,   212,    45,    28,
     136,   196,   276,   200,   213,   137,   138,   216,   129,   113,
      29,   166,     9,    10,    11,   217,    67,    68,    69,    37,
     196,   196,    70,     5,     6,   275,   136,    38,   210,   200,
     169,   137,   196,   211,    42,   170,     5,     6,   200,   255,
     200,   102,   103,   215,   210,    47,     7,     8,   243,   211,
       9,    10,    11,    12,    48,   200,   263,   224,   196,    94,
       8,   264,    94,     9,    10,    11,   -56,   196,    52,   227,
     115,   116,   200,   118,   119,   200,   200,   200,   124,   125,
     126,   127,   200,   245,   196,   246,   130,   131,   132,   227,
     121,   122,    53,   250,   251,   269,   253,    54,   200,   200,
     227,   196,   200,   -54,   196,    99,   196,   100,   200,   200,
     200,   196,   258,     5,     6,   200,   108,   200,   200,   109,
     200,   238,    68,    69,   110,   111,   227,   196,   196,   291,
     142,   196,   296,   292,   301,   114,    93,   196,   196,   196,
       9,    10,    11,   145,   196,   146,   196,   196,   283,   196,
     151,   149,   227,   155,   167,   322,   323,   238,   158,   324,
     271,     6,    58,   159,    59,    60,    61,    62,    63,   168,
     305,   272,   331,   172,   227,   334,   203,   204,   205,   227,
     220,    88,    65,    64,    65,   228,   214,     9,    10,    11,
     218,   241,   325,    66,   219,    89,   231,   232,   233,   234,
     235,   236,   221,   222,   225,   227,   227,   227,   247,   278,
     267,   229,   230,   248,   227,   266,   268,   227,   270,    67,
      68,    69,   277,   279,   -30,    70,    58,   112,    59,    60,
      61,    62,    63,    58,   280,    59,    60,    61,    62,    63,
      58,   284,    59,    60,    61,    62,    63,    64,    65,   282,
     288,   290,    45,   292,    64,    65,   295,    66,   308,   307,
     312,    64,    65,   314,    66,   152,   313,   315,   318,   317,
     316,    66,   326,    58,   330,    59,    60,    61,    62,    63,
     328,    15,   256,    67,    68,    69,    57,   262,    34,    70,
      67,    68,    69,   173,   171,    65,    70,    67,    68,    69,
     174,     6,   107,    70,   134,   321,   297,   175,   303,   274,
     176,   160,   161,   177,   178,   179,   180,   181,   182,   162,
     183,   163,    65,     7,   164,   174,     6,     9,    10,    11,
     165,   157,   175,   300,   226,   176,    70,     0,   177,   178,
     179,   180,   181,   182,     0,   183,     0,    65,     7,     0,
     174,     6,     9,    10,    11,     0,     0,   175,     0,   244,
     176,     0,     0,   177,   178,   179,   180,   181,   182,     0,
     183,     0,    65,     7,     0,   174,     6,     9,    10,    11,
       0,     0,   175,     0,   249,   176,     0,     0,   177,   178,
     179,   180,   181,   182,     0,   183,     0,    65,     7,     0,
     174,     6,     9,    10,    11,     0,     0,   175,     0,   265,
     176,     0,     0,   177,   178,   179,   180,   181,   182,     0,
     183,     0,    65,     7,     0,   174,     6,     9,    10,    11,
       0,     0,   175,     0,   281,   176,     0,     0,   177,   178,
     179,   180,   181,   182,     0,   183,     0,    65,     7,     0,
     174,     6,     9,    10,    11,     0,     0,   175,     0,   298,
     176,     0,     0,   177,   178,   179,   180,   181,   182,     0,
     183,     0,    65,     7,     0,   174,     6,     9,    10,    11,
       0,     0,   175,     0,   306,   176,     0,     0,   177,   178,
     179,   180,   181,   182,     0,   183,     0,    65,     7,     0,
     174,     6,     9,    10,    11,     0,     0,   175,     0,   327,
     176,     0,     0,   177,   178,   179,   180,   181,   182,     0,
     183,     0,    65,     7,     0,   174,     6,     9,    10,    11,
       0,     0,   175,     0,   333,   176,     0,     0,   177,   178,
     179,   180,   181,   182,     0,   183,     0,    65,     7,     0,
     174,     6,     9,    10,    11,     0,     0,   175,     0,   335,
     176,     0,     0,   177,   178,   179,   180,   181,   182,     0,
     183,     0,    65,     7,     0,     0,     0,     9,    10,    11
};

static const yytype_int16 yycheck[] =
{
      45,     4,     4,    78,   110,     3,    89,    40,    82,    42,
     238,   145,     5,     6,     7,     8,     9,   151,     3,    21,
      23,    66,    38,    35,    26,    27,    38,    25,     3,     4,
      35,    43,     3,     3,    50,     0,    38,    42,   172,     3,
     145,     5,     6,     7,     8,     9,   151,    49,   276,    34,
      46,    53,   186,    55,    25,    30,    31,    32,    22,    46,
      24,    25,    37,    34,   109,     3,     4,   172,    35,    35,
      34,   205,   206,    66,   151,    42,    42,    35,    38,     3,
      38,   186,    42,   217,   158,    43,    88,   170,   163,   134,
       3,   136,    30,    31,    32,   172,    60,    61,    62,    34,
     205,   206,    66,     3,     4,    35,    38,    46,    38,   243,
      37,    43,   217,    43,    34,    42,     3,     4,   252,   225,
     254,    28,    29,   168,    38,     3,    26,    27,   205,    43,
      30,    31,    32,    33,     3,   269,    37,   182,   243,   141,
      27,    42,   144,    30,    31,    32,    35,   252,    47,   186,
      58,    59,   286,    56,    57,   289,   290,   291,    46,    47,
      48,    49,   296,   208,   269,   210,    63,    64,    65,   206,
      44,    45,    42,   218,   219,   252,   221,    50,   312,   313,
     217,   286,   316,    35,   289,    35,   291,    47,   322,   323,
     324,   296,   237,     3,     4,   329,    35,   331,   332,    34,
     334,   203,    61,    62,    34,    34,   243,   312,   313,   286,
       3,   316,   289,    14,    15,    39,    26,   322,   323,   324,
      30,    31,    32,    36,   329,    47,   331,   332,   273,   334,
      36,    40,   269,     3,     3,   312,   313,   239,    35,   316,
       3,     4,     3,    35,     5,     6,     7,     8,     9,    38,
     295,   254,   329,    36,   291,   332,    36,    36,    36,   296,
      36,    22,    25,    24,    25,    40,    39,    30,    31,    32,
      34,     3,   317,    34,    34,    36,    50,    51,    52,    53,
      54,    55,    34,    34,    34,   322,   323,   324,     3,     3,
      35,    40,    40,    39,   331,    39,    35,   334,    35,    60,
      61,    62,    40,    36,     3,    66,     3,     4,     5,     6,
       7,     8,     9,     3,    36,     5,     6,     7,     8,     9,
       3,    40,     5,     6,     7,     8,     9,    24,    25,    36,
      17,    40,    38,    14,    24,    25,    34,    34,    12,    35,
      41,    24,    25,    37,    34,    35,    41,    35,    11,    34,
      36,    34,    36,     3,    36,     5,     6,     7,     8,     9,
      35,     4,   237,    60,    61,    62,    44,   239,    21,    66,
      60,    61,    62,   144,   141,    25,    66,    60,    61,    62,
       3,     4,    55,    66,    34,   310,   290,    10,   293,   254,
      13,   117,   120,    16,    17,    18,    19,    20,    21,   123,
      23,   128,    25,    26,   129,     3,     4,    30,    31,    32,
     133,   111,    10,   292,    37,    13,    66,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
       3,     4,    30,    31,    32,    -1,    -1,    10,    -1,    37,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,     3,     4,    30,    31,    32,
      -1,    -1,    10,    -1,    37,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
       3,     4,    30,    31,    32,    -1,    -1,    10,    -1,    37,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,     3,     4,    30,    31,    32,
      -1,    -1,    10,    -1,    37,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
       3,     4,    30,    31,    32,    -1,    -1,    10,    -1,    37,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,     3,     4,    30,    31,    32,
      -1,    -1,    10,    -1,    37,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
       3,     4,    30,    31,    32,    -1,    -1,    10,    -1,    37,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,     3,     4,    30,    31,    32,
      -1,    -1,    10,    -1,    37,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
       3,     4,    30,    31,    32,    -1,    -1,    10,    -1,    37,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,    69,     0,    70,     3,     4,    26,    27,    30,
      31,    32,    33,    71,    72,    73,    75,    83,    85,    87,
      88,    97,    98,    74,     3,    86,    46,    46,     3,     3,
      77,    78,    79,    83,    98,    72,    83,    34,    46,    83,
      83,    76,    34,    40,    42,    38,    50,     3,     3,   100,
     102,    83,    47,    42,    50,    99,   101,    78,     3,     5,
       6,     7,     8,     9,    24,    25,    34,    60,    61,    62,
      66,   137,   142,   147,   148,   150,   152,   154,   156,   157,
     159,   160,   161,   162,   163,   164,   165,   166,    22,    36,
      80,    82,   147,    26,    83,   103,   104,   105,   106,    35,
      47,    83,    28,    29,    84,    89,    92,   103,    35,    34,
      34,    34,     4,   147,    39,    58,    59,   149,    56,    57,
     151,    44,    45,   153,    46,    47,    48,    49,   155,   162,
      63,    64,    65,   158,    34,   163,    38,    43,    83,    80,
      81,   107,     3,    35,    42,    36,    47,    93,    90,    40,
      35,    36,    35,   138,   147,     3,   146,   165,    35,    35,
     150,   152,   154,   156,   157,   159,   147,     3,    38,    37,
      42,   105,    36,   104,     3,    10,    13,    16,    17,    18,
      19,    20,    21,    23,    72,    73,   108,   109,   110,   111,
     112,   114,   123,   125,   127,   130,   137,   139,   140,   141,
     142,   145,   146,    36,    36,    36,   108,    35,    42,    35,
      38,    43,    35,   163,    39,   147,    80,   108,    34,    34,
      36,    34,    34,   113,   147,    34,    37,   109,    40,    40,
      40,    50,    51,    52,    53,    54,    55,   143,    83,    94,
      95,     3,    91,   108,    37,   147,   147,     3,    39,    37,
     147,   147,   126,   147,   128,   146,    82,   144,   147,    79,
      96,    37,    95,    37,    42,    37,    39,    35,    35,   108,
      35,     3,    72,   129,   140,    35,    42,    40,     3,    36,
      36,    37,    36,   147,    40,    79,   115,   131,    17,   124,
      40,   108,    14,   133,   134,    34,   108,   139,    37,   136,
     166,    15,   132,   134,   135,   147,    37,    35,    12,   116,
     117,   118,    41,    41,    37,    35,    36,    34,    11,   120,
     121,   118,   108,   108,   108,   147,    36,    37,    35,   122,
      36,   108,   119,    37,   108,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    71,    71,    71,    72,
      74,    73,    76,    75,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    83,    83,    83,    83,
      83,    84,    84,    86,    85,    87,    88,    90,    89,    91,
      91,    93,    92,    94,    94,    95,    96,    96,    97,    97,
      99,    98,   100,    98,   101,    98,   102,    98,   103,   103,
     104,   104,   105,   107,   106,   108,   108,   109,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   111,
     111,   111,   112,   113,   113,   115,   114,   116,   116,   117,
     117,   119,   118,   120,   120,   122,   121,   124,   123,   126,
     125,   128,   127,   129,   129,   131,   130,   132,   132,   133,
     133,   134,   135,   136,   137,   137,   138,   138,   139,   140,
     141,   141,   142,   143,   143,   143,   143,   143,   143,   144,
     144,   145,   146,   146,   146,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   155,   155,   156,   156,   157,   157,   158,   158,
     158,   159,   159,   159,   159,   160,   161,   161,   162,   162,
     163,   163,   164,   164,   164,   165,   165,   165,   165,   166,
     166,   166,   166,   166,   166
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     1,     1,     1,     3,
       0,     3,     0,     6,     1,     3,     1,     3,     1,     4,
       1,     3,     1,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     6,     4,     0,     5,     1,
       3,     0,     5,     1,     2,     3,     1,     3,     1,     2,
       0,     9,     0,     9,     0,     8,     0,     8,     1,     3,
       1,     1,     2,     0,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     0,     1,     0,    10,     0,     1,     1,
       2,     0,     8,     0,     1,     0,     5,     0,     8,     0,
       9,     0,    11,     1,     1,     0,     9,     0,     1,     1,
       2,     2,     3,     3,     3,     4,     1,     3,     3,     2,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     4,     3,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     4,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     3,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 79 "parser.y"
          { stack = create_stack(); }
#line 1694 "y.tab.c"
    break;

  case 3: /* program: $@1 declarations subprograms  */
#line 79 "parser.y"
                                                                 {
                                                                      fprintf(yyout,"#include \"./raaw/header.h\"\n\n%s%s", (yyvsp[-1].rec)->code, (yyvsp[0].rec)->code);
                                                                      free_record((yyvsp[-1].rec));
                                                                      free_record((yyvsp[0].rec));
                                                                      free_stack(stack);
                                                                 }
#line 1705 "y.tab.c"
    break;

  case 4: /* declarations: %empty  */
#line 88 "parser.y"
                                         { (yyval.rec) = create_record("", ""); }
#line 1711 "y.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 89 "parser.y"
                                         {
                                             char *s = cat(2, (yyvsp[-1].rec)->code, (yyvsp[0].rec)->code);
                                             free_record((yyvsp[-1].rec));
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                        }
#line 1723 "y.tab.c"
    break;

  case 6: /* declaration: var_declaration  */
#line 98 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 1729 "y.tab.c"
    break;

  case 7: /* declaration: const_declaration  */
#line 99 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 1735 "y.tab.c"
    break;

  case 8: /* declaration: type_declaration  */
#line 100 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 1741 "y.tab.c"
    break;

  case 9: /* var_declaration: type declaration_line SEMICOLON  */
#line 103 "parser.y"
                                                   {
                                                       char *s = cat(4, (yyvsp[-2].type_rec)->code, " ", (yyvsp[-1].decl_term)->code, ";\n");

                                                       declaration_term_record* decl = (yyvsp[-1].decl_term);

                                                       while (decl != NULL) {
                                                            char* type = strdup((yyvsp[-2].type_rec)->name);

                                                            if ((yyvsp[-1].decl_term)->init_type != NULL && !type_check(type, (yyvsp[-1].decl_term)->init_type)) {
                                                                 yyerror(cat(4, "Invalid type: expected ", type, ", received ", (yyvsp[-1].decl_term)->init_type));
                                                            }

                                                            for (int i = 0; i < decl->dimension; i++) {
                                                                 char* aux = type;
                                                                 type = cat(3, "ptr<", aux, ">");
                                                                 free(aux);
                                                            }

                                                            if(strcmp(stack->top->name, "") == 0 && has_type(decl->name)) {
                                                                 yyerror(cat(3, "Type ", decl->name, " has already bean declareted."));
                                                            }

                                                            if(insert_variable(stack, decl->name, type, const_mode, decl->dimension) == 1) {
                                                                 yyerror(cat(4, "Variable '", decl->name, "' already declared in scope ", stack->top->name));
                                                            }

                                                            free(decl->name);
                                                            free(decl->code);
                                                            decl = decl->next;
                                                       }

                                                       (yyval.rec) = create_record(s, "");
                                                       free((yyvsp[-2].type_rec)->code);
                                                       free((yyvsp[-2].type_rec)->name);
                                                       //free($2);
                                                       free(s);
                                                       const_mode = 0;
                                                  }
#line 1784 "y.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 143 "parser.y"
                          { const_mode = 1; }
#line 1790 "y.tab.c"
    break;

  case 11: /* const_declaration: CONST $@2 var_declaration  */
#line 143 "parser.y"
                                                              {

                                             char *s = cat(2, "const ", (yyvsp[0].rec)->code);
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                        }
#line 1802 "y.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 152 "parser.y"
                              {
                                   if (has_type((yyvsp[0].sValue))) {
                                        yyerror(cat(3, "Type '", (yyvsp[0].sValue), "' already declared"));
                                   } else if(exists_in_scope(stack, (yyvsp[0].sValue)) == 1) {
                                        yyerror(cat(3, "Variable '", (yyvsp[0].sValue), "' already declared"));
                                   }
                                   type_name = strdup((yyvsp[0].sValue));
                              }
#line 1815 "y.tab.c"
    break;

  case 13: /* type_declaration: TYPE ID $@3 ASSIGNMENT user_type SEMICOLON  */
#line 160 "parser.y"
                                                   {
                                                            char* s = cat(5, "typedef ", (yyvsp[-1].rec)->code, " ", (yyvsp[-4].sValue), ";\n");
                                                            free((yyvsp[-4].sValue));
                                                            free_record((yyvsp[-1].rec));
                                                            (yyval.rec) = create_record(s, "");
                                                            free(s);
                                                            free(type_name);
                                                            type_name = NULL;
                                                       }
#line 1829 "y.tab.c"
    break;

  case 14: /* declaration_line: declaration_item  */
#line 171 "parser.y"
                                                            { (yyval.decl_term) = (yyvsp[0].decl_term); }
#line 1835 "y.tab.c"
    break;

  case 15: /* declaration_line: declaration_line COMMA declaration_item  */
#line 172 "parser.y"
                                                            {
                                                                 char *s = cat(3, (yyvsp[-2].decl_term)->code, ", ", (yyvsp[0].decl_term)->code);
                                                                 free((yyvsp[0].decl_term)->code);
                                                                 (yyval.decl_term) = (yyvsp[0].decl_term);
                                                                 (yyval.decl_term)->code = s;
                                                                 (yyval.decl_term)->next = (yyvsp[-2].decl_term);
                                                            }
#line 1847 "y.tab.c"
    break;

  case 16: /* declaration_item: declaration_term  */
#line 181 "parser.y"
                                                                 { (yyval.decl_term) = (yyvsp[0].decl_term); }
#line 1853 "y.tab.c"
    break;

  case 17: /* declaration_item: declaration_term ASSIGNMENT initialization  */
#line 182 "parser.y"
                                                                 {
                                                                      if ((yyvsp[-2].decl_term)->dimension != (yyvsp[0].dimensional_rec)->dimension) {
                                                                           yyerror("Invalid dimension in variable initialization");
                                                                      }

                                                                      char *s = cat(3, (yyvsp[-2].decl_term)->code, " = ", (yyvsp[0].dimensional_rec)->code);
                                                                      free((yyvsp[-2].decl_term)->code);
                                                                      (yyval.decl_term) = (yyvsp[-2].decl_term);
                                                                      (yyval.decl_term)->code = s;
                                                                      (yyval.decl_term)->init_type = strdup((yyvsp[0].dimensional_rec)->type);
                                                                      free((yyvsp[0].dimensional_rec)->code);
                                                                      free((yyvsp[0].dimensional_rec)->type);
                                                                 }
#line 1871 "y.tab.c"
    break;

  case 18: /* declaration_term: ID  */
#line 197 "parser.y"
                                                            {
                                                                 (yyval.decl_term) = (declaration_term_record*) malloc((sizeof(declaration_term_record)));
                                                                 (yyval.decl_term)->code = strdup((yyvsp[0].sValue));
                                                                 (yyval.decl_term)->name = strdup((yyvsp[0].sValue));
                                                                 (yyval.decl_term)->dimension = 0;
                                                                 (yyval.decl_term)->init_type = NULL;
                                                                 (yyval.decl_term)->next = NULL;
                                                                 free((yyvsp[0].sValue));
                                                            }
#line 1885 "y.tab.c"
    break;

  case 19: /* declaration_term: declaration_term LBRACKET expr RBRACKET  */
#line 206 "parser.y"
                                                            {
                                                                 char *s = cat(4, (yyvsp[-3].decl_term)->code, "[", (yyvsp[-1].rec)->code,"]");
                                                                 free((yyvsp[-3].decl_term)->code);
                                                                 free_record((yyvsp[-1].rec));
                                                                 (yyval.decl_term) = (yyvsp[-3].decl_term);
                                                                 (yyval.decl_term)->dimension++;
                                                                 (yyval.decl_term)->code = s;
                                                                 (yyval.decl_term)->init_type = NULL;
                                                            }
#line 1899 "y.tab.c"
    break;

  case 20: /* initialization: expr  */
#line 217 "parser.y"
                         {
                              (yyval.dimensional_rec) = (dimensional_record*) malloc(sizeof(dimensional_record));
                              (yyval.dimensional_rec)->code = strdup((yyvsp[0].rec)->code);
                              (yyval.dimensional_rec)->type = strdup((yyvsp[0].rec)->type);
                              (yyval.dimensional_rec)->dimension = 0;
                              free_record((yyvsp[0].rec));
                         }
#line 1911 "y.tab.c"
    break;

  case 21: /* initialization: LBRACE initialization_list RBRACE  */
#line 224 "parser.y"
                                                    {
                         (yyval.dimensional_rec) = (dimensional_record*) malloc(sizeof(dimensional_record));
                         char *s = cat(3, "{", (yyvsp[-1].dimensional_rec)->code, "}\n");
                         (yyval.dimensional_rec)->code = s;
                         (yyval.dimensional_rec)->type = strdup((yyvsp[-1].dimensional_rec)->type);
                         (yyval.dimensional_rec)->dimension = (yyvsp[-1].dimensional_rec)->dimension + 1;
                         free((yyvsp[-1].dimensional_rec)->code);
                         free((yyvsp[-1].dimensional_rec)->type);
                    }
#line 1925 "y.tab.c"
    break;

  case 22: /* initialization: allocation  */
#line 233 "parser.y"
                                                                                                    {
                    non_constant_expr("allocation");
                    (yyval.dimensional_rec) = (dimensional_record*) malloc(sizeof(dimensional_record));
                    (yyval.dimensional_rec)->code = strdup((yyvsp[0].rec)->code);
                    (yyval.dimensional_rec)->type = strdup((yyvsp[0].rec)->type);
                    (yyval.dimensional_rec)->dimension = 0;
                    free_record((yyvsp[0].rec));
               }
#line 1938 "y.tab.c"
    break;

  case 23: /* initialization_list: initialization  */
#line 243 "parser.y"
                                                                                                    { (yyval.dimensional_rec) = (yyvsp[0].dimensional_rec); }
#line 1944 "y.tab.c"
    break;

  case 24: /* initialization_list: initialization_list COMMA initialization  */
#line 244 "parser.y"
                                                                 {
                                                                      if (!type_check((yyvsp[-2].dimensional_rec)->type, (yyvsp[0].dimensional_rec)->type)) {
                                                                           yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].dimensional_rec)->type, ", received ", (yyvsp[0].dimensional_rec)->type));
                                                                      }

                                                                      if ((yyvsp[-2].dimensional_rec)->dimension != (yyvsp[0].dimensional_rec)->dimension) {
                                                                           yyerror("Invalid dimension in variable initialization");
                                                                      }

                                                                      (yyval.dimensional_rec) = (dimensional_record*) malloc(sizeof(dimensional_record));
                                                                      char *s = cat(3, (yyvsp[-2].dimensional_rec)->code, ", ", (yyvsp[0].dimensional_rec)->code);
                                                                      (yyval.dimensional_rec)->code = s;
                                                                      (yyval.dimensional_rec)->type = strdup((yyvsp[-2].dimensional_rec)->type);
                                                                      (yyval.dimensional_rec)->dimension = (yyvsp[-2].dimensional_rec)->dimension;
                                                                      free((yyvsp[-2].dimensional_rec)->code);
                                                                      free((yyvsp[-2].dimensional_rec)->type);
                                                                      free((yyvsp[0].dimensional_rec)->code);
                                                                      free((yyvsp[0].dimensional_rec)->type);
                                                                 }
#line 1968 "y.tab.c"
    break;

  case 25: /* allocation: NEW type LBRACKET expr RBRACKET  */
#line 265 "parser.y"
                                             {
                                                  char *s = cat(7,
                                                       "(", (yyvsp[-3].type_rec)->code, "*) malloc(sizeof(", (yyvsp[-3].type_rec)->code, ") * ", (yyvsp[-1].rec)->code, ")"
                                                  );
                                                  char *type = cat(3, "ptr<", (yyvsp[-3].type_rec)->code, ">");
                                                  free((yyvsp[-3].type_rec)->code);
                                                  free_record((yyvsp[-1].rec));
                                                  (yyval.rec) = create_record(s, type);
                                                  free(s);
                                                  free(type);
                                             }
#line 1984 "y.tab.c"
    break;

  case 26: /* type: PRIM_TYPE  */
#line 278 "parser.y"
                    {
                         (yyval.type_rec) = (type_record*) malloc(sizeof(type_record));
                         (yyval.type_rec)->code = strdup((yyvsp[0].sValue));
                         (yyval.type_rec)->name = strdup((yyvsp[0].sValue));
                         free((yyvsp[0].sValue));
                    }
#line 1995 "y.tab.c"
    break;

  case 27: /* type: ptr_type  */
#line 284 "parser.y"
                    { (yyval.type_rec) = (yyvsp[0].type_rec); }
#line 2001 "y.tab.c"
    break;

  case 28: /* type: map_type  */
#line 285 "parser.y"
                    { (yyval.type_rec) = (yyvsp[0].type_rec); }
#line 2007 "y.tab.c"
    break;

  case 29: /* type: list_type  */
#line 286 "parser.y"
                    { (yyval.type_rec) = (yyvsp[0].type_rec); }
#line 2013 "y.tab.c"
    break;

  case 30: /* type: ID  */
#line 287 "parser.y"
          {
               if (type_name != NULL && strcmp(type_name, (yyvsp[0].sValue)) == 0) {
                    if (!inside_struct) {
                         yyerror(cat(3, "Forbidden recursive reference outside struct on type '", (yyvsp[0].sValue), "'"));
                    } else if (ptr_count == 0) {
                         yyerror(cat(3, "Forbidden recursive reference without ptr on type '", (yyvsp[0].sValue), "'"));
                    }

                    (yyval.type_rec) = (type_record*) malloc(sizeof(type_record));
                    (yyval.type_rec)->code = cat(2, "struct ", (yyvsp[0].sValue));
                    (yyval.type_rec)->name = strdup((yyvsp[0].sValue));
               } else {
                    if (!has_type((yyvsp[0].sValue))) {
                         yyerror(cat(3, "Type '", (yyvsp[0].sValue), "' not declared"));
                    }

                    (yyval.type_rec) = (type_record*) malloc(sizeof(type_record));
                    (yyval.type_rec)->code = strdup((yyvsp[0].sValue));
                    (yyval.type_rec)->name = strdup((yyvsp[0].sValue));
               }

               free((yyvsp[0].sValue));
          }
#line 2041 "y.tab.c"
    break;

  case 31: /* user_type: enum_type  */
#line 312 "parser.y"
                         { (yyval.rec) = (yyvsp[0].rec); }
#line 2047 "y.tab.c"
    break;

  case 32: /* user_type: struct_type  */
#line 313 "parser.y"
                         { (yyval.rec) = (yyvsp[0].rec); }
#line 2053 "y.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 316 "parser.y"
               { ptr_count += 1; }
#line 2059 "y.tab.c"
    break;

  case 34: /* ptr_type: PTR $@4 ABRACKET_OPEN type ABRACKET_CLOSE  */
#line 316 "parser.y"
                                                                           {
                                                            (yyval.type_rec) = (type_record*) malloc(sizeof(type_record));
                                                            (yyval.type_rec)->code = cat(2, (yyvsp[-1].type_rec)->code, "*");
                                                            (yyval.type_rec)->name = cat(3, "ptr<", (yyvsp[-1].type_rec)->name, ">");
                                                            free((yyvsp[-1].type_rec)->code);
                                                            free((yyvsp[-1].type_rec)->name);
                                                            ptr_count -= 1;
                                                       }
#line 2072 "y.tab.c"
    break;

  case 35: /* map_type: MAP ABRACKET_OPEN type COMMA type ABRACKET_CLOSE  */
#line 326 "parser.y"
                                                             {
                                                                 (yyval.type_rec) = (type_record*) malloc(sizeof(type_record));
                                                                 (yyval.type_rec)->code = strdup("map");
                                                                 (yyval.type_rec)->name = strdup("");
                                                                 free((yyvsp[-3].type_rec)->code);
                                                                 free((yyvsp[-3].type_rec)->name);
                                                                 free((yyvsp[-1].type_rec)->code);
                                                                 free((yyvsp[-1].type_rec)->name);
                                                             }
#line 2086 "y.tab.c"
    break;

  case 36: /* list_type: LIST ABRACKET_OPEN type ABRACKET_CLOSE  */
#line 337 "parser.y"
                                                   {
                                                       (yyval.type_rec) = (type_record*) malloc(sizeof(type_record));
                                                       (yyval.type_rec)->code = strdup("list");
                                                       (yyval.type_rec)->name = cat(3, "list<", (yyvsp[-1].type_rec)->name, ">");
                                                       free((yyvsp[-1].type_rec)->code);
                                                       free((yyvsp[-1].type_rec)->name);
                                                  }
#line 2098 "y.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 346 "parser.y"
                 { insert_enum_type(type_name); }
#line 2104 "y.tab.c"
    break;

  case 38: /* enum_type: ENUM $@5 LBRACE enum_list RBRACE  */
#line 346 "parser.y"
                                                                              {
                                                  char *s = cat(5, "enum ", type_name," {", (yyvsp[-1].rec)->code, "}\n");
                                                  free_record((yyvsp[-1].rec));
                                                  (yyval.rec) = create_record(s, "");
                                                  free(s);
                                             }
#line 2115 "y.tab.c"
    break;

  case 39: /* enum_list: ID  */
#line 354 "parser.y"
               {
                    insert_enum_attr(type_name, (yyvsp[0].sValue));
                    char* s = cat(3, type_name, "__", (yyvsp[0].sValue));
                    (yyval.rec) = create_record(s, "");
                    free(s);
                    free((yyvsp[0].sValue));
               }
#line 2127 "y.tab.c"
    break;

  case 40: /* enum_list: enum_list COMMA ID  */
#line 362 "parser.y"
                                {
                                   insert_enum_attr(type_name, (yyvsp[0].sValue));
                                   char *s = cat(5, (yyvsp[-2].rec)->code, ", ", type_name, "__", (yyvsp[0].sValue));
                                   free_record((yyvsp[-2].rec));
                                   free((yyvsp[0].sValue));
                                   (yyval.rec) = create_record(s, "");
                                   free(s);
                                }
#line 2140 "y.tab.c"
    break;

  case 41: /* $@6: %empty  */
#line 372 "parser.y"
                     {

                         insert_struct_type(type_name);
                         inside_struct = 1;

                    }
#line 2151 "y.tab.c"
    break;

  case 42: /* struct_type: STRUCT $@6 LBRACE struct_vars RBRACE  */
#line 377 "parser.y"
                                                {
                                                  char *s = cat(5, "struct ", type_name, " {", (yyvsp[-1].rec)->code, "}\n");
                                                  free_record((yyvsp[-1].rec));
                                                  (yyval.rec) = create_record(s, "");
                                                  free(s);
                                                  inside_struct = 0;
                                               }
#line 2163 "y.tab.c"
    break;

  case 43: /* struct_vars: struct_var_declaration  */
#line 386 "parser.y"
                                                 { (yyval.rec) = (yyvsp[0].rec); }
#line 2169 "y.tab.c"
    break;

  case 44: /* struct_vars: struct_vars struct_var_declaration  */
#line 387 "parser.y"
                                                 {
                                             char *s = cat(2, (yyvsp[-1].rec)->code, (yyvsp[0].rec)->code);
                                             free_record((yyvsp[-1].rec));
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                          }
#line 2181 "y.tab.c"
    break;

  case 45: /* struct_var_declaration: type struct_declaration_line SEMICOLON  */
#line 396 "parser.y"
                                                                 {
                                                       char *s = cat(4, (yyvsp[-2].type_rec)->code, " ", (yyvsp[-1].decl_term)->code, ";");

                                                       declaration_term_record* decl = (yyvsp[-1].decl_term);

                                                       while (decl != NULL) {
                                                            char* type = strdup((yyvsp[-2].type_rec)->name);

                                                            for (int i = 0; i < decl->dimension; i++) {
                                                                 char* aux = type;
                                                                 type = cat(3, "ptr<", aux, ">");
                                                                 free(aux);
                                                            }

                                                            if (struct_has_attr(type_name, decl->name)) {
                                                                 yyerror(cat(3, "Attribute '", decl->name, "' declared twice or more in struct"));
                                                            }

                                                            insert_struct_attr(type_name, decl->name, type, decl->dimension);

                                                            free(decl->name);
                                                            free(decl->code);
                                                            decl = decl->next;
                                                       }

                                                       (yyval.rec) = create_record(s, "");
                                                       free((yyvsp[-2].type_rec)->code);
                                                       free((yyvsp[-2].type_rec)->name);
                                                       free(s);
                                                  }
#line 2216 "y.tab.c"
    break;

  case 46: /* struct_declaration_line: declaration_term  */
#line 428 "parser.y"
                                                                   { (yyval.decl_term) = (yyvsp[0].decl_term); }
#line 2222 "y.tab.c"
    break;

  case 47: /* struct_declaration_line: declaration_term COMMA declaration_term  */
#line 429 "parser.y"
                                                            {
                                                                 char *s = cat(3, (yyvsp[-2].decl_term)->code, ", ", (yyvsp[0].decl_term)->code);
                                                                 free((yyvsp[-2].decl_term)->code);
                                                                 free((yyvsp[0].decl_term)->code);
                                                                 (yyval.decl_term) = (yyvsp[0].decl_term);
                                                                 (yyval.decl_term)->code = s;
                                                                 (yyval.decl_term)->next = (yyvsp[-2].decl_term);
                                                            }
#line 2235 "y.tab.c"
    break;

  case 48: /* subprograms: subprogram  */
#line 439 "parser.y"
                                        {
                                             char* s = cat(2, (yyvsp[0].rec)->code, "\n");
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "");
                                             current_fd = NULL;
                                             free(s);
                                        }
#line 2247 "y.tab.c"
    break;

  case 49: /* subprograms: subprograms subprogram  */
#line 446 "parser.y"
                                        {
                                             char *s = cat(3, (yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code);
                                             free_record((yyvsp[-1].rec));
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                        }
#line 2259 "y.tab.c"
    break;

  case 50: /* $@7: %empty  */
#line 455 "parser.y"
                              {
                                   if(exists_in_scope(stack, (yyvsp[-1].sValue))) {
                                        yyerror(cat(3, "Variable ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   } else if(has_type((yyvsp[-1].sValue))) {
                                        yyerror(cat(3, "Type ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   } else if(insert_function((yyvsp[-1].sValue), (yyvsp[-2].type_rec)->code, &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   }
                                   push_subprogram(stack, (yyvsp[-1].sValue));

                              }
#line 2275 "y.tab.c"
    break;

  case 51: /* subprogram: type ID LPAREN $@7 parameters RPAREN LBRACE statements RBRACE  */
#line 465 "parser.y"
                                                                           {

                                   char *s = cat(8, (yyvsp[-8].type_rec)->code, " ", (yyvsp[-7].sValue), "(", (yyvsp[-4].rec)->code, ") {\n", (yyvsp[-1].rec)->code, "\n}\n");
                                   free((yyvsp[-8].type_rec)->code);
                                   free((yyvsp[-8].type_rec)->name);
                                   //free($1);
                                   free((yyvsp[-7].sValue));
                                   free_record((yyvsp[-4].rec));
                                   free_record((yyvsp[-1].rec));
                                   (yyval.rec) = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
#line 2293 "y.tab.c"
    break;

  case 52: /* $@8: %empty  */
#line 478 "parser.y"
                              {
                                   if(exists_in_scope(stack, (yyvsp[-1].sValue))) {
                                        yyerror(cat(3, "Variable ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   } else if(has_type((yyvsp[-1].sValue))) {
                                        yyerror(cat(3, "Type ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   } else if(insert_function((yyvsp[-1].sValue), strdup("void"), &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   }
                                   push_subprogram(stack, (yyvsp[-1].sValue));
                              }
#line 2308 "y.tab.c"
    break;

  case 53: /* subprogram: VOID ID LPAREN $@8 parameters RPAREN LBRACE statements RBRACE  */
#line 487 "parser.y"
                                                                           {
                                   char *s = cat(7, "void ", (yyvsp[-7].sValue), "(", (yyvsp[-4].rec)->code, ") {\n", (yyvsp[-1].rec)->code, "\n}\n");
                                   free((yyvsp[-7].sValue));
                                   free_record((yyvsp[-4].rec));
                                   free_record((yyvsp[-1].rec));
                                   (yyval.rec) = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
#line 2322 "y.tab.c"
    break;

  case 54: /* $@9: %empty  */
#line 496 "parser.y"
                              {

                              if(exists_in_scope(stack, (yyvsp[-1].sValue))) {
                                   yyerror(cat(3, "Variable ", (yyvsp[-1].sValue), " has already bean declareted."));
                              } else if(has_type((yyvsp[-1].sValue))) {
                                   yyerror(cat(3, "Type ", (yyvsp[-1].sValue), " has already bean declareted."));
                              } else if(insert_function((yyvsp[-1].sValue), (yyvsp[-2].type_rec)->code, &current_fd) == 1) {
                                   yyerror(cat(3, "Function ", (yyvsp[-1].sValue), " has already bean declareted."));
                              }

                              push_subprogram(stack, (yyvsp[-1].sValue));
                              }
#line 2339 "y.tab.c"
    break;

  case 55: /* subprogram: type ID LPAREN $@9 RPAREN LBRACE statements RBRACE  */
#line 507 "parser.y"
                                                                 {
                                   char *s = cat(6, (yyvsp[-7].type_rec)->code, " ", (yyvsp[-6].sValue), "() {\n", (yyvsp[-1].rec)->code, "\n}\n");
                                   free((yyvsp[-7].type_rec)->code);
                                   free((yyvsp[-7].type_rec)->name);
                                   free((yyvsp[-6].sValue));
                                   free_record((yyvsp[-1].rec));
                                   (yyval.rec) = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
#line 2354 "y.tab.c"
    break;

  case 56: /* $@10: %empty  */
#line 517 "parser.y"
                              {
                                   if(exists_in_scope(stack, (yyvsp[-1].sValue))) {
                                        yyerror(cat(3, "Variable ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   } else if(has_type((yyvsp[-1].sValue))) {
                                        yyerror(cat(3, "Type ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   } else if(insert_function((yyvsp[-1].sValue), strdup("void"), &current_fd) == 1) {
                                        yyerror(cat(3, "Function ", (yyvsp[-1].sValue), " has already bean declareted."));
                                   }

                                   push_subprogram(stack, (yyvsp[-1].sValue));
                              }
#line 2370 "y.tab.c"
    break;

  case 57: /* subprogram: VOID ID LPAREN $@10 RPAREN LBRACE statements RBRACE  */
#line 527 "parser.y"
                                                                 {
                                   char *s = cat(5, "void ", (yyvsp[-6].sValue), "() {\n", (yyvsp[-1].rec)->code, "\n}\n");
                                   free((yyvsp[-6].sValue));
                                   free_record((yyvsp[-1].rec));
                                   (yyval.rec) = create_record(s, "");
                                   free(s);
                                   pop(stack);
                              }
#line 2383 "y.tab.c"
    break;

  case 58: /* parameters: parameter_type  */
#line 537 "parser.y"
                                             { (yyval.rec) = (yyvsp[0].rec); }
#line 2389 "y.tab.c"
    break;

  case 59: /* parameters: parameters COMMA parameter_type  */
#line 538 "parser.y"
                                             {
                                             char *s = cat(3, (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code);
                                             free_record((yyvsp[-2].rec));
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                        }
#line 2401 "y.tab.c"
    break;

  case 60: /* parameter_type: parameter  */
#line 547 "parser.y"
                                             { (yyval.rec) = (yyvsp[0].rec); }
#line 2407 "y.tab.c"
    break;

  case 61: /* parameter_type: const_parameter  */
#line 548 "parser.y"
                                             { (yyval.rec) = (yyvsp[0].rec); }
#line 2413 "y.tab.c"
    break;

  case 62: /* parameter: type ID  */
#line 551 "parser.y"
                    {
                         if(has_type((yyvsp[0].sValue))) {
                              yyerror(cat(3, "Type ", (yyvsp[0].sValue), " has already bean declareted."));
                         }

                         if(insert_variable(stack, (yyvsp[0].sValue), (yyvsp[-1].type_rec)->name, const_mode, 0) == 1) {
                              yyerror(cat(3, "Variable ", (yyvsp[0].sValue), " already declared on scope."));
                         }

                         new_param(current_fd, (yyvsp[-1].type_rec)->name);
                         //  parametro pode ser constante
                         char *s = cat(3, (yyvsp[-1].type_rec)->code, " ", (yyvsp[0].sValue));
                         free((yyvsp[-1].type_rec)->code);
                         free((yyvsp[-1].type_rec)->name);
                         //free($1);
                         free((yyvsp[0].sValue));
                         (yyval.rec) = create_record(s, "");
                         const_mode = 0;
                         free(s);
                    }
#line 2438 "y.tab.c"
    break;

  case 63: /* $@11: %empty  */
#line 574 "parser.y"
                        {const_mode = 1; }
#line 2444 "y.tab.c"
    break;

  case 64: /* const_parameter: CONST $@11 parameter  */
#line 574 "parser.y"
                                                      {
                                                            char *s = cat(2, "const ", (yyvsp[0].rec)->code);
                                                            free((yyvsp[0].rec)->code);
                                                            (yyval.rec) = create_record(s, "");
                                                            free(s);
                                                       }
#line 2455 "y.tab.c"
    break;

  case 65: /* statements: statement  */
#line 582 "parser.y"
                         {
                              char *s = cat(3, "\n", (yyvsp[0].rec)->code, "\n");
                              free_record((yyvsp[0].rec));
                              (yyval.rec) = create_record(s, "");
                              free(s);
                         }
#line 2466 "y.tab.c"
    break;

  case 66: /* statements: statements statement  */
#line 588 "parser.y"
                                  {
                                        char *s = cat(3, (yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code);
                                        free_record((yyvsp[-1].rec));
                                        free_record((yyvsp[0].rec));
                                        (yyval.rec) = create_record(s, "");
                                        free(s);
                                   }
#line 2478 "y.tab.c"
    break;

  case 67: /* statement: var_declaration  */
#line 597 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2484 "y.tab.c"
    break;

  case 68: /* statement: const_declaration  */
#line 598 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2490 "y.tab.c"
    break;

  case 69: /* statement: command  */
#line 599 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2496 "y.tab.c"
    break;

  case 70: /* statement: assignment_command  */
#line 600 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2502 "y.tab.c"
    break;

  case 71: /* command: if  */
#line 603 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2508 "y.tab.c"
    break;

  case 72: /* command: while  */
#line 604 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2514 "y.tab.c"
    break;

  case 73: /* command: do_while  */
#line 605 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2520 "y.tab.c"
    break;

  case 74: /* command: for  */
#line 606 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2526 "y.tab.c"
    break;

  case 75: /* command: switch  */
#line 607 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2532 "y.tab.c"
    break;

  case 76: /* command: function_call SEMICOLON  */
#line 608 "parser.y"
                                  {
                                        char *s = cat(2, (yyvsp[-1].rec)->code, ";");
                                        free_record((yyvsp[-1].rec));
                                        (yyval.rec) = create_record(s, "");
                                        free(s);
                                  }
#line 2543 "y.tab.c"
    break;

  case 77: /* command: jump SEMICOLON  */
#line 614 "parser.y"
                                  {
                                        char *s = cat(2, (yyvsp[-1].rec)->code, ";");
                                        free_record((yyvsp[-1].rec));
                                        (yyval.rec) = create_record(s, "");
                                        free(s);
                                  }
#line 2554 "y.tab.c"
    break;

  case 78: /* command: deletion  */
#line 620 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2560 "y.tab.c"
    break;

  case 79: /* jump: CONTINUE  */
#line 623 "parser.y"
                                                                                                    {
                                                                                                         ScopeNode* top = stack->top;
                                                                                                         char *s;
                                                                                                         if (!top->is_loop || top->continue_label == NULL) {
                                                                                                              s = "";
                                                                                                              yyerror("Invalid continue outside loop");
                                                                                                         } else {
                                                                                                              s = cat(2, "goto ", top->continue_label);
                                                                                                         }
                                                                                                         (yyval.rec) = create_record(s, "");
                                                                                                         free(s);
                                                                                                    }
#line 2577 "y.tab.c"
    break;

  case 80: /* jump: BREAK  */
#line 635 "parser.y"
                                                                                                    {
                                                                                                         ScopeNode* top = stack->top;
                                                                                                         char *s;
                                                                                                         if ((!top->is_loop && !top->is_switch) || top->break_label == NULL) {
                                                                                                              s = "";
                                                                                                              yyerror("Invalid break outside loop or switch");
                                                                                                         } else {
                                                                                                              s = cat(2, "goto ", top->break_label);
                                                                                                         }
                                                                                                         (yyval.rec) = create_record(s, "");
                                                                                                         free(s);
                                                                                                    }
#line 2594 "y.tab.c"
    break;

  case 81: /* jump: return  */
#line 647 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2600 "y.tab.c"
    break;

  case 82: /* return: RETURN return_value  */
#line 650 "parser.y"
                              {
                                   char *s = cat(2, "return ", (yyvsp[0].rec)->code);
                                   if (current_fd == NULL) {
                                        yyerror("'return' statement outside a function.");
                                   } else {
                                        char* expected_type = current_fd->return_type;
                                        char* actual_type = (yyvsp[0].rec)->type;

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
                                   free_record((yyvsp[0].rec));
                                   (yyval.rec) = create_record(s, "");
                                   free(s);
                              }
#line 2629 "y.tab.c"
    break;

  case 83: /* return_value: %empty  */
#line 676 "parser.y"
                                                                                                    { (yyval.rec) = create_record("", "void"); }
#line 2635 "y.tab.c"
    break;

  case 84: /* return_value: expr  */
#line 677 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2641 "y.tab.c"
    break;

  case 85: /* $@12: %empty  */
#line 680 "parser.y"
                                   {
                                        push(stack, 0, 0);
                                        ScopeNode* top = stack->top;
                                        top->if_end_label = cat(2, top->name, "_end");

                                        if (!type_check((yyvsp[-2].rec)->type, "boolean")) {
                                            yyerror(cat(3, "Condition 'if' requires boolean type, but '",  (yyvsp[-2].rec)->type, "' was found."));
                                        }

                                   }
#line 2656 "y.tab.c"
    break;

  case 86: /* if: IF LPAREN expr RPAREN LBRACE $@12 statements RBRACE else_ifs_opt else_opt  */
#line 689 "parser.y"
                                                                              {

                                        ScopeNode* top = stack->top;
                                        char* next_else = cat(2, top->name, "_else");
                                        char* else_chain = cat(2, (yyvsp[-1].rec)->code, (yyvsp[0].rec)->code);

                                        char* final_code;

                                        if (strlen(else_chain) > 0) {
                                             final_code = cat(17,
                                                  "if (!(", (yyvsp[-7].rec)->code, ")) goto ", next_else, ";\n",
                                                  "{", (yyvsp[-3].rec)->code, "\n}\n",
                                                  "goto ", top->if_end_label, ";\n",
                                                  next_else, ":\n",
                                                  else_chain, "\n",
                                                  top->if_end_label, ":"
                                             );
                                        } else {
                                             final_code = cat(10,
                                                  "if (!(", (yyvsp[-7].rec)->code, ")) goto ", top->if_end_label, ";\n",
                                                   "{", (yyvsp[-3].rec)->code, "\n}\n",
                                                  top->if_end_label, ":"
                                             );
                                        }

                                        free_record((yyvsp[-7].rec));
                                        free_record((yyvsp[-3].rec));
                                        free_record((yyvsp[-1].rec));
                                        free_record((yyvsp[0].rec));
                                        free(next_else);
                                        free(else_chain);
                                        (yyval.rec) = create_record(final_code, "");
                                        free(final_code);
                                        pop(stack);
                                   }
#line 2696 "y.tab.c"
    break;

  case 87: /* else_ifs_opt: %empty  */
#line 726 "parser.y"
                                                                                                    { (yyval.rec) = create_record("", ""); }
#line 2702 "y.tab.c"
    break;

  case 88: /* else_ifs_opt: else_ifs  */
#line 727 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2708 "y.tab.c"
    break;

  case 89: /* else_ifs: else_if  */
#line 730 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2714 "y.tab.c"
    break;

  case 90: /* else_ifs: else_ifs else_if  */
#line 731 "parser.y"
                              {
                                   char *s = cat(3, (yyvsp[-1].rec)->code, " ", (yyvsp[0].rec)->code);
                                   free_record((yyvsp[-1].rec));
                                   free_record((yyvsp[0].rec));
                                   (yyval.rec) = create_record(s, "");
                                   free(s);
                              }
#line 2726 "y.tab.c"
    break;

  case 91: /* $@13: %empty  */
#line 740 "parser.y"
                                           { push(stack, 0, 0); }
#line 2732 "y.tab.c"
    break;

  case 92: /* else_if: ELSEIF LPAREN expr RPAREN LBRACE $@13 statements RBRACE  */
#line 740 "parser.y"
                                                                                          {
                                                                                               if (!type_check((yyvsp[-5].rec)->type, "boolean")) {
                                                                                                    yyerror(cat(3, "Condition 'else if' requires boolean type, but '", (yyvsp[-5].rec)->type, "' was found."));
                                                                                               }

                                                                                               ScopeNode* top = stack->top;
                                                                                               char* next_else = cat(2, top->name, "_next");

                                                                                               char* s = cat(13,
                                                                                                    "if (!(", (yyvsp[-5].rec)->code, ")) goto ", next_else, ";\n",
                                                                                                    "{", (yyvsp[-1].rec)->code, "\n}\n",
                                                                                                    "goto ", top->if_end_label, ";\n",
                                                                                                    next_else, ":"
                                                                                               );
                                                                                               free_record((yyvsp[-5].rec));
                                                                                               free_record((yyvsp[-1].rec));
                                                                                               free(next_else);
                                                                                               (yyval.rec) = create_record(s, "");
                                                                                               free(s);
                                                                                               pop(stack);
                                                                                          }
#line 2758 "y.tab.c"
    break;

  case 93: /* else_opt: %empty  */
#line 762 "parser.y"
                    { (yyval.rec) = create_record("", ""); }
#line 2764 "y.tab.c"
    break;

  case 94: /* else_opt: else  */
#line 763 "parser.y"
                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2770 "y.tab.c"
    break;

  case 95: /* $@14: %empty  */
#line 766 "parser.y"
                   { push(stack, 0, 0); }
#line 2776 "y.tab.c"
    break;

  case 96: /* else: ELSE LBRACE $@14 statements RBRACE  */
#line 766 "parser.y"
                                                               {
                                             char* s = cat(3, "{", (yyvsp[-1].rec)->code, "\n}\n");
                                             free_record((yyvsp[-1].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                             pop(stack);
                                        }
#line 2788 "y.tab.c"
    break;

  case 97: /* $@15: %empty  */
#line 775 "parser.y"
                                        {
                                             push(stack, 1, 0);
                                             ScopeNode* top = stack->top;
                                             top->break_label = cat(2, top->name, "_end");
                                             top->continue_label = strdup(top->name);

                                             if (!type_check((yyvsp[-2].rec)->type, "boolean")) {
                                                yyerror(cat(3, "Condition 'while' requires boolean type, but '", (yyvsp[-2].rec)->type, "' was found."));
                                             }
                                        }
#line 2803 "y.tab.c"
    break;

  case 98: /* while: WHILE LPAREN expr RPAREN LBRACE $@15 statements RBRACE  */
#line 784 "parser.y"
                                                            {

                                             ScopeNode* top = stack->top;
                                             char* s = cat(16,
                                                  "\n", top->name, ":\n",
                                                  "if (!(", (yyvsp[-5].rec)->code, ")) goto ", top->break_label, ";\n",
                                                  "{", (yyvsp[-1].rec)->code, "\n",
                                                  "goto ", top->name, ";\n}\n",
                                                  top->break_label, ":"
                                             );
                                             free_record((yyvsp[-5].rec));
                                             free_record((yyvsp[-1].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                             pop(stack);
                                        }
#line 2824 "y.tab.c"
    break;

  case 99: /* $@16: %empty  */
#line 802 "parser.y"
                      {
                         push(stack, 1, 0);
                         ScopeNode* top = stack->top;
                         top->break_label = cat(2, top->name, "_end");
                         top->continue_label = strdup(top->name);
                    }
#line 2835 "y.tab.c"
    break;

  case 100: /* do_while: DO LBRACE $@16 statements RBRACE WHILE LPAREN expr RPAREN  */
#line 807 "parser.y"
                                                                  {

                         if (!type_check((yyvsp[-1].rec)->type, "boolean")) {
                             yyerror(cat(3, "Condition 'do-while' requires boolean type, but '", (yyvsp[-1].rec)->type, "' was found."));
                         }

                         ScopeNode* top = stack->top;
                         char *s = cat(13,
                              "\n", top->name, ":\n",
                              "{", (yyvsp[-5].rec)->code, "\n}\n",
                              "if (", (yyvsp[-1].rec)->code, ") goto ", top->name, ";\n",
                              top->break_label, ":"
                         );

                         free_record((yyvsp[-5].rec));
                         free_record((yyvsp[-1].rec));
                         (yyval.rec) = create_record(s, "");
                         free(s);
                         pop(stack);
                    }
#line 2860 "y.tab.c"
    break;

  case 101: /* $@17: %empty  */
#line 829 "parser.y"
                 {
                    push(stack, 1, 0);
                    ScopeNode* top = stack->top;
                    top->break_label = cat(2, top->name, "_end");
                    top->continue_label = cat(2, top->name, "_continue");

               }
#line 2872 "y.tab.c"
    break;

  case 102: /* for: FOR LPAREN $@17 for_init expr SEMICOLON assignment RPAREN LBRACE statements RBRACE  */
#line 835 "parser.y"
                                                                                     {

                    if (!type_check((yyvsp[-6].rec)->type, "boolean")) {
                        yyerror(cat(3, "Condition 'for' requires boolean type, but '", (yyvsp[-6].rec)->type, "' was found."));
                    }
                    ScopeNode* top = stack->top;

                    char* s = cat(20,"\n{\n",
                         (yyvsp[-7].rec)->code, "\n",
                         top->name, ":\n",
                         "if (!(", (yyvsp[-6].rec)->code, ")) goto ", top->break_label, ";\n",
                         (yyvsp[-1].rec)->code,
                         top->continue_label, ":\n",
                         (yyvsp[-4].rec)->code, ";\n",
                         "goto ", top->name, ";\n}\n",
                         top->break_label, ":"
                    );

                    free_record((yyvsp[-7].rec));
                    free_record((yyvsp[-6].rec));
                    free_record((yyvsp[-4].rec));
                    free_record((yyvsp[-1].rec));
                    (yyval.rec) = create_record(s, "");
                    free(s);
                    pop(stack);
               }
#line 2903 "y.tab.c"
    break;

  case 103: /* for_init: assignment_command  */
#line 863 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2909 "y.tab.c"
    break;

  case 104: /* for_init: var_declaration  */
#line 864 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2915 "y.tab.c"
    break;

  case 105: /* $@18: %empty  */
#line 867 "parser.y"
                                          {
                                             push(stack, 0, 1);
                                             ScopeNode* top = stack->top;
                                             top->break_label = cat(2, top->name, "_end");

                                        }
#line 2926 "y.tab.c"
    break;

  case 106: /* switch: SWITCH LPAREN expr RPAREN LBRACE $@18 cases default_opt RBRACE  */
#line 872 "parser.y"
                                                                     {
                                             ScopeNode* top = stack->top;
                                             char *s = cat(10,
                                                  "switch (", (yyvsp[-6].rec)->code, ") {\n",
                                                  (yyvsp[-2].rec)->code, "\n",
                                                  (yyvsp[-1].rec)->code, "\n",
                                                  "}\n",
                                                  top->break_label, ":"
                                             );
                                             free_record((yyvsp[-6].rec));
                                             free_record((yyvsp[-2].rec));
                                             free_record((yyvsp[-1].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                             pop(stack);
                                        }
#line 2947 "y.tab.c"
    break;

  case 107: /* default_opt: %empty  */
#line 890 "parser.y"
                       { (yyval.rec) = create_record("", ""); }
#line 2953 "y.tab.c"
    break;

  case 108: /* default_opt: default  */
#line 891 "parser.y"
                       { (yyval.rec) = (yyvsp[0].rec); }
#line 2959 "y.tab.c"
    break;

  case 109: /* cases: case  */
#line 894 "parser.y"
                    { (yyval.rec) = (yyvsp[0].rec); }
#line 2965 "y.tab.c"
    break;

  case 110: /* cases: cases case  */
#line 895 "parser.y"
                    {
                         char *s = cat(3, (yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code);
                         free_record((yyvsp[-1].rec));
                         free_record((yyvsp[0].rec));
                         (yyval.rec) = create_record(s, "");
                         free(s);
                    }
#line 2977 "y.tab.c"
    break;

  case 111: /* case: CASE case_item  */
#line 904 "parser.y"
                         {
                              char *s = cat(2, "case ", (yyvsp[0].rec)->code);
                              free_record((yyvsp[0].rec));
                              (yyval.rec) = create_record(s, "");
                              free(s);
                         }
#line 2988 "y.tab.c"
    break;

  case 112: /* default: DEFAULT COLON statements  */
#line 912 "parser.y"
                                   {
                                        char *s = cat(2,"default: ", (yyvsp[0].rec)->code);
                                        free_record((yyvsp[0].rec));
                                        (yyval.rec) = create_record(s, "");
                                        free(s);
                                   }
#line 2999 "y.tab.c"
    break;

  case 113: /* case_item: literal COLON statements  */
#line 921 "parser.y"
                                           {
                                             char *s = cat(3, (yyvsp[-2].rec)->code, ":", (yyvsp[0].rec)->code);
                                             free_record((yyvsp[-2].rec));
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                        }
#line 3011 "y.tab.c"
    break;

  case 114: /* function_call: ID LPAREN RPAREN  */
#line 931 "parser.y"
                                   {
                                        if(!has_function((yyvsp[-2].sValue))) {
                                             char *s = cat(2, (yyvsp[-2].sValue), "()");
                                             yyerror(cat(3, "Invalid call: ", (yyvsp[-2].sValue), " is not declared"));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                        } else {
                                             if (!strcmp((yyvsp[-2].sValue),"print") || !strcmp((yyvsp[-2].sValue),"printLine")) {
                                                  (yyval.rec) = build_printf(NULL, !strcmp((yyvsp[-2].sValue),"printLine"));
                                             } else {
                                                  (yyval.rec) = build_function_call((yyvsp[-2].sValue), NULL);
                                                  (yyval.rec)->type = get_function_return_type((yyvsp[-2].sValue));
                                             }
                                        }

                                        free((yyvsp[-2].sValue));

                                   }
#line 3034 "y.tab.c"
    break;

  case 115: /* function_call: ID LPAREN parameters_call RPAREN  */
#line 949 "parser.y"
                                                  {
                                                  if(!has_function((yyvsp[-3].sValue))) {
                                                       char *s = cat(4, (yyvsp[-3].sValue), "(", (yyvsp[-1].param)->code, ")");
                                                       yyerror(cat(3, "Invalid call: ", (yyvsp[-3].sValue), " is not declared"));
                                                       (yyval.rec) = create_record(s, "");
                                                       free(s);
                                                  } else {
                                                       if (!strcmp((yyvsp[-3].sValue),"print") || !strcmp((yyvsp[-3].sValue),"printLine")) {
                                                            (yyval.rec) = build_printf((yyvsp[-1].param), !strcmp((yyvsp[-3].sValue),"printLine"));
                                                       } else {
                                                            int is_gen_list_function = is_list_function((yyvsp[-3].sValue), (yyvsp[-1].param));
                                                            char* gen_type = NULL;

                                                            if (is_gen_list_function) {
                                                                 gen_type = get_list_type((yyvsp[-1].param)->type);
                                                            }

                                                            function_data fdata = get_function((yyvsp[-3].sValue));

                                                            if (fdata.num_params != num_params((yyvsp[-1].param))) {
                                                                 yyerror(cat(3, "Invalid call: incompatible number of arguments for function ", (yyvsp[-3].sValue), "."));
                                                            } else {
                                                                 function_param* formal = fdata.params;
                                                                 parameter_record* curr = (yyvsp[-1].param);
                                                                 int pos = 0;

                                                                 while(formal != NULL && curr != NULL) {
                                                                      char pos_str[12];
                                                                      sprintf(pos_str, "%d", pos);
                                                                      char* formal_type = formal->type;

                                                                      if (gen_type != NULL && strcmp(formal_type, "_") == 0) {
                                                                           formal_type = gen_type;
                                                                      }

                                                                      if(!type_check(formal_type, curr->type)) {
                                                                           yyerror(cat(8, "Invalid call: argument ", pos_str,  " of function ", (yyvsp[-3].sValue), " expected ", formal_type, ", received ", curr->type));
                                                                      }
                                                                      formal = formal->next;
                                                                      curr = curr->next;
                                                                      pos++;
                                                                 }
                                                            }


                                                            (yyval.rec) = build_function_call((yyvsp[-3].sValue), (yyvsp[-1].param));
                                                            (yyval.rec)->type = get_function_return_type((yyvsp[-3].sValue));

                                                            free(gen_type);
                                                       }
                                                  }
                                                  free((yyvsp[-3].sValue));
                                                  if ((yyvsp[-1].param)) free_param((yyvsp[-1].param));


                                                  }
#line 3095 "y.tab.c"
    break;

  case 116: /* parameters_call: expr  */
#line 1007 "parser.y"
                                                             {
                                                                 (yyval.param) = create_param((yyvsp[0].rec)->code, (yyvsp[0].rec)->type);
                                                                 free_record((yyvsp[0].rec));
                                                             }
#line 3104 "y.tab.c"
    break;

  case 117: /* parameters_call: parameters_call COMMA expr  */
#line 1011 "parser.y"
                                                             {
                                                                 (yyval.param) = add_param((yyvsp[-2].param), create_param((yyvsp[0].rec)->code, (yyvsp[0].rec)->type));
                                                                 free_record((yyvsp[0].rec));
                                                             }
#line 3113 "y.tab.c"
    break;

  case 118: /* assignment: assignable assignment_operator assignment_expr  */
#line 1017 "parser.y"
                                                             {

                                                                char * s_code;
                                                                char * assigned_type = strdup((yyvsp[-2].identifier_ref_rec)->type);

                                                                if(is_const_variable(stack, (yyvsp[-2].identifier_ref_rec)->code)) {
                                                                      yyerror(cat(3, "Invalid operator: cannot assign to constant variable ", (yyvsp[-2].identifier_ref_rec)->code, "."));
                                                                      s_code = strdup("");
                                                                }

                                                                if (type_check(assigned_type, "string")) {

                                                                    if (strcmp((yyvsp[-1].sValue), " = ") == 0) {
                                                                      s_code = cat(5, "strCopy(", (yyvsp[-2].identifier_ref_rec)->code, ", ", (yyvsp[0].rec)->code, ")");
                                                                    }

                                                                    else if (strcmp((yyvsp[-1].sValue), " += ") == 0) {
                                                                      s_code = cat(6, (yyvsp[-2].identifier_ref_rec)->code, " = strConcat(", (yyvsp[-2].identifier_ref_rec)->code, ", ", (yyvsp[0].rec)->code, ")");
                                                                    }
                                                                    else {
                                                                      yyerror(cat(3, "Invalid operator '", (yyvsp[-1].sValue), "' for string assignment."));
                                                                      s_code = strdup("");
                                                                    }
                                                                } else {
                                                                    if (strcmp((yyvsp[-1].sValue), " = ") != 0) {
                                                                      if (!type_check(assigned_type, "int") && !type_check(assigned_type, "float")) {
                                                                           yyerror(cat(2, "Invalid type: expected int or float, received ", (yyvsp[-2].identifier_ref_rec)->type));
                                                                      }
                                                                    } else if ((yyvsp[-2].identifier_ref_rec)->setter_code != NULL) {
                                                                      s_code = cat(5, (yyvsp[-2].identifier_ref_rec)->setter_code, (yyvsp[0].rec)->code, ", ", translate_type((yyvsp[0].rec)->type), ")");
                                                                      free((yyvsp[-2].identifier_ref_rec)->setter_code);
                                                                    } else {
                                                                      s_code = cat(3, (yyvsp[-2].identifier_ref_rec)->code, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                                                    }
                                                                }

                                                                if (!type_check((yyvsp[-2].identifier_ref_rec)->type, (yyvsp[0].rec)->type)) {
                                                                      yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].identifier_ref_rec)->type , " , received ", (yyvsp[0].rec)->type));
                                                                 }

                                                                (yyval.rec) = create_record(s_code, assigned_type);
                                                                free((yyvsp[-2].identifier_ref_rec)->code);
                                                                free((yyvsp[-2].identifier_ref_rec)->type);
                                                                free((yyvsp[-1].sValue));
                                                                free_record((yyvsp[0].rec));
                                                                free(s_code);
                                                                free(assigned_type);
                                                             }
#line 3166 "y.tab.c"
    break;

  case 119: /* assignment_command: assignment SEMICOLON  */
#line 1067 "parser.y"
                                          {
                                             char *s = cat(2, (yyvsp[-1].rec)->code, ";");
                                             free_record((yyvsp[-1].rec));
                                             (yyval.rec) = create_record(s, "");
                                             free(s);
                                          }
#line 3177 "y.tab.c"
    break;

  case 120: /* assignable: identifier_ref  */
#line 1075 "parser.y"
                                   {
                                         (yyval.identifier_ref_rec) = (yyvsp[0].identifier_ref_rec);

                                        if ((yyvsp[0].identifier_ref_rec)->ref_code != NULL) {
                                             free((yyval.identifier_ref_rec)->ref_code);
                                        }

                                         if ((yyvsp[0].identifier_ref_rec)->dimension > 0) {
                                              yyerror("Invalid assignment to array");
                                         }
                                   }
#line 3193 "y.tab.c"
    break;

  case 121: /* assignable: val  */
#line 1086 "parser.y"
                                   {
                                        (yyval.identifier_ref_rec) = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                        (yyval.identifier_ref_rec)->code = strdup((yyvsp[0].rec)->code);
                                        (yyval.identifier_ref_rec)->type = strdup((yyvsp[0].rec)->type);
                                        (yyval.identifier_ref_rec)->dimension = 0;
                                        (yyval.identifier_ref_rec)->ref_code = NULL;
                                        (yyval.identifier_ref_rec)->setter_code = NULL;
                                        free_record((yyvsp[0].rec));
                                   }
#line 3207 "y.tab.c"
    break;

  case 122: /* val: VAL LPAREN target RPAREN  */
#line 1097 "parser.y"
                                   {
                                        char *s = cat(3, "*(", (yyvsp[-1].rec)->code, ")");

                                        char* type = (yyvsp[-1].rec)->type;

                                        if(!is_ptr(type)) {
                                             yyerror(cat(2, "Invalid type: expected ptr, received ", type));
                                        } else {
                                             type = get_ptr_type(type);
                                        }


                                        (yyval.rec) = create_record(s, type);
                                        free_record((yyvsp[-1].rec));
                                        free(s);
                                   }
#line 3228 "y.tab.c"
    break;

  case 123: /* assignment_operator: ASSIGNMENT  */
#line 1115 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" = ");}
#line 3234 "y.tab.c"
    break;

  case 124: /* assignment_operator: ASSIGNMENT_MUL  */
#line 1116 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" *= ");}
#line 3240 "y.tab.c"
    break;

  case 125: /* assignment_operator: ASSIGNMENT_DIV  */
#line 1117 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" /= ");}
#line 3246 "y.tab.c"
    break;

  case 126: /* assignment_operator: ASSIGNMENT_MOD  */
#line 1118 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" %= ");}
#line 3252 "y.tab.c"
    break;

  case 127: /* assignment_operator: ASSIGNMENT_ADD  */
#line 1119 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" += ");}
#line 3258 "y.tab.c"
    break;

  case 128: /* assignment_operator: ASSIGNMENT_SUB  */
#line 1120 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" -= ");}
#line 3264 "y.tab.c"
    break;

  case 129: /* assignment_expr: expr  */
#line 1123 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 3270 "y.tab.c"
    break;

  case 130: /* assignment_expr: allocation  */
#line 1124 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 3276 "y.tab.c"
    break;

  case 131: /* deletion: DELETE LPAREN identifier_ref RPAREN SEMICOLON  */
#line 1127 "parser.y"
                                                            {
                                                                 char * s = cat(5, "free", "(,", (yyvsp[-2].identifier_ref_rec)->code, ")", ";");
                                                                 free((yyvsp[-2].identifier_ref_rec)->code);
                                                                 free((yyvsp[-2].identifier_ref_rec)->type);
                                                                 (yyval.rec) = create_record(s, "");
                                                                 free(s);
                                                            }
#line 3288 "y.tab.c"
    break;

  case 132: /* identifier_ref: ID  */
#line 1136 "parser.y"
                                                       {
                                                            char* type;
                                                            int dimension = 0;
                                                            if (!exists_scope_parent(stack, (yyvsp[0].sValue))) {
                                                                 yyerror(cat(3, "Variable '", (yyvsp[0].sValue), "' is not declared"));
                                                                 type = strdup("");
                                                            } else {
                                                                 variable_data var = get_variable(stack, (yyvsp[0].sValue));
                                                                 type = strdup(var.type);
                                                                 dimension = var.dimension;
                                                            }

                                                            (yyval.identifier_ref_rec) = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                                            (yyval.identifier_ref_rec)->code = strdup((yyvsp[0].sValue));
                                                            (yyval.identifier_ref_rec)->type = type;
                                                            (yyval.identifier_ref_rec)->dimension = dimension;
                                                            (yyval.identifier_ref_rec)->setter_code = NULL;
                                                            (yyval.identifier_ref_rec)->ref_code = NULL;
                                                            free((yyvsp[0].sValue));
                                                       }
#line 3313 "y.tab.c"
    break;

  case 133: /* identifier_ref: identifier_ref LBRACKET expr RBRACKET  */
#line 1156 "parser.y"
                                                       {
                                                            char* s;
                                                            char* setter_code = NULL;
                                                            char* ref_code = NULL;
                                                            char* type;
                                                            int dimension = 0;
                                                            if (is_list((yyvsp[-3].identifier_ref_rec)->type)) {
                                                                 s = cat(5, "_listGet(", (yyvsp[-3].identifier_ref_rec)->code, ", ", (yyvsp[-1].rec)->code, ")");
                                                                 setter_code = cat(5, "_listSet(&", (yyvsp[-3].identifier_ref_rec)->code, ", ", (yyvsp[-1].rec)->code, ", ");
                                                                 type = get_list_type((yyvsp[-3].identifier_ref_rec)->type);
                                                                 char* translated_type = translate_type(type);
                                                                 ref_code = cat(7, "((", translated_type, "*)", (yyvsp[-3].identifier_ref_rec)->code, ".data[", (yyvsp[-1].rec)->code, "])");
                                                                 free(translated_type);
                                                            } else if (is_ptr((yyvsp[-3].identifier_ref_rec)->type)) {
                                                                 s = cat(4, (yyvsp[-3].identifier_ref_rec)->code, "[", (yyvsp[-1].rec)->code, "]");
                                                                 type = get_ptr_type((yyvsp[-3].identifier_ref_rec)->type);
                                                                 dimension = (yyvsp[-3].identifier_ref_rec)->dimension - 1;
                                                            } else {
                                                                 yyerror(cat(2, "Invalid type: expected ptr or list, received ", (yyvsp[-1].rec)->type));
                                                            }
                                                            (yyval.identifier_ref_rec) = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                                            (yyval.identifier_ref_rec)->code = s;
                                                            (yyval.identifier_ref_rec)->setter_code = setter_code;
                                                            (yyval.identifier_ref_rec)->ref_code = ref_code;
                                                            (yyval.identifier_ref_rec)->type = type;
                                                            (yyval.identifier_ref_rec)->dimension = dimension;
                                                            free((yyvsp[-3].identifier_ref_rec)->code);
                                                            free((yyvsp[-3].identifier_ref_rec)->type);
                                                            free_record((yyvsp[-1].rec));
                                                       }
#line 3348 "y.tab.c"
    break;

  case 134: /* identifier_ref: identifier_ref DOT ID  */
#line 1186 "parser.y"
                                        {
                                             char * s = cat(3, (yyvsp[-2].identifier_ref_rec)->code, ".", (yyvsp[0].sValue));
                                             char * type;
                                             int dimension = 0;

                                             if(!is_struct((yyvsp[-2].identifier_ref_rec)->type)) {
                                                  yyerror(cat(2, "Invalid type: expected struct, received ", (yyvsp[-2].identifier_ref_rec)->type));
                                                  type = strdup("");
                                             } else if(!struct_has_attr((yyvsp[-2].identifier_ref_rec)->type, (yyvsp[0].sValue))) {
                                                  yyerror(cat(2, "Invalid: struct does not have the attribute ", (yyvsp[-2].identifier_ref_rec)->type));
                                                  type = strdup("");
                                             } else {
                                                  struct_attr attr = get_struct_attr((yyvsp[-2].identifier_ref_rec)->type, (yyvsp[0].sValue));
                                                  type = strdup(attr.type);
                                                  dimension = attr.dimension;
                                             }

                                             (yyval.identifier_ref_rec) = (identifier_ref_record*) malloc(sizeof(identifier_ref_record));
                                             (yyval.identifier_ref_rec)->code = s;
                                             (yyval.identifier_ref_rec)->type = type;
                                             (yyval.identifier_ref_rec)->dimension = dimension;
                                             (yyval.identifier_ref_rec)->setter_code = NULL;
                                             (yyval.identifier_ref_rec)->ref_code = NULL;

                                             free((yyvsp[-2].identifier_ref_rec)->code);
                                             free((yyvsp[-2].identifier_ref_rec)->type);
                                             free((yyvsp[0].sValue));
                                        }
#line 3381 "y.tab.c"
    break;

  case 135: /* expr: or_expr  */
#line 1216 "parser.y"
                { (yyval.rec) = (yyvsp[0].rec);}
#line 3387 "y.tab.c"
    break;

  case 136: /* or_expr: and_expr  */
#line 1219 "parser.y"
                                       { (yyval.rec) = (yyvsp[0].rec);}
#line 3393 "y.tab.c"
    break;

  case 137: /* or_expr: or_expr or_operator and_expr  */
#line 1220 "parser.y"
                                       {
                                             if (!type_check((yyvsp[-2].rec)->type, "boolean")) {
                                                  yyerror(cat(2, "Invalid type: expected boolean, received ", (yyvsp[-2].rec)->type));
                                             }

                                             if (!type_check((yyvsp[-2].rec)->type, (yyvsp[0].rec)->type)) {
                                                  yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].rec)->type , " , received ", (yyvsp[0].rec)->type));
                                             }

                                             char * s = cat(3, (yyvsp[-2].rec)->code, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                             free_record((yyvsp[-2].rec));
                                             free((yyvsp[-1].sValue));
                                             free_record((yyvsp[0].rec));
                                             (yyval.rec) = create_record(s, "boolean");
                                             free(s);
                                        }
#line 3414 "y.tab.c"
    break;

  case 138: /* or_operator: OR  */
#line 1238 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" | ");}
#line 3420 "y.tab.c"
    break;

  case 139: /* or_operator: ORC  */
#line 1239 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" || ");}
#line 3426 "y.tab.c"
    break;

  case 140: /* and_expr: eq_expr  */
#line 1242 "parser.y"
                                                  {(yyval.rec) = (yyvsp[0].rec);}
#line 3432 "y.tab.c"
    break;

  case 141: /* and_expr: and_expr and_operator eq_expr  */
#line 1243 "parser.y"
                                            {
                                                  if (!type_check((yyvsp[-2].rec)->type, "boolean")) {
                                                       yyerror(cat(2, "Invalid type: expected boolean, received ", (yyvsp[-2].rec)->type));
                                                  }

                                                  if (!type_check((yyvsp[-2].rec)->type, (yyvsp[0].rec)->type)) {
                                                       yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].rec)->type , " , received ", (yyvsp[0].rec)->type));
                                                  }

                                                  char * s = cat(3, (yyvsp[-2].rec)->code, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                                  free_record((yyvsp[-2].rec));
                                                  free((yyvsp[-1].sValue));
                                                  free_record((yyvsp[0].rec));
                                                  (yyval.rec) = create_record(s, "boolean");
                                                  free(s);
                                             }
#line 3453 "y.tab.c"
    break;

  case 142: /* and_operator: AND  */
#line 1261 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" & ");}
#line 3459 "y.tab.c"
    break;

  case 143: /* and_operator: ANDC  */
#line 1262 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" && ");}
#line 3465 "y.tab.c"
    break;

  case 144: /* eq_expr: relational_expr  */
#line 1265 "parser.y"
                                                                                                    {(yyval.rec) = (yyvsp[0].rec);}
#line 3471 "y.tab.c"
    break;

  case 145: /* eq_expr: eq_expr eq_operator relational_expr  */
#line 1266 "parser.y"
                                                  {
                                                        char *s;

                                                        if (type_check((yyvsp[-2].rec)->type, "string")) {

                                                            if (strcmp((yyvsp[-1].sValue), " == ") == 0) {
                                                                s = cat(4, "isEquals(", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, ")");
                                                                (yyval.rec) = create_record(s, "boolean");

                                                            } else if (strcmp((yyvsp[-1].sValue), " != ") == 0) {
                                                                s = cat(5, "!", "isEquals(", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, ")");
                                                                (yyval.rec) = create_record(s, "boolean");

                                                            }
                                                        } else {

                                                            s = cat(3, (yyvsp[-2].rec)->code, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                                            (yyval.rec) = create_record(s, "boolean");
                                                        }

                                                       if (!type_check((yyvsp[-2].rec)->type, (yyvsp[0].rec)->type)) {
                                                            yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].rec)->type , " , received ", (yyvsp[0].rec)->type));
                                                       }

                                                        free_record((yyvsp[-2].rec));
                                                        free((yyvsp[-1].sValue));
                                                        free_record((yyvsp[0].rec));
                                                        free(s);
                                                  }
#line 3505 "y.tab.c"
    break;

  case 146: /* eq_operator: EQUALITY  */
#line 1297 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" == ");}
#line 3511 "y.tab.c"
    break;

  case 147: /* eq_operator: DIFFERENCE  */
#line 1298 "parser.y"
                                                                                                    {(yyval.sValue) = strdup(" != ");}
#line 3517 "y.tab.c"
    break;

  case 148: /* relational_expr: arithmetic_expr  */
#line 1301 "parser.y"
                                                                { (yyval.rec) = (yyvsp[0].rec); }
#line 3523 "y.tab.c"
    break;

  case 149: /* relational_expr: relational_expr ineq_operator arithmetic_expr  */
#line 1302 "parser.y"
                                                                {

                                                                      if (!type_check((yyvsp[-2].rec)->type, "int") && !type_check((yyvsp[-2].rec)->type, "float")) {
                                                                           yyerror(cat(2, "Invalid type: expected int or float, received ", (yyvsp[-2].rec)->type));
                                                                      }
                                                                       if (!type_check((yyvsp[-2].rec)->type, (yyvsp[0].rec)->type)) {
                                                                           yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].rec)->type , " , received ", (yyvsp[0].rec)->type));
                                                                      }

                                                                      char * s = cat(3, (yyvsp[-2].rec)->code, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                                                      free_record((yyvsp[-2].rec));
                                                                      free((yyvsp[-1].sValue));
                                                                      free_record((yyvsp[0].rec));
                                                                      (yyval.rec) = create_record(s, "boolean");
                                                                      free(s);
                                                                 }
#line 3544 "y.tab.c"
    break;

  case 150: /* ineq_operator: ABRACKET_OPEN  */
#line 1320 "parser.y"
                                                { (yyval.sValue) = strdup(" < "); }
#line 3550 "y.tab.c"
    break;

  case 151: /* ineq_operator: MORE_THAN_EQUALS  */
#line 1321 "parser.y"
                                                { (yyval.sValue) = strdup(" >= "); }
#line 3556 "y.tab.c"
    break;

  case 152: /* ineq_operator: ABRACKET_CLOSE  */
#line 1322 "parser.y"
                                                { (yyval.sValue) = strdup(" > "); }
#line 3562 "y.tab.c"
    break;

  case 153: /* ineq_operator: LESS_THAN_EQUALS  */
#line 1323 "parser.y"
                                                { (yyval.sValue) = strdup(" <= "); }
#line 3568 "y.tab.c"
    break;

  case 154: /* arithmetic_expr: term  */
#line 1326 "parser.y"
                                                                                                    { (yyval.rec) = (yyvsp[0].rec); }
#line 3574 "y.tab.c"
    break;

  case 155: /* arithmetic_expr: arithmetic_expr add_operator term  */
#line 1327 "parser.y"
                                                    {
                                                        char * s_code;
                                                        char * result_type = strdup((yyvsp[-2].rec)->type);

                                                        if (type_check((yyvsp[-2].rec)->type, "string") && strcmp((yyvsp[-1].sValue), " + ") == 0) {
                                                            s_code = cat(4, "strConcat(", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, ")");
                                                        } else if (type_check((yyvsp[-2].rec)->type, "int") || type_check((yyvsp[-2].rec)->type, "float")) {
                                                            s_code = cat(3, (yyvsp[-2].rec)->code, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                                        } else {
                                                            yyerror(cat(2, "Invalid type: expected int or float, received ", (yyvsp[-2].rec)->type));
                                                            s_code = strdup("");
                                                        }

                                                        if (!type_check((yyvsp[-2].rec)->type, (yyvsp[0].rec)->type)) {
                                                            yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].rec)->type , " , received ", (yyvsp[0].rec)->type));
                                                            s_code = strdup("");
                                                        }

                                                        (yyval.rec) = create_record(s_code, result_type);
                                                        free_record((yyvsp[-2].rec));
                                                        free((yyvsp[-1].sValue));
                                                        free_record((yyvsp[0].rec));
                                                        free(s_code);
                                                        free(result_type);
                                                    }
#line 3604 "y.tab.c"
    break;

  case 156: /* term: prefix_expr  */
#line 1354 "parser.y"
                                                                                                 { (yyval.rec) = (yyvsp[0].rec); }
#line 3610 "y.tab.c"
    break;

  case 157: /* term: term mult_operator prefix_expr  */
#line 1355 "parser.y"
                                        {
                                             if (strcmp((yyvsp[-1].sValue), " * ") == 0 || strcmp((yyvsp[-1].sValue), " / ") == 0) {
                                                  if (!type_check((yyvsp[-2].rec)->type, "int") && !type_check((yyvsp[-2].rec)->type, "float")) {
                                                       yyerror(cat(2, "Invalid type: expected int or float, received ", (yyvsp[-2].rec)->type));
                                                  }
                                             } else {
                                                  if (!type_check((yyvsp[-2].rec)->type, "int")) {
                                                       yyerror(cat(2, "Invalid type: expected int, received ", (yyvsp[-2].rec)->type));
                                                  }
                                             }

                                             if (!type_check((yyvsp[-2].rec)->type, (yyvsp[0].rec)->type)) {
                                                  yyerror(cat(4, "Invalid type: expected ", (yyvsp[-2].rec)->type , " , received ", (yyvsp[0].rec)->type));
                                             }

                                             char * s = cat(3, (yyvsp[-2].rec)->code, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                             (yyval.rec) = create_record(s, (yyvsp[-2].rec)->type);
                                             free_record((yyvsp[-2].rec));
                                             free((yyvsp[-1].sValue));
                                             free_record((yyvsp[0].rec));
                                             free(s);
                                        }
#line 3637 "y.tab.c"
    break;

  case 158: /* mult_operator: TIMES  */
#line 1379 "parser.y"
                         { (yyval.sValue) = strdup(" * "); }
#line 3643 "y.tab.c"
    break;

  case 159: /* mult_operator: SLASH  */
#line 1380 "parser.y"
                         { (yyval.sValue) = strdup(" / "); }
#line 3649 "y.tab.c"
    break;

  case 160: /* mult_operator: MOD  */
#line 1381 "parser.y"
                         { (yyval.sValue) = strdup(" % "); }
#line 3655 "y.tab.c"
    break;

  case 161: /* prefix_expr: postfix_expr  */
#line 1384 "parser.y"
                                                  { (yyval.rec) = (yyvsp[0].rec); }
#line 3661 "y.tab.c"
    break;

  case 162: /* prefix_expr: unary_operator postfix_expr  */
#line 1385 "parser.y"
                                                  {
                                                       if (strcmp((yyvsp[-1].sValue), " + ") == 0 || strcmp((yyvsp[-1].sValue), " - ") == 0) {
                                                            if (!type_check((yyvsp[0].rec)->type, "int") && !type_check((yyvsp[0].rec)->type, "float")) {
                                                                 yyerror(cat(2, "Invalid type: expected int or float, received ", (yyvsp[0].rec)->type));
                                                            }
                                                       } else {
                                                            if (!type_check((yyvsp[0].rec)->type, "boolean")) {
                                                                 yyerror(cat(2, "Invalid type: expected boolean, received ", (yyvsp[0].rec)->type));
                                                            }
                                                       }

                                                       char * s = cat(2, (yyvsp[-1].sValue), (yyvsp[0].rec)->code);
                                                       (yyval.rec) = create_record(s, (yyvsp[0].rec)->type);
                                                       free((yyvsp[-1].sValue));
                                                       free_record((yyvsp[0].rec));
                                                       free(s);
                                                  }
#line 3683 "y.tab.c"
    break;

  case 163: /* prefix_expr: REF LPAREN identifier_ref RPAREN  */
#line 1402 "parser.y"
                                                 {
                                                       non_constant_expr("reference");
                                                       if(is_const_variable(stack, (yyvsp[-1].identifier_ref_rec)->code)) {
                                                            yyerror(cat(3, "Invalid operator: cannot assign to constant variable ", (yyvsp[-1].identifier_ref_rec)->code, "."));
                                                       }

                                                       char * s;

                                                       if ((yyvsp[-1].identifier_ref_rec)->ref_code != NULL) {
                                                            s = strdup((yyvsp[-1].identifier_ref_rec)->ref_code);
                                                            free((yyvsp[-1].identifier_ref_rec)->ref_code);
                                                       } else {
                                                            s = cat(4,"&","(", (yyvsp[-1].identifier_ref_rec)->code,")");
                                                       }

                                                       if ((yyvsp[-1].identifier_ref_rec)->setter_code != NULL) {
                                                            free((yyvsp[-1].identifier_ref_rec)->setter_code);
                                                       }

                                                       char* type = cat(3, "ptr<", (yyvsp[-1].identifier_ref_rec)->type, ">");
                                                       free((yyvsp[-1].identifier_ref_rec)->code);
                                                       free((yyvsp[-1].identifier_ref_rec)->type);
                                                       (yyval.rec) = create_record(s, type);
                                                       free(s);
                                                       free(type);
                                                  }
#line 3714 "y.tab.c"
    break;

  case 164: /* prefix_expr: cast  */
#line 1428 "parser.y"
                                                                                                      { (yyval.rec) = (yyvsp[0].rec); }
#line 3720 "y.tab.c"
    break;

  case 165: /* cast: LPAREN PRIM_TYPE RPAREN postfix_expr  */
#line 1431 "parser.y"
                                             {
                                                  if (type_check((yyvsp[-2].sValue), "float")) {
                                                       if (type_check((yyvsp[0].rec)->type, "int")) {
                                                            char * s = cat(2,"(float) ", (yyvsp[0].rec)->code);
                                                            (yyval.rec) = create_record(s, "float");
                                                            free(s);
                                                       } else {
                                                            yyerror(cat(3, "Invalid cast from ", (yyvsp[0].rec)->type, " to float"));
                                                       }
                                                  } else if (type_check((yyvsp[-2].sValue), (yyvsp[0].rec)->type)) {
                                                       (yyval.rec) = create_record((yyvsp[0].rec)->code, (yyvsp[0].rec)->type);
                                                  } else{
                                                       yyerror(cat(2, "Invalid cast to ", (yyvsp[-2].sValue)));
                                                  }

                                                  free((yyvsp[-2].sValue));
                                                  free_record((yyvsp[0].rec));
                                             }
#line 3743 "y.tab.c"
    break;

  case 166: /* unary_operator: add_operator  */
#line 1451 "parser.y"
                              { (yyval.sValue) = (yyvsp[0].sValue); }
#line 3749 "y.tab.c"
    break;

  case 167: /* unary_operator: NOT  */
#line 1452 "parser.y"
                              { (yyval.sValue) = strdup("!"); }
#line 3755 "y.tab.c"
    break;

  case 168: /* add_operator: PLUS  */
#line 1455 "parser.y"
                         { (yyval.sValue) = strdup(" + "); }
#line 3761 "y.tab.c"
    break;

  case 169: /* add_operator: MINUS  */
#line 1456 "parser.y"
                         { (yyval.sValue) = strdup(" - "); }
#line 3767 "y.tab.c"
    break;

  case 170: /* postfix_expr: target  */
#line 1459 "parser.y"
                         {
                              if (is_enum_group((yyvsp[0].rec)->type)) {
                                   yyerror("Invalid enum expression");
                              }
                              (yyval.rec) = (yyvsp[0].rec);
                         }
#line 3778 "y.tab.c"
    break;

  case 171: /* postfix_expr: literal  */
#line 1465 "parser.y"
                         { (yyval.rec) = (yyvsp[0].rec); }
#line 3784 "y.tab.c"
    break;

  case 172: /* base: ID  */
#line 1468 "parser.y"
                              {
                                   non_constant_expr("variable access");
                                   if (is_enum((yyvsp[0].sValue)) & !exists_scope_parent(stack, (yyvsp[0].sValue))) {
                                        char* type = cat(3, "enum_group<", (yyvsp[0].sValue), ">");

                                        (yyval.rec) = create_record((yyvsp[0].sValue), type);
                                        free(type);
                                   } else if (!exists_scope_parent(stack, (yyvsp[0].sValue))) {
                                        yyerror(cat(3, "Variable '", (yyvsp[0].sValue), "' is not declared"));
                                        (yyval.rec) = create_record((yyvsp[0].sValue), "");
                                   } else {
                                        char* type = get_variable_type(stack, (yyvsp[0].sValue));

                                        (yyval.rec) = create_record((yyvsp[0].sValue), type);
                                        free(type);
                                   }

                                   free((yyvsp[0].sValue));
                              }
#line 3808 "y.tab.c"
    break;

  case 173: /* base: val  */
#line 1487 "parser.y"
                              {
                                   (yyval.rec) = (yyvsp[0].rec);
                              }
#line 3816 "y.tab.c"
    break;

  case 174: /* base: LPAREN expr RPAREN  */
#line 1490 "parser.y"
                              {
                                   printf("em (expr) %s", (yyvsp[-1].rec)->code);
                                   char * s = cat(3,"(", (yyvsp[-1].rec)->code,")");
                                   free_record((yyvsp[-1].rec));
                                   (yyval.rec) = create_record(s, (yyvsp[-1].rec)->type);
                                   free(s);
                              }
#line 3828 "y.tab.c"
    break;

  case 175: /* target: base  */
#line 1500 "parser.y"
                                        { (yyval.rec) = (yyvsp[0].rec); }
#line 3834 "y.tab.c"
    break;

  case 176: /* target: function_call  */
#line 1501 "parser.y"
                                        {
                                             non_constant_expr("function call");
                                             (yyval.rec) = (yyvsp[0].rec);
                                        }
#line 3843 "y.tab.c"
    break;

  case 177: /* target: target LBRACKET expr RBRACKET  */
#line 1505 "parser.y"
                                        {
                                             if (!type_check((yyvsp[-1].rec)->type, "int")) {
                                                  yyerror(cat(2, "Invalid type: expected int, received ", (yyvsp[-3].rec)->type));
                                             }

                                             if (is_list((yyvsp[-3].rec)->type)) {
                                                 char* type = get_list_type((yyvsp[-3].rec)->type);
                                                 char * s = cat(7, "_listGet(&", (yyvsp[-3].rec)->code, ", ", (yyvsp[-1].rec)->code, ", ", translate_type(type), ")");
                                                 (yyval.rec) = create_record(s, type);
                                                 free(s);
                                                 free(type);
                                             } else if (type_check((yyvsp[-3].rec)->type, "string")) {
                                                  char * s = cat(4, (yyvsp[-3].rec)->code, "[", (yyvsp[-1].rec)->code,"]");
                                                  (yyval.rec) = create_record(s, "char");
                                                  free(s);
                                             } else if (is_ptr((yyvsp[-3].rec)->type)) {
                                                  char * s = cat(4, (yyvsp[-3].rec)->code, "[", (yyvsp[-1].rec)->code,"]");
                                                  char* type = get_ptr_type((yyvsp[-3].rec)->type);
                                                  (yyval.rec) = create_record(s, type);
                                                  free(s);
                                                  free(type);
                                             } else {
                                                  yyerror(cat(2, "Invalid type: expected ptr, list, or string, received ", (yyvsp[-3].rec)->type));
                                             }

                                             free_record((yyvsp[-3].rec));
                                             free_record((yyvsp[-1].rec));

                                        }
#line 3877 "y.tab.c"
    break;

  case 178: /* target: target DOT ID  */
#line 1534 "parser.y"
                                        {
                                             if (is_enum_group((yyvsp[-2].rec)->type)) {
                                                  char* type = get_enum_group_name((yyvsp[-2].rec)->type);

                                                  if (!enum_has_attr(type, (yyvsp[0].sValue))) {
                                                       yyerror(cat(5, "Invalid enum value '", (yyvsp[0].sValue), "' for enum '", type, "'"));
                                                  }

                                                  char* s = cat(3, type, "__", (yyvsp[0].sValue));

                                                  (yyval.rec) = create_record(s, type);

                                                  free(type);

                                                  free(s);
                                             } else if(!is_struct((yyvsp[-2].rec)->type)) {
                                                  yyerror(cat(2, "Invalid type: expected struct, received ", (yyvsp[-2].rec)->type));
                                             } else if(!struct_has_attr((yyvsp[-2].rec)->type, (yyvsp[0].sValue))) {
                                                  yyerror(cat(2, "Invalid: struct does not have the attribute ", (yyvsp[-2].rec)->type));
                                             } else {
                                                  char * s = cat(3, (yyvsp[-2].rec)->code, ".", (yyvsp[0].sValue));

                                                  (yyval.rec) = create_record(s, get_struct_attr((yyvsp[-2].rec)->type, (yyvsp[0].sValue)).type);

                                                  free(s);
                                             }

                                             free_record((yyvsp[-2].rec));
                                             free((yyvsp[0].sValue));

                                        }
#line 3913 "y.tab.c"
    break;

  case 179: /* literal: INTEGER  */
#line 1568 "parser.y"
                    {
                         (yyval.rec) = create_record((yyvsp[0].sValue), "int");
                         free((yyvsp[0].sValue));
                    }
#line 3922 "y.tab.c"
    break;

  case 180: /* literal: CHAR  */
#line 1572 "parser.y"
                    {
                         (yyval.rec) = create_record((yyvsp[0].sValue), "char");
                         free((yyvsp[0].sValue));
                    }
#line 3931 "y.tab.c"
    break;

  case 181: /* literal: STRING  */
#line 1576 "parser.y"
                    {
                         (yyval.rec) = create_record((yyvsp[0].sValue), "string");
                         free((yyvsp[0].sValue));
                    }
#line 3940 "y.tab.c"
    break;

  case 182: /* literal: REAL  */
#line 1580 "parser.y"
                    {
                         (yyval.rec) = create_record((yyvsp[0].sValue), "float");
                         free((yyvsp[0].sValue));
                    }
#line 3949 "y.tab.c"
    break;

  case 183: /* literal: BOOL  */
#line 1584 "parser.y"
                    {
                         (yyval.rec) = create_record((yyvsp[0].sValue), "boolean");
                         free((yyvsp[0].sValue));
                    }
#line 3958 "y.tab.c"
    break;

  case 184: /* literal: NULLISH  */
#line 1588 "parser.y"
                    {
                         (yyval.rec) = create_record("NULL", "ptr<_>");
                    }
#line 3966 "y.tab.c"
    break;


#line 3970 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1593 "parser.y"


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


void non_constant_expr(char* name) {
     if (strcmp(stack->top->name, "") == 0) {
          yyerror(cat(2, "Non constant expression at global scope: ", name));
     }
}
