#pragma once

enum datatype {
	DTYPE_INTEGER,
	DTYPE_FLOAT,
	DTYPE_STRING,
	DTYPE_BOOL,
	DTYPE_VOID
}

class Symbol {
	private:
		string name;
		datatype type;
		bool is_ptr;

	public:
		Symbol(string, datatype, bool);
		string get_name();
		datatype get_type();
};

class SymbolTable {
	private:
		map<string, Symbol*> symbols;
	
	public:
		SymbolTable();
		SymbolTable(datatype, vector<AST*>*,bool);
		int add_symbol(Symbol*);
		int add_symbols_from_table(SymbolTable*);
};
