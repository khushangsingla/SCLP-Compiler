#include "symbol_table.h"

Symbol::Symbol(string name, datatype type, bool is_ptr = false){
	this->name = name;
	this->type = type;
	this->is_ptr = is_ptr;
}

string Symbol::get_name(){
	return this->name;	
}

datatype Symbol::get_type(){
	return type;
}

SymbolTable::SymbolTable(){
	
}

SymbolTable::SymbolTable(datatype d, vector<AST*>* v,bool to_delete = false;){
	for(auto x: *v){
		if(add_symbol(new Symbol(x->name, d, false)) != 0) my_exit(1);
		if(to_delete)
			delete x;
	}
}

int SymbolTable::add_symbol(Symbol* s){
	if(symbols.find(s->name) != symbols.end()){
		return -1;
	}	

	symbols[s->name] = s;
	return 0;
}

int SymbolTable::add_symbols_from_table(SymbolTable* t){
	for(auto s: t->symbols){
		if(add_symbol(s) != 0) return -1;
	}
	return 0;
}
