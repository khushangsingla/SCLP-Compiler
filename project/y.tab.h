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

#line 174 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
