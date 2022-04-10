1_fork: 1_fork.o
	gcc 1_fork.o -o 1_fork

2_how_many: 2_how_many.o
	gcc 2_how_many.o -o 2_how_many

3_fork_mod: 3_fork_mod.o
	gcc 3_fork_mod.o -o 3_fork_mod

4_waitpid_macros: 4_waitpid_macros.o
	gcc 4_waitpid_macros.o -o 4_waitpid_macros

5_fork_status: 5_fork_status.o
	gcc 5_fork_status.o -o 5_fork_status

6_zombie: 6_zombie.o
	gcc 6_zombie.o -o 6_zombie

7_exec: 7_exec.o
	gcc 7_exec.o -o 7_exec

envs: envs.o
	gcc envs.o -o envs

1_fork.o: 1_fork.c ../main.h
	gcc -O0 -g3 -Wall -c 1_fork.c

2_how_many.o: 2_how_many.c ../main.h
	gcc -O0 -g3 -Wall -c 2_how_many.c

3_fork_mod.o: 3_fork_mod.c ../main.h
	gcc -O0 -g3 -Wall -c 3_fork_mod.c

4_waitpid_macros.o: 4_waitpid_macros.c ../main.h
	gcc -O0 -g3 -Wall -c 4_waitpid_macros.c

5_fork_status.o: 5_fork_status.c ../main.h
	gcc -O0 -g3 -Wall -c 5_fork_status.c

6_zombie.o: 6_zombie.c ../main.h
	gcc -O0 -g3 -Wall -c 6_zombie.c

7_exec.o: 7_exec.c ../main.h
	gcc -O0 -g3 -Wall -c 7_exec.c

envs.o: envs.c ../main.h
	gcc -O0 -g3 -Wall -c envs.c

all: 1_fork 2_how_many 3_fork_mod 4_waitpid_macros 5_fork_status 6_zombie 7_exec envs

clean:
	rm -rf *.o 1_fork 2_how_many 3_fork_mod 4_waitpid_macros 5_fork_status 6_zombie 7_exec envs