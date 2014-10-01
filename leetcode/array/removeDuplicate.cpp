/*
 * =====================================================================================
 *
 *       Filename:  removeDuplicate.cpp
 *
 *    Description:  remove duplicates from sorted array
 *
 *        Version:  1.0
 *        Created:  2014年09月29日 21时03分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution1
{
public:
	int removeDuplicate(int A[], int n)
	{
		if (n == 0)
			return 0;

		int index = 1;
		for (int i = 1; i < n; ++i) {
			if (A[index - 1] != A[i])
				A[index++] = A[i];
		}

		return index;
	}
};

class Solution2
{
public:
	int removeDuplicate(int A[], int n)
	{
		return distance(A, unique(A, A + n));
	}
};

class Solution3
{
public:
	int removeDuplicate(int A[], int n)
	{
		return removeDuplicate(A, A + n, A) - A;
	}

	template<typename InIt, typename OutIt>
	OutIt removeDuplicate(InIt first, InIt last, OutIt output)
	{
		while (first != last)
		{
			*output++ = *first;
			first = upper_bound(first, last, *first);
		}

		return output;
	}
};

int main()
{
	int a[] = {1, 1, 2};
	int n = sizeof(a) / sizeof(a[0]);

	Solution1 s1;
	cout << s1.removeDuplicate(a, n) << endl;;

	Solution2 s2;
	cout << s2.removeDuplicate(a, n) << endl;;

	Solution3 s3;
	cout << s3.removeDuplicate(a, n) << endl;;

	return 0;
}
