#include "calc.h"


char *input;

CTEST(Proverka_arifmeticheskih_dejstvij, CALCULATION) {
    const double exp1 = 12;

    strcpy(input, "12"); // Ввод неправильного формат
    double c1 = Calculation(input);

    ASSERT_EQUAL(exp1, c1);


}