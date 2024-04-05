#include "rtl.h"

RTLStatement::RTLStatement()
{
}

RTLOperand::RTLOperand()
{
}

ComputeRTLStatement::ComputeRTLStatement(int result, int left, int right, computation_type type) : RTLStatement()
{
	reg1 = left;
	reg2 = right;
	reg_dst = result;
	this->type = type;
}

ControlFlowRTLStatement::ControlFlowRTLStatement(TACOperand* target) : RTLStatement()
{
	this->target = target;
}

LabelRTLStatement::LabelRTLStatement(TACOperand* l) : RTLStatement()
{
	label = l;
}

MoveRTLStatement::MoveRTLStatement(int reg, TACOperand* op) : RTLStatement()
{
	this->reg = reg;
	this->op = op;
	this->is_store = 0;
	reg_dst = -1;
}

MoveRTLStatement::MoveRTLStatement(TACOperand* op, int reg) : RTLStatement()
{
	this->reg = reg;
	this->op = op;
	this->is_store = 1;
	reg_dst = -1;
}

MoveRTLStatement::MoveRTLStatement(int reg1,int reg2) : RTLStatement()
{
	this->reg = reg2;
	this->reg_dst = reg1;
	this->is_store = -1;
	op = NULL;
}

NopRTLStatement::NopRTLStatement() : RTLStatement()
{
}

ReadRTLStatement::ReadRTLStatement() : RTLStatement()
{
}

WriteRTLStatement::WriteRTLStatement() : RTLStatement()
{
}

CallCFRTLStatement::CallCFRTLStatement() : ControlFlowRTLStatement(NULL)
{
}

IfGotoCFRTLStatement::IfGotoCFRTLStatement(int reg, TACOperand* target) : ControlFlowRTLStatement(target)
{
	this->condition = reg;
}

GotoCFRTLStatement::GotoCFRTLStatement(TACOperand* target) : ControlFlowRTLStatement(target)
{
}

ReturnCFRTLStatement::ReturnCFRTLStatement() : ControlFlowRTLStatement(NULL)
{
}

DoubleConstRTLOperand::DoubleConstRTLOperand() : RTLOperand()
{
}

IntConstRTLOperand::IntConstRTLOperand() : RTLOperand()
{
}

LabelRTLOperand::LabelRTLOperand() : RTLOperand()
{
}

RegisterRTLOperand::RegisterRTLOperand() : RTLOperand()
{
}

StringConstRTLOperand::StringConstRTLOperand() : RTLOperand()
{
}

VariableRTLOperand::VariableRTLOperand() : RTLOperand()
{
}

int RTLOperand::get_new_int_register()
{
	for(int i=0;i<=LAST_INT_REGISTER;i++)
	{
		if(!register_mapping[i])
		{
			register_mapping[i] = true;
			return i;
		}
	}
	my_exit(1,"int register finis\n");
	return -1;
}

int RTLOperand::get_new_float_register()
{
	for(int i=LAST_INT_REGISTER+1;i<=LAST_FLOAT_REGISTER;i++)
	{
		if(!register_mapping[i])
		{
			register_mapping[i] = true;
			return i;
		}
	}
	my_exit(1,"int register finis\n");
	return -1;
}

void RTLOperand::free_register(int num)
{
	assert(num >= 0 && num <= LAST_FLOAT_REGISTER);
	assert(register_mapping[num]);
	register_mapping[num] = false;
}

int RTLOperand::is_reg_allocated(int num)
{
	assert(num >= 0 && num <= LAST_FLOAT_REGISTER);
	return register_mapping[num];
}

// void RTLOperand::initialize_register_mapping()
// {
// 	for(int i=0;i<=LAST_FLOAT_REGISTER;i++)
// 	{
// 		register_mapping.push_back(false);
// 	}
// }

vector<bool> RTLOperand::register_mapping = vector<bool>(LAST_FLOAT_REGISTER+1,false);

void ComputeRTLStatement::print()
{
	assert(reg1 >= 0 && reg1 <= LAST_FLOAT_REGISTER);
	assert(reg_dst >= 0 && reg_dst <= LAST_FLOAT_REGISTER);
	if(reg1 <= LAST_INT_REGISTER)	assert(reg_dst <= LAST_INT_REGISTER);
	else assert(reg_dst > LAST_INT_REGISTER);

	bool is_float = reg_dst > LAST_INT_REGISTER;

	switch(type){
		case ADD_COMPUTATION_TYPE:
			if(is_float)	rtl_output("add.d:\t");
			else	rtl_output("add:\t");
			break;
		case SUB_COMPUTATION_TYPE:
			if(is_float)	rtl_output("sub.d:\t");
			else	rtl_output("sub:\t");
			break;
		case MUL_COMPUTATION_TYPE:
			if(is_float)	rtl_output("mul.d:\t");
			else	rtl_output("mul:\t");
			break;
		case DIV_COMPUTATION_TYPE:
			if(is_float)	rtl_output("div.d:\t");
			else	rtl_output("div:\t");
			break;
		case EQ_COMPUTATION_TYPE:
			if(is_float)	rtl_output("seq.d:\t");
			else	rtl_output("seq:\t");
			break;
		case NEQ_COMPUTATION_TYPE:
			if(is_float)	rtl_output("sne.d:\t");
			else	rtl_output("sne:\t");
			break;
		case LT_COMPUTATION_TYPE:
			if(is_float)	rtl_output("slt.d:\t");
			else	rtl_output("slt:\t");
			break;
		case GT_COMPUTATION_TYPE:
			if(is_float)	rtl_output("sgt.d:\t");
			else	rtl_output("sgt:\t");
			break;
		case LTE_COMPUTATION_TYPE:
			if(is_float)	rtl_output("sle.d:\t");
			else	rtl_output("sle:\t");
			break;
		case GTE_COMPUTATION_TYPE:
			if(is_float)	rtl_output("sge.d:\t");
			else	rtl_output("sge:\t");
			break;
		case AND_COMPUTATION_TYPE:
			rtl_output("and:\t");
			break; 
		case OR_COMPUTATION_TYPE:
			rtl_output("or:\t");
			break;
		case NOT_COMPUTATION_TYPE:
			rtl_output("not:\t");
			break;

	}
}
