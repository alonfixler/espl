CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: xsum

xsum: xsum.o
	$(CC) $(CFLAGS) -o $@ $^

xsum.o: xsum.c


clean:
	rm -f *.o xsum
