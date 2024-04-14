#pragma once
// #define DEBUG
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <assert.h>
#include <map>

using namespace std;

enum computation_type {
	ADD_COMPUTATION_TYPE,
	SUB_COMPUTATION_TYPE,
	MUL_COMPUTATION_TYPE,
	DIV_COMPUTATION_TYPE,
	MOD_COMPUTATION_TYPE,
	NEG_COMPUTATION_TYPE,
	AND_COMPUTATION_TYPE,
	OR_COMPUTATION_TYPE,
	NOT_COMPUTATION_TYPE,
	EQ_COMPUTATION_TYPE,
	NEQ_COMPUTATION_TYPE,
	LT_COMPUTATION_TYPE,
	GT_COMPUTATION_TYPE,
	LTE_COMPUTATION_TYPE,
	GTE_COMPUTATION_TYPE
};

enum tac_operand_type {
	ARRAY_ACCESS_TAC_OPERAND,
	DOUBLE_CONSTANT_TAC_OPERAND,
	INTEGER_CONSTANT_TAC_OPERAND,
	LABEL_TAC_OPERAND,
	POINTER_DEREFERENCE_TAC_OPERAND,
	STRING_CONSTANT_TAC_OPERAND,
	TEMPORARY_TAC_OPERAND,
	VARIABLE_TAC_OPERAND,
	STEMPORARY_TAC_OPERAND,
};

enum st_datatype 
{
	DTYPE_UNKNOWN,
	DTYPE_INTEGER,
	DTYPE_FLOAT,
	DTYPE_STRING,
	DTYPE_BOOL,
	DTYPE_VOID
};

extern FILE* token_output_file;
class Program;
class Procedure;

struct arguments 
{
	bool show_tokens = false;
	bool stop_after_scanning = false;
	bool stop_after_parsing = false;
	bool stop_after_ast = false;
	bool stop_after_tac = false;
	bool stop_after_rtl = false;
	bool show_ast = false;
	bool show_tac = false;
	bool show_rtl = false;
	bool print_to_term = false;
	FILE* ast_output_file = NULL;
	FILE* tac_output_file = NULL;
	FILE* rtl_output_file = NULL;
	FILE* asm_output_file = NULL;
	std::string input_file = "";
};

void my_print(const char* a, const char* b);
void my_print_vars(const char* a, const char* b, int a1, int b1, ...);

void scanner_output(const char* token,char* val,int lineno);
void ast_output(const char* str);
void ast_output(string str);
void tac_output(const char* str, bool istab = true);
void tac_output(string str, bool istab = true);
void rtl_output(const char* str, bool istab = true);
void rtl_output(string str, bool istab = true);

void my_exit(int exit_code);
void my_exit(int exit_code,const char* msg);

void continue_after_ast(Program*);
