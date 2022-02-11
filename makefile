CC = gcc
CFLAGS = -Wall -pedantic
objetos = point.o p1_e1.o
ficheros = point.c p1_e1.c

all: $(objetos)
	$(CC) $(CFLAGS) $(objetos)
	./a.out

point.o : point.c point.h map.h types.h
	$(CC) $(CFLAGS) -c point.c

p1_e1.o : p1_e1.c point.h
	$(CC) $(CFLAGS) -c p1_e1.c

clean:
	rm -f all $(objetos)
