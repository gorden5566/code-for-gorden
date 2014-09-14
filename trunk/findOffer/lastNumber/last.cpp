/*
 * =====================================================================================
 *
 *       Filename:  last.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月14日 10时40分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "last.h"

int last_remaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1) {
		return -1;
	}

	int last = 0;
	for (unsigned int i = 2; i <= n; ++i) {
		last = (last + m) % i;
	}

	return last;
}
