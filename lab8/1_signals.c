#include "../main.h"

void signal_handler(int sig) {
	printf("Received signal: %d\n", sig);
}

int main(int argc, char* argv[]) {
	if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
		perror("Error changing behavior of signal");
		return -1;
	}
	if (signal(SIGUSR2, signal_handler) == SIG_ERR) {
		perror("Error changing behavior of signal");
		return -1;
	}
	int i = 0;
	pid_t pid = fork();
	switch (pid) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			while (TRUE) {
				if (i % 2 == 0) {
					if (kill(getppid(), SIGUSR1) == -1) {
						perror("Error sending a signal");
						return -1;
					}
				} else {
					if (kill(getppid(), SIGUSR2) == -1) {
						perror("Error sending a signal");
						return -1;
					}
				}
				i++;
				sleep(5);
			}
			exit(EXIT_SUCCESS);
		default:
			waitpid(pid, NULL, 0);
			exit(EXIT_SUCCESS);
	}

	return 0;
}