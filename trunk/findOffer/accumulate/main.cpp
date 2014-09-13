/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月13日 16时47分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "accumulate.h"
#include <iostream>

using namespace std;

unsigned int solution1(unsigned int n);

int main()
{
	cout << solution1(5) << endl;

	return 0;
}

unsigned int solution1(unsigned int n)
{

	Temp::reset();

	Temp *a = new Temp[n];
	delete[] a;
	a = NULL;

	return Temp::getsum();
}
