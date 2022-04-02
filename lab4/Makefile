1_pid: 1_pid.o
	gcc 1_pid.o -o 1_pid

2_block_size: 2_block_size.o
	gcc 2_block_size.o -o 2_block_size

3_env: 3_env.o
	gcc 3_env.o -o 3_env

4_all_vars: 4_all_vars.o
	gcc 4_all_vars.o -o 4_all_vars

1_pid.o: 1_pid.c ../main.h
	gcc -O0 -g3 -Wall -c 1_pid.c

2_block_size.o: 2_block_size.c ../main.h
	gcc -O0 -g3 -Wall -c 2_block_size.c

3_env.o: 3_env.c ../main.h
	gcc -O0 -g3 -Wall -c 3_env.c

4_all_vars.o: 4_all_vars.c ../main.h
	gcc -O0 -g3 -Wall -c 4_all_vars.c

all: 1_pid 2_block_size 3_env 4_all_vars

clean:
	rm -rf 1_pid 2_block_size 3_env 4_all_vars *.o