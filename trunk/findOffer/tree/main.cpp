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

void find_sum_path();
BinaryTreeNode *get_tree1();
BinaryTreeNode *get_tree2();
void convert_tree_to_list();
void depth_and_balance();
void travel_tree();
void find_sum_path1();
void find_tree_path();

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

    //back order
    cout << "back order travel" << endl;
    travel_tree_back(root);
    cout << endl;

    //has subtree
    cout << "two tree" << endl;
    BinaryTreeNode *pRoot1 = get_tree1();
    BinaryTreeNode *pRoot2 = get_tree2();
    if (has_subtree(pRoot1, pRoot2)) {
        cout << "tree1 has tree2" << endl;
    } else {
        cout << "tree1 doesn't have tree2" << endl;
    }

    //mirror
    cout << "mirror tree1" << endl;
    mirror_recurse(pRoot1);
    travel_tree_bfs(pRoot1);

    //bst seq
    cout << "bst seq" << endl;
    int arr_bst1[] = {5, 7, 6, 9, 11, 10, 8};
    int arr_bst2[] = {7, 4, 6, 5};
    cout << is_seq_of_bst(arr_bst1, sizeof(arr_bst1)/sizeof(int)) << endl;
    cout << is_seq_of_bst(arr_bst2, sizeof(arr_bst2)/sizeof(int)) << endl;

    find_sum_path();

	convert_tree_to_list();

	depth_and_balance();

	travel_tree();

	find_sum_path1();

	find_tree_path();

    return 0;
}

void find_sum_path()
{
    int arr_pre[] = {10, 5, 4, 7, 12};
    int arr_in[] = {4, 5, 7, 10, 12};
    BinaryTreeNode *pRoot = construct(arr_pre, arr_in, sizeof(arr_in)/sizeof(int));
    find_path(pRoot, 22);
}

BinaryTreeNode *get_tree1()
{
    int arr_pre1[] = {8, 9, 2, 4, 7};
    int arr_in1[] = {9, 8, 4, 2, 7};
    BinaryTreeNode *pRoot1 = construct(arr_pre1, arr_in1, sizeof(arr_in1)/sizeof(int));

    int arr_pre2[] = {8, 7};
    int arr_in2[] = {8, 7};
    BinaryTreeNode *pRoot2 = construct(arr_pre2, arr_in2, sizeof(arr_in2)/sizeof(int));

    pRoot2->m_pLeft = pRoot1;

    travel_tree_bfs(pRoot2);

    return pRoot2;
}

BinaryTreeNode *get_tree2()
{
    int arr_pre[] = {8, 9, 2};
    int arr_in[] = {9, 8, 2};
    BinaryTreeNode *pRoot = construct(arr_pre, arr_in, sizeof(arr_in)/sizeof(int));

    travel_tree_bfs(pRoot);

    return pRoot;
}

void convert_tree_to_list()
{
    int arr_pre[] = {10, 6, 4, 8, 14, 12, 16};
    int arr_in[] = {4, 6, 8, 10, 12, 14, 16};
    BinaryTreeNode *pRoot = construct(arr_pre, arr_in, sizeof(arr_in)/sizeof(int));
	travel_tree_bfs(pRoot);
	
	BinaryTreeNode *pHead = convert(pRoot);
	while (pHead != NULL) {
		cout << pHead->m_nValue << " ";
		pHead = pHead->m_pRight;
	}
	cout << endl;

}

void depth_and_balance()
{
    int arr_pre[] = {1, 2, 4, 5, 7, 3, 6};
    int arr_in[] = {4, 2, 7, 5, 1, 3, 6};
    BinaryTreeNode *pRoot = construct(arr_pre, arr_in, sizeof(arr_in)/sizeof(int));
	//travel_tree_bfs(pRoot);
	cout << "tree depth: " << tree_depth(pRoot) << endl;
	if (is_balanced1(pRoot)) {
		cout << "is balanced1: true "<< endl;
	} else {
		cout << "is balanced1: false "<< endl;
	}

	if (is_balanced2(pRoot)) {
		cout << "is balanced2: true "<< endl;
	} else {
		cout << "is balanced2: false "<< endl;
	}
}

void travel_tree()
{
    int arr_pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int arr_in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *pRoot = construct(arr_pre, arr_in, sizeof(arr_in)/sizeof(int));
	cout << "pre order recur: ";
	pre_order_recur(pRoot);
	cout << endl;

	cout << "pre order loop: ";
	pre_order_loop(pRoot);
	cout << endl;

	cout << "in order recur: ";
	in_order_recur(pRoot);
	cout << endl;

	cout << "in order loop: ";
	in_order_loop(pRoot);
	cout << endl;

	cout << "post order recur: ";
	post_order_recur(pRoot);
	cout << endl;

	cout << "post order loop: ";
	post_order_loop(pRoot);
	cout << endl;
}

//wang dao
void find_sum_path1()
{
    int arr_pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int arr_in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *pRoot = construct(arr_pre, arr_in, sizeof(arr_in)/sizeof(int));
	
	vector<int> buffer;
	find_sum(pRoot, 14, buffer, 0);
}

void find_tree_path()
{
    int arr_pre[] = {10, 5, 3, 7, 6, 2, 12};
    int arr_in[] = {3, 7, 5, 2, 6, 12, 10};
    BinaryTreeNode *pRoot = construct(arr_pre, arr_in, sizeof(arr_in)/sizeof(int));
	travel_tree_bfs(pRoot);

	find_tree_path(pRoot, 18);
}
