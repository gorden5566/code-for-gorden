/*
 * =====================================================================================
 *
 *       Filename:  probability.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月14日 15时59分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef PROBABILITY_H
#define PROBABILITY_H

#include <iostream>
#include <cmath>
using namespace std;

extern int g_maxValue;

void probability(int number, int *pProbability);
void probability(int original, int current, int sum, int *pProbability);
void print_probability(int number);

#endif
