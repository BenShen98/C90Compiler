CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include -std=c++11
CPPFLAGS += -Wfatal-errors -ggdb

a.out: testMp.o Stack.o TempReg.o Mp.o
	g++ -o $@ $^
	./a.out
	cat MpOut.temp

clean:
	rm -f *.o
	rm -f *.out
	rm -f MpOut.temp