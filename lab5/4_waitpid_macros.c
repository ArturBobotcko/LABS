#include "../main.h"
int status;

int main(int argc, char* argv[]) {
	pid_t p1 = fork();
	switch (p1) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			printf("This is a child proccess\n");
			kill(getpid(), SIGKILL);
			//exit(EXIT_SUCCESS);
		default:
			if (waitpid(p1, &status, 0) == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			printf("This is a parent process\n\n");

			/* Тесты макросов waitpid */
			
			/* Было ли успешным завершение процесса */
			printf("Exit normally? %s\n", (WIFEXITED(status) ? "true" : "false"));

			/* Был ли процесс завершен сигналом */
			printf("Was a child procces terminated by a signal? %s\n", (WIFSIGNALED(status) ? "true" : "false"));

			/* Был ли процесс остановлен сигналом */
			printf("Was a child procces stopped by a signal? %s\n", (WIFSTOPPED(status) ? "true" : "false"));

			/*
			 * SIGCONT — сигнал, посылаемый для возобновления выполнения процесса,
			 * ранее остановленного сигналом SIGSTOP или другим сигналом (SIGTSTP, SIGTTIN, SIGTTOU).
			*/

			/* Был ли процесс возобновлял сигналом SIGCONT */
			printf("Was a child procces resumed by a SIGCONT? %s\n", (WIFCONTINUED(status) ? "true" : "false"));
			exit(EXIT_SUCCESS);
	}
	return 0;
}