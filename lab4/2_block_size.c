#include "../main.h"

int main() {
	extern char etext, edata, end;

	printf("%ld\n",&end-&edata); // Размер неинициализированных данных (bss)
	printf("%ld\n",&edata-&etext); // Размер инциализированных данных

	return 0;
}