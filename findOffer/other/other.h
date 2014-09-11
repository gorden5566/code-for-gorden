/*
 * =====================================================================================
 *
 *       Filename:  other.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月11日 22时00分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef OTHER_H
#define OTHER_H

#include <set>
#include <vector>

using namespace std;

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void get_least_numbers(const vector<int> &data, intSet &leastNumbers, unsigned int k);

#endif
