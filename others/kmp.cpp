/*
 * =====================================================================================
 *
 *       Filename:  kmp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月11日 20时33分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

int bf_search(const char *string, const char *substring)
{
	assert(string != NULL && substring != NULL);

	int m = strlen(string);
	int n = strlen(substring);

	if (m < n)
		return -1;

	for (int i = 0; i <= m - n; ++i) {
		int j = 0;
		for ( ; j < n; ++j) {
			if (string[i + j] != substring[j])
				break;
		}

		if (j == n)
			return i;
	}

	return -1;
}

void get_nextval(const char *ptrn, int plen, int *nextval)
{
	int i = 0;
	nextval[i] = -1;
	int j = -1;

	while (i < plen - 1) {
		if (j == -1 || ptrn[i] == ptrn[j]) {
			++i;
			++j;
			nextval[i] = j;
		} else {
			j = nextval[j];
		}
	}
}

int kmp_search(const char *string, const char *substring, const int *nextval, int pos)
{
	assert(string != NULL && substring != NULL);

	int m = strlen(string);
	int n = strlen(substring);

	if (m < n)
		return -1;
	
	int i = pos;
	int j = 0;
	while (i < m && j < n) {
		if (j == -1 || string[i] == substring[j]) {
			++i;
			++j;
		} else {
			j = nextval[j];
		}
	}

	if (j >= n) {
		return i - n;
	} else {
		return -1;
	}

}

int main()
{
	const char *str = "ababcabcacbab";
	const char *substr = "abcac";
	int len = strlen(substr);

	//cout << bf_search(str, substr) << endl;

	int next[20] = {0};
	get_nextval(substr, len, next);

	for (int i = 0; i < len; ++i) {
		cout << next[i] << " ";
	}
	cout << endl;

	cout << kmp_search(str, substr, next, 1) << endl;

	return 0;
}
