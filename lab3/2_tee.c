#include "../main.h"
#define SIZE 50000

/* Функция очистики буфера, куда считывается введеный текст */
void clear_buf(char buf[], int bytes) {
	for (int i = 0; i < bytes; i++) {
		buf[i] = '\0';
	}
}

int main() {
	char string[SIZE] = {'\0'};
	while (TRUE) {
		int bytes = read(STDIN_FILENO, &string[0], SIZE);
		if (bytes == -1) {
			perror("read");
			return 1;
		}
		if (write(STDOUT_FILENO, &string[0], bytes) == -1) {
			perror("write");
			return 2;
		}
		clear_buf(string, bytes);
	}

	return 0;
}