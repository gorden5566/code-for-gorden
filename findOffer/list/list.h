/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2014 05:09:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stack>

typedef struct ListNode{
    int m_nValue;
    struct ListNode* m_pNext;
} ListNode;


void add_to_tail(ListNode** pHead, int value);
void print_list(ListNode** pHead);
void remove_node(ListNode** pHead, int value);
void print_list_reverse_iter(ListNode *pHead);
void print_list_reverse_recur(ListNode *pHead);

#endif
