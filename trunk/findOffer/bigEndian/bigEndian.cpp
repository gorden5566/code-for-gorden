/*
 * =====================================================================================
 *
 *       Filename:  biEndian.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月23日 16时01分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

/**
* @brief 判断是否是小端字节序
*
* @return true小端 false大端 
*/
bool is_little_endian()
{
	union endian
	{
		int a;
		char ch;
	} test;

	//把a设置为0x0001
	//小端01 00 先存储低字节
	//大端00 01 先存储高字节
	test.a = 1;

	return (test.ch == 1);
}

int main()
{
	if (is_little_endian()) {
		cout << "little endian" << endl;
	} else {
		cout << "big endian" << endl;
	}

	return 0;
}
