#pragma once
#include "utils.h"
class TACOperand;

class RTLStatement
{
	public:
		RTLStatement();
		virtual void print() = 0;
};

#define LAST_INT_REGISTER reg_s7
#define LAST_FLOAT_REGISTER reg_f30

enum int_registers{
	reg_v0,
	reg_t0,
	reg_t1,
	reg_t2,
	reg_t3,
	reg_t4,
	reg_t5,
	reg_t6,
	reg_t7,
	reg_t8,
	reg_t9,
	reg_s0,
	reg_s1,
	reg_s2,
	reg_s3,
	reg_s4,
	reg_s5,
	reg_s6,
	reg_s7
};

enum float_registers{
	reg_f2 = LAST_INT_REGISTER + 1,
	reg_f4,
	reg_f6,
	reg_f8,
	reg_f10,
	reg_f12,
	reg_f14,
	reg_f16,
	reg_f18,
	reg_f20,
	reg_f22,
	reg_f24,
	reg_f26,
	reg_f28,
	reg_f30
};

enum special_registers{
	reg_f0 = LAST_FLOAT_REGISTER + 1,
	reg_a0,
	reg_zero
};

class RTLOperand
{
	public:
		RTLOperand();
		static vector<bool> register_mapping;
		// static void initialize_register_mapping();
		static int get_new_int_register();
		static int get_new_float_register();
		static void free_register(int);
		static int is_reg_allocated(int);
		static string get_reg_name(int);
};

class ComputeRTLStatement : public RTLStatement
{
	private:
		int reg1;
		int reg2;
		int reg_dst;
		computation_type type;
	public:
		ComputeRTLStatement(int, int, int, computation_type);
		void print();
};

class ControlFlowRTLStatement : public RTLStatement
{
	protected:
		TACOperand* target;
	public:
		ControlFlowRTLStatement(TACOperand*);
};

class LabelRTLStatement : public RTLStatement
{
	TACOperand* label;
	public:
		LabelRTLStatement(TACOperand*);
};

class MoveRTLStatement : public RTLStatement
{
	protected:
		int reg;
	public:
		MoveRTLStatement(int);
};

class ILoadMoveRTLStatement : public MoveRTLStatement
{
	private:
		int int_val;
	public:
		ILoadMoveRTLStatement(int, int);
};

class ILoadfMoveRTLStatement : public MoveRTLStatement
{
	private:
		double float_val;
	public:
		ILoadfMoveRTLStatement(int, float);
};

class RegisterMoveRTLStatement : public MoveRTLStatement
{
	private:
		int src_reg;
	public:
		RegisterMoveRTLStatement(int, int);
};

class LoadMoveRTLStatement : public MoveRTLStatement
{
	private:
		TACOperand* src;
	public:
		LoadMoveRTLStatement(int, TACOperand*);
};

class StoreMoveRTLStatement : public MoveRTLStatement
{
	private:
		TACOperand* dst;
	public:
		StoreMoveRTLStatement(int, TACOperand*);
};

class LoadAddrMoveRTLStatement : public MoveRTLStatement
{
	private:
		TACOperand* src;
	public:
		LoadAddrMoveRTLStatement(int, TACOperand*);
};

class NopRTLStatement : public RTLStatement
{
	public:
		NopRTLStatement();
};

class ReadRTLStatement : public RTLStatement
{
	public:
		ReadRTLStatement();
};

class WriteRTLStatement : public RTLStatement
{
	public:
		WriteRTLStatement();
};

class CallCFRTLStatement : public ControlFlowRTLStatement
{
	public:
		CallCFRTLStatement();
};

class IfGotoCFRTLStatement : public ControlFlowRTLStatement
{
	private:
		int condition;
	public:
		IfGotoCFRTLStatement(int, TACOperand*);
};

class GotoCFRTLStatement : public ControlFlowRTLStatement
{
	public:
		GotoCFRTLStatement(TACOperand*);
};

class ReturnCFRTLStatement : public ControlFlowRTLStatement
{
	public:
		ReturnCFRTLStatement();
};

class DoubleConstRTLOperand : public RTLOperand
{
	public:
		DoubleConstRTLOperand();
};

class IntConstRTLOperand : public RTLOperand
{
	public:
		IntConstRTLOperand();
};

class LabelRTLOperand : public RTLOperand
{
	public:
		LabelRTLOperand();
};

class RegisterRTLOperand : public RTLOperand
{
	public:
		RegisterRTLOperand();
};

class StringConstRTLOperand : public RTLOperand
{
	public:
		StringConstRTLOperand();
};

class VariableRTLOperand : public RTLOperand
{
	public:
		VariableRTLOperand();
};
