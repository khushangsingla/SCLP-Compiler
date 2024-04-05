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
	alloted_register = -1;
}

AssignmentTACStatement::AssignmentTACStatement(TACOperand* res,TACOperand* val,bool do_negation) : TACStatement(ASSIGNMENT_TAC_STATEMENT)
{
	result = res;
	value = val;
	this -> do_negation = do_negation;
}

CallTACStatement::CallTACStatement() : TACStatement(CALL_TAC_STATEMENT)
{
}

st_datatype TACOperand::get_type()
{
	return DTYPE_UNKNOWN;
}

ComputeTACStatement::ComputeTACStatement(TACOperand* left,TACOperand* right,computation_type type) : TACStatement(COMPUTE_TAC_STATEMENT)
{
	this->left = left;
	this->right = right;
	this->type = type;
	this->result = new TemporaryTACOperand(left->get_type());
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
	if(string_index.find(val) == string_index.end())
	{
		string_index[val] = string_index.size();
	}
}

TemporaryTACOperand::TemporaryTACOperand(st_datatype d) : TACOperand()
{
	num = count++;
	type = d;
}

VariableTACOperand::VariableTACOperand(string name,st_datatype d) : TACOperand()
{
	this->name = name;
	type = d;
}

STemporaryTACOperand::STemporaryTACOperand(st_datatype d) : TACOperand()
{
	num = count++;
	type = d;
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
	if(do_negation)
		tac_output(result->to_string() + " = !" + value->to_string() + "\n");
	else
		tac_output(result->to_string() + " = " + value->to_string() + "\n");
}

st_datatype DoubleConstantTACOperand::get_type()
{
	return DTYPE_FLOAT;
}

st_datatype IntegerConstantTACOperand::get_type()
{
	return DTYPE_INTEGER;
}

st_datatype StringConstantTACOperand::get_type()
{
	return DTYPE_STRING;
}

st_datatype TemporaryTACOperand::get_type()
{
	return type;
}

st_datatype VariableTACOperand::get_type()
{
	return type;
}

st_datatype STemporaryTACOperand::get_type()
{
	return type;
}

void AssignmentTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	if(value->alloted_register == -1)
	{
		value->alloted_register = value->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
		rtl.push_back(new MoveRTLStatement(value->alloted_register,value));
	}
	rtl.push_back(new MoveRTLStatement(result,value->alloted_register));
	RTLOperand::free_register(value -> alloted_register);
}

void IOTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	if(!is_write)
	{
		if(result->get_type() == DTYPE_INTEGER)
		{
			rtl.push_back(new MoveRTLStatement(reg_v0, new IntegerConstantTACOperand(5)));
			rtl.push_back(new ReadRTLStatement());
			rtl.push_back(new MoveRTLStatement(result,reg_v0));
		}
		else if(result->get_type() == DTYPE_FLOAT)
		{
			rtl.push_back(new MoveRTLStatement(reg_v0, new IntegerConstantTACOperand(7)));
			rtl.push_back(new ReadRTLStatement());
			rtl.push_back(new MoveRTLStatement(result,reg_f0));
		}
		else
		{
			assert(false);
		}
	}
	else
	{
		if(result->get_type() == DTYPE_INTEGER)
		{
			int new_reg = RTLOperand::get_new_int_register();
			if(new_reg != reg_v0)
			{
				rtl.push_back(new MoveRTLStatement(new_reg,reg_v0));
				result -> alloted_register = new_reg;
			}
			rtl.push_back(new MoveRTLStatement(reg_v0, new IntegerConstantTACOperand(1)));
			if(result -> alloted_register == -1)
			{
				rtl.push_back(new MoveRTLStatement(reg_a0,result));
			}
			else
			{
				assert(result->alloted_register >= 0 && result->alloted_register <= LAST_INT_REGISTER);
				rtl.push_back(new MoveRTLStatement(reg_a0,result -> alloted_register));
			}
			rtl.push_back(new WriteRTLStatement());
			RTLOperand::free_register(new_reg);
			if(result->alloted_register != -1)
				RTLOperand::free_register(result -> alloted_register);
		}
		else if(result->get_type() == DTYPE_FLOAT)
		{
			rtl.push_back(new MoveRTLStatement(reg_v0, new IntegerConstantTACOperand(3)));
			if(result -> alloted_register == -1)
			{
				rtl.push_back(new MoveRTLStatement(reg_f12,result));
			}
			else
			{
				assert(result -> alloted_register > LAST_INT_REGISTER && result -> alloted_register <= LAST_FLOAT_REGISTER);
				rtl.push_back(new MoveRTLStatement(reg_f12,result -> alloted_register));
			}
			rtl.push_back(new WriteRTLStatement());
		}
		else if(result->get_type() == DTYPE_STRING)
		{
			rtl.push_back(new MoveRTLStatement(reg_v0, new IntegerConstantTACOperand(4)));
			rtl.push_back(new MoveRTLStatement(reg_a0,result));
			rtl.push_back(new WriteRTLStatement());
		}
		else
		{
			assert(false);
		}
	}
}

void LabelTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	rtl.push_back(new LabelRTLStatement(label));
}

void ComputeTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	assert(left);
	assert(left->get_type() == DTYPE_FLOAT || left->get_type() == DTYPE_INTEGER);
	if(right)
		assert(right->get_type() == DTYPE_FLOAT || right->get_type() == DTYPE_INTEGER);
	if(left->alloted_register == -1)
	{
		left->alloted_register = left->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
		rtl.push_back(new MoveRTLStatement(left->alloted_register,left));
	}
	if(right && right->alloted_register == -1)
	{
		right->alloted_register = right->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
		rtl.push_back(new MoveRTLStatement(right->alloted_register,right));
	}
	if(result->alloted_register == -1)
	{
		result->alloted_register = result->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
	}
	rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,right ? right->alloted_register : -1, type));
	if(left->value->get_type() == DTYPE_FLOAT)
	{
		
	}
	RTLOperand::free_register(left -> alloted_register);
	if(right)
		RTLOperand::free_register(right -> alloted_register);
}

void GotoTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	rtl.push_back(new GotoCFRTLStatement(label));
}

void IfGotoTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	assert(condition);
	assert(condition -> get_type() == DTYPE_BOOL);
	assert(condition->alloted_register >= 0 && condition->alloted_register <= LAST_INT_REGISTER);
	rtl.push_back(new IfGotoCFRTLStatement(condition->alloted_register,label));
	RTLOperand::free_register(condition -> alloted_register);
}

map<string,int> StringConstantTACOperand::string_index = map<string,int>();

void TACOperand::set_type(st_datatype t)
{
	assert(false);
}

void TemporaryTACOperand::set_type(st_datatype t)
{
	type = t;
}

void VariableTACOperand::set_type(st_datatype t)
{
	type = t;
}

void STemporaryTACOperand::set_type(st_datatype t)
{
	type = t;
}
