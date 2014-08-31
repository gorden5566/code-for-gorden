/*
 * =====================================================================================
 *
 *       Filename:  sort.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/29/2014 04:51:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  TaoMee, Inc. ShangHai CN. All rights reserved.
 *
 * =====================================================================================
 */

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <cstdlib>

void swap(int &data1, int &data2);
int random_in_range(int start, int end);
int partition(int data[], int length, int start, int end);
void quick_sort(int data[], int length, int start, int end);
void sort_ages(int ages[], int length);
void print_arr(int arr[], int length);

#endif
