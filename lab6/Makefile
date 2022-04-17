1_sort_thread: 1_sort_thread.o
	gcc -pthread 1_sort_thread.o -o 1_sort_thread

1_sort_thread.o:  1_sort_thread.c ../main.h
	gcc -O0 -g3 -Wall -c 1_sort_thread.c

clean:
	rm -rf *.o 1_sort_thread

all: 1_sort_thread