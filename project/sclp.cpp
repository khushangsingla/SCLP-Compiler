#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include "printing.h"

using namespace std;

// int yylex (void);

extern FILE* yyin, yyout;

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

	if(argc == 1){
		cerr << "Usage: " << argv[0] << " [OPTION...] [FILE]\nTry `" << argv[0] << " --help' or `" << argv[0] << " --usage' for more information." << endl;
		return 1;
	}

	const vector<string> args(argv+1, argv+argc);

	if( find(args.begin(), args.end(), "--usage") != args.end() || find(args.begin(), args.end(), "--help") != args.end() ) {
		print_help( (string)argv[0] );
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
	// while(true){
	// 	// yylex();
	// }

}
