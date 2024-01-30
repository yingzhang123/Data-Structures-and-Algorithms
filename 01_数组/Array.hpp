#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_


#include <iostream>

using namespace std;

// 数组实现
class Array
{
public:
    Array(int size = 10) : mCur(0), mCap(size)
    {
        mpArr = new int[mCap]();   //带()表示初始化
    }
    ~Array()
    {
        delete[]mpArr;
        mpArr = nullptr;
    }

public:
    // 末尾增加元素
    void push_back(int val)
    {
        if (mCur == mCap)
        {
            expand(2 * mCap);  // O(n)
        }
        mpArr[mCur++] = val; // O(1)
    }
    // 末尾删除元素
    void pop_back()
    {
        if (mCur == 0)
        {
            return;
        }
        mCur--; // O(1)
    }
    // 按位置增加元素
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

        // 移动元素  O(n)
        for (int i = mCur - 1; i >= pos; i--)
        {
            mpArr[i + 1] = mpArr[i];
        }

        mpArr[pos] = val;
        mCur++;
    }
    // 按位置删除
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
    // 元素查询
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
    // 打印数据（也可以重载输出流运算符）
    void show()const
    {
        for (int i = 0; i < mCur; i++)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }
private:
    // 内部数组扩容接口
    void expand(int size)
    {
        int* p = new int[size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete[]mpArr;
        mpArr = p;
        mCap = size;
    }
private:
    int* mpArr;  // 指向可扩容的数组内存
    int mCap;    // 数组的容量
    int mCur;    // 数组有效元素个数
};
#endif // !_ARRAY_HPP_
