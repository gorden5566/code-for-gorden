/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 15时34分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
} ListNode;

#endif
