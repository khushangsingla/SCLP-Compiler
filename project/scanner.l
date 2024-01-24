%{
#include <stdio.h>
#include "printing.h"
#include "y.tab.h"
%}

digits [0-9]
alphabets [a-zA-Z_]
alphanumeric [0-9a-zA-Z_]
operator [-+*/]

%%
	/* Semantics Related */
void		{
				my_print("", "[scanner.l] void found!\n");
				return VOID;
			}

main		{
				my_print("", "[scanner.l] main found!\n");
				return MAIN;
			}

{			{
				my_print("", "[scanner.l] opening curly brace found!\n");
				return BRACE_OPEN;
			}

}			{
				my_print("", "[scanner.l] closing curly brace found!\n");
				return BRACE_CLOSE;
			}

print		{
				my_print("", "[scanner.l] print statement found!\n");
				return PRINT;
			}

read		{
				my_print("", "[scanner.l] read statement found!\n");
				return READ;
			}

if			{
				my_print("", "[scanner.l] if statement found!\n");
				return IF;
			}

else		{
				my_print("","[scanner.l] else statement found!\n)");
				return ELSE;
			}

do		{
				my_print("","[scanner.l] do statement found!\n)");
				return DO;
			}

while		{
				my_print("","[scanner.l] while statement found!\n)");
				return WHILE;
			}

	/* Expression Related */
{digits}+		{
				my_print("", "[scanner.l] number found!\n");
				yylval = atoi(yytext);
				return NUM;
			}

{operator}	{
				my_print("", "[scanner.l] operator found!\n");
				yylval = yytext[0];
				return OPERATOR;
			}

	/* Datatypes */
int			{
				my_print("", "[scanner.l] int datatype found!\n");
				return DTYPE_INT;
			}

string		{
				my_print("", "[scanner.l] string datatype found!\n");
				return DTYPE_STRING;
			}

float		{
				my_print("","[scanner.l] float identifier found!\n)");
				return DTYPE_FLOAT;
			}

bool		{
				my_print("","[scanner.l] bool identifier found!\n)");
				return DTYPE_BOOL;
			}
	
	/* Variables */
{alphabets}{alphanumeric}*		{
									my_print("CORRECT THIS!!\t", "[scanner.l] variable identifier found!\n");
									/* CORRECT THIS */
									yylval = yytext[0];
									return IDENTIFIER;
								}

.		{
			my_print_vars("","[scanner.l] unknown character: %c(%d)\n",0,2,yytext[0],yytext[0]);
			// return ;
		}
%%
