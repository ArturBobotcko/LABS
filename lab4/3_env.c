#include "../main.h"

/* Функция проверки, есть ли в строке знак = */
int IsThereEqualSign(char* string) {
	char* c = string;
	while (*c != '\0') {
		if (*c == '=') return 1;
		c = c + 1;
	}
	return 0;
}

/* А что должна делать программа, если ввести имя переменной, которая уже существует */
/* и попытаться изменить её значение? */
int main(int argc, char* argv[]) {
	extern char** environ;
	char* env;
	char* str;

	if(IsThereEqualSign(argv[1]) == 1) { // Если в аргументе есть знак =, то помещаем в среду
		int j = 0, k1 = 0, k2 = 0, t = 0;
		str = argv[1]; // str - строка переменной окружения
		while(*str != '\0') { // Перебираем всю строку, чтобы узнать её длину
			str++;
			k1++;
		}

		str = argv[1];
		
		while(*str != '=') { // Перебираем строку, чтобы узнать длину имени переменной
			str++;
			k2++;
		}
		
		str = argv[1];
		char var[k1]; // Массив имени переменной
		while(*str != '\0') { // Записываем в массив переменной всю строку
			var[t++] = *str;
			str++;
		}

		char value[k1-k2]; // Массив значения переменной
		str = argv[1];

		for(j=0; j < k1-k2-1; j++) // Записываем в массив значения значение переменной окружения
			value[j] = var[k2+j+1];
		 
		value[j] = '\0';
		
		for (int i = k2; i < k1; i++) { // Удаляем значение переменной из массив имени переменной
			var[i] = '\0';
		}

		/* Добавление переменной в окружение */
		if(setenv(var,value,0) != 0) {
			perror("setenv");
			return 1;
		}
	
		/* Вывод переменных окружения */
		while(*environ != NULL) {
			printf("%s\n",*environ);
			environ++;
		}
	} else {
		env = getenv(argv[1]);
		if (env != NULL) printf("The value of %s is %s\n",argv[1],env);
		else printf("There is no value for %s\n",argv[1]);
	}
	return 0; 
}