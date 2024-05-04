#include<ctime>
#include<iostream>
#include<cstdlib>

using namespace std;


void Merge(int arr[], int l, int m, int r,int* p)
{
	//int* p = new int[r - l + 1];  // 申请额外内存空间，存放排完序的元素
	int idx = 0;

	int i = l;
	int j = m + 1;
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}

	// 假如因j <= r条件不满足而退出，左边有剩余
	while (i <= m)
	{
		p[idx++] = arr[i++];
	}
	// 假如因i <= m条件不满足而退出，右边有剩余
	while (j <= r)
	{
		p[idx++] = arr[j++];
	}

	// 再把合并好的大段有序的结果，拷贝到原始arr数组[l,r]区间内
	//for (i = l, j = 0; j < idx; i++, j++)
	for (i = l, j = 0; i <= r; i++, j++)
	{
		arr[i] = p[j];
	}

	//delete[] p;

}


// 归并排序递归接口
void MergeSort(int arr[], int begin, int end,int* p)
{
	// 递归结束条件
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	// 先递																			 快速排序是递的过程中排序的，每递一次就做一次快排分割，在归的过程什么也没做
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	                   
	// 再归并  [begin, mid]  [mid+1, end] 把两个小段有序的序列，合并成大段有序的序列           //归并排序是在归的过程排序的
	Merge(arr, begin, mid, end, p);
}

// 归并排序
void MergeSort(int arr[], int size)
{
	int* p = new int[size];
	MergeSort(arr, 0, size - 1,p);
	delete []p;
}


int main()
{
	int arr[10];
	srand(time(nullptr));
	//srand(100);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//BubbleSort(arr, 10);
	//SelectSort(arr, 10);
	//InsertSort(arr, 10);
	//ShellSort(arr, 10);
	//QuickSort(arr, 10);
	MergeSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}




//// 13_归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//using namespace std;
//
//// 归并过程函数  O(n)
//void Merge(int arr[], int l, int m, int r, int* p)
//{
//	int idx = 0;
 
//
//	while (i <= m && j <= r)
//	{
//		if (arr[i] <= arr[j])
//		{
//			p[idx++] = arr[i++];
//		}
//		else
//		{
//			p[idx++] = arr[j++];
//		}
//	}
//
//	while (i <= m)
//	{
//		p[idx++] = arr[i++];
//	}
//
//	while (j <= r)
//	{
//		p[idx++] = arr[j++];
//	}
//
//	// 再把合并好的大段有序的结果，拷贝到原始arr数组[l,r]区间内
//	for (i = l, j = 0; i <= r; i++, j++)
//	{
//		arr[i] = p[j];
//	}
//}
//
//// 归并排序递归接口
//void MergeSort(int arr[], int begin, int end, int* p)
//{
//	// 递归结束的条件
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int mid = (begin + end) / 2;
//	// 先递
//	MergeSort(arr, begin, mid, p);
//	MergeSort(arr, mid + 1, end, p);
//	// 再归并  [begin, mid]  [mid+1, end] 把两个小段有序的序列，合并成大段有序的序列
//	Merge(arr, begin, mid, end, p);
//}
//
//// 归并排序
//void MergeSort(int arr[], int size)
//{
//	int* p = new int[size];
//	MergeSort(arr, 0, size - 1, p);
//	delete[]p;
//}
//
//int main()
//{
//	int arr[10];
//	srand(time(NULL));
//
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = rand() % 100 + 1;
//	}
//
//	for (int v : arr)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	MergeSort(arr, 10);
//
//	for (int v : arr)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//}