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

