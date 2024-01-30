#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_


#include <iostream>

using namespace std;

// ����ʵ��
class Array
{
public:
    Array(int size = 10) : mCur(0), mCap(size)
    {
        mpArr = new int[mCap]();   //��()��ʾ��ʼ��
    }
    ~Array()
    {
        delete[]mpArr;
        mpArr = nullptr;
    }

public:
    // ĩβ����Ԫ��
    void push_back(int val)
    {
        if (mCur == mCap)
        {
            expand(2 * mCap);  // O(n)
        }
        mpArr[mCur++] = val; // O(1)
    }
    // ĩβɾ��Ԫ��
    void pop_back()
    {
        if (mCur == 0)
        {
            return;
        }
        mCur--; // O(1)
    }
    // ��λ������Ԫ��
    void insert(int pos, int val)
    {
        if (pos < 0 || pos > mCur)
        {
            cout << "pos invalid!" << endl;
            return; // throw "pos invalid!";
        }

        if (mCur == mCap)
        {
            expand(2 * mCap);
        }

        // �ƶ�Ԫ��  O(n)
        for (int i = mCur - 1; i >= pos; i--)
        {
            mpArr[i + 1] = mpArr[i];
        }

        mpArr[pos] = val;
        mCur++;
    }
    // ��λ��ɾ��
    void erase(int pos)
    {
        if (pos < 0 || pos >= mCur)
        {
            return;
        }

        // O(n)
        for (int i = pos + 1; i < mCur; i++)
        {
            mpArr[i - 1] = mpArr[i];
        }

        mCur--;
    }
    // Ԫ�ز�ѯ
    int find(int val)
    {
        for (int i = 0; i < mCur; i++) // O(n)
        {
            if (mpArr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    // ��ӡ���ݣ�Ҳ��������������������
    void show()const
    {
        for (int i = 0; i < mCur; i++)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }
private:
    // �ڲ��������ݽӿ�
    void expand(int size)
    {
        int* p = new int[size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete[]mpArr;
        mpArr = p;
        mCap = size;
    }
private:
    int* mpArr;  // ָ������ݵ������ڴ�
    int mCap;    // ���������
    int mCur;    // ������ЧԪ�ظ���
};
#endif // !_ARRAY_HPP_
