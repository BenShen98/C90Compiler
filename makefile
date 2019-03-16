SHELL := /bin/bash

CC = g++

INC = -I/include

CPPFLAGS += -std=c++11 -g
# CPPFLAGS += -W -Wall  -Wno-unused-parameter
CPPFLAGS += -I include -std=c++11
CPPFLAGS += -fmax-errors=5 -ggdb
# CPPFLAGS += -edantic-errors  -ansi



all : clean ./bin/c_compiler
	 ./bin/c_compiler --translate test.c -o x.py
	 cat x.py

debug: clean ./bin/c_compiler
	gdb --args ./bin/c_compiler --translate test.c -o x.py

src/C90_parser.tab.cpp src/C90_parser.tab.hpp : src/C90.y
	bison -v -d src/C90.y -o src/C90_parser.tab.cpp

src/C90_lexer.yy.cpp : src/C90.flex src/C90_parser.tab.hpp
	flex -o src/C90_lexer.yy.cpp  src/C90.flex

include/Mp.o : include/Mp.cpp
	$(CC) $(CPPFLAGS) $(INC) -c $< -o $@

include/Context.o : include/Context.cpp
	$(CC) $(CPPFLAGS) $(INC) -c $< -o $@

bin/c_compiler : src/c_compiler.o src/C90_parser.tab.o src/C90_lexer.yy.o src/C90_parser.tab.o include/Mp.o include/Context.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o $@ $^

clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.yy.cpp
