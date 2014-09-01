/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月31日 00时12分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "reorder.h"
#include <iostream>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, n);

    //reorder_odd_even(arr, n);
    reorder_odd_even2(arr, n);
    print_arr(arr, n);

    return 0;
}
