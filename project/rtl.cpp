#include "rtl.h"
#include "procedure.h"

extern Program* only_program_rn;
extern Procedure* current_procedure_rn;

RTLStatement::RTLStatement()
{
}

RTLOperand::RTLOperand()
{
}

string RTLOperand::get_reg_name(int reg)
{
	switch(reg)
	{
		case reg_v0:
			return "v0";
		case reg_v1:
			return "v1";
		case reg_t0:
			return "t0";
		case reg_t1:
			return "t1";
		case reg_t2:
			return "t2";
		case reg_t3:
			return "t3";
		case reg_t4:
			return "t4";
		case reg_t5:
			return "t5";
		case reg_t6:
			return "t6";
		case reg_t7:
			return "t7";
		case reg_t8:
			return "t8";
		case reg_t9:
			return "t9";
		case reg_s0:
			return "s0";
		case reg_s1:
			return "s1";
		case reg_s2:
			return "s2";
		case reg_s3:
			return "s3";
		case reg_s4:
			return "s4";
		case reg_s5:
			return "s5";
		case reg_s6:
			return "s6";
		case reg_s7:
			return "s7";
		case reg_f0:
			return "f0";
		case reg_f2:
			return "f2";
		case reg_f4:
			return "f4";
		case reg_f6:
			return "f6";
		case reg_f8:
			return "f8";
		case reg_f10:
			return "f10";
		case reg_f12:
			return "f12";
		case reg_f14:
			return "f14";
		case reg_f16:
			return "f16";
		case reg_f18:
			return "f18";
		case reg_f20:
			return "f20";
		case reg_f22:
			return "f22";
		case reg_f24:
			return "f24";
		case reg_f26:
			return "f26";
		case reg_f28:
			return "f28";
		case reg_f30:
			return "f30";
		case reg_a0:
			return "a0";
		case reg_zero:
			return "zero";
		case reg_ra:
			return "ra";
		case reg_sp:
			return "sp";
		case reg_fp:
			return "fp";
		default:
			asm("int3");
			assert(false);
	}
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

MoveRTLStatement::MoveRTLStatement(int reg) : RTLStatement()
{
	this->reg = reg;
}

ILoadMoveRTLStatement::ILoadMoveRTLStatement(int reg, int val) : MoveRTLStatement(reg)
{
	int_val = val;
}

ILoadfMoveRTLStatement::ILoadfMoveRTLStatement(int reg, double val) : MoveRTLStatement(reg)
{
	float_val = val;
}

RegisterMoveRTLStatement::RegisterMoveRTLStatement(int dst, int src) : MoveRTLStatement(dst)
{
	src_reg = src;
}

LoadMoveRTLStatement::LoadMoveRTLStatement(int reg, TACOperand* var) : MoveRTLStatement(reg)
{
	src = var;
}

StoreMoveRTLStatement::StoreMoveRTLStatement(int reg, TACOperand* var) : MoveRTLStatement(reg)
{
	dst = var;
}

LoadAddrMoveRTLStatement::LoadAddrMoveRTLStatement(int reg, TACOperand* var) : MoveRTLStatement(reg)
{
	src = var;
}

MoveFRTLStatement::MoveFRTLStatement(int reg, int regop, int num) : MoveRTLStatement(reg)
{
	this->regop = regop;
	this->num = num;
}

MoveTRTLStatement::MoveTRTLStatement(int reg, int regop, int num) : MoveRTLStatement(reg)
{
	this->regop = regop;
	this->num = num;
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

CallCFRTLStatement::CallCFRTLStatement(string name, st_datatype ret) : ControlFlowRTLStatement(NULL)
{
	arg = name;
	ret_type = ret;
}

IfGotoCFRTLStatement::IfGotoCFRTLStatement(int reg, TACOperand* target) : ControlFlowRTLStatement(target)
{
	this->condition = reg;
}

GotoCFRTLStatement::GotoCFRTLStatement(TACOperand* target) : ControlFlowRTLStatement(target)
{
}

ReturnCFRTLStatement::ReturnCFRTLStatement(st_datatype t) : ControlFlowRTLStatement(NULL)
{
	ret_type = t;
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
	// assert(register_mapping[num]);
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
	// if(reg1 <= LAST_INT_REGISTER)	assert(reg_dst <= LAST_INT_REGISTER);
	// else assert(reg_dst > LAST_INT_REGISTER);

	bool is_float = reg1 > LAST_INT_REGISTER;

	bool is_arrow = false;
	switch(type){
		case ADD_COMPUTATION_TYPE:
			if(is_float)	rtl_output("add.d:\t");
			else	rtl_output("add:\t");
			is_arrow = true;
			break;
		case SUB_COMPUTATION_TYPE:
			if(is_float)	rtl_output("sub.d:\t");
			else	rtl_output("sub:\t");
			is_arrow = true;
			break;
		case MUL_COMPUTATION_TYPE:
			if(is_float)	rtl_output("mul.d:\t");
			else	rtl_output("mul:\t");
			is_arrow = true;
			break;
		case DIV_COMPUTATION_TYPE:
			if(is_float)	rtl_output("div.d:\t");
			else	rtl_output("div:\t");
			is_arrow = true;
			break;
		case EQ_COMPUTATION_TYPE:
			if(is_float)	rtl_output("seq.d:\t");
			else	rtl_output("seq:\t");
			// is_arrow = true;
			break;
		case NEQ_COMPUTATION_TYPE:
			if(is_float)	rtl_output("sne.d:\t");
			else	rtl_output("sne:\t");
			is_arrow = true;
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
			is_arrow = true;
			break; 
		case OR_COMPUTATION_TYPE:
			rtl_output("or:\t");
			is_arrow = true;
			break;
		case NOT_COMPUTATION_TYPE:
			rtl_output("not:\t");
			is_arrow = true;
			break;
		case NEG_COMPUTATION_TYPE:
			if(is_float)	rtl_output("uminus.d:\t");
			else	rtl_output("uminus:\t");
			is_arrow = true;
			break;
		default:
			assert(false);
	}

	if(!is_float || is_arrow)
	{
		rtl_output(RTLOperand::get_reg_name(reg_dst) + " <- ");
	}

	if(reg2 == -1)
	{
		rtl_output(RTLOperand::get_reg_name(reg1));
	}
	else
	{
		rtl_output(RTLOperand::get_reg_name(reg1) + ", " + RTLOperand::get_reg_name(reg2));
	}
}

void ComputeRTLStatement::printasm()
{
	assert(reg1 >= 0 && reg1 <= LAST_FLOAT_REGISTER);
	assert(reg_dst >= 0 && reg_dst <= LAST_FLOAT_REGISTER);
	// if(reg1 <= LAST_INT_REGISTER)	assert(reg_dst <= LAST_INT_REGISTER);
	// else assert(reg_dst > LAST_INT_REGISTER);

	bool is_float = reg1 > LAST_INT_REGISTER;

	bool is_arrow = false;
	switch(type){
		case ADD_COMPUTATION_TYPE:
			if(is_float)	asm_output("add.d ");
			else	asm_output("add ");
			is_arrow = true;
			break;
		case SUB_COMPUTATION_TYPE:
			if(is_float)	asm_output("sub.d ");
			else	asm_output("sub ");
			is_arrow = true;
			break;
		case MUL_COMPUTATION_TYPE:
			if(is_float)	asm_output("mul.d ");
			else	asm_output("mul ");
			is_arrow = true;
			break;
		case DIV_COMPUTATION_TYPE:
			if(is_float)	asm_output("div.d ");
			else	asm_output("div ");
			is_arrow = true;
			break;
		case EQ_COMPUTATION_TYPE:
			if(is_float)	asm_output("c.eq.d ");
			else	asm_output("seq ");
			// is_arrow = true;
			break;
		case NEQ_COMPUTATION_TYPE:
			if(is_float)	assert(1);
			else	asm_output("sne ");
			is_arrow = true;
			break;
		case LT_COMPUTATION_TYPE:
			if(is_float)	asm_output("c.lt.d ");
			else	asm_output("slt ");
			break;
		case GT_COMPUTATION_TYPE:
			if(is_float)	assert(1);
			else	asm_output("sgt ");
			break;
		case LTE_COMPUTATION_TYPE:
			if(is_float)	asm_output("c.le.d ");
			else	asm_output("sle ");
			break;
		case GTE_COMPUTATION_TYPE:
			if(is_float)	assert(1);
			else	asm_output("sge ");
			break;
		case AND_COMPUTATION_TYPE:
			asm_output("and ");
			is_arrow = true;
			break; 
		case OR_COMPUTATION_TYPE:
			asm_output("or ");
			is_arrow = true;
			break;
		case NOT_COMPUTATION_TYPE:
			asm_output("xori ");
			is_arrow = true;
			break;
		case NEG_COMPUTATION_TYPE:
			if(is_float)	asm_output("neg.d ");
			else	asm_output("neg ");
			is_arrow = true;
			break;
		default:
			assert(false);
	}

	if(!is_float || is_arrow)
	{
		asm_output("$" + RTLOperand::get_reg_name(reg_dst) + ", ");
	}

	if(reg2 == -1)
	{
		asm_output("$" + RTLOperand::get_reg_name(reg1));
	}
	else
	{
		asm_output("$" + RTLOperand::get_reg_name(reg1) + ", $" + RTLOperand::get_reg_name(reg2));
	}
	if( type == NOT_COMPUTATION_TYPE)
	{
		asm_output(", 1");
	}
}
void ILoadMoveRTLStatement::print()
{
	rtl_output("iLoad:\t" + RTLOperand::get_reg_name(reg) + " <- " + to_string(int_val));
}

void ILoadMoveRTLStatement::printasm()
{
	asm_output("li $" + RTLOperand::get_reg_name(reg) + ", " + to_string(int_val));
}

void ILoadfMoveRTLStatement::print()
{
	string float_str;
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << float_val;
	float_str = ss.str();
	rtl_output("iLoad.d:\t" + RTLOperand::get_reg_name(reg) + " <- " + float_str);
}

void ILoadfMoveRTLStatement::printasm()
{
	string float_str;
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << float_val;
	float_str = ss.str();
	asm_output("li.d $" + RTLOperand::get_reg_name(reg) + ", " + float_str);
}

void RegisterMoveRTLStatement::print()
{
	if(reg <= LAST_INT_REGISTER || reg > LAST_FLOAT_REGISTER)
	{
		rtl_output("move:\t" + RTLOperand::get_reg_name(reg) + " <- " + RTLOperand::get_reg_name(src_reg));
	}
	else
	{
		rtl_output("move.d:\t" + RTLOperand::get_reg_name(reg) + " <- " + RTLOperand::get_reg_name(src_reg));
	}
	// rtl_output("move:\t" + RTLOperand::get_reg_name(reg) + " <- " + RTLOperand::get_reg_name(src_reg));
}

void RegisterMoveRTLStatement::printasm()
{
	if(reg <= LAST_INT_REGISTER || reg > LAST_FLOAT_REGISTER)
	{
		asm_output("move $" + RTLOperand::get_reg_name(reg) + ", $" + RTLOperand::get_reg_name(src_reg));
	}
	else
	{
		asm_output("mov.d $" + RTLOperand::get_reg_name(reg) + ", $" + RTLOperand::get_reg_name(src_reg));
	}
	// rtl_output("move:\t" + RTLOperand::get_reg_name(reg) + " <- " + RTLOperand::get_reg_name(src_reg));
}

void LoadMoveRTLStatement::print()
{
	if(src->get_type() != DTYPE_FLOAT)
	{
		rtl_output("load:\t" + RTLOperand::get_reg_name(reg) + " <- " + src->to_string());
	}
	else
	{
		rtl_output("load.d:\t" + RTLOperand::get_reg_name(reg) + " <- " + src->to_string());
	}
}

void LoadMoveRTLStatement::printasm()
{
	if(src->get_type() != DTYPE_FLOAT)
	{
		asm_output("lw $" + RTLOperand::get_reg_name(reg) + ", " + print_offset_reg(src));
	}
	else
	{
		asm_output("l.d $" + RTLOperand::get_reg_name(reg) + ", " + print_offset_reg(src));
	}
}

void StoreMoveRTLStatement::print()
{
	if(dst->get_type() != DTYPE_FLOAT)
	{
		rtl_output("store:\t" + dst->to_string() + " <- " + RTLOperand::get_reg_name(reg));
	}
	else
	{
		rtl_output("store.d:\t" + dst->to_string() + " <- " + RTLOperand::get_reg_name(reg));
	}
}

void StoreMoveRTLStatement::printasm()
{
	if(dst->get_type() != DTYPE_FLOAT)
	{
		asm_output("sw $" + RTLOperand::get_reg_name(reg) + ", " + print_offset_reg(dst));
	}
	else
	{
		asm_output("s.d $" + RTLOperand::get_reg_name(reg) + ", " + print_offset_reg(dst));
	}
}

void LoadAddrMoveRTLStatement::print()
{
	rtl_output("load_addr:\t" + RTLOperand::get_reg_name(reg) + " <- " + src->to_string());
}

void LoadAddrMoveRTLStatement::printasm()
{
	asm_output("la $" + RTLOperand::get_reg_name(reg) + ", " + src->to_string());
}

void MoveFRTLStatement::print()
{
	rtl_output("movf:\t" + RTLOperand::get_reg_name(reg) + " <- " + RTLOperand::get_reg_name(regop) + " , " + to_string(num));
}

void MoveFRTLStatement::printasm()
{
	asm_output("movf $" + RTLOperand::get_reg_name(reg) + ", $" + RTLOperand::get_reg_name(regop) + ", " + to_string(num));
}

void MoveTRTLStatement::print()
{
	rtl_output("movt:\t" + RTLOperand::get_reg_name(reg) + " <- " + RTLOperand::get_reg_name(regop) + " , " + to_string(num));
}

void MoveTRTLStatement::printasm()
{
	asm_output("movt $" + RTLOperand::get_reg_name(reg) + ", $" + RTLOperand::get_reg_name(regop) + " , " + to_string(num));
}

void ReadRTLStatement::print()
{
	rtl_output("read\t");
}

void WriteRTLStatement::print()
{
	rtl_output("write\t");
}

void ReadRTLStatement::printasm()
{
	asm_output("syscall");
}

void WriteRTLStatement::printasm()
{
	asm_output("syscall");
}

void GotoCFRTLStatement::print()
{
	rtl_output("goto:\t" + target->to_string());
}

void GotoCFRTLStatement::printasm()
{
	asm_output("j " + target->to_string());
}

void IfGotoCFRTLStatement::print()
{
	rtl_output("bgtz:\t" + RTLOperand::get_reg_name(condition) + ", " + target->to_string());
}

void IfGotoCFRTLStatement::printasm()
{
	asm_output("bgtz $" + RTLOperand::get_reg_name(condition) + ", " + target->to_string());
}

void LabelRTLStatement::print()
{
	rtl_output(label->to_string() + ":", false);
}

void LabelRTLStatement::printasm()
{
	asm_output(label->to_string() + ":", false);
}

void ReturnCFRTLStatement::print()
{
	if(ret_type == DTYPE_FLOAT)
		rtl_output("return\tf0\n");
	else if(ret_type == DTYPE_VOID)
		rtl_output("return\n");
	else
		rtl_output("return\tv1\n");
}

void ReturnCFRTLStatement::printasm()
{
	asm_output("j epilogue_" + current_procedure_rn->name);
	if(current_procedure_rn -> name != "main")
	{
		asm_output("_",false);
	}
}

PushRTLStatement::PushRTLStatement(int reg) : RTLStatement()
{
	this->reg = reg;
}

PopRTLStatement::PopRTLStatement(st_datatype dt) : RTLStatement()
{
	this->dt = dt;
}

void PushRTLStatement::print()
{
	rtl_output("push:\t" + RTLOperand::get_reg_name(reg) );
}

void PushRTLStatement::printasm()
{
	if(reg <= LAST_INT_REGISTER || reg > LAST_FLOAT_REGISTER)
		asm_output("sw $" + RTLOperand::get_reg_name(reg) + ", 0($sp)");
	else
		asm_output("s.d $" + RTLOperand::get_reg_name(reg) + ", -4($sp)");
	asm_output("\n");
	if(reg <= LAST_INT_REGISTER || reg > LAST_FLOAT_REGISTER)
		asm_output("sub $sp, $sp, 4");
	else
		asm_output("sub $sp, $sp, 8");
}

void PopRTLStatement::print()
{
	rtl_output("pop");
}

void PopRTLStatement::printasm()
{
	if(dt == DTYPE_FLOAT)
		asm_output("add $sp, $sp, 8");
	else
		asm_output("add $sp, $sp, 4");
}

void CallCFRTLStatement::print()
{
	if(ret_type == DTYPE_VOID)
		rtl_output("call " + arg);
	else if(ret_type == DTYPE_FLOAT)
		rtl_output("f0 = call " + arg);
	else
		rtl_output("v1 = call " + arg);
	if(strcmp(arg.c_str(), "main"))
	{
		rtl_output("_",false);
	}
}

void CallCFRTLStatement::printasm()
{
	asm_output("jal " + arg);
	if(strcmp(arg.c_str(), "main"))
	{
		asm_output("_",false);
	}
}
