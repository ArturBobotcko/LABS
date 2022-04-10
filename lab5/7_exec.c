#include "../main.h"

int status;

int main(int argc, char* argv[], char* envp[]) {
	
	pid_t childPid = fork();
	switch (childPid) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			if (execve("./envs", argv, envp) == -1) {
				perror("execve");
				exit(EXIT_FAILURE);
			}
		default:
			if (waitpid(childPid, &status, 0) == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			printf("\nThe child process return value is %s\n", (WIFEXITED(status) ? "SUCCESS" : "FAILURE"));
			exit(EXIT_SUCCESS);
	}
	return 0;
}