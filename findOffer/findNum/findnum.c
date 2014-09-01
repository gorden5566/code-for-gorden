/*
 * =====================================================================================
 *
 *       Filename:  findnum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2014 03:58:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "findnum.h"

int find_num(int *matrix, int rows, int columns, int number)
{
    int found = 0;

    if (matrix != NULL && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0) {
            if (matrix[row * columns + column] == number) {
                found = 1;
                break;
            } else if (matrix[row * columns + column] > number) {
                column--;
            } else {
                row++;
            }
        }
    }

    return found;
}

int min_in_revolve(int *numbers, int length)
{
	if (numbers == NULL || length <= 0) {
		exit(-1);
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return min_in_order(numbers, index1, index2);
		if (numbers[indexMid] >= numbers[index1]) {
			index1 = indexMid;
		} else if (numbers[indexMid] <= numbers[index2]) {
			index2 = indexMid;
		}
	}

	return numbers[indexMid];
}

int min_in_order(int *numbers, int index1, int index2)
{
	int result = numbers[index1];
	int i = index1 + 1;
	for ( ; i <= index2; ++i) {
		if (result > numbers[i]) {
			result = numbers[i];
		}
	}

	return result;
}
