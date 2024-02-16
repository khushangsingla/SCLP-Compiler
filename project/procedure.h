#pragma once

#include <vector>
#include "symbol_table.h"
#include "ast.h"

class ProcedureDefn {
	private:	
		vector<AST*> statements;
	
	public:
		SymbolTable *local_symbol_table;
		ProcedureDefn(SymbolTable*, vector<AST*>);
		int is_defn_valid(SymbolTable*, map<string, Procedure*>&);
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
		int is_proc_valid(SymbolTable*, map<string, Procedure*>&);
};
