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

//新加入结点i 其父结点下标为 (i - 1) / 2
void min_heap_fixup(int arr[], int i)
{
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

//在最小堆中加入新的数据 nNum
void min_heap_add_number(int arr[], int n, int nNum)
{
	arr[n] = nNum;
	min_heap_fixup(arr, n);
}

// 从结点i开始往下调整 n为结点总数
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

//建立最小堆
void make_min_heap(int arr[], int n)
{
	//从最后一个叶结点的父结点处开始向下调整
	for (int i = n / 2 - 1; i >= 0; --i) {
		min_heap_fixdown(arr, i, n);
	}
}

//在最小堆中删除数
void min_heap_delete_number(int arr[], int n)
{
	int temp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = temp;

	min_heap_fixdown(arr, 0, n - 1);
}

//最小堆排序 得到递减数组
void min_heap_sort(int arr[], int n)
{
	for (int i = n - 1; i >= 1; --i) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;

		min_heap_fixdown(arr, 0, i);
	}
}
