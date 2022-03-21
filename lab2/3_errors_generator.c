#include "../main.h"

int main() {
	int er = 0;
	while (er <= 133) { // 133 взял из GitHub`а
		if (strncmp("Unknown error",strerror(er),13) != 0) { // Не нужно выводить Unknown error
			printf("%d: %s\n",er,strerror(er));
		}
		er += 1;
	}
	return 0;
}