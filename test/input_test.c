#include "../src/input.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

char *str;
int lenght;
int input(char** str, int* lenght);


CTEST(input_check, symbol_check) {
	strcpy(str, "qwerty");//Неправильные символы
	lenght = 6;
	int t1 = input(&str, &lenght);

	strcpy(str, "(1.1+1)-(1*1/1)^1");//Все разрешенные символы
	lenght = 15;
	int t2 = input(&str, &lenght);

	strcpy(str, "1+*1");//Неправильное расположение символов
	lenght = 4;
	int t3 = input(&str, &lenght);

	const int exp1 = 1;
	const int exp2 = 0;
	const int exp3 = 1;

	ASSERT_EQUAL(exp1, t1);
	ASSERT_EQUAL(exp2, t2);
	ASSERT_EQUAL(exp3, t3);
}

CTEST(input_check, bracket_check) {
	strcpy(str, "(1+1");//Открытых скобок больше закрытых
	lenght = 4;
	int t1 = input(&str, &lenght);

	strcpy(str, "1+1)");//Закрытых скобок больше открытых
	lenght = 4;
	int t2 = input(&str, &lenght);

	strcpy(str, "(1+1)1");//Нет символа после скобок
	lenght = 6;
	int t3 = input(&str, &lenght);

	strcpy(str, "1(1+1)");//Нет символа перед скобкой
	lenght = 6;
	int t4 = input(&str, &lenght);

	strcpy(str, "()");//Пустые скобки
	lenght = 2;
	int t5 = input(&str, &lenght);

	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 1;
	const int exp4 = 1;
	const int exp5 = 1;

	ASSERT_EQUAL(exp1, t1);
	ASSERT_EQUAL(exp2, t2);
	ASSERT_EQUAL(exp3, t3);
	ASSERT_EQUAL(exp4, t4);
	ASSERT_EQUAL(exp5, t5);
}

CTEST(input_check, dot_check) {
	strcpy(str, "1.+");//Неправильное расположение точки
	lenght = 3;
	int t1 = input(&str, &lenght);

	strcpy(str, "(1+1).");//Точка после скобок
	lenght = 6;
	int t2 = input(&str, &lenght);

	strcpy(str, ".(1+1)");//Точка перед скобками
	lenght = 6;
	int t3 = input(&str, &lenght);

	strcpy(str, "1..1");//Две точки
	lenght = 4;
	int t4 = input(&str, &lenght);

	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 1;
	const int exp4 = 1;

	ASSERT_EQUAL(exp1, t1);
	ASSERT_EQUAL(exp2, t2);
	ASSERT_EQUAL(exp3, t3);
	ASSERT_EQUAL(exp4, t4);
}
