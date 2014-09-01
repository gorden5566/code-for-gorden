/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 21时33分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "findnum.h"

int main()
{
	/*
    int arr[] = {
        1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15
    };

    int i = 0;
    for (i = 0; i < 16; ++i) {
        printf("number:%d, result:%d\n", i, find_num(arr, 4, 4, i));
    }
	*/

	int revolve_arr[] = {3, 4, 5, 1, 2};
	int min = min_in_revolve(revolve_arr, 5);
	printf("%d\n", min);

    return 0;
}
