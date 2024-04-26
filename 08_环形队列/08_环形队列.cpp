// 08_���ζ���.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
using namespace std;

// ���ζ���   queue  push  pop  front  back  empty size
class Queue
{
public:
    Queue(int size = 10)
        : cap_(size)
        , front_(0)
        , rear_(0)
        , size_(0)
    {
        pQue_ = new int[cap_];
    }
    ~Queue()
    {
        delete[]pQue_;
        pQue_ = nullptr;
    }

public:
    // ��� O(1)
    void push(int val)
    {
        if ((rear_ + 1) % cap_ == front_)    // ����������
        {
            expand(2 * cap_);
        }
        pQue_[rear_] = val;
        rear_ = (rear_ + 1) % cap_;
        size_++;
    }
    // ���� O(1)
    void pop()
    {
        if (front_ == rear_)   // �ӿ�
            throw "queue is empty!";
        front_ = (front_ + 1) % cap_;
        size_--;
    }
    // ��ͷԪ��
    int front() const
    {
        if (front_ == rear_)
            throw "queue is empty!";
        return pQue_[front_];
    }
    // ��βԪ��
    int back() const
    {
        if (front_ == rear_)
            throw "queue is empty!";
        return pQue_[(rear_ - 1 + cap_) % cap_];        //��βԪ��
    }
    // �ӿ�
    bool empty() const
    {
        return front_ == rear_;
    }
    // ����Ԫ�صĸ���
    int size() const
    {
        // return size;  O(1)

        // ����һ��ͳ�ƶ���Ԫ�ظ��� O(n)
        int size = 0;
        for (int i = front_; i != rear_; i = (i + 1) % cap_)
        {
            size++;
        }
        return size;
    }

private:
    // ���ݽӿ�
    void expand(int size)
    {
        int* p = new int[size];
        int i = 0;
        int j = front_;
        for (; j != rear_; i++, j = (j + 1) % cap_)    // ����ʹ��memcpy()����Ҫѭ������
        {
            p[i] = pQue_[j];
        }
        delete[]pQue_;
        pQue_ = p;
        cap_ = size;
        front_ = 0;
        rear_ = i;
    }

private:
    int* pQue_;
    int cap_;   // �ռ�����
    int front_; // ��ͷ
    int rear_;  // ��β
    int size_;  // ����Ԫ�ظ���
};

int main()
{
    int arr[] = { 12,4,56,7,89,31,53,75 };
    Queue que;

    for (int v : arr)
    {
        que.push(v);
    }

    cout << que.front() << endl;
    cout << que.back() << endl;

    que.push(100);
    que.push(200);
    que.push(300);
    cout << que.front() << endl;
    cout << que.back() << endl;

    while (!que.empty())
    {
        cout << que.front() << " " << que.back() << endl;
        que.pop();
    }
}