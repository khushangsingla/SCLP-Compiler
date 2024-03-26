RTLStatement::RTLStatement()
{
}

RTLOperand::RTLOperand()
{
}

ComputeRTLStatement::ComputeRTLStatement() : RTLStatement()
{
}

ControlFlowRTLStatement::ControlFlowRTLStatement() : RTLStatement()
{
}

LabelRTLStatement::LabelRTLStatement() : RTLStatement()
{
}

MoveRTLStatement::MoveRTLStatement() : RTLStatement()
{
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

CallCFRTLStatement::CallCFRTLStatement() : ControlFlowRTLStatement()
{
}

IfGotoCFRTLStatement::IfGotoCFRTLStatement() : ControlFlowRTLStatement()
{
}

GotoCFRTLStatement::GotoCFRTLStatement() : ControlFlowRTLStatement()
{
}

ReturnCFRTLStatement::ReturnCFRTLStatement() : ControlFlowRTLStatement()
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
