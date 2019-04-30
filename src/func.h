#ifdef CALC_H
#define CALC_H

#include <stdlib.h>

int compare (char ch, char *list);

void input(char **str, int* mistake);

int checkLBracket(char l);

int checkRBracket(char l);

int checkDigit(char l);

int checkNum(char l);

int checkOperator(char l);

int performOp(int num1, int num2, char op);

int calc(char* str);

int grabLeftOper(char* str, char* oper);

int grabLeftOper(char* str, char* oper);
#endif
