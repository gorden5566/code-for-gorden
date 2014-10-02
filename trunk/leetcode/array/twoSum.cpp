/*
 * =====================================================================================
 *
 *       Filename:  twoSum.cpp
 *
 *    Description:  two sum
 *
 *        Version:  1.0
 *        Created:  2014年10月01日 19时49分58秒
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
	vector<int> twoSum(vector<int> &num, int target)
	{
		unordered_map<int, int> map; //key为值,value为下标
		vector<int> result;

		for (int i = 0; i < num.size(); ++i) { //初始化映射关系
			map[num[i]] = i;
		}

		for (int i = 0; i < num.size(); ++i) {
			const int gap = target - num[i]; //要找的值
			if (map.find(gap) != map.end() && map[gap] > i) { //找到且下标比当前的大
				result.push_back(i + 1);
				result.push_back(map[gap] + 1);
				break;
			}
		}

		return result;
	}
};

int main()
{
	int a[] = {2, 7, 11, 15};
	int n = sizeof(a) / sizeof(a[0]);

	vector<int> ivec(a, a + n);

	Solution s;

	vector<int> result = s.twoSum(ivec, 9);

	for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
