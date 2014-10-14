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

/**
* @brief 根据前序遍历和中序遍历构建二叉树
*
* @param preorder 前序遍历数组
* @param inorder 中序遍历数组
* @param length 数组长度
*
* @return 根节点指针
*/
BinaryTreeNode* construct(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }
    return do_construct(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

/**
* @brief 根据前序遍历和中序遍历构建二叉树
*
* @param pre_start
* @param pre_end
* @param in_start
* @param in_end
*
* @return 
*/
BinaryTreeNode* do_construct(int *pre_start, int *pre_end, int *in_start, int *in_end)
{
    int rootValue = pre_start[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (pre_start == pre_end) {
        if (in_start == in_end) {
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

/**
* @brief 使用递归方法前序遍历二叉树
*
* @param root
*/
void pre_order_recur(BinaryTreeNode *root)
{
	if (root != NULL) {
		std::cout << root->m_nValue << " ";
		
		if (root->m_pLeft != NULL) {
			pre_order_recur(root->m_pLeft);
		}

		if (root->m_pRight != NULL) {
			pre_order_recur(root->m_pRight);
		}
	}
}

/**
* @brief 使用非递归方法前序遍历二叉树
*
* @param root
*/
void pre_order_loop(BinaryTreeNode *root)
{
	std::stack<BinaryTreeNode*> nodes;

	BinaryTreeNode *curr = root;
	while (curr || !nodes.empty()) {
		while (curr) {
			std::cout << curr->m_nValue << " ";
			nodes.push(curr);
			curr = curr->m_pLeft;
		}
		
		curr = nodes.top();
		nodes.pop();
		curr = curr->m_pRight;
	}
}

/**
* @brief 使用递归方法中序遍历二叉树
*
* @param root
*/
void in_order_recur(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
	if (root->m_pLeft != NULL) {
		in_order_recur(root->m_pLeft);
	}

	std::cout << root->m_nValue << " ";

	if (root->m_pRight != NULL) {
		in_order_recur(root->m_pRight);
	}
}

/**
* @brief 使用非递归方法中序遍历二叉树
*
* @param root
*/
void in_order_loop(BinaryTreeNode *root)
{
	std::stack<BinaryTreeNode*> nodes;

	BinaryTreeNode *curr = root;
	while (curr || !nodes.empty()) {
		while (curr) {
			nodes.push(curr);
			curr = curr->m_pLeft;
		}
		
		curr = nodes.top();
		std::cout << curr->m_nValue << " ";
		nodes.pop();
		curr = curr->m_pRight;
	}

}

/**
* @brief 使用递归方法后续遍历二叉树
*
* @param root
*/
void post_order_recur(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
	if (root->m_pLeft != NULL) {
		post_order_recur(root->m_pLeft);
	}

	if (root->m_pRight != NULL) {
		post_order_recur(root->m_pRight);
	}

	std::cout << root->m_nValue << " ";
}

/**
* @brief 使用非递归方法后续遍历二叉树
*
* @param root
*/
void post_order_loop(BinaryTreeNode *root)
{
	std::stack<BinaryTreeNode*> nodes;
	BinaryTreeNode *curr = root;
	BinaryTreeNode *last = NULL;

	while (curr || !nodes.empty()) {
		if (curr) { // go to left
			nodes.push(curr);
			curr = curr->m_pLeft;
		} else { // go to right
			curr = nodes.top();
			if (curr->m_pRight && curr->m_pRight != last) {
				curr = curr->m_pRight;
				nodes.push(curr);
				curr = curr->m_pLeft;
			} else {
				curr = nodes.top();
				nodes.pop();
				std::cout << curr->m_nValue << " ";
				last = curr;
				curr = NULL;
			}
		}
	}
}

/**
* @brief 广度优先遍历二叉树
*
* @param root
*/
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

/**
* @brief 深度优先遍历二叉树
*
* @param root
*/
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

/**
* @brief 判断pRoot2二叉树是不是pRoot1二叉树的子结构
*
* @param pRoot1
* @param pRoot2
*
* @return 
*/
bool has_subtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    bool result = false;

    if (pRoot1 != NULL && pRoot2 != NULL) {
        if (pRoot1->m_nValue == pRoot2->m_nValue) {
            result = does_tree1_has_tree2(pRoot1, pRoot2);
        }

        if (!result) {
            result = has_subtree(pRoot1->m_pLeft, pRoot2);
        }

        if (!result) {
            result = has_subtree(pRoot1->m_pRight, pRoot2);
        }
    }

    return result;
}

/**
* @brief 判断pRoot1二叉树与pRoot2二叉树是不是有相同的结构
*
* @param pRoot1
* @param pRoot2
*
* @return 
*/
bool does_tree1_has_tree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot2 == NULL) { //must be here
        return true;
    }
    
    if (pRoot1 == NULL) {
        return false;
    }

    if (pRoot1->m_nValue != pRoot2->m_nValue) {
        return false;
    }

    return does_tree1_has_tree2(pRoot1->m_pLeft, pRoot2->m_pLeft)
        && does_tree1_has_tree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

/**
* @brief 生成镜像二叉树
*
* @param pRoot
*/
void mirror_recurse(BinaryTreeNode *pRoot)
{
    if (pRoot == NULL) {
        return;
    }

    if (pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL) { //and
        return;
    }

    //swap left and right point
    BinaryTreeNode *pTmp = pRoot->m_pLeft;
    pRoot->m_pLeft = pRoot->m_pRight;
    pRoot->m_pRight = pTmp;

    if (pRoot->m_pLeft) {
        mirror_recurse(pRoot->m_pLeft);
    }

    if (pRoot->m_pRight) {
        mirror_recurse(pRoot->m_pRight);
    }
}

/**
* @brief 判断序列是不是后序遍历的结果
*
* @param seq[]
* @param length
*
* @return 
*/
bool is_seq_of_bst(int seq[], int length)
{
    if (seq == NULL || length <= 0)
        return false;

    int root = seq[length - 1];

	//找左子树上的节点
    int i = 0;
    for ( ; i < length -1; ++i) {
        if (seq[i] > root)
            break;
    }

	//判断右子树的节点是否满足要求
    int j = i;
    for ( ; j < length - 1; ++j) {
        if (seq[j] < root)
            return false;
    }

	//递归判断左子树
    bool left = true;
    if (i > 0) {
        left = is_seq_of_bst(seq, i);
    }

	//递归判断右子树
    bool right = true;
    if (i < length - 1) {
        right = is_seq_of_bst(seq + i, length - i - 1);
    }

    return (left && right);
}

/**
* @brief 二叉树和为某一值的路径
*
* @param pRoot
* @param expectedSum
*/
void find_path(BinaryTreeNode *pRoot, int expectedSum)
{
    if (pRoot == NULL)
        return;
    std::vector<int> path;
    int currentSum = 0;
    do_find_path(pRoot, expectedSum, path, currentSum);
}

/**
* @brief 二叉树和为某一值的路径
*
* @param pRoot
* @param expectedSum
* @param path
* @param currentSum
*/
void do_find_path(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int currentSum)
{
	//加上当前节点的值
    currentSum += pRoot->m_nValue;
	//把当前节点入栈
    path.push_back(pRoot->m_nValue);

	//到达叶节点，若和满足则输出路径
    bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
    if (currentSum == expectedSum && isLeaf) {
        std::cout << "A path is found: " << std::endl;
        std::vector<int>::iterator iter = path.begin();
        for ( ; iter != path.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

	//递归到左子树查找
    if (pRoot->m_pLeft != NULL) {
        do_find_path(pRoot->m_pLeft, expectedSum, path, currentSum);
    }
	//递归到右子树查找
    if (pRoot->m_pRight != NULL) {
        do_find_path(pRoot->m_pRight, expectedSum, path, currentSum);
    }

	//手动将当前节点出栈
    path.pop_back();
}

/**
* @brief 将二叉树转换为双向链表
*
* @param pRootOfTree
*
* @return 
*/
BinaryTreeNode* convert(BinaryTreeNode *pRootOfTree)
{
	BinaryTreeNode *pLastNodeInList = NULL;
	convert_node(pRootOfTree, &pLastNodeInList);

	//find head
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL) {
		pHeadOfList = pHeadOfList->m_pLeft;
	}

	return pHeadOfList;
}

/**
* @brief 将二叉树转换为双向链表
*
* @param pNode
* @param pLastNodeInList
*/
void convert_node(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList)
{
	if (pNode == NULL) {
		return;
	}

	BinaryTreeNode *pCurrent = pNode;

	//convert left
	if (pCurrent->m_pLeft != NULL) {
		convert_node(pCurrent->m_pLeft, pLastNodeInList);
	}

	//link left with current
	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL) {
		(*pLastNodeInList)->m_pRight = pCurrent;
	}

	*pLastNodeInList = pCurrent;

	//convert right
	if (pCurrent->m_pRight != NULL) {
		convert_node(pCurrent->m_pRight, pLastNodeInList);
	}
}

/**
* @brief 求二叉树的深度
*
* @param pRoot
*
* @return 
*/
int tree_depth(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL) {
		return 0;
	}

	int left = tree_depth(pRoot->m_pLeft);
	int right = tree_depth(pRoot->m_pRight);

	return left > right ? (left + 1) : (right + 1);
}

/**
* @brief 根据左右子树的深度差判断是否是平衡二叉树
*
* @param pRoot
*
* @return 
*/
bool is_balanced1(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL) {
		return true;
	}

	int left = tree_depth(pRoot->m_pLeft);
	int right = tree_depth(pRoot->m_pRight);

	int diff = left - right;
	if (diff > 1 || diff < -1) {
		return false;
	}

	return is_balanced1(pRoot->m_pLeft) && is_balanced1(pRoot->m_pRight);
}

/**
* @brief 判断是否是平衡二叉树，在遍历的时候保存深度
*
* @param pRoot
* @param pDepth
*
* @return 
*/
bool is_balanced2(BinaryTreeNode *pRoot, int *pDepth)
{
	if (pRoot == NULL) {
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (is_balanced2(pRoot->m_pLeft, &left) && is_balanced2(pRoot->m_pRight, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}

/**
* @brief 判断是否是平衡二叉树
*
* @param pRoot
*
* @return 
*/
bool is_balanced2(BinaryTreeNode *pRoot)
{
	int depth = 0;
	return is_balanced2(pRoot, &depth);
}

/**
* @brief 求二叉树的最大深度
*
* @param pRoot
*
* @return 
*/
int max_depth(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL) {
		return 0;
	}

	int leftMaxDepth = max_depth(pRoot->m_pLeft);
	int rightMaxDepth = max_depth(pRoot->m_pRight);

	return 1 + (leftMaxDepth > rightMaxDepth ? leftMaxDepth : rightMaxDepth);
}

/**
* @brief 求二叉树的最小深度
*
* @param pRoot
*
* @return 
*/
int min_depth(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL) {
		return 0;
	}

	int leftMinDepth = min_depth(pRoot->m_pLeft);
	int rightMinDepth = min_depth(pRoot->m_pRight);

	return 1 + (leftMinDepth < rightMinDepth ? leftMinDepth : rightMinDepth);
}

/**
* @brief 根据最大最小深度差判断是否是平衡二叉树
*
* @param pRoot
*
* @return 
*/
bool is_balanced3(BinaryTreeNode *pRoot)
{
	return max_depth(pRoot) - min_depth(pRoot);	
}

/**
* @brief 打印路径
*
* @param path
* @param start
* @param end
*/
void print_path(std::vector<int> path, int start, int end)
{
	for (int i = start; i <= end; i++) {
		std::cout << path[i] << " ";
	}
	std::cout << std::endl;
}

/**
* @brief 找和等于给定值的路径，不一定从根节点开始
*
* @param head
* @param sum 给定的值
* @param path 保存路径
* @param num 路径中节点的下标
*/
void find_sum(BinaryTreeNode *head, int sum, std::vector<int> path, int num)
{
	if (head == NULL) {
		return;
	}

	int tmp = sum;
	path.push_back(head->m_nValue);
	for (int i = num; i >= 0; i--) {
		tmp -= path[i];
		if (tmp == 0) {
			print_path(path, i, num);
		}
	}

	find_sum(head->m_pLeft, sum, path, num + 1);
	find_sum(head->m_pRight, sum, path, num + 1);
	path.pop_back();
}

/**
* @brief 在任意树中查找等于给定值的路径
*
* @param pRoot 根节点指针(使用孩子兄弟表示法)
* @param expectedSum
*/
void find_tree_path(BinaryTreeNode *pRoot, int expectedSum)
{
    if (pRoot == NULL)
        return;
    std::vector<int> path;
    int currentSum = 0;
    do_find_tree_path(pRoot, expectedSum, path, currentSum);
}

/**
* @brief 在任意树中查找等于给定值的路径
*
* @param pRoot
* @param expectedSum
* @param path
* @param currentSum
*/
void do_find_tree_path(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int currentSum)
{
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    bool isLeaf = pRoot->m_pLeft == NULL;
    if (currentSum == expectedSum && isLeaf) {
        std::cout << "A path is found: " << std::endl;
        std::vector<int>::iterator iter = path.begin();
        for ( ; iter != path.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    if (pRoot->m_pLeft != NULL) {
        do_find_tree_path(pRoot->m_pLeft, expectedSum, path, currentSum);

		path.pop_back(); //把当前结点从路径中去掉

		BinaryTreeNode *pBrother = pRoot->m_pLeft->m_pRight;
		while (pBrother != NULL) { //遍历兄弟结点
			do_find_tree_path(pBrother, expectedSum, path, currentSum);
			pBrother = pBrother->m_pRight;
			path.pop_back();
		}
    }
}
