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
#include <queue>

typedef struct BinaryTreeNode {
    int                     m_nValue;
    struct BinaryTreeNode   *m_pLeft;
    struct BinaryTreeNode   *m_pRight;
} BinaryTreeNode;

BinaryTreeNode* construct(int *preorder, int *inorder, int length);
BinaryTreeNode* do_construct(int *pre_start, int *pre_end, int *in_start, int *in_end);
void travel_tree_bfs(BinaryTreeNode *root);
void travel_tree_dfs(BinaryTreeNode *root);

#endif
