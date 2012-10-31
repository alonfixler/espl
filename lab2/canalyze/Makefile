all: testnl testfgn canalyze

test: testnl testfgn
	./testnl
	./testfgn

testnl: testnl.o namelist.o
testfgn: testfgn.o fgetname.o
canalyze: canalyze.o namelist.o fgetname.o

testnl.o: testnl.c namelist.h
namelist.o: namelist.c namelist.h
canalyze.o: canalyze.c namelist.h fgetname.h

testfgn.o: testfgn.c fgetname.h
fgetname.o: fgetname.c fgetname.h

clean:
	rm -f testnl testfgn canalyze *.o
