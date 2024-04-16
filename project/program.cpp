#include "program.h"
void my_exit(int exit_code, const char* msg);
extern Procedure* current_procedure_rn;
using namespace std;

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
	bool is_ret_label_defined = false;
	if(global_symbol_table->is_variable_present(proc->name) == 0)
	{
		my_exit(1, "[program.cpp] procedure name same as global variable");
		return -1;
	}
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
		is_ret_label_defined = true;
	}
	if(proc -> ret_type != DTYPE_VOID){
		if (is_ret_label_defined)
			proc -> ret_label = procedures[proc->name] -> ret_label;
		else
			proc -> ret_label = new LabelTACOperand();
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
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		if(global_symbol_table->is_variable_present(it->first) == 0){
			my_exit(1, "[program.cpp] procedure name same as global variable");
			return -1;
		}
	}
	if(global_symbol_table->add_symbols_from_table(st) != 0)	return -1;
	return 0;
}

void Program::gentac()
{
	vector<string> keys;
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		if(it->first == "main")	keys.push_back(it->first);
		else keys.push_back(it->first + "_");
	}
	sort(keys.begin(), keys.end());
	vector<string> order_of_keys_with__;
	for(int i = 0; i < keys.size(); i++){
		string curr;
		if(keys[i] == "main")	curr= "main";
		else
			curr = keys[i].substr(0, keys[i].size()-1);
		TemporaryTACOperand::count = 0;
		STemporaryTACOperand::count = 0;
		procedures[curr]->gentac();
	}
	// for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
	// 	TemporaryTACOperand::count = 0;
	// 	STemporaryTACOperand::count = 0;
	// 	it->second->gentac();
	// }
}

void Program::genrtl()
{
	vector<string> keys;
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		if(it->first == "main")	keys.push_back(it->first);
		else keys.push_back(it->first + "_");
	}
	sort(keys.begin(), keys.end());
	vector<string> order_of_keys_with__;
	for(int i = 0; i < keys.size(); i++){
		string curr;
		if(keys[i] == "main")	curr= "main";
		else
			curr = keys[i].substr(0, keys[i].size()-1);
		current_procedure_rn = procedures[curr];
		procedures[curr]->genrtl();
	}
	// // Iterate procedures in order of keys
	// for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
	// 	it->second->genrtl();
	// }
}

void Program::printast()
{

	vector<string> keys;
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		if(it->first == "main")	keys.push_back(it->first);
		else keys.push_back(it->first + "_");
	}
	sort(keys.begin(), keys.end());
	vector<string> order_of_keys_with__;
	for(int i = 0; i < keys.size(); i++){
		string curr;
		if(keys[i] == "main")	curr= "main";
		else
			curr = keys[i].substr(0, keys[i].size()-1);
		procedures[curr]->print_ast();
	}
}

void Program::genasm()
{
	// print data section
	map<string,int> str_consts = StringConstantTACOperand::string_index;
	if(global_symbol_table -> symbols . size() || str_consts.size()){
		asm_output(".data\n");
	}
	vector<pair<int,string>> ordered_gst;
	for(auto s: global_symbol_table->symbols){
		ordered_gst.push_back(make_pair(s.second->offset, s.first));
	}
	sort(ordered_gst.begin(), ordered_gst.end());
	for(auto s: ordered_gst){
		asm_output(s.second + "_:",false);
		if(global_symbol_table -> symbols[s.second] -> type == DTYPE_FLOAT){
			asm_output(".double 0.0",true);
		}
		else{
			asm_output(".word 0",true);
		}
		asm_output("\n",false);
	}
	vector<pair<int,string>> ordered_str_consts;
	for(auto s: str_consts){
		ordered_str_consts.push_back(make_pair(s.second, s.first));
	}

	sort(ordered_str_consts.begin(), ordered_str_consts.end());
	for(auto s: ordered_str_consts){
		asm_output("_str_" + to_string(s.first) + ":",false);
		asm_output(".asciiz " + s.second,true);
		asm_output("\n",false);
	}
	
	asm_output("\n");
	// print code
	vector<string> keys;
	for(map<string, Procedure*>::iterator it = procedures.begin(); it != procedures.end(); it++){
		if(it->first == "main")	keys.push_back(it->first);
		else keys.push_back(it->first + "_");
	}
	sort(keys.begin(), keys.end());
	vector<string> order_of_keys_with__;
	for(int i = 0; i < keys.size(); i++){
		string curr;
		if(keys[i] == "main")	curr= "main";
		else
			curr = keys[i].substr(0, keys[i].size()-1);
		current_procedure_rn = procedures[curr];
		asm_output(".text\n\t.globl " + curr ,true);
		if(curr == "main"){
			asm_output("\n");
		}
		else{
			asm_output("_\n");
		}
		asm_output(curr ,false);
		if(curr == "main"){
			asm_output(":\n",false);
		}
		else{
			asm_output("_:\n",false);
		}
		procedures[curr]->genasm();
	}
}
