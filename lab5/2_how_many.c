#include "../main.h"

int main(int argc, char* argv[]) {
	
	/*
	 * Чтобы посчитать количество процессов нужно написать: ./2_how_many | wc -l
	 * Получается, что количество процессов созданных с помощью fork()
	 * будет равняться 2 в степени кол-во вызовов fork()
	 */

	pid_t pid1 = fork();
	pid_t pid2 = fork();
	pid_t pid3 = fork();
	pid_t pid4 = fork();
	pid_t pid5 = fork();


	printf("PID: %d\n", getpid());
	return 0;
}