/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 16时20分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "quality.h"
#include <iostream>

using namespace std;

int main()
{
    double base = 7.0;
    int exponent = 3;
    double result = power(base, exponent);

    if (g_InvalidInput == true) {
        cout << "input error." << endl;
    } else {
        cout << "result = " << result << endl;
    }

    print_one_to_max(3);
    print_one_to_max2(3);

    return 0;
}
