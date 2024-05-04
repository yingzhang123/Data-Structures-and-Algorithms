#include<ctime>
#include<iostream>
#include<cstdlib>

using namespace std;


void Merge(int arr[], int l, int m, int r,int* p)
{
	//int* p = new int[r - l + 1];  // ��������ڴ�ռ䣬����������Ԫ��
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

	// ������j <= r������������˳��������ʣ��
	while (i <= m)
	{
		p[idx++] = arr[i++];
	}
	// ������i <= m������������˳����ұ���ʣ��
	while (j <= r)
	{
		p[idx++] = arr[j++];
	}

	// �ٰѺϲ��õĴ������Ľ����������ԭʼarr����[l,r]������
	//for (i = l, j = 0; j < idx; i++, j++)
	for (i = l, j = 0; i <= r; i++, j++)
	{
		arr[i] = p[j];
	}

	//delete[] p;

}


// �鲢����ݹ�ӿ�
void MergeSort(int arr[], int begin, int end,int* p)
{
	// �ݹ��������
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	// �ȵ�																			 ���������ǵݵĹ���������ģ�ÿ��һ�ξ���һ�ο��ŷָ�ڹ�Ĺ���ʲôҲû��
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	                   
	// �ٹ鲢  [begin, mid]  [mid+1, end] ������С����������У��ϲ��ɴ�����������           //�鲢�������ڹ�Ĺ��������
	Merge(arr, begin, mid, end, p);
}

// �鲢����
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




//// 13_�鲢����.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
////
//
//#include <iostream>
//using namespace std;
//
//// �鲢���̺���  O(n)
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
//	// �ٰѺϲ��õĴ������Ľ����������ԭʼarr����[l,r]������
//	for (i = l, j = 0; i <= r; i++, j++)
//	{
//		arr[i] = p[j];
//	}
//}
//
//// �鲢����ݹ�ӿ�
//void MergeSort(int arr[], int begin, int end, int* p)
//{
//	// �ݹ����������
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int mid = (begin + end) / 2;
//	// �ȵ�
//	MergeSort(arr, begin, mid, p);
//	MergeSort(arr, mid + 1, end, p);
//	// �ٹ鲢  [begin, mid]  [mid+1, end] ������С����������У��ϲ��ɴ�����������
//	Merge(arr, begin, mid, end, p);
//}
//
//// �鲢����
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