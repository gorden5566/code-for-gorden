/*
 * =====================================================================================
 *
 *       Filename:  singleton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月21日 10时53分56秒
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

class Singleton1
{
public:
	static Singleton1& instance()
	{
		return s;
	}
	int getValue()
	{
		return i;
	}
	int setValue(int x)
	{
		i = x;
	}
private:
	static Singleton1 s;
	int i;
	Singleton1(int x) : i(x) { };
	Singleton1& operator=(Singleton1&);
	Singleton1(const Singleton1&);
};

Singleton1 Singleton1::s(47);

void solution1()
{
	cout << "------------solution1------------" << endl;

	Singleton1 &s = Singleton1::instance();
	cout << s.getValue() << endl;

	Singleton1 &s2 = Singleton1::instance();
	s2.setValue(9);
	cout << s.getValue() << endl;

	cout << "------------solution1------------" << endl;
}

class Singleton2
{
public:
	static Singleton2& instance()
	{
		static Singleton2 s(47);
		return s;
	}
	int getValue()
	{
		return i;
	}
	int setValue(int x)
	{
		i = x;
	}
private:
	int i;
	Singleton2(int x) : i(x) { }
	Singleton2& operator=(Singleton2&);
	Singleton2(const Singleton2&);
};

void solution2()
{
	cout << "------------solution2------------" << endl;

	Singleton2 &s = Singleton2::instance();
	cout << s.getValue() << endl;

	Singleton2 &s2 = Singleton2::instance();
	s2.setValue(9);
	cout << s.getValue() << endl;

	cout << "------------solution2------------" << endl;
}

int main()
{
	solution1();

	solution2();

	return 0;
}
