%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "ast.h"
extern void my_exit(int);
extern struct arguments arguments;

int do_parse();
int yyerror();
// int yydebug = 1;
%}

%union{
	char* name;
	AST* ast;
	vector<AST*>* vec_of_ast;
	SymbolTable* symtab;
	datatype dtype;
}

%token WHILE				
%token ELSE			
%token INTEGER				/*		int ( L1 )*/
%token FLOAT				/*		float(L1)*/
%token BOOL					/*		bool(L1)*/
%token STRING				/*		string(L1)*/
%token VOID					/*		void(L1)*/
%token WRITE				/*		print(L1)*/
%token READ					/*		read(L1)*/
%token <name> NAME					/*		.*(L1)*/
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
%token <name> FLOAT_NUM			/*		L1*/
%token <name> INT_NUM				/*		L1*/
%token <name> STR_CONST			/*		L1*/
%token DIV					/*			/ (L1)*/
%token IF
%token NOT_IN_CURRENT_LEVEL
%token IGNORE
%token AND
%token OR
%token NOT
%token UNKNOWN_CHAR

%right '?' ':'
%left OR
%left AND
%right NOT
%nonassoc LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL EQUAL NOT_EQUAL
%left PLUS MINUS
%left MULT DIV
%right UMINUS


%type<> program
%type<symtab> global_decl_statement_list
%type<symtab> var_decl_stmt
%type<vec_of_ast> var_decl_item_list
%type<ast> var_decl_item
%type<dtype> named_type
%type<dtype> param_type
%type<> func_decl
%type<> func_decl_defn
%type<> funcdecl_param_list
%type<> funcdecl_param
%type<> func_defn
%type<symtab> optional_var_decl_stmt_list
%type<symtab> var_decl_stmt_list
%type<vec_of_ast> statement_list
%type<ast> statement
%type<ast> print_statement
%type<ast> read_statement
%type<ast> assignment_statement
%type<ast> expression
%type<ast> relative_expression
%type<ast> variable_as_operand
%type<ast> constant_as_operand

%%

program 
	: global_decl_statement_list func_decl_defn {
													if(!arguments.stop_after_parsing){
													}
												}
	| func_decl_defn {
													if(!arguments.stop_after_parsing){
													}
												}
	| global_decl_statement_list func_decl func_decl_defn {
													if(!arguments.stop_after_parsing){
													}
												}
	| func_decl global_decl_statement_list func_decl_defn {
													if(!arguments.stop_after_parsing){
													}
												}
	| global_decl_statement_list func_decl global_decl_statement_list func_decl_defn {
													if(!arguments.stop_after_parsing){
													}
												}
	| func_decl func_decl_defn {
													if(!arguments.stop_after_parsing){
													}
												}
;

global_decl_statement_list
	: global_decl_statement_list var_decl_stmt {
													if(!arguments.stop_after_parsing){
														$1->add_symbols_from_table($2);
														$$ = $1;
														delete $2;
													}
												}
	| var_decl_stmt {
													if(!arguments.stop_after_parsing){
														$$ = $1;
													}
												}
;

var_decl_stmt
	: named_type var_decl_item_list SEMICOLON {
													if(!arguments.stop_after_parsing){
														$$ = new SymbolTable($1, $2,true);
														delete $2;
													}
												}
;

var_decl_item_list
	: var_decl_item_list COMMA var_decl_item {
													if(!arguments.stop_after_parsing){
														$$->push_back($3);
													}
												}
	| var_decl_item {
													if(!arguments.stop_after_parsing){
														$$ = new vector<AST*> (1, $1);
													}
												}
;

var_decl_item
	: variable_as_operand {
													if(!arguments.stop_after_parsing){
														$$ = $1;
													}
												}
;

named_type
	: INTEGER {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_INTEGER;
													}
												}
	| FLOAT {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_FLOAT;
													}
												}
	| VOID {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_VOID;
													}
												}
	| STRING {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_STRING;
													}
												}
	| BOOL {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_BOOL;
													}
												}
;

param_type
	: INTEGER {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_INTEGER; 	
													}
												}
	| FLOAT {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_FLOAT;
													}
												}
	| STRING {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_STRING;
													}
												}
	| BOOL {
													if(!arguments.stop_after_parsing){
														$$ = DTYPE_BOOL;
													}
												}
;

func_decl
	: named_type variable_as_operand LEFT_ROUND_BRACKET funcdecl_param_list RIGHT_ROUND_BRACKET SEMICOLON {
													if(!arguments.stop_after_parsing){
													}
												}
	| named_type variable_as_operand LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET SEMICOLON {
													if(!arguments.stop_after_parsing){
													}
												}

func_decl_defn
	: named_type variable_as_operand LEFT_ROUND_BRACKET funcdecl_param_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET func_defn RIGHT_CURLY_BRACKET {
													if(!arguments.stop_after_parsing){
													}
												}
	| named_type variable_as_operand LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET func_defn RIGHT_CURLY_BRACKET {
													if(!arguments.stop_after_parsing){
													}
												}
;

funcdecl_param_list
	: funcdecl_param_list COMMA funcdecl_param {
													if(!arguments.stop_after_parsing){
													}
												}
	| funcdecl_param {
													if(!arguments.stop_after_parsing){
													}
												}
;

funcdecl_param
	: param_type variable_as_operand {
													if(!arguments.stop_after_parsing){
													}
												}
;

func_defn
	: optional_var_decl_stmt_list statement_list {
													if(!arguments.stop_after_parsing){
													}
												}
;

optional_var_decl_stmt_list
	: %empty {
													if(!arguments.stop_after_parsing){
														$$ = new SymbolTable();
													}
												}
	| var_decl_stmt_list {
													if(!arguments.stop_after_parsing){
														$$ = $1;
													}
												}
;

var_decl_stmt_list
	: var_decl_stmt {
													if(!arguments.stop_after_parsing){
														$$ = $1;														
													}
												}
	| var_decl_stmt_list var_decl_stmt {
													if(!arguments.stop_after_parsing){
														$1->add_symbols_from_table($2);
														$$ = $1;
														delete $2;
													}
												}
;

statement_list
	: statement_list statement {
													if(!arguments.stop_after_parsing){
														$1->push_back($2);
														$$ = $1;
													}
												}
	| %empty {
													if(!arguments.stop_after_parsing){
														$$ = new vector<AST*>;
													}
												}
;

statement
	: assignment_statement {
													if(!arguments.stop_after_parsing){
														$$ = $1;
													}
												}
	| print_statement {
													if(!arguments.stop_after_parsing){
														$$ = $1;
													}
												}
	| read_statement {
													if(!arguments.stop_after_parsing){
														$$ = $1;
													}
												}
;

print_statement
	: WRITE expression SEMICOLON {
													if(!arguments.stop_after_parsing){
														$$ = new PrintStatementAST($2);
													}
												}
;

read_statement
	: READ variable_as_operand SEMICOLON {
													if(!arguments.stop_after_parsing){
														$$ = new ReadStatementAST($2);
													}
												}
;

assignment_statement
	: variable_as_operand ASSIGN_OP expression SEMICOLON	{
												if (!arguments.stop_after_parsing){
													$$ = new AssignmentStatementAST($1,$3);
												}
											}
;

expression
	: expression PLUS expression		{
											if (!arguments.stop_after_parsing){
												$$ = new PlusExpressionAST($1,$3);
											}
										}
	| expression MINUS expression		{
											if (!arguments.stop_after_parsing){
												$$ = new MinusExpressionAST($1,$3);
											}
										}
	| expression MULT expression		{
											if (!arguments.stop_after_parsing){
												$$ = new MultiplicationExpressionAST($1,$3);
											}
										}
	| expression DIV expression			{
											if (!arguments.stop_after_parsing){
												$$ = new DivisionExpressionAST($1,$3);
											}
										}
	| MINUS expression	%prec UMINUS	{
											if (!arguments.stop_after_parsing){
												$$ = new UMinusExpressionAST($2);
											}
										}
	| LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET	{if(!arguments.stop_after_parsing){ $$ = $2; }}
	| expression '?' expression ':' expression {
													if (!arguments.stop_after_parsing){
														$$ = new ConditionalExpressionAST($1,$3,$5);
													}
												}
	| expression AND expression			{
											if (!arguments.stop_after_parsing){
												$$ = new BooleanExpressionAST($1,$3,BOOL_AND);
											}
										}
	| expression OR expression			{
											if (!arguments.stop_after_parsing){
												$$ = new BooleanExpressionAST($1,$3,BOOL_OR);
											}
										}
	| NOT expression
	| relative_expression				{if(!arguments.stop_after_parsing){ $$ = $1; }}
	| variable_as_operand				{if(!arguments.stop_after_parsing){ $$ = $1; }}
	| constant_as_operand				{if(!arguments.stop_after_parsing){ $$ = $1; }}
;

relative_expression
	: expression LESS_THAN expression {
													if(!arguments.stop_after_parsing){
														$$ = new RelationalExpressionAST($1,$3,RELOP_LESS_THAN);
													}
												}
	| expression LESS_THAN_EQUAL expression {
													if(!arguments.stop_after_parsing){
														$$ = new RelationalExpressionAST($1,$3,RELOP_LESS_THAN_EQUAL);
													}
												}
	| expression GREATER_THAN expression {
													if(!arguments.stop_after_parsing){
														$$ = new RelationalExpressionAST($1,$3,RELOP_GREATER_THAN);
													}
												}
	| expression GREATER_THAN_EQUAL expression {
													if(!arguments.stop_after_parsing){
														$$ = new RelationalExpressionAST($1,$3,RELOP_GREATER_THAN_EQUAL);
													}
												}
	| expression NOT_EQUAL expression {
													if(!arguments.stop_after_parsing){
														$$ = new RelationalExpressionAST($1,$3,RELOP_NOT_EQUAL);
													}
												}
	| expression EQUAL expression {
													if(!arguments.stop_after_parsing){
														$$ = new RelationalExpressionAST($1,$3,RELOP_EQUAL);
													}
												}
;

variable_as_operand
	: NAME							{if(!arguments.stop_after_parsing){ $$ = new NameExpressionAST($1);free($1);}}
;

constant_as_operand
	: INT_NUM						{if(!arguments.stop_after_parsing){ $$ = new IntegerExpressionAST($1); free($1);}}
	| FLOAT_NUM						{if(!arguments.stop_after_parsing){ $$ = new FloatExpressionAST($1);free($1);}}
	| STR_CONST						{if(!arguments.stop_after_parsing){ $$ = new StringExpressionAST($1);free($1);}}
;

error_thing
	: NOT_IN_CURRENT_LEVEL
	| UNKNOWN_CHAR
	{yyerror("NOT IN CURRENT LEVEL");}
;


%%
int yyerror (char *mesg)
{
	fprintf (stderr, "[parser.y] %s\n", mesg);
	my_exit(1);
}

int do_parse()
{
	return yyparse();
}
