CC = gcc -g -ansi -pedantic
CFLAGS = -Wall
EXE = p1_e1

all : $(EXE)

.PHONY : clean

clean :
	rm -f *.o core $(EXE)
	$(EXE) : % : %.o point.o types.o
	$(CC) $(CFLAGS) -o $@ $@.o point.o types.o


point.o : point.c point.h 
	$(CC) $(CFLAGS) -c $<

types.o : types.h
	$(CC) $(CFLAGS) -c $<

p1_e1:
	@./p1_e1


