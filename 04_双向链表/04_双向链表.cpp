// 04_˫������.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
using namespace std;

// ����˫������Ľڵ�����
struct Node
{
    Node(int data = 0)
        : data_(data)
        , next_(nullptr)
        , pre_(nullptr)
    {}
    int data_;   // ������
    Node* next_; // ָ����һ���ڵ�
    Node* pre_;  // ָ��ǰһ���ڵ�
};

// ˫������
class DoubleLink
{
public:
    DoubleLink()
    {
        head_ = new Node();
    }
    ~DoubleLink()
    {
        Node* p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

public:
    // ͷ�巨
    void InsertHead(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_->next_;
        node->pre_ = head_;
        if (head_->next_ != nullptr)              // ���������������ǿ�������Ҫ����һ������preָ��ָ��node���½�㣩
        {
            head_->next_->pre_ = node;
        }
        head_->next_ = node;
    }

    // β�巨(û�ж���βָ��)
    void InsertTail(int val)
    {
        Node* p = head_;
        while (p->next_ != nullptr)    //p�ƶ������һ�����
        {
            p = p->next_;
        }

        // p->β�ڵ�              
        Node* node = new Node(val);
        node->pre_ = p;       // ֻ��Ҫ�ı�����ָ����
        p->next_ = node;
    }

    // �ڵ�ɾ��
    void Remove(int val)
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                // ɾ��pָ��Ľڵ�
                p->pre_->next_ = p->next_;
                if (p->next_ != nullptr)
                {
                    p->next_->pre_ = p->pre_;
                }
                //Node* next = p->next_;    // ɾ������ֵΪval�Ľ��   ����Ҫ��return��
                delete p;
                //p = next;
                return;
            }
            else
            {
                p = p->next_;
            }
        }
    }

    // �ڵ�����
    bool Find(int val)
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                return true;
            }
            else
            {
                p = p->next_;
            }
        }
        return false;
    }

    // ����ڵ����
    void Show()
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    Node* head_; // ָ��ͷ�ڵ�
};

int main()
{
    DoubleLink dlink;

    dlink.InsertHead(100);

    dlink.InsertTail(20);
    dlink.InsertTail(12);
    dlink.InsertTail(78);
    dlink.InsertTail(32);
    dlink.InsertTail(7);
    dlink.InsertTail(90);
    dlink.Show();

    dlink.InsertHead(200);
    dlink.Show();

    dlink.Remove(200);
    dlink.Show();

    dlink.Remove(90);
    dlink.Show();

    dlink.Remove(78);
    dlink.Show();
}