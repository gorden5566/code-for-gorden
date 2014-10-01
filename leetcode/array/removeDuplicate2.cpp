/*
 * =====================================================================================
 *
 *       Filename:  removeDuplicate2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月30日 11时42分58秒
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
		if (n <= 2)
			return n;

		int index = 2;
		for (int i = 2; i < n; ++i) {
			if (A[i] != A[index - 2])
				A[index++] = A[i];
		}

		return index;
	}
};

int main()
{
	int a[] = {1, 1, 1, 2, 2, 3};
	int n = sizeof(a) / sizeof(a[0]);

	Solution1 s1;
	cout << s1.removeDuplicate(a, n) << endl;
	
	return 0;
}
