#pragma once

#include <vector>

#include "symbol_table.h"
#include "procedure.h"

using namespace std;

class Program {
	private:
		SymbolTable *global_symbol_table;
		vector<Procedure*> procedures;

	public:
		int add_symbol_to_GST(/* TODO */);
		int add_procedure(Procedure*);
};
