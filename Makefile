# TODO - fix this

CC = gcc
CFLAGS = -pthread

all: msg_lib
    $(CC) $(CFLAGS) msg_lib.o main.c -o main

msg_lib: list msg_lib.h msg_lib.C
    $(CC) $(CFLAGS) msg_lib.c -c -o msg_lib.o

list: list.h list.c
    $(CC) $(CFLAGS) lib.c -c -o list.o

clean:
    rm -f msg_lib.o main