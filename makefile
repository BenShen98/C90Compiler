SHELL := /bin/bash

CC = g++


CPPFLAGS += -std=c++11 -g
# CPPFLAGS += -W -Wall  -Wno-unused-parameter
CPPFLAGS += -I include
CPPFLAGS += -fmax-errors=5 -ggdb
# CPPFLAGS += -edantic-errors  -ansi


.PHONY: all clean debug

all : clean ./bin/c_compiler
#	 ./bin/c_compiler --translate test.c -o x.py
	 ./bin/c_compiler -S test.c -o x.s
	 cat x.s

debug: clean ./bin/c_compiler
#	gdb --args ./bin/c_compiler --translate test.c -o x.py
	gdb --args ./bin/c_compiler -S test.c -o x.s

src/C90_parser.tab.cpp src/C90_parser.tab.hpp : src/C90.y
	bison -v -d src/C90.y -o src/C90_parser.tab.cpp

src/C90_lexer.yy.cpp : src/C90.flex src/C90_parser.tab.hpp
	flex -o src/C90_lexer.yy.cpp  src/C90.flex

include/%.o : include/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

bin/c_compiler : src/c_compiler.o src/C90_parser.tab.o src/C90_lexer.yy.o src/C90_parser.tab.o include/Mp.o include/Context.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o $@ $^

clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.yy.cpp

# astSrc : include/ast/*.hpp include/ast.hpp