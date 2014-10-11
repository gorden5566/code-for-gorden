/*
 * =====================================================================================
 *
 *       Filename:  nonVirtual.cpp
 *
 *    Description:  never redefine an inherited non-virtual function
 *
 *        Version:  1.0
 *        Created:  2014年10月11日 14时39分09秒
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

class B
{
public:
	void mf()
	{
		cout << "B:mf()" << endl;
	}
};

/**
* @brief 覆盖了基类的mf方法，调用结果取决于调用指针
*/
class D : public B
{
public:
	void mf()
	{
		cout << "D:mf()" << endl;
	}
};

int main()
{
	D x;

	B *pB = &x;
	pB->mf(); //调用B中的mf()

	D *pD = &x;
	pD->mf(); //调用D中的mf()

	return 0;
}
