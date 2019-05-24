#include "calc.h"

char *str[100];
char *list = "0123456789+-/*^";
int lenght;
int input(char** str, int* lenght);
int compare(char ch, char* list);

CTEST(input_check, compare_check) {
	strcpy(*str, "1+2q");
	int t1 = compare((*str)[1], list);
	int t2 = compare((*str)[2], list);
	int t3 = compare((*str)[3], list);
	int t4 = compare((*str)[4], list);

	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 1;
	const int exp4 = 0;

	ASSERT_EQUAL(exp1, t1);
	ASSERT_EQUAL(exp2, t2);
	ASSERT_EQUAL(exp3, t3);
	ASSERT_EQUAL(exp4, t4);
}

CTEST(input_check, symbol_check) {
	strcpy((*str), "qwerty");//Неправильные символы
	lenght = 6;
	int t1 = input(&str[100], &lenght);

	strcpy(*str, "(1.1+1)-(1*1/1)^1");//Все разрешенные символы
	lenght = 15;
	int t2 = input(&str[100], &lenght);

	strcpy(*str, "1+*1");//Неправильное расположение символов
	lenght = 4;
	int t3 = input(&str[100], &lenght);

	const int exp1 = 1;
	const int exp2 = 0;
	const int exp3 = 1;

	ASSERT_EQUAL(exp1, t1);
	ASSERT_EQUAL(exp2, t2);
	ASSERT_EQUAL(exp3, t3);
}

CTEST(input_check, bracket_check) {
	strcpy(*str, "(1+1");//Открытых скобок больше закрытых
	lenght = 4;
	int t1 = input(&str[100], &lenght);

	strcpy(*str, "1+1)");//Закрытых скобок больше открытых
	lenght = 4;
	int t2 = input(&str[100], &lenght);

	strcpy(*str, "(1+1)1");//Нет символа после скобок
	lenght = 6;
	int t3 = input(&str[100], &lenght);

	strcpy(*str, "1(1+1)");//Нет символа перед скобкой
	lenght = 6;
	int t4 = input(&str[100], &lenght);

	strcpy(*str, "()");//Пустые скобки
	lenght = 2;
	int t5 = input(&str[100], &lenght);

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
	strcpy(*str, "1.+");//Неправильное расположение точки
	lenght = 3;
	int t1 = input(&str[100], &lenght);

	strcpy(*str, "(1+1).");//Точка после скобок
	lenght = 6;
	int t2 = input(&str[100], &lenght);

	strcpy(*str, ".(1+1)");//Точка перед скобками
	lenght = 6;
	int t3 = input(&str[100], &lenght);

	strcpy(*str, "1..1");//Две точки
	lenght = 4;
	int t4 = input(&str[100], &lenght);

	const int exp1 = 1;
	const int exp2 = 1;
	const int exp3 = 1;
	const int exp4 = 1;

	ASSERT_EQUAL(exp1, t1);
	ASSERT_EQUAL(exp2, t2);
	ASSERT_EQUAL(exp3, t3);
	ASSERT_EQUAL(exp4, t4);
}
