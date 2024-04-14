#pragma once

#include <vector>
#include <map>

#include "procedure.h"

using namespace std;

class Program 
{
	private:
		map<string, Procedure*> procedures;

	public:
		SymbolTable *global_symbol_table;
		// vector<string> order_of_keys_with__;
		// Program(SymbolTable*);
		// Program(SymbolTable*, Procedure*);
		Program(pair<SymbolTable*, vector<Procedure*>>*, vector<Procedure*>*);
		// Program(SymbolTable*, vector<Procedure*>);
		// int add_symbol_to_GST(/* TODO */);
		int add_procedure(Procedure*);
		int add_global_symbols(SymbolTable*);
		int main_func_check();
		void printast();
		void gentac();
		void genrtl();
		// void print_ast();
};
