#include <iostream>
#include <functional>
#include <cstdlib>
#include <ctime>

using namespace std;

// ���ȼ�����ʵ��   priority_queue(vector)  push pop top empty size
class PriorityQueue
{
public:
    using Comp = function<bool(int, int)>;
    PriorityQueue(int cap = 20, Comp comp = greater<int>())
        : size_(0)
        , cap_(cap)
        , comp_(comp)
    {
        que_ = new int[cap_];
    }

    PriorityQueue(Comp comp)
        : size_(0)
        , cap_(20)
        , comp_(comp)
    {
        que_ = new int[cap_];
    }

    ~PriorityQueue()
    {
        delete[]que_;
        que_ = nullptr;
    }

public:
    // ��Ѳ���
    void push(int val)
    {
        // �ж�����
        if (size_ == cap_)
        {
            int* p = new int[2 * cap_];
            memcpy(p, que_, cap_ * sizeof(int));
            delete[]que_;
            que_ = p;
            cap_ *= 2;
        }

        if (size_ == 0)
        {
            // ֻ��һ��Ԫ�أ����ý��жѵ��ϸ�����
            que_[size_] = val;
        }
        else
        {
            // �������ж��Ԫ�أ���Ҫ�����ϸ�����
            siftUp(size_, val);
        }
        size_++;
    }

    // ���Ѳ���
    void pop()
    {
        if (size_ == 0)
            throw "container is empty!";

        size_--;
        if (size_ > 0)
        {
            // ɾ���Ѷ�Ԫ�أ�����ʣ���Ԫ�أ�Ҫ���жѵ��³�����
            siftDown(0, que_[size_]);   //��
        }
    }

    bool empty() const 
    { 
        return size_ == 0;
    }

    int top() const
    {
        if (size_ == 0)
            throw "container is empty!";
        return que_[0];
    }

    int size() const 
    { 
        return size_;
    }

private:
    // ����ϸ����� O(logn)   O(1)
    void siftUp(int i, int val)
    {
        while (i > 0) // �����㵽���ڵ�(0��λ)
        {
            int father = (i - 1) / 2;
            if (comp_(val, que_[father]))
            {
                que_[i] = que_[father];
                i = father;
            }
            else
            {
                break;
            }
        }
        // ��val�ŵ�i��λ��
        que_[i] = val;
    }
    // �����³����� O(logn)    O(1)
    void siftDown(int i, int val)
    {
        // i�³����ܳ������һ���к��ӵĽڵ�          size-1
        while (i < size_ / 2)
        {
            int child = 2 * i + 1; // ��i���ڵ������
            if (child + 1 < size_ && comp_(que_[child + 1], que_[child]))
            {
                // ���i�ڵ��Һ��ӵ�ֵ��������, child��¼�Һ��ӵ��±�
                child = child + 1;
            }

            if (comp_(que_[child], val))
            {
                que_[i] = que_[child];
                i = child;
            }
            else
            {
                break; // �Ѿ�����ѵ����ʣ���ǰ����
            }
        }
        que_[i] = val;
    }
private:
    int* que_;  // ָ��̬���ݵ�����
    int size_;  // ����Ԫ�صĸ���
    int cap_;   // ������ܿռ��С
    Comp comp_; // �Ƚ�������
};

int main()
{
    // PriorityQueue que; // ���ڴ����ʵ�ֵ����ȼ����� (Ĭ��)

    // ����С����ʵ�ֵ����ȼ�����
    PriorityQueue que([](int a, int b) {return a < b; });
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        que.push(rand() % 100);
    }

    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
}