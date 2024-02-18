#include "program.h"
void my_exit(int exit_code, const char* msg);

Program::Program(SymbolTable* gst)
{
	global_symbol_table = gst;
}

Program::Program(SymbolTable* gst, Procedure* proc)
{
	global_symbol_table = gst;
	procedures[proc->name] = proc;
	
	if(proc -> is_defined &&  proc->is_proc_valid(gst, procedures) != 0){
		my_exit(1, "[program.cpp] procedure not valid");
	}
	if(proc -> is_defined)
		proc->print_ast();
}

int Program::main_func_check()
{
	if(procedures.size() != 1){
		my_exit(1, "Only main function should be present");
	}	
	if(procedures.find("main") == procedures.end()){
		my_exit(1, "main not present");
	}
	if(procedures["main"]->get_return_type() != DTYPE_VOID){
		my_exit(1, "main return type not void");
	}
	return 0;
}

int Program::add_procedure(Procedure* proc)
{
	if(procedures.find(proc->name) != procedures.end()){
		if(procedures[proc->name]->is_defined || !proc->is_defined){
			return -1;
		}
		else{
			// Check if declaration matches definition
			if(procedures[proc->name] -> match_declaration(proc) != 0){
				return -1;
			}
			// delete procedures[proc->name];
		}
	}
	procedures[proc->name] = proc;
	if(proc->is_defined && proc->is_proc_valid(global_symbol_table, procedures) != 0){
		my_exit(1, "[program.cpp] procedure not valid");
	}
	if(proc -> is_defined)
		proc -> print_ast();
	return 0;
}

int Program::add_global_symbols(SymbolTable* st)
{
	if(global_symbol_table->add_symbols_from_table(st) != 0)	return -1;
	return 0;
}
