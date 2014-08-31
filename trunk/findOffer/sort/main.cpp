/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2014 04:52:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "sort.h"
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {2, 5, 4, 7, 3, 1, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quick_sort(arr, n, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
