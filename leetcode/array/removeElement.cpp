/*
 * =====================================================================================
 *
 *       Filename:  removeElement.cpp
 *
 *    Description:  remove element
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 15时13分03秒
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
	int removeElement(int A[], int n, int elem)
	{
		int index = 0;
		for (int i = 0; i < n; ++i) {
			if (A[i] != elem) {
				A[index++] = A[i];
			}
		}

		return index;
	}
};

class Solution2
{
public:
	int removeElement(int A[], int n, int elem)
	{
		return distance(A, remove(A, A + n, elem));
	}
};

int main()
{
	int a[] = {1, 2, 1, 3, 4, 5};
	int n = sizeof(a) / sizeof(a[0]);

	//Solution1 s1;
	//cout << s1.removeElement(a, n, 1) << endl;

	Solution2 s2;
	cout << s2.removeElement(a, n, 1) << endl;

	return 0;
}
