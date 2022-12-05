CC = g++
CFLAGS = -pthread

test: msg_lib list link globals.hpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o
	$(CC) $(CFLAGS) msg_lib.o list.o link.o test.o -o test.exe

msg_lib: msg_lib.cpp msg_lib.hpp globals.hpp
	$(CC) $(CFLAGS) -c msg_lib.cpp -o msg_lib.o

list: list.cpp list.hpp msg_lib.hpp globals.hpp
	$(CC) $(CFLAGS) -c list.cpp -o list.o

link: link.cpp link.hpp msg_lib.hpp globals.hpp
	$(CC) $(CFLAGS) -c link.cpp -o link.o

clean:
	rm -f test.o msg_lib.o list.o link.o test.exe

