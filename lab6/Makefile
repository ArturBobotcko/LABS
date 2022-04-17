1_sort_thread: 1_sort_thread.o
	gcc -pthread 1_sort_thread.o -o 1_sort_thread

2_sort_random: 2_sort_random.o
	gcc -pthread 2_sort_random.o -o 2_sort_random

3_thread_attr: 3_thread_attr.o
	gcc -pthread 3_thread_attr.o -o 3_thread_attr

1_sort_thread.o: 1_sort_thread.c ../main.h
	gcc -O0 -g3 -Wall -c 1_sort_thread.c

2_sort_random.o: 2_sort_random.c ../main.h
	gcc -O0 -g3 -Wall -c 2_sort_random.c

3_thread_attr.o: 3_thread_attr.c ../main.h
	gcc -O0 -g3 -Wall -c 3_thread_attr.c

clean:
	rm -rf *.o 1_sort_thread 2_sort_random 3_thread_attr

all: 1_sort_thread 2_sort_random 3_thread_attr