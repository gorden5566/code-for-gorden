/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月29日 17时28分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "grep.h"
#include <iostream>

using namespace std;

int main()
{
	char regexp[] = "ab*";

	char *text[] = {"abcdefg", "ab", "abc", "c", "a"};
	int n = sizeof(text) / sizeof(text[0]);

	cout << "regexp : " << regexp << endl; 
	for (int i = 0; i < n; ++i) {
		cout << text[i] << " : " << match(regexp, text[i]) << endl;
	}

	return 0;
}
