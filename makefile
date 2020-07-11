CC=musl-clang -static -Os
CFLAGS=-std=c99 -Wall -pedantic
LDFLAGS=
DEPS=main.c
TARGET=main

all: clean mat4.o

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $(DEPS) -o $(TARGET)

mat4.o:
	$(CC) $(CFLAGS) -c mat4.c -o mat4.o

clean:
	rm -f *.o $(TARGET)
