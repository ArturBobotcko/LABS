1_fd: 1_fd.o
	gcc 1_fd.o -o 1_fd

2_tee: 2_tee.o
	gcc 2_tee.o -o 2_tee

3_cp: 3_cp.o
	gcc 3_cp.o -o 3_cp

4_rev: 4_rev.o
	gcc 4_rev.o -o 4_rev

1_fd.o: 1_fd.c ../main.h
	gcc -O0 -g3 -Wall -c 1_fd.c

2_tee.o: 2_tee.c ../main.h
	gcc -O0 -g3 -Wall -c 2_tee.c

3_cp.o: 3_cp.c ../main.h
	gcc -O0 -g3 -Wall -c 3_cp.c

4_rev.o: 4_rev.c ../main.h
	gcc -O0 -g3 -Wall -c 4_rev.c

clean:
	rm -rf 1_fd 2_tee 3_cp 4_rev *.o

all: 1_fd 2_tee 3_cp 4_rev