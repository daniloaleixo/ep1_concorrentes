CC = gcc
CFLAGS = -Wall -O0 -g
LFLAGS = -lm
OUT = ep1 
IN = ep1.c
OBJS = ep1.o StringOps.o Fibonacci.o Heapsort.o integral_sec_x.o agulha.o

all: $(OUT) ep1

clean:
	rm -f $(OUT) $(OBJS) ep1.o ep1sh
	

ep1: ep1.o StringOps.o
	$(CC) $(OBJS) $(LFLAGS) -o ep1sh

$(OUT): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(OUT)

ep1.o: $(IN)
	$(CC) $(IN) -c -o ep1.o

StringOps.o: StringOps.c
	$(CC) StringOps.c -c -o StringOps.o


Fibonacci.o: Fibonacci.c
	$(CC) Fibonacci.c -c -o Fibonacci.o

	
Heapsort.o: Heapsort.c
	$(CC) Heapsort.c -c -o Heapsort.o

integral_sec_x.o: integral_sec_x.c
	$(CC) integral_sec_x.c -c -o integral_sec_x.o

agulha.o: agulha.c
	$(CC) agulha.c -c -o agulha.o

