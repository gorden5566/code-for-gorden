/*
 * =====================================================================================
 *
 *       Filename:  loop.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 11时47分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef LOOP_H
#define LOOP_H

#include <iostream>
#include <cstdlib>

long long fibonacci(unsigned n);
int number_of_one(int n);
void print_matrix_clockwise(int **numbers, int columns, int rows);
void print_matrix_in_circle(int **numbers, int columns, int rows, int start);
 
int compare(const void *num1, const void *num2);
bool is_continuous(int *numbers, int length);

#endif
