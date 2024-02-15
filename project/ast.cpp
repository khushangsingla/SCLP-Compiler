#include <cassert>

#include "ast.h"

AST::AST(ast_type type)
{
	this->type = type;
}

ExpressionAST::ExpressionAST(ast_type type) : AST(type)
{
}

StatementAST::StatementAST(ast_type t) : AST(t)
{
}

BaseExpressionAST::BaseExpressionAST(ast_type t) : ExpressionAST(t)
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

BinaryExpressionAST::setLeftChild(AST* ast)
{
	left = ast;
}

BinaryExpressionAST::setRightChild(AST* ast)
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
	var = NULL;
	this->name = new string(name);
}

NameExpressionAST::~NameExpressionAST()
{
	delete name;
}

IntegerExpressionAST::IntegerExpressionAST(int val) : BaseExpressionAST(INTEGER_EXPRESSION_AST)
{
	this->val = atoi(val);
}

FloatExpressionAST::FloatExpressionAST(float val) : BaseExpressionAST(FLOAT_EXPRESSION_AST)
{
	this->val = atof(val);
}

StringExpressionAST::StringExpressionAST(string val) : BaseExpressionAST(STRING_EXPRESSION_AST)
{
	this->val = new string(val);
}

StringExpressionAST::~StringExpressionAST()
{
	delete val;
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

PlusExpressionAST::PlusExpressionAST(ASTAST* left,AST* right* left, AST* right) : BinaryExpressionAST(PLUS_EXPRESSION_AST,left,right,left,right)
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

ReadStatementAST::ReadStatementAST(NameExpressionAST* opd) : StatementAST(READ_STATEMENT_AST)
{
	this->opd = opd;
}

PrintStatementAST::PrintStatementAST(ExpressionAST* opd) : StatementAST(PRINT_STATEMENT_AST)
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
