#include "../main.h"
#define SIZE 50000

/* argv[1] - первый файл */
/* argv[2] - второй файл */
int main(int argc, char* argv[]) {
	char buffer[SIZE];
	if (argc == 1) {
		printf("Не указаны файлы\n");
		return 1;
	}

	if (argc > 3) {
		printf("Нельзя указать больше 2-х файлов\n");
		return 2;
	}

	int FILE_1 = open(argv[1], O_RDONLY); // Открываем первый файл на чтение
	if (FILE_1 < 0) {
		perror(argv[1]);
		return 3;
	}

	int FILE_2 = open(argv[2], O_WRONLY); // Открываем второй файл на запись
	if (FILE_2 < 0) {
		perror(argv[2]);
		return 4;
	}
	
	int bytes = read(FILE_1, &buffer[0], SIZE); // Считываем данные из первого файла
	if (bytes == -1) {
		perror(argv[1]);
		return 5;
	}

	if (write(FILE_2, &buffer[0], bytes) == -1) { // Записываем считанные данные во второй файл
		perror(argv[2]);
		return 6;
	}

	if (close(FILE_1) == -1) {
		perror(argv[1]);
		return 7;
	}

	if (close(FILE_2) == -1) {
		perror(argv[2]);
		return 8;
	}

	return 0;
}