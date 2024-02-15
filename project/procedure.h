#pragma once

#include <vector>
#include "symbol_table.h"
#include "ast.h"

class ProcedureDefn {
	private:	
		SymbolTable *local_symbol_table;
		vector<AST*> statements;
	
	public:
		ProcedureDefn(SymbolTable*, vector<AST*>);
};

class Procedure {
	private:
		SymbolTable *formal_param_list;
		ProcedureDefn* defn;
		st_datatype ret_type;
	
	public:
		string name;
		bool is_defined;
		Procedure(AST*, SymbolTable*, ProcedureDefn*, st_datatype);
		Procedure(AST*, SymbolTable*, st_datatype);
		Procedure(AST*, SymbolTable*, SymbolTable*, vector<AST*>, st_datatype);
		int add_defn(ProcedureDefn*);
};
