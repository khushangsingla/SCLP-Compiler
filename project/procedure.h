#pragma once

#include <vector>

#include "symbol_table.h"
#include "ast.h"

class Procedure {
	private:
		SymbolTable *local_symbol_table, *formal_param_list;
		AST *ast;
};
