#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cstdio>
#include <cerrno>
#include <cstring>
# include <argp.h>
using namespace std;
#include "utils.h"
#include "program.h"
#include "y.tab.h"

#define SHOW_TOKENS 't'
#define STOP_AFTER_SCAN 's'
#define STOP_AFTER_PARSE 'p'
#define SHOW_AST 'a'
#define SHOW_TAC 'c'
#define STOP_AFTER_AST 'A'
#define PRINT_TO_TERM 'd'

extern void my_exit(int);

// int yylex (void);
// extern int yyparse(void);


static int parse_opt (int key, char *arg, struct argp_state *state);

extern FILE *yyin, *yyout;
FILE* token_output_file = NULL;

struct arguments arguments;

int yylex (void);
int do_parse(void);

void print_help(string cmd)
{
		cout << "Usage: " << cmd <<" [OPTION...] [FILE]\nSclp - A language processor for C-like language\n\n      --sa-scan              Stop after scanning\n      --sa-parse             Stop after parsing\n      --sa-ast               Stop after constructing Abstract Syntax Tree\n                             (AST)\n      --sa-tac               Stop after constructing Three Address Code (TAC)\n      --sa-rtl               Stop after constructing Register Transfer Language\n                             (RTL) code\n      --show-tokens          Show the tokens in FILE.toks (or out.toks)\n      --show-ast             Show abstract syntax trees in FILE.ast (or\n                             out.ast)\n      --show-tac             Show the Three Address Code in FILE.tac (or\n                             out.tac)\n      --show-rtl             Show the Register Transfer Language code in\n                             FILE.rtl (or out.rtl)\n      --show-symtab          Show the symbol table after RTL construction (when\n                             offsets are allocated) in FILE.sym, (or out.sym)\n      --show-asm             Generate the assembly program in FILE.spim (or\n                             out.spim). This is the default action and is\n                             suppressed only if a valid `sa-...' option is\n                             given to stop the compilation after some earlier\n                             phase.\n      --show-json-ast        Show the Abstract Syntax Tree in JSON format\n      --show-json-tac        Show the Three Address Code in JSON format\n      --show-json-rtl        Show the Register Transfer Language code in JSON\n                             format\n      --read-json-ast        Use the input file (in JSON format) to generate\n                             the AST and skip all the phases from scanning to\n                             parsing\n      --read-json-tac        Use the input file (in JSON format) to generate\n                             the TAC and skip all the phases from scanning to\n                             TAC generation\n      --read-json-rtl        Use the input file (in JSON format) to generate\n                             the RTL code and skip all the phases from scanning\n                             to RTL generation\n  -d, --demo                 Demo version. Use stdout for the output instead of\n                             files\n      --gen-temp-symb-table  Populate Symbol Table For Temporaries\n  -e, --single-stmt-bb       Flag to construct single statement basic blocks\n  -?, --help                 Give this help list\n      --usage                Give a short usage message\n  -V, --version              Print program version\n\nReport bugs to <khushangsingla@cse.iitb.ac.in> and <hrishijd@cse.iitb.ac.in>"<<endl;
}

string get_input_file(vector<string> args)
{
	vector<string>::iterator iter = find_if(args.begin(), args.end(), [](string s){return s[0] != '-';});
	if(iter == args.end()){
		return "";
	}
	return *iter;
}

int main(int argc, char* argv[])
{

	struct argp_option options[] = {
  		{ "show-tokens", SHOW_TOKENS, 0, 0, "Show the tokens in FILE.toks (or out.toks)", 9 },
  		{ "show-ast", SHOW_AST, 0, 0, "Show the ast in FILE.ast (or out.ast)", 9 },
		{ "show-tac", SHOW_TAC, 0, 0, "Show the tac in FILE.tac (or out.tac)", 9 },
  		{ "sa-scan",  STOP_AFTER_SCAN, 0, 0, "Stop after lexical analysis", 0 },
  		{ "sa-parse",  STOP_AFTER_PARSE, 0, 0, "Stop after parsing", 0 },
		{ "sa-ast",  STOP_AFTER_AST, 0, 0, "Stop after constructing AST", 0 },
		{"print-to-term", PRINT_TO_TERM, 0, 0, "Printing to terminal", 0 },
		{ 0 }
		};

	struct argp argp = {options, parse_opt};

	argp_parse (&argp, argc, argv, 0, 0, 0);
	if( arguments.input_file == "" ){
		cerr << "No input file" << endl;
		my_exit(1);
	}

	yyin = fopen(arguments.input_file.c_str(), "r");

	if(yyin == NULL){
		cerr << argv[0] << ": " << arguments.input_file << ": " << strerror(errno) << endl;
	}

#ifdef DEBUG
	cerr << "[sclp.cpp] arguments.show_tokens = " << arguments.show_tokens<<endl;
	cerr << "[sclp.cpp] arguments.stop_after_scan = " << arguments.stop_after_scanning<<endl;
	cerr << "[sclp.cpp] arguments.input_file = " << arguments.input_file<<endl;
	cerr << "[sclp.cpp] arguments.show_ast = " << arguments.show_ast<<endl;
	
#endif

	if(arguments.show_tokens)
	{
		if(!arguments.print_to_term)
			token_output_file = fopen((arguments.input_file + ".toks").c_str(),"w");
		else
			token_output_file = stdout;
	}

	if(arguments.show_ast)
	{
		if(!arguments.print_to_term)
			arguments.ast_output_file = fopen((arguments.input_file + ".ast").c_str(),"w");
		else
			arguments.ast_output_file = stdout;
	}

	if(arguments.show_tac)
	{
		if(!arguments.print_to_term)
			arguments.tac_output_file = fopen((arguments.input_file + ".tac").c_str(),"w");
		else
			arguments.tac_output_file = stdout;
	}

	if(arguments.stop_after_scanning){
		while(true){
			int output = yylex();
			if(!output)	break;
			bool allowed = (output != NOT_IN_CURRENT_LEVEL) && (output != UNKNOWN_CHAR);
			if(!allowed){
				cerr << "Handle this\n";
				my_exit(1);
				break;
			}
		}
		my_exit(0);
	}
	
	// yyparse();
	
	do_parse();

	my_exit(0);
// 	if(argc == 1){
// 		cerr << "Usage: " << argv[0] << " [OPTION...] [FILE]\nTry `" << argv[0] << " --help' or `" << argv[0] << " --usage' for more information." << endl;
// 		return 1;
// 	}
// 
// 	const vector<string> args(argv+1, argv+argc);
// 
// 	if( find(args.begin(), args.end(), "--usage") != args.end() || find(args.begin(), args.end(), "--help") != args.end() ) {
// 		print_help( (string)argv[0] );
// 		return 0;
// 	}
// 
// 	if( find(args.begin(), args.end(), "--version") != args.end() || find(args.begin(), args.end(), "-V") != args.end() ) {
// 		cout << "scLp version: v0.0.0" << endl;
// 	}
// 
// 	string input_file = get_input_file(args);
// 
// 	if(input_file == ""){	
// 		cerr << "Usage: " << argv[0] << " [OPTION...] [FILE]\nTry `" << argv[0] << " --help' or `" << argv[0] << " --usage' for more information." << endl;
// 		return 1;
// 	}
// 
// 	yyin = fopen(input_file.c_str(), "r");
// 
// 	if(yyin == NULL){
// 		cerr << argv[0] << ": " << input_file << ": " << strerror(errno) << endl;
// 	}
// 	while(yylex());
	// yyparse();

}

static int parse_opt (int key, char *arg, struct argp_state *state)
{
	switch (key)
	{
		case SHOW_TOKENS: 
			arguments.show_tokens = true;	
			break;
		case SHOW_AST:
			arguments.show_ast = true;
			break;
		case SHOW_TAC:
			arguments.show_tac = true;
			break;
		case STOP_AFTER_SCAN: 
			arguments.stop_after_scanning = true;	
			break;
		case STOP_AFTER_PARSE:
			arguments.stop_after_parsing = true;
			break;
		case PRINT_TO_TERM:
			arguments.print_to_term = true;
			break;
		case 0:
			arguments.input_file = arg;
	}
	return 0;
}
