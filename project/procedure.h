#pragma once
#define SHIT_MAIN_ONLY

#include <vector>
#include "symbol_table.h"
#include "ast.h"
#include "utils.h"

class ProcedureDefn 
{
	private:	
		vector<AST*> statements;
	
	public:
		SymbolTable *local_symbol_table;
		ProcedureDefn(SymbolTable*, vector<AST*>);
		int is_defn_valid(SymbolTable*, map<string, Procedure*>&);
		void print_ast();
};

class Procedure 
{
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
		st_datatype get_return_type();
		int get_param_list_size();
		void print_ast();
		int match_declaration(Procedure* proc);
};
