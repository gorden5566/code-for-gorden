/*
 * =====================================================================================
 *
 *       Filename:  complexlist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月04日 14时23分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "complexlist.h"


void clone_nodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;

    while (pNode != NULL) {
        ComplexListNode *pCloned = new ComplexListNode;

        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;

        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }
}

void connect_sibling_nodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode *pCloned = pNode->m_pNext;
        if (pNode->m_pSibling != NULL) {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* reconnect_nodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = NULL;
    ComplexListNode *pClonedNode = NULL;
    
    if (pNode != NULL) {
        pClonedHead = pClonedNode = pNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != NULL) {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pClonedHead;
}

ComplexListNode* clone(ComplexListNode *pHead)
{
    clone_nodes(pHead);
    connect_sibling_nodes(pHead);

    return reconnect_nodes(pHead);
}
