#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int compare (char ch, char *list) //Сравнение символа со списком
{
	int i;
	for (i = 0; list[i] != '\0'; i++)
	{
		if (ch == list[i])
			return 1;
	}
	return 0;
}

void input(char** str, int* mistake) //Ввод примера
{
	int i, j, open_brackets = 0;
	*str = malloc(sizeof(char) * 100);

	for (i = 0; ((*str)[i] = getchar()) != '\n'; i++)
	{
		if (compare ((*str)[i], "()-+/*.0123456789"))
		{
			if ((*str)[i] == '(') //Если скобка открывается
			{
				open_brackets++;
			}
			if ((*str)[i] == ')') //Если скобка закрывается
			{
				open_brackets--;
				if (open_brackets < 0) //Если закрытых скобок больше открытых
				{
					printf("Wrong input. Not found opened bracket before closed bracket.\n");
					*mistake = 1;
					return ;
				}
			}
		}
		else
		{
			printf("Wrong symbol.\n");
			*mistake = 1;
			return ;
		}
	}
	if (open_brackets) //Если открытых скобок больше закрытых
	{
		printf("Wrong input. Too many opened brackets.\n");
		*mistake = 1;
		return ;
	}
for (i = 0; (*str)[i] != '\0'; i++)
	{
		if (compare((*str)[i], "+/*") && (( (i == 0) || ((*str)[i + 1] =='\0') || ((*str)[i - 1] == '(') || ((*str)[i + 1] == ')') ) || ( (i > 0) && ((compare((*str)[i - 1], "+-/*")) || (compare((*str)[i + 1], "+-/*")))))) //Неправильное расположение знаков
		{
			printf("Wrong input. Symbol placement error.\n");
			*mistake = 1;
			return ;
		}
		if (((*str)[i] == '.') && (( i - 1 < 0) || (compare((*str)[i + 1], "-+/*") || compare((*str)[i - 1], "+-/*") || ((*str)[i + 1] == '\0') || ((*str)[i - 1] == '\0'))))//Неправильное расположение точки WIP
		{
			printf("Wrong input. \n");
		}
		if ((*str)[i] == '.')//Точка рядом со скобками
		{
			if (compare((*str)[i + 1], "()") || compare((*str)[i - 1], "()"))
			{
				printf("Wrong input. Dot before or after bracket. \n");
				*mistake = 1;
				return ;
			}
			for (j = i + 1; (*str)[j] != '\0'; j++)
			{
				if ((*str)[j] == '.')
				{
					printf("Wrong input. Double dot.\n");
					*mistake = 1;
					return ;
				}
			}
		}
		if (((*str)[i] == '(') && (i > 0))
		{
			if (compare((*str)[i - 1], "(+-/*"))
			{
				printf("Wrong input. Not found symbol before bracket.\n");
				*mistake = 1;
				return ;
			}
			if ((*str)[i + 1] == ')')
			{
				printf("Wrong input. Empty brackets.\n");
				*mistake = 1;
				return ;
			}
		}
		if (((*str)[i] == ')') && ((*str)[i + 1] != '\0'))
		{
			if (compare((*str)[i + 1], ")+-/*") == 0)
			{
				printf("Wrong input. Not found symbol after bracket.\n");
				*mistake = 1;
				return ;
			}
		}
	}
}
