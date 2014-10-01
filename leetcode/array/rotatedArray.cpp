/*
 * =====================================================================================
 *
 *       Filename:  rotatedArray.cpp
 *
 *    Description:  search in rotated sorted array
 *
 *        Version:  1.0
 *        Created:  2014年09月30日 16时00分38秒
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
	int search(int A[], int n, int target)
	{
		int first = 0;
		int last = n - 1;

		while (first <= last) {
			int mid = (first + last) / 2;

			if (A[mid] == target)
				return mid;

			if (A[first] <= A[mid]) { //左边为递增序列
				if (A[first] <= target && target < A[mid]) { //在左边的区间
					last = mid - 1;
				} else { //在右边的区间
					first = mid + 1;
				}
			} else { //右边为递增序列
				if (A[mid] < target && target <= A[last]) { //在右边
					first = mid + 1;
				} else { //在左边
					last = mid - 1;
				}
			}
		}

		return -1;
	}
};

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6};
	//int a[] = {4, 5, 6, 7, 0, 1, 2};
	int n = sizeof(a) / sizeof(a[0]);
	
	Solution s;

	cout << s.search(a, n, 5) << endl;
	
	return 0;
}
