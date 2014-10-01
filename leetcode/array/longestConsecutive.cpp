/*
 * =====================================================================================
 *
 *       Filename:  longestConsecutive.cpp
 *
 *    Description:  longest consecutive sequence
 *
 *        Version:  1.0
 *        Created:  2014年10月01日 14时26分55秒
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
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int longestConsecutive(const vector<int> &num)
	{
		unordered_map<int, bool> used;

		for (auto i : num)
			used[i] = false;

		int longest = 0;

		for (auto i : num) {
			//i已经处理过
			if (used[i])
				continue;

			//i未处理，下面计算跟i相邻的连续数字个数
			int length = 1;
			used[i] = true;

			//计算大于i的连续数字个数
			for (int j = i + 1; used.find(j) != used.end(); ++j) {
				used[j] = true;
				++length;
			}

			//计算小于i的连续数组个数
			for (int j = i - 1; used.find(j) != used.end(); --j) {
				used[j] = true;
				++length;
			}

			//保存最大值
			longest = max(longest, length);
		}

		return longest;
	}
};

int main()
{
	int a[] = {100, 4, 200, 1, 3, 2};
	int n = sizeof(a) / sizeof(a[0]);

	vector<int> num(a, a + n);

	Solution s;

	cout << s.longestConsecutive(num) << endl;

	return 0;
}
