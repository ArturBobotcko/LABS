#include "../main.h"
#include "stack.h"

pthread_mutex_t mutex;

// void produce(Node* head) {
	// pthread_mutex_lock(&mutex);
	// srand(time(NULL));
	// for (int i = 0; i < 2; i++) {
	// 	args[i] = malloc(sizeof(int));
	// 	if (args[i] == NULL) {
	// 		printf("No memory\n");
	// 		return;
	// 	}
	// }
	// int a = rand() % 100;
	// int b = rand() % 100;
	// stack_add(head, a, b);

	// pthread_mutex_unlock(&mutex);
	// return;
// }

/*int consume(int* args[2]) {
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		sum += *(args[i]);
	}
	return sum;
}*/

int main(int argc, char* argv[]) {
	stack* head = NULL;
	// int a = 1;
	// int b = 1;

	// head = PUSH(head,&a,&b,sizeof(int));
	// a = 2;
	// b = 2;
	// head = PUSH(head,&a,&b,sizeof(int));

	// print_stack(head);

	/*pthread_t p1, p2;
	int* args[2];

	pthread_mutex_init(&mutex, NULL);

	int ret = pthread_create(
		&p1,
		NULL,
		(void*)&produce,
		stack
	);

	if (ret != 0) {
		perror("Error creating a thread\n");
		return -1;
	}*/
	

	// ret = pthread_create(
	// 	&p2,
	// 	NULL,
	// 	(void*)&consume,
	// 	args
	// );

	// if (ret != 0) {
	// 	perror("Error creating a thread\n");
	// 	return -1;
	// }
	
	// if (pthread_join(p1, NULL) != 0) {
	// 	perror("Error joinig a thread\n");
	// 	return -2;
	// }

	// if (pthread_join(p2, (void**)&ret) != 0) {
	// 	perror("Error joinig a thread\n");
	// 	return -2;
	// }



	//printf("%d\n", ret);


	// pthread_mutex_destroy(&mutex);
	return 0;
}