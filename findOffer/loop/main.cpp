/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 11时49分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "loop.h"
#include <iostream>

using namespace std;

int main()
{
    unsigned int n = 100;
    cout << "fibonacci " << n << " = " << fibonacci(n) << endl;

    cout << "number of 1 in " << n << " is " << number_of_one(n) << endl;

    /*
    int num[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    */
    int num[4][4];
    for (int i = 0; i < 16; ++i) {
        num[i/4][i%4] = i + 1;
    }

    int *nums[] = {num[0], num[1], num[2], num[3]};

    print_matrix_clockwise(nums, 4, 4);

    return 0;
}
