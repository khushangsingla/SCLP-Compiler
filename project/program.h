#pragma once

#include <vector>
#include <map>

#include "procedure.h"

using namespace std;

class Program {
	private:
		SymbolTable *global_symbol_table;
		map<string, Procedure*> procedures;

	public:
		Program(SymbolTable*);
		Program(SymbolTable*, Procedure*);
		// Program(SymbolTable*, vector<Procedure*>);
		// int add_symbol_to_GST(/* TODO */);
		int add_procedure(Procedure*);
		int add_global_symbols(SymbolTable*);
};
