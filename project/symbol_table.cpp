#include "symbol_table.h"
#include "ast.h"
#include <cassert>

using namespace std;

Symbol::Symbol(string s, st_datatype type, bool is_ptr )
{
	this->name = s;
	this->type = type;
	this->is_ptr = is_ptr;
}

Symbol::Symbol(AST* a, st_datatype type, bool is_ptr )
{
	this->name = ((NameExpressionAST*)a)->name;
	// delete a;
	this->type = type;
	this->is_ptr = is_ptr;
}

string Symbol::get_name()
{
	return this->name;	
}

st_datatype Symbol::get_type()
{
	return type;
}

SymbolTable::SymbolTable()
{
}

SymbolTable::SymbolTable(st_datatype d, vector<AST*>* v,bool to_delete)
{
	for(auto x: *v){
		if(add_symbol(new Symbol(((NameExpressionAST*)x)->name, d, false)) != 0) my_exit(1);
		// if(to_delete)
			// delete x;
	}
}

int SymbolTable::add_symbol(Symbol* s)
{
	if(symbols.find(s->name) != symbols.end()){
		return -1;
	}	

	symbols[s->name] = s;
	return 0;
}

int SymbolTable::add_symbols_from_table(SymbolTable* t)
{
	for(auto s: t->symbols){
		if(add_symbol(s.second) != 0) return -1;
	}
	return 0;
}

int SymbolTable::add_global_symbols(SymbolTable* gst)
{
	for(auto s: gst->symbols){
		add_symbol(s.second);
	}
	return 0;
}

int SymbolTable::is_variable_present(string name)
{
	if(symbols.find(name) == symbols.end())	return -1;
	return 0;
}

st_datatype SymbolTable::get_datatype(string name)
{
	assert(is_variable_present(name) == 0);
	return symbols[name] -> type;
}

int SymbolTable::get_symbol_count()
{
	return symbols.size();
}

string get_string_for_dtype(st_datatype dt)
{
	switch(dt){
		case DTYPE_INTEGER: 
			return "<int>";
		case DTYPE_FLOAT: 
			return "<float>";
		case DTYPE_STRING: 
			return "<string>";
		case DTYPE_BOOL: 
			return "<bool>";
		case DTYPE_VOID: 
			return "<void>";
		default: 
			assert(0);
			return "<unknown>";
	}
}
