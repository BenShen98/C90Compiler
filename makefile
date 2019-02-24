CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include
CPPFLAGS += -Wfatal-errors

all : bin/c_compiler

src/C90_parser.tab.cpp src/C90_parser.tab.hpp : src/C90.y
	bison -v -d src/C90.y -o src/C90_parser.tab.cpp

src/C90_lexer.yy.cpp : src/C90.flex src/C90_parser.tab.hpp
	flex -o src/C90_lexer.yy.cpp  src/C90.flex

bin/c_compiler : src/c_compiler.o src/C90_parser.tab.o src/C90_lexer.yy.o src/C90_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/print_canonical $^

clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp
