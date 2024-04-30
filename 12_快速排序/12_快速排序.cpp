#include<ctime>
#include<iostream>
#include<cstdlib>

using namespace std;

// 快排分割处理函数
int Partation(int arr[], int l, int r)
{
	//    优化二: 选择基准数的优化：“三数取中”法   arr[l]   arr[r]   arr[(l+r)/2]  取值为中间的当基准数
	 
	// 记录基准数
	int val = arr[l];  
	// 一次快排处理   时间：O(n) * O(logn) = O(nlogn)    空间：O(logn)  递归的深度所占用的栈内存!!!!
	while (l < r)
	{
		// 1、从后往前找大于基准数的元素，并放在arr[l]中
		while (l<r && arr[r]>val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}

		// 2、从前往后找小于基准数的元素，并放在arr[r]中
		while (l<r && arr[l]<val)
		{
			l++;
		}
		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}
	}
	// l==r的位置,就是放基准数的位置
	arr[l] = val;
	return l;
}

// 快排的递归接口
void QuickSort(int arr[], int begin, int end)
{
	if (begin >= end)    // 快排递归结束的条件（begin跑到end的后面 或者只用一个元素的时候[即begin,end指向同一个元素]）
	{
		return;
	}

	// 优化一：当[begin, end]序列的元素个数小到指定数量，采用插入排序
	//if (end - begin <= 50)
	//{
	//	 InsertSort(arr, begin, end);
	//	return;
	//}

	//在[begin,end]区间的元素做一次快排分割处理，返回处理后的基准数的位置
	int pos = Partation(arr, begin, end);  

	// 对基准数的左边和右边的序列，再分别进行快排
	QuickSort(arr, begin, pos - 1);
	QuickSort(arr, pos+1, end);
}

// 快速排序
void QuickSort(int arr[], int size)
{
	QuickSort(arr, 0, size - 1);
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
	QuickSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}