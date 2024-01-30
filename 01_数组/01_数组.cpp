#include<ctime>
#include<cstdlib>

#include"Array.hpp"


// 整型数组，把偶数调整到数组的左边，把奇数调整到数组的右边  // O(n)
void AdjustArray(int arr[], int size)
{
    int* p = arr;
    int* q = arr + size - 1;
    while (p < q) {
        
        // 从左边找奇数
        if ((*p & 0x1) == 0) {
            p++;
            continue;
        }

        // 从右边找偶数
        if ((*q & 0x1) == 1) {
            q--;
            continue;
        }

        int temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;

    }
}

// O(n)
void AdjustArray2(int arr[], int size)
{
    int* p = arr;
    int* q = arr + size - 1;
    while (p < q) {


        while (p < q)
        {
            if ((*p & 0x1) == 1) {
                break;
            }
            p++;
        }

        while (p < q) {
 
            if ((*q & 0x1) == 0) {
                break;
            }
            q--;
        }

        if (p < q)   // 有可能全为奇数，不需要交换
        {
            int temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
    }
}


void AdjustArray3(int arr[], int size)
{
    int* p = arr;
    int* q = arr + size - 1;
    while (p < q) {

        // 从左边找奇数
        while ((p < q) &&(*p % 2 == 0))
        {
            p++;
        }

        // 从右边找偶数
        while ((p < q) && (*q %2 !=0)) {
            q--;
        }

        if (p < q)   // 有可能全为奇数，不需要交换
        {
            int temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
    }
}

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 1000;
    }
    for (auto i : arr) {
        cout << i << " ";
    }
    AdjustArray3(arr, 10);
    cout << endl;
    for (auto i : arr) {
        cout << i << " ";
    }
}



#if 0
// 元素逆序字符串（任何逆序问题都可以用双指针解决）
void reverse(char arr[], size_t size)
{
    char* p = arr;
    char* q = arr + size - 1;
    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
}

int main()
{
    char arr[] = "zhang ying";
    reverse(arr, strlen(arr));
    cout << arr << endl;
}
#endif



#if 0
int main()
{
    Array arr;

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100);
    }

    arr.show();
    arr.pop_back();
    arr.show();

    arr.insert(0, 100);
    arr.show();

    arr.insert(10, 200);
    arr.show();

    int pos = arr.find(100);
    if (pos != -1)
    {
        arr.erase(pos);
        arr.show();
    }
}
#endif