/*
 * =====================================================================================
 *
 *       Filename:  string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月11日 14时28分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "string.h"

void permutation(char *pstr)
{
	if (pstr == NULL) {
		return;
	}

	permutation(pstr, pstr);
}

void permutation(char *pstr, char *pbegin)
{
	if (*pbegin == '\0') {
		std::cout << pstr << std::endl;
	} else {
		for (char *pch = pbegin; *pch != '\0'; ++pch) {
			char temp = *pch;
			*pch = *pbegin;
			*pbegin = temp;

			permutation(pstr, pbegin + 1);

			temp = *pch;
			*pch = *pbegin;
			*pbegin = temp;
		}
	}
}
