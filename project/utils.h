#pragma once
// #define DEBUG
// #include <iostream>
// #include <string>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>

// class AST;
// class SymbolTable;
// class Symbol;
// class Procedure;
// class ProcedureDefn;
// class Program;

extern FILE* token_output_file;

struct arguments {
	bool show_tokens = false;
	bool stop_after_scanning = false;
	bool stop_after_parsing = false;
	std::string input_file = "";
};

void my_print(const char* a, const char* b);

void my_print_vars(const char* a, const char* b, int a1, int b1, ...);
// 
// void my_print(std::string a, std::string b)
// {
// 	std::cout<<a;
// #ifdef DEBUG
// 	std::cout<<b;
// #endif
// }

void scanner_output(const char* token,char* val,int lineno);

void my_exit(int exit_code);
