#include "tac.h"
#include "procedure.h"

extern bool is_rtl_printing_rn;
extern Procedure* current_procedure_rn;

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

CallTACStatement::CallTACStatement(Procedure* proc, vector<TACOperand*> args) : TACStatement(CALL_TAC_STATEMENT)
{
	this->proc = proc;
	this->args = args;
	if(proc->get_return_type() != DTYPE_VOID)
	{
		result = new TemporaryTACOperand(proc->get_return_type());
	}
	else
	{
		result = NULL;
	}
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

ReturnTACStatement::ReturnTACStatement(TACOperand* t) : TACStatement(RETURN_TAC_STATEMENT)
{
	this->value = t;
}

ArrayAccessTACOperand::ArrayAccessTACOperand() : TACOperand()
{
	op_type = ARRAY_ACCESS_TAC_OPERAND;
}

DoubleConstantTACOperand::DoubleConstantTACOperand(double val) : TACOperand()
{
	value = val;
	op_type = DOUBLE_CONSTANT_TAC_OPERAND;
}

IntegerConstantTACOperand::IntegerConstantTACOperand(int val) : TACOperand()
{
	value = val;
	op_type = INTEGER_CONSTANT_TAC_OPERAND;
}

LabelTACOperand::LabelTACOperand() : TACOperand()
{
	num = count++;
	op_type = LABEL_TAC_OPERAND;
}

PointerDereferenceTACOperand::PointerDereferenceTACOperand() : TACOperand()
{
	op_type = POINTER_DEREFERENCE_TAC_OPERAND;
}

StringConstantTACOperand::StringConstantTACOperand(string val) : TACOperand()
{
	value = val;
	if(string_index.find(val) == string_index.end())
	{
		string_index[val] = string_index.size();
	}
	op_type = STRING_CONSTANT_TAC_OPERAND;
}

TemporaryTACOperand::TemporaryTACOperand(st_datatype d) : TACOperand()
{
	num = count++;
	type = d;
	op_type = TEMPORARY_TAC_OPERAND;
}

VariableTACOperand::VariableTACOperand(string name,st_datatype d) : TACOperand()
{
	this->name = name;
	type = d;
	op_type = VARIABLE_TAC_OPERAND;
}

STemporaryTACOperand::STemporaryTACOperand(st_datatype d) : TACOperand()
{
	num = count++;
	type = d;
	op_type = STEMPORARY_TAC_OPERAND;
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
	if(is_rtl_printing_rn)
	{
		return "_str_" + std::to_string(string_index[value]);
	}
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
		switch(value->op_type)
		{
			case DOUBLE_CONSTANT_TAC_OPERAND:
				rtl.push_back(new ILoadfMoveRTLStatement(value->alloted_register,((DoubleConstantTACOperand*)value)->value));
				break;
			case INTEGER_CONSTANT_TAC_OPERAND:
				rtl.push_back(new ILoadMoveRTLStatement(value->alloted_register,((IntegerConstantTACOperand*)value)->value));
				break;
			case STRING_CONSTANT_TAC_OPERAND:
				rtl.push_back(new LoadAddrMoveRTLStatement(value -> alloted_register,value));
				break;
			case TEMPORARY_TAC_OPERAND:
				assert(false);
				break;
			case VARIABLE_TAC_OPERAND:
			case STEMPORARY_TAC_OPERAND:
				rtl.push_back(new LoadMoveRTLStatement(value->alloted_register, value));
				break;
			default:
				assert(false);
		}
	}
	if(result->op_type == VARIABLE_TAC_OPERAND || result->op_type == STEMPORARY_TAC_OPERAND){
		assert(!do_negation);
		rtl.push_back(new StoreMoveRTLStatement(value->alloted_register, result));
	}
	else{
		if(result->alloted_register == -1)
		{
			result->alloted_register = result->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
		}
		if(do_negation)
		{
			rtl.push_back(new ComputeRTLStatement(result->alloted_register,value->alloted_register,-1,NOT_COMPUTATION_TYPE));
			assert(result->get_type() == DTYPE_BOOL);
		}
		else
		{
			rtl.push_back(new RegisterMoveRTLStatement(result->alloted_register,value->alloted_register));
		}
	}

	// rtl.push_back(new RegisterMoveRTLStatement(result->alloted_register,value->alloted_register));
	RTLOperand::free_register(value -> alloted_register);
}

void IOTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	if(!is_write)
	{
		if(result->get_type() == DTYPE_INTEGER)
		{
			rtl.push_back(new ILoadMoveRTLStatement(reg_v0, 5));
			rtl.push_back(new ReadRTLStatement());
			rtl.push_back(new StoreMoveRTLStatement(reg_v0,result));
		}
		else if(result->get_type() == DTYPE_FLOAT)
		{
			rtl.push_back(new ILoadMoveRTLStatement(reg_v0, 7));
			rtl.push_back(new ReadRTLStatement());
			rtl.push_back(new StoreMoveRTLStatement(reg_f0,result));
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
				rtl.push_back(new RegisterMoveRTLStatement(new_reg,reg_v0));
				result -> alloted_register = new_reg;
			}
			rtl.push_back(new ILoadMoveRTLStatement(reg_v0, 1));
			if(result -> alloted_register == -1)
			{
				switch(result -> op_type)
				{
					case INTEGER_CONSTANT_TAC_OPERAND:
						rtl.push_back(new ILoadMoveRTLStatement(reg_a0,((IntegerConstantTACOperand*)result)->value));
						break;
					case TEMPORARY_TAC_OPERAND:
					case STEMPORARY_TAC_OPERAND:
					case VARIABLE_TAC_OPERAND:
						rtl.push_back(new LoadMoveRTLStatement(reg_a0,result));
						break;
					default:
						assert(false);
				}
			}
			else
			{
				assert(result->alloted_register >= 0 && result->alloted_register <= LAST_INT_REGISTER);
				rtl.push_back(new RegisterMoveRTLStatement(reg_a0,result -> alloted_register));
			}
			rtl.push_back(new WriteRTLStatement());
			RTLOperand::free_register(new_reg);
			if(new_reg != reg_v0)
				RTLOperand::free_register(reg_v0);
			if(result->alloted_register != -1)
				RTLOperand::free_register(result -> alloted_register);
		}
		else if(result->get_type() == DTYPE_FLOAT)
		{
			rtl.push_back(new ILoadMoveRTLStatement(reg_v0, 3));
			if(result -> alloted_register == -1)
			{
				switch(result -> op_type)
				{
					case DOUBLE_CONSTANT_TAC_OPERAND:
						rtl.push_back(new ILoadfMoveRTLStatement(reg_f12,((DoubleConstantTACOperand*)result)->value));
						break;
					case TEMPORARY_TAC_OPERAND:
					case STEMPORARY_TAC_OPERAND:
					case VARIABLE_TAC_OPERAND:
						rtl.push_back(new LoadMoveRTLStatement(reg_f12,result));
						break;
					default:
						assert(false);
				}
			}
			else
			{
				assert(result -> alloted_register > LAST_INT_REGISTER && result -> alloted_register <= LAST_FLOAT_REGISTER);
				rtl.push_back(new RegisterMoveRTLStatement(reg_f12,result -> alloted_register));
			}
			rtl.push_back(new WriteRTLStatement());
		}
		else if(result->get_type() == DTYPE_STRING)
		{
			rtl.push_back(new ILoadMoveRTLStatement(reg_v0, 4));
			switch(result -> op_type)
			{
				case STRING_CONSTANT_TAC_OPERAND:
					rtl.push_back(new LoadAddrMoveRTLStatement(reg_a0,result));
					break;
				case TEMPORARY_TAC_OPERAND:
				case STEMPORARY_TAC_OPERAND:
				case VARIABLE_TAC_OPERAND:
					rtl.push_back(new LoadMoveRTLStatement(reg_a0,result));
					break;
				default:
					assert(false);
			}
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
	assert(left->get_type() == DTYPE_FLOAT || left->get_type() == DTYPE_INTEGER || left->get_type() == DTYPE_BOOL);
	if(right)
		assert(right->get_type() == DTYPE_FLOAT || right->get_type() == DTYPE_INTEGER || right->get_type() == DTYPE_BOOL);
	if(left->alloted_register == -1)
	{
		left->alloted_register = left->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
		switch(left->op_type)
		{
			case DOUBLE_CONSTANT_TAC_OPERAND:
				rtl.push_back(new ILoadfMoveRTLStatement(left->alloted_register,((DoubleConstantTACOperand*)left)->value));
				break;
			case INTEGER_CONSTANT_TAC_OPERAND:
				rtl.push_back(new ILoadMoveRTLStatement(left->alloted_register,((IntegerConstantTACOperand*)left)->value));
				break;
			case TEMPORARY_TAC_OPERAND:
				assert(false);
				break;
			case VARIABLE_TAC_OPERAND:
			case STEMPORARY_TAC_OPERAND:
				rtl.push_back(new LoadMoveRTLStatement(left->alloted_register,left));
				break;
			default:
				assert(false);
		}
	}
	if(result->alloted_register == -1)
	{
		result->alloted_register = result->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
	}
	if(right && right->alloted_register == -1)
	{
		right->alloted_register = right->get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
		switch(right->op_type)
		{
			case DOUBLE_CONSTANT_TAC_OPERAND:
				rtl.push_back(new ILoadfMoveRTLStatement(right->alloted_register,((DoubleConstantTACOperand*)right)->value));
				break;
			case INTEGER_CONSTANT_TAC_OPERAND:
				rtl.push_back(new ILoadMoveRTLStatement(right->alloted_register,((IntegerConstantTACOperand*)right)->value));
				break;
			case TEMPORARY_TAC_OPERAND:
				assert(false);
				break;
			case VARIABLE_TAC_OPERAND:
			case STEMPORARY_TAC_OPERAND:
				rtl.push_back(new LoadMoveRTLStatement(right->alloted_register, right));
				break;
			default:
				assert(false);
				break;
		}
	}
	if(left->get_type() == DTYPE_FLOAT)
	{
		bool is_comparison = false;
		bool is_negated = false;
		switch(type)
		{
			case ADD_COMPUTATION_TYPE:
			case SUB_COMPUTATION_TYPE:
			case MUL_COMPUTATION_TYPE:
			case DIV_COMPUTATION_TYPE:
				rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,right ? right->alloted_register : -1, type));
				break;
			
			case GT_COMPUTATION_TYPE:
				rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,right->alloted_register, LTE_COMPUTATION_TYPE));
				is_comparison = true;
				is_negated = true;
				break;
			case GTE_COMPUTATION_TYPE:
				rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,right->alloted_register, LT_COMPUTATION_TYPE));
				is_comparison = true;
				is_negated = true;
				break;
			case NEQ_COMPUTATION_TYPE:
				rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,right->alloted_register, EQ_COMPUTATION_TYPE));
				is_comparison = true;
				is_negated = true;
				break;
			case LT_COMPUTATION_TYPE:
			case LTE_COMPUTATION_TYPE:
			case EQ_COMPUTATION_TYPE:
				rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,right->alloted_register, type));
				is_comparison = true;
				break;
			case NEG_COMPUTATION_TYPE:
				rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,-1, type));
				assert(!right);
				break;
			case NOT_COMPUTATION_TYPE:
				rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,-1, type));
				assert(!right);
				break;
			default:
				assert(false);
				break;
		}
		if(is_comparison)
		{
			int reg = RTLOperand::get_new_int_register();
			int temp = result -> alloted_register;
			result->alloted_register = reg;
			reg = temp;
			rtl.push_back(new ILoadMoveRTLStatement(reg,1));
			rtl.push_back(new RegisterMoveRTLStatement(result -> alloted_register,reg_zero));
			if(is_negated)
			{
				rtl.push_back(new MoveFRTLStatement(result -> alloted_register,reg,0));
			}
			else
			{
				rtl.push_back(new MoveTRTLStatement(result->alloted_register,reg,0));
			}
			RTLOperand::free_register(reg);
		}
	}
	else{
		rtl.push_back(new ComputeRTLStatement(result->alloted_register,left->alloted_register,right ? right->alloted_register : -1, type));
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
	// assert(condition->alloted_register >= 0 && condition->alloted_register <= LAST_INT_REGISTER);
	if(condition->alloted_register == -1)
	{
		condition->alloted_register = RTLOperand::get_new_int_register();
		rtl.push_back(new LoadMoveRTLStatement(condition->alloted_register,condition));
	}
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

void CallTACStatement::print()
{
	if(result)
	{
		tac_output(result->to_string() + " = ");
	}
	tac_output(proc->name + "_(");
	for(int i=0;i<args.size();i++)
	{
		tac_output(args[i]->to_string());
		if(i != args.size()-1)
		{
			tac_output(", ");
		}
	}
	tac_output(")\n");
}

void CallTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	for(int i=args.size()-1;i>=0;i--)
	{
		if(args[i]->alloted_register == -1)
		{
			args[i]->alloted_register = args[i] -> get_type() == DTYPE_FLOAT ? RTLOperand::get_new_float_register() : RTLOperand::get_new_int_register();
			rtl.push_back(new LoadMoveRTLStatement(args[i]->alloted_register,args[i]));
		}
		rtl.push_back(new PushRTLStatement(args[i]->alloted_register));
		RTLOperand::free_register(args[i]->alloted_register);
	}
	rtl.push_back(new CallCFRTLStatement(proc->name));

}

void ReturnTACStatement::print(){
	assert(value);
	tac_output("return " + value->to_string() + "\n");
}

void ReturnTACStatement::genrtl(vector<RTLStatement*> &rtl)
{
	rtl.push_back(new LoadMoveRTLStatement(reg_v1,value));
	rtl.push_back(new ReturnCFRTLStatement());
}
