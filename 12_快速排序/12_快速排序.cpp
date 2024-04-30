#include<ctime>
#include<iostream>
#include<cstdlib>

using namespace std;

// ���ŷָ����
int Partation(int arr[], int l, int r)
{
	//    �Ż���: ѡ���׼�����Ż���������ȡ�С���   arr[l]   arr[r]   arr[(l+r)/2]  ȡֵΪ�м�ĵ���׼��
	 
	// ��¼��׼��
	int val = arr[l];  
	// һ�ο��Ŵ���   ʱ�䣺O(n) * O(logn) = O(nlogn)    �ռ䣺O(logn)  �ݹ�������ռ�õ�ջ�ڴ�!!!!
	while (l < r)
	{
		// 1���Ӻ���ǰ�Ҵ��ڻ�׼����Ԫ�أ�������arr[l]��
		while (l<r && arr[r]>val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}

		// 2����ǰ������С�ڻ�׼����Ԫ�أ�������arr[r]��
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
	// l==r��λ��,���ǷŻ�׼����λ��
	arr[l] = val;
	return l;
}

// ���ŵĵݹ�ӿ�
void QuickSort(int arr[], int begin, int end)
{
	if (begin >= end)    // ���ŵݹ������������begin�ܵ�end�ĺ��� ����ֻ��һ��Ԫ�ص�ʱ��[��begin,endָ��ͬһ��Ԫ��]��
	{
		return;
	}

	// �Ż�һ����[begin, end]���е�Ԫ�ظ���С��ָ�����������ò�������
	//if (end - begin <= 50)
	//{
	//	 InsertSort(arr, begin, end);
	//	return;
	//}

	//��[begin,end]�����Ԫ����һ�ο��ŷָ�����ش����Ļ�׼����λ��
	int pos = Partation(arr, begin, end);  

	// �Ի�׼������ߺ��ұߵ����У��ٷֱ���п���
	QuickSort(arr, begin, pos - 1);
	QuickSort(arr, pos+1, end);
}

// ��������
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