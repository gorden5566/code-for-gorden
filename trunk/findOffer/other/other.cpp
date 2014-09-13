/*
 * =====================================================================================
 *
 *       Filename:  other.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月11日 22时01分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "other.h"

bool g_InvalidInput = false;

void get_least_numbers(const vector<int> &data, intSet &leastNumbers, unsigned int k)
{
	leastNumbers.clear();

	if (k < 1 || data.size() < k) {
		return;
	}

	vector<int>::const_iterator iter = data.begin();
	for ( ; iter != data.end(); ++iter) {
		if ((leastNumbers.size()) < k) {
			leastNumbers.insert(*iter);
		} else {
			setIterator iterGreatest = leastNumbers.begin();

			if (*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}

}

int find_greatest_sum_of_sub_array(int *pData, int nLength)
{
	if ((pData == NULL) || (nLength <= 0)) {
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0; i < nLength; ++i) {
		if (nCurSum <= 0) {
			nCurSum = pData[i];
		} else {
			nCurSum += pData[i];
		}

		if (nCurSum > nGreatestSum) {
			nGreatestSum = nCurSum;
		}
	}

	return nGreatestSum;
}

const int g_MaxNumberLength = 10;
char *g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char *g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void print_min_number(int *numbers, int length)
{
	if (numbers == NULL || length <= 0) {
		return;
	}

	char **strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; ++i) {
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; ++i) {
		cout << strNumbers[i];
	}
	cout << endl;

	for (int i = 0; i < length; ++i) {
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}

int min_in_three_number(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;

	return min;
}

int get_ugly_number(int index)
{
	if (index <= 0) {
		return 0;
	}

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;
	while (nextUglyIndex < index) {
		int min = min_in_three_number(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex]) {
			++pMultiply2;
		}
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex]) {
			++pMultiply3;
		}
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex]) {
			++pMultiply5;
		}
		++nextUglyIndex;
	}

	int ugly = pUglyNumbers[nextUglyIndex - 1];

	delete[] pUglyNumbers;
	return ugly;
}

char first_not_repeat_char(char *pString)
{
	if (pString == NULL) {
		return '\0';
	}
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (int i = 0; i < tableSize; ++i) {
		hashTable[i] = 0;
	}

	char *pHashKey = pString;
	while (*(pHashKey) != '\0') {
		hashTable[static_cast<int>(*pHashKey)]++;
		pHashKey++;
	}

	pHashKey = pString;
	while (*(pHashKey) != '\0') {
		if (hashTable[static_cast<int>(*pHashKey)] == 1) {
			return *pHashKey;
		}
		pHashKey++;
	}

	return '\0';
}

unsigned int find_first_bit_is_one(int num)
{
	unsigned int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

bool is_bit_one(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void find_nums_appear_once(int data[], int length, int *num1, int *num2)
{
	if (data == NULL || length < 2) {
		return ;
	}

	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i) {
		resultExclusiveOR ^= data[i];
	}

	//find the first bit is 1
	unsigned int indexOf1 = find_first_bit_is_one(resultExclusiveOR);

	*num1 = *num2 = 0;
	for (int j = 0; j < length; ++j) {
		if (is_bit_one(data[j], indexOf1)) {
			*num1 ^= data[j];
		} else {
			*num2 ^= data[j];
		}
	}
}

bool find_numbers_with_sum(int data[], int length, int sum, int *num1, int *num2)
{
	bool found = false;
	if (length < 1 || num1 == NULL || num2 == NULL || data == NULL) {
		return found;
	}

	int ahead = length - 1;
	int behind = 0;

	while (ahead > behind) {
		long long curSum = data[ahead] + data[behind];

		if (curSum == sum) {
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		} else if (curSum > sum) {
			ahead--;
		} else {
			behind++;
		}
	}

	return found;
}
