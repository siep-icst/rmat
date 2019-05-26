#compile parameters

CC = g++
CFLAGS = -c -Wall -O6 #-fprofile-arcs -ftest-coverage -coverage #-pg
EXEFLAG = -O6 #-fprofile-arcs -ftest-coverage -coverage #-pg #-O2
#CFLAGS = -c -Wall -g #-fprofile-arcs -ftest-coverage -coverage #-pg
#EXEFLAG = -g #-fprofile-arcs -ftest-coverage -coverage #-pg #-O2
	 
#add -lreadline -ltermcap if using readline or objs contain readline
library = #-lgcov -coverage

objdir = ./objs/
objfile = $(objdir)Util.o

all: rmat_gen.exe

rmat_gen.exe: main/run.cpp $(objfile)
	$(CC) $(EXEFLAG) -o rmat_gen.exe main/run.cpp $(objfile) $(library)

$(objdir) Util.o: util/Util.cpp util/Util.h 
	$(CC) $(CFLAGS) util/Util.cpp -o $(objdir)Util.o




.PHONY: clean dist tarball test sumlines

clean:
	rm -f $(objdir)*
dist: clean
	rm -f *.txt dig




