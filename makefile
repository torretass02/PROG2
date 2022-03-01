CC = gcc -g -ansi -pedantic
CFLAGS = -Wall
objetos = point.o map.o

EXE = p2_e1a


all : $(EXE)

.PHONY : clean

clean:
	rm -f *.o core $(EXE)

$(EXE): % : %.o $(objetos)
	$(CC) $(CFLAGS) -o $@ $@.o $(objetos) -lm
	

point.o : point.c point.h map.h types.h
	$(CC) $(CFLAGS) -c $<

map.o : map.c point.h map.h types.h
	$(CC) $(CFLAGS) -c $<

p2_e1a.o : p2_e1a.c point.h
	$(CC) $(CFLAGS) -c $<

ej1a_test:
	@./p2_e1a



