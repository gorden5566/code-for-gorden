/*
 * =====================================================================================
 *
 *       Filename:  singleNumber.cpp
 *
 *    Description:  single number
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 16时05分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <numeric>

using namespace std;

class Solution1
{
public:
	int singleNumber(int A[], int n)
	{
		int x = 0;
		for (int i = 0; i < n; ++i) {
			x ^= A[i];
		}

		return x;
	}
};

class Solution2
{
public:
	int singleNumber(int A[], int n)
	{
		//传递bit_xor给accumulate
		return accumulate(A, A + n, 0, bit_xor<int>());
	}
};

int main()
{
	int a[] = {15, 20, 31, 20, 15, 31, 44};
	int n = sizeof(a) / sizeof(a[0]);

	Solution1 s1;
	cout << s1.singleNumber(a, n) << endl;

	Solution2 s2;
	cout << s2.singleNumber(a, n) << endl;

	return 0;
}
