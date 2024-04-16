#include "utils.h"
#include "program.h"
#include "tac.h"
extern struct arguments arguments;
extern int yylineno;
extern Procedure* current_procedure_rn;
extern Program* only_program_rn;

void my_print(const char* a, const char* b)
{
	printf("%s",a);
#ifdef DEBUG
	fprintf(stderr,"%s",b);
#endif
}

void my_print_vars(const char* a, const char* b, int a1, int b1, ...)
{
	int count = a1+b1;
	va_list varg;
	va_start(varg,count);
	vprintf(a,varg);
#ifdef DEBUG
	vprintf(b,varg);
#endif
	va_end(varg);
}

void scanner_output(const char* token,char* val,int lineno)
{
	if(token_output_file)
		fprintf(token_output_file,"\tToken Name: %s\tLexeme: %s\tLineno: %d\n",token,val,lineno);
}

void my_exit(int exit_code)
{
	if(token_output_file){
		fclose(token_output_file);
		token_output_file = NULL;
	}
	if(exit_code != 0)	fprintf(stderr,"ERROR ENCOUNTERED!\n");

	exit(exit_code);
}

void my_exit(int exit_code, const char* msg)
{
	if(token_output_file){
		fclose(token_output_file);
		token_output_file = NULL;
	}
	if(exit_code == 2)
	{
		fprintf(stderr,"Line: %d, %s\n",yylineno,msg);
	}
	if(exit_code != 0){
		fprintf(stderr,"ERROR ENCOUNTERED!\n");
		fprintf(stderr,"%s\n",msg);
	}

	exit(exit_code);
}

void ast_output(const char* str)
{
	if(arguments.show_ast)
		fprintf(arguments.ast_output_file,"%s",str);
}

void ast_output(string str)
{
	ast_output(str.c_str());
}

void continue_after_ast(Program* p)
{
	only_program_rn = p;
	p->printast();
	if(arguments.stop_after_ast)
	{
		my_exit(0);
	}
	p->gentac();
	if(arguments.stop_after_tac)
	{
		my_exit(0);
	}
	p->genrtl();
	if(arguments.stop_after_rtl)
	{
		my_exit(0);
	}
	if(arguments.print_to_term)
	{
		arguments.asm_output_file = stdout;
	}
	else
		arguments.asm_output_file = fopen((arguments.input_file + ".spim").c_str(),"w");
	p->genasm();
	if(!arguments.print_to_term)
		fclose(arguments.asm_output_file);
}

void tac_output(const char* str, bool istab)
{
	if(arguments.show_tac)
	{
		if(istab)
			fprintf(arguments.tac_output_file,"\t%s",str);
		else
			fprintf(arguments.tac_output_file,"%s",str);
	}
}

void tac_output(string str, bool istab)
{
	tac_output(str.c_str(), istab);
}

void rtl_output(const char* str, bool istab)
{
	if(arguments.show_rtl)
	{
		if(istab)
			fprintf(arguments.rtl_output_file,"\t%s",str);
		else
			fprintf(arguments.rtl_output_file,"%s",str);
	}
}

void rtl_output(string str, bool istab)
{
	rtl_output(str.c_str(), istab);
}

void asm_output(string str, bool istab)
{
	asm_output(str.c_str(), istab);
}

void asm_output(const char* str, bool istab)
{
		if(istab)
			fprintf(arguments.asm_output_file,"\t%s",str);
		else
			fprintf(arguments.asm_output_file,"%s",str);
}

string print_offset_reg(TACOperand* opd)
{
	assert(opd->op_type == VARIABLE_TAC_OPERAND || opd->op_type == STEMPORARY_TAC_OPERAND);
	if(opd->op_type == STEMPORARY_TAC_OPERAND)
	{
		int idx = ((STemporaryTACOperand*)opd)->num;
		int ret = current_procedure_rn->stemp_offsets[idx+1] + current_procedure_rn->defn->local_symbol_table->current_offset;
		if(current_procedure_rn->ret_label && idx == 0)
		{
			ret = (current_procedure_rn->ret_type==DTYPE_FLOAT?8:4);
		}
		return  "-" + to_string(ret) + "($fp)";
	}
	string var = ((VariableTACOperand*)opd) -> get_name();
	vector<Symbol*> param_list = *(current_procedure_rn->formal_param_list);
	int curr_offset = 8;
	for(int i=0;i<param_list.size();i++)
	{
		if(param_list[i]->get_name() == var)
		{
			return to_string(curr_offset) + "($fp)";
		}
		if(param_list[i]->get_type() == DTYPE_FLOAT)
		{
			curr_offset += 8;
		}
		else
		{
			curr_offset += 4;
		}
	}

	// Search in local_symbol_table
	SymbolTable* local_symbol_table = current_procedure_rn->defn->local_symbol_table;
	map<string, Symbol*> symbols = local_symbol_table->symbols;
	if(symbols.find(var) != symbols.end())
	{
		if(current_procedure_rn->ret_label)
			return "-" + to_string(symbols[var]->offset+(current_procedure_rn->ret_type==DTYPE_FLOAT?8:4)) + "($fp)";
		else
			return "-" + to_string(symbols[var]->offset) + "($fp)";
	}

	// Search in global_symbol_table
	SymbolTable* global_symbol_table = only_program_rn -> global_symbol_table;
	if(!global_symbol_table->is_variable_present(var))
	{
		assert(1);
	}
	return var + "_";
}

