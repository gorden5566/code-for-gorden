/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月11日 22时15分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "other.h"
#include <iostream>

void least_numbers();
void greatest_sum();
void min_number();
void ugly_number();
void first_char();

int main()
{
	least_numbers();

	greatest_sum();

	min_number();

	ugly_number();

	first_char();

	return 0;
}

void least_numbers()
{
	int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> ivec(arr, arr + n);
	intSet leastNumbers;
	
	get_least_numbers(ivec, leastNumbers, 5);

	for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}

void greatest_sum()
{
	int arr[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int n = sizeof(arr) / sizeof(arr[0]);

	int result = find_greatest_sum_of_sub_array(arr, n);
	if (result == 0 && g_InvalidInput == true) {
		cout << "Invalid Input" << endl;
	} else {
		cout << result << endl;
	}
}

void min_number()
{
	int arr[] = {3, 32, 321};
	int n = sizeof(arr) / sizeof(arr[0]);
	print_min_number(arr, n);
}

void ugly_number()
{
	cout << get_ugly_number(1500) << endl;
}

void first_char()
{
	char str[] = "abaccdeff";
	cout << first_not_repeat_char(str) << endl;
}
