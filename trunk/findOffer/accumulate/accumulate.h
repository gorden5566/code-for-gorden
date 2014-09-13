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

unsigned int Temp::n = 0;
unsigned int Temp::sum = 0;

#endif
