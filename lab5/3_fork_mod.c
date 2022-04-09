#include "../main.h"

int num = 0;

void exitFunc(void) {
	num = 0;
	printf("The child process is being completed | num = %d\n", num);
}

int main(int argc, char* argv[]) {
	pid_t pid = fork();

	switch (pid) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0: // Child
			num++;
			printf("This is child process. My pid is: %d | num = %d\n", getpid(), num);
			if (atexit(exitFunc) != 0) {
				perror("atexit");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		default: // Parent
			printf("This is parent process. My pid is: %d\n", getpid());
			exit(EXIT_SUCCESS);
	}
	return 0;
}