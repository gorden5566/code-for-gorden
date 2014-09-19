/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月19日 11时34分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "heap.h"
#include <iostream>

using namespace std;

void print_arr(int arr[], int n);

int main()
{
	int arr[] = {9, 12, 17, 30, 50, 20, 60, 65, 4, 49};
	int n = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, n);

	make_min_heap(arr, n);
	print_arr(arr, n);

	min_heap_sort(arr, n);
	print_arr(arr, n);

	return 0;
}

void print_arr(int arr[], int n)
{
	if (arr != NULL && n > 0) {
		for (int i = 0; i < n; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}
