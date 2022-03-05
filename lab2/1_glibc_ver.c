#include <gnu/libc-version.h>
#include <stdio.h>

/* Для определения версии glibc можно воспользоваться командой: */
/* ldd --version ldd */

int main() {
	const char* ver = gnu_get_libc_version();
	const char* rel = gnu_get_libc_release();
	printf("Версия glibc = %s\n",ver);
	printf("Релиз glibc = %s\n",rel);
}