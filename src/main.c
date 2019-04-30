#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "func.h"

void input(char **str,int* mistake, int* lenght);
double Calculation(char *str, int Start, int End);

int main()
{
	char* str = NULL;
	int mistake = 0, lenght = 0;

	input(&str, &mistake, &lenght);

	if (mistake == 0)
	{
	double result = Calculation(str, 0, lenght - 1);
	printf("\t\t%s = %lf\n", str, result);
	}

	return 0;
}
