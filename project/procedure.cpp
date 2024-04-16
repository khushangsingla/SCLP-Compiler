#include "procedure.h"

extern bool is_rtl_printing_rn;
extern string function_being_checked_for_ast_rn;
extern bool return_statement_present_in_function_being_checked_for_ast_rn;
extern Procedure* current_procedure_rn;

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
	ret_label = NULL;
	stemp_offsets.push_back(0);
}

Procedure::Procedure(AST* a, vector<Symbol*>* st, st_datatype dt)
{
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = st;
	is_defined = false;
	ret_type = dt;
	defn = NULL;
	ret_label = NULL;
	stemp_offsets.push_back(0);
}

Procedure::Procedure(AST* a, vector<Symbol*>* params, SymbolTable* vars, vector<AST*> stmts, st_datatype dt)
{
	name = ((NameExpressionAST*)a)->name;
	// delete a;
	formal_param_list = params;
	defn = new ProcedureDefn(vars, stmts);
	ret_type = dt;
	is_defined = true;
	ret_label = NULL;
	stemp_offsets.push_back(0);
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
	function_being_checked_for_ast_rn = name;
	return_statement_present_in_function_being_checked_for_ast_rn = false;
	SymbolTable* unin = new SymbolTable();
	unin->add_symbols_from_table(formal_param_list);
	if(unin->add_symbols_from_table(defn->local_symbol_table) != 0) return -1;

	unin->add_global_symbols(gst);

	if(defn -> is_defn_valid(unin,fns) != 0){
		delete unin;
		return -1;
	}

	if(!return_statement_present_in_function_being_checked_for_ast_rn){
		if(ret_type != DTYPE_VOID){
			delete unin;
			return -1;
		}
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
	if(strcmp(name.c_str(), "main") != 0)
		ast_output("_");
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

int Procedure::check_if_formal_param_list_match(vector<Symbol*> *parms)
{
	if(formal_param_list->size() != parms->size()) return -1;
	for(int i=0; i<formal_param_list->size(); ++i){
		if(formal_param_list->at(i)->type != parms->at(i)->type) return-1;	
	}
	return 0;
}

void Procedure::gentac()
{
	ret_stemp = NULL;
	current_procedure_rn = this;
	if(defn){
		if(ret_type != DTYPE_VOID){
			ret_stemp = new STemporaryTACOperand(ret_type);
		}
		defn -> gentac(ret_stemp);
		if(defn->tac.size()){
			tac_output("**PROCEDURE: " + name, false);	
			if(strcmp(name.c_str(), "main") != 0)
				tac_output("_", false);
			tac_output("\n", false);
			tac_output("**BEGIN: Three Address Code Statements\n", false);
			defn->print_tac();
			tac_output("**END: Three Address Code Statements\n", false);
		}
	}
}

void Procedure::genasm()
{
		int total_offset = defn->local_symbol_table->current_offset + stemp_offsets.back() + 8;
		asm_output("sw $ra, 0($sp)\n");
		asm_output("sw $fp, -4($sp)\n");
		asm_output("sub $fp, $sp, 4\n");
		asm_output("sub $sp, $sp, " + to_string(total_offset) + "\n");
		defn->genasm();
		asm_output("epilogue_",false);
		asm_output(name,false);
		asm_output(name=="main"?":\n":"_:\n" ,false);
		asm_output("add $sp, $sp, " + to_string(total_offset) + "\n");
		asm_output("lw $fp, -4($sp)\n");
		asm_output("lw $ra, 0($sp)\n");
		asm_output("jr $ra\n");
}

void ProcedureDefn::genasm()
{
	for(int i=0; i<rtl.size(); ++i){
		rtl[i]->printasm();
		asm_output("\n");
	}
}

void ProcedureDefn::print_tac()
{
	for(int i=0;i<tac.size();i++)
	{
		tac[i]->print();
	}
}

void ProcedureDefn::gentac(TACOperand* ret_stemp)
{
	for(int i=0; i<statements.size(); ++i){
		statements[i]->gentac(tac);
	}	
	if(current_procedure_rn -> ret_type != DTYPE_VOID){
		assert(current_procedure_rn->ret_label);
		tac.push_back(new LabelTACStatement(current_procedure_rn->ret_label));
		tac.push_back(new ReturnTACStatement(ret_stemp));
	}
}

void Procedure::genrtl()
{
	if(defn){
		defn -> genrtl();
		if(defn->rtl.size()){
			rtl_output("**PROCEDURE: " + name, false);	
			if(strcmp(name.c_str(), "main") != 0)
				rtl_output("_", false);
			rtl_output("\n", false);
			rtl_output("**BEGIN: RTL Statements\n", false);
			is_rtl_printing_rn = true;
			defn->print_rtl();
			rtl_output("**END: RTL Statements\n", false);
		}
	}
}

void ProcedureDefn::genrtl()
{
	for(int i=0; i<tac.size(); ++i){
		tac[i]->genrtl(rtl);
#ifdef DEBUG
		print_rtl();
		rtl.erase(rtl.begin(), rtl.end());
#endif
	}
}

void ProcedureDefn::print_rtl()
{
	for(int i=0; i<rtl.size(); ++i){
		rtl[i]->print();
		rtl_output("\n");
	}
}

st_datatype Procedure::get_arg_type(int i)
{
	assert(i < formal_param_list->size());
	assert(i>=0);
	return (*formal_param_list)[i]->type;
}
