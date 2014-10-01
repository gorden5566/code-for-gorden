/*
 * =====================================================================================
 *
 *       Filename:  maxProduct.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月25日 14时16分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int solution1(int arr[], int length);

int main()
{
	int arr[] = {1, 2, 2, 3, 4, 2, 5};
	int length = sizeof(arr) / sizeof(arr[0]);

	cout << solution1(arr, length) << endl;

	return 0;
}

/**
* @brief 求子数组的最大乘积
*
* @param arr[] 给定整形数组
* @param length 数组长度
*
* @return 
*/
int solution1(int arr[], int length)
{
	//pre[i]表示前i个元素的乘积
	int *pre = new int[length];
	//post[i]表示后(n-i)个元素的乘积
	int *post = new int[length];

	pre[0] = 1;
	for (int i = 1; i < length; ++i) {
		pre[i] = pre[i - 1] * arr[i - 1];
		//cout << pre[i] << " ";
	}

	post[length - 1] = 1;
	for (int i = length - 2; i >= 0; --i) {
		post[i] = post[i + 1] * arr[i + 1];
		//cout << post[i] << " ";
	}

	int *p = new int[length];
	for (int i = 0; i < length; ++i) {
		p[i] = pre[i] * post[i];
	}

	int max = p[0];
	for (int i = 1; i < length; ++i) {
		if (max < p[i])
			max = p[i];
	}

	delete pre;
	delete post;

	return max;
}
