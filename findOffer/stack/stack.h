/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 22时12分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef STACK_H
#define STACK_H

#include <stack>
#include <iostream>

template <typename T>
class StackWithMin
{
private:
    std::stack<T> m_data;
    std::stack<T> m_min;
public:
    void push(const T &value);
    void pop();
    const T& min() const;
};

template <typename T>
void StackWithMin<T>::push(const T &value)
{
    m_data.push(value);

    if (m_min.size() == 0 || value < m_min.top()) {
        m_min.push(value);
    } else {
        m_min.push(m_min.top());
    }

}

template <typename T>
void StackWithMin<T>::pop()
{
    //assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
    //assert(m_data.size() > 0 && m_min.size() > 0);
    return m_min.top();
}

bool is_pop_order(const int *push, const int *pop, int length);

#endif
