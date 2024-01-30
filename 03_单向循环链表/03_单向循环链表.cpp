// 03_����ѭ������.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//struct Node
//{
//    Node(int data = 0) : data_(data), next_(nullptr) {}
//    int data_;
//    Node* next_;
//};
//
//// Լɪ������ - ����ͷ���ĵ���ѭ������Ӧ��
//void Joseph(Node* head, int k, int m)
//{
//    Node* p = head;
//    Node* q = head;
//
//    // qָ�����һ��
//    while (q->next_ != head)
//    {
//        q = q->next_;
//    }
//
//    // �ӵ�k���˿�ʼ������
//    for (int i = 1; i < k; i++)
//    {
//        q = p;
//        p = p->next_;
//    }
//
//    // p -> ��k����
//    for (;;)
//    {
//        for (int i = 1; i < m; i++)
//        {
//            q = p;
//            p = p->next_;
//        }
//
//        // ɾ��pָ��Ľ��
//        // q p node
//        cout << p->data_ << " ";
//
//        if (p == q)
//        {
//            delete p;
//            break;
//        }
//
//        q->next_ = p->next_;
//        delete p;
//        p = q->next_;
//    }
//}
//
//int main()
//{
//    Node* head = new Node(1);
//    Node* n2 = new Node(2);
//    Node* n3 = new Node(3);
//    Node* n4 = new Node(4);
//    Node* n5 = new Node(5);
//    Node* n6 = new Node(6);
//    Node* n7 = new Node(7);
//    Node* n8 = new Node(8);
//
//    head->next_ = n2;
//    n2->next_ = n3;
//    n3->next_ = n4;
//    n4->next_ = n5;
//    n5->next_ = n6;
//    n6->next_ = n7;
//    n7->next_ = n8;
//    n8->next_ = head;
//
//    Joseph(head, 1, 5);
//}

//#if 0
// ����ѭ������
class CircleLink
{
public:
    CircleLink()
    {
        head_ = new Node();
        tail_ = head_;
        head_->next_ = head_;
    }
    ~CircleLink()
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
    }

public:
    // β�巨   O(1)
    void InsertTail(int val)
    {
        Node* node = new Node(val);   //����һ���½��
        node->next_ = tail_->next_;   // node->next_ = head_;
        tail_->next_ = node;
        tail_ = node;    // ����tail_ָ��ָ���µ�β�ڵ�
    }

    // ͷ�巨
    void InsertHead(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
        if (node->next_ == head_)
        {
            tail_ = node;
        }
    }

    // ɾ���ڵ�  ��ֵɾ����һ��ֵΪval��ֵ
    void Remove(int val)
    {
        Node* q = head_;
        Node* p = head_->next_;

        while (p != head_)
        {
            if (p->data_ == val)
            {
                // �ҵ�ɾ���ڵ�   head 
                //                 q     
                q->next_ = p->next_;
                delete p;
                if (q->next_ == head_)    //���ɾ������ĩβ��㣬����һ��tailָ��
                {
                    tail_ = q;
                }
                return;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }

    // ��ѯ
    bool Find(int val) const
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                return true;
            }
        }
        return false;
    }

    // ��ӡ����
    void Show() const
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
    struct Node
    {
        Node(int data = 0) : data_(data), next_(nullptr) {}
        int data_;
        Node* next_;
    };

    Node* head_; // ָ��ͷ�ڵ�
    Node* tail_; // ָ��ĩβ�ڵ�
};


int main()
{
    CircleLink clink;
    srand(time(0));

    clink.InsertHead(100);

    for (int i = 0; i < 10; i++)
    {
        clink.InsertTail(rand() % 100);
    }

    clink.InsertTail(200);
    clink.Show();

    clink.Remove(200);
    clink.Show();

    clink.InsertTail(300);
    clink.Show();
}
//#endif

