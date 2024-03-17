#include "tac.h"

int TemporaryTACOperand::count = 0;
int STemporaryTACOperand::count = 0;
int LabelTACOperand::count = 0;

TACStatement::TACStatement(tac_type t)
{
	type = t;
}

TACOperand* TACStatement::get_value()
{
	return result;
}

TACOperand::TACOperand()
{
}

AssignmentTACStatement::AssignmentTACStatement(TACOperand* res,TACOperand* val) : TACStatement(ASSIGNMENT_TAC_STATEMENT)
{
	result = res;
	value = val;
}

CallTACStatement::CallTACStatement() : TACStatement(CALL_TAC_STATEMENT)
{
}

ComputeTACStatement::ComputeTACStatement(TACOperand* left,TACOperand* right,computation_type type) : TACStatement(COMPUTE_TAC_STATEMENT)
{
	this->left = left;
	this->right = right;
	this->type = type;
	this->result = new TemporaryTACOperand();
}

GotoTACStatement::GotoTACStatement(TACOperand* label) : TACStatement(GOTO_TAC_STATEMENT)
{
	this->label = label;
}

IfGotoTACStatement::IfGotoTACStatement(TACOperand* condition, TACOperand* label) : TACStatement(IFGOTO_TAC_STATEMENT)
{
	this->condition = condition;
	this->label = label;
}

IOTACStatement::IOTACStatement(TACOperand* opd, bool is_write) : TACStatement(IO_TAC_STATEMENT)
{
	this->result = opd;
	this->is_write = is_write;
}

LabelTACStatement::LabelTACStatement(TACOperand* label) : TACStatement(LABEL_TAC_STATEMENT)
{
	this->label = label;
}

NopTACStatement::NopTACStatement() : TACStatement(NOP_TAC_STATEMENT)
{
}

ReturnTACStatement::ReturnTACStatement() : TACStatement(RETURN_TAC_STATEMENT)
{
}

ArrayAccessTACOperand::ArrayAccessTACOperand() : TACOperand()
{
}

DoubleConstantTACOperand::DoubleConstantTACOperand(double val) : TACOperand()
{
	value = val;
}

IntegerConstantTACOperand::IntegerConstantTACOperand(int val) : TACOperand()
{
	value = val;
}

LabelTACOperand::LabelTACOperand() : TACOperand()
{
	num = count++;
}

PointerDereferenceTACOperand::PointerDereferenceTACOperand() : TACOperand()
{
}

StringConstantTACOperand::StringConstantTACOperand(string val) : TACOperand()
{
	value = val;
}

TemporaryTACOperand::TemporaryTACOperand() : TACOperand()
{
	num = count++;
}

VariableTACOperand::VariableTACOperand(string name) : TACOperand()
{
	this->name = name;
}

STemporaryTACOperand::STemporaryTACOperand() : TACOperand()
{
	num = count++;
}

void ComputeTACStatement::print()
{
	string op;
	switch(type)
	{
		case ADD_COMPUTATION_TYPE:
			op = "+";
			break;
		case SUB_COMPUTATION_TYPE:
			op = "-";
			break;
		case MUL_COMPUTATION_TYPE:
			op = "*";
			break;
		case DIV_COMPUTATION_TYPE:
			op = "/";
			break;
		case MOD_COMPUTATION_TYPE:
			op = "%";
			break;
		case AND_COMPUTATION_TYPE:
			op = "&&";
			break;
		case OR_COMPUTATION_TYPE:
			op = "||";
			break;
		case LT_COMPUTATION_TYPE:
			op = "<";
			break;
		case GT_COMPUTATION_TYPE:
			op = ">";
			break;
		case LTE_COMPUTATION_TYPE:
			op = "<=";
			break;
		case GTE_COMPUTATION_TYPE:
			op = ">=";
			break;
		case EQ_COMPUTATION_TYPE:
			op = "==";
			break;
		case NEQ_COMPUTATION_TYPE:
			op = "!=";
			break;
		case NEG_COMPUTATION_TYPE:
			op = "-";
			break;
		case NOT_COMPUTATION_TYPE:
			op = "!";
			break;
		default:
			assert(false);
	}
	if(right)
		tac_output(result->to_string() + " = " + left->to_string() + " " + op + " " + right->to_string() + "\n");
	else
		tac_output(result->to_string() + " = " + op + " " + left->to_string() + "\n");
}

void GotoTACStatement::print()
{
	tac_output("goto " + label->to_string() + "\n");
}

void IfGotoTACStatement::print()
{
	tac_output("if(" + condition->to_string() + ") goto " + label->to_string() + "\n");
}

void IOTACStatement::print()
{
	if(is_write)
	{
		tac_output("write " + result->to_string() + "\n");
	}
	else
	{
		tac_output("read " + result->to_string() + "\n");
	}
}

void LabelTACStatement::print()
{
	tac_output(label->to_string() + ":\n", false);
}

string DoubleConstantTACOperand::to_string()
{
	string float_str;
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << value;
	float_str = ss.str();
	return float_str;
}

string IntegerConstantTACOperand::to_string()
{
	return std::to_string(value);
}

string LabelTACOperand::to_string()
{
	return "Label" + std::to_string(num);
}

string StringConstantTACOperand::to_string()
{
	return  value;
}

string TemporaryTACOperand::to_string()
{
	return "temp" + std::to_string(num);
}

string VariableTACOperand::to_string()
{
	return name + "_";
}

string STemporaryTACOperand::to_string()
{
	return "stemp" + std::to_string(num);
}

void AssignmentTACStatement::print()
{
	tac_output(result->to_string() + " = " + value->to_string() + "\n");
}
