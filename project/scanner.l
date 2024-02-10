%option noyywrap
%{
#include <stdio.h>
#include "utils.h"
#include "y.tab.h"

extern void my_exit(int);

%}

digits [0-9]
alphabets [a-zA-Z_]
alphanumeric [0-9a-zA-Z_]
operator [-+*/]
ternary_ops [:?]


%%
while		{
				my_print("", "[scanner.l] while found!\n");
				return NOT_IN_CURRENT_LEVEL;
				scanner_output("WHILE",yytext,yylineno);
				return WHILE;
			}

else		{
				my_print("", "[scanner.l] else found!\n");
				return NOT_IN_CURRENT_LEVEL;
				scanner_output("ELSE",yytext,yylineno);
				return ELSE;
			}

if			{
				my_print("", "[scanner.l] if found!\n");
				return NOT_IN_CURRENT_LEVEL;
				scanner_output("IF",yytext,yylineno);
				return IF;
			}

int			{
				my_print("", "[scanner.l] int found!\n");
				scanner_output("INTEGER",yytext,yylineno);
				return INTEGER;
			}

float		{
				my_print("", "[scanner.l] float found!\n");
				scanner_output("FLOAT",yytext,yylineno);
				return FLOAT;
			}

bool		{
				my_print("", "[scanner.l] bool found!\n");
				scanner_output("BOOL",yytext,yylineno);
				return BOOL;
			}

string		{
				my_print("", "[scanner.l] string found!\n");
				scanner_output("STRING",yytext,yylineno);
				return STRING;
			}

void		{
				my_print("", "[scanner.l] void found!\n");
				scanner_output("VOID",yytext,yylineno);
				return VOID;
			}

print		{
				my_print("", "[scanner.l] print found!\n");
				scanner_output("WRITE",yytext,yylineno);
				return WRITE;
			}

read		{
				my_print("", "[scanner.l] read found!\n");
				scanner_output("READ",yytext,yylineno);
				return READ;
			}

return {
				my_print("", "[scanner.l] return found!\n");
				return NOT_IN_CURRENT_LEVEL;
				scanner_output("RETURN",yytext,yylineno);
				return RETURN;
			}

=			{
				my_print("", "[scanner.l] = found!\n");
				scanner_output("ASSIGN_OP",yytext,yylineno);
				return ASSIGN_OP;
			}

>			{
				my_print("", "[scanner.l] greater_than found!\n");
				scanner_output("GREATER_THAN",yytext,yylineno);
				return GREATER_THAN;
			}

\<			{
				my_print("", "[scanner.l] less_than found!\n");
				scanner_output("LESS_THAN",yytext,yylineno);
				return LESS_THAN;
			}

>=			{
				my_print("", "[scanner.l] >= found!\n");
				scanner_output("GREATER_THAN_EQUAL",yytext,yylineno);
				return GREATER_THAN_EQUAL;
			}

\<=			{
				my_print("", "[scanner.l] <= found!\n");
				scanner_output("LESS_THAN_EQUAL",yytext,yylineno);
				return LESS_THAN_EQUAL;
			}

!=			{
				my_print("", "[scanner.l] != found!\n");
				scanner_output("NOT_EQUAL",yytext,yylineno);
				return NOT_EQUAL;
			}

==			{
				my_print("", "[scanner.l] == found!\n");
				scanner_output("EQUAL",yytext,yylineno);
				return EQUAL;
			}

\+			{
				my_print("", "[scanner.l] add found!\n");
				scanner_output("PLUS",yytext,yylineno);
				return PLUS;
			}

-			{
				my_print("", "[scanner.l] minus found!\n");
				scanner_output("MINUS",yytext,yylineno);
				return MINUS;
			}

\*			{
				my_print("", "[scanner.l] mult found!\n");
				scanner_output("MULT",yytext,yylineno);
				return MULT;
			}

\/			{
				my_print("", "[scanner.l] div found!\n");
				scanner_output("DIV",yytext,yylineno);
				return DIV;
			}

&			{
				my_print("", "[scanner.l] & found!\n");
				return NOT_IN_CURRENT_LEVEL;
				scanner_output("ADDRESSOF",yytext,yylineno);
				return ADDRESSOF;
			}

\{			{
				my_print("", "[scanner.l] { found!\n");
				scanner_output("LEFT_CURLY_BRACKET",yytext,yylineno);
				return LEFT_CURLY_BRACKET;
			}

\}			{
				my_print("", "[scanner.l] } found!\n");
				scanner_output("RIGHT_CURLY_BRACKET",yytext,yylineno);
				return RIGHT_CURLY_BRACKET;
			}

\(			{
				my_print("", "[scanner.l] ( found!\n");
				scanner_output("LEFT_ROUND_BRACKET",yytext,yylineno);
				return LEFT_ROUND_BRACKET;
			}

\)			{
				my_print("", "[scanner.l] ) found!\n");
				scanner_output("RIGHT_ROUND_BRACKET",yytext,yylineno);
				return RIGHT_ROUND_BRACKET;
			}

\[			{
				my_print("", "[scanner.l] [ found!\n");
				scanner_output("LEFT_SQUARE_BRACKET",yytext,yylineno);
				return LEFT_SQUARE_BRACKET;
			}

]			{
				my_print("", "[scanner.l] ] found!\n");
				scanner_output("RIGHT_SQUARE_BRACKET",yytext,yylineno);
				return RIGHT_SQUARE_BRACKET;
			}

;			{
				my_print("", "[scanner.l] ; found!\n");
				scanner_output("SEMICOLON",yytext,yylineno);
				return SEMICOLON;
			}

,			{
				my_print("", "[scanner.l] , found!\n");
				scanner_output("COMMA",yytext,yylineno);
				return COMMA;
			}

&&			{
				my_print("","[scanner.l] && found!\n");
				scanner_output("AND",yytext,yylineno);
				return AND;
			}

\|\|			{
				my_print("","[scanner.l] || found!\n");
				scanner_output("OR",yytext,yylineno);
				return OR;
			}

!			{
				my_print("","[scanner.l] ! found!\n");
				scanner_output("NOT",yytext,yylineno);
				return NOT;
			}

{ternary_ops}	{
				my_print("", "[scanner.l] ?: found!\n");
				scanner_output("OP_FOR_TERNARY_EXPR",yytext,yylineno);
				return yytext[0];
			}

\.			{
				my_print("", "[scanner.l] . found!\n");
				return NOT_IN_CURRENT_LEVEL;
			}

{digits}*\.{digits}*	{
				my_print("", "[scanner.l] float_num found!\n");
				scanner_output("FLOAT_NUM",yytext,yylineno);
				return FLOAT_NUM;
			}

{digits}+	{
				my_print("", "[scanner.l] integer found!\n");
				scanner_output("INT_NUM",yytext,yylineno);
				return INT_NUM;
			}

\"[^\"]*\"	{
				my_print("", "[scanner.l] string found!\n");
				scanner_output("STR_CONST",yytext,yylineno);
				return STR_CONST;
			}

{alphabets}{alphanumeric}*	{
				my_print("", "[scanner.l] variable found!\n");
				scanner_output("NAME",yytext,yylineno);
				return NAME;
			}

\/\/.*		{
				my_print("","[scanner.l] comment found!\n");
			}

[\t ]+		{
				my_print("","[scanner.l] whitespace found\n");
			}

\n			{
				my_print("","[scanner.l] newline found\n");
				yylineno++;
			}

.			{
				my_print_vars("","[scanner.l] Unknown char found: %c(%d)\n",0,2,yytext[0],yytext[0]);
				my_exit(1);
			}

%%
