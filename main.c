#include <stdio.h>
#include <stdlib.h>

#include "func.h"

void input(char** str);

int main()
{
	char* str = NULL;

	input(&str);


	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("%c", str[i]);
	}

	return 0;
}
