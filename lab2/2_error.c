#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int fd = open("./1.txt",O_RDONLY); // Такого файла не существует
	if (fd == -1) { // Если возникли ошибки
		switch(errno) { // Код errno = 2, из man errno берем имя ошибки
			case ENOENT:
				perror("open");
				exit(EXIT_FAILURE);
				break;
		}
	}
	return 0;
}