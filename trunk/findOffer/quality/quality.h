/*
 * =====================================================================================
 *
 *       Filename:  quality.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 16时04分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef QUALITY_H
#define QUALITY_H
#include <iostream>
#include <cstring>

extern bool g_InvalidInput;
double power(double base, int exponent);
double power_with_unsigned_exponent(double base, unsigned int exponent);
double power_with_unsigned_exponent_recurse(double base, unsigned int exponent);
bool equal(double num1, double num2);
void print_one_to_max(int n);
bool increment(char *number);
void print_number(char *number);
void print_one_to_max2(int n);
void print_one_to_max_recurse(char *number, int length, int index);

#endif
