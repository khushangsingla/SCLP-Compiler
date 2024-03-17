#pragma once

#include <string>
#include "utils.h"

using namespace std;

enum tac_type {
	ASSIGNMENT_TAC_STATEMENT,
	CALL_TAC_STATEMENT,
	COMPUTE_TAC_STATEMENT,
	GOTO_TAC_STATEMENT,
	IFGOTO_TAC_STATEMENT,
	IO_TAC_STATEMENT,
	LABEL_TAC_STATEMENT,
	NOP_TAC_STATEMENT,
	RETURN_TAC_STATEMENT,
};

enum computation_type {
	ADD_COMPUTATION_TYPE,
	SUB_COMPUTATION_TYPE,
	MUL_COMPUTATION_TYPE,
	DIV_COMPUTATION_TYPE,
	MOD_COMPUTATION_TYPE,
	NEG_COMPUTATION_TYPE,
	AND_COMPUTATION_TYPE,
	OR_COMPUTATION_TYPE,
	NOT_COMPUTATION_TYPE,
	EQ_COMPUTATION_TYPE,
	NEQ_COMPUTATION_TYPE,
	LT_COMPUTATION_TYPE,
	GT_COMPUTATION_TYPE,
	LTE_COMPUTATION_TYPE,
	GTE_COMPUTATION_TYPE
};

class TACOperand
{
	public:
		TACOperand();
		virtual string to_string() = 0;
};

class TACStatement
{
	protected:
		tac_type type;
		TACOperand* result;
	public:
		TACStatement(tac_type);
		TACOperand* get_value();
		virtual void print() = 0;
};

class AssignmentTACStatement : public TACStatement
{
	TACOperand *value;
	public:
		AssignmentTACStatement(TACOperand* result, TACOperand* value);
		void print();
};

class CallTACStatement : public TACStatement
{
	public:
	CallTACStatement();
};

class ComputeTACStatement : public TACStatement
{
	TACOperand *left, *right;
	computation_type type;
	public:
		ComputeTACStatement(TACOperand*, TACOperand*, computation_type);
		void print();
};

class GotoTACStatement : public TACStatement
{
	private:
		TACOperand* label;
	public:
		GotoTACStatement(TACOperand*);
		void print();
};

class IfGotoTACStatement : public TACStatement
{
	private:
		TACOperand* condition;
		TACOperand* label;
	public:
		IfGotoTACStatement(TACOperand*, TACOperand*);
		void print();
};

class IOTACStatement : public TACStatement
{
	protected:
		bool is_write;
	public:
		IOTACStatement(TACOperand*, bool);
		void print();
};

class LabelTACStatement : public TACStatement
{
	private:
		TACOperand* label;
	public:
		LabelTACStatement(TACOperand*);
		void print();
};

class NopTACStatement : public TACStatement
{
	public:
	NopTACStatement();
};

class ReturnTACStatement : public TACStatement
{
	public:
	ReturnTACStatement();
};

class ArrayAccessTACOperand : public TACOperand
{
	public:
	ArrayAccessTACOperand();
};

class DoubleConstantTACOperand : public TACOperand
{
	double value;
	public:
		DoubleConstantTACOperand(double);
		string to_string();
};

class IntegerConstantTACOperand : public TACOperand
{
	int value;
	public:
		IntegerConstantTACOperand(int);
		string to_string();
};

class LabelTACOperand : public TACOperand
{
	private:
		int num;
		static int count;
	public:
		LabelTACOperand();
		string to_string();
};

class PointerDereferenceTACOperand : public TACOperand
{
	public:
	PointerDereferenceTACOperand();
};

class StringConstantTACOperand : public TACOperand
{
	string value;
	public:
		StringConstantTACOperand(string);
		string to_string();
};

class TemporaryTACOperand : public TACOperand
{
	private:
		int num;
		static int count;
	public:
		TemporaryTACOperand();
		string to_string();
};

class VariableTACOperand : public TACOperand
{
	string name;
	public:
		VariableTACOperand(string);
		string to_string();
};

class STemporaryTACOperand : public TACOperand
{
	private:
		int num;
		static int count;
	public:
		STemporaryTACOperand();
		string to_string();
};
