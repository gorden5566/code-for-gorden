/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2014 05:45:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "list.h"
using namespace std;

int main()
{
    ListNode *list = NULL;
    ListNode *list2 = NULL;

    //create a list
    for (int i = 0; i < 20; ++i) {
        if (i & 0x1) {
            add_to_tail(&list, i);//odd
        } else {
            add_to_tail(&list2, i);//even
        }
    }

    //remove a node from list
    remove_node(&list, 10);

    //print list
    cout << "------------------------print list: start-------------------" << endl;
    print_list(list);
    print_list(list2);
    cout << "------------------------print list: end---------------------" << endl;

    //merge two list
    //ListNode *merged_list = merge_recur(list, list2);
    ListNode *merged_list = merge_loop(list, list2);
    print_list(merged_list);

    //ListNode *result = find_kth_to_tail(list, 10);
    //cout << result->m_nValue << endl;
    
    //remove a node from list
    //remove_node(&list, 10);

    //reverse list
    //list = reverse_list(list);


    //print list reversingly
    /*
    cout << endl << "-----------------print list reversingly: start--------------" << endl;
    print_list_reverse_iter(list);
    print_list_reverse_recur(list);
    cout << endl << "------------------print list reversingly: end---------------" << endl;
    */

    return 0;
}
