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
void nums_appear_once();
void numbers_with_sum();
void continuous_sequence();

int main()
{
	least_numbers();

	greatest_sum();

	min_number();

	ugly_number();

	first_char();

	nums_appear_once();

	numbers_with_sum();

	continuous_sequence();

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

void nums_appear_once()
{
	int arr[] = {2, 4, 3, 6, 3, 2, 5, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	int num1 = 0;
	int num2 = 0;
	find_nums_appear_once(arr, n, &num1, &num2);

	cout << "num1: " << num1 << ", num2: " << num2 << endl;
}

void numbers_with_sum()
{
	int arr[] = {1, 2, 4, 7, 11, 15};
	int n = sizeof(arr) / sizeof(arr[0]);

	int num1 = 0;
	int num2 = 0;
	find_numbers_with_sum(arr, n, 15, &num1, &num2);

	cout << "num1: " << num1 << ", num2: " << num2 << endl;
}

void continuous_sequence()
{
	find_continuous_sequence(15);
}
