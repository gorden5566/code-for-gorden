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

    //create a list
    for (int i = 0; i < 20; ++i) {
        add_to_tail(&list, i);
    }

    //remove a node from list
    remove_node(&list, 10);

    //print list
    cout << "------------------------print list: start-------------------" << endl;
    print_list(&list);
    cout << "------------------------print list: end---------------------" << endl;

    //print list reversingly
    cout << endl << "-----------------print list reversingly: start--------------" << endl;
    print_list_reverse_iter(list);
    print_list_reverse_recur(list);
    cout << endl << "------------------print list reversingly: end---------------" << endl;

    return 0;
}
