/*
 * =====================================================================================
 *
 *       Filename:  stack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 22时13分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "stack.h"

bool is_pop_order(const int *push, const int *pop, int length)
{
    bool possible = false;
    if (push != NULL && pop != NULL && length > 0) {
        const int *pNextPush = push;
        const int *pNextPop = pop;
        std::stack<int> m_data;

        while (pNextPop - pop < length) {
            while (m_data.empty() || m_data.top() != *pNextPop) {
                if (pNextPush - push >= length) {
                    break;
                }
                m_data.push(*pNextPush);
                pNextPush++;
            }
            if (m_data.top() != *pNextPop)
                break;
            m_data.pop();
            pNextPop++;
        }

        if (m_data.empty() && pNextPop - pop == length)
            possible = true;
    }

    return possible;
}
