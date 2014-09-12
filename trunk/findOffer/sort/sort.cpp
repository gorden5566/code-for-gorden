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

int inverse_pairs_core(int *data, int *copy, int start, int end)
{
	//copy data from data[] to copy[] array
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}

	int mid = (end - start) / 2;
	//current copy[] has sorted child arrays
	//so, merge them
	int left = inverse_pairs_core(copy, data, start, start + mid);
	int right = inverse_pairs_core(copy, data, start + mid + 1, end);

	int i = start + mid;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + mid + 1) {
		if (data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - mid;
		} else {
			copy[indexCopy--] = data[j--];
		}
	}

	//the rest data
	for ( ; i >= start; --i) {
		copy[indexCopy--] = data[i];
	}
	for ( ; j >= start + mid + 1; --j) {
		copy[indexCopy--] = data[j];
	}

	return left + right + count;
}

int inverse_pairs(int *data, int length)
{
	if (data == NULL || length < 0) {
		return 0;
	}

	int *copy = new int[length];
	for (int i = 0; i < length; ++i) {
		copy[i] = data[i];
	}

	int count = inverse_pairs_core(data, copy, 0, length - 1);

	delete[] copy;

	return count;
}

int get_first_k(int *data, int length, int k, int start, int end)
{
	if (start > end) {
		return -1;
	}

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if (middleData == k) {
		if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0) { //found the first k
			return middleIndex;
		} else { //not the first k
			end = middleIndex - 1;
		}
	} else if (middleData > k) {
		end = middleIndex - 1;
	} else {
		start = middleIndex + 1;
	}

	return get_first_k(data, length, k, start, end);
}

int get_last_k(int *data, int length, int k, int start, int end)
{
	if (start > end) {
		return -1;
	}

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if (middleData == k) {
		if ((middleIndex < length -1 && data[middleIndex + 1] != k) || middleIndex == length - 1) { //found the last k
			return middleIndex;
		} else { //not the first k
			start = middleIndex + 1;
		}
	} else if (middleData < k) {
		start = middleIndex + 1;
	} else {
		end = middleIndex - 1;
	}

	return get_last_k(data, length, k, start, end);
}

int get_number_of_k(int *data, int length, int k)
{
	int number = 0;

	if (data != NULL && length > 0) {
		int first = get_first_k(data, length, k, 0, length - 1);
		int last = get_last_k(data, length, k, 0, length - 1);

		if (first > -1 && last > -1) {
			number = last - first + 1;
		}
	}

	return number;
}
