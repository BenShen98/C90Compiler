SHELL := /bin/bash

CC = g++


CPPFLAGS += -std=c++11 -g
CPPFLAGS += -I include

# for production
CPPFLAGS += -o2

# for debug
#CPPFLAGS += -fmax-errors=5 -ggdb -W -Wall  -Wno-unused-parameter


.PHONY: all clean debug


bin/c_compiler : src/c_compiler.o src/C90_parser.tab.o src/C90_lexer.yy.o src/C90_parser.tab.o include/Mp.o include/Context.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o $@ $^
	rm -f src/*.o
	rm -f include/*.o

src/C90_parser.tab.cpp src/C90_parser.tab.hpp : src/C90.y
	bison -v -d src/C90.y -o src/C90_parser.tab.cpp

src/C90_lexer.yy.cpp : src/C90.flex src/C90_parser.tab.hpp
	flex -o src/C90_lexer.yy.cpp  src/C90.flex

include/%.o : include/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f src/*.o
	rm -f include/*.o
	rm -f bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.yy.cpp

	rm -f tmp/*.py
	rm -f test/C_output/*
	rm -f test/C_driver_exec/*
	rm -f test/dump/*

.PHONY test:testbench.sh
	./testbench.sh

# ########### below are debug short cut ###########

all : clean ./bin/c_compiler r

debug: clean ./bin/c_compiler d


r:
	 ./bin/c_compiler --translate test.c -o x.py
#	 ./bin/c_compiler -S test.c -o x.s
	 cat x.py

d:
	gdb --args ./bin/c_compiler --translate test.c -o x.py
#	gdb --args ./bin/c_compiler -S test.c -o x.s