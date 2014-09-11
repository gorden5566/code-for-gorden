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

int main()
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

	return 0;
}
