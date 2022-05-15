#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h> /* Определения типов, используемые многими программами */
#include <stdio.h> /* Стандартные функции ввода-вывода */
#include <stdlib.h> /* Прототипы наиболее востребованных библиотечных функций плюс константы EXIT_SUCCESS и EXIT_FAILURE */
#include <unistd.h> /* Прототипы многих системных вызовов */
#include <errno.h> /* Объявление errno и определение констант ошибок */
#include <string.h> /* Наиболее используемые функции обработки строк */
#include <unistd.h> /* Стандартные файловые дескрипторы и системные вызовы для манипуляций с файлами */
#include <fcntl.h> /* Системные вызов creat() */
#include <sys/wait.h> /* Системный вызов wait() */
#include <pthread.h> /* Потоки */
#include <signal.h> /* Сигналы */

typedef enum { FALSE, TRUE } Boolean;

#endif