// 05_˫��ѭ������.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

// ˫��ѭ������
class DoubleCircleLink
{
public:
    DoubleCircleLink()
    {
        head_ = new Node();
        head_->next_ = head_;
        head_->pre_ = head_;
    }
    ~DoubleCircleLink()
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            p->next_->pre_ = head_;
            delete p;
            p = head_->next_; // ��p����ָ���һ���ڵ㣬����ɾ��
        }
        delete head_;         //���ɾ��ͷ���
        head_ = nullptr;
    }

public:
    // ͷ�巨 O(1)
    void InsertHead(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_->next_;
        node->pre_ = head_;
        head_->next_->pre_ = node;
        head_->next_ = node;
    }

    // β�巨  O(1)
    void InsertTail(int val)
    {
        Node* p = head_->pre_;         //�ҵ����һ�����
        // p->β�ڵ�
        Node* node = new Node(val);
        node->pre_ = p;
        p->next_ = node;
        node->next_ = head_;
        head_->pre_ = node;
    }

    // �ڵ�ɾ��
    void Remove(int val)
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                // ɾ��pָ��Ľڵ�
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
                delete p;
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
        while (p != head_)
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
        while (p != head_)
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
    DoubleCircleLink dlink;

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