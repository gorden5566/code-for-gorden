/*
 * =====================================================================================
 *
 *       Filename:  threeSumClosest.cpp
 *
 *    Description:  3sum closest
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 11时53分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &num, int target)
	{
		int result = 0;
		int min_gap = INT_MAX; //初始化为最大的整数

		sort(num.begin(), num.end()); //先排序

		for (vector<int>::iterator a = num.begin(); a != prev(num.end(), 2); ++a) {
			vector<int>::iterator b = next(a);
			vector<int>::iterator c = prev(num.end());

			while (b < c) { //两边夹击
				const int sum = *a + *b + *c;
				const int gap = abs(sum - target);

				if (gap < min_gap) { //找到一个更接近target的和
					result = sum;
					min_gap = gap;
				}

				if (sum < target)
					++b;
				else
					--c;
			}
		}

		return result;
	}
};

int main()
{
	int a[] = {-1, 2, 1, -4};
	int n = sizeof(a) / sizeof(a[0]);

	vector<int> ivec(a, a + n);

	Solution s;
	int result = s.threeSumClosest(ivec, 1);

	cout << result << endl;

	return 0;
}
