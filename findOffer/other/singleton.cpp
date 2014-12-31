/*
 * =====================================================================================
 *
 *       Filename:  singleton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月15日 11时48分58秒
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

class Singleton
{
public:
	static Singleton *Instance()
	{
		if (_instance == NULL) {
			_instance = new Singleton;
		}
		return _instance;
	}
private:
	Singleton()
	{
	}
	~Singleton()
	{
	}
	static Singleton* _instance;
};

Singleton* Singleton::_instance;

int main()
{
	Singleton *s = Singleton::Instance();

	return 0;
}
