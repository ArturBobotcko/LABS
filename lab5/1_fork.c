#include "../main.h"

int main(int argc, char* argv[]) {
	pid_t pid = fork();

	switch (pid) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			printf("This is child process. My pid is: %d\n", getpid());
			break;
		default:
			printf("This is parent process. My pid is: %d\n", getpid());
			break;
	}
	return 0;
}