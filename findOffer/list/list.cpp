/*
 * =====================================================================================
 *
 *       Filename:  list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2014 05:40:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "list.h"

void add_to_tail(ListNode** pHead, int value)
{
    ListNode *pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if (*pHead == NULL) {
        *pHead = pNew;
    } else {
        ListNode *pNode = *pHead;

        while (pNode->m_pNext != NULL) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

void print_list(ListNode** pHead)
{
    if (*pHead == NULL) {
        std::cout << "list has no node." << std::endl;
    } else {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != NULL) {
            std::cout << pNode->m_nValue << "->";
            pNode = pNode->m_pNext;
        }
        std::cout << pNode->m_nValue << std::endl;
    }
}

void remove_node(ListNode** pHead, int value)
{
    if (pHead == NULL || *pHead == NULL)
        return;

    ListNode *pToBeDeleted = NULL;
    if ((*pHead)->m_nValue == value) {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    } else {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value) {
            pNode = pNode->m_pNext;
        }
        if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value) {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if (pToBeDeleted != NULL) {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

void print_list_reverse_iter(ListNode *pHead)
{
    std::stack<ListNode*> nodes;

    ListNode *pNode = pHead;
    while (pNode != NULL) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty()) {
        pNode = nodes.top();
        std::cout << pNode->m_nValue;
        nodes.pop();
        if (!nodes.empty()) {
            std::cout << "<-";
        }
    }
    std::cout << std::endl;
}

void print_list_reverse_recur(ListNode *pHead)
{
    if (pHead != NULL) {
        if (pHead->m_pNext != NULL) {
            print_list_reverse_recur(pHead->m_pNext);
        }
        std::cout << pHead->m_nValue << " ";
    }
}
