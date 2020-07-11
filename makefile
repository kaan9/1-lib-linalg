CC=musl-clang -static -Os
CFLAGS=-std=c89 -Wall -pedantic
LDFLAGS=

all: clean mat4.o

mat4.o:
	$(CC) -c mat4.c -o mat4.o

clean:
	rm -f *.o
