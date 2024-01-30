#include<ctime>
#include<cstdlib>

#include"Array.hpp"


// �������飬��ż���������������ߣ�������������������ұ�  // O(n)
void AdjustArray(int arr[], int size)
{
    int* p = arr;
    int* q = arr + size - 1;
    while (p < q) {
        
        // �����������
        if ((*p & 0x1) == 0) {
            p++;
            continue;
        }

        // ���ұ���ż��
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

        if (p < q)   // �п���ȫΪ����������Ҫ����
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

        // �����������
        while ((p < q) &&(*p % 2 == 0))
        {
            p++;
        }

        // ���ұ���ż��
        while ((p < q) && (*q %2 !=0)) {
            q--;
        }

        if (p < q)   // �п���ȫΪ����������Ҫ����
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
// Ԫ�������ַ������κ��������ⶼ������˫ָ������
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