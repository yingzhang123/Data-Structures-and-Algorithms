#include <iostream>
using namespace std;

// O(logN)
// 二分搜索递归代码
int BinarySearch(int arr[], int i, int j, int val)
{
    if (i > j)             //递归结束条件
        return -1;

    int mid = (i + j) / 2; 
    if (arr[mid] == val)   // 比较中间数值
    {
        return mid;
    }
    else if (arr[mid] > val)
    {
        return BinarySearch(arr, i, mid - 1, val);
    }
    else
    {
        return BinarySearch(arr, mid + 1, j, val);
    }
}

// 二分搜索非递归实现
int BinarySearch(int arr[], int size, int val)
{
    return BinarySearch(arr, 0, size - 1, val);

    /*int first = 0;
    int last = size - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    return -1;*/
}

int main()
{
    int arr[] = { 12, 25, 34, 39, 45, 57, 63, 78, 82, 96, 100 };
    int size = sizeof arr / sizeof arr[0];
    cout << BinarySearch(arr, size, 39) << endl;
    cout << BinarySearch(arr, size, 45) << endl;
    cout << BinarySearch(arr, size, 12) << endl;
    cout << BinarySearch(arr, size, 64) << endl;

    return 0;
}
