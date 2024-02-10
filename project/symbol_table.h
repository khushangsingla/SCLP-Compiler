#pragma once

enum type {
	INTEGER,
	FLOAT,
	STRING,
	BOOL,
	VOID
}

class Symbol {
	private:
		string name;
		enum type;
		bool is_ptr;

	public:
		
};

class SymbolTable {
	private:
		vector<Symbol*> symbols;
};
