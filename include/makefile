CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include -std=c++11
CPPFLAGS += -Wfatal-errors -ggdb

all: a.out
	./a.out
	cat MpOut.temp


a.out: testMp.o Mp.o
	g++ -o $@ $^

clean:
	rm -f *.o
	rm -f *.out
	rm -f MpOut.temp

debug: clean ./a.out
	gdb ./a.out