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
}

BinaryExpressionAST::BinaryExpressionAST(ast_type t, AST* left, AST* right) : ExpressionAST(t)
{
	setLeftChild(left);
	setRightChild(right);
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
	dtype = operand->dtype;
	return 0;
}

int BooleanExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(left -> type != DTYPE_BOOL || right -> type != DTYPE_BOOL)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

int BinaryExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(left -> type != right -> type)	return -1;
	if(left -> type != DTYPE_INTEGER && left -> type != DTYPE_FLOAT)	return -1;
	dtype = left -> type;
	return 0;
}

int RelationalExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(left -> type != right -> type)	return -1;
	if(left -> type != DTYPE_INTEGER && left -> type != DTYPE_FLOAT)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

int ConditionalExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left->is_valid(vars,fns) != 0)	return -1;
	if(mid->is_valid(vars,fns) != 0)	return -1;
	if(right->is_valid(vars,fns) != 0)	return -1;
	if(left->type != DTYPE_BOOL)	return -1;
	if(mid->type != right -> type)	return -1;
	dtype = mid->type;
	return 0;
}

int AssignmentStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(left -> type != right -> type)	return -1;
	return 0;
}

int ReadStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(opd -> is_valid(vars,fns) != 0)	return -1;
	if(opd -> type != NAME_EXPRESSION_AST)	return -1;
	return 0;
}

int PrintStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(opd -> is_valid(vars,fns) != 0)	return -1;
	if(opd -> type == DTYPE_BOOL)	return -1;
	return 0;
}

int NotBoolExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(operand -> is_valid(vars,fns) != 0)	return -1;
	if(operand -> dtype != DTYPE_BOOL)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}
