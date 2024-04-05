#pragma once

#include <string>
#include "utils.h"
#include "symbol_table.h"
#include "rtl.h"

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

enum tac_operand_type {
	ARRAY_ACCESS_TAC_OPERAND,
	DOUBLE_CONSTANT_TAC_OPERAND,
	INTEGER_CONSTANT_TAC_OPERAND,
	LABEL_TAC_OPERAND,
	POINTER_DEREFERENCE_TAC_OPERAND,
	STRING_CONSTANT_TAC_OPERAND,
	TEMPORARY_TAC_OPERAND,
	VARIABLE_TAC_OPERAND,
	STEMPORARY_TAC_OPERAND,
};

class TACOperand
{
	public:
		TACOperand();
		tac_operand_type op_type;
		int alloted_register;
		virtual string to_string() = 0;
		virtual st_datatype get_type();
		virtual void set_type(st_datatype t);
};

class TACStatement
{
	protected:
		tac_type type;
		TACOperand* result;
	public:
		TACStatement(tac_type);
		TACOperand* get_value();
		virtual void genrtl(vector<RTLStatement*>&) = 0;
		virtual void print() = 0;
};

class AssignmentTACStatement : public TACStatement
{
	TACOperand *value;
	bool do_negation;
	public:
		AssignmentTACStatement(TACOperand* result, TACOperand* value, bool do_negation = false);
		void print();
		void genrtl(vector<RTLStatement*>&);
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
		void genrtl(vector<RTLStatement*>&);
};

class GotoTACStatement : public TACStatement
{
	private:
		TACOperand* label;
	public:
		GotoTACStatement(TACOperand*);
		void print();
		void genrtl(vector<RTLStatement*>&);
};

class IfGotoTACStatement : public TACStatement
{
	private:
		TACOperand* condition;
		TACOperand* label;
	public:
		IfGotoTACStatement(TACOperand*, TACOperand*);
		void print();
		void genrtl(vector<RTLStatement*>&);
};

class IOTACStatement : public TACStatement
{
	protected:
		bool is_write;
	public:
		IOTACStatement(TACOperand*, bool);
		void print();
		void genrtl(vector<RTLStatement*>&);
};

class LabelTACStatement : public TACStatement
{
	private:
		TACOperand* label;
	public:
		LabelTACStatement(TACOperand*);
		void print();
		void genrtl(vector<RTLStatement*>&);
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
		st_datatype get_type();
};

class IntegerConstantTACOperand : public TACOperand
{
	int value;
	public:
		IntegerConstantTACOperand(int);
		string to_string();
		st_datatype get_type();
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
		static map<string,int> string_index;
		StringConstantTACOperand(string);
		string to_string();
		st_datatype get_type();
};

class TemporaryTACOperand : public TACOperand
{
	private:
		int num;
		static int count;
		st_datatype type;
	public:
		TemporaryTACOperand(st_datatype);
		string to_string();
		st_datatype get_type();
		void set_type(st_datatype t);
};

class VariableTACOperand : public TACOperand
{
	string name;
	st_datatype type;
	public:
		VariableTACOperand(string, st_datatype);
		string to_string();
		st_datatype get_type();
		void set_type(st_datatype t);
};

class STemporaryTACOperand : public TACOperand
{
	private:
		int num;
		static int count;
		st_datatype type;
	public:
		STemporaryTACOperand(st_datatype);
		string to_string();
		st_datatype get_type();
		void set_type(st_datatype t);
};
