/*
 * =====================================================================================
 *
 *       Filename:  threeSum.cpp
 *
 *    Description:  3Sum
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 10时45分11秒
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

using namespace std;

class Solution
{
public:
	vector< vector<int> > threeSum(vector<int> &num)
	{
		vector< vector<int> > result;

		if (num.size() < 3)
			return result;

		sort(num.begin(), num.end()); //先进行排序

		const int target = 0;

		vector<int>::iterator last = num.end();
		for (vector<int>::iterator a = num.begin(); a < prev(last, 2); ++a) {
			vector<int>::iterator b = next(a); //b从前往后走
			vector<int>::iterator c = prev(last); //c从后往前走

			while (b < c) {
				if (*a + *b + *c < target) {
					++b;
				} else if (*a + *b + *c > target) {
					--c;
				} else { //找到一组值
					result.push_back({*a, *b, *c});
					++b;
					--c;
				}
			}
		}

		sort(result.begin(), result.end()); //排序
		result.erase(unique(result.begin(), result.end()), result.end()); //去掉重复的结果

		return result;
	}
};

int main()
{
	int a[] = {-1, 0, 1, 2, -1, -4};
	int n = sizeof(a) / sizeof(a[0]);

	vector<int> ivec(a, a + n);

	Solution s;
	vector< vector<int> > result = s.threeSum(ivec);

	for (int i = 0; i < result.size(); ++i) {
		for (vector<int>::iterator iter = result[i].begin(); iter != result[i].end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}

	return 0;
}
