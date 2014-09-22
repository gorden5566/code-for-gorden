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
 *   Organization:  
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
void insert_sort(int data[], int n);
int inverse_pairs_core(int *data, int *copy, int start, int end);
int inverse_pairs(int *data, int length);
int get_first_k(int *data, int length, int k, int start, int end);
int get_last_k(int *data, int length, int k, int start, int end);
int get_number_of_k(int *data, int length, int k);

#endif
