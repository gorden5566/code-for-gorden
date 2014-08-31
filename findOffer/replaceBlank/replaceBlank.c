/*
 * =====================================================================================
 *
 *       Filename:  replace_blank.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2014 04:28:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

#define MAX_NUM 30

void replace_blank(char string[], int length)
{
    if (string == NULL || length <= 0)
        return;

    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0') {
        ++originalLength;
        if (string[i] == ' ') {
            ++numberOfBlank;
        }
        ++i;
    }

    int newLength = originalLength + 2 * numberOfBlank;
    if (newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;

    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if (string[indexOfOriginal] == ' ') {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        } else {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}

int main()
{
    char str[MAX_NUM] = "We are happy.";

    printf("original string: %s\n", str);
    replace_blank(str, MAX_NUM);
    printf("new string: %s\n", str);

    return 0;
}
