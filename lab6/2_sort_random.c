#include "../main.h"

void* sortNumbers(void* arg) {
	int fd = *((int*)(arg));
	off_t size = lseek(fd, 0, SEEK_END); // В конец ставим указатель, чтобы узнать размер файла
	if (size == -1) {
		perror("lseek");
		pthread_exit((void*)-1);
	}

	if (lseek(fd, 0, SEEK_SET) == -1) { // Возвращаем обратно в начало файла
		perror("lseek");
		pthread_exit((void*)-1);
	}

	char buf[size+1];
	char buf2[size+1];
	buf[size+1] = '\0';
	buf2[size+1] = '\0';
	
	if (read(fd, buf, size) == -1) { // Считываем файл
		perror("read");
		pthread_exit((void*)-1);
	}
	
	if (lseek(fd, 0, SEEK_SET) == -1) { // Возвращаем в начало
		perror("lseek");
		pthread_exit((void*)-1);
	}
	
	if (read(fd, buf2, size) == -1) { // Считываем еще раз
		perror("read");
		pthread_exit((void*)-1);
	}
	
	int t = 0;
	char* s = strtok(buf, " \n"); // Разделяем строку по разделителю "пробел"
	while (s != NULL) {
		s = strtok(NULL, " \n");
		t++; // Считаем кол-во чисел
	}
	
	int ar[t];
	t = 0;
	
	char* s2 = strtok(buf2, " \n");
	while (s2 != NULL) {
		sscanf(s2, "%d", &ar[t]); // Вписываем числа в массив
		s2 = strtok(NULL, " \n");
		t++;
	}

	/* Метод пузырька */
	/* С конца массива переносит меньшее число в начало */
	for (int i = 0; i < t-1; i++) {
		for (int j = t-2; j >= i; j--) {
			if (ar[j] > ar[j+1]) {
				int tmp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = tmp;
			}
		}
	}

	/* Вывод массива */
	for (int i = 0; i < t; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");

	pthread_exit((void*)0);
}

int main(int argc, char* argv[]) {
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		return -1;
	}
	
	pthread_t command_thread;

	int thr = pthread_create(
		&command_thread,
		NULL,
		sortNumbers,
		&fd
	);

	if (thr != 0) {
		perror("pthread_create");
		return -1;
	}

	int iret, tryCount = 1;
	label: 
		iret = pthread_tryjoin_np(
		command_thread,
		NULL
	);
	if ((iret != 0) && (iret != EBUSY)) {
		perror("pthread_tryjoin_np");
		return -1;
	}
	if (iret == EBUSY) {
		if (tryCount == 6) {
			printf("The thread is busy. Returning...\n");
			return 1;
		}
		printf("[%d]\n",tryCount);
		
		if (usleep(1000000) == -1) {
			perror("usleep");
			return -1;
		}
		tryCount++;
		goto label;
	}
	if (iret == 0) {}
	
	if (close(fd) == -1) {
		perror("close");
		return -1;
	}
	return 0;
}