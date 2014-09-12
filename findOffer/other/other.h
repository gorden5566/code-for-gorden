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

#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

extern bool g_InvalidInput;

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void get_least_numbers(const vector<int> &data, intSet &leastNumbers, unsigned int k);
int find_greatest_sum_of_sub_array(int *pData, int nLength);

extern const int g_MaxNumberLength;
void print_min_number(int *numbers, int length);

int get_ugly_number(int index);

char first_not_repeat_char(char *pString);

#endif
