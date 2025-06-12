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

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;


#line 81 "y.tab.c"

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
#line 11 "parser.y"

	char   cValue; 	/* char value */
	char * sValue;      /* string value */
	

#line 202 "y.tab.c"

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
  YYSYMBOL_var_specifier = 71,             /* var_specifier  */
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
  YYSYMBOL_return_type = 89,               /* return_type  */
  YYSYMBOL_parameters = 90,                /* parameters  */
  YYSYMBOL_parameter = 91,                 /* parameter  */
  YYSYMBOL_statements = 92,                /* statements  */
  YYSYMBOL_statement = 93,                 /* statement  */
  YYSYMBOL_command = 94,                   /* command  */
  YYSYMBOL_jump = 95,                      /* jump  */
  YYSYMBOL_return = 96,                    /* return  */
  YYSYMBOL_return_value = 97,              /* return_value  */
  YYSYMBOL_if = 98,                        /* if  */
  YYSYMBOL_else_ifs_opt = 99,              /* else_ifs_opt  */
  YYSYMBOL_else_ifs = 100,                 /* else_ifs  */
  YYSYMBOL_else_if = 101,                  /* else_if  */
  YYSYMBOL_else_opt = 102,                 /* else_opt  */
  YYSYMBOL_else = 103,                     /* else  */
  YYSYMBOL_while = 104,                    /* while  */
  YYSYMBOL_do_while = 105,                 /* do_while  */
  YYSYMBOL_for = 106,                      /* for  */
  YYSYMBOL_for_initialization = 107,       /* for_initialization  */
  YYSYMBOL_switch = 108,                   /* switch  */
  YYSYMBOL_cases = 109,                    /* cases  */
  YYSYMBOL_case = 110,                     /* case  */
  YYSYMBOL_default = 111,                  /* default  */
  YYSYMBOL_case_item = 112,                /* case_item  */
  YYSYMBOL_function_call = 113,            /* function_call  */
  YYSYMBOL_parameters_call = 114,          /* parameters_call  */
  YYSYMBOL_assignment = 115,               /* assignment  */
  YYSYMBOL_assignable = 116,               /* assignable  */
  YYSYMBOL_assignment_operator = 117,      /* assignment_operator  */
  YYSYMBOL_assignment_expr = 118,          /* assignment_expr  */
  YYSYMBOL_deletion = 119,                 /* deletion  */
  YYSYMBOL_identifier_ref = 120,           /* identifier_ref  */
  YYSYMBOL_expr = 121,                     /* expr  */
  YYSYMBOL_or_expr = 122,                  /* or_expr  */
  YYSYMBOL_or_operator = 123,              /* or_operator  */
  YYSYMBOL_and_expr = 124,                 /* and_expr  */
  YYSYMBOL_and_operator = 125,             /* and_operator  */
  YYSYMBOL_eq_expr = 126,                  /* eq_expr  */
  YYSYMBOL_eq_operator = 127,              /* eq_operator  */
  YYSYMBOL_relational_expr = 128,          /* relational_expr  */
  YYSYMBOL_ineq_operator = 129,            /* ineq_operator  */
  YYSYMBOL_arithmetic_expr = 130,          /* arithmetic_expr  */
  YYSYMBOL_add_operator = 131,             /* add_operator  */
  YYSYMBOL_term = 132,                     /* term  */
  YYSYMBOL_mult_operator = 133,            /* mult_operator  */
  YYSYMBOL_prefix_expr = 134,              /* prefix_expr  */
  YYSYMBOL_unary_operator = 135,           /* unary_operator  */
  YYSYMBOL_postfix_expr = 136,             /* postfix_expr  */
  YYSYMBOL_cast = 137,                     /* cast  */
  YYSYMBOL_element = 138,                  /* element  */
  YYSYMBOL_literal = 139                   /* literal  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   445

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  276

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
       0,    33,    33,    37,    38,    41,    42,    45,    48,    49,
      52,    54,    55,    58,    59,    62,    63,    66,    67,    68,
      71,    72,    75,    79,    80,    81,    82,    83,    84,    85,
      88,    91,    94,    97,   100,   101,   104,   107,   108,   111,
     112,   115,   118,   119,   122,   123,   126,   129,   130,   133,
     134,   137,   138,   139,   140,   141,   142,   143,   144,   147,
     148,   149,   152,   155,   156,   159,   162,   163,   166,   167,
     170,   172,   173,   176,   179,   182,   185,   188,   189,   192,
     193,   196,   197,   200,   203,   206,   210,   211,   214,   215,
     218,   221,   222,   225,   226,   227,   228,   229,   230,   233,
     234,   237,   240,   241,   242,   245,   248,   249,   252,   253,
     256,   257,   260,   261,   264,   265,   268,   269,   272,   273,
     276,   277,   278,   279,   282,   283,   286,   287,   290,   291,
     294,   295,   296,   299,   300,   303,   304,   305,   306,   307,
     310,   311,   314,   315,   318,   319,   320,   323,   324,   325,
     326,   327
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
  "var_declaration", "var_specifier", "type_declaration",
  "declaration_line", "declaration_item", "declaration_term",
  "initialization", "initialization_list", "allocation", "type",
  "ptr_type", "map_type", "list_type", "enum_type", "enum_list",
  "struct_type", "struct_vars", "subprograms", "subprogram", "return_type",
  "parameters", "parameter", "statements", "statement", "command", "jump",
  "return", "return_value", "if", "else_ifs_opt", "else_ifs", "else_if",
  "else_opt", "else", "while", "do_while", "for", "for_initialization",
  "switch", "cases", "case", "default", "case_item", "function_call",
  "parameters_call", "assignment", "assignable", "assignment_operator",
  "assignment_expr", "deletion", "identifier_ref", "expr", "or_expr",
  "or_operator", "and_expr", "and_operator", "eq_expr", "eq_operator",
  "relational_expr", "ineq_operator", "arithmetic_expr", "add_operator",
  "term", "mult_operator", "prefix_expr", "unary_operator", "postfix_expr",
  "cast", "element", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,  -171,    17,    36,   233,  -171,  -171,    45,  -171,     5,
    -171,  -171,  -171,  -171,    22,    28,    -3,    35,    44,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,   413,  -171,    89,   100,
      45,    85,   119,    45,    45,    45,  -171,    95,  -171,    38,
    -171,   -29,    93,  -171,    25,  -171,    -4,    92,    96,    94,
      45,  -171,   100,    10,   208,  -171,  -171,  -171,  -171,   144,
    -171,  -171,    45,   150,    24,  -171,  -171,   128,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,   167,  -171,  -171,  -171,  -171,
     124,   -48,    69,    87,   140,    84,    54,  -171,    20,  -171,
    -171,  -171,  -171,    45,   208,  -171,  -171,  -171,  -171,   118,
    -171,   130,    45,   215,   115,   133,   134,  -171,  -171,  -171,
      10,  -171,  -171,    10,  -171,  -171,    10,  -171,  -171,  -171,
    -171,    10,  -171,  -171,    10,  -171,  -171,  -171,    10,  -171,
     139,  -171,    26,  -171,   138,  -171,  -171,    56,  -171,    80,
    -171,    69,    87,   140,    84,    54,  -171,    10,  -171,   208,
     128,   145,   147,   142,   148,   159,  -171,  -171,    10,   181,
    -171,   303,  -171,  -171,   154,  -171,  -171,  -171,  -171,  -171,
    -171,   160,  -171,  -171,    10,  -171,    10,  -171,   163,  -171,
      10,    10,   138,    10,    21,  -171,  -171,  -171,    61,  -171,
    -171,  -171,  -171,  -171,  -171,   168,   169,   315,   170,    20,
    -171,   165,  -171,   294,    77,    10,  -171,   205,   173,   174,
     195,   183,  -171,    10,  -171,  -171,  -171,  -171,  -171,  -171,
     249,   186,  -171,   138,   212,   197,   138,   192,  -171,   198,
    -171,  -171,   204,    10,    -7,  -171,    10,   340,   415,  -171,
     223,  -171,   202,    10,  -171,  -171,   209,   210,  -171,   213,
     217,   236,   223,  -171,   138,  -171,  -171,  -171,   231,    10,
     243,  -171,  -171,  -171,   275,   138,   218,   138,   352,   244,
     377,  -171,   138,  -171,   389,  -171
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     9,     0,     0,     0,     3,     5,     0,     6,     0,
       1,    29,    23,    43,     0,     0,     0,     0,     0,     4,
      42,    24,    27,    28,    25,    26,     2,    39,     0,     0,
       0,     8,     0,     0,     0,     0,    40,     0,    15,     0,
      11,    13,     0,    37,     8,    34,     0,     0,     0,     0,
       0,     7,     0,     0,     0,    10,    36,    38,    33,     0,
      30,    32,     0,     0,     0,    44,    12,   144,   147,   149,
     151,   150,   148,   137,   138,     0,   139,   135,   136,   141,
       0,   105,   106,   110,   114,   118,   124,   128,     0,   133,
     140,   142,   145,     0,     0,    14,    19,    17,    35,     0,
      46,     0,     0,     0,   144,     0,     0,    16,   108,   109,
       0,   112,   113,     0,   116,   117,     0,   120,   122,   123,
     121,     0,   126,   127,     0,   130,   131,   132,     0,   134,
       0,    20,     0,    31,     8,    45,    86,     0,    88,     0,
     146,   107,   111,   115,   119,   125,   129,     0,    18,     0,
       0,     0,     0,     0,     0,     0,    60,    59,    63,     0,
      49,     8,    47,    50,     0,    61,    51,    52,    53,    54,
      55,     0,    58,    87,     0,   144,     0,   143,     0,    21,
       0,     0,     8,     0,     8,    62,    64,   102,     0,    41,
      48,    57,    56,    89,    22,     0,     0,     8,     0,     0,
      78,     0,    77,     0,    91,     0,   101,     0,     0,     0,
       0,     0,    92,     0,    93,    94,    95,    96,    97,    98,
       0,     0,   104,     8,     0,     0,     8,     0,   100,     0,
      99,   103,     0,     0,     0,    81,     0,     8,     0,    90,
      66,    83,     0,     0,    79,    82,     0,     0,    74,     0,
       0,    71,    67,    68,     8,    84,    80,    75,     0,     0,
       0,    65,    72,    69,     8,     8,     0,     8,     8,     0,
       8,    76,     8,    73,     8,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,   268,     1,  -171,  -171,  -171,   229,  -171,
     -88,  -171,    62,     7,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,   258,  -171,  -171,   184,  -170,  -158,    49,  -171,
    -171,  -171,  -171,  -171,  -171,    47,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,    63,  -171,    57,  -130,  -171,  -171,
    -171,  -171,  -171,  -171,   120,   -53,  -171,  -171,   193,  -171,
     189,  -171,   191,  -171,   187,  -171,   190,  -171,   177,  -171,
     -86,  -171,   176,  -171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,     5,   160,     7,     8,    39,    40,    41,
      95,   132,    96,    20,    21,    22,    23,    24,    46,    25,
      44,    26,    27,    28,    64,    65,   161,   162,   163,   164,
     165,   185,   166,   251,   252,   253,   261,   262,   167,   168,
     169,   201,   170,   234,   235,   246,   241,    79,   137,   202,
     203,   220,   229,   172,   188,    97,    81,   110,    82,   113,
      83,   116,    84,   121,    85,   124,    86,   128,    87,    88,
      89,    90,    91,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,     6,   129,   190,   171,     6,   131,   233,   243,    53,
     108,   109,   197,    67,    29,    68,    69,    70,    71,    72,
       9,    54,   106,    67,   187,    68,    69,    70,    71,    72,
     244,   171,    43,    58,    73,    74,    10,    42,    59,   190,
      47,    48,    49,    33,    75,    57,   199,     1,    11,    12,
     138,     1,   171,     1,    75,    30,   237,    63,    31,   101,
       2,   179,    56,   148,    32,   232,   102,   171,   149,    99,
      76,    77,    78,    14,    15,    16,    17,    18,    51,   190,
      52,    34,   105,   175,   264,    68,    69,    70,    71,    72,
      35,   173,    37,   171,   178,   268,   171,   270,   174,   205,
     130,   206,   274,    38,   207,   186,   190,   171,   171,    63,
     190,     1,   190,   212,   176,   205,   190,   125,   126,   127,
     207,   193,    45,   106,   171,   111,   112,   195,   196,    50,
     198,   114,   115,    55,   171,   171,    62,   171,   171,    60,
     171,   150,   171,    61,   171,   122,   123,    98,   151,   103,
     -29,   152,   221,   100,   153,   154,   155,   156,   157,   158,
     227,   159,   103,   107,     1,   133,   134,   230,   139,   140,
     104,    12,    68,    69,    70,    71,    72,   147,   182,   180,
     242,   181,   183,   247,   187,   200,   117,   118,   119,   120,
     242,    73,    74,   184,   191,    14,    15,    16,    17,    18,
     192,    75,   194,   208,   209,   211,   266,   213,   222,   223,
     224,    67,   225,    68,    69,    70,    71,    72,    67,   226,
      68,    69,    70,    71,    72,   231,   233,    76,    77,    78,
      93,   236,    73,    74,   238,   250,    11,    12,   239,    73,
      74,   240,    75,   254,    94,   257,   256,   260,   258,    75,
     136,   259,    67,   269,    68,    69,    70,    71,    72,     1,
      13,    14,    15,    16,    17,    18,     2,   265,    76,    77,
      78,    93,    19,    73,    74,    76,    77,    78,   150,   267,
     272,    66,   228,    75,    36,   151,   135,   249,   152,   -85,
     -85,   153,   154,   155,   156,   157,   158,   245,   159,   263,
     255,     1,   142,   141,   204,   146,   150,   143,   144,    76,
      77,    78,   -85,   151,   145,   177,   152,     0,   150,   153,
     154,   155,   156,   157,   158,   151,   159,     0,   152,     1,
       0,   153,   154,   155,   156,   157,   158,     0,   159,     0,
     189,     1,     0,   150,   214,   215,   216,   217,   218,   219,
     151,     0,   210,   152,     0,   150,   153,   154,   155,   156,
     157,   158,   151,   159,     0,   152,     1,     0,   153,   154,
     155,   156,   157,   158,     0,   159,     0,   248,     1,     0,
     150,     0,     0,     0,     0,     0,     0,   151,     0,   271,
     152,     0,   150,   153,   154,   155,   156,   157,   158,   151,
     159,     0,   152,     1,     0,   153,   154,   155,   156,   157,
     158,     0,   159,     0,   273,     1,    11,    12,   150,     0,
       0,     0,     0,     0,     0,   151,   275,     0,   152,     0,
       0,   153,   154,   155,   156,   157,   158,     0,   159,     0,
      13,    14,    15,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
      53,     0,    88,   161,   134,     4,    94,    14,    15,    38,
      58,    59,   182,     3,     7,     5,     6,     7,     8,     9,
       3,    50,    75,     3,     3,     5,     6,     7,     8,     9,
      37,   161,    31,    37,    24,    25,     0,    30,    42,   197,
      33,    34,    35,    46,    34,    44,    25,    26,     3,     4,
     103,    26,   182,    26,    34,    50,   226,    50,    36,    35,
      33,   149,    37,    37,    36,   223,    42,   197,    42,    62,
      60,    61,    62,    28,    29,    30,    31,    32,    40,   237,
      42,    46,    75,     3,   254,     5,     6,     7,     8,     9,
      46,    35,     3,   223,   147,   265,   226,   267,    42,    38,
      93,    40,   272,     3,    43,   158,   264,   237,   238,   102,
     268,    26,   270,   199,    34,    38,   274,    63,    64,    65,
      43,   174,     3,   176,   254,    56,    57,   180,   181,    34,
     183,    44,    45,    40,   264,   265,    42,   267,   268,    47,
     270,     3,   272,    47,   274,    61,    62,     3,    10,    34,
      35,    13,   205,     3,    16,    17,    18,    19,    20,    21,
     213,    23,    34,    39,    26,    47,    36,   220,    35,    35,
       3,     4,     5,     6,     7,     8,     9,    38,    36,    34,
     233,    34,    34,   236,     3,   184,    46,    47,    48,    49,
     243,    24,    25,    34,    40,    28,    29,    30,    31,    32,
      40,    34,    39,    35,    35,    35,   259,    42,     3,    36,
      36,     3,    17,     5,     6,     7,     8,     9,     3,    36,
       5,     6,     7,     8,     9,    39,    14,    60,    61,    62,
      22,    34,    24,    25,    42,    12,     3,     4,    40,    24,
      25,    37,    34,    41,    36,    35,    37,    11,    35,    34,
      35,    34,     3,    35,     5,     6,     7,     8,     9,    26,
      27,    28,    29,    30,    31,    32,    33,    36,    60,    61,
      62,    22,     4,    24,    25,    60,    61,    62,     3,    36,
      36,    52,   220,    34,    26,    10,   102,   238,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   234,    23,   252,
     243,    26,   113,   110,   184,   128,     3,   116,   121,    60,
      61,    62,    37,    10,   124,   139,    13,    -1,     3,    16,
      17,    18,    19,    20,    21,    10,    23,    -1,    13,    26,
      -1,    16,    17,    18,    19,    20,    21,    -1,    23,    -1,
      37,    26,    -1,     3,    50,    51,    52,    53,    54,    55,
      10,    -1,    37,    13,    -1,     3,    16,    17,    18,    19,
      20,    21,    10,    23,    -1,    13,    26,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    37,    26,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    37,
      13,    -1,     3,    16,    17,    18,    19,    20,    21,    10,
      23,    -1,    13,    26,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    37,    26,     3,     4,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    37,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    -1,    23,    -1,
      27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    33,    67,    68,    69,    70,    71,    72,     3,
       0,     3,     4,    27,    28,    29,    30,    31,    32,    69,
      79,    80,    81,    82,    83,    85,    87,    88,    89,    79,
      50,    36,    36,    46,    46,    46,    88,     3,     3,    73,
      74,    75,    79,    70,    86,     3,    84,    79,    79,    79,
      34,    40,    42,    38,    50,    40,    37,    70,    37,    42,
      47,    47,    42,    79,    90,    91,    74,     3,     5,     6,
       7,     8,     9,    24,    25,    34,    60,    61,    62,   113,
     121,   122,   124,   126,   128,   130,   132,   134,   135,   136,
     137,   138,   139,    22,    36,    76,    78,   121,     3,    79,
       3,    35,    42,    34,     3,    79,   121,    39,    58,    59,
     123,    56,    57,   125,    44,    45,   127,    46,    47,    48,
      49,   129,    61,    62,   131,    63,    64,    65,   133,   136,
      79,    76,    77,    47,    36,    91,    35,   114,   121,    35,
      35,   124,   126,   128,   130,   132,   134,    38,    37,    42,
       3,    10,    13,    16,    17,    18,    19,    20,    21,    23,
      70,    92,    93,    94,    95,    96,    98,   104,   105,   106,
     108,   113,   119,    35,    42,     3,    34,   138,   121,    76,
      34,    34,    36,    34,    34,    97,   121,     3,   120,    37,
      93,    40,    40,   121,    39,   121,   121,    92,   121,    25,
      70,   107,   115,   116,   120,    38,    40,    43,    35,    35,
      37,    35,   136,    42,    50,    51,    52,    53,    54,    55,
     117,   121,     3,    36,    36,    17,    36,   121,    78,   118,
     121,    39,    93,    14,   109,   110,    34,    92,    42,    40,
      37,   112,   121,    15,    37,   110,   111,   121,    37,    94,
      12,    99,   100,   101,    41,   112,    37,    35,    35,    34,
      11,   102,   103,   101,    92,    36,   121,    36,    92,    35,
      92,    37,    36,    37,    92,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    70,    71,    71,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    78,    79,    79,    79,    79,    79,    79,    79,
      80,    81,    82,    83,    84,    84,    85,    86,    86,    87,
      87,    88,    89,    89,    90,    90,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    96,    97,    97,    98,    99,    99,   100,   100,
     101,   102,   102,   103,   104,   105,   106,   107,   107,   108,
     108,   109,   109,   110,   111,   112,   113,   113,   114,   114,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   120,   120,   120,   121,   122,   122,   123,   123,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   134,   134,   135,   135,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   139,   139,   139,
     139,   139
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     4,     0,     1,
       5,     1,     3,     1,     3,     1,     4,     1,     3,     1,
       1,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     4,     4,     1,     3,     4,     1,     2,     1,
       2,     8,     1,     1,     1,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     0,     1,     9,     0,     1,     1,     2,
       7,     0,     1,     4,     7,     8,    11,     1,     1,     7,
       8,     1,     2,     2,     2,     3,     3,     4,     1,     3,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     4,     3,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     3,     1,     1,     1,
       1,     1
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
#line 33 "parser.y"
                                                                                                   {}
#line 1565 "y.tab.c"
    break;

  case 3: /* declarations: declaration  */
#line 37 "parser.y"
                                                                                                    {}
#line 1571 "y.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 38 "parser.y"
                                                                                                    {}
#line 1577 "y.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 41 "parser.y"
                                                                                                    {}
#line 1583 "y.tab.c"
    break;

  case 6: /* declaration: type_declaration  */
#line 42 "parser.y"
                                                                                                    {}
#line 1589 "y.tab.c"
    break;

  case 7: /* var_declaration: var_specifier type declaration_line SEMICOLON  */
#line 45 "parser.y"
                                                                                                    {}
#line 1595 "y.tab.c"
    break;

  case 8: /* var_specifier: %empty  */
#line 48 "parser.y"
                                                                                                    {}
#line 1601 "y.tab.c"
    break;

  case 9: /* var_specifier: CONST  */
#line 49 "parser.y"
                                                                                                    {}
#line 1607 "y.tab.c"
    break;

  case 10: /* type_declaration: TYPE ID ASSIGNMENT type SEMICOLON  */
#line 52 "parser.y"
                                                                                                    {}
#line 1613 "y.tab.c"
    break;

  case 11: /* declaration_line: declaration_item  */
#line 54 "parser.y"
                                                                                                    {}
#line 1619 "y.tab.c"
    break;

  case 12: /* declaration_line: declaration_line COMMA declaration_item  */
#line 55 "parser.y"
                                                                                                    {}
#line 1625 "y.tab.c"
    break;

  case 13: /* declaration_item: declaration_term  */
#line 58 "parser.y"
                                                                                                    {}
#line 1631 "y.tab.c"
    break;

  case 14: /* declaration_item: declaration_term ASSIGNMENT initialization  */
#line 59 "parser.y"
                                                                                                    {}
#line 1637 "y.tab.c"
    break;

  case 15: /* declaration_term: ID  */
#line 62 "parser.y"
                                                                                                    {}
#line 1643 "y.tab.c"
    break;

  case 16: /* declaration_term: declaration_term LBRACKET expr RBRACKET  */
#line 63 "parser.y"
                                                                                                    {}
#line 1649 "y.tab.c"
    break;

  case 17: /* initialization: expr  */
#line 66 "parser.y"
                                                                                                    {}
#line 1655 "y.tab.c"
    break;

  case 18: /* initialization: LBRACE initialization_list RBRACE  */
#line 67 "parser.y"
                                                                                                    {}
#line 1661 "y.tab.c"
    break;

  case 19: /* initialization: allocation  */
#line 68 "parser.y"
                                                                                                    {}
#line 1667 "y.tab.c"
    break;

  case 20: /* initialization_list: initialization  */
#line 71 "parser.y"
                                                                                                    {}
#line 1673 "y.tab.c"
    break;

  case 21: /* initialization_list: initialization_list COMMA initialization  */
#line 72 "parser.y"
                                                                                                    {}
#line 1679 "y.tab.c"
    break;

  case 22: /* allocation: NEW type LBRACKET expr RBRACKET  */
#line 75 "parser.y"
                                                                                                    {}
#line 1685 "y.tab.c"
    break;

  case 24: /* type: ptr_type  */
#line 80 "parser.y"
                                                                                                    {}
#line 1691 "y.tab.c"
    break;

  case 25: /* type: enum_type  */
#line 81 "parser.y"
                                                                                                    {}
#line 1697 "y.tab.c"
    break;

  case 26: /* type: struct_type  */
#line 82 "parser.y"
                                                                                                    {}
#line 1703 "y.tab.c"
    break;

  case 27: /* type: map_type  */
#line 83 "parser.y"
                                                                                                    {}
#line 1709 "y.tab.c"
    break;

  case 28: /* type: list_type  */
#line 84 "parser.y"
                                                                                                    {}
#line 1715 "y.tab.c"
    break;

  case 29: /* type: ID  */
#line 85 "parser.y"
                                                                                                    {}
#line 1721 "y.tab.c"
    break;

  case 30: /* ptr_type: PTR ABRACKET_OPEN type ABRACKET_CLOSE  */
#line 88 "parser.y"
                                                                                                    {}
#line 1727 "y.tab.c"
    break;

  case 31: /* map_type: MAP ABRACKET_OPEN type COMMA type ABRACKET_CLOSE  */
#line 91 "parser.y"
                                                                                                    {}
#line 1733 "y.tab.c"
    break;

  case 32: /* list_type: LIST ABRACKET_OPEN type ABRACKET_CLOSE  */
#line 94 "parser.y"
                                                                                                    {}
#line 1739 "y.tab.c"
    break;

  case 33: /* enum_type: ENUM LBRACE enum_list RBRACE  */
#line 97 "parser.y"
                                                                                                    {}
#line 1745 "y.tab.c"
    break;

  case 34: /* enum_list: ID  */
#line 100 "parser.y"
                                                                                                    {}
#line 1751 "y.tab.c"
    break;

  case 35: /* enum_list: enum_list COMMA ID  */
#line 101 "parser.y"
                                                                                                    {}
#line 1757 "y.tab.c"
    break;

  case 36: /* struct_type: STRUCT LBRACE struct_vars RBRACE  */
#line 104 "parser.y"
                                                                                                    {}
#line 1763 "y.tab.c"
    break;

  case 37: /* struct_vars: var_declaration  */
#line 107 "parser.y"
                                                                                                    {}
#line 1769 "y.tab.c"
    break;

  case 38: /* struct_vars: struct_vars var_declaration  */
#line 108 "parser.y"
                                                                                                    {}
#line 1775 "y.tab.c"
    break;

  case 39: /* subprograms: subprogram  */
#line 111 "parser.y"
                                                                                                    {}
#line 1781 "y.tab.c"
    break;

  case 40: /* subprograms: subprograms subprogram  */
#line 112 "parser.y"
                                                                                                    {}
#line 1787 "y.tab.c"
    break;

  case 41: /* subprogram: return_type ID LPAREN parameters RPAREN LBRACE statements RBRACE  */
#line 115 "parser.y"
                                                                                                    {}
#line 1793 "y.tab.c"
    break;

  case 42: /* return_type: type  */
#line 118 "parser.y"
                                                                                                    {}
#line 1799 "y.tab.c"
    break;

  case 43: /* return_type: VOID  */
#line 119 "parser.y"
                                                                                                    {}
#line 1805 "y.tab.c"
    break;

  case 44: /* parameters: parameter  */
#line 122 "parser.y"
                                                                                                    {}
#line 1811 "y.tab.c"
    break;

  case 45: /* parameters: parameters COMMA parameter  */
#line 123 "parser.y"
                                                                                                    {}
#line 1817 "y.tab.c"
    break;

  case 46: /* parameter: type ID  */
#line 126 "parser.y"
                                                                                                    {}
#line 1823 "y.tab.c"
    break;

  case 47: /* statements: statement  */
#line 129 "parser.y"
                                                                                                    {}
#line 1829 "y.tab.c"
    break;

  case 48: /* statements: statements statement  */
#line 130 "parser.y"
                                                                                                    {}
#line 1835 "y.tab.c"
    break;

  case 49: /* statement: var_declaration  */
#line 133 "parser.y"
                                                                                                    {}
#line 1841 "y.tab.c"
    break;

  case 50: /* statement: command  */
#line 134 "parser.y"
                                                                                                    {}
#line 1847 "y.tab.c"
    break;

  case 51: /* command: if  */
#line 137 "parser.y"
                                                                                                    {}
#line 1853 "y.tab.c"
    break;

  case 52: /* command: while  */
#line 138 "parser.y"
                                                                                                    {}
#line 1859 "y.tab.c"
    break;

  case 53: /* command: do_while  */
#line 139 "parser.y"
                                                                                                    {}
#line 1865 "y.tab.c"
    break;

  case 54: /* command: for  */
#line 140 "parser.y"
                                                                                                    {}
#line 1871 "y.tab.c"
    break;

  case 55: /* command: switch  */
#line 141 "parser.y"
                                                                                                    {}
#line 1877 "y.tab.c"
    break;

  case 56: /* command: function_call SEMICOLON  */
#line 142 "parser.y"
                                                                                                    {}
#line 1883 "y.tab.c"
    break;

  case 57: /* command: jump SEMICOLON  */
#line 143 "parser.y"
                                                                                                    {}
#line 1889 "y.tab.c"
    break;

  case 58: /* command: deletion  */
#line 144 "parser.y"
                                                                                                    {}
#line 1895 "y.tab.c"
    break;

  case 59: /* jump: CONTINUE  */
#line 147 "parser.y"
                                                                                                    {}
#line 1901 "y.tab.c"
    break;

  case 60: /* jump: BREAK  */
#line 148 "parser.y"
                                                                                                    {}
#line 1907 "y.tab.c"
    break;

  case 61: /* jump: return  */
#line 149 "parser.y"
                                                                                                    {}
#line 1913 "y.tab.c"
    break;

  case 62: /* return: RETURN return_value  */
#line 152 "parser.y"
                                                                                                    {}
#line 1919 "y.tab.c"
    break;

  case 63: /* return_value: %empty  */
#line 155 "parser.y"
                                                                                                    {}
#line 1925 "y.tab.c"
    break;

  case 64: /* return_value: expr  */
#line 156 "parser.y"
                                                                                                    {}
#line 1931 "y.tab.c"
    break;

  case 65: /* if: IF LPAREN expr RPAREN LBRACE statement RBRACE else_ifs_opt else_opt  */
#line 159 "parser.y"
                                                                                                    {}
#line 1937 "y.tab.c"
    break;

  case 66: /* else_ifs_opt: %empty  */
#line 162 "parser.y"
                                                                                                    {}
#line 1943 "y.tab.c"
    break;

  case 67: /* else_ifs_opt: else_ifs  */
#line 163 "parser.y"
                                                                                                    {}
#line 1949 "y.tab.c"
    break;

  case 68: /* else_ifs: else_if  */
#line 166 "parser.y"
                                                                                                    {}
#line 1955 "y.tab.c"
    break;

  case 69: /* else_ifs: else_ifs else_if  */
#line 167 "parser.y"
                                                                                                    {}
#line 1961 "y.tab.c"
    break;

  case 70: /* else_if: ELSEIF LPAREN expr RPAREN LBRACE statements RBRACE  */
#line 170 "parser.y"
                                                                                                    {}
#line 1967 "y.tab.c"
    break;

  case 71: /* else_opt: %empty  */
#line 172 "parser.y"
                                                                                                    {}
#line 1973 "y.tab.c"
    break;

  case 72: /* else_opt: else  */
#line 173 "parser.y"
                                                                                                    {}
#line 1979 "y.tab.c"
    break;

  case 73: /* else: ELSE LBRACE statements RBRACE  */
#line 176 "parser.y"
                                                                                                    {}
#line 1985 "y.tab.c"
    break;

  case 74: /* while: WHILE LPAREN expr RPAREN LBRACE statements RBRACE  */
#line 179 "parser.y"
                                                                                                    {}
#line 1991 "y.tab.c"
    break;

  case 75: /* do_while: DO LBRACE statements RBRACE WHILE LPAREN expr RPAREN  */
#line 182 "parser.y"
                                                                                                    {}
#line 1997 "y.tab.c"
    break;

  case 76: /* for: FOR LPAREN for_initialization COMMA expr COMMA command RPAREN LBRACE statements RBRACE  */
#line 185 "parser.y"
                                                                                                    {}
#line 2003 "y.tab.c"
    break;

  case 77: /* for_initialization: assignment  */
#line 188 "parser.y"
                                                                                                    {}
#line 2009 "y.tab.c"
    break;

  case 78: /* for_initialization: var_declaration  */
#line 189 "parser.y"
                                                                                                    {}
#line 2015 "y.tab.c"
    break;

  case 79: /* switch: SWITCH LPAREN expr RPAREN LBRACE cases RBRACE  */
#line 192 "parser.y"
                                                                                                    {}
#line 2021 "y.tab.c"
    break;

  case 80: /* switch: SWITCH LPAREN expr RPAREN LBRACE cases default RBRACE  */
#line 193 "parser.y"
                                                                                                    {}
#line 2027 "y.tab.c"
    break;

  case 81: /* cases: case  */
#line 196 "parser.y"
                                                                                                    {}
#line 2033 "y.tab.c"
    break;

  case 82: /* cases: cases case  */
#line 197 "parser.y"
                                                                                                    {}
#line 2039 "y.tab.c"
    break;

  case 83: /* case: CASE case_item  */
#line 200 "parser.y"
                                                                                                    {}
#line 2045 "y.tab.c"
    break;

  case 84: /* default: DEFAULT case_item  */
#line 203 "parser.y"
                                                                                                    {}
#line 2051 "y.tab.c"
    break;

  case 85: /* case_item: expr COLON statements  */
#line 206 "parser.y"
                                                                                                    {}
#line 2057 "y.tab.c"
    break;

  case 86: /* function_call: ID LPAREN RPAREN  */
#line 210 "parser.y"
                                                                                                    {}
#line 2063 "y.tab.c"
    break;

  case 87: /* function_call: ID LPAREN parameters_call RPAREN  */
#line 211 "parser.y"
                                                                                                    {}
#line 2069 "y.tab.c"
    break;

  case 88: /* parameters_call: expr  */
#line 214 "parser.y"
                                                                                                    {}
#line 2075 "y.tab.c"
    break;

  case 89: /* parameters_call: parameters_call COMMA expr  */
#line 215 "parser.y"
                                                                                                    {}
#line 2081 "y.tab.c"
    break;

  case 90: /* assignment: assignable assignment_operator assignment_expr SEMICOLON  */
#line 218 "parser.y"
                                                                                                    {}
#line 2087 "y.tab.c"
    break;

  case 91: /* assignable: identifier_ref  */
#line 221 "parser.y"
                                                                                                   {}
#line 2093 "y.tab.c"
    break;

  case 92: /* assignable: VAL postfix_expr  */
#line 222 "parser.y"
                                                                                                    {}
#line 2099 "y.tab.c"
    break;

  case 93: /* assignment_operator: ASSIGNMENT  */
#line 225 "parser.y"
                                                                                                    {}
#line 2105 "y.tab.c"
    break;

  case 94: /* assignment_operator: ASSIGNMENT_MUL  */
#line 226 "parser.y"
                                                                                                    {}
#line 2111 "y.tab.c"
    break;

  case 95: /* assignment_operator: ASSIGNMENT_DIV  */
#line 227 "parser.y"
                                                                                                    {}
#line 2117 "y.tab.c"
    break;

  case 96: /* assignment_operator: ASSIGNMENT_MOD  */
#line 228 "parser.y"
                                                                                                    {}
#line 2123 "y.tab.c"
    break;

  case 97: /* assignment_operator: ASSIGNMENT_ADD  */
#line 229 "parser.y"
                                                                                                    {}
#line 2129 "y.tab.c"
    break;

  case 98: /* assignment_operator: ASSIGNMENT_SUB  */
#line 230 "parser.y"
                                                                                                    {}
#line 2135 "y.tab.c"
    break;

  case 99: /* assignment_expr: expr  */
#line 233 "parser.y"
                                                                                                    {}
#line 2141 "y.tab.c"
    break;

  case 100: /* assignment_expr: allocation  */
#line 234 "parser.y"
                                                                                                    {}
#line 2147 "y.tab.c"
    break;

  case 101: /* deletion: DELETE identifier_ref SEMICOLON  */
#line 237 "parser.y"
                                                                                                    {}
#line 2153 "y.tab.c"
    break;

  case 102: /* identifier_ref: ID  */
#line 240 "parser.y"
                                                                                                    {}
#line 2159 "y.tab.c"
    break;

  case 103: /* identifier_ref: identifier_ref LBRACKET expr RBRACKET  */
#line 241 "parser.y"
                                                                                                    {}
#line 2165 "y.tab.c"
    break;

  case 104: /* identifier_ref: identifier_ref DOT ID  */
#line 242 "parser.y"
                                                                                                    {}
#line 2171 "y.tab.c"
    break;

  case 105: /* expr: or_expr  */
#line 245 "parser.y"
                                                                                                    {}
#line 2177 "y.tab.c"
    break;

  case 106: /* or_expr: and_expr  */
#line 248 "parser.y"
                                                                                                    {}
#line 2183 "y.tab.c"
    break;

  case 107: /* or_expr: or_expr or_operator and_expr  */
#line 249 "parser.y"
                                                                                                    {}
#line 2189 "y.tab.c"
    break;

  case 108: /* or_operator: OR  */
#line 252 "parser.y"
                                                                                                    {}
#line 2195 "y.tab.c"
    break;

  case 109: /* or_operator: ORC  */
#line 253 "parser.y"
                                                                                                    {}
#line 2201 "y.tab.c"
    break;

  case 110: /* and_expr: eq_expr  */
#line 256 "parser.y"
                                                                                                    {}
#line 2207 "y.tab.c"
    break;

  case 111: /* and_expr: and_expr and_operator eq_expr  */
#line 257 "parser.y"
                                                                                                    {}
#line 2213 "y.tab.c"
    break;

  case 112: /* and_operator: AND  */
#line 260 "parser.y"
                                                                                                    {}
#line 2219 "y.tab.c"
    break;

  case 113: /* and_operator: ANDC  */
#line 261 "parser.y"
                                                                                                    {}
#line 2225 "y.tab.c"
    break;

  case 114: /* eq_expr: relational_expr  */
#line 264 "parser.y"
                                                                                                    {}
#line 2231 "y.tab.c"
    break;

  case 115: /* eq_expr: eq_expr eq_operator relational_expr  */
#line 265 "parser.y"
                                                                                                    {}
#line 2237 "y.tab.c"
    break;

  case 116: /* eq_operator: EQUALITY  */
#line 268 "parser.y"
                                                                                                    {}
#line 2243 "y.tab.c"
    break;

  case 117: /* eq_operator: DIFFERENCE  */
#line 269 "parser.y"
                                                                                                    {}
#line 2249 "y.tab.c"
    break;

  case 118: /* relational_expr: arithmetic_expr  */
#line 272 "parser.y"
                                                                                                    {}
#line 2255 "y.tab.c"
    break;

  case 119: /* relational_expr: relational_expr ineq_operator arithmetic_expr  */
#line 273 "parser.y"
                                                                                                    {}
#line 2261 "y.tab.c"
    break;

  case 120: /* ineq_operator: ABRACKET_OPEN  */
#line 276 "parser.y"
                                                                                                    {}
#line 2267 "y.tab.c"
    break;

  case 121: /* ineq_operator: MORE_THAN_EQUALS  */
#line 277 "parser.y"
                                                                                                    {}
#line 2273 "y.tab.c"
    break;

  case 122: /* ineq_operator: ABRACKET_CLOSE  */
#line 278 "parser.y"
                                                                                                    {}
#line 2279 "y.tab.c"
    break;

  case 123: /* ineq_operator: LESS_THAN_EQUALS  */
#line 279 "parser.y"
                                                                                                    {}
#line 2285 "y.tab.c"
    break;

  case 124: /* arithmetic_expr: term  */
#line 282 "parser.y"
                                                                                                    {}
#line 2291 "y.tab.c"
    break;

  case 125: /* arithmetic_expr: arithmetic_expr add_operator term  */
#line 283 "parser.y"
                                                                                                    {}
#line 2297 "y.tab.c"
    break;

  case 126: /* add_operator: PLUS  */
#line 286 "parser.y"
                                                                                                    {}
#line 2303 "y.tab.c"
    break;

  case 127: /* add_operator: MINUS  */
#line 287 "parser.y"
                                                                                                    {}
#line 2309 "y.tab.c"
    break;

  case 128: /* term: prefix_expr  */
#line 290 "parser.y"
                                                                                                    {}
#line 2315 "y.tab.c"
    break;

  case 129: /* term: term mult_operator prefix_expr  */
#line 291 "parser.y"
                                                                                                    {}
#line 2321 "y.tab.c"
    break;

  case 130: /* mult_operator: TIMES  */
#line 294 "parser.y"
                                                                                                    {}
#line 2327 "y.tab.c"
    break;

  case 131: /* mult_operator: SLASH  */
#line 295 "parser.y"
                                                                                                    {}
#line 2333 "y.tab.c"
    break;

  case 132: /* mult_operator: MOD  */
#line 296 "parser.y"
                                                                                                    {}
#line 2339 "y.tab.c"
    break;

  case 133: /* prefix_expr: postfix_expr  */
#line 299 "parser.y"
                                                                                                    {}
#line 2345 "y.tab.c"
    break;

  case 134: /* prefix_expr: unary_operator postfix_expr  */
#line 300 "parser.y"
                                                                                                    {}
#line 2351 "y.tab.c"
    break;

  case 135: /* unary_operator: PLUS  */
#line 303 "parser.y"
                                                                                                    {}
#line 2357 "y.tab.c"
    break;

  case 136: /* unary_operator: MINUS  */
#line 304 "parser.y"
                                                                                                    {}
#line 2363 "y.tab.c"
    break;

  case 137: /* unary_operator: REF  */
#line 305 "parser.y"
                                                                                                    {}
#line 2369 "y.tab.c"
    break;

  case 138: /* unary_operator: VAL  */
#line 306 "parser.y"
                                                                                                    {}
#line 2375 "y.tab.c"
    break;

  case 139: /* unary_operator: NOT  */
#line 307 "parser.y"
                                                                                                    {}
#line 2381 "y.tab.c"
    break;

  case 140: /* postfix_expr: cast  */
#line 310 "parser.y"
                                                                                                    {}
#line 2387 "y.tab.c"
    break;

  case 141: /* postfix_expr: function_call  */
#line 311 "parser.y"
                                                                                                    {}
#line 2393 "y.tab.c"
    break;

  case 142: /* cast: element  */
#line 314 "parser.y"
                                                                                                    {}
#line 2399 "y.tab.c"
    break;

  case 143: /* cast: LPAREN type RPAREN element  */
#line 315 "parser.y"
                                                                                                    {}
#line 2405 "y.tab.c"
    break;

  case 144: /* element: ID  */
#line 318 "parser.y"
                                                                                                    {}
#line 2411 "y.tab.c"
    break;

  case 145: /* element: literal  */
#line 319 "parser.y"
                                                                                                    {}
#line 2417 "y.tab.c"
    break;

  case 146: /* element: LPAREN expr RPAREN  */
#line 320 "parser.y"
                                                                                                    {}
#line 2423 "y.tab.c"
    break;

  case 147: /* literal: INTEGER  */
#line 323 "parser.y"
                                                                                                    {}
#line 2429 "y.tab.c"
    break;

  case 148: /* literal: CHAR  */
#line 324 "parser.y"
                                                                                                    {}
#line 2435 "y.tab.c"
    break;

  case 149: /* literal: STRING  */
#line 325 "parser.y"
                                                                                                    {}
#line 2441 "y.tab.c"
    break;

  case 150: /* literal: REAL  */
#line 326 "parser.y"
                                                                                                    {}
#line 2447 "y.tab.c"
    break;

  case 151: /* literal: BOOL  */
#line 327 "parser.y"
                                                                                                    {}
#line 2453 "y.tab.c"
    break;


#line 2457 "y.tab.c"

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

#line 330 "parser.y"


int main (void) {
	return yyparse ( );
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
