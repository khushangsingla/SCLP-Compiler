#pragma once

#include <vector>

#include "utils.h"

enum bool_type {
	BOOL_AND,
	BOOL_OR
};

enum relop {
	RELOP_GREATER_THAN,
	RELOP_LESS_THAN,
	RELOP_GREATER_THAN_EQUAL,
	RELOP_LESS_THAN_EQUAL,
	RELOP_NOT_EQUAL,
	RELOP_EQUAL
};

enum ast_type {
	FUNCTION_CALL_AST,
	NAME_EXPRESSION_AST,
	INTEGER_EXPRESSION_AST,
	FLOAT_EXPRESSION_AST,
	STRING_EXPRESSION_AST,
	ARRAY_ACCESS_EXPRESSION_AST,
	BOOLEAN_EXPRESSION_AST,
	DIVISION_EXPRESSION_AST,
	FIELD_ACCESS_EXPRESSION_AST,
	MINUS_EXPRESSION_AST,
	MULTIPLICATION_EXPRESSION_AST,
	PLUS_EXPRESSION_AST,
	RELATIONAL_EXPRESSION_AST,
	CONDITIONAL_EXPRESSION_AST,
	ADDRESS_EXPRESSION_AST,
	POINTER_DEREFERENCE_EXPRESSION_AST,
	UMINUS_EXPRESSION_AST,
	NOT_BOOL_EXPRESSION_AST,
	ASSIGNMENT_STATEMENT_AST,
	ITERATION_STATEMENT_AST,
	READ_STATEMENT_AST,
	RETURN_STATEMENT_AST,
	PRINT_STATEMENT_AST,
	SELECTION_STATEMENT_AST,
	SEQUENCE_STATEMENT_AST
};

class AST 
{
	protected:
		ast_type type;
		vector<AST*> children;

	public:
		AST(ast_type);
};

class ExpressionAST : public AST 
{
	public:
		ExpressionAST(ast_type);
};

class StatementAST : public AST
{
	public:
		StatementAST(ast_type);
};

class BaseExpressionAST : public ExpressionAST
{
	public:
		BaseExpressionAST(ast_type);
};

class UnaryExpressionAST : public ExpressionAST
{
	protected:
		AST *operand;
		UnaryExpressionAST(ast_type,AST*);
	public:
};

class BinaryExpressionAST : public ExpressionAST
{
	protected:
		AST *left,*right;
		BinaryExpressionAST(ast_type,AST* left, AST* right);
		setLeftChild(AST*);
		setRightChild(AST*);
	public:
};

class TernaryExpressionAST : public ExpressionAST
{
	protected:
		AST *left,*mid,*right;
		TernaryExpressionAST(ast_type,AST*,AST*,AST*);
	public:

};

class FunctionCallAST : public BaseExpressionAST
{
	public:
		FunctionCallAST();
};

class NameExpressionAST : public BaseExpressionAST
{
	Symbol* var;
	string name;
	public:
		NameExpressionAST(char* name);
		~NameExpressionAST();
};

class IntegerExpressionAST : public BaseExpressionAST
{
	int val;
	public:
		IntegerExpressionAST(char*);
};

class FloatExpressionAST : public BaseExpressionAST
{
	float val;
	public:
		FloatExpressionAST(char*);
};

class StringExpressionAST : public BaseExpressionAST
{
	string val;
	public:
		StringExpressionAST(char*);
		~StringExpressionAST();
};

class AddressExpressionAST : public UnaryExpressionAST
{
	public:
		AddressExpressionAST(AST*);
};

class PointerDereferenceExpressionAST : public UnaryExpressionAST
{
	public:
		PointerDereferenceExpressionAST(AST*);
};

class UMinusExpressionAST : public UnaryExpressionAST
{
	public:
		UMinusExpressionAST(AST*);
};

class ArrayAccessExpressionAST : public BinaryExpressionAST
{
	public:
		ArrayAccessExpressionAST(AST* left,AST* right);
};

class BooleanExpressionAST : public BinaryExpressionAST
{
	bool_type type;
	public:
		BooleanExpressionAST(AST* left,AST* right, bool_type);
};

class DivisionExpressionAST : public BinaryExpressionAST
{
	public:
		DivisionExpressionAST(AST* left,AST* right);
};

class FieldAccessExpressionAST : public BinaryExpressionAST
{
	public:
		FieldAccessExpressionAST(AST* left,AST* right);
};

class MinusExpressionAST : public BinaryExpressionAST
{
	public:
		MinusExpressionAST(AST* left,AST* right);
};

class MultiplicationExpressionAST : public BinaryExpressionAST
{
	public:
		MultiplicationExpressionAST(AST* left, AST* right);
};

class PlusExpressionAST : public BinaryExpressionAST
{
	public:
		PlusExpressionAST(Expression* left, Expression* rightAST* left,AST* right);
};

class RelationalExpressionAST : public BinaryExpressionAST
{
	relop opn;
	public:
		RelationalExpressionAST(AST*,AST*,relop);
};

class ConditionalExpressionAST : public TernaryExpressionAST
{
	public:
		ConditionalExpressionAST(AST*,AST*,AST*);
};

class AssignmentStatementAST : public StatementAST
{
	AST *lhs,*rhs;
	public:
		AssignmentStatementAST(AST*,AST*);
};

class IterationStatementAST : public StatementAST
{
	public:
		IterationStatementAST();
};

class ReadStatementAST : public StatementAST
{
	private:
		NameExpressionAST* opd;
	public:
		ReadStatementAST(NameExpressionAST*);
};

class PrintStatementAST : public StatementAST
{	
	private:
		ExpressionAST* opd;
	public:
		PrintStatementAST(ExpressionAST*);
};

class ReturnStatementAST : public StatementAST
{
	public:
		ReturnStatementAST();
};

class SelectionStatementAST : public StatementAST
{
	public:
		SelectionStatementAST();
};

class SequenceStatementAST : public StatementAST
{
	public:
		SequenceStatementAST();
};

class NotBoolExpressionAST : public UnaryExpressionAST
{
	public:
		NotBoolExpressionAST(AST*);
