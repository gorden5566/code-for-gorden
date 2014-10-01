/*
 * =====================================================================================
 *
 *       Filename:  rotatedArray2.cpp
 *
 *    Description:  search in rotated sorted array II
 *
 *        Version:  1.0
 *        Created:  2014年10月01日 09时39分21秒
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

class Solution
{
public:
	bool search(int A[], int n, int target)
	{
		int first = 0;
		int last = n - 1;

		while (first <= last) {
			int mid = (first + last) / 2;
			if (A[mid] == target) {
				return true;
			}

			if (A[mid] > A[first]) { //左边递增
				if (target >= A[first] && target < A[mid]) { //在左边的区间
					last = mid - 1;
				} else { //在右边的区间
					first = mid + 1;
				}
			} else if (A[mid] < A[first]) { //右边递增
				if (target > A[mid] && target <= A[last]) { //在右边的区间
					first = mid + 1;	
				} else { //在左边的区间
					last = mid - 1;
				}
			} else { //忽略重复值
				first++;
			}
		}

		return false;
	}
};

int main()
{
	int a[] = {1, 2, 3, 1, 1, 1};
	int n = sizeof(a) / sizeof(a[0]);

	int value = 3;

	Solution s;
	cout << "value : " << value << endl;
	if (s.search(a, n, value)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	return 0;
}
