#define DEBUG
// #include <iostream>
// #include <string>
#include <stdio.h>
#include <stdarg.h>

void my_print(const char* a, const char* b)
{
	printf("%s",a);
#ifdef DEBUG
	printf("%s",b);
#endif
}

void my_print_vars(const char* a, const char* b, int a1, int b1, ...)
{
	va_list varg;
	va_start(varg,a1+b1);
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
