/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2014 02:42:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "tree.h"
using namespace std;

int main()
{
    int arr_pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int arr_in[] = {4, 7, 2, 1, 5, 3, 8, 6};

    //construct a binary tree
    BinaryTreeNode *root = NULL;
    root = construct(arr_pre, arr_in, sizeof(arr_pre)/sizeof(int));
    
    //BFS
    cout << "BFS travel" << endl;
    travel_tree_bfs(root);

    //DFS
    cout << "DFS travel" << endl;
    travel_tree_dfs(root);
    cout << endl;

    return 0;
}
