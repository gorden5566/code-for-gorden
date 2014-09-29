/*
 * =====================================================================================
 *
 *       Filename:  grep.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月29日 17时15分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef GREP_H
#define GREP_H

int match(char *regexp, char *text);
int match_here(char *regexp, char *text);
int match_star(int c, char *regexp, char *text);

#endif
