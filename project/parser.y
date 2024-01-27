%{
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

%left '+' '-'
%left '*' '/'

%%

tok1 : tok tok
tok : WHILE				| 
       ELSE			| 
       INTEGER				| 
       FLOAT				| 
       BOOL					| 
       STRING				| 
       VOID					| 
       WRITE				| 
       READ					| 
       NAME					| 
       RETURN				| 
       ASSIGN_OP			| 
       GREATER_THAN			| 
       LESS_THAN			| 
       GREATER_THAN_EQUAL	| 
       LESS_THAN_EQUAL		| 
       NOT_EQUAL			| 
       EQUAL				| 
       PLUS					| 
       MINUS				| 
       MULT					| 
       ADDRESSOF			| 
       LEFT_CURLY_BRACKET	| 
       RIGHT_CURLY_BRACKET	| 
       LEFT_ROUND_BRACKET	| 
       RIGHT_ROUND_BRACKET	| 
       LEFT_SQUARE_BRACKET	| 
       RIGHT_SQUARE_BRACKET	| 
       SEMICOLON			| 
       COMMA				| 
       OP_FOR_TERNARY_EXPR	| 
       FLOAT_NUM			| 
       INT_NUM				| 
       STR_CONST			| 
       DIV					| 
       IF					| 
       NOT_IN_CURRENT_LEVEL	|
	   IGNORE
	   ;



%%
int yyerror (char *mesg)
{
	fprintf (stderr, "[parser.y]%s\n", mesg);
	// exit (1);
}

