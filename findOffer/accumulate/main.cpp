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

int main()
{
	cout << "solution1: " << solution1(5) << endl;

	cout << "solution2: " << solution2(5) << endl;

	cout << "solution3: " << solution3(5) << endl;

	cout << "solution4: " << solution4<5>::N << endl;

	cout << "add 5 and 17 : " << add(5, 17) << endl;

	return 0;
}


