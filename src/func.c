#include "func.h"
#include "input.h"
#include <stdio.h>
#include <math.h>

double charToDigit(char* str, int i1, int i2)
{
    int power(int x, int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 1 / (x * power(1 / x, n + 1));
        return x * power(x, n - 1);
    }

    double Result = 0, doubles = 0;
    int i, d;
    for (i = i1; i <= i2; i++) {
        if (str[i] != '.')
            Result = (Result + (str[i] - '0')) * 10;
        else
            break;
    }
    Result = Result / 10;
    d = i;
    for (i = i + 1; i <= i2; i++)
        if (str[i] != '.')
            Result = Result + (doubles + (str[i] - '0')) / power(10, i - d);
        else
            break;
    return Result;
}

double Calculation(char* str, int Start, int End)
{
    int i = Start, OpenBr, CloseBr, openbr, closebr, Tmp = 0;

    if ((str[Start] == '(') && (str[End] == ')')) {
        OpenBr = 1;
        CloseBr = 0;
        i++;
        while (OpenBr != CloseBr) {
            if (str[i] == '(')
                OpenBr++;
            if (str[i] == ')')
                CloseBr++;
            i++;
        }
        i--;

        if (i == End)
            return Calculation(str, Start + 1, End - 1);
    }

    for (i = Start; i <= End; i++) {
        switch (str[i]) {
        case '+':
            return Calculation(str, Start, (i - 1))
                    + Calculation(str, (i + 1), End);
        case '-':
            if (i > Tmp)
                Tmp = i;
            break;
        case '*':
            if (Tmp == 0)
                Tmp = i;
            break;
        case '/':
            if ((Tmp == 0) || (str[Tmp] == '/'))
                Tmp = i;
            break;
        case '(':
            openbr = 1;
            closebr = 0;
            i++;
            while (openbr != closebr) {
                if (str[i] == '(')
                    openbr++;
                if (str[i] == ')')
                    closebr++;
                i++;
            }
            i--;
            break;
        }
    }
    if (Tmp > 0) {
        switch (str[Tmp]) {
        case '-':
            return Calculation(str, Start, Tmp - 1)
                    - Calculation(str, Tmp + 1, End);
        case '*':
            return Calculation(str, Start, Tmp - 1)
                    * Calculation(str, Tmp + 1, End);
        case '/':
            return Calculation(str, Start, Tmp - 1)
                    / Calculation(str, Tmp + 1, End);
        case '^':
            return pow(Calculation(str, Start, Tmp - 1),Calculation(str, Tmp + 1, End));
        case 's':
            return sqrt(Calculation(str, Start, Tmp));
        }
    }
    return charToDigit(str, Start, End);
}
