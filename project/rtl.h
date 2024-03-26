class RTLStatement
{
	public:
		RTLStatement();
};

class RTLOperand
{
	public:
		RTLOperand();
};

class ComputeRTLStatement : public RTLStatement
{
	public:
		ComputeRTLStatement();
};

class ControlFlowRTLStatement : public RTLStatement
{
	public:
		ControlFlowRTLStatement();
};

class LabelRTLStatement : public RTLStatement
{
	public:
		LabelRTLStatement();
};

class MoveRTLStatement : public RTLStatement
{
	public:
		MoveRTLStatement();
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
	public:
		IfGotoCFRTLStatement();
};

class GotoCFRTLStatement : public ControlFlowRTLStatement
{
	public:
		GotoCFRTLStatement();
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
