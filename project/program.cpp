#include "program.h"
void my_exit(int exit_code, const char* msg);

Program::Program(pair<SymbolTable* , vector<Procedure*>> *p, vector<Procedure*> *procs)
{
	if(p){
		global_symbol_table = p->first;
		for(int i = 0; i < p->second.size(); i++){
			add_procedure(p->second[i]);
		}
	}
	else{
		global_symbol_table = new SymbolTable();
	}
	for(int i = 0; i < procs->size(); i++){
		add_procedure((*procs)[i]);
	}
	main_func_check();

	vector<string> keys;
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		if(it->first == "main")	keys.push_back(it->first);
		else keys.push_back(it->first + "_");
	}
	sort(keys.begin(), keys.end());
	for(int i = 0; i < keys.size(); i++){
		if(keys[i] == "main")	order_of_keys_with__.push_back("main");
		else
			order_of_keys_with__.push_back(keys[i].substr(0, keys[i].size() - 1));
	}
}

int Program::main_func_check()
{
	// if(procedures.size() != 1){
	// 	my_exit(1, "Only main function should be present");
	// }	
	if(procedures.find("main") == procedures.end()){
		my_exit(1, "main not present");
	}
	// if(procedures["main"]->get_return_type() != DTYPE_VOID){
	// 	my_exit(1, "main return type not void");
	// }
	return 0;
}

int Program::add_procedure(Procedure* proc)
{
	if(procedures.find(proc->name) != procedures.end()){
		if(procedures[proc->name]->is_defined || !proc->is_defined){
			my_exit(1, "[program.cpp] procedure defined twice or not defined at all");
			return -1;
		}
		else{
			// Check if declaration matches definition
			if(procedures[proc->name] -> match_declaration(proc) != 0){
				my_exit(1, "[program.cpp] declaration doesn't match definition");
				return -1;
			}
			// delete procedures[proc->name];
		}
	}
	procedures[proc->name] = proc;
	if(proc->is_defined && proc->is_proc_valid(global_symbol_table, procedures) != 0){
		my_exit(1, "[program.cpp] procedure not valid");
	}
	// if(proc -> is_defined)
	// 	proc -> print_ast();
	return 0;
}

int Program::add_global_symbols(SymbolTable* st)
{
	if(global_symbol_table->add_symbols_from_table(st) != 0)	return -1;
	return 0;
}

void Program::gentac()
{
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		TemporaryTACOperand::count = 0;
		STemporaryTACOperand::count = 0;
		it->second->gentac();
	}
}

void Program::genrtl()
{
	// Iterate procedures in order of keys
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		it->second->genrtl();
	}
}

void Program::printast()
{

	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		it->second->print_ast();
	}
}
