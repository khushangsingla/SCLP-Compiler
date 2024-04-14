CPP = g++
CC = g++
CFLAGS = -std=c++11 -g -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-missing-field-initializers
CODE = sclp
PARSE = parser
SCAN = scanner
YACC_FLAGS = -dv -Wcounterexamples

# YACC_FLAGS += -t
# CFLAGS += -DDEBUG -g
# FLAGS += -DDEBUG -g

all: sclp

sclp: $(CODE).o lex.yy.o y.tab.o Makefile symbol_table.o ast.o program.o procedure.o utils.o tac.o rtl.o
	$(CPP) $(CFLAGS) -o sclp $(CODE).o symbol_table.o ast.o program.o procedure.o utils.o tac.o rtl.o lex.yy.o y.tab.o -ly -ll

utils.o: utils.h utils.cpp
	$(CPP) $(CFLAGS) -c utils.cpp

ast.o: ast.cpp ast.h symbol_table.h
	$(CPP) $(CFLAGS) -c ast.cpp

tac.o: tac.cpp tac.h rtl.h
	$(CPP) $(CFLAGS) -c tac.cpp

rtl.o: rtl.cpp rtl.h utils.h
	$(CPP) $(CFLAGS) -c rtl.cpp

program.o: program.cpp procedure.h symbol_table.h program.h ast.h
	$(CPP) $(CFLAGS) -c program.cpp

procedure.o: procedure.cpp symbol_table.h procedure.h ast.h
	$(CPP) $(CFLAGS) -c procedure.cpp

symbol_table.o: symbol_table.cpp symbol_table.h
	$(CPP) $(CFLAGS) -c symbol_table.cpp

$(CODE).o: $(CODE).cpp y.tab.h utils.h Makefile
	$(CPP) $(CFLAGS) -c $(CODE).cpp

y.tab.o: y.tab.c y.tab.h Makefile
	$(CC) $(CFLAGS) -c y.tab.c

lex.yy.o: $(SCAN).l y.tab.h utils.h Makefile
	lex $(SCAN).l
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.h y.tab.c: $(PARSE).y utils.h Makefile
	yacc $(YACC_FLAGS) $(PARSE).y

clean:
	rm *.o sclp lex.yy.c y.tab.c y.tab.h y.output *.toks 2>/dev/null || true
