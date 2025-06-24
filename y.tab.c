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
#include <stdarg.h>

#include "./lib/record.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;

char *cat(int, ...);


#line 89 "y.tab.c"

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
    MOD = 320                      /* MOD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

	char   cValue; 	/* char value */
	char * sValue;      /* string value */
     struct record * rec;

#line 210 "y.tab.c"

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
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_declarations = 68,              /* declarations  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_var_declaration = 70,           /* var_declaration  */
  YYSYMBOL_const_declaration = 71,         /* const_declaration  */
  YYSYMBOL_type_declaration = 72,          /* type_declaration  */
  YYSYMBOL_declaration_line = 73,          /* declaration_line  */
  YYSYMBOL_declaration_item = 74,          /* declaration_item  */
  YYSYMBOL_declaration_term = 75,          /* declaration_term  */
  YYSYMBOL_initialization = 76,            /* initialization  */
  YYSYMBOL_initialization_list = 77,       /* initialization_list  */
  YYSYMBOL_allocation = 78,                /* allocation  */
  YYSYMBOL_type = 79,                      /* type  */
  YYSYMBOL_ptr_type = 80,                  /* ptr_type  */
  YYSYMBOL_map_type = 81,                  /* map_type  */
  YYSYMBOL_list_type = 82,                 /* list_type  */
  YYSYMBOL_enum_type = 83,                 /* enum_type  */
  YYSYMBOL_enum_list = 84,                 /* enum_list  */
  YYSYMBOL_struct_type = 85,               /* struct_type  */
  YYSYMBOL_struct_vars = 86,               /* struct_vars  */
  YYSYMBOL_subprograms = 87,               /* subprograms  */
  YYSYMBOL_subprogram = 88,                /* subprogram  */
  YYSYMBOL_parameters = 89,                /* parameters  */
  YYSYMBOL_parameter = 90,                 /* parameter  */
  YYSYMBOL_statements = 91,                /* statements  */
  YYSYMBOL_statement = 92,                 /* statement  */
  YYSYMBOL_command = 93,                   /* command  */
  YYSYMBOL_jump = 94,                      /* jump  */
  YYSYMBOL_return = 95,                    /* return  */
  YYSYMBOL_return_value = 96,              /* return_value  */
  YYSYMBOL_if = 97,                        /* if  */
  YYSYMBOL_else_ifs_opt = 98,              /* else_ifs_opt  */
  YYSYMBOL_else_ifs = 99,                  /* else_ifs  */
  YYSYMBOL_else_if = 100,                  /* else_if  */
  YYSYMBOL_else_opt = 101,                 /* else_opt  */
  YYSYMBOL_else = 102,                     /* else  */
  YYSYMBOL_while = 103,                    /* while  */
  YYSYMBOL_do_while = 104,                 /* do_while  */
  YYSYMBOL_for = 105,                      /* for  */
  YYSYMBOL_for_init = 106,                 /* for_init  */
  YYSYMBOL_switch = 107,                   /* switch  */
  YYSYMBOL_cases = 108,                    /* cases  */
  YYSYMBOL_case = 109,                     /* case  */
  YYSYMBOL_default = 110,                  /* default  */
  YYSYMBOL_case_item = 111,                /* case_item  */
  YYSYMBOL_function_call = 112,            /* function_call  */
  YYSYMBOL_parameters_call = 113,          /* parameters_call  */
  YYSYMBOL_assignment = 114,               /* assignment  */
  YYSYMBOL_assignment_command = 115,       /* assignment_command  */
  YYSYMBOL_assignable = 116,               /* assignable  */
  YYSYMBOL_val = 117,                      /* val  */
  YYSYMBOL_assignment_operator = 118,      /* assignment_operator  */
  YYSYMBOL_assignment_expr = 119,          /* assignment_expr  */
  YYSYMBOL_deletion = 120,                 /* deletion  */
  YYSYMBOL_identifier_ref = 121,           /* identifier_ref  */
  YYSYMBOL_expr = 122,                     /* expr  */
  YYSYMBOL_or_expr = 123,                  /* or_expr  */
  YYSYMBOL_or_operator = 124,              /* or_operator  */
  YYSYMBOL_and_expr = 125,                 /* and_expr  */
  YYSYMBOL_and_operator = 126,             /* and_operator  */
  YYSYMBOL_eq_expr = 127,                  /* eq_expr  */
  YYSYMBOL_eq_operator = 128,              /* eq_operator  */
  YYSYMBOL_relational_expr = 129,          /* relational_expr  */
  YYSYMBOL_ineq_operator = 130,            /* ineq_operator  */
  YYSYMBOL_arithmetic_expr = 131,          /* arithmetic_expr  */
  YYSYMBOL_add_operator = 132,             /* add_operator  */
  YYSYMBOL_term = 133,                     /* term  */
  YYSYMBOL_mult_operator = 134,            /* mult_operator  */
  YYSYMBOL_prefix_expr = 135,              /* prefix_expr  */
  YYSYMBOL_cast = 136,                     /* cast  */
  YYSYMBOL_unary_operator = 137,           /* unary_operator  */
  YYSYMBOL_postfix_expr = 138,             /* postfix_expr  */
  YYSYMBOL_base = 139,                     /* base  */
  YYSYMBOL_target = 140,                   /* target  */
  YYSYMBOL_literal = 141                   /* literal  */
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
#define YYLAST   722

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    45,    46,    49,    50,    51,    54,    57,
      60,    62,    63,    66,    67,    70,    71,    74,    75,    76,
      79,    80,    83,    87,    88,    89,    90,    91,    92,    93,
      96,    99,   102,   105,   108,   109,   112,   115,   116,   119,
     120,   123,   124,   125,   126,   129,   130,   133,   136,   137,
     140,   141,   142,   143,   146,   147,   148,   149,   150,   151,
     152,   153,   156,   157,   158,   161,   164,   165,   168,   171,
     172,   175,   176,   179,   181,   182,   185,   188,   191,   194,
     197,   198,   201,   202,   205,   206,   209,   212,   215,   219,
     220,   223,   224,   227,   230,   233,   234,   237,   240,   241,
     242,   243,   244,   245,   248,   249,   252,   255,   256,   257,
     260,   263,   264,   267,   268,   271,   272,   275,   276,   279,
     280,   283,   284,   287,   288,   291,   292,   293,   294,   297,
     298,   301,   302,   305,   306,   309,   310,   311,   314,   315,
     316,   317,   320,   323,   324,   325,   328,   329,   332,   333,
     334,   337,   338,   339,   340,   344,   345,   346,   347,   348
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
  "MOD", "$accept", "program", "declarations", "declaration",
  "var_declaration", "const_declaration", "type_declaration",
  "declaration_line", "declaration_item", "declaration_term",
  "initialization", "initialization_list", "allocation", "type",
  "ptr_type", "map_type", "list_type", "enum_type", "enum_list",
  "struct_type", "struct_vars", "subprograms", "subprogram", "parameters",
  "parameter", "statements", "statement", "command", "jump", "return",
  "return_value", "if", "else_ifs_opt", "else_ifs", "else_if", "else_opt",
  "else", "while", "do_while", "for", "for_init", "switch", "cases",
  "case", "default", "case_item", "function_call", "parameters_call",
  "assignment", "assignment_command", "assignable", "val",
  "assignment_operator", "assignment_expr", "deletion", "identifier_ref",
  "expr", "or_expr", "or_operator", "and_expr", "and_operator", "eq_expr",
  "eq_operator", "relational_expr", "ineq_operator", "arithmetic_expr",
  "add_operator", "term", "mult_operator", "prefix_expr", "cast",
  "unary_operator", "postfix_expr", "base", "target", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -113,     6,   659,  -113,  -113,  -113,   165,    33,    41,    52,
      57,    65,    68,   101,  -113,  -113,  -113,  -113,   116,  -113,
    -113,  -113,  -113,  -113,   640,  -113,  -113,   117,   103,   165,
     132,   165,   165,   165,    90,   107,    36,  -113,   -30,   142,
    -113,  -113,    95,  -113,    78,  -113,    29,    99,   104,   110,
     165,   125,  -113,   117,   335,   264,   107,   122,   156,     0,
    -113,  -113,  -113,  -113,   159,  -113,  -113,   165,   123,   135,
       5,  -113,   140,  -113,  -113,  -113,  -113,  -113,   143,   145,
     287,  -113,  -113,  -113,  -113,  -113,   141,   -49,    -5,    47,
      85,     7,   -41,  -113,  -113,   276,  -113,  -113,    32,  -113,
     165,   264,  -113,  -113,  -113,   690,  -113,   146,   165,  -113,
     134,  -113,   690,   148,    24,   198,    16,   170,   172,  -113,
    -113,  -113,   335,  -113,  -113,   335,  -113,  -113,   335,  -113,
    -113,  -113,  -113,   335,  -113,  -113,   335,  -113,  -113,  -113,
     335,   335,  -113,   335,   205,   153,  -113,    58,     4,   180,
     184,   186,   189,   191,  -113,  -113,   335,   192,  -113,  -113,
     354,  -113,  -113,   190,  -113,  -113,  -113,  -113,  -113,  -113,
     194,   196,  -113,   188,  -113,  -113,    74,   690,  -113,  -113,
     389,   690,  -113,    30,  -113,  -113,   -22,    18,   276,  -113,
      -5,    47,    85,     7,   -41,  -113,   181,  -113,   335,  -113,
     264,   335,   335,   690,   335,   225,  -113,  -113,   198,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
     328,   335,   228,   419,  -113,   449,  -113,   335,  -113,  -113,
    -113,  -113,   206,  -113,   209,   212,   479,   216,   258,  -113,
     335,  -113,    19,  -113,  -113,  -113,   224,  -113,  -113,  -113,
    -113,  -113,   238,   240,   247,   241,   257,   259,  -113,   690,
     273,   244,   690,    14,  -113,   509,   335,    -3,  -113,   335,
     539,   267,   291,  -113,   263,   268,  -113,  -113,   277,   270,
    -113,   279,   283,   307,   291,  -113,   690,   690,  -113,  -113,
     690,   335,   284,  -113,  -113,  -113,   690,   690,   569,   288,
     690,  -113,   286,   599,   690,  -113,   629,  -113
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    29,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     0,    24,
      27,    28,    25,    26,     2,    39,     9,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,    11,    13,     0,
      40,    15,     0,    37,     0,    34,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
      45,    36,    38,    33,     0,    30,    32,     0,     0,     0,
       0,    12,   148,   155,   157,   159,   158,   156,     0,     0,
       0,   145,   143,   144,   152,   149,     0,   110,   111,   115,
     119,   123,   129,   133,   141,     0,   138,   151,   146,   147,
       0,     0,    14,    19,    17,     0,    47,     0,     0,    35,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    16,
     113,   114,     0,   117,   118,     0,   121,   122,     0,   125,
     127,   128,   126,     0,   131,   132,     0,   135,   136,   137,
       0,     0,   139,     0,     0,     0,    20,     0,   107,     0,
       0,     0,     0,     0,    63,    62,    66,     0,    50,    51,
       0,    48,    52,     0,    64,    54,    55,    56,    57,    58,
       0,     0,    53,     0,    96,    61,    95,     0,    46,    31,
       0,     0,    89,     0,    91,   107,     0,     0,     0,   150,
     112,   116,   120,   124,   130,   134,     0,   154,     0,    18,
       0,     0,     0,     0,     0,     0,    65,    67,     0,    44,
      49,    60,    59,    94,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,    43,     0,    90,     0,   140,    97,
     142,   153,     0,    21,     0,     0,     0,     0,   107,    81,
       0,    80,     0,   105,    93,   104,     0,   109,    42,    41,
      92,    22,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,   106,     0,     0,     0,    84,     0,
       0,     0,    69,    86,     0,     0,    82,    85,     0,     0,
      77,     0,     0,    74,    70,    71,     0,     0,    83,    78,
       0,     0,     0,    68,    75,    72,    88,    87,     0,     0,
       0,    79,     0,     0,     0,    76,     0,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,  -113,    -1,   317,  -113,  -113,   274,  -113,
     -99,  -113,   108,    13,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,   305,   281,   222,   -98,    10,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,    55,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,    79,  -113,  -113,   -38,  -113,    82,   149,
    -113,   -87,  -113,  -113,  -113,  -112,   -54,  -113,  -113,   229,
    -113,   230,  -113,   233,  -113,   223,  -113,   227,  -113,   226,
    -113,  -113,   -91,  -113,   249,  -113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    14,   158,   159,    17,    36,    37,    38,
     102,   147,   103,    27,    19,    20,    21,    22,    46,    23,
      44,    24,    25,    59,    60,   160,   161,   162,   163,   164,
     206,   165,   283,   284,   285,   293,   294,   166,   167,   168,
     240,   169,   267,   268,   278,   273,    84,   183,   171,   172,
     173,    85,   220,   244,   175,   176,   104,    87,   122,    88,
     125,    89,   128,    90,   133,    91,   136,    92,   140,    93,
      94,    95,    96,    97,    98,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,    15,   146,   186,   142,    26,     3,   -29,    54,   120,
     121,   266,   275,   228,   180,    18,   221,   185,   174,    72,
      55,   222,   137,   138,   139,   174,   118,    72,    43,    73,
      74,    75,    76,    77,   276,   107,    28,    39,   114,    79,
     113,    79,   108,    62,    47,    48,    49,   108,    78,    79,
     141,   123,   124,   229,   257,    58,   143,   221,    80,   182,
     184,   144,   222,    68,    58,   226,    63,   170,   134,   135,
     143,    64,   227,   174,   170,   144,    52,    29,    53,   223,
     110,     4,     5,   225,    81,    82,    83,   118,    30,   196,
     174,   126,   127,   174,   174,   199,   242,   230,     4,     5,
     200,   233,   207,    31,    34,   236,     8,     9,    10,    11,
      12,    32,   221,   145,    33,    61,   174,   222,   174,    35,
      41,    58,   170,     8,     9,    10,    11,    12,     4,     5,
      57,   129,   130,   131,   132,    45,   174,    42,   174,   170,
      50,    51,   170,   170,   232,    56,    65,   234,   235,   174,
     237,    66,    67,     8,     9,    10,    11,    12,   105,   106,
      69,   265,   109,   111,   270,   170,   245,   246,     4,     5,
     210,   112,   174,   250,   114,   174,   174,   115,   174,   116,
     119,   179,   177,   174,   181,   170,   256,   170,   296,   297,
     210,   198,   298,     8,     9,    10,    11,    12,   170,   174,
     174,   185,   303,   174,   239,   188,   306,   189,   197,   174,
     174,   174,   274,   174,   201,   279,   174,   174,   202,   174,
     231,   170,   203,   204,   170,   205,   208,   170,   238,     5,
     211,   247,   170,   210,   212,   210,   213,   299,   214,   215,
     216,   217,   218,   219,   252,   251,   210,   253,   170,   170,
      79,   255,   170,     8,     9,    10,    11,    12,   170,   170,
     170,   -29,   170,   258,   261,   170,   170,    72,   170,    73,
      74,    75,    76,    77,   259,   210,   260,   262,   269,    72,
     210,    73,    74,    75,    76,    77,   100,   266,    78,    79,
      72,   117,    73,    74,    75,    76,    77,   263,    80,   264,
     101,    79,   281,   282,   286,   289,   210,   210,   210,   287,
     141,    78,    79,   210,   288,   290,   210,   291,   292,    16,
     300,    80,   304,   302,    81,    82,    83,    71,   243,    40,
     178,    72,    70,    73,    74,    75,    76,    77,    72,   295,
      73,    74,    75,    76,    77,   271,   277,    81,    82,    83,
     100,   190,    78,    79,   241,   191,   193,   148,     5,    78,
      79,   192,    80,   194,   149,   187,   195,   150,     0,    80,
     151,   152,   153,   154,   155,   156,     0,   157,     0,    79,
       6,     0,     8,     9,    10,    11,    12,     0,    81,    82,
      83,   209,   148,     5,     0,    81,    82,    83,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   224,     0,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   248,     0,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   249,     0,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   254,     0,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   272,     0,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   280,     0,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   301,     0,     0,   149,
       0,     0,   150,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,   148,     5,     0,     0,   305,     0,     0,   149,
       0,     0,   150,     4,     5,   151,   152,   153,   154,   155,
     156,     0,   157,     0,    79,     6,     0,     8,     9,    10,
      11,    12,     4,     5,     0,     0,   307,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,   148,     5,     0,     0,     0,     0,     0,
     149,     0,     0,   150,     0,     0,   151,   152,   153,   154,
     155,   156,     0,   157,     0,    79,     6,     0,     8,     9,
      10,    11,    12
};

static const yytype_int16 yycheck[] =
{
      54,     2,   101,   115,    95,     6,     0,     3,    38,    58,
      59,    14,    15,    35,   112,     2,    38,     3,   105,     3,
      50,    43,    63,    64,    65,   112,    80,     3,    29,     5,
       6,     7,     8,     9,    37,    35,     3,    24,    34,    25,
      35,    25,    42,    44,    31,    32,    33,    42,    24,    25,
      34,    56,    57,    35,    35,    42,    38,    38,    34,    35,
     114,    43,    43,    50,    51,    35,    37,   105,    61,    62,
      38,    42,    42,   160,   112,    43,    40,    36,    42,   177,
      67,     3,     4,   181,    60,    61,    62,   141,    36,   143,
     177,    44,    45,   180,   181,    37,   208,   188,     3,     4,
      42,   200,   156,    46,     3,   203,    28,    29,    30,    31,
      32,    46,    38,   100,    46,    37,   203,    43,   205,     3,
       3,   108,   160,    28,    29,    30,    31,    32,     3,     4,
      35,    46,    47,    48,    49,     3,   223,    34,   225,   177,
      50,    34,   180,   181,   198,     3,    47,   201,   202,   236,
     204,    47,    42,    28,    29,    30,    31,    32,    36,     3,
      35,   259,     3,    40,   262,   203,   220,   221,     3,     4,
     160,    36,   259,   227,    34,   262,   263,    34,   265,    34,
      39,    47,    36,   270,    36,   223,   240,   225,   286,   287,
     180,    38,   290,    28,    29,    30,    31,    32,   236,   286,
     287,     3,   300,   290,   205,    35,   304,    35,     3,   296,
     297,   298,   266,   300,    34,   269,   303,   304,    34,   306,
      39,   259,    36,    34,   262,    34,    34,   265,     3,     4,
      40,     3,   270,   223,    40,   225,    40,   291,    50,    51,
      52,    53,    54,    55,    35,    39,   236,    35,   286,   287,
      25,    35,   290,    28,    29,    30,    31,    32,   296,   297,
     298,     3,   300,    39,    17,   303,   304,     3,   306,     5,
       6,     7,     8,     9,    36,   265,    36,    36,    34,     3,
     270,     5,     6,     7,     8,     9,    22,    14,    24,    25,
       3,     4,     5,     6,     7,     8,     9,    40,    34,    40,
      36,    25,    35,    12,    41,    35,   296,   297,   298,    41,
      34,    24,    25,   303,    37,    36,   306,    34,    11,     2,
      36,    34,    36,    35,    60,    61,    62,    53,   220,    24,
     108,     3,    51,     5,     6,     7,     8,     9,     3,   284,
       5,     6,     7,     8,     9,   263,   267,    60,    61,    62,
      22,   122,    24,    25,   205,   125,   133,     3,     4,    24,
      25,   128,    34,   136,    10,   116,   140,    13,    -1,    34,
      16,    17,    18,    19,    20,    21,    -1,    23,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    -1,    60,    61,
      62,    37,     3,     4,    -1,    60,    61,    62,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    -1,    -1,    10,
      -1,    -1,    13,     3,     4,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,     3,     4,    -1,    -1,    37,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,     3,     4,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     3,     4,    26,    27,    28,    29,
      30,    31,    32,    33,    69,    70,    71,    72,    79,    80,
      81,    82,    83,    85,    87,    88,    70,    79,     3,    36,
      36,    46,    46,    46,     3,     3,    73,    74,    75,    79,
      88,     3,    34,    70,    86,     3,    84,    79,    79,    79,
      50,    34,    40,    42,    38,    50,     3,    35,    79,    89,
      90,    37,    70,    37,    42,    47,    47,    42,    79,    35,
      89,    74,     3,     5,     6,     7,     8,     9,    24,    25,
      34,    60,    61,    62,   112,   117,   122,   123,   125,   127,
     129,   131,   133,   135,   136,   137,   138,   139,   140,   141,
      22,    36,    76,    78,   122,    36,     3,    35,    42,     3,
      79,    40,    36,    35,    34,    34,    34,     4,   122,    39,
      58,    59,   124,    56,    57,   126,    44,    45,   128,    46,
      47,    48,    49,   130,    61,    62,   132,    63,    64,    65,
     134,    34,   138,    38,    43,    79,    76,    77,     3,    10,
      13,    16,    17,    18,    19,    20,    21,    23,    70,    71,
      91,    92,    93,    94,    95,    97,   103,   104,   105,   107,
     112,   114,   115,   116,   117,   120,   121,    36,    90,    47,
      91,    36,    35,   113,   122,     3,   121,   140,    35,    35,
     125,   127,   129,   131,   133,   135,   122,     3,    38,    37,
      42,    34,    34,    36,    34,    34,    96,   122,    34,    37,
      92,    40,    40,    40,    50,    51,    52,    53,    54,    55,
     118,    38,    43,    91,    37,    91,    35,    42,    35,    35,
     138,    39,   122,    76,   122,   122,    91,   122,     3,    70,
     106,   115,   121,    78,   119,   122,   122,     3,    37,    37,
     122,    39,    35,    35,    37,    35,   122,    35,    39,    36,
      36,    17,    36,    40,    40,    91,    14,   108,   109,    34,
      91,   114,    37,   111,   122,    15,    37,   109,   110,   122,
      37,    35,    12,    98,    99,   100,    41,    41,    37,    35,
      36,    34,    11,   101,   102,   100,    91,    91,    91,   122,
      36,    37,    35,    91,    36,    37,    91,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    70,    71,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    78,    79,    79,    79,    79,    79,    79,    79,
      80,    81,    82,    83,    84,    84,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    89,    89,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    95,    96,    96,    97,    98,
      98,    99,    99,   100,   101,   101,   102,   103,   104,   105,
     106,   106,   107,   107,   108,   108,   109,   110,   111,   112,
     112,   113,   113,   114,   115,   116,   116,   117,   118,   118,
     118,   118,   118,   118,   119,   119,   120,   121,   121,   121,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   134,   135,   135,
     135,   135,   136,   137,   137,   137,   138,   138,   139,   139,
     139,   140,   140,   140,   140,   141,   141,   141,   141,   141
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     3,     2,
       5,     1,     3,     1,     3,     1,     4,     1,     3,     1,
       1,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     4,     4,     1,     3,     4,     1,     2,     1,
       2,     8,     8,     7,     7,     1,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     2,     0,     1,     9,     0,
       1,     1,     2,     7,     0,     1,     4,     7,     8,    10,
       1,     1,     7,     8,     1,     2,     2,     3,     3,     3,
       4,     1,     3,     3,     2,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     1,     4,     3,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       4,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     4,     3,     1,     1,     1,     1,     1
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
  case 2: /* program: declarations subprograms  */
#line 41 "parser.y"
                                                                                                    {}
#line 1640 "y.tab.c"
    break;

  case 3: /* declarations: %empty  */
#line 45 "parser.y"
                                                                                                    {}
#line 1646 "y.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 46 "parser.y"
                                                                                                    {}
#line 1652 "y.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 49 "parser.y"
                                                                                                    {}
#line 1658 "y.tab.c"
    break;

  case 6: /* declaration: const_declaration  */
#line 50 "parser.y"
                                                                                                    {}
#line 1664 "y.tab.c"
    break;

  case 7: /* declaration: type_declaration  */
#line 51 "parser.y"
                                                                                                    {}
#line 1670 "y.tab.c"
    break;

  case 8: /* var_declaration: type declaration_line SEMICOLON  */
#line 54 "parser.y"
                                                                                                    {}
#line 1676 "y.tab.c"
    break;

  case 9: /* const_declaration: CONST var_declaration  */
#line 57 "parser.y"
                                                                                                    {}
#line 1682 "y.tab.c"
    break;

  case 10: /* type_declaration: TYPE ID ASSIGNMENT type SEMICOLON  */
#line 60 "parser.y"
                                                                                                    {}
#line 1688 "y.tab.c"
    break;

  case 11: /* declaration_line: declaration_item  */
#line 62 "parser.y"
                                                                                                    {}
#line 1694 "y.tab.c"
    break;

  case 12: /* declaration_line: declaration_line COMMA declaration_item  */
#line 63 "parser.y"
                                                                                                    {}
#line 1700 "y.tab.c"
    break;

  case 13: /* declaration_item: declaration_term  */
#line 66 "parser.y"
                                                                                                    {}
#line 1706 "y.tab.c"
    break;

  case 14: /* declaration_item: declaration_term ASSIGNMENT initialization  */
#line 67 "parser.y"
                                                                                                    {}
#line 1712 "y.tab.c"
    break;

  case 15: /* declaration_term: ID  */
#line 70 "parser.y"
                                                                                                    {}
#line 1718 "y.tab.c"
    break;

  case 16: /* declaration_term: declaration_term LBRACKET expr RBRACKET  */
#line 71 "parser.y"
                                                                                                    {}
#line 1724 "y.tab.c"
    break;

  case 17: /* initialization: expr  */
#line 74 "parser.y"
                                                                                                    {}
#line 1730 "y.tab.c"
    break;

  case 18: /* initialization: LBRACE initialization_list RBRACE  */
#line 75 "parser.y"
                                                                                                    {}
#line 1736 "y.tab.c"
    break;

  case 19: /* initialization: allocation  */
#line 76 "parser.y"
                                                                                                    {}
#line 1742 "y.tab.c"
    break;

  case 20: /* initialization_list: initialization  */
#line 79 "parser.y"
                                                                                                    {}
#line 1748 "y.tab.c"
    break;

  case 21: /* initialization_list: initialization_list COMMA initialization  */
#line 80 "parser.y"
                                                                                                    {}
#line 1754 "y.tab.c"
    break;

  case 22: /* allocation: NEW type LBRACKET expr RBRACKET  */
#line 83 "parser.y"
                                                                                                    {}
#line 1760 "y.tab.c"
    break;

  case 23: /* type: PRIM_TYPE  */
#line 87 "parser.y"
                                                                                                    {}
#line 1766 "y.tab.c"
    break;

  case 24: /* type: ptr_type  */
#line 88 "parser.y"
                                                                                                    {}
#line 1772 "y.tab.c"
    break;

  case 25: /* type: enum_type  */
#line 89 "parser.y"
                                                                                                    {}
#line 1778 "y.tab.c"
    break;

  case 26: /* type: struct_type  */
#line 90 "parser.y"
                                                                                                    {}
#line 1784 "y.tab.c"
    break;

  case 27: /* type: map_type  */
#line 91 "parser.y"
                                                                                                    {}
#line 1790 "y.tab.c"
    break;

  case 28: /* type: list_type  */
#line 92 "parser.y"
                                                                                                    {}
#line 1796 "y.tab.c"
    break;

  case 29: /* type: ID  */
#line 93 "parser.y"
                                                                                                    {}
#line 1802 "y.tab.c"
    break;

  case 30: /* ptr_type: PTR ABRACKET_OPEN type ABRACKET_CLOSE  */
#line 96 "parser.y"
                                                                                                    {}
#line 1808 "y.tab.c"
    break;

  case 31: /* map_type: MAP ABRACKET_OPEN type COMMA type ABRACKET_CLOSE  */
#line 99 "parser.y"
                                                                                                    {}
#line 1814 "y.tab.c"
    break;

  case 32: /* list_type: LIST ABRACKET_OPEN type ABRACKET_CLOSE  */
#line 102 "parser.y"
                                                                                                    {}
#line 1820 "y.tab.c"
    break;

  case 33: /* enum_type: ENUM LBRACE enum_list RBRACE  */
#line 105 "parser.y"
                                                                                                    {}
#line 1826 "y.tab.c"
    break;

  case 34: /* enum_list: ID  */
#line 108 "parser.y"
                                                                                                    {}
#line 1832 "y.tab.c"
    break;

  case 35: /* enum_list: enum_list COMMA ID  */
#line 109 "parser.y"
                                                                                                    {}
#line 1838 "y.tab.c"
    break;

  case 36: /* struct_type: STRUCT LBRACE struct_vars RBRACE  */
#line 112 "parser.y"
                                                                                                    {}
#line 1844 "y.tab.c"
    break;

  case 37: /* struct_vars: var_declaration  */
#line 115 "parser.y"
                                                                                                    {}
#line 1850 "y.tab.c"
    break;

  case 38: /* struct_vars: struct_vars var_declaration  */
#line 116 "parser.y"
                                                                                                    {}
#line 1856 "y.tab.c"
    break;

  case 39: /* subprograms: subprogram  */
#line 119 "parser.y"
                                                                                                    {}
#line 1862 "y.tab.c"
    break;

  case 40: /* subprograms: subprograms subprogram  */
#line 120 "parser.y"
                                                                                                    {}
#line 1868 "y.tab.c"
    break;

  case 41: /* subprogram: type ID LPAREN parameters RPAREN LBRACE statements RBRACE  */
#line 123 "parser.y"
                                                                                                    {}
#line 1874 "y.tab.c"
    break;

  case 42: /* subprogram: VOID ID LPAREN parameters RPAREN LBRACE statements RBRACE  */
#line 124 "parser.y"
                                                                                                    {}
#line 1880 "y.tab.c"
    break;

  case 43: /* subprogram: type ID LPAREN RPAREN LBRACE statements RBRACE  */
#line 125 "parser.y"
                                                                                                    {}
#line 1886 "y.tab.c"
    break;

  case 44: /* subprogram: VOID ID LPAREN RPAREN LBRACE statements RBRACE  */
#line 126 "parser.y"
                                                                                                    {}
#line 1892 "y.tab.c"
    break;

  case 45: /* parameters: parameter  */
#line 129 "parser.y"
                                                                                                    {}
#line 1898 "y.tab.c"
    break;

  case 46: /* parameters: parameters COMMA parameter  */
#line 130 "parser.y"
                                                                                                    {}
#line 1904 "y.tab.c"
    break;

  case 47: /* parameter: type ID  */
#line 133 "parser.y"
                                                                                                    {}
#line 1910 "y.tab.c"
    break;

  case 48: /* statements: statement  */
#line 136 "parser.y"
                                                                                                    {}
#line 1916 "y.tab.c"
    break;

  case 49: /* statements: statements statement  */
#line 137 "parser.y"
                                                                                                    {}
#line 1922 "y.tab.c"
    break;

  case 50: /* statement: var_declaration  */
#line 140 "parser.y"
                                                                                                    {}
#line 1928 "y.tab.c"
    break;

  case 51: /* statement: const_declaration  */
#line 141 "parser.y"
                                                                                                    {}
#line 1934 "y.tab.c"
    break;

  case 52: /* statement: command  */
#line 142 "parser.y"
                                                                                                    {}
#line 1940 "y.tab.c"
    break;

  case 53: /* statement: assignment_command  */
#line 143 "parser.y"
                                                                                                    {}
#line 1946 "y.tab.c"
    break;

  case 54: /* command: if  */
#line 146 "parser.y"
                                                                                                    {}
#line 1952 "y.tab.c"
    break;

  case 55: /* command: while  */
#line 147 "parser.y"
                                                                                                    {}
#line 1958 "y.tab.c"
    break;

  case 56: /* command: do_while  */
#line 148 "parser.y"
                                                                                                    {}
#line 1964 "y.tab.c"
    break;

  case 57: /* command: for  */
#line 149 "parser.y"
                                                                                                    {}
#line 1970 "y.tab.c"
    break;

  case 58: /* command: switch  */
#line 150 "parser.y"
                                                                                                    {}
#line 1976 "y.tab.c"
    break;

  case 59: /* command: function_call SEMICOLON  */
#line 151 "parser.y"
                                                                                                    {}
#line 1982 "y.tab.c"
    break;

  case 60: /* command: jump SEMICOLON  */
#line 152 "parser.y"
                                                                                                    {}
#line 1988 "y.tab.c"
    break;

  case 61: /* command: deletion  */
#line 153 "parser.y"
                                                                                                    {}
#line 1994 "y.tab.c"
    break;

  case 62: /* jump: CONTINUE  */
#line 156 "parser.y"
                                                                                                    {}
#line 2000 "y.tab.c"
    break;

  case 63: /* jump: BREAK  */
#line 157 "parser.y"
                                                                                                    {}
#line 2006 "y.tab.c"
    break;

  case 64: /* jump: return  */
#line 158 "parser.y"
                                                                                                    {}
#line 2012 "y.tab.c"
    break;

  case 65: /* return: RETURN return_value  */
#line 161 "parser.y"
                                                                                                    {}
#line 2018 "y.tab.c"
    break;

  case 66: /* return_value: %empty  */
#line 164 "parser.y"
                                                                                                    {}
#line 2024 "y.tab.c"
    break;

  case 67: /* return_value: expr  */
#line 165 "parser.y"
                                                                                                    {}
#line 2030 "y.tab.c"
    break;

  case 68: /* if: IF LPAREN expr RPAREN LBRACE statements RBRACE else_ifs_opt else_opt  */
#line 168 "parser.y"
                                                                                                    {}
#line 2036 "y.tab.c"
    break;

  case 69: /* else_ifs_opt: %empty  */
#line 171 "parser.y"
                                                                                                    {}
#line 2042 "y.tab.c"
    break;

  case 70: /* else_ifs_opt: else_ifs  */
#line 172 "parser.y"
                                                                                                    {}
#line 2048 "y.tab.c"
    break;

  case 71: /* else_ifs: else_if  */
#line 175 "parser.y"
                                                                                                    {}
#line 2054 "y.tab.c"
    break;

  case 72: /* else_ifs: else_ifs else_if  */
#line 176 "parser.y"
                                                                                                    {}
#line 2060 "y.tab.c"
    break;

  case 73: /* else_if: ELSEIF LPAREN expr RPAREN LBRACE statements RBRACE  */
#line 179 "parser.y"
                                                                                                    {}
#line 2066 "y.tab.c"
    break;

  case 74: /* else_opt: %empty  */
#line 181 "parser.y"
                                                                                                    {}
#line 2072 "y.tab.c"
    break;

  case 75: /* else_opt: else  */
#line 182 "parser.y"
                                                                                                    {}
#line 2078 "y.tab.c"
    break;

  case 76: /* else: ELSE LBRACE statements RBRACE  */
#line 185 "parser.y"
                                                                                                    {}
#line 2084 "y.tab.c"
    break;

  case 77: /* while: WHILE LPAREN expr RPAREN LBRACE statements RBRACE  */
#line 188 "parser.y"
                                                                                                    {}
#line 2090 "y.tab.c"
    break;

  case 78: /* do_while: DO LBRACE statements RBRACE WHILE LPAREN expr RPAREN  */
#line 191 "parser.y"
                                                                                                    {}
#line 2096 "y.tab.c"
    break;

  case 79: /* for: FOR LPAREN for_init expr SEMICOLON assignment RPAREN LBRACE statements RBRACE  */
#line 194 "parser.y"
                                                                                                    {}
#line 2102 "y.tab.c"
    break;

  case 80: /* for_init: assignment_command  */
#line 197 "parser.y"
                                                                                                    {}
#line 2108 "y.tab.c"
    break;

  case 81: /* for_init: var_declaration  */
#line 198 "parser.y"
                                                                                                    {}
#line 2114 "y.tab.c"
    break;

  case 82: /* switch: SWITCH LPAREN expr RPAREN LBRACE cases RBRACE  */
#line 201 "parser.y"
                                                                                                    {}
#line 2120 "y.tab.c"
    break;

  case 83: /* switch: SWITCH LPAREN expr RPAREN LBRACE cases default RBRACE  */
#line 202 "parser.y"
                                                                                                    {}
#line 2126 "y.tab.c"
    break;

  case 84: /* cases: case  */
#line 205 "parser.y"
                                                                                                    {}
#line 2132 "y.tab.c"
    break;

  case 85: /* cases: cases case  */
#line 206 "parser.y"
                                                                                                    {}
#line 2138 "y.tab.c"
    break;

  case 86: /* case: CASE case_item  */
#line 209 "parser.y"
                                                                                                    {}
#line 2144 "y.tab.c"
    break;

  case 87: /* default: DEFAULT COLON statements  */
#line 212 "parser.y"
                                                                                                    {}
#line 2150 "y.tab.c"
    break;

  case 88: /* case_item: expr COLON statements  */
#line 215 "parser.y"
                                                                                                    {}
#line 2156 "y.tab.c"
    break;

  case 89: /* function_call: ID LPAREN RPAREN  */
#line 219 "parser.y"
                                                                                                    {}
#line 2162 "y.tab.c"
    break;

  case 90: /* function_call: ID LPAREN parameters_call RPAREN  */
#line 220 "parser.y"
                                                                                                    {}
#line 2168 "y.tab.c"
    break;

  case 91: /* parameters_call: expr  */
#line 223 "parser.y"
                                                                                                    {}
#line 2174 "y.tab.c"
    break;

  case 92: /* parameters_call: parameters_call COMMA expr  */
#line 224 "parser.y"
                                                                                                    {}
#line 2180 "y.tab.c"
    break;

  case 93: /* assignment: assignable assignment_operator assignment_expr  */
#line 227 "parser.y"
                                                                                                    {}
#line 2186 "y.tab.c"
    break;

  case 94: /* assignment_command: assignment SEMICOLON  */
#line 230 "parser.y"
                                                                                                    {}
#line 2192 "y.tab.c"
    break;

  case 95: /* assignable: identifier_ref  */
#line 233 "parser.y"
                                                                                                    {}
#line 2198 "y.tab.c"
    break;

  case 96: /* assignable: val  */
#line 234 "parser.y"
                                                                                                    {}
#line 2204 "y.tab.c"
    break;

  case 97: /* val: VAL LPAREN target RPAREN  */
#line 237 "parser.y"
                                                                                                    {}
#line 2210 "y.tab.c"
    break;

  case 98: /* assignment_operator: ASSIGNMENT  */
#line 240 "parser.y"
                                                                                                    {}
#line 2216 "y.tab.c"
    break;

  case 99: /* assignment_operator: ASSIGNMENT_MUL  */
#line 241 "parser.y"
                                                                                                    {}
#line 2222 "y.tab.c"
    break;

  case 100: /* assignment_operator: ASSIGNMENT_DIV  */
#line 242 "parser.y"
                                                                                                    {}
#line 2228 "y.tab.c"
    break;

  case 101: /* assignment_operator: ASSIGNMENT_MOD  */
#line 243 "parser.y"
                                                                                                    {}
#line 2234 "y.tab.c"
    break;

  case 102: /* assignment_operator: ASSIGNMENT_ADD  */
#line 244 "parser.y"
                                                                                                    {}
#line 2240 "y.tab.c"
    break;

  case 103: /* assignment_operator: ASSIGNMENT_SUB  */
#line 245 "parser.y"
                                                                                                    {}
#line 2246 "y.tab.c"
    break;

  case 104: /* assignment_expr: expr  */
#line 248 "parser.y"
                                                                                                    {}
#line 2252 "y.tab.c"
    break;

  case 105: /* assignment_expr: allocation  */
#line 249 "parser.y"
                                                                                                    {}
#line 2258 "y.tab.c"
    break;

  case 106: /* deletion: DELETE LPAREN identifier_ref RPAREN SEMICOLON  */
#line 252 "parser.y"
                                                                                                    {}
#line 2264 "y.tab.c"
    break;

  case 107: /* identifier_ref: ID  */
#line 255 "parser.y"
                                                                                                    {}
#line 2270 "y.tab.c"
    break;

  case 108: /* identifier_ref: identifier_ref LBRACKET expr RBRACKET  */
#line 256 "parser.y"
                                                                                                    {}
#line 2276 "y.tab.c"
    break;

  case 109: /* identifier_ref: identifier_ref DOT ID  */
#line 257 "parser.y"
                                                                                                    {}
#line 2282 "y.tab.c"
    break;

  case 110: /* expr: or_expr  */
#line 260 "parser.y"
                                                                                                    {}
#line 2288 "y.tab.c"
    break;

  case 111: /* or_expr: and_expr  */
#line 263 "parser.y"
                                                                                                    {}
#line 2294 "y.tab.c"
    break;

  case 112: /* or_expr: or_expr or_operator and_expr  */
#line 264 "parser.y"
                                                                                                    {}
#line 2300 "y.tab.c"
    break;

  case 113: /* or_operator: OR  */
#line 267 "parser.y"
                                                                                                    {}
#line 2306 "y.tab.c"
    break;

  case 114: /* or_operator: ORC  */
#line 268 "parser.y"
                                                                                                    {}
#line 2312 "y.tab.c"
    break;

  case 115: /* and_expr: eq_expr  */
#line 271 "parser.y"
                                                                                                    {}
#line 2318 "y.tab.c"
    break;

  case 116: /* and_expr: and_expr and_operator eq_expr  */
#line 272 "parser.y"
                                                                                                    {}
#line 2324 "y.tab.c"
    break;

  case 117: /* and_operator: AND  */
#line 275 "parser.y"
                                                                                                    {}
#line 2330 "y.tab.c"
    break;

  case 118: /* and_operator: ANDC  */
#line 276 "parser.y"
                                                                                                    {}
#line 2336 "y.tab.c"
    break;

  case 119: /* eq_expr: relational_expr  */
#line 279 "parser.y"
                                                                                                    {}
#line 2342 "y.tab.c"
    break;

  case 120: /* eq_expr: eq_expr eq_operator relational_expr  */
#line 280 "parser.y"
                                                                                                    {}
#line 2348 "y.tab.c"
    break;

  case 121: /* eq_operator: EQUALITY  */
#line 283 "parser.y"
                                                                                                    {}
#line 2354 "y.tab.c"
    break;

  case 122: /* eq_operator: DIFFERENCE  */
#line 284 "parser.y"
                                                                                                    {}
#line 2360 "y.tab.c"
    break;

  case 123: /* relational_expr: arithmetic_expr  */
#line 287 "parser.y"
                                                                                                    {}
#line 2366 "y.tab.c"
    break;

  case 124: /* relational_expr: relational_expr ineq_operator arithmetic_expr  */
#line 288 "parser.y"
                                                                                                    {}
#line 2372 "y.tab.c"
    break;

  case 125: /* ineq_operator: ABRACKET_OPEN  */
#line 291 "parser.y"
                                                                                                    {}
#line 2378 "y.tab.c"
    break;

  case 126: /* ineq_operator: MORE_THAN_EQUALS  */
#line 292 "parser.y"
                                                                                                    {}
#line 2384 "y.tab.c"
    break;

  case 127: /* ineq_operator: ABRACKET_CLOSE  */
#line 293 "parser.y"
                                                                                                    {}
#line 2390 "y.tab.c"
    break;

  case 128: /* ineq_operator: LESS_THAN_EQUALS  */
#line 294 "parser.y"
                                                                                                    {}
#line 2396 "y.tab.c"
    break;

  case 129: /* arithmetic_expr: term  */
#line 297 "parser.y"
                                                                                                    {}
#line 2402 "y.tab.c"
    break;

  case 130: /* arithmetic_expr: arithmetic_expr add_operator term  */
#line 298 "parser.y"
                                                                                                    {}
#line 2408 "y.tab.c"
    break;

  case 131: /* add_operator: PLUS  */
#line 301 "parser.y"
                                                                                                    {}
#line 2414 "y.tab.c"
    break;

  case 132: /* add_operator: MINUS  */
#line 302 "parser.y"
                                                                                                    {}
#line 2420 "y.tab.c"
    break;

  case 133: /* term: prefix_expr  */
#line 305 "parser.y"
                                                                                                    {}
#line 2426 "y.tab.c"
    break;

  case 134: /* term: term mult_operator prefix_expr  */
#line 306 "parser.y"
                                                                                                    {}
#line 2432 "y.tab.c"
    break;

  case 135: /* mult_operator: TIMES  */
#line 309 "parser.y"
                                                                                                    {}
#line 2438 "y.tab.c"
    break;

  case 136: /* mult_operator: SLASH  */
#line 310 "parser.y"
                                                                                                    {}
#line 2444 "y.tab.c"
    break;

  case 137: /* mult_operator: MOD  */
#line 311 "parser.y"
                                                                                                    {}
#line 2450 "y.tab.c"
    break;

  case 138: /* prefix_expr: postfix_expr  */
#line 314 "parser.y"
                                                                                                    {}
#line 2456 "y.tab.c"
    break;

  case 139: /* prefix_expr: unary_operator postfix_expr  */
#line 315 "parser.y"
                                                                                                    {}
#line 2462 "y.tab.c"
    break;

  case 140: /* prefix_expr: REF LPAREN identifier_ref RPAREN  */
#line 316 "parser.y"
                                                                                                    {}
#line 2468 "y.tab.c"
    break;

  case 142: /* cast: LPAREN PRIM_TYPE RPAREN postfix_expr  */
#line 320 "parser.y"
                                                                                                    {}
#line 2474 "y.tab.c"
    break;

  case 143: /* unary_operator: PLUS  */
#line 323 "parser.y"
                                                                                                    {}
#line 2480 "y.tab.c"
    break;

  case 144: /* unary_operator: MINUS  */
#line 324 "parser.y"
                                                                                                    {}
#line 2486 "y.tab.c"
    break;

  case 145: /* unary_operator: NOT  */
#line 325 "parser.y"
                                                                                                    {}
#line 2492 "y.tab.c"
    break;

  case 146: /* postfix_expr: target  */
#line 328 "parser.y"
                                                                                                    {}
#line 2498 "y.tab.c"
    break;

  case 147: /* postfix_expr: literal  */
#line 329 "parser.y"
                                                                                                    {}
#line 2504 "y.tab.c"
    break;

  case 148: /* base: ID  */
#line 332 "parser.y"
                                                                                                    {}
#line 2510 "y.tab.c"
    break;

  case 149: /* base: val  */
#line 333 "parser.y"
                                                                                                    {}
#line 2516 "y.tab.c"
    break;

  case 150: /* base: LPAREN expr RPAREN  */
#line 334 "parser.y"
                                                                                                    {}
#line 2522 "y.tab.c"
    break;

  case 151: /* target: base  */
#line 337 "parser.y"
                                                                                                    {}
#line 2528 "y.tab.c"
    break;

  case 152: /* target: function_call  */
#line 338 "parser.y"
                                                                                                    {}
#line 2534 "y.tab.c"
    break;

  case 153: /* target: target LBRACKET expr RBRACKET  */
#line 339 "parser.y"
                                                                                                    {}
#line 2540 "y.tab.c"
    break;

  case 154: /* target: target DOT ID  */
#line 340 "parser.y"
                                                                                                    {}
#line 2546 "y.tab.c"
    break;

  case 155: /* literal: INTEGER  */
#line 344 "parser.y"
                                                                                                    {}
#line 2552 "y.tab.c"
    break;

  case 156: /* literal: CHAR  */
#line 345 "parser.y"
                                                                                                    {}
#line 2558 "y.tab.c"
    break;

  case 157: /* literal: STRING  */
#line 346 "parser.y"
                                                                                                    {}
#line 2564 "y.tab.c"
    break;

  case 158: /* literal: REAL  */
#line 347 "parser.y"
                                                                                                    {}
#line 2570 "y.tab.c"
    break;

  case 159: /* literal: BOOL  */
#line 348 "parser.y"
                                                                                                    {}
#line 2576 "y.tab.c"
    break;


#line 2580 "y.tab.c"

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

#line 351 "parser.y"


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
