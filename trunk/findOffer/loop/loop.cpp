/*
 * =====================================================================================
 *
 *       Filename:  loop.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 11时43分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "loop.h"

long long fibonacci(unsigned n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    long long first = 0;
    long long second = 1;
    long long sum = 0;
    for (unsigned int i = 2; i <= n; ++i) {
        sum = first + second;
        first = second;
        second = sum;
    }

    return sum;
}

int number_of_one(int n)
{
    int count = 0;

    while (n) {
        ++count;
        n = (n - 1) & n;
    }

    return count;
}

void print_matrix_clockwise(int **numbers, int columns, int rows)
{
    if (numbers == NULL || columns <= 0 || rows <= 0)
        return;

    int start = 0;

    while (columns > start * 2 && rows > start * 2) {
        print_matrix_in_circle(numbers, columns, rows, start);
        ++start;
    }
    std::cout << std::endl;
}

void print_matrix_in_circle(int **numbers, int columns, int rows, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 -start;

    //from left to right
    for (int i = start; i <= endX; ++i) {
        int number = numbers[start][i];
        std::cout << number << " ";
    }

    //from top to bottom
    if (start < endY) {
        for (int i = start + 1; i <= endY; ++i) {
            int number = numbers[i][endX];
            std::cout << number << " ";
        }
    }

    if (start < endX && start < endY) {
        for (int i = endX - 1; i >= start; --i) {
            int number = numbers[endY][i];
            std::cout << number << " ";
        }
    }

    if (start < endX && start < endY - 1) {
        for (int i = endY - 1; i >= start + 1; --i) {
            int number = numbers[i][start];
            std::cout << number << " ";
        }
    }
}
