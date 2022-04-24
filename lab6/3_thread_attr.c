#include "../main.h"

void* command(void* p) {
	printf("Hello from command thread\n");
	pthread_exit((void *)100);
}

int main(int argc, char* argv[]) {
	int retval = 0, err;
	pthread_t thread;
	pthread_attr_t attr;
	
	err = pthread_attr_init(&attr);
	if (err != 0) {
		perror("pthread_attr_init");
		return -1;
	}
	err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	int pt = pthread_create(
		&thread,
		&attr,
		command,
		NULL
	);
	pthread_attr_destroy(&attr);
	pthread_join(thread, (void*)&retval);

	printf("retval = %d\n\n", retval);

	pt = pthread_create(
		&thread,
		NULL,
		command,
		NULL
	);

	pthread_join(thread, (void*)&retval);

	printf("retval = %d\n", retval);

	return 0;
}