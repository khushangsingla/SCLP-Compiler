CPP = g++
CC = gcc
FLAGS = -g
CODE = sclp
PARSE = parser
SCAN = scanner

all: sclp

sclp: $(CODE).o lex.yy.o y.tab.o
	$(CPP) $(FLAGS) -o $(CODE).o sclp lex.yy.o y.tab.o -ly -ll

$(CODE).o: $(CODE).cpp y.tab.h
	$(CPP) $(FLAGS) -c $(CODE).cpp

y.tab.o: y.tab.c y.tab.h
	$(CC) $(FLAGS) -c y.tab.c

lex.yy.o: $(SCAN).l y.tab.h
	lex $(SCAN).l
	$(CC) $(FLAGS) -c lex.yy.c

y.tab.h y.tab.c: $(PARSE).y
	yacc -dv $(PARSE).y

clean:
	rm *.o sclp lex.yy.c y.tab.c y.tab.h y.output 2>/dev/null || true
