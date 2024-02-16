#include "procedure.h"

ProcedureDefn::ProcedureDefn(SymbolTable* s, vector<AST*> v){
	local_symbol_table = s;
	statements = v;
}

Procedure::Procedure(AST* a, SymbolTable* st, ProcedureDefn* pd, st_datatype dt){
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = st;
	defn = pd;
	ret_type = dt;
	is_defined = true;
}

Procedure::Procedure(AST* a, SymbolTable* st, st_datatype dt){
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = st;
	is_defined = false;
	ret_type = dt;
	defn = NULL;
}

Procedure::Procedure(AST* a, SymbolTable* params, SymbolTable* vars, vector<AST*> stmts, st_datatype dt){
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = params;
	defn = new ProcedureDefn(vars, stmts);
	ret_type = dt;
	is_defined = true;
}

int Procedure::add_defn(ProcedureDefn* pd){
	if(is_defined) return -1;

	defn = pd;
	is_defined = true;
	return 0;
}

int Procedure::is_proc_valid(SymbolTable* gst, map<string, Procedure*>& fns){
	SymbolTable* unin = new SymbolTable();
	unin->add_symbols_from_table(formal_param_list);
	if(unin->add_symbols_from_table(defn->local_symbol_table) != 0) return -1;

	unin->add_global_symbols(gst);

	if(defn -> is_defn_valid(unin,fns) != 0){
		delete unin;
		return -1;
	}
	delete unin;
	return 0;
}

int ProcedureDefn::is_defn_valid(SymbolTable* vars, map<string, Procedure*>& fns)
{
	for(unsigned int i=0;i<statements.size();i++)
	{
		if(statements[i] -> is_valid(vars,fns) != 0)	return -1;
	}
	return 0;
}

st_datatype Procedure::get_return_type(){
	return ret_type;
}

int Procedure::get_param_list_size(){
	return formal_param_list->get_symbol_count();
}
