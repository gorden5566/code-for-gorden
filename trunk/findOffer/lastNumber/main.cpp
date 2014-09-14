/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月14日 10时42分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "last.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 5;
	int m = 3;
	for (int i = 1; i <= n; ++i) {
		cout << "n: " << i << ", m: " << m << ", last num:" << last_remaining(i, m) << endl;
	}

	return 0;
}
