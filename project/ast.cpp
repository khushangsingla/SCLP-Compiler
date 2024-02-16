#include <cassert>

#include "ast.h"

AST::AST(ast_type type)
{
	this->type = type;
}

ExpressionAST::ExpressionAST(ast_type type) : AST(type)
{
}

ExpressionAST::ExpressionAST(ast_type type, st_datatype dt) : AST(type)
{
	dtype = dt;
}

StatementAST::StatementAST(ast_type t) : AST(t)
{
}

BaseExpressionAST::BaseExpressionAST(ast_type t) : ExpressionAST(t)
{
}

BaseExpressionAST::BaseExpressionAST(ast_type t, st_datatype dt) : ExpressionAST(t, dt)
{
}

UnaryExpressionAST::UnaryExpressionAST(ast_type t,AST* ch) : ExpressionAST(t)
{
	this -> operand = ch;
	dtype = DTYPE_UNKNOWN;
}

BinaryExpressionAST::BinaryExpressionAST(ast_type t, AST* left, AST* right) : ExpressionAST(t)
{
	setLeftChild(left);
	setRightChild(right);
	dtype = DTYPE_UNKNOWN;
}

void BinaryExpressionAST::setLeftChild(AST* ast)
{
	left = ast;
}

void BinaryExpressionAST::setRightChild(AST* ast)
{
	right = ast;
}

TernaryExpressionAST::TernaryExpressionAST(ast_type t,AST* l, AST* m, AST* r) : ExpressionAST(t)
{
	left = l;
	mid = m;
	right = r;
	dtype = DTYPE_UNKNOWN;
}

FunctionCallAST::FunctionCallAST() : BaseExpressionAST(FUNCTION_CALL_AST)
{
}

NameExpressionAST::NameExpressionAST(char* name) : BaseExpressionAST(NAME_EXPRESSION_AST)
{
	/* TODO */
	/* Convert string name to symbol* */
	this->name = name;
}

IntegerExpressionAST::IntegerExpressionAST(char* val) : BaseExpressionAST(INTEGER_EXPRESSION_AST, DTYPE_INTEGER)
{
	this->val = atoi(val);
}

FloatExpressionAST::FloatExpressionAST(char* val) : BaseExpressionAST(FLOAT_EXPRESSION_AST, DTYPE_FLOAT)
{
	this->val = atof(val);
}

StringExpressionAST::StringExpressionAST(char* val) : BaseExpressionAST(STRING_EXPRESSION_AST, DTYPE_STRING)
{
	this->val = val;
}

AddressExpressionAST::AddressExpressionAST(AST* t) : UnaryExpressionAST(ADDRESS_EXPRESSION_AST,t)
{
}

PointerDereferenceExpressionAST::PointerDereferenceExpressionAST(AST* t) : UnaryExpressionAST(POINTER_DEREFERENCE_EXPRESSION_AST,t)
{
}

UMinusExpressionAST::UMinusExpressionAST(AST* t) : UnaryExpressionAST(UMINUS_EXPRESSION_AST,t)
{
}

ArrayAccessExpressionAST::ArrayAccessExpressionAST(AST* left,AST* right) : BinaryExpressionAST(ARRAY_ACCESS_EXPRESSION_AST,left,right)
{
}

BooleanExpressionAST::BooleanExpressionAST(AST* left,AST* right,bool_type type) : BinaryExpressionAST(BOOLEAN_EXPRESSION_AST,left,right)
{
	this->type = type;
}

DivisionExpressionAST::DivisionExpressionAST(AST* left,AST* right) : BinaryExpressionAST(DIVISION_EXPRESSION_AST,left,right)
{
}

FieldAccessExpressionAST::FieldAccessExpressionAST(AST* left,AST* right) : BinaryExpressionAST(FIELD_ACCESS_EXPRESSION_AST,left,right)
{
}

MinusExpressionAST::MinusExpressionAST(AST* left,AST* right) : BinaryExpressionAST(MINUS_EXPRESSION_AST,left,right)
{
}

MultiplicationExpressionAST::MultiplicationExpressionAST(AST* left, AST *right) : BinaryExpressionAST(MULTIPLICATION_EXPRESSION_AST,left,right)
{
}

PlusExpressionAST::PlusExpressionAST(AST* left,AST* right) : BinaryExpressionAST(PLUS_EXPRESSION_AST,left,right)
{
}

RelationalExpressionAST::RelationalExpressionAST(AST* left,AST* right,relop op) : BinaryExpressionAST(RELATIONAL_EXPRESSION_AST,left,right)
{
	this->opn = op;
}

ConditionalExpressionAST::ConditionalExpressionAST(AST* a,AST* b,AST* c) : TernaryExpressionAST(CONDITIONAL_EXPRESSION_AST,a,b,c)
{
}

AssignmentStatementAST::AssignmentStatementAST(AST* l, AST* r) : StatementAST(ASSIGNMENT_STATEMENT_AST)
{
	lhs = l;
	rhs = r;
}

IterationStatementAST::IterationStatementAST() : StatementAST(ITERATION_STATEMENT_AST)
{
}

ReadStatementAST::ReadStatementAST(AST* opd) : StatementAST(READ_STATEMENT_AST)
{
	this->opd = opd;
}

PrintStatementAST::PrintStatementAST(AST* opd) : StatementAST(PRINT_STATEMENT_AST)
{
	this->opd = opd;
}

ReturnStatementAST::ReturnStatementAST() : StatementAST(RETURN_STATEMENT_AST)
{
}

SelectionStatementAST::SelectionStatementAST() : StatementAST(SELECTION_STATEMENT_AST)
{
}

NotBoolExpressionAST::NotBoolExpressionAST(AST* t) : UnaryExpressionAST(NOT_BOOL_EXPRESSION_AST,t)
{
}

int NameExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(vars->is_variable_present(name) != 0)	return -1;
	dtype = vars->get_datatype(name);
	return 0;
}

int IntegerExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	return 0;
}

int FloatExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	return 0;
}

int StringExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	return 0;
}

int UMinusExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(operand->is_valid(vars,fns) != 0)	return -1;
	dtype = ((ExpressionAST*)operand)->dtype;
	return 0;
}

int BooleanExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left) -> dtype != DTYPE_BOOL || ((ExpressionAST*)right) -> dtype != DTYPE_BOOL)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

int BinaryExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left) -> dtype != ((ExpressionAST*)right) -> dtype)	return -1;
	if(((ExpressionAST*)left) -> dtype != DTYPE_INTEGER && ((ExpressionAST*)left) -> dtype != DTYPE_FLOAT)	return -1;
	dtype = ((ExpressionAST*)left) -> dtype;
	return 0;
}

int RelationalExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left) ->dtype != ((ExpressionAST*)right) ->dtype)	return -1;
	if(((ExpressionAST*)left) ->dtype != DTYPE_INTEGER && ((ExpressionAST*)left) ->dtype != DTYPE_FLOAT)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

int ConditionalExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left->is_valid(vars,fns) != 0)	return -1;
	if(mid->is_valid(vars,fns) != 0)	return -1;
	if(right->is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left)->dtype != DTYPE_BOOL)	return -1;
	if(((ExpressionAST*)mid)->dtype != ((ExpressionAST*)right) -> dtype)	return -1;
	dtype = ((ExpressionAST*)mid)->dtype;
	return 0;
}

int AssignmentStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(((ExpressionAST*)lhs) -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)rhs) -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)lhs) -> dtype != ((ExpressionAST*)rhs) -> dtype)	return -1;
	return 0;
}

int ReadStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(opd -> is_valid(vars,fns) != 0)	return -1;
	if(opd -> type != NAME_EXPRESSION_AST)	return -1;
	if(((ExpressionAST*)opd) -> dtype != DTYPE_INTEGER && ((ExpressionAST*)opd) -> dtype != DTYPE_FLOAT)	return -1;
	return 0;
}

int PrintStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(opd -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)opd) -> dtype == DTYPE_BOOL)	return -1;
	return 0;
}

int NotBoolExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(operand -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)operand) -> dtype != DTYPE_BOOL)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

void AssignmentStatementAST::print(string prefix)
{
	ast_output(prefix + "Asgn:\n" + prefix + "  LHS (");
	lhs -> print(prefix + "  ");
	ast_output(")\n" + prefix + "  RHS (");
	rhs -> print(prefix + "  ");
	ast_output(")\n");
}

void ReadStatementAST::print(string prefix)
{
	ast_output(prefix + "Read: ");
	opd -> print(prefix + "  ");
	ast_output("\n");
}

void PrintStatementAST::print(string prefix)
{
	ast_output(prefix + "Write: ");
	opd -> print(prefix + "  ");
	ast_output("\n");
}

void NameExpressionAST::print(string prefix)
{
	ast_output(prefix + "Name : " + name + "_" + get_string_for_dtype(dtype));
}

void IntegerExpressionAST::print(string prefix)
{
	ast_output(prefix + "Num : " + to_string(val) + get_string_for_dtype(dtype));
}

void FloatExpressionAST::print(string prefix)
{
	// convert float to string with precision 2
	string float_str;
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << val;
	float_str = ss.str();
	ast_output(prefix + "Num : " + float_str + get_string_for_dtype(dtype));
}

void BinaryExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Arith: ");
	switch(type)
	{
		case PLUS_EXPRESSION_AST:
			ast_output("Plus");
			break;
		case MINUS_EXPRESSION_AST:
			ast_output("Minus");
			break;
		case MULTIPLICATION_EXPRESSION_AST:
			ast_output("Mult");
			break;
		case DIVISION_EXPRESSION_AST:
			ast_output("Div");
			break;
		default:
			assert(0);
	}
	ast_output(get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	left -> print(prefix + "  ");
	ast_output(")\n" + prefix + "  R_Opd (");
	right -> print(prefix + "  ");
	ast_output(")\n");
}

void ConditionalExpressionAST::print(string prefix)
{
	left -> print(prefix + "  ");
	ast_output("\n" + prefix + "True_Part (");
	mid -> print(prefix + "  ");
	ast_output(")\n" + prefix + "False_Part (");
	right -> print(prefix + "  ");
	ast_output(")\n");
}

void RelationalExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Condition: ");
	switch(opn)
	{
		case RELOP_LESS_THAN:
			ast_output("LT");
			break;
		case RELOP_LESS_THAN_EQUAL:
			ast_output("LE");
			break;
		case RELOP_GREATER_THAN:
			ast_output("GT");
			break;
		case RELOP_GREATER_THAN_EQUAL:
			ast_output("GE");
			break;
		case RELOP_EQUAL:
			ast_output("EQ");
			break;
		case RELOP_NOT_EQUAL:
			ast_output("NE");
			break;
		default:
			assert(0);
	}
	ast_output(get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	left -> print(prefix + "  ");
	ast_output(")\n" + prefix + "  R_Opd (");
	right -> print(prefix + "  ");
	ast_output(")\n");
}

void NotBoolExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Condition: NOT" + get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	operand -> print(prefix + "  ");
	ast_output(")\n");
}

void UMinusExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Arith: UMinus" + get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	operand -> print(prefix + "  ");
	ast_output(")\n");
}

void StringExpressionAST::print(string prefix)
{
	ast_output(prefix + "String : " + val + get_string_for_dtype(dtype));
}
