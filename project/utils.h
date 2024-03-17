#pragma once
// #define DEBUG
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

extern FILE* token_output_file;
class Program;

struct arguments 
{
	bool show_tokens = false;
	bool stop_after_scanning = false;
	bool stop_after_parsing = false;
	bool show_ast = false;
	bool show_tac = false;
	bool print_to_term = false;
	FILE* ast_output_file = NULL;
	FILE* tac_output_file = NULL;
	std::string input_file = "";
};

void my_print(const char* a, const char* b);
void my_print_vars(const char* a, const char* b, int a1, int b1, ...);

void scanner_output(const char* token,char* val,int lineno);
void ast_output(const char* str);
void ast_output(string str);
void tac_output(const char* str, bool istab = true);
void tac_output(string str, bool istab = true);

void my_exit(int exit_code);
void my_exit(int exit_code,const char* msg);

void continue_after_ast(Program*);
