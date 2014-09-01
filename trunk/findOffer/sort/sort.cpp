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
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }
    int r = rand() % (end - start + 1);
    return start + r;
}

void print_arr(int arr[], int length)
{
    if (arr == NULL || length <= 0)
        return;
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
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

void sort_ages(int ages[], int length)
{
    if (ages == NULL || length <= 0)
        return;

    const int oldest_age = 99;
    int times_of_age[oldest_age + 1];
    for (int i = 0; i <= oldest_age; ++i)
        times_of_age[i] = 0;

    for (int i = 0; i < length; ++i) {
        int age = ages[i];
        if (age < 0 || age > oldest_age)
            return;

        ++times_of_age[age];
    }

    int index = 0;
    for (int i = 0; i <= oldest_age; ++i) {
        for (int j = 0; j < times_of_age[i]; ++j) {
            ages[index] = i;
            ++index;
        }
    }
}
