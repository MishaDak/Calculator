#include "func.h"
#include "Input.h"

double charToDigit(char *str, int i1, int i2)
{
	int power(int x, int n)
	{
		if(n == 0)
			return 1;
		if(n < 0)
			return 1 / (x * power (1 / x, n + 1));
		return x * power(x, n - 1);
	}

	double Result = 0, doubles = 0;
	int i, d;
	for (i = i1; i <= i2; i++)
	{
		if (str[i] != '.')
			Result = (Result + (str[i] - '0')) * 10;
		else
			break;
	}
	Result = Result / 10;
	d=i;
	for (i = i + 1; i <= i2; i++)
		if (str[i] != '.')
			Result = Result + (doubles + (str[i] - '0')) / power(10, i - d);
		else
			break;
	return Result;
}


