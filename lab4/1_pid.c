#include "../main.h"

int main() {
	pid_t pid = getpid();
	pid_t ppid = getppid();

	printf("PID: %d\nP_PID: %d\n",pid,ppid);
	
	return 0;
}