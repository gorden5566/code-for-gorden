/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 00时16分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    StackWithMin<int> istack;

    for (int i = 7; i >= 1; --i) {
        istack.push(i);
    }

    for (int i = 1; i <= 7; ++i) {
        cout << istack.min() << " ";
        istack.pop();
    }
    cout << endl;

    int arr_push[] = {1, 2, 3, 4, 5};
    int arr_pop1[] = {4, 5, 3, 2, 1};
    int arr_pop2[] = {4, 3, 5, 1, 2};
    int n = sizeof(arr_push) / sizeof(int);
    cout << is_pop_order(arr_push, arr_pop1, n) << endl;
    cout << is_pop_order(arr_push, arr_pop2, n) << endl;
    
    return 0;
}
