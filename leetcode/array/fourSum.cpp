/*
 * =====================================================================================
 *
 *       Filename:  fourSum.cpp
 *
 *    Description:  4sum
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 14时04分46秒
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
#include <algorithm>

using namespace std;

/**
* @brief 先排序，然后左右夹逼，时间复杂度O(n^3)，空间复杂度O(1)
*/
class Solution1
{
public:
	vector< vector<int> > fourSum(vector<int> &num, int target)
	{
		vector< vector<int> > result;

		if (num.size() < 4)
			return result;

		sort(num.begin(), num.end()); //先进行排序

		vector<int>::iterator last = num.end();
		for (vector<int>::iterator a = num.begin(); a < prev(last, 3); ++a) {
			for (vector<int>::iterator b = next(a); b < prev(last, 2); ++b) {
				vector<int>::iterator c = next(b); //c从前往后走
				vector<int>::iterator d = prev(last); //d从后往前走
				while (c < d) {
					if (*a + *b + *c  + *d < target) {
						++c;
					} else if (*a + *b + *c  + *d > target) {
						--d;
					} else { //找到一组值
						result.push_back({*a, *b, *c, *d});
						++c;
						--d;
					}
				}
			}

		}

		sort(result.begin(), result.end()); //排序
		result.erase(unique(result.begin(), result.end()), result.end()); //去掉重复的结果

		return result;

	}
};

/**
* @brief 用一个hashmap先缓存两个数的和
* 时间复杂度，平均O(n^2)，最坏O(n^4)，空间复杂度O(n^2)
*/
class Solution2
{
public:
	vector< vector<int> > fourSum(vector<int> &num, int target)
	{
		vector< vector<int> > result;

		if (num.size() < 4)
			return result;

		sort(num.begin(), num.end()); //先进行排序

		unordered_map<int, vector< pair<int, int> > > cache;
		for (vector<int>::size_type a = 0; a < num.size(); ++a) {
			for (vector<int>::size_type b = a + 1; b < num.size(); ++b) {
				cache[num[a] + num[b]].push_back(pair<int, int>(a, b));
			}
		}

		for (vector<int>::size_type c = 0; c < num.size(); ++c) {
			for (vector<int>::size_type d = c + 1; d < num.size(); ++d) {
				const int key = target - num[c] - num[d];

				if (cache.find(key) == cache.end()) //未找到
					continue;

				const vector< pair<int, int> > &vec = cache[key];
				for (auto k = 0; k < vec.size(); ++k) {
					if (c <= vec[k].second)
						continue;

					result.push_back({num[vec[k].first], num[vec[k].second], num[c], num[d]});
				}
			}
		}

		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());

		return result;
	}
};

int main()
{
	int a[] = {1, 0, -1, 0, -2, 2};
	int n = sizeof(a) / sizeof(a[0]);

	vector<int> ivec(a, a + n);
	vector< vector<int> > result;

	//Solution1
	Solution1 s1;
	result = s1.fourSum(ivec, 0);
	for (int i = 0; i < result.size(); ++i) {
		for (vector<int>::iterator iter = result[i].begin(); iter != result[i].end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}

	//Solution2
	Solution2 s2;
	result = s2.fourSum(ivec, 0);
	for (int i = 0; i < result.size(); ++i) {
		for (vector<int>::iterator iter = result[i].begin(); iter != result[i].end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}

	return 0;
}
