/*
 * =====================================================================================
 *
 *       Filename:  probability.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月14日 15时59分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "probability.h"

int g_maxValue = 6;

void probability(int number, int *pProbability)
{
	for (int i = 1; i <= g_maxValue; ++i) {
		probability(number, number, i, pProbability);
	}
}

void probability(int original, int current, int sum, int *pProbability)
{
	if (current == 1) {
		pProbability[sum - original]++;
	} else {
		for (int i = 1; i <= g_maxValue; ++i) {
			probability(original, current - 1, i + sum, pProbability);
		}
	}
}

void print_probability(int number)
{
	if (number < 1)
		return;

	int maxSum = number * g_maxValue;

	// initialize probability array
	int *pProbability = new int[maxSum - number + 1];
	for (int i = number; i < maxSum; ++i) {
		pProbability[i - number] = 0;
	}

	probability(number, pProbability);

	//calculate probabilities and print out
	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i) {
		double ratio = (double)pProbability[i - number] / total * 100;
		cout << i << ": " << ratio << "%" << endl;
	}

	delete[] pProbability;
}
