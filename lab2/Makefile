CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: fortune

fortune: fortune.o
	$(CC) $(CFLAGS) -o $@ $^

fortune.o: fortune.c


clean:
	rm -f *.o fortune
