#include "utils.h"
#include "program.h"
extern struct arguments arguments;
extern int yylineno;

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
