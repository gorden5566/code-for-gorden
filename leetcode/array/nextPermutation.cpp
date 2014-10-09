/*
 * =====================================================================================
 *
 *       Filename:  nextPermutation.cpp
 *
 *    Description:  next permutation
 *
 *        Version:  1.0
 *        Created:  2014年10月08日 19时48分39秒
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
	void nextPermutation(vector<int> &num)
	{
		next_permutation(num.begin(), num.end());
	}

	template<typename T>
	bool next_permutation(T first, T last)
	{
		const auto rfirst = reverse_iterator<T>(last);
		const auto rlast = reverse_iterator<T>(first);

		auto pivot = next(rfirst);
		while (pivot != rlast && *pivot >= *prev(pivot)) {
			++pivot;
		}

		if (pivot == rlast) {
			reverse(rfirst, rlast);
			return false;
		}

		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

		swap(*change, *pivot);
		reverse(rfirst, pivot);

		return true;
	}
};

class Solution1
{
public:
	void nextPermutation(vector<int> &num)
	{
		const vector<int>::reverse_iterator rfirst = num.rbegin();
		const auto rlast = num.rend(); //反向迭代器,指向尾元素的下一个元素

		auto pivot = next(rfirst); //指向第二个元素

		while (pivot != rlast && *pivot >= *prev(pivot)) { //找到第一个不符合递增序列的元素
			++pivot;
		}

		if (pivot == rlast) { //未找到对应值，全部反转
			reverse(rfirst, rlast);
		}

		//在该区间内找第一个比*pivot小的值
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

		swap(*change, *pivot);

		//从最右边到pivot反转
		reverse(rfirst, pivot);
	}
};

int main()
{
	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	vector<int> a(arr, arr + n);

	//Solution s;
	Solution1 s;
	s.nextPermutation(a);

	for (auto iter = a.begin(); iter != a.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
