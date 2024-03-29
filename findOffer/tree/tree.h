/*
 * =====================================================================================
 *
 *       Filename:  tree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/2014 11:55:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

typedef struct BinaryTreeNode {
    int              m_nValue;
    BinaryTreeNode   *m_pLeft;
    BinaryTreeNode   *m_pRight;
} BinaryTreeNode;

BinaryTreeNode* construct(int *preorder, int *inorder, int length);
BinaryTreeNode* do_construct(int *pre_start, int *pre_end, int *in_start, int *in_end);
void pre_order_recur(BinaryTreeNode *root);
void pre_order_loop(BinaryTreeNode *root);
void in_order_recur(BinaryTreeNode *root);
void in_order_loop(BinaryTreeNode *root);
void post_order_recur(BinaryTreeNode *root);
void post_order_loop(BinaryTreeNode *root);
void travel_tree_bfs(BinaryTreeNode *root);
void travel_tree_dfs(BinaryTreeNode *root);
bool has_subtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);
bool does_tree1_has_tree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);
void mirror_recurse(BinaryTreeNode *pRoot);
bool is_seq_of_bst(int seq[], int length);
void find_path(BinaryTreeNode *pRoot, int expectedSum);
void do_find_path(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int currentSum);
BinaryTreeNode* convert(BinaryTreeNode *pRootOfTree);
void convert_node(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList);
int tree_depth(BinaryTreeNode *pRoot);
bool is_balanced1(BinaryTreeNode *pRoot);
bool is_balanced2(BinaryTreeNode *pRoot, int *pDepth);
bool is_balanced2(BinaryTreeNode *pRoot);

int max_depth(BinaryTreeNode *pRoot);
int min_depth(BinaryTreeNode *pRoot);
bool is_balanced3(BinaryTreeNode *pRoot);

void print_path(std::vector<int> path, int start, int end);
void find_sum(BinaryTreeNode *head, int sum, std::vector<int> path, int num);

void find_tree_path(BinaryTreeNode *pRoot, int expectedSum);
void do_find_tree_path(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int currentSum);

#endif
