/*
 * =====================================================================================
 *
 *       Filename:  accumulate.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月13日 16时44分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "accumulate.h"

unsigned int Temp::n = 0;
unsigned int Temp::sum = 0;

A *array[2];

unsigned int solution1(unsigned int n)
{
	Temp::reset();

	Temp *a = new Temp[n];
	delete[] a;
	a = NULL;

	return Temp::getsum();
}

unsigned int solution2(unsigned int n)
{
	A a;
	B b;
	array[0] = &a;
	array[1] = &b;

	int value = array[1]->sum(n);

	return value;
}

unsigned int solution3_terminator(unsigned int)
{
	return 0;
}

unsigned int solution3(unsigned int n)
{
	static fun f[2] = {solution3_terminator, solution3};
	return n + f[!!n](n-1);
}
