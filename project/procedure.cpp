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
