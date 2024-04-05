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
#include <vector>
#include "utils.h"
#include "program.h"
#include <bits/stdc++.h>
using namespace std;
extern void my_exit(int);
extern struct arguments arguments;

int do_parse();
int yyerror(char*);
extern int yylex();
// int yydebug = 1;

#line 88 "y.tab.c"

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
    DO = 258,                      /* DO  */
    WHILE = 259,                   /* WHILE  */
    ELSE = 260,                    /* ELSE  */
    INTEGER = 261,                 /* INTEGER  */
    FLOAT = 262,                   /* FLOAT  */
    BOOL = 263,                    /* BOOL  */
    STRING = 264,                  /* STRING  */
    VOID = 265,                    /* VOID  */
    WRITE = 266,                   /* WRITE  */
    READ = 267,                    /* READ  */
    NAME = 268,                    /* NAME  */
    RETURN = 269,                  /* RETURN  */
    ASSIGN_OP = 270,               /* ASSIGN_OP  */
    GREATER_THAN = 271,            /* GREATER_THAN  */
    LESS_THAN = 272,               /* LESS_THAN  */
    GREATER_THAN_EQUAL = 273,      /* GREATER_THAN_EQUAL  */
    LESS_THAN_EQUAL = 274,         /* LESS_THAN_EQUAL  */
    NOT_EQUAL = 275,               /* NOT_EQUAL  */
    EQUAL = 276,                   /* EQUAL  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    MULT = 279,                    /* MULT  */
    ADDRESSOF = 280,               /* ADDRESSOF  */
    LEFT_CURLY_BRACKET = 281,      /* LEFT_CURLY_BRACKET  */
    RIGHT_CURLY_BRACKET = 282,     /* RIGHT_CURLY_BRACKET  */
    LEFT_ROUND_BRACKET = 283,      /* LEFT_ROUND_BRACKET  */
    RIGHT_ROUND_BRACKET = 284,     /* RIGHT_ROUND_BRACKET  */
    LEFT_SQUARE_BRACKET = 285,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 286,    /* RIGHT_SQUARE_BRACKET  */
    SEMICOLON = 287,               /* SEMICOLON  */
    COMMA = 288,                   /* COMMA  */
    OP_FOR_TERNARY_EXPR = 289,     /* OP_FOR_TERNARY_EXPR  */
    FLOAT_NUM = 290,               /* FLOAT_NUM  */
    INT_NUM = 291,                 /* INT_NUM  */
    STR_CONST = 292,               /* STR_CONST  */
    DIV = 293,                     /* DIV  */
    IF = 294,                      /* IF  */
    NOT_IN_CURRENT_LEVEL = 295,    /* NOT_IN_CURRENT_LEVEL  */
    IGNORE = 296,                  /* IGNORE  */
    AND = 297,                     /* AND  */
    OR = 298,                      /* OR  */
    NOT = 299,                     /* NOT  */
    UNKNOWN_CHAR = 300,            /* UNKNOWN_CHAR  */
    UMINUS = 301,                  /* UMINUS  */
    ifakela = 302                  /* ifakela  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DO 258
#define WHILE 259
#define ELSE 260
#define INTEGER 261
#define FLOAT 262
#define BOOL 263
#define STRING 264
#define VOID 265
#define WRITE 266
#define READ 267
#define NAME 268
#define RETURN 269
#define ASSIGN_OP 270
#define GREATER_THAN 271
#define LESS_THAN 272
#define GREATER_THAN_EQUAL 273
#define LESS_THAN_EQUAL 274
#define NOT_EQUAL 275
#define EQUAL 276
#define PLUS 277
#define MINUS 278
#define MULT 279
#define ADDRESSOF 280
#define LEFT_CURLY_BRACKET 281
#define RIGHT_CURLY_BRACKET 282
#define LEFT_ROUND_BRACKET 283
#define RIGHT_ROUND_BRACKET 284
#define LEFT_SQUARE_BRACKET 285
#define RIGHT_SQUARE_BRACKET 286
#define SEMICOLON 287
#define COMMA 288
#define OP_FOR_TERNARY_EXPR 289
#define FLOAT_NUM 290
#define INT_NUM 291
#define STR_CONST 292
#define DIV 293
#define IF 294
#define NOT_IN_CURRENT_LEVEL 295
#define IGNORE 296
#define AND 297
#define OR 298
#define NOT 299
#define UNKNOWN_CHAR 300
#define UMINUS 301
#define ifakela 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parser.y"

	char* name;
	AST* ast;
	vector<AST*>* vec_of_ast;
	SymbolTable* symtab;
	st_datatype dtype;
	Procedure* procedure;
	ProcedureDefn* procdef;
	Symbol* symb;
	Program* prog;
	vector<Symbol*>* vecsymb;

#line 248 "y.tab.c"

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
  YYSYMBOL_DO = 3,                         /* DO  */
  YYSYMBOL_WHILE = 4,                      /* WHILE  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_WRITE = 11,                     /* WRITE  */
  YYSYMBOL_READ = 12,                      /* READ  */
  YYSYMBOL_NAME = 13,                      /* NAME  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_ASSIGN_OP = 15,                 /* ASSIGN_OP  */
  YYSYMBOL_GREATER_THAN = 16,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 17,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN_EQUAL = 18,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_LESS_THAN_EQUAL = 19,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 20,                 /* NOT_EQUAL  */
  YYSYMBOL_EQUAL = 21,                     /* EQUAL  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MULT = 24,                      /* MULT  */
  YYSYMBOL_ADDRESSOF = 25,                 /* ADDRESSOF  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 26,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 27,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_LEFT_ROUND_BRACKET = 28,        /* LEFT_ROUND_BRACKET  */
  YYSYMBOL_RIGHT_ROUND_BRACKET = 29,       /* RIGHT_ROUND_BRACKET  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 30,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 31,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 33,                     /* COMMA  */
  YYSYMBOL_OP_FOR_TERNARY_EXPR = 34,       /* OP_FOR_TERNARY_EXPR  */
  YYSYMBOL_FLOAT_NUM = 35,                 /* FLOAT_NUM  */
  YYSYMBOL_INT_NUM = 36,                   /* INT_NUM  */
  YYSYMBOL_STR_CONST = 37,                 /* STR_CONST  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_IF = 39,                        /* IF  */
  YYSYMBOL_NOT_IN_CURRENT_LEVEL = 40,      /* NOT_IN_CURRENT_LEVEL  */
  YYSYMBOL_IGNORE = 41,                    /* IGNORE  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_UNKNOWN_CHAR = 45,              /* UNKNOWN_CHAR  */
  YYSYMBOL_46_ = 46,                       /* '?'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_ifakela = 49,                   /* ifakela  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_global_decl_statement_list = 52, /* global_decl_statement_list  */
  YYSYMBOL_var_decl_stmt = 53,             /* var_decl_stmt  */
  YYSYMBOL_var_decl_item_list = 54,        /* var_decl_item_list  */
  YYSYMBOL_var_decl_item = 55,             /* var_decl_item  */
  YYSYMBOL_named_type = 56,                /* named_type  */
  YYSYMBOL_param_type = 57,                /* param_type  */
  YYSYMBOL_func_decl = 58,                 /* func_decl  */
  YYSYMBOL_func_decl_defn = 59,            /* func_decl_defn  */
  YYSYMBOL_funcdecl_param_list = 60,       /* funcdecl_param_list  */
  YYSYMBOL_funcdecl_param = 61,            /* funcdecl_param  */
  YYSYMBOL_func_defn = 62,                 /* func_defn  */
  YYSYMBOL_optional_var_decl_stmt_list = 63, /* optional_var_decl_stmt_list  */
  YYSYMBOL_var_decl_stmt_list = 64,        /* var_decl_stmt_list  */
  YYSYMBOL_statement_list = 65,            /* statement_list  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_if_condition = 67,              /* if_condition  */
  YYSYMBOL_if_statement = 68,              /* if_statement  */
  YYSYMBOL_do_while_statement = 69,        /* do_while_statement  */
  YYSYMBOL_while_statement = 70,           /* while_statement  */
  YYSYMBOL_compound_statement = 71,        /* compound_statement  */
  YYSYMBOL_print_statement = 72,           /* print_statement  */
  YYSYMBOL_read_statement = 73,            /* read_statement  */
  YYSYMBOL_assignment_statement = 74,      /* assignment_statement  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_relative_expression = 76,       /* relative_expression  */
  YYSYMBOL_variable_as_operand = 77,       /* variable_as_operand  */
  YYSYMBOL_constant_as_operand = 78        /* constant_as_operand  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   389

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
       2,     2,     2,     2,     2,     2,     2,     2,    47,     2,
       2,     2,     2,    46,     2,     2,     2,     2,     2,     2,
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
      45,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   126,   133,   141,   150,   159,   170,   177,
     185,   194,   199,   207,   215,   220,   225,   230,   235,   243,
     248,   253,   258,   266,   271,   278,   283,   291,   297,   306,
     315,   323,   328,   336,   341,   351,   357,   365,   370,   375,
     380,   386,   392,   398,   406,   414,   419,   427,   435,   443,
     451,   459,   467,   475,   480,   485,   490,   495,   500,   501,
     506,   511,   516,   517,   518,   519,   523,   528,   533,   538,
     543,   548,   556,   560,   561,   562
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
  "\"end of file\"", "error", "\"invalid token\"", "DO", "WHILE", "ELSE",
  "INTEGER", "FLOAT", "BOOL", "STRING", "VOID", "WRITE", "READ", "NAME",
  "RETURN", "ASSIGN_OP", "GREATER_THAN", "LESS_THAN", "GREATER_THAN_EQUAL",
  "LESS_THAN_EQUAL", "NOT_EQUAL", "EQUAL", "PLUS", "MINUS", "MULT",
  "ADDRESSOF", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET",
  "LEFT_ROUND_BRACKET", "RIGHT_ROUND_BRACKET", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "SEMICOLON", "COMMA", "OP_FOR_TERNARY_EXPR",
  "FLOAT_NUM", "INT_NUM", "STR_CONST", "DIV", "IF", "NOT_IN_CURRENT_LEVEL",
  "IGNORE", "AND", "OR", "NOT", "UNKNOWN_CHAR", "'?'", "':'", "UMINUS",
  "ifakela", "$accept", "program", "global_decl_statement_list",
  "var_decl_stmt", "var_decl_item_list", "var_decl_item", "named_type",
  "param_type", "func_decl", "func_decl_defn", "funcdecl_param_list",
  "funcdecl_param", "func_defn", "optional_var_decl_stmt_list",
  "var_decl_stmt_list", "statement_list", "statement", "if_condition",
  "if_statement", "do_while_statement", "while_statement",
  "compound_statement", "print_statement", "read_statement",
  "assignment_statement", "expression", "relative_expression",
  "variable_as_operand", "constant_as_operand", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,   -62,   -62,   -62,   -62,   -62,    16,    55,   -62,    31,
      55,   -62,   -62,   -62,    55,   -62,   -62,    54,   -62,   -10,
      55,    31,   -62,    55,   -62,   -62,    31,   191,   -62,    24,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    -6,    31,     2,
     -62,   222,    55,   -62,   -62,     7,   125,    28,     9,   -62,
      31,    30,   -62,    55,    55,   -62,   -62,    62,   -62,   109,
     -62,    53,   109,    61,    80,    31,   -62,    63,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,    66,   -62,    88,    80,
      80,    80,   -62,   -62,   -62,    80,   133,   -62,   -62,   -62,
      65,    10,    80,   109,    80,    67,   164,   -62,   195,   328,
      80,    80,    80,    80,    80,    80,    80,    80,    80,   -62,
      80,    80,    80,    80,   -62,   -62,   226,    89,   257,    80,
     109,   -62,   351,   351,   351,   351,   351,   351,   -13,   -13,
     -62,   -62,   328,   -14,   120,   -62,   109,   -62,   288,   -62,
      80,   -62,    68,   319,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    14,    15,    18,    17,    16,     0,     0,     9,     0,
       0,     3,     1,     8,     0,     2,    72,     0,    12,    13,
       0,     0,     7,     0,     4,    10,     0,     0,     5,    13,
       6,    11,    13,    19,    20,    22,    21,     0,     0,     0,
      28,     0,    31,    24,    29,     0,     0,     0,     0,    33,
       0,     0,    36,    32,    31,    23,    27,     0,    26,    30,
      34,     0,     0,     0,     0,     0,    36,     0,    35,    41,
      42,    43,    40,    38,    39,    37,     0,    25,     0,     0,
       0,     0,    74,    73,    75,     0,     0,    63,    64,    65,
       0,     0,     0,     0,     0,     0,     0,    57,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,    51,    49,     0,    46,     0,     0,
       0,    58,    68,    66,    69,    67,    70,    71,    53,    54,
      55,    56,    60,    61,     0,    44,     0,    52,     0,    48,
       0,    45,     0,    59,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,     5,    76,   -62,    72,    48,   -62,    97,    20,
      64,    73,    56,   -62,   -62,    41,   -61,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -34,   -62,    -9,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,    17,    18,    21,    38,    10,    11,
      39,    40,    51,    52,    53,    59,    68,    93,    69,    70,
      71,    72,    73,    74,    75,    86,    87,    88,    89
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    78,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   108,    29,    62,    63,    20,    12,    32,    27,    23,
      42,    64,    65,    16,   110,   110,    43,    15,   111,    44,
      22,    45,   117,    54,    24,    46,    66,   115,    57,    55,
      28,    32,    46,    30,    16,    96,    97,    98,     9,    67,
      76,    99,    41,    76,    42,     9,    90,    58,   116,   139,
     118,     1,     2,     3,     4,     5,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   141,   131,   132,   133,   134,
      77,    94,    76,    13,    76,   138,    25,    26,    54,    79,
      50,    92,    95,    16,   136,   119,    13,   114,    31,    13,
     144,    50,    50,    80,    14,    48,   143,    91,    81,     0,
      61,    76,    62,    63,     0,    82,    83,    84,    49,    56,
      64,    65,    16,     0,    85,     0,     0,    76,     0,    60,
      49,    33,    34,    35,    36,    66,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,    67,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   110,     0,
       0,     0,   111,   112,     0,   109,   113,   140,     0,     0,
       0,   110,     0,     0,     0,   111,   112,     0,     0,   113,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,   120,     0,     0,     0,    33,    34,    35,
      36,     0,   110,     0,     0,     0,   111,   112,     0,     0,
     113,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      37,     0,     0,     0,   121,     0,     0,     0,    33,    34,
      35,    36,     0,   110,     0,     0,     0,   111,   112,     0,
       0,   113,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    47,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,   111,   112,
       0,     0,   113,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,     0,     0,     0,   110,     0,     0,     0,   111,
     112,     0,     0,   113,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
     111,   112,     0,     0,   113,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   110,     0,     0,
       0,   111,   112,     0,     0,   113,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110
};

static const yytype_int16 yycheck[] =
{
       9,    62,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    24,    21,     3,     4,    10,     0,    26,    28,    14,
      26,    11,    12,    13,    38,    38,    32,     7,    42,    38,
      10,    29,    93,    26,    14,    33,    26,    27,    29,    32,
      20,    50,    33,    23,    13,    79,    80,    81,     0,    39,
      59,    85,    28,    62,    26,     7,    65,    27,    92,   120,
      94,     6,     7,     8,     9,    10,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   136,   110,   111,   112,   113,
      27,    15,    91,     7,    93,   119,    32,    33,    26,    28,
      42,    28,     4,    13,     5,    28,    20,    32,    26,    23,
      32,    53,    54,    23,     7,    41,   140,    66,    28,    -1,
      54,   120,     3,     4,    -1,    35,    36,    37,    42,    46,
      11,    12,    13,    -1,    44,    -1,    -1,   136,    -1,    53,
      54,     6,     7,     8,     9,    26,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    39,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    38,    -1,
      -1,    -1,    42,    43,    -1,    32,    46,    47,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    46,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,     6,     7,     8,
       9,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,
      46,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      29,    -1,    -1,    -1,    29,    -1,    -1,    -1,     6,     7,
       8,     9,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,
      -1,    46,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    29,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
      43,    -1,    -1,    46,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      42,    43,    -1,    -1,    46,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    43,    -1,    -1,    46,    38,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    51,    52,    53,    56,
      58,    59,     0,    53,    58,    59,    13,    54,    55,    77,
      52,    56,    59,    52,    59,    32,    33,    28,    59,    77,
      59,    55,    77,     6,     7,     8,     9,    29,    57,    60,
      61,    28,    26,    32,    77,    29,    33,    29,    60,    53,
      56,    62,    63,    64,    26,    32,    61,    29,    27,    65,
      53,    62,     3,     4,    11,    12,    26,    39,    66,    68,
      69,    70,    71,    72,    73,    74,    77,    27,    66,    28,
      23,    28,    35,    36,    37,    44,    75,    76,    77,    78,
      77,    65,    28,    67,    15,     4,    75,    75,    75,    75,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    32,
      38,    42,    43,    46,    32,    27,    75,    66,    75,    28,
      29,    29,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    29,     5,    32,    75,    66,
      47,    66,    29,    75,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    51,    51,    52,    52,
      53,    54,    54,    55,    56,    56,    56,    56,    56,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    67,    68,    68,    69,    70,    71,
      72,    73,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    77,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     3,     4,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     5,     8,     7,     3,     1,     2,
       2,     0,     1,     1,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     3,     7,     5,     3,
       3,     3,     4,     3,     3,     3,     3,     2,     3,     5,
       3,     3,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1
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
  case 2: /* program: global_decl_statement_list func_decl_defn  */
#line 119 "parser.y"
                                                    {
													if(!arguments.stop_after_parsing){
														(yyval.prog) = new Program((yyvsp[-1].symtab), (yyvsp[0].procedure));
														(yyval.prog)->main_func_check();
														continue_after_ast((yyval.prog));
													}
												}
#line 1461 "y.tab.c"
    break;

  case 3: /* program: func_decl_defn  */
#line 126 "parser.y"
                         {
													if(!arguments.stop_after_parsing){
														(yyval.prog) = new Program(new SymbolTable(), (yyvsp[0].procedure));
														(yyval.prog)->main_func_check();
														continue_after_ast((yyval.prog));
													}
												}
#line 1473 "y.tab.c"
    break;

  case 4: /* program: global_decl_statement_list func_decl func_decl_defn  */
#line 133 "parser.y"
                                                              {
													if(!arguments.stop_after_parsing){
														(yyval.prog) = new Program((yyvsp[-2].symtab), (yyvsp[-1].procedure));
														(yyval.prog)->add_procedure((yyvsp[0].procedure));
														(yyval.prog)->main_func_check();
														continue_after_ast((yyval.prog));
													}
												}
#line 1486 "y.tab.c"
    break;

  case 5: /* program: func_decl global_decl_statement_list func_decl_defn  */
#line 141 "parser.y"
                                                              {
													if(!arguments.stop_after_parsing){
														(yyval.prog) = new Program(new SymbolTable(), (yyvsp[-2].procedure));
														(yyval.prog)->add_global_symbols((yyvsp[-1].symtab));
														(yyval.prog)->add_procedure((yyvsp[0].procedure));
														(yyval.prog)->main_func_check();
														continue_after_ast((yyval.prog));
													}
												}
#line 1500 "y.tab.c"
    break;

  case 6: /* program: global_decl_statement_list func_decl global_decl_statement_list func_decl_defn  */
#line 150 "parser.y"
                                                                                         {
													if(!arguments.stop_after_parsing){
														(yyval.prog) = new Program((yyvsp[-3].symtab), (yyvsp[-2].procedure));
														(yyval.prog)->add_global_symbols((yyvsp[-1].symtab));
														(yyval.prog)->add_procedure((yyvsp[0].procedure));
														(yyval.prog)->main_func_check();
														continue_after_ast((yyval.prog));
													}
												}
#line 1514 "y.tab.c"
    break;

  case 7: /* program: func_decl func_decl_defn  */
#line 159 "parser.y"
                                   {
													if(!arguments.stop_after_parsing){
														(yyval.prog) = new Program(new SymbolTable(), (yyvsp[-1].procedure));
														(yyval.prog)->add_procedure((yyvsp[0].procedure));
														(yyval.prog)->main_func_check();
														continue_after_ast((yyval.prog));
													}
												}
#line 1527 "y.tab.c"
    break;

  case 8: /* global_decl_statement_list: global_decl_statement_list var_decl_stmt  */
#line 170 "parser.y"
                                                   {
													if(!arguments.stop_after_parsing){
														(yyvsp[-1].symtab)->add_symbols_from_table((yyvsp[0].symtab));
														(yyval.symtab) = (yyvsp[-1].symtab);
														// delete $2;
													}
												}
#line 1539 "y.tab.c"
    break;

  case 9: /* global_decl_statement_list: var_decl_stmt  */
#line 177 "parser.y"
                        {
													if(!arguments.stop_after_parsing){
														(yyval.symtab) = (yyvsp[0].symtab);
													}
												}
#line 1549 "y.tab.c"
    break;

  case 10: /* var_decl_stmt: named_type var_decl_item_list SEMICOLON  */
#line 185 "parser.y"
                                                  {
													if(!arguments.stop_after_parsing){
														(yyval.symtab) = new SymbolTable((yyvsp[-2].dtype), (yyvsp[-1].vec_of_ast),true);
														// delete $2;
													}
												}
#line 1560 "y.tab.c"
    break;

  case 11: /* var_decl_item_list: var_decl_item_list COMMA var_decl_item  */
#line 194 "parser.y"
                                                 {
													if(!arguments.stop_after_parsing){
														(yyval.vec_of_ast)->push_back((yyvsp[0].ast));
													}
												}
#line 1570 "y.tab.c"
    break;

  case 12: /* var_decl_item_list: var_decl_item  */
#line 199 "parser.y"
                        {
													if(!arguments.stop_after_parsing){
														(yyval.vec_of_ast) = new vector<AST*> (1, (yyvsp[0].ast));
													}
												}
#line 1580 "y.tab.c"
    break;

  case 13: /* var_decl_item: variable_as_operand  */
#line 207 "parser.y"
                              {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1590 "y.tab.c"
    break;

  case 14: /* named_type: INTEGER  */
#line 215 "parser.y"
                  {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_INTEGER;
													}
												}
#line 1600 "y.tab.c"
    break;

  case 15: /* named_type: FLOAT  */
#line 220 "parser.y"
                {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_FLOAT;
													}
												}
#line 1610 "y.tab.c"
    break;

  case 16: /* named_type: VOID  */
#line 225 "parser.y"
               {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_VOID;
													}
												}
#line 1620 "y.tab.c"
    break;

  case 17: /* named_type: STRING  */
#line 230 "parser.y"
                 {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_STRING;
													}
												}
#line 1630 "y.tab.c"
    break;

  case 18: /* named_type: BOOL  */
#line 235 "parser.y"
               {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_BOOL;
													}
												}
#line 1640 "y.tab.c"
    break;

  case 19: /* param_type: INTEGER  */
#line 243 "parser.y"
                  {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_INTEGER; 	
													}
												}
#line 1650 "y.tab.c"
    break;

  case 20: /* param_type: FLOAT  */
#line 248 "parser.y"
                {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_FLOAT;
													}
												}
#line 1660 "y.tab.c"
    break;

  case 21: /* param_type: STRING  */
#line 253 "parser.y"
                 {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_STRING;
													}
												}
#line 1670 "y.tab.c"
    break;

  case 22: /* param_type: BOOL  */
#line 258 "parser.y"
               {
													if(!arguments.stop_after_parsing){
														(yyval.dtype) = DTYPE_BOOL;
													}
												}
#line 1680 "y.tab.c"
    break;

  case 23: /* func_decl: named_type variable_as_operand LEFT_ROUND_BRACKET funcdecl_param_list RIGHT_ROUND_BRACKET SEMICOLON  */
#line 266 "parser.y"
                                                                                                              {
													if(!arguments.stop_after_parsing){
														(yyval.procedure) = new Procedure((yyvsp[-4].ast), (yyvsp[-2].vecsymb), (yyvsp[-5].dtype));
													}
												}
#line 1690 "y.tab.c"
    break;

  case 24: /* func_decl: named_type variable_as_operand LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET SEMICOLON  */
#line 271 "parser.y"
                                                                                          {
													if(!arguments.stop_after_parsing){
														(yyval.procedure) = new Procedure((yyvsp[-3].ast), new vector<Symbol*>(), (yyvsp[-4].dtype));
													}
												}
#line 1700 "y.tab.c"
    break;

  case 25: /* func_decl_defn: named_type variable_as_operand LEFT_ROUND_BRACKET funcdecl_param_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET func_defn RIGHT_CURLY_BRACKET  */
#line 278 "parser.y"
                                                                                                                                                     {
													if(!arguments.stop_after_parsing){
														(yyval.procedure) = new Procedure((yyvsp[-6].ast), (yyvsp[-4].vecsymb), (yyvsp[-1].procdef), (yyvsp[-7].dtype));
													}
												}
#line 1710 "y.tab.c"
    break;

  case 26: /* func_decl_defn: named_type variable_as_operand LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET func_defn RIGHT_CURLY_BRACKET  */
#line 283 "parser.y"
                                                                                                                                 {
													if(!arguments.stop_after_parsing){
														(yyval.procedure) = new Procedure((yyvsp[-5].ast), new vector<Symbol*>(), (yyvsp[-1].procdef), (yyvsp[-6].dtype));
													}
												}
#line 1720 "y.tab.c"
    break;

  case 27: /* funcdecl_param_list: funcdecl_param_list COMMA funcdecl_param  */
#line 291 "parser.y"
                                                   {
													if(!arguments.stop_after_parsing){
														(yyval.vecsymb) = (yyvsp[-2].vecsymb);
														(yyvsp[-2].vecsymb)->push_back((yyvsp[0].symb));
													}
												}
#line 1731 "y.tab.c"
    break;

  case 28: /* funcdecl_param_list: funcdecl_param  */
#line 297 "parser.y"
                         {
													if(!arguments.stop_after_parsing){
														(yyval.vecsymb) = new vector<Symbol*> ();
														(yyval.vecsymb)->push_back((yyvsp[0].symb));
													}
												}
#line 1742 "y.tab.c"
    break;

  case 29: /* funcdecl_param: param_type variable_as_operand  */
#line 306 "parser.y"
                                         {
													if(!arguments.stop_after_parsing){
														(yyval.symb) = new Symbol((yyvsp[0].ast), (yyvsp[-1].dtype));
														// delete $2;
													}
												}
#line 1753 "y.tab.c"
    break;

  case 30: /* func_defn: optional_var_decl_stmt_list statement_list  */
#line 315 "parser.y"
                                                     {
													if(!arguments.stop_after_parsing){
														(yyval.procdef) = new ProcedureDefn((yyvsp[-1].symtab), *(yyvsp[0].vec_of_ast));
													}
												}
#line 1763 "y.tab.c"
    break;

  case 31: /* optional_var_decl_stmt_list: %empty  */
#line 323 "parser.y"
                 {
													if(!arguments.stop_after_parsing){
														(yyval.symtab) = new SymbolTable();
													}
												}
#line 1773 "y.tab.c"
    break;

  case 32: /* optional_var_decl_stmt_list: var_decl_stmt_list  */
#line 328 "parser.y"
                             {
													if(!arguments.stop_after_parsing){
														(yyval.symtab) = (yyvsp[0].symtab);
													}
												}
#line 1783 "y.tab.c"
    break;

  case 33: /* var_decl_stmt_list: var_decl_stmt  */
#line 336 "parser.y"
                        {
													if(!arguments.stop_after_parsing){
														(yyval.symtab) = (yyvsp[0].symtab);														
													}
												}
#line 1793 "y.tab.c"
    break;

  case 34: /* var_decl_stmt_list: var_decl_stmt_list var_decl_stmt  */
#line 341 "parser.y"
                                           {
													if(!arguments.stop_after_parsing){
														(yyvsp[-1].symtab)->add_symbols_from_table((yyvsp[0].symtab));
														(yyval.symtab) = (yyvsp[-1].symtab);
														// delete $2;
													}
												}
#line 1805 "y.tab.c"
    break;

  case 35: /* statement_list: statement_list statement  */
#line 351 "parser.y"
                                   {
													if(!arguments.stop_after_parsing){
														(yyvsp[-1].vec_of_ast)->push_back((yyvsp[0].ast));
														(yyval.vec_of_ast) = (yyvsp[-1].vec_of_ast);
													}
												}
#line 1816 "y.tab.c"
    break;

  case 36: /* statement_list: %empty  */
#line 357 "parser.y"
                 {
													if(!arguments.stop_after_parsing){
														(yyval.vec_of_ast) = new vector<AST*>;
													}
												}
#line 1826 "y.tab.c"
    break;

  case 37: /* statement: assignment_statement  */
#line 365 "parser.y"
                               {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1836 "y.tab.c"
    break;

  case 38: /* statement: print_statement  */
#line 370 "parser.y"
                          {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1846 "y.tab.c"
    break;

  case 39: /* statement: read_statement  */
#line 375 "parser.y"
                         {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1856 "y.tab.c"
    break;

  case 40: /* statement: compound_statement  */
#line 380 "parser.y"
                             {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1866 "y.tab.c"
    break;

  case 41: /* statement: if_statement  */
#line 386 "parser.y"
                       {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1876 "y.tab.c"
    break;

  case 42: /* statement: do_while_statement  */
#line 392 "parser.y"
                             {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1886 "y.tab.c"
    break;

  case 43: /* statement: while_statement  */
#line 398 "parser.y"
                          {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[0].ast);
													}
												}
#line 1896 "y.tab.c"
    break;

  case 44: /* if_condition: LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET  */
#line 406 "parser.y"
                                                            {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = (yyvsp[-1].ast);
													}
												}
#line 1906 "y.tab.c"
    break;

  case 45: /* if_statement: IF if_condition statement ELSE statement  */
#line 414 "parser.y"
                                                    {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new SelectionStatementAST((yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
													}
												}
#line 1916 "y.tab.c"
    break;

  case 46: /* if_statement: IF if_condition statement  */
#line 419 "parser.y"
                                                   {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new SelectionStatementAST((yyvsp[-1].ast), (yyvsp[0].ast), NULL);
													}
												}
#line 1926 "y.tab.c"
    break;

  case 47: /* do_while_statement: DO statement WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET SEMICOLON  */
#line 427 "parser.y"
                                                                                         {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new IterationStatementAST((yyvsp[-2].ast), (yyvsp[-5].ast), true);
													}
												}
#line 1936 "y.tab.c"
    break;

  case 48: /* while_statement: WHILE LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET statement  */
#line 435 "parser.y"
                                                                                 {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new IterationStatementAST((yyvsp[-2].ast), (yyvsp[0].ast), false);
													}
												}
#line 1946 "y.tab.c"
    break;

  case 49: /* compound_statement: LEFT_CURLY_BRACKET statement_list RIGHT_CURLY_BRACKET  */
#line 443 "parser.y"
                                                                   {
																if(!arguments.stop_after_parsing){
																	(yyval.ast) = new SequenceStatementAST(*(yyvsp[-1].vec_of_ast));
																}
												}
#line 1956 "y.tab.c"
    break;

  case 50: /* print_statement: WRITE expression SEMICOLON  */
#line 451 "parser.y"
                                     {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new PrintStatementAST((yyvsp[-1].ast));
													}
												}
#line 1966 "y.tab.c"
    break;

  case 51: /* read_statement: READ variable_as_operand SEMICOLON  */
#line 459 "parser.y"
                                             {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new ReadStatementAST((yyvsp[-1].ast));
													}
												}
#line 1976 "y.tab.c"
    break;

  case 52: /* assignment_statement: variable_as_operand ASSIGN_OP expression SEMICOLON  */
#line 467 "parser.y"
                                                                {
												if (!arguments.stop_after_parsing){
													(yyval.ast) = new AssignmentStatementAST((yyvsp[-3].ast),(yyvsp[-1].ast));
												}
											}
#line 1986 "y.tab.c"
    break;

  case 53: /* expression: expression PLUS expression  */
#line 475 "parser.y"
                                                {
											if (!arguments.stop_after_parsing){
												(yyval.ast) = new PlusExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast));
											}
										}
#line 1996 "y.tab.c"
    break;

  case 54: /* expression: expression MINUS expression  */
#line 480 "parser.y"
                                                {
											if (!arguments.stop_after_parsing){
												(yyval.ast) = new MinusExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast));
											}
										}
#line 2006 "y.tab.c"
    break;

  case 55: /* expression: expression MULT expression  */
#line 485 "parser.y"
                                                {
											if (!arguments.stop_after_parsing){
												(yyval.ast) = new MultiplicationExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast));
											}
										}
#line 2016 "y.tab.c"
    break;

  case 56: /* expression: expression DIV expression  */
#line 490 "parser.y"
                                                        {
											if (!arguments.stop_after_parsing){
												(yyval.ast) = new DivisionExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast));
											}
										}
#line 2026 "y.tab.c"
    break;

  case 57: /* expression: MINUS expression  */
#line 495 "parser.y"
                                                {
											if (!arguments.stop_after_parsing){
												(yyval.ast) = new UMinusExpressionAST((yyvsp[0].ast));
											}
										}
#line 2036 "y.tab.c"
    break;

  case 58: /* expression: LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET  */
#line 500 "parser.y"
                                                                {if(!arguments.stop_after_parsing){ (yyval.ast) = (yyvsp[-1].ast); }}
#line 2042 "y.tab.c"
    break;

  case 59: /* expression: expression '?' expression ':' expression  */
#line 501 "parser.y"
                                                   {
													if (!arguments.stop_after_parsing){
														(yyval.ast) = new ConditionalExpressionAST((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast));
													}
												}
#line 2052 "y.tab.c"
    break;

  case 60: /* expression: expression AND expression  */
#line 506 "parser.y"
                                                        {
											if (!arguments.stop_after_parsing){
												(yyval.ast) = new BooleanExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),BOOL_AND);
											}
										}
#line 2062 "y.tab.c"
    break;

  case 61: /* expression: expression OR expression  */
#line 511 "parser.y"
                                                        {
											if (!arguments.stop_after_parsing){
												(yyval.ast) = new BooleanExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),BOOL_OR);
											}
										}
#line 2072 "y.tab.c"
    break;

  case 62: /* expression: NOT expression  */
#line 516 "parser.y"
                                                                {if(!arguments.stop_after_parsing){(yyval.ast) = new NotBoolExpressionAST((yyvsp[0].ast));}}
#line 2078 "y.tab.c"
    break;

  case 63: /* expression: relative_expression  */
#line 517 "parser.y"
                                                        {if(!arguments.stop_after_parsing){ (yyval.ast) = (yyvsp[0].ast); }}
#line 2084 "y.tab.c"
    break;

  case 64: /* expression: variable_as_operand  */
#line 518 "parser.y"
                                                        {if(!arguments.stop_after_parsing){ (yyval.ast) = (yyvsp[0].ast); }}
#line 2090 "y.tab.c"
    break;

  case 65: /* expression: constant_as_operand  */
#line 519 "parser.y"
                                                        {if(!arguments.stop_after_parsing){ (yyval.ast) = (yyvsp[0].ast); }}
#line 2096 "y.tab.c"
    break;

  case 66: /* relative_expression: expression LESS_THAN expression  */
#line 523 "parser.y"
                                          {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new RelationalExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),RELOP_LESS_THAN);
													}
												}
#line 2106 "y.tab.c"
    break;

  case 67: /* relative_expression: expression LESS_THAN_EQUAL expression  */
#line 528 "parser.y"
                                                {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new RelationalExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),RELOP_LESS_THAN_EQUAL);
													}
												}
#line 2116 "y.tab.c"
    break;

  case 68: /* relative_expression: expression GREATER_THAN expression  */
#line 533 "parser.y"
                                             {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new RelationalExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),RELOP_GREATER_THAN);
													}
												}
#line 2126 "y.tab.c"
    break;

  case 69: /* relative_expression: expression GREATER_THAN_EQUAL expression  */
#line 538 "parser.y"
                                                   {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new RelationalExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),RELOP_GREATER_THAN_EQUAL);
													}
												}
#line 2136 "y.tab.c"
    break;

  case 70: /* relative_expression: expression NOT_EQUAL expression  */
#line 543 "parser.y"
                                          {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new RelationalExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),RELOP_NOT_EQUAL);
													}
												}
#line 2146 "y.tab.c"
    break;

  case 71: /* relative_expression: expression EQUAL expression  */
#line 548 "parser.y"
                                      {
													if(!arguments.stop_after_parsing){
														(yyval.ast) = new RelationalExpressionAST((yyvsp[-2].ast),(yyvsp[0].ast),RELOP_EQUAL);
													}
												}
#line 2156 "y.tab.c"
    break;

  case 72: /* variable_as_operand: NAME  */
#line 556 "parser.y"
                                                                {if(!arguments.stop_after_parsing){ (yyval.ast) = new NameExpressionAST((yyvsp[0].name));/*free($1);*/}}
#line 2162 "y.tab.c"
    break;

  case 73: /* constant_as_operand: INT_NUM  */
#line 560 "parser.y"
                                                                {if(!arguments.stop_after_parsing){ (yyval.ast) = new IntegerExpressionAST((yyvsp[0].name)); /*free($1);*/}}
#line 2168 "y.tab.c"
    break;

  case 74: /* constant_as_operand: FLOAT_NUM  */
#line 561 "parser.y"
                                                                {if(!arguments.stop_after_parsing){ (yyval.ast) = new FloatExpressionAST((yyvsp[0].name));/*free($1);*/}}
#line 2174 "y.tab.c"
    break;

  case 75: /* constant_as_operand: STR_CONST  */
#line 562 "parser.y"
                                                                {if(!arguments.stop_after_parsing){ (yyval.ast) = new StringExpressionAST((yyvsp[0].name));/*free($1);*/}}
#line 2180 "y.tab.c"
    break;


#line 2184 "y.tab.c"

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

#line 572 "parser.y"

int yyerror (char *mesg)
{
	fprintf (stderr, "[parser.y] %s\n", mesg);
	my_exit(1);
}

int do_parse()
{
	return yyparse();
}
