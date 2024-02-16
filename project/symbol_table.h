#pragma once

#include <map>
#include <vector>
#include <string>
class AST;
// #include "utils.h"

void my_exit(int exit_code);
using namespace std;

enum st_datatype {
	DTYPE_UNKNOWN,
	DTYPE_INTEGER,
	DTYPE_FLOAT,
	DTYPE_STRING,
	DTYPE_BOOL,
	DTYPE_VOID
};

class Symbol {
	private:
		bool is_ptr;

	public:
		st_datatype type;
		string name;
		Symbol(AST*, st_datatype, bool is_ptr = false);
		Symbol(string, st_datatype, bool is_ptr = false);
		string get_name();
		st_datatype get_type();
};

class SymbolTable {
	private:
		map<string, Symbol*> symbols;
	
	public:
		SymbolTable();
		SymbolTable(st_datatype, vector<AST*>*,bool to_delete = false);	// for int a, b, c;
		int add_symbol(Symbol*);
		int add_symbols_from_table(SymbolTable*);
		int add_global_symbols(SymbolTable*);
		int is_variable_present(string);
		st_datatype get_datatype(string);
		int get_symbol_count();
};

string get_string_for_dtype(st_datatype);
