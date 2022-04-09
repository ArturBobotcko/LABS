#include "../main.h"

int main(int argc, char* argv[]) {
	char cmd[4096];
	pid_t childPid;
	printf("Parent PID = %ld\n", (long)getpid());

	switch (childPid = fork()) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			printf("Child PID  = %ld\n", (long)getpid());
			exit(EXIT_SUCCESS);
		default:
			sleep(3);
			printf("\nFirst ps:\n");
			system("ps");
			if (kill(childPid, SIGKILL) == -1) {
				perror("kill");
				exit(EXIT_FAILURE);
			}
			printf("\n");
			sleep(3);
			printf("ps after sending a kill signal:\n");
			system("ps");

			if (waitpid(childPid, NULL, 0) == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			printf("\n");
			sleep(3);
			printf("ps after waitpid():\n");
			system("ps");

			exit(EXIT_SUCCESS);
	}
	return 0;
}