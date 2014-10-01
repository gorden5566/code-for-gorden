/*
 * =====================================================================================
 *
 *       Filename:  medianSortedArray.cpp
 *
 *    Description:  median of two sorted arrays
 *
 *        Version:  1.0
 *        Created:  2014年10月01日 11时31分20秒
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
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total & 0x01) { //总数为奇数
			return find_kth(A, m, B, n, total / 2 + 1);
		} else { //总数为偶数
			return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0; 
		}
	}
private:
	static int find_kth(int A[], int m, int B[], int n, int k)
	{
		//使得最终调用时m>=n
		if (m > n)
			return find_kth(B, n, A, m, k);

		//数组A为空
		if (m == 0)
			return B[k - 1];

		//获取两个数组的最小值
		if (k == 1)
			return min(A[0], B[0]);

		//从2/k处划分
		int ia = min(k / 2, m);
		int ib = k - ia;

		//数组A取前ia个，数组B取前k-ia个
		if (A[ia - 1] < B[ib - 1]) {
			return find_kth(A + ia, m - ia, B, n, k - ia);
		} else if(A[ia - 1] > B[ib - 1]) {
			return find_kth(A, m, B + ib, n - ib, k - ib);
		} else {
			return A[ia - 1];
		}
	}
};

int main()
{
	int a[] = {1, 3, 4, 8};
	int m = sizeof(a) / sizeof(a[0]);

	int b[] = {2, 5, 7, 9};
	int n = sizeof(b) / sizeof(b[0]);

	Solution s;

	cout << s.findMedianSortedArrays(a, m, b, n) << endl;

	return 0;
}
