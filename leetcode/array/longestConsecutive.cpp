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

class Solution1
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

class Solution2
{
public:
	int longestConsecutive(vector<int> &num)
	{
		unordered_map<int, int> map;
		int size = num.size();
		int l = 1;

		for (int i = 0; i < size; ++i) {
			if (map.find(num[i]) != map.end())
				continue;

			map[num[i]] = 1;
			if (map.find(num[i] - 1) != map.end()) {
				l = max(l, mergeCluster(map, num[i] - 1, num[i]));
			}

			if (map.find(num[i] + 1) != map.end()) {
				l = max(l , mergeCluster(map, num[i], num[i] + 1));
			}
		}

		return size == 0 ? 0 : l;
	}
private:
	int mergeCluster(unordered_map<int, int> &map, int left, int right)
	{
		int upper = right + map[right] - 1;
		int lower = left - map[left] + 1;
		int length = upper - lower + 1;

		map[upper] = length;
		map[lower] = length;

		return length;
	}
};

int main()
{
	int a[] = {100, 4, 200, 1, 3, 2};
	int n = sizeof(a) / sizeof(a[0]);

	vector<int> num(a, a + n);

	Solution1 s1;
	cout << s1.longestConsecutive(num) << endl;

	Solution2 s2;
	cout << s2.longestConsecutive(num) << endl;

	return 0;
}
