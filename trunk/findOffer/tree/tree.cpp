/*
 * =====================================================================================
 *
 *       Filename:  tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/2014 12:20:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden (), 695459065@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "tree.h"

BinaryTreeNode* construct(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }
    return do_construct(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* do_construct(int *pre_start, int *pre_end, int *in_start, int *in_end)
{
    int rootValue = pre_start[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (pre_start == pre_end) {
        if (in_start == in_end && *pre_start == *pre_end) {
            return root;
        } else { 
            return NULL;
        }
    }

    int *in_root = in_start;
    while (in_root <= in_end && *in_root != rootValue) {
        ++in_root;
    }
    if (in_root == in_end && *in_root != rootValue) {
        return NULL;
    }

    int leftLength = in_root - in_start;
    int *left_pre_end = pre_start + leftLength;
    if (leftLength > 0) {
        root->m_pLeft = do_construct(pre_start + 1, left_pre_end, in_start, in_root - 1);
    }

    if (leftLength < pre_end - pre_start) {
        root->m_pRight = do_construct(left_pre_end + 1, pre_end, in_root + 1, in_end);
    }

    return root;
}

void travel_tree_bfs(BinaryTreeNode *root)
{
    if (root == NULL)
        return;

    std::queue<BinaryTreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        BinaryTreeNode *node = nodes.front();
        std::cout << node->m_nValue << " ";
        nodes.pop();

        if (node->m_pLeft != NULL) {
            nodes.push(node->m_pLeft);
        }
        if (node->m_pRight != NULL) {
            nodes.push(node->m_pRight);
        }
    }
    std::cout << std::endl;
}

void travel_tree_dfs(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    
    std::cout << root->m_nValue << " ";
    if (root->m_pLeft != NULL) {
        travel_tree_dfs(root->m_pLeft);
    }
    if (root->m_pRight != NULL) {
        travel_tree_dfs(root->m_pRight);
    }
}
