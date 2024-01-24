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
E : NUM
  {
  printf("NUL FOUND");
  }
%%
int yyerror (char *mesg)
{
	fprintf (stderr, "%s\n", mesg);
	exit (1);
}

