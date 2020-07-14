CC=musl-clang -static -Os
CFLAGS=-std=c99 -Wall -pedantic
LDFLAGS=-lm
DEPS=main.c
TARGET=main

all: clean  $(TARGET)

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS)  $(DEPS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
