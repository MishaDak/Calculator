#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int compare (char ch, char *list) //��������� ������� �� �������
{
	int i;
	for (i = 0; list[i] != '\0'; i++)
	{
		if (ch == list[i])
			return 1;
	}
	return 0;
}

void input(char** str) //���� �������
{
	int i, open_brackets = 0;
	*str = malloc(sizeof(char) * 100);

	for (i = 0; ((*str)[i] = getchar()) != '\n'; i++)
	{
		if (compare ((*str)[i], "()-+/*.0123456789"))
		{
			if ((*str)[i] == '(') //���� ������ �����������
			{
				open_brackets++;
			}
			if ((*str)[i] == ')') //���� ������ �����������
			{
				open_brackets--;
				if (open_brackets < 0) //���� �������� ������ ������ ��������
				{
					printf("Wrong input. Not found opened bracket before closed bracket.\n");
					return ;
				}
			}
		}
		else
		{
			printf("Wrong symbol.\n");
			return ;
		}
	}
	if (open_brackets) //���� �������� ������ ������ ��������
	{
		printf("Wrong input. Too many opened brackets.\n");
		return ;
	}
}