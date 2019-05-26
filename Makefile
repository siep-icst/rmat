#compile parameters

CC = g++
CFLAGS = -c -Wall -O6 #-fprofile-arcs -ftest-coverage -coverage #-pg
EXEFLAG = -O6 #-fprofile-arcs -ftest-coverage -coverage #-pg #-O2
#CFLAGS = -c -Wall -g #-fprofile-arcs -ftest-coverage -coverage #-pg
#EXEFLAG = -g #-fprofile-arcs -ftest-coverage -coverage #-pg #-O2
	 
#add -lreadline -ltermcap if using readline or objs contain readline
library = #-lgcov -coverage

objdir = ./objs/
objfile = $(objdir)rmat_generator.o

all: rmat_gen.exe

rmat_gen.exe: rmat_generator.cpp $(objfile)
	$(CC) $(EXEFLAG) -o graphql.exe rmat_generator.cpp $(objfile) $(library)

$(objdir)rmat_generator.o: rmat_generator.cpp 
	$(CC) $(CFLAGS) rmat_generator.cpp -o $(objdir)rmat_generator.o




.PHONY: clean dist tarball test sumlines

clean:
	rm -f $(objdir)*
dist: clean
	rm -f *.txt dig




