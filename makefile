CC = gcc -g -ansi -pedantic
CFLAGS = -Wall
objetos = point.o

EXE = p1_e1


all : $(EXE)

.PHONY : clean

clean:
	rm -f *.o core $(EXE)

$(EXE): % : %.o $(objetos)
	$(CC) $(CFLAGS) -o $@ $@.o $(objetos)
	

point.o : point.c point.h map.h types.h
	$(CC) $(CFLAGS) -c $<

p1_e1.o : p1_e1.c point.h
	$(CC) $(CFLAGS) -c $<

ej1_test:
	@./p1_e1


