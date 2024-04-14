#pragma once
#define SHIT_MAIN_ONLY

#include <vector>
#include "symbol_table.h"
#include "ast.h"
#include "utils.h"
#include "tac.h"

class ProcedureDefn 
{
	friend class Procedure;

	private:	
		vector<AST*> statements;
		vector<TACStatement*> tac;
		vector<RTLStatement*> rtl;
	
	public:
		SymbolTable *local_symbol_table;
		ProcedureDefn(SymbolTable*, vector<AST*>);
		int is_defn_valid(SymbolTable*, map<string, Procedure*>&);
		void print_ast();
		void gentac(TACOperand*);
		void print_tac();
		void genrtl();
		void print_rtl();
};

class Procedure 
{
	private:
		ProcedureDefn* defn;
	
	public:
		st_datatype ret_type;
		LabelTACOperand* ret_label;
		vector<Symbol*> *formal_param_list;
		string name;
		bool is_defined;
		Procedure(AST*, vector<Symbol*>*, ProcedureDefn*, st_datatype);
		Procedure(AST*, vector<Symbol*>*, st_datatype);
		Procedure(AST*, vector<Symbol*>*, SymbolTable*, vector<AST*>, st_datatype);
		int add_defn(ProcedureDefn*);
		int is_proc_valid(SymbolTable*, map<string, Procedure*>&);
		st_datatype get_return_type();
		int get_param_list_size();
		void print_ast();
		int match_declaration(Procedure* proc);
		int check_if_formal_param_list_match(vector<Symbol*>*);
		st_datatype get_arg_type(int);
		void gentac();
		void genrtl();
};
