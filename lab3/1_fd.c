#include "../main.h"

int main() {
	if (close(0) == -1) {
		perror("close");
		return 1;
	}

	int fd = open("text.txt",O_RDONLY);

	if (fd < 0) {
		perror("open");
		return 2;
	}
	printf("Open return value is: %d\n",fd);
	
	return 0;
}