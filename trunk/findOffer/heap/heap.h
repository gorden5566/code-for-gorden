/*
 * =====================================================================================
 *
 *       Filename:  heap.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月19日 11时21分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef HEAP_H
#define HEAP_H

void min_heap_fixup(int arr[], int i);
void min_heap_add_number(int arr[], int i, int nNum);
void min_heap_fixdown(int arr[], int i, int n);
void make_min_heap(int arr[], int n);
void min_heap_delete_number(int arr[], int n);
void min_heap_sort(int arr[], int n);

#endif
