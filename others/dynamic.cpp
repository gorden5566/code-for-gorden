/*
 * =====================================================================================
 *
 *       Filename:  dynamic.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月11日 20时23分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

int result[1000] = {0};
int func(int m)
{
	assert(m > 0);

	if (result[m] != 0) {
		return result[m];
	}

	if (m == 1) {
		result[m] = 1;
	} else if (m == 2) {
		result[m] = 2;
	} else {
		result[m] = func(m - 1) + func(m - 2);
	}

	return result[m];
}

int main()
{
	cout << func(20) << endl;

	return 0;
}
