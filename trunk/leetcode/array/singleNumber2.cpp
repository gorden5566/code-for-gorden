/*
 * =====================================================================================
 *
 *       Filename:  singleNumber2.cpp
 *
 *    Description:  single number II
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 16时39分25秒
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

class Solution1
{
public:
	int singleNumber(int A[], int n)
	{
		const int bits = sizeof(int) * 8;
		int count[bits];
		fill_n(&count[0], bits, 0); //数组初始化
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < bits; ++j) { //处理A[i]的每一位
				count[j] += (A[i] >> j) & 1;
				count[j] %= 3; //是3的倍数时置0
			}
		}

		int result = 0;
		for (int i = 0; i < bits; ++i) {
			result += (count[i] << i);
		}

		return result;
	}
};

class Solution2
{
public:
	int singleNumber(int A[], int n)
	{
		int one = 0;
		int two = 0;
		int three = 0;

		for (int i = 0; i < n; ++i) {
			two |= (one & A[i]);
			one ^= A[i];
			three = ~(one & two);
			one &= three;
			two &= three;
		}

		return one;
	}
};

int main()
{
	int a[] = {15, 20, 15, 20, 15, 20, 44};
	int n = sizeof(a) / sizeof(a[0]);

	Solution1 s1;
	cout << s1.singleNumber(a, n) << endl;

	Solution2 s2;
	cout << s2.singleNumber(a, n) << endl;

	return 0;
}
