/*
 * =====================================================================================
 *
 *       Filename:  grep.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月29日 17时15分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "grep.h"

int match(char *regexp, char *text)
{
	if (regexp[0] == '^')
		return match_here(regexp + 1, text);
	
	do {
		if (match_here(regexp, text))
			return 1;
	} while (*text++ != '\0');

	return 0;
}

int match_here(char *regexp, char *text)
{
	if (regexp[0] == '\0')
		return 1;
	
	if (regexp[1] == '*')
		return match_star(regexp[0], regexp + 2, text);
	
	if (regexp[0] == '$' && regexp[1] == '\0')
		return *text == '\0';
	
	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
		return match_here(regexp + 1, text + 1);
	
	return 0;
}

int match_star(int c, char *regexp, char *text)
{
	do {
		if (match_here(regexp, text))
			return 1;
	} while (*text != '\0' && (*text++ == c || c == '.'));

	return 0;
}
