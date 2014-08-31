/*
 * =====================================================================================
 *
 *       Filename:  sort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/29/2014 04:50:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "sort.h"

void swap(int &data1, int &data2)
{
    int temp = data1;
    data1 = data2;
    data2 = temp;
}

int random_in_range(int start, int end)
{
    return (end + start) / 2;
}

int partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        return -1;

    int index = random_in_range(start, end);
    swap(data[index], data[end]);

    int small = start - 1;
    for (index = start; index < end; ++index) {
        if (data[index] < data[end]) {
            ++small;
            if (small != index)
                swap(data[index], data[small]);
        }
    }

    ++small;
    swap(data[small], data[end]);
    return small;
}

void quick_sort(int data[], int length, int start, int end)
{
    if (start == end)
        return;

    int index = partition(data, length, start, end);
    if (index > start)
        quick_sort(data, length, start, index - 1);
    if (index < end)
        quick_sort(data, length, index + 1, end);
}
