/*
 * =====================================================================================
 *
 *       Filename:  addTwoNumber.cpp
 *
 *    Description:  add two numbers
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 15时37分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "list.h"
#include <iostream>

using namespace std;

class Solution
{
public:
	ListNode* addTwoNumber(ListNode *first, ListNode *second)
	{
		ListNode dummy(-1);
		int carry = 0;
		ListNode *prev = &dummy;

		for (ListNode *pa = first, *pb = second;
			pa != NULL || pb != NULL;
			pa = pa == NULL ? NULL : pa->next,
			pb = pb == NULL ? NULL : pb->next,
			prev = prev->next) {
			const int ai = pa == NULL ? 0 : pa->val;
			const int bi = pb == NULL ? 0 : pb->val;
			const int value = (ai + bi + carry) % 10;
			carry = (ai + bi + carry) / 10;
			prev->next = new ListNode(value);
		}

		if (carry > 0) {
			prev->next = new ListNode(carry);
		}

		return dummy.next;
	}
};

int main()
{

	return 0;
}
