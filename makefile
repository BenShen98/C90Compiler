CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include -std=c++11
CPPFLAGS += -Wfatal-errors -ggdb



all : clean ./bin/c_compiler
	 ./bin/c_compiler --translate test.c -o x.py
	 cat x.py

debug: clean ./bin/c_compiler
	gdb --args ./bin/c_compiler --translate test.c -o x.py

src/C90_parser.tab.cpp src/C90_parser.tab.hpp : src/C90.y
	bison -v -d src/C90.y -o src/C90_parser.tab.cpp

src/C90_lexer.yy.cpp : src/C90.flex src/C90_parser.tab.hpp
	flex -o src/C90_lexer.yy.cpp  src/C90.flex

bin/c_compiler : src/c_compiler.o src/C90_parser.tab.o src/C90_lexer.yy.o src/C90_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o $@ $^

clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.yy.cpp
	rm -f tmp/*.py

.PHONY test:testbench.sh
	./testbench.sh
