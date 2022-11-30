CC = gcc
CFLAGS = -pthread
main: msg_lib list
	CC CFLAGS -c main.cpp -o main.o
	CC CFLAGS msg_lib.o list.o main.o -o test.exe

msg_lib: msg_lib.cpp msg_lib.h
	CC CFLAGS -c msg_lib.cpp -o msg_lib.o

list: list.cpp list.h msg_lib.h
	CC CFLAGS -c list.cpp -o list.o

clean:
rm -f main.o msg_lib.o list.o test.exe

