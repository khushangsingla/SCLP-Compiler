%{
#include <stdio.h>
#include <stdlib.h>
%}
%token VOID
%token MAIN
%token BRACE_OPEN 
%token BRACE_CLOSE
%token PRINT
%token READ
%token IF
%token ELSE 
%token IDENTIFIER
%token DTYPE_BOOL
%token DTYPE_FLOAT
%token DTYPE_STRING
%token DTYPE_INT
%token OPERATOR
%token NUM
%token WHILE
%token DO
%left '+' '-'
%left '*' '/'	
%%
PROGRAM : tok
  {
	printf("[parser.y] NUL FOUND\n");
  }
tok : tok tok | 
	VOID |
	MAIN |
	BRACE_OPEN  |
	BRACE_CLOSE |
	PRINT |
	READ |
	IF |
	ELSE  |
	IDENTIFIER |
	DTYPE_BOOL |
	DTYPE_FLOAT |
	DTYPE_STRING |
	DTYPE_INT |
	OPERATOR |
	NUM |
	WHILE |
	DO |


%%
int yyerror (char *mesg)
{
	fprintf (stderr, "[parser.y]%s\n", mesg);
	// exit (1);
}

