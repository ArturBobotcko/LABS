#include "../main.h"

int main(int argc, char* argv[], char* envp[]) {
	pid_t pid = fork();
	switch (pid) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			if (execve("./sort_thread_for_2", argv, envp) == -1) {
				perror("execve");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		default:
			if (waitpid(pid, NULL, 0) == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
	}
	return 0;
}