#include "../main.h"
#include "stack.h"
#include <semaphore.h>

#define PRODUCER_NUM 2
#define CONSUMER_NUM 2
#define STACK_MAX 100

pthread_mutex_t mutex;
sem_t available_slots;
sem_t occupied_slots;

stack* head = NULL;
int stack_size = 0;

void* producer() {
	while(TRUE) {
		int a = rand () % 100;
		int b = rand () % 100;
		sem_wait(&available_slots);
		pthread_mutex_lock(&mutex);
		head = PUSH(head, &a, &b, sizeof(int));
		stack_size++;
		pthread_mutex_unlock(&mutex);
		sem_post(&occupied_slots);
	}
}

void* consumer() {
	while(TRUE) {
		int a, b, c;
		sem_wait(&occupied_slots);
		pthread_mutex_lock(&mutex);
		sleep(1);
		head = POP(head, &a, &b, sizeof(int));
		stack_size--;
		c = a + b;
		// printf("Количество занятых слотов: %d | %d + %d = %d\n", stack_size, a, b, c);
		printf("%d + %d = %d\n", a, b, c);
		pthread_mutex_unlock(&mutex);
		sem_post(&available_slots);
	}
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int THREADS_NUM = PRODUCER_NUM + CONSUMER_NUM;
	pthread_t threads[THREADS_NUM];
	for (int i = 0; i < THREADS_NUM; i++) {
		threads[i] = 0;
	}

	sem_init(&available_slots, 0, STACK_MAX);
	sem_init(&occupied_slots, 0, 0);

	pthread_mutex_init(&mutex, NULL);
	int ret, i, j;
	for (i = 0; i < PRODUCER_NUM; i++) {
		ret = pthread_create(
			&threads[i],
			NULL,
			&producer,
			NULL
		);
		if (ret != 0) {
			perror("Error creating a thread\n");
			return -1;
		}
	}

	for (j = 0; j < CONSUMER_NUM; j++) {
		ret = pthread_create(
			&threads[j+i],
			NULL,
			&consumer,
			NULL
		);
		if (ret != 0) {
			perror("Error creating a thread\n");
			return -1;
		}
	}

	for (int i = 0; i < THREADS_NUM; i++) {
		if (pthread_join(threads[i], NULL) != 0) {
			perror("Error joining a thread\n");
			return -1;
		}
	}

	sem_destroy(&available_slots);
	sem_destroy(&occupied_slots);
	pthread_mutex_destroy(&mutex);
	return 0;
}