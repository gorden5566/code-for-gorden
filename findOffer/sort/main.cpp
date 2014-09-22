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

void inverse_count();
void number_of_k();

int main()
{
    int arr[] = {2, 5, 4, 7, 3, 1, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, n);

    //quick_sort(arr, n, 0, n - 1);
	insert_sort(arr, n);
    print_arr(arr, n);

    //int ages[] = {};
	
	inverse_count();

	number_of_k();

    return 0;
}

void inverse_count()
{
    int arr[] = {7, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

	cout << inverse_pairs(arr, n) << endl;
}

void number_of_k()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << get_number_of_k(arr, n, 3) << endl;
}
