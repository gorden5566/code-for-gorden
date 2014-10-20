/*
 * =====================================================================================
 *
 *       Filename:  lcs.cpp
 *
 *    Description:  longest common subsequence
 *
 *        Version:  1.0
 *        Created:  2014年10月20日 21时18分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>

using namespace std;

int c[100][100];
int lcs(const char *str1, const char *str2);

int main()
{
	char *str1 = "abcbdab";
	char *str2 = "bdcaba";

	cout << lcs(str1, str2) << endl;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

int lcs(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL) {
		return 0;
	}

	int m = strlen(str1);
	int n = strlen(str2);

	//当str2为空时，lcs长度为0
	for (int i = 1; i < m; ++i) {
		c[i][0] = 0;
	}

	//当str1为空时，lcs长度为0
	for (int j = 1; j < n; ++j) {
		c[0][j] = 0;
	}
	c[0][0] = 0;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (str1[i] == str2[j]) {
				c[i][j] = c[i-1][j-1] + 1;
			} else {
				c[i][j] = max(c[i][j-1], c[i-1][j]);
			}
		}
	}

	return c[m][n];
}
