1_fd: 1_fd.o
	gcc 1_fd.o -o 1_fd

1_fd.o: 1_fd.c ../main.h
	gcc -O0 -g3 -Wall -c 1_fd.c

clean:
	rm -rf 1_fd *.o

all: 1_fd