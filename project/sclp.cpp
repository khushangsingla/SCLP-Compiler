#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include "printing.h"
#include "y.tab.h"

enum option_passed {
	SHOW_TOKENS,
	STOP_AFTER_SCAN,
	STOP_AFTER_PARSE,
	SHOW_AST
};

using namespace std;

// int yylex (void);
// extern int yyparse(void);

extern FILE* yyin, yyout;
extern "C"
{
	// int yyparse(void);
	#include <argp.h>
	int yylex (void);
}

bool show_tokens = false;
bool stop_after_scan = false;

static int parse_options (int key, char* arg, struct argp_state* state)
{
	switch(key){
		case SHOW_TOKENS:
			show_tokens = true;
			break;
		case STOP_AFTER_SCAN:
			stop_after_scan = true;
			break;
		default:
			cerr << "Not Implented Yet! Cope.\n" << endl;
			break;
	}
	return 0;
}

// void print_help(string cmd)
// {
// 		cout << "Usage: " << cmd <<" [OPTION...] [FILE]
// Sclp - A language processor for C-like language
// 
//       --sa-scan              Stop after scanning
//       --sa-parse             Stop after parsing
//       --sa-ast               Stop after constructing Abstract Syntax Tree
//                              (AST)
//       --sa-tac               Stop after constructing Three Address Code (TAC)
//       --sa-rtl               Stop after constructing Register Transfer Language
//                              (RTL) code
//       --show-tokens          Show the tokens in FILE.toks (or out.toks)
//       --show-ast             Show abstract syntax trees in FILE.ast (or
//                              out.ast)
//       --show-tac             Show the Three Address Code in FILE.tac (or
//                              out.tac)
//       --show-rtl             Show the Register Transfer Language code in
//                              FILE.rtl (or out.rtl)
//       --show-symtab          Show the symbol table after RTL construction (when
//                              offsets are allocated) in FILE.sym, (or out.sym)
//       --show-asm             Generate the assembly program in FILE.spim (or
//                              out.spim). This is the default action and is
//                              suppressed only if a valid `sa-...' option is
//                              given to stop the compilation after some earlier
//                              phase.
//       --show-json-ast        Show the Abstract Syntax Tree in JSON format
//       --show-json-tac        Show the Three Address Code in JSON format
//       --show-json-rtl        Show the Register Transfer Language code in JSON
//                              format
//       --read-json-ast        Use the input file (in JSON format) to generate
//                              the AST and skip all the phases from scanning to
//                              parsing
//       --read-json-tac        Use the input file (in JSON format) to generate
//                              the TAC and skip all the phases from scanning to
//                              TAC generation
//       --read-json-rtl        Use the input file (in JSON format) to generate
//                              the RTL code and skip all the phases from scanning
//                              to RTL generation
//   -d, --demo                 Demo version. Use stdout for the output instead of
//                              files
//       --gen-temp-symb-table  Populate Symbol Table For Temporaries
//   -e, --single-stmt-bb       Flag to construct single statement basic blocks
//   -?, --help                 Give this help list
//       --usage                Give a short usage message
//   -V, --version              Print program version
// 
// Report bugs to <khushangsingla@cse.iitb.ac.in> and <hrishijd@cse.iitb.ac.in>"<<endl;
// }

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

	if(argc == 1){
		cerr << "Usage: " << argv[0] << " [OPTION...] [FILE]\nTry `" << argv[0] << " --help' or `" << argv[0] << " --usage' for more information." << endl;
		return 1;
	}
	
	struct argp_option options[] = {
		{"show-tokens", SHOW_TOKENS, 0, 0, "Show the tokens in FILE.toks (or out.toks)", 9}
	};
	struct argp argp = {options, parse_options};
	argp_parse(&argp, argc, argv, 0, 0, 0);

	const vector<string> args(argv+1, argv+argc);

	if( find(args.begin(), args.end(), "--usage") != args.end() || find(args.begin(), args.end(), "--help") != args.end() ) {
		// print_help( (string)argv[0] );
		return 0;
	}

	if( find(args.begin(), args.end(), "--version") != args.end() || find(args.begin(), args.end(), "-V") != args.end() ) {
		cout << "scLp version: v0.0.0" << endl;
	}

	string input_file = get_input_file(args);

	if(input_file == ""){	
		cerr << "Usage: " << argv[0] << " [OPTION...] [FILE]\nTry `" << argv[0] << " --help' or `" << argv[0] << " --usage' for more information." << endl;
		return 1;
	}

	yyin = fopen(input_file.c_str(), "r");

	if(yyin == NULL){
		cerr << argv[0] << ": " << input_file << ": " << strerror(errno) << endl;
	}
	while(yylex());
	// yyparse();

}
