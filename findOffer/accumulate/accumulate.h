/*
 * =====================================================================================
 *
 *       Filename:  accumulate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月13日 16时44分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef ACCUMULATE_H
#define ACCUMULATE_H

#include <iostream>

//solution1
class Temp
{
public:
	Temp()
	{
		++n;
		sum += n;
	}

	static void reset()
	{
		n = 0;
		sum = 0;
	}

	static unsigned int getsum()
	{
		return sum;
	}

private:
	static unsigned int n;
	static unsigned int sum;
};

unsigned int solution1(unsigned int n);

//solution2
class A
{
public:
	virtual unsigned int sum(unsigned int n)
	{
		return 0;
	}
};

extern A *array[2];
class B: public A
{
public:
	virtual unsigned int sum(unsigned int n)
	{
		return array[!!n]->sum(n-1) + n;
	}
};

unsigned int solution2(unsigned int n);

//solution3
typedef unsigned int (*fun)(unsigned int);
unsigned int solution3_terminator(unsigned int);
unsigned int solution3(unsigned int n);

//solution4
template <unsigned int n>
struct solution4
{
	enum value { N = solution4<n - 1>::N + n };
};

template <>
struct solution4<1>
{
	enum value { N = 1 };
};

#endif
