#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "func.h"

void input(char **str,int* mistake);
double Calculation(char **str, int Start, int End);

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

	double result = Calculation(&str, 0, z - 1);
	printf("\t\t%s = %lf\n", str, result);

	return 0;
}
