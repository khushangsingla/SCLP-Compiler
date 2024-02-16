#include "utils.h"

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
// 
// void my_print(std::string a, std::string b)
// {
// 	std::cout<<a;
// #ifdef DEBUG
// 	std::cout<<b;
// #endif
// }

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
	if(exit_code != 0){
		fprintf(stderr,"ERROR ENCOUNTERED!\n");
		fprintf(stderr,"%s\n",msg);
	}

	exit(exit_code);
}
