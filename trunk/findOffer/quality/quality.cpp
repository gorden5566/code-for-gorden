/*
 * =====================================================================================
 *
 *       Filename:  quality.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 16时03分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "quality.h"

bool g_InvalidInput = false;

double power(double base, int exponent)
{
    g_InvalidInput = false;

    if (equal(base, 0.0) && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0) {
        absExponent = (unsigned int)(-exponent);
    }

    //double result = power_with_unsigned_exponent(base, absExponent);
    double result = power_with_unsigned_exponent_recurse(base, absExponent);
    if (exponent < 0) {
        result = 1.0 / result;
    }

    return result;
}

double power_with_unsigned_exponent(double base, unsigned int exponent)
{
    double result = 1.0;
    for (unsigned int i = 1; i <= exponent; ++i) {
        result *= base;
    }

    return result;
}

double power_with_unsigned_exponent_recurse(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = power_with_unsigned_exponent_recurse(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1) {
        result *= base;
    }

    return result;
}

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

void print_one_to_max(int n)
{
    if (n < 0)
        return ;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!increment(number)) {
        print_number(number);
    }
    std::cout << std::endl;

    delete []number;
}

bool increment(char *number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);

    for (int i = nLength - 1; i >= 0; --i) {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1) //the lowest position
            nSum++;

        if (nSum >= 10) { //need take over
            if (i == 0) {
                isOverflow = true;
            } else {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }

        } else {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}

void print_number(char *number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i) {
        if (isBeginning0 && number[i] != '0') {
            isBeginning0 = false;
        }
        if (!isBeginning0) {
            std::cout << number[i];
        }
    }
    std::cout << " ";
}

void print_one_to_max2(int n)
{
    if (n < 0)
        return;
    char *number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i) {
        number[0] = i + '0';
        print_one_to_max_recurse(number, n, 0);
    }

    delete []number;
}

void print_one_to_max_recurse(char *number, int length, int index)
{
    if (index == length - 1) {
        print_number(number);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        number[index + 1] = i + '0';
        print_one_to_max_recurse(number, length, index + 1);
    }

}
