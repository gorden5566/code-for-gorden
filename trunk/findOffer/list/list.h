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

/**
* @brief 链表节点
*/
typedef struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
} ListNode;


void add_to_tail(ListNode** pHead, int value);
void print_list(ListNode* pHead);
void remove_node(ListNode** pHead, int value);
void print_list_reverse_iter(ListNode *pHead);
void print_list_reverse_recur(ListNode *pHead);
ListNode* find_kth_to_tail(ListNode *pHead, unsigned int k);
ListNode* reverse_list(ListNode *pHead);
ListNode* reverse_list_recur(ListNode *pHead);
ListNode* merge_recur(ListNode *pHead1, ListNode *pHead2);
ListNode* merge_loop(ListNode *pHead1, ListNode *pHead2);
void delete_node(ListNode **pListHead, ListNode *pToBeDeleted);
unsigned int get_list_length(ListNode *pHead);
ListNode* find_first_common_node(ListNode *pHead1, ListNode *pHead2);

#endif
