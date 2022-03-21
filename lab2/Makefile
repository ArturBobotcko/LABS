1_glibc_ver: 1_glibc_ver.o
	gcc 1_glibc_ver.o -o 1_glibc_ver

2_error: 2_error.o
	gcc 2_error.o -o 2_error

3_errors_generator: 3_errors_generator.o
	gcc 3_errors_generator.o -o 3_errors_generator

4_test: 4_test.c
	gcc -E 4_test.c

1_glibc_ver.o: 1_glibc_ver.c ../main.h
	gcc -O0 -g3 -Wall -c 1_glibc_ver.c

2_error.o: 2_error.c ../main.h
	gcc -O0 -g3 -Wall -c 2_error.c

3_errors_generator.o: 3_errors_generator.c ../main.h
	gcc -O0 -g3 -Wall -c 3_errors_generator.c

clean:
	rm -rf 1_glibc_ver 2_error 3_errors_generator 4_test *.o *.out

all: 1_glibc_ver 2_error 3_errors_generator
