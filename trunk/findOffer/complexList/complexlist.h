/*
 * =====================================================================================
 *
 *       Filename:  complexlist.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 14时23分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef COMPLEXLIST_H
#define COMPLEXLIST_H

#include <iostream>

typedef struct ComplexListNode
{
    int                     m_nValue;
    struct ComplexListNode  *m_pNext;
    struct ComplexListNode  *m_pSibling;
} ComplexListNode;

void clone_nodes(ComplexListNode *pHead);
void connect_sibling_nodes(ComplexListNode *pHead);
ComplexListNode* reconnect_nodes(ComplexListNode *pHead);
ComplexListNode* clone(ComplexListNode *pHead);

#endif
