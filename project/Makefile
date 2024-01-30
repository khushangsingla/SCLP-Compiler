CPP = g++
CC = gcc
CFLAGS = 
CODE = sclp
PARSE = parser
SCAN = scanner
YACC_FLAGS = -dv

# YACC_FLAGS += -t
# CFLAGS += -DDEBUG -g

all: sclp

sclp: $(CODE).o lex.yy.o y.tab.o Makefile
	$(CPP) $(CFLAGS) -o sclp $(CODE).o lex.yy.o y.tab.o -ly -ll

$(CODE).o: $(CODE).cpp y.tab.h Makefile
	$(CPP) $(CFLAGS) -c $(CODE).cpp

y.tab.o: y.tab.c y.tab.h Makefile
	$(CC) $(CFLAGS) -c y.tab.c

lex.yy.o: $(SCAN).l y.tab.h printing.h Makefile
	lex $(SCAN).l
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.h y.tab.c: $(PARSE).y printing.h Makefile
	yacc $(YACC_FLAGS) $(PARSE).y

clean:
	rm *.o sclp lex.yy.c y.tab.c y.tab.h y.output 2>/dev/null || true
