/*
 * =====================================================================================
 *
 *       Filename:  reorder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月31日 00时05分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "reorder.h"

void reorder_odd_even(int *pdata, unsigned int length)
{
   if (pdata == NULL || length <= 0) {
        return;
   }


   int *pbegin = pdata;
   int *pend = pdata + length - 1;

   while (pbegin < pend) {
        while (pbegin < pend && (*pbegin & 0x1) != 0) {
            pbegin++;
        }
        while (pbegin < pend && (*pend & 0x1) == 0) {
            pend--;
        }

        if (pbegin < pend) {
            int temp = *pbegin;
            *pbegin = *pend;
            *pend = temp;
        }
   }
}

void reorder(int *pdata, unsigned int length, bool (*func)(int))
{
   if (pdata == NULL || length <= 0) {
        return;
   }


   int *pbegin = pdata;
   int *pend = pdata + length - 1;

   while (pbegin < pend) {
        while (pbegin < pend && !func(*pbegin)) {
            pbegin++;
        }
        while (pbegin < pend && func(*pend)) {
            pend--;
        }

        if (pbegin < pend) {
            int temp = *pbegin;
            *pbegin = *pend;
            *pend = temp;
        }
   }
}

bool isEven(int n)
{
    return (n & 1) == 0;
}

void reorder_odd_even2(int *pdata, unsigned int length)
{
    reorder(pdata, length, isEven);
}

void print_arr(int arr[], int length)
{
    if (arr == NULL || length <= 0) {
        return;
    }

    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
