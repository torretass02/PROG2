CC = gcc -g -ansi -pedantic
CFLAGS = -Wall
objetos = point.o map.o

EXE = p1_e1 p1_e2 p1_e3


all : $(EXE)

.PHONY : clean

clean:
	rm -f *.o core $(EXE)

$(EXE): % : %.o $(objetos)
	$(CC) $(CFLAGS) -o $@ $@.o $(objetos)
	

point.o : point.c point.h map.h types.h
	$(CC) $(CFLAGS) -c $<

map.o : map.c point.h map.h types.h
	$(CC) $(CFLAGS) -c $<

p1_e1.o : p1_e1.c point.h
	$(CC) $(CFLAGS) -c $<

p1_e2.o : p1_e2.c map.h point.h
	$(CC) $(CFLAGS) -c $<

p1_e3.o : p1_e3.c map.h point.h
	$(CC) $(CFLAGS) -c $<

ej1_test:
	@./p1_e1

ej2_test:
	@./p1_e2

ej3_test:
	@./p1_e3 laberinto_1.txt


