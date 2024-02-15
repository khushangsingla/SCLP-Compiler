#include "program.h"

Program::Program(SymbolTable* gst){
	global_symbol_table = gst;
}

Program::Program(SymbolTable* gst, Procedure* proc){
	global_symbol_table = gst;
	procedures[proc->name] = proc;
}

int Program::add_procedure(Procedure* proc){
	if(procedures.find(proc->name) != procedures.end()){
		if(procedures[proc->name]->is_defined || !proc->is_defined){
			return -1;
		}
		else{
			// delete procedures[proc->name];
		}
	}
	procedures[proc->name] = proc;
	return 0;
}

int Program::add_global_symbols(SymbolTable* st){
	if(global_symbol_table->add_symbols_from_table(st) != 0)	return -1;
	return 0;
}
