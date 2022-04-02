#include "../main.h"

int main() {
	extern char** environ;
	char* str;
	int i = 0;
	char* Env = "Environment_Variable";
	printf(" #\t%-29s\tValue\n",Env);
	char** env1 = environ;
	char** env2 = environ;
	char** env3 = environ;

	/* Первоначальный вывод переменных окружения */
	while (*env1 != NULL) {
		// k1 - длина всей строки
		// k2 - длина имени переменной
		int j = 0, k1 = 0, k2 = 0, t = 0;
		str = *env1; // str - строка переменной окружения
		while(*str != '\0') { // Перебираем всю строку, чтобы узнать её длину
			str++;
			k1++;
		}

		str = *env1;
		
		while(*str != '=') { // Перебираем строку, чтобы узнать длину имени переменной
			str++;
			k2++;
		}
		
		str = *env1;
		char var[k1]; // Массив имени переменной
		while(*str != '\0') { // Записываем в массив переменной всю строку
			var[t++] = *str;
			str++;
		}

		char value[k1-k2]; // Массив значения переменной
		str = *env1;

		for(j=0; j < k1-k2-1; j++) // Записываем в массив значения значение переменной окружения
			value[j] = var[k2+j+1];
		 
		value[j] = '\0';
		
		for (int i = k2; i < k1; i++) { // Удаляем значение переменной из массив имени переменной
			var[i] = '\0';
		}

		printf("%2d\t%-29s\t%s\n",i,var,value);
		env1++;
		i++;
	}

	/* Примечание: далее используется точно такой же алгоритм для получения */
	/* имени переменной для её удаления, а также для повторного вывода всех переменных */

	int del = 0;
	printf("\nEnter a number of environment variable you want to delete: ");
	scanf("%d",&del); // Выбираем удаляемую переменную
	
	if (del > i) {
		printf("You entered a number that is more than quatity of environment variables\n");
		return 1;
	}
	i = 0;
	
	/* Удаление переменной из окружения */
	while(*env2 != NULL) {

		if (del == i) {
			int k1 = 0, k2 = 0, t = 0;
			str = *env2;
			while(*str != '\0') {
				str++;
				k1++;
			}

			str = *env2;
			
			while(*str != '=') {
				str++;
				k2++;
			}
			
			str = *env2;
			char var[k1];
			while(*str != '\0') {
				var[t++] = *str;
				str++;
			}

			for (int i = k2; i < k1; i++) {
				var[i] = '\0';
			}
			printf("%s\n",var);

			
			if(unsetenv(var) == -1) { // Удаляем переменную из окружения
				perror("unsetenv");
				return 1;
			}
			break;
		}
		i++;
		env2++;
	}

	printf("--------------------------------------------------\n");
	
	i = 0;

	/* Повторный вывод переменных окружения */
	while (*env3 != NULL) { 
		int j = 0, k1 = 0, k2 = 0, t = 0;
		str = *env3;
		while(*str != '\0') {
			str++;
			k1++;
		}

		str = *env3;
		
		while(*str != '=') {
			str++;
			k2++;
		}
		
		str = *env3;
		char var[k1];
		while(*str != '\0') {
			var[t++] = *str;
			str++;
		}

		char value[k1-k2];
		str = *env3;

		for(j=0; j < k1-k2-1; j++)
			value[j] = var[k2+j+1];
		 
		value[j] = '\0';
		
		for (int i = k2; i < k1; i++) {
			var[i] = '\0';
		}

		printf("%2d\t%-29s\t%s\n",i,var,value);
		env3++;
		i++;
	}
	return 0;
}