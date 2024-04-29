#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// ð�������㷨
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++) // ����  O(n) * O(n) = O(n^2)
	{
		bool flag = false;
		// һ�˵Ĵ���   
		for (int j = 0; j < size - 1 - i; j++)  // O(n)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = true;
			}
		}

		if (!flag)
		{
			// ���û�����κε����ݽ�������ô˵�������Ѿ�������
			return;
		}
	}
}

// ѡ�������㷨 O(n) * O(n) = O(n^2)   �ռ临�Ӷȣ� O(1)   �ȶ��ԣ����ȶ�    
// 5 5 3
void ChoiceSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)  // O(n)
	{
		int min = arr[i];
		int k = i;
		for (int j = i + 1; j < size; j++) // O(n)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				k = j;
			}
		}
		// �ҵ�����ʣ�������е���Сֵ���Ϳ�ʼλ�õ�ֵ���н���
		if (k != i)
		{
			int tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
		}
	}
}

// ���������㷨  ʱ�临�Ӷ�: ���ƽ�� O(n^2)  ��ã�O(n)  �ռ䣺O(1)  �ȶ��ԣ��ȶ���
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++) // O(n)
	{
		int val = arr[i];
		int j = i - 1;
		for (; j >= 0; j--) // O(n)
		{
			if (arr[j] <= val)
			{
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}
}

// ϣ������
void ShellSort(int arr[], int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2) // 100W 19 1000W 24
	{
		for (int i = gap; i < size; i++) // O(n)
		{
			int val = arr[i];
			int j = i - gap;
			for (; j >= 0; j -= gap) // O(n)
			{
				if (arr[j] <= val)
				{
					break;
				}
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = val;
		}
	}
}

int main()
{
	const int COUNT = 100000;
	int* arr = new int[COUNT];
	int* brr = new int[COUNT];
	int* crr = new int[COUNT];
	int* drr = new int[COUNT];

	srand(time(NULL));

	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT;
		arr[i] = val;
		brr[i] = val;
		crr[i] = val;
		drr[i] = val;
	}

	clock_t begin, end;

	begin = clock();
	BubbleSort(arr, COUNT);
	end = clock();
	cout << "BubbleSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;  //��λ����ת��

	begin = clock();
	ChoiceSort(brr, COUNT);
	end = clock();
	cout << "ChoiceSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	InsertSort(crr, COUNT);
	end = clock();
	cout << "InsertSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ShellSort(drr, COUNT);
	end = clock();
	cout << "ShellSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
}

#if 0
int main()
{
	int arr[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	//BubbleSort(arr, 10);
	//SelectSort(arr, 10);
	//InsertSort(arr, 10);
	ShellSort(arr, 10);

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}
#endif