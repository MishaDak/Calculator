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
#endif
