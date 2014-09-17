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

void print_list(ListNode* pHead)
{
    if (pHead == NULL) {
        std::cout << "list has no node." << std::endl;
    } else {
        ListNode *pNode = pHead;
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

ListNode* find_kth_to_tail(ListNode *pHead, unsigned int k)
{
    if (pHead == NULL || k <= 0)
        return NULL;

    ListNode *pAhead = pHead;
    ListNode *pBehind = NULL;

    for (unsigned int i = 0; i < k - 1; ++i) {
        if (pAhead->m_pNext != NULL) {
            pAhead = pAhead->m_pNext;
        } else {
            return NULL;
        }
    }

    pBehind = pHead;
    while (pAhead->m_pNext != NULL) {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }

    return pBehind;
}

ListNode* reverse_list(ListNode *pHead)
{
    ListNode *pReversedHead = NULL;
    ListNode *pNode = pHead;
    ListNode *pPrev = NULL;

    while (pNode != NULL) {
        ListNode *pNext = pNode->m_pNext; //save point to next node

        if (pNext == NULL) //find reversed head
            pReversedHead = pNode;

        pNode->m_pNext = pPrev; //reverse link

        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}

ListNode* reverse_list_recur(ListNode *pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	if (pHead->m_pNext == NULL) {
		return pHead;
	}

	ListNode *pTmp = pHead->m_pNext; //the sub list's tail
	ListNode *reverse_head = reverse_list_recur(pTmp);

	pTmp->m_pNext = pHead; //connect to the sub list
	pHead->m_pNext = NULL;

	return reverse_head;
}

ListNode* merge_recur(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == NULL) {
        return pHead2;
    } else if (pHead2 == NULL) {
        return pHead1;
    }

    ListNode *pMergedHead = NULL;

    if (pHead1->m_nValue < pHead2->m_nValue) {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = merge_recur(pHead1->m_pNext, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = merge_recur(pHead1, pHead2->m_pNext);
    }

    return pMergedHead;
}

ListNode* merge_loop(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == NULL) {
        return pHead2;
    } else if (pHead2 == NULL) {
        return pHead1;
    }

    ListNode *pMergedHead = NULL;
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;

    if (p1->m_nValue < p2->m_nValue) {
        pMergedHead = p1;
        p1 = p1->m_pNext;
    } else {
        pMergedHead = p2;
        p2 = p2->m_pNext;
    }
    ListNode *pMergedTail = pMergedHead;

    while (p1 != NULL && p2 != NULL) {
        if (p1->m_nValue < p2->m_nValue) {
            pMergedTail->m_pNext = p1;
            p1 = p1->m_pNext;
        } else {
            pMergedTail->m_pNext = p2;
            p2 = p2->m_pNext;
        }
        pMergedTail = pMergedTail->m_pNext;
    }

    if (p1 != NULL) {
        pMergedTail->m_pNext = p1;
    } else if (p2 != NULL) {
        pMergedTail->m_pNext = p2;
    } else {
        pMergedTail->m_pNext = NULL;
    }

    return pMergedHead;
}

void delete_node(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if (!pListHead || !pToBeDeleted)
        return;

    if (pToBeDeleted->m_pNext != NULL) {
        ListNode *pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = NULL;
    } else if (*pListHead == pToBeDeleted) {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    } else {
        ListNode *pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

unsigned int get_list_length(ListNode *pHead)
{
	unsigned int nLength = 0;
	ListNode *pNode = pHead;
	while (pNode != NULL) {
		++nLength;
		pNode = pNode->m_pNext;
	}

	return nLength;
}

ListNode* find_first_common_node(ListNode *pHead1, ListNode *pHead2)
{
	unsigned int nLength1 = get_list_length(pHead1);
	unsigned int nLength2 = get_list_length(pHead2);
	int nLengthDif = nLength1 - nLength2;

	ListNode *pListHeadLong = pHead1;
	ListNode *pListHeadShort = pHead2;

	if (nLength2 > nLength1) {
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	//the long list moves (nLong - nShort) steps
	for (int i = 0; i < nLengthDif; ++i) {
		pListHeadLong = pListHeadLong->m_pNext;
	}

	while ((pListHeadLong != NULL) && (pListHeadShort != NULL)
		&& (pListHeadLong != pListHeadShort)) {
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	//found the first common node
	ListNode *pFirstCommonNode = pListHeadLong;

	return pFirstCommonNode;
}
