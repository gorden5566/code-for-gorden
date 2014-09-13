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

using namespace std;

void odd_even();
void sentence();
void rotate_string();

int main()
{
	odd_even();

	sentence();

	rotate_string();

    return 0;
}

void odd_even()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, n);

    //reorder_odd_even(arr, n);
    reorder_odd_even2(arr, n);
    print_arr(arr, n);
}

void sentence()
{
	char str[] = "I am a student.";	
	cout << reverse_sentence(str) << endl;
}

void rotate_string()
{
	char str[] = "abcdefg";
	cout << left_rotate_string(str, 2) << endl;
}
