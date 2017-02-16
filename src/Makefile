CC = gcc
CFLAGS = -Wall -g
OBJS = main.o List.o
HDRS = List.h
EXEC = bash

.SUFFIXES: .c
.c.o:
	$(CC) -c $(CFLAGS) $*.c
	
default: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

$(OBJS): $(HDRS)

clean:
	rm -rf $(EXEC) $(OBJS)