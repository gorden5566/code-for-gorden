/*
 * =====================================================================================
 *
 *       Filename:  reorder.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月31日 00时04分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef REORDER_H
#define REORDER_H

#include <iostream>
#include <cstring>

void reorder_odd_even(int *pdata, unsigned int length);
void reorder_odd_even2(int *pdata, unsigned int length);
void print_arr(int arr[], int length);
void reverse(char *pbegin, char *pend);
char *reverse_sentence(char *pdata);
char* left_rotate_string(char *pstr, int n);

#endif
