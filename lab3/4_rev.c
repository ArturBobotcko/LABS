#include "../main.h"
#define SIZE 50000

int main(int argc, char* argv[]) {
	char buf[SIZE] = {'\0'};
	int k = 0;
	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDONLY);
		
		if (fd < 0) {
			perror(argv[i]);
			return 1;
		}

		int bytes;
		off_t t = lseek(fd, -1, SEEK_END); // Ставим смещение на последний байт файла
		while (t >= 0) {
			bytes = read(fd, &buf[k], 1); // Считываем по 1 байту (1 символу)
			if (bytes == -1) {
				perror(argv[i]);
				return 2;
			}
			t = lseek(fd, -2, SEEK_CUR); // Смещаемся от конца к началу по 1 байту
			k++;
		}
		
		if (close(fd) == -1) {
			perror(argv[i]);
			return 3;
		}
	}

	for (int i = 0; i < SIZE; i++) { // Вывод буфера
			printf("%c",buf[i]);
	}

	return 0;
}