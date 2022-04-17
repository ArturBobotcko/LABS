1_sort_thread: 1_sort_thread.o
	gcc -pthread 1_sort_thread.o -o 1_sort_thread

2_random_nums: 2_random_nums.o
	gcc -pthread 2_random_nums.o -o 2_random_nums

sort_thread_for_2: sort_thread_for_2.o
	gcc -pthread sort_thread_for_2.o -o sort_thread_for_2

1_sort_thread.o: 1_sort_thread.c ../main.h
	gcc -O0 -g3 -Wall -c 1_sort_thread.c

2_random_nums.o: 2_random_nums.c ../main.h
	gcc -O0 -g3 -Wall -c 2_random_nums.c

sort_thread_for_2.o: sort_thread_for_2.c ../main.h
	gcc -O0 -g3 -Wall -c sort_thread_for_2.c

clean:
	rm -rf *.o 1_sort_thread 2_random_nums sort_thread_for_2

all: 1_sort_thread 2_random_nums sort_thread_for_2