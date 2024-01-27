%{
int yydebug = 1;
#include <stdio.h>
#include <stdlib.h>
%}


%token WHILE				
%token ELSE			
%token INTEGER				/*		int ( L1 )*/
%token FLOAT				/*		float(L1)*/
%token BOOL					/*		bool(L1)*/
%token STRING				/*		string(L1)*/
%token VOID					/*		void(L1)*/
%token WRITE				/*		print(L1)*/
%token READ					/*		read(L1)*/
%token NAME					/*		.*(L1)*/
%token RETURN				/*		*/
%token ASSIGN_OP			/*	= (L1)*/
%token GREATER_THAN			/*		*/
%token LESS_THAN			/*		*/
%token GREATER_THAN_EQUAL	/*		*/
%token LESS_THAN_EQUAL		/*		*/
%token NOT_EQUAL			/*		*/
%token EQUAL				/*		*/
%token PLUS					/*		+ (L1)*/
%token MINUS				/*		- (L1)*/
%token MULT					/*		* (L1)*/
%token ADDRESSOF			/*		*/
%token LEFT_CURLY_BRACKET	/*		{ L1*/
%token RIGHT_CURLY_BRACKET	/*		} L1*/
%token LEFT_ROUND_BRACKET	/*		( L1*/
%token RIGHT_ROUND_BRACKET	/*		) L1*/
%token LEFT_SQUARE_BRACKET	/*		[ L1*/
%token RIGHT_SQUARE_BRACKET	/*	] L1*/
%token SEMICOLON			/*		; L1*/
%token COMMA				/*		, L1*/
%token OP_FOR_TERNARY_EXPR	/*		*/
%token FLOAT_NUM			/*		L1*/
%token INT_NUM				/*		L1*/
%token STR_CONST			/*		L1*/
%token DIV					/*			/ (L1)*/
%token IF
%token NOT_IN_CURRENT_LEVEL
%token IGNORE
%token AND
%token OR
%token NOT

%left PLUS MINUS
%left MULT DIV
%right UMINUS

%%

program 
	: global_decl_statement_list func_decl_defn
	| func_decl_defn
;

global_decl_statement_list
	: global_decl_statement_list var_decl_stmt
	| var_decl_stmt
;

var_decl_stmt
	: named_type var_decl_item_list ';'
;

var_decl_item_list
	: var_decl_item_list ',' var_decl_item
	| var_decl_item
;

var_decl_item
	: NAME
;

named_type
	: INTEGER
	| FLOAT
	| VOID
	| STRING
	| BOOL
;

func_decl_defn
	: named_type NAME '(' funcdecl_param_list ')' '{' func_defn '}'
	| named_type NAME '(' ')' '{' func_defn '}'
;

funcdecl_param_list
	: funcdecl_param_list ',' funcdecl_param
	| funcdecl_param
;

funcdecl_param
	: named_type NAME
;

func_defn
	: optional_var_decl_stmt_list statement_list
;

optional_var_decl_stmt_list
	: %empty
	| var_decl_stmt_list
;

var_decl_stmt_list
	: var_decl_stmt
	| var_decl_stmt_list var_decl_stmt
;

statement_list
	: statement_list statement
	| %empty
;

statement
	: assignment_statement
	| print_statement
	| read_statement
;

print_statement
	: WRITE expression ';'
;

read_statement
	: READ NAME ';'
;

assignment_statement
	: NAME ASSIGN_OP expression ';'
;

expression
	: expression PLUS expression
	| expression MINUS expression
	| expression MULT expression
	| expression DIV expression
	| MINUS expression	%prec UMINUS 
	| '(' expression ')'
	| variable_as_operand
	| constant_as_operand
;

variable_as_operand
	: NAME
;

constant_as_operand
	: INT_NUM
	| FLOAT_NUM
	| STR_CONST
;

error_thing
	: NOT_IN_CURRENT_LEVEL {yyerror("NOT IN CURRENT LEVEL");}
;


%%
int yyerror (char *mesg)
{
	fprintf (stderr, "[parser.y]%s\n", mesg);
	exit (1);
}
