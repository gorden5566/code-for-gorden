/*
 * =====================================================================================
 *
 *       Filename:  heap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月19日 11时21分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  gorden5566 (), gorden5566@126.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "heap.h"

/**
* @brief 添加节点，从下往上调整
*
* @param arr[]
* @param i 从节点i的父节点开始调整
*/
void min_heap_fixup(int arr[], int i)
{
	//新加入结点i 其父结点下标为 (i - 1) / 2
	int parent = (i - 1) / 2;
	int temp = arr[i];

	while (parent >= 0 && i != 0) {
		if (arr[parent] <= temp)
			break;

		arr[i] = arr[parent]; //把较大的子结点往下移动
		i = parent;
		parent = (i - 1) / 2;
	}

	arr[i] = temp;
}

/**
* @brief 往最小堆中添加值
*
* @param arr[]
* @param i 新节点的下标 
* @param nNum 新添加的值
*/
void min_heap_add_number(int arr[], int i, int nNum)
{
	arr[i] = nNum;
	min_heap_fixup(arr, i);
}

/**
* @brief 从上往下调整
*
* @param arr[]
* @param i 从节点i开始调整
* @param n 节点总数
*/
void min_heap_fixdown(int arr[], int i, int n)
{
	int temp = arr[i]; //保存要调整结点的值

	int child = 2 * i + 1;
	while (child < n) {
		if (child + 1 < n && arr[child + 1] < arr[child]) //在左右孩子中找最小的
			child++;

		if (arr[child] >= temp) //子结点大于要调整的结点，无需再往下调整
			break;

		arr[i] = arr[child]; //较小的结点往上移动
		
		i = child;
		child = 2 * i + 1;
	}
	arr[i] = temp; //找到了最终位置
}

/**
* @brief 建立最小堆
*
* @param arr[]
* @param n 元素个数
*/
void make_min_heap(int arr[], int n)
{
	//从最后一个叶结点的父结点处开始往前扫描，依次向下调整
	for (int i = n / 2 - 1; i >= 0; --i) {
		min_heap_fixdown(arr, i, n);
	}
}

/**
* @brief 从最小堆中删除第一个元素并放到最后一个位置
*
* @param arr[]
* @param n 元素个数
*/
void min_heap_delete_number(int arr[], int n)
{
	//交换第一元素和最后一个元素
	int temp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = temp;

	//从第一个元素开始向下调整
	min_heap_fixdown(arr, 0, n - 1);
}

/**
* @brief 最小堆排序
*
* @param arr[]
* @param n
*/
void min_heap_sort(int arr[], int n)
{
	for (int i = n - 1; i >= 1; --i) {
		//把当前最小的元素放到最后
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;

		//重新调整堆
		min_heap_fixdown(arr, 0, i);
	}
}
