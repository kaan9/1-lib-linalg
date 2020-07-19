CC=musl-clang -static -Os
CFLAGS=-std=c99 -Wall -pedantic
LDFLAGS=-lm
DEPS=test.c
TARGET=test

all: clean  $(TARGET)

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS)  $(DEPS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
