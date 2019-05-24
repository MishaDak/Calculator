#include "../src/input.h"
#include "../src/func.h"
#include "../thirdparty/ctest.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

double Calculation(char* str, int Start, int End);

char *input;

CTEST(Clogenie, CALCULATION) {

    const double exp1 = 12;
    const double exp2 = 17;
    const double exp3 = 1082;
    const double exp4 = 201;

    input = malloc(10);


    strcpy(input, "12");
    int s1 = strlen(input);
    double c1 = Calculation(input, 0, s1 - 1);

    strcpy(input,"12+5");
    int s2 = strlen(input);
    double c2 = Calculation(input, 0, s2 - 1);

    strcpy(input,"1018+59+5");
    int s3 = strlen(input);
    double c3 = Calculation(input, 0, s3 - 1);

    strcpy(input,"85+116");
    int s4 = strlen(input);
    double c4 = Calculation(input, 0, s4 - 1);


    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(Vichitanie, CALCULATION) {

    const double exp1 = 13;
    const double exp2 = 124;
    const double exp3 = 954;
    const double exp4 = 69;

    input = malloc(10);

    strcpy(input, "18-5");
    int s1 = strlen(input);
    double c1 = Calculation(input, 0, s1 - 1);

    strcpy(input,"175-51");
    int s2 = strlen(input);
    double c2 = Calculation(input, 0, s2 - 1);

    strcpy(input,"1018-59-5");
    int s3 = strlen(input);
    double c3 = Calculation(input, 0, s3 - 1);

    strcpy(input,"185-116");
    int s4 = strlen(input);
    double c4 = Calculation(input, 0, s4 - 1);


    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(Ymnojenie, CALCULATION1) {

    const double exp1 = 60;
    const double exp2 = 224;
    const double exp3 = 1527;
    const double exp4 = -85;

    input = malloc(10);


    strcpy(input, "12*5");
    int s1 = strlen(input);
    double c1 = Calculation(input, 0, s1 - 1);

    strcpy(input,"16*14");
    int s2 = strlen(input);
    double c2 = Calculation(input, 0, s2 - 1);

    strcpy(input,"1018*1.5");
    int s3 = strlen(input);
    double c3 = Calculation(input, 0, s3 - 1);

    strcpy(input,"85*(-1)");
    int s4 = strlen(input);
    double c4 = Calculation(input, 0, s4 - 1);


    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(Delenie, CALCULATION) {

    const double exp1 = 6;
    const double exp2 = 24;
    const double exp3 = 72.71428;
    const double exp4 = -17;

    input = malloc(10);


    strcpy(input, "12/2");
    int s1 = strlen(input);
    double c1 = Calculation(input, 0, s1 - 1);

    strcpy(input,"12/0.5");
    int s2 = strlen(input);
    double c2 = Calculation(input, 0, s2 - 1);

    strcpy(input,"1018/2/7");
    int s3 = strlen(input);
    double c3 = Calculation(input, 0, s3 - 1);

    strcpy(input,"85/(-5)");
    int s4 = strlen(input);
    double c4 = Calculation(input, 0, s4 - 1);


    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(Stepen, CALCULATION) {

    const double exp1 = 144;
    const double exp2 = 216699865625;
    const double exp3 = 31.9061;
    const double exp4 = 0.0117;

    input = malloc(10);


    strcpy(input, "12^2");
    int s1 = strlen(input);
    double c1 = Calculation(input, 0, s1 - 1);

    strcpy(input,"185^5");
    int s2 = strlen(input);
    double c2 = Calculation(input, 0, s2 - 1);

    strcpy(input,"1018^0.5");
    int s3 = strlen(input);
    double c3 = Calculation(input, 0, s3 - 1);

    strcpy(input,"85^(-1)");
    int s4 = strlen(input);
    double c4 = Calculation(input, 0, s4 - 1);


    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}
