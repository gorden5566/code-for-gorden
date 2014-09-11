/*
 * =====================================================================================
 *
 *       Filename:  other.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月11日 22时01分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "other.h"

void get_least_numbers(const vector<int> &data, intSet &leastNumbers, unsigned int k)
{
	leastNumbers.clear();

	if (k < 1 || data.size() < k) {
		return;
	}

	vector<int>::const_iterator iter = data.begin();
	for ( ; iter != data.end(); ++iter) {
		if ((leastNumbers.size()) < k) {
			leastNumbers.insert(*iter);
		} else {
			setIterator iterGreatest = leastNumbers.begin();

			if (*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}

}
