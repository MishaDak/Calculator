#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define BUFLEN 20
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


int checkLBracket (char l) 
{
	if(l == '(')
		return 1;
	else return 0;
}

int checkRBracket (char l)
{
	if(l == ')')
		return 1;
	else return 0;
}

int checkDigit(char l)
{
	if(l >= '0' && l <= '9') 
		return 1;
	else return 0;
}
int checkNum(char *str)
{
	while(*str)
	{
		if(!checkDigit(*p))
			return 0;
		str++;
	}
return 1;
}

int checkOperator(char l)
{	
	if( l == '+' || l == '-' || l == '*' || l == '/')
	return l;
	else return 0;
}

int performOp(int num1, int num2, char op)
{
	switch(op){
	case '+': return num1+num2;
	case '-': return num1-num2;
	case '*': return num1*num2;
	case '/':
		  if(num2 == 0){
			  printf("Неправильный ввод. Деление на ноль невозможно");
		  	//здесь должен быть выход
		  }
		return num1/num2;
	}

}

int calc(char* str)
{
if(checkNum(str) == 1)
	return atoi(p);

char leftOper[BUFLEN];
char rightoper[BUFLEN];


}

int grabLeftOper(char* str, char* oper)
{
int i;
	
for(i = 0;;)
{
if(checkDigit(*p)
		break;
		oper[i++] = str++;
}
return i;
}

int grabRightOper(char *str, char*oper)
{
while(checkDigit(*p)){
*oper++ = *str++;

}
return 0;
}


