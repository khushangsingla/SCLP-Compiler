#include <cassert>
#include "procedure.h"
#include "ast.h"

extern string function_being_checked_for_ast_rn;
extern bool return_statement_present_in_function_being_checked_for_ast_rn;
extern Procedure* current_procedure_rn;

AST::AST(ast_type type)
{
	this->type = type;
}

ExpressionAST::ExpressionAST(ast_type type) : AST(type)
{
}

ExpressionAST::ExpressionAST(ast_type type, st_datatype dt) : AST(type)
{
	dtype = dt;
}

StatementAST::StatementAST(ast_type t) : AST(t)
{
}

BaseExpressionAST::BaseExpressionAST(ast_type t) : ExpressionAST(t)
{
}

BaseExpressionAST::BaseExpressionAST(ast_type t, st_datatype dt) : ExpressionAST(t, dt)
{
}

UnaryExpressionAST::UnaryExpressionAST(ast_type t,AST* ch) : ExpressionAST(t)
{
	this -> operand = ch;
	dtype = DTYPE_UNKNOWN;
}

BinaryExpressionAST::BinaryExpressionAST(ast_type t, AST* left, AST* right) : ExpressionAST(t)
{
	setLeftChild(left);
	setRightChild(right);
	dtype = DTYPE_UNKNOWN;
}

void BinaryExpressionAST::setLeftChild(AST* ast)
{
	left = ast;
}

void BinaryExpressionAST::setRightChild(AST* ast)
{
	right = ast;
}

TernaryExpressionAST::TernaryExpressionAST(ast_type t,AST* l, AST* m, AST* r) : ExpressionAST(t)
{
	left = l;
	mid = m;
	right = r;
	dtype = DTYPE_UNKNOWN;
}

FunctionCallAST::FunctionCallAST(char* name, vector<AST*> *vec) : BaseExpressionAST(FUNCTION_CALL_AST)
{
	this->name = name;
	this->arguments = *vec;
}

int FunctionCallAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(fns.find(name) == fns.end())	return -1;
	proc = fns[name];
	// if(proc -> is_proc_valid(vars,fns) != 0)	return -1;
	if(arguments.size() != proc -> get_param_list_size())	return -1;
	for(int i=0;i<arguments.size();i++)
	{
		if(arguments[i] -> is_valid(vars,fns) != 0)	return -1;
		if(((ExpressionAST*)arguments[i]) -> dtype != proc -> get_arg_type(i))	return -1;
	}
	dtype = proc -> get_return_type();
	return 0;
}

void FunctionCallAST::print(string prefix)
{
	if(name != "main")
		ast_output("\n" + prefix + "FN CALL: " + name + "_ (");
	else
		ast_output("\n" + prefix + "FN CALL: " + name + " (");
	for(int i=0;i<arguments.size();i++)
	{
		ast_output("\n");
		ast_output(prefix + "  ");
		arguments[i] -> print(prefix + "  ");
	}
	ast_output(")");
}

FunctionStatementAST::FunctionStatementAST(AST* fn) : StatementAST(FUNCTION_STATEMENT_AST)
{
	this->fn = fn;
}

int FunctionStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(fn -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)fn) -> dtype != DTYPE_VOID)	return -1;
	return 0;
}

void FunctionStatementAST::print(string prefix)
{
	fn -> print(prefix );
}

NameExpressionAST::NameExpressionAST(char* name) : BaseExpressionAST(NAME_EXPRESSION_AST)
{
	/* TODO */
	/* Convert string name to symbol* */
	this->name = name;
}

IntegerExpressionAST::IntegerExpressionAST(char* val) : BaseExpressionAST(INTEGER_EXPRESSION_AST, DTYPE_INTEGER)
{
	this->val = atoi(val);
}

FloatExpressionAST::FloatExpressionAST(char* val) : BaseExpressionAST(FLOAT_EXPRESSION_AST, DTYPE_FLOAT)
{
	this->val = atof(val);
}

StringExpressionAST::StringExpressionAST(char* val) : BaseExpressionAST(STRING_EXPRESSION_AST, DTYPE_STRING)
{
	this->val = val;
}

AddressExpressionAST::AddressExpressionAST(AST* t) : UnaryExpressionAST(ADDRESS_EXPRESSION_AST,t)
{
}

PointerDereferenceExpressionAST::PointerDereferenceExpressionAST(AST* t) : UnaryExpressionAST(POINTER_DEREFERENCE_EXPRESSION_AST,t)
{
}

UMinusExpressionAST::UMinusExpressionAST(AST* t) : UnaryExpressionAST(UMINUS_EXPRESSION_AST,t)
{
}

ArrayAccessExpressionAST::ArrayAccessExpressionAST(AST* left,AST* right) : BinaryExpressionAST(ARRAY_ACCESS_EXPRESSION_AST,left,right)
{
}

BooleanExpressionAST::BooleanExpressionAST(AST* left,AST* right,bool_type type) : BinaryExpressionAST(BOOLEAN_EXPRESSION_AST,left,right)
{
	this->type = type;
}

DivisionExpressionAST::DivisionExpressionAST(AST* left,AST* right) : BinaryExpressionAST(DIVISION_EXPRESSION_AST,left,right)
{
}

FieldAccessExpressionAST::FieldAccessExpressionAST(AST* left,AST* right) : BinaryExpressionAST(FIELD_ACCESS_EXPRESSION_AST,left,right)
{
}

MinusExpressionAST::MinusExpressionAST(AST* left,AST* right) : BinaryExpressionAST(MINUS_EXPRESSION_AST,left,right)
{
}

MultiplicationExpressionAST::MultiplicationExpressionAST(AST* left, AST *right) : BinaryExpressionAST(MULTIPLICATION_EXPRESSION_AST,left,right)
{
}

PlusExpressionAST::PlusExpressionAST(AST* left,AST* right) : BinaryExpressionAST(PLUS_EXPRESSION_AST,left,right)
{
}

RelationalExpressionAST::RelationalExpressionAST(AST* left,AST* right,relop op) : BinaryExpressionAST(RELATIONAL_EXPRESSION_AST,left,right)
{
	this->opn = op;
}

ConditionalExpressionAST::ConditionalExpressionAST(AST* a,AST* b,AST* c) : TernaryExpressionAST(CONDITIONAL_EXPRESSION_AST,a,b,c)
{
}

AssignmentStatementAST::AssignmentStatementAST(AST* l, AST* r) : StatementAST(ASSIGNMENT_STATEMENT_AST)
{
	lhs = l;
	rhs = r;
}

IterationStatementAST::IterationStatementAST(AST* condition, AST* body, bool is_do_while) : StatementAST(ITERATION_STATEMENT_AST)
{
	this->condition = condition;
	this->body = body;
	this->is_do_while = is_do_while;
}

ReadStatementAST::ReadStatementAST(AST* opd) : StatementAST(READ_STATEMENT_AST)
{
	this->opd = opd;
}

PrintStatementAST::PrintStatementAST(AST* opd) : StatementAST(PRINT_STATEMENT_AST)
{
	this->opd = opd;
}

ReturnStatementAST::ReturnStatementAST(AST* opd) : StatementAST(RETURN_STATEMENT_AST)
{
	this->opd = opd;
}

int ReturnStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	return_statement_present_in_function_being_checked_for_ast_rn = true;
	if(opd -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)opd) -> dtype != fns[function_being_checked_for_ast_rn] -> get_return_type())	return -1;
	return 0;
}

void ReturnStatementAST::print(string prefix)
{
	ast_output("\n" + prefix + "Return: ");
	opd -> print(prefix + "  ");
}

SelectionStatementAST::SelectionStatementAST(AST* cond, AST* ifpart, AST* elsepart) : StatementAST(SELECTION_STATEMENT_AST)
{
	this->cond = cond;
	this->ifpart = ifpart;
	this->elsepart = elsepart;
}

SequenceStatementAST::SequenceStatementAST(vector<AST*> s) : StatementAST(SEQUENCE_STATEMENT_AST)
{
	this->statements = s;
}

SequenceStatementAST::SequenceStatementAST(AST* a) : StatementAST(SEQUENCE_STATEMENT_AST)
{
	this->statements.push_back(a);
}

NotBoolExpressionAST::NotBoolExpressionAST(AST* t) : UnaryExpressionAST(NOT_BOOL_EXPRESSION_AST,t)
{
}

int NameExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(vars->is_variable_present(name) != 0)	return -1;
	if(fns.find(name) != fns.end())	return -1;
	dtype = vars->get_datatype(name);
	return 0;
}

int IntegerExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	return 0;
}

int FloatExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	return 0;
}

int StringExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	return 0;
}

int UMinusExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(operand->is_valid(vars,fns) != 0)	return -1;
	dtype = ((ExpressionAST*)operand)->dtype;
	return 0;
}

int BooleanExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left) -> dtype != DTYPE_BOOL || ((ExpressionAST*)right) -> dtype != DTYPE_BOOL)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

int BinaryExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left) -> dtype != ((ExpressionAST*)right) -> dtype)	return -1;
	if(((ExpressionAST*)left) -> dtype != DTYPE_INTEGER && ((ExpressionAST*)left) -> dtype != DTYPE_FLOAT)	return -1;
	dtype = ((ExpressionAST*)left) -> dtype;
	return 0;
}

int RelationalExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left -> is_valid(vars,fns) != 0)	return -1;
	if(right -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left) ->dtype != ((ExpressionAST*)right) ->dtype)	return -1;
	if(((ExpressionAST*)left) ->dtype != DTYPE_INTEGER && ((ExpressionAST*)left) ->dtype != DTYPE_FLOAT)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

int ConditionalExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(left->is_valid(vars,fns) != 0)	return -1;
	if(mid->is_valid(vars,fns) != 0)	return -1;
	if(right->is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)left)->dtype != DTYPE_BOOL)	return -1;
	if(((ExpressionAST*)mid)->dtype != ((ExpressionAST*)right) -> dtype)	return -1;
	dtype = ((ExpressionAST*)mid)->dtype;
	return 0;
}

int AssignmentStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(((ExpressionAST*)lhs) -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)rhs) -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)lhs) -> dtype != ((ExpressionAST*)rhs) -> dtype)	return -1;
	return 0;
}

int ReadStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(opd -> is_valid(vars,fns) != 0)	return -1;
	if(opd -> type != NAME_EXPRESSION_AST)	return -1;
	if(((ExpressionAST*)opd) -> dtype != DTYPE_INTEGER && ((ExpressionAST*)opd) -> dtype != DTYPE_FLOAT)	return -1;
	return 0;
}

int PrintStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(opd -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)opd) -> dtype == DTYPE_BOOL)	return -1;
	return 0;
}

int NotBoolExpressionAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(operand -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)operand) -> dtype != DTYPE_BOOL)	return -1;
	dtype = DTYPE_BOOL;
	return 0;
}

int SequenceStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	for(int i=0;i<statements.size();i++)
	{
		if(statements[i] -> is_valid(vars,fns) != 0)	return -1;
	}
	return 0;
}

int SelectionStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(cond -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)cond) -> dtype != DTYPE_BOOL)	return -1;
	if(ifpart -> is_valid(vars,fns) != 0)	return -1;
	if(elsepart != NULL && elsepart -> is_valid(vars,fns) != 0)	return -1;
	return 0;
}

int IterationStatementAST::is_valid(SymbolTable* vars,map<string,Procedure*>& fns)
{
	if(condition -> is_valid(vars,fns) != 0)	return -1;
	if(((ExpressionAST*)condition) -> dtype != DTYPE_BOOL)	return -1;
	if(body -> is_valid(vars,fns) != 0)	return -1;
	return 0;
}

void AssignmentStatementAST::print(string prefix)
{
	ast_output("\n" + prefix + "Asgn:\n" + prefix + "  LHS (");
	lhs -> print(prefix + "  ");
	ast_output(")\n" + prefix + "  RHS (");
	rhs -> print(prefix + "  ");
	ast_output(")");
}

void ReadStatementAST::print(string prefix)
{
	ast_output("\n" + prefix + "Read: ");
	opd -> print(prefix + "  ");
}

void PrintStatementAST::print(string prefix)
{
	ast_output("\n" + prefix + "Write: ");
	opd -> print(prefix + "  ");
}

void NameExpressionAST::print(string prefix)
{
	ast_output("Name : " + name + "_" + get_string_for_dtype(dtype));
}

void IntegerExpressionAST::print(string prefix)
{
	ast_output("Num : " + to_string(val) + get_string_for_dtype(dtype));
}

void FloatExpressionAST::print(string prefix)
{
	// convert float to string with precision 2
	string float_str;
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << val;
	float_str = ss.str();
	ast_output("Num : " + float_str + get_string_for_dtype(dtype));
}

void BinaryExpressionAST::print(string prefix)
{
	prefix += "  ";
	ast_output("\n" + prefix + "Arith: ");
	switch(type)
	{
		case PLUS_EXPRESSION_AST:
			ast_output("Plus");
			break;
		case MINUS_EXPRESSION_AST:
			ast_output("Minus");
			break;
		case MULTIPLICATION_EXPRESSION_AST:
			ast_output("Mult");
			break;
		case DIVISION_EXPRESSION_AST:
			ast_output("Div");
			break;
		default:
			// my_exit(2,"asserted here");
			// fflush(stderr);
			// asm("int3");
			assert(0);
	}
	ast_output(get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	left -> print(prefix + "  ");
	ast_output(")\n" + prefix + "  R_Opd (");
	right -> print(prefix + "  ");
	ast_output(")");
}

void ConditionalExpressionAST::print(string prefix)
{
	left -> print(prefix + "  ");
	ast_output("\n" + prefix + "True_Part (");
	mid -> print(prefix + "  ");
	ast_output(")\n" + prefix + "False_Part (");
	right -> print(prefix + "  ");
	ast_output(")");
}

void RelationalExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Condition: ");
	switch(opn)
	{
		case RELOP_LESS_THAN:
			ast_output("LT");
			break;
		case RELOP_LESS_THAN_EQUAL:
			ast_output("LE");
			break;
		case RELOP_GREATER_THAN:
			ast_output("GT");
			break;
		case RELOP_GREATER_THAN_EQUAL:
			ast_output("GE");
			break;
		case RELOP_EQUAL:
			ast_output("EQ");
			break;
		case RELOP_NOT_EQUAL:
			ast_output("NE");
			break;
		default:
			assert(0);
	}
	ast_output(get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	left -> print(prefix + "  ");
	ast_output(")\n" + prefix + "  R_Opd (");
	right -> print(prefix + "  ");
	ast_output(")");
}

void NotBoolExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Condition: NOT" + get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	operand -> print(prefix + "  ");
	ast_output(")");
}

void UMinusExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Arith: Uminus" + get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	operand -> print(prefix + "  ");
	ast_output(")");
}

void StringExpressionAST::print(string prefix)
{
	ast_output("String : " + val + get_string_for_dtype(dtype));
}

void BooleanExpressionAST::print(string prefix)
{
	ast_output("\n" + prefix + "Condition: ");
	switch(type)
	{
		case BOOL_AND:
			ast_output("AND");
			break;
		case BOOL_OR:
			ast_output("OR");
			break;
		default:
			assert(0);
	}
	ast_output(get_string_for_dtype(dtype) + "\n" + prefix + "  L_Opd (");
	left -> print(prefix + "  ");
	ast_output(")\n" + prefix + "  " + "  R_Opd (");
	right -> print(prefix + "  ");
	ast_output(")");
}

void SequenceStatementAST::print(string prefix)
{
	for(int i=0;i<statements.size();i++)
	{
		statements[i] -> print(prefix + "  ");
	}
}

void SelectionStatementAST::print(string prefix)
{
	ast_output("\n" + prefix + "If: \n");
	ast_output(prefix + "  " + "Condition (");
	cond -> print(prefix + "  ");
	ast_output(")");
	ast_output("\n" + prefix + "Then (");
	ifpart -> print(prefix + "  ");
	ast_output(")");
	if(elsepart != NULL)
	{
		ast_output("\n" + prefix + "Else (");
		elsepart -> print(prefix + "  ");
		ast_output(")");
	}
}

void IterationStatementAST::print(string prefix)
{
	if(is_do_while)
	{
		ast_output("\n" + prefix + "Do: ");
		ast_output("\n" + prefix + "Body (");
		body -> print(prefix + "  ");
		ast_output(")");
		ast_output("\n" + prefix + "While Condition (");
		condition -> print(prefix + "  ");
		ast_output(")");
	}
	else
	{
		ast_output("\n" + prefix + "While: \n");
		ast_output(prefix + "  " + "Condition (");
		condition -> print(prefix + "  ");
		ast_output(")");
		ast_output("\n" + prefix + "Body (");
		body -> print(prefix + "  ");
		ast_output(")");
	}
}

void BooleanExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	left -> gentac(tacs);
	right -> gentac(tacs);
	assert(left->value && right->value);
	assert(left->value->get_type() == DTYPE_BOOL && right->value->get_type() == DTYPE_BOOL);
	TACStatement* tac;
	switch(type)
	{
		case BOOL_AND:
			tac = new ComputeTACStatement(left->value, right->value, AND_COMPUTATION_TYPE);
			break;
		case BOOL_OR:
			tac = new ComputeTACStatement(left->value, right->value, OR_COMPUTATION_TYPE);
			break;
		default:
			assert(0);
	}
	tac->get_value()->set_type(DTYPE_BOOL);
	value = tac -> get_value();
	tacs.push_back(tac);
}

void BinaryExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	left -> gentac(tacs);
	right -> gentac(tacs);
	assert(left->value && right->value);
	assert(left->value->get_type() == right->value->get_type());
	assert(left->value->get_type() == DTYPE_INTEGER || left->value->get_type() == DTYPE_FLOAT);
	TACStatement* tac;
	switch(type)
	{
		case PLUS_EXPRESSION_AST:
			tac = new ComputeTACStatement(left->value, right->value, ADD_COMPUTATION_TYPE);
			break;
		case MINUS_EXPRESSION_AST:
			tac = new ComputeTACStatement(left->value, right->value, SUB_COMPUTATION_TYPE);
			break;
		case MULTIPLICATION_EXPRESSION_AST:
			tac = new ComputeTACStatement(left->value, right->value, MUL_COMPUTATION_TYPE);
			break;
		case DIVISION_EXPRESSION_AST:
			tac = new ComputeTACStatement(left->value, right->value, DIV_COMPUTATION_TYPE);
			break;
		default:
			assert(0);
	}
	tac->get_value()->set_type(left->value->get_type());
	value = tac -> get_value();
	tacs.push_back(tac);
}

void ReadStatementAST::gentac(vector<TACStatement*> &tacs)
{
	opd -> gentac(tacs);
	TACStatement* tac = new IOTACStatement(opd->value, 0);
	tacs.push_back(tac);
}

void PrintStatementAST::gentac(vector<TACStatement*> &tacs)
{
	opd -> gentac(tacs);
	TACStatement* tac = new IOTACStatement(opd->value, 1);
	tacs.push_back(tac);
}

void NameExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	TACOperand* opd = new VariableTACOperand(name, dtype);
	value = opd;
}

void IntegerExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	TACOperand* opd = new IntegerConstantTACOperand(val);
	value = opd;
}

void FloatExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	TACOperand* opd = new DoubleConstantTACOperand(val);
	value = opd;
}

void StringExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	TACOperand* opd = new StringConstantTACOperand(val);
	value = opd;
}

void UMinusExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	operand -> gentac(tacs);
	assert(operand->value);
	assert(operand->value->get_type() == DTYPE_INTEGER || operand->value->get_type() == DTYPE_FLOAT);
	TACStatement* tac = new ComputeTACStatement(operand->value, NULL, NEG_COMPUTATION_TYPE);
	tac->get_value()->set_type(operand->value->get_type());
	value = tac -> get_value();
	tacs.push_back(tac);
}

void RelationalExpressionAST::gentac(vector<TACStatement*>& tacs)
{
	left -> gentac(tacs);
	right -> gentac(tacs);
	assert(left->value && right->value);
	assert(left->value->get_type() == right->value->get_type());
	assert(left->value->get_type() == DTYPE_INTEGER || left->value->get_type() == DTYPE_FLOAT);
	TACStatement* tac;
	switch(opn)
	{
		case RELOP_LESS_THAN:
			tac = new ComputeTACStatement(left->value, right->value, LT_COMPUTATION_TYPE);
			break;
		case RELOP_LESS_THAN_EQUAL:
			tac = new ComputeTACStatement(left->value, right->value, LTE_COMPUTATION_TYPE);
			break;
		case RELOP_GREATER_THAN:
			tac = new ComputeTACStatement(left->value, right->value, GT_COMPUTATION_TYPE);
			break;
		case RELOP_GREATER_THAN_EQUAL:
			tac = new ComputeTACStatement(left->value, right->value, GTE_COMPUTATION_TYPE);
			break;
		case RELOP_EQUAL:
			tac = new ComputeTACStatement(left->value, right->value, EQ_COMPUTATION_TYPE);
			break;
		case RELOP_NOT_EQUAL:
			tac = new ComputeTACStatement(left->value, right->value, NEQ_COMPUTATION_TYPE);
			break;
		default:
			assert(0);
	}
	tac->get_value()->set_type(DTYPE_BOOL);
	value = tac -> get_value();
	value->set_type(DTYPE_BOOL);
	tacs.push_back(tac);
}

void ConditionalExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	vector<TACStatement*> tacs1;
	left -> gentac(tacs);
	assert(left->value);
	assert(left->value->get_type() == DTYPE_BOOL);
	TACOperand* label1 = new LabelTACOperand();
	TACOperand* label2 = new LabelTACOperand();
	value = new STemporaryTACOperand(dtype);	
	mid -> gentac(tacs1);
	tacs1.push_back(new AssignmentTACStatement(value, mid->value));
	TACStatement* tac3 = new GotoTACStatement(label2);
	tacs1.push_back(tac3);
	tacs1.push_back(new LabelTACStatement(label1));
	right -> gentac(tacs1);
	assert(mid->value);
	assert(right->value);
	assert(right->value->get_type() == mid->value->get_type());
	TACStatement* tac1 = new ComputeTACStatement(left->value, NULL, NOT_COMPUTATION_TYPE);
	tac1->get_value()->set_type(DTYPE_BOOL);
	tacs.push_back(tac1);
	TACStatement* tac2 = new IfGotoTACStatement(tac1->get_value(), label1);
	tacs.push_back(tac2);
	tacs.insert(tacs.end(), tacs1.begin(), tacs1.end());
	tacs.push_back(new AssignmentTACStatement(value, right->value));
	value->set_type(right->value->get_type());
	tacs.push_back(new LabelTACStatement(label2));
}

void AssignmentStatementAST::gentac(vector<TACStatement*> &tacs)
{
	lhs -> gentac(tacs);
	rhs -> gentac(tacs);
	assert(lhs->value && rhs->value);
	assert(lhs->value->get_type() == rhs->value->get_type());
	assert(lhs->value->get_type() != DTYPE_UNKNOWN);
	TACStatement* tac = new AssignmentTACStatement(lhs->value, rhs->value);
	tacs.push_back(tac);
}

void NotBoolExpressionAST::gentac(vector<TACStatement*> &tacs)
{
	operand -> gentac(tacs);
	assert(operand->value);
	assert(operand->value->get_type() == DTYPE_BOOL);
	TACStatement* tac = new ComputeTACStatement(operand->value, NULL, NOT_COMPUTATION_TYPE);
	value = tac -> get_value();
	value->set_type(DTYPE_BOOL);
	tacs.push_back(tac);
}

void SequenceStatementAST::gentac(vector<TACStatement*> &tacs)
{
	for(int i=0;i<statements.size();i++)
	{
		statements[i] -> gentac(tacs);
	}
}

void SelectionStatementAST::gentac(vector<TACStatement*> &tacs)
{
	cond -> gentac(tacs);
	vector<TACStatement*> tacs1;
	ifpart -> gentac(tacs1);
	TemporaryTACOperand* temp = new TemporaryTACOperand(DTYPE_BOOL);
	tacs.push_back(new AssignmentTACStatement(temp, cond->value, true));
	if(!elsepart){
		TACOperand* label1 = new LabelTACOperand();
		tacs.push_back(new IfGotoTACStatement(temp, label1));
		tacs.insert(tacs.end(), tacs1.begin(), tacs1.end());
		tacs.push_back(new GotoTACStatement(label1));
		if(elsepart != NULL)
		{
			TACOperand* label2 = new LabelTACOperand();
			tacs.push_back(new LabelTACStatement(label2));
			elsepart -> gentac(tacs);
		}
		tacs.push_back(new LabelTACStatement(label1));
	}
	else{
		TACOperand* label1 = new LabelTACOperand();
		TACOperand* label2 = new LabelTACOperand();
		tacs.push_back(new IfGotoTACStatement(temp, label2));
		tacs.insert(tacs.end(), tacs1.begin(), tacs1.end());
		tacs.push_back(new GotoTACStatement(label1));
		tacs.push_back(new LabelTACStatement(label2));
		elsepart -> gentac(tacs);
		tacs.push_back(new LabelTACStatement(label1));
	}
}

void IterationStatementAST::gentac(vector<TACStatement*> &tacs)
{
	vector<TACStatement*> tacs1, tacs2;
	if(!is_do_while){
		condition -> gentac(tacs2);
		body -> gentac(tacs1);
		TACOperand* label1 = new LabelTACOperand();
		TACOperand* label2 = new LabelTACOperand();
		TemporaryTACOperand* temp = new TemporaryTACOperand(DTYPE_BOOL);
		tacs.push_back(new LabelTACStatement(label1));
		tacs.insert(tacs.end(), tacs2.begin(), tacs2.end());
		tacs.push_back(new AssignmentTACStatement(temp, condition->value, true));
		tacs.push_back(new IfGotoTACStatement(temp, label2));
		tacs.insert(tacs.end(), tacs1.begin(), tacs1.end());
		tacs.push_back(new GotoTACStatement(label1));
		tacs.push_back(new LabelTACStatement(label2));
	}else{
		body -> gentac(tacs1);
		condition -> gentac(tacs2);
		TACOperand* label1 = new LabelTACOperand();
		tacs.push_back(new LabelTACStatement(label1));
		tacs.insert(tacs.end(), tacs1.begin(), tacs1.end());
		tacs.insert(tacs.end(), tacs2.begin(), tacs2.end());
		tacs.push_back(new IfGotoTACStatement(condition->value, label1));
	}
	
}

void SequenceStatementAST::add_statement(AST* ast)
{
	statements.push_back(ast);
}

void FunctionCallAST::gentac(vector<TACStatement*> &tacs)
{
	vector<TACOperand*> args;
	TemporaryTACOperand* res = NULL;
	for(int i=0;i<arguments.size();i++)
	{
		arguments[i] -> gentac(tacs);
		args.push_back(((ExpressionAST*)arguments[i]) -> value);
	}
	TACStatement* tac = new CallTACStatement(proc, args);
	value = tac -> get_value();
	tacs.push_back(tac);
}

void FunctionStatementAST::gentac(vector<TACStatement*> &tacs)
{
	fn -> gentac(tacs);
}

void ReturnStatementAST::gentac(vector<TACStatement*> &tacs)
{
	opd -> gentac(tacs);
	tacs.push_back(new AssignmentTACStatement(current_procedure_rn->ret_stemp, opd->value));
	TACStatement* tac = new GotoTACStatement(current_procedure_rn->ret_label);
	tacs.push_back(tac);
}
