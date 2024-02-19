#include "procedure.h"

ProcedureDefn::ProcedureDefn(SymbolTable* s, vector<AST*> v)
{
	local_symbol_table = s;
	statements = v;
}

Procedure::Procedure(AST* a, vector<Symbol*>* st, ProcedureDefn* pd, st_datatype dt)
{
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = st;
	defn = pd;
	ret_type = dt;
	is_defined = true;
}

Procedure::Procedure(AST* a, vector<Symbol*>* st, st_datatype dt)
{
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = st;
	is_defined = false;
	ret_type = dt;
	defn = NULL;
}

Procedure::Procedure(AST* a, vector<Symbol*>* params, SymbolTable* vars, vector<AST*> stmts, st_datatype dt)
{
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = params;
	defn = new ProcedureDefn(vars, stmts);
	ret_type = dt;
	is_defined = true;
}

int Procedure::add_defn(ProcedureDefn* pd)
{
	if(is_defined) return -1;

	defn = pd;
	is_defined = true;
	return 0;
}

int Procedure::is_proc_valid(SymbolTable* gst, map<string, Procedure*>& fns)
{
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

st_datatype Procedure::get_return_type()
{
	return ret_type;
}

int Procedure::get_param_list_size()
{
	return formal_param_list->size();
}

void Procedure::print_ast()
{
	ast_output("**PROCEDURE: ");
	ast_output(name.c_str());
	ast_output("\n");
	ast_output("\tReturn Type: ");
	ast_output(get_string_for_dtype(ret_type));
	ast_output("\n");
	ast_output("\tFormal Parameters:\n");
	for(int i=0; i<formal_param_list->size(); ++i){
		ast_output("\t\t" + formal_param_list->at(i)->name + "_ Type:" + get_string_for_dtype(formal_param_list->at(i)->type) + "\n");
	}
#ifndef SHIT_MAIN_ONLY
	assert(0);
#endif
	ast_output("**BEGIN: Abstract Syntax Tree ");
	assert(defn);
	defn->print_ast();
	ast_output("\n**END: Abstract Syntax Tree\n");
}

void ProcedureDefn::print_ast()
{
	for(unsigned int i=0;i<statements.size();i++)
	{
		statements[i] -> print("         ");
	}
}

int Procedure::match_declaration(Procedure* proc)
{
	if(ret_type != proc->ret_type)	return -1;
	if(check_if_formal_param_list_match(proc->formal_param_list) != 0)	return -1;

	return 0;
}

int Procedure::check_if_formal_param_list_match(vector<Symbol*> *parms){
	if(formal_param_list->size() != parms->size()) return -1;
	for(int i=0; i<formal_param_list->size(); ++i){
		if(formal_param_list->at(i)->type != parms->at(i)->type) return-1;	
	}
	return 0;
}
