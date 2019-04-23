#include <stdio.h>
#include <stdlib.h>

#include "func.h"

void input(char** str, int* mistake);

int main()
{
	char* str = NULL;
	int mistake = 0;

	input(&str, &mistake);

	if (mistake == 0)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			printf("%c", str[i]);
		}
	}

	return 0;
}
