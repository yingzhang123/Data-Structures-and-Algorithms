// 02_����.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// �ڵ�����
struct Node
{
    Node(int data = 0) :data_(data), next_(nullptr) {}
    int data_;
    Node* next_;
};

// ���������ʵ��
class Clink
{
public:
    Clink()
    {
        // ��head_��ʼ��ָ��ͷ�ڵ�
        head_ = new Node();
    }
    ~Clink()
    {
        // �ڵ���ͷ�
        Node* p = head_;
        while (p != nullptr)     
        {
            head_ = head_->next_;  // ������һ�����ĵ�ַ
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }

public:
    // ����β�巨 O(n)   head_:ͷ�ڵ�    tail_:β�ڵ�
    void InsertTail(int val)
    {
        // ���ҵ���ǰ�����ĩβ�ڵ�
        Node* p = head_;
        while (p->next_ != nullptr)    // �����һ����㣬��ҪѰ������ĩβ����ʱ�򣬲��ж� (p->next_ != nullptr)
        {
            p = p->next_;
        }

        // �����½ڵ�
        Node* node = new Node(val);
        // ���½ڵ����β�ڵ�ĺ���
        p->next_ = node;
    }
    // �����ͷ�巨  O(1)
    void InsertHead(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
    }
    // ����ڵ��ɾ����ɾ�������е�һ��ֵΪval�Ľ�㣩
    void Remove(int val)
    {
        Node* q = head_;
        Node* p = head_->next_;

        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                // ɾ��һ���ڵ㱾��Ĳ�����O(1)
                q->next_ = p->next_;
                delete p;
                return;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }
    // ɾ������ڵ㣨ɾ�����ֵΪval�Ľ�㣩
    void RemoveAll(int val)   //!!!!
    {
        Node* q = head_;
        Node* p = head_->next_;

        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
                delete p;
                // ��ָ��p��������
                p = q->next_;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }
    // ���� list O(n) ���������  �±����/�������arr[i]O(1)  ����O(n)
    bool Find(int val)
    {
        Node* p = head_->next_;   // pָ���һ�����
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
    // �����ӡ
    void Show()
    {
        Node* p = head_->next_;
        while (p != nullptr)     // ��Ҫд��(p->next_ != nullptr)��������©��ӡ���һ��Ԫ��
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }
private:
    Node* head_; // ָ�������ͷ�ڵ�

    friend void ReverseLink(Clink& link);
    friend void ReverseLink2(Clink& link);
    friend bool GetLaskKNode(Clink& link, int k, int& val);
    friend void MergeLink(Clink& link1, Clink& link2);
};

// ����������
void ReverseLink(Clink& link)
{
    Node* head = link.head_;  // ��ȡ����ͷָ��
    Node* p = head->next_;    // pָ������ĵ�һ���ڵ�

    if (p == nullptr)
    {
        return;  // �������Ϊ�գ�ֱ�ӷ���
    }

    head->next_ = nullptr;  // ��ԭ����ͷ��next��Ϊ�գ����������β��

    while (p != nullptr)
    {
        Node* q = p->next_;  // ������һ���ڵ��ָ��

        // pָ��ָ��Ľڵ����ͷ��
        p->next_ = head->next_;
        head->next_ = p;

        p = q;  // �ƶ�pָ�뵽��һ���ڵ�
    }
}


void ReverseLink2(Clink& link)    
{
    Node* head = link.head_;  // ��ȡ����ͷָ��

    Node* p = head->next_->next_;  // ������ĵڶ����ڵ㿪ʼ��ת
    Node* q = p->next_;

    if (head->next_ == nullptr)
    {
        return;  // �������Ϊ�գ�ֱ�ӷ���
    }

    head->next_->next_ = nullptr;         // !!!!!!!!!!һ��Ҫ�ϵ��������� ��ԭ����ͷ��next��Ϊ�գ����������β��
    while (p != nullptr)
    {
        // pָ��ָ��Ľڵ����ͷ��
        p->next_ = head->next_;
        head->next_ = p;

        p = q;
        if (q != nullptr)
        {
            q = q->next_;
        }
    }
}

//void ReverseLink3(Clink& link)
//{
//    Node* head = link.head_;  // ��ȡ����ͷָ��
//
//    if (head == nullptr || head->next_ == nullptr)
//    {
//        return;  // �������Ϊ�ջ�ֻ��һ���ڵ㣬ֱ�ӷ���
//    }
//
//    Node* p = head->next_->next_;  // ������ĵڶ����ڵ㿪ʼ��ת
//    Node* q = nullptr;
//
//    head->next_->next_ = nullptr;  // ��ԭ����ͷ��next��Ϊ�գ����������β��
//
//    while (p != nullptr)
//    {
//        q = p->next_;  // ������һ���ڵ��ָ��
//
//         pָ��ָ��Ľڵ����ͷ��
//        p->next_ = head->next_;
//        head->next_ = p;
//
//        p = q;
//    }
//}



// ������k���ڵ��ֵ
bool GetLaskKNode(Clink& link, int k, int& val)
{
    Node* head = link.head_;
    Node* pre = head;
    Node* p = head;

    if (k < 1)
    {
        return false;
    }

    for (int i = 0; i < k; i++)
    {
        p = p->next_;
        if (p == nullptr)
        {
            return false;
        }
    }

    // pre��ͷ�ڵ㣬p��������k���ڵ�
    while (p != nullptr)
    {
        pre = pre->next_;
        p = p->next_;
    }

    val = pre->data_;
    return true;
}

// �ϲ���������ĵ�����
void MergeLink(Clink& link1, Clink& link2)
{
    Node* p = link1.head_->next_;
    Node* q = link2.head_->next_;
    Node* last = link1.head_;
    link2.head_->next_ = nullptr;

    while (p != nullptr && q != nullptr)
    {
        if (p->data_ < q->data_)
        {
            last->next_ = p;
            p = p->next_;
            last = last->next_;
        }
        else
        {
            last->next_ = q;
            q = q->next_;
            last = last->next_;
        }
    }

    if (p != nullptr)
    {
        last->next_ = p;
    }
    else
    {
        last->next_ = q;
    }
}

// �жϵ������Ƿ���ڻ������ڷ��ػ�����ڽڵ�
bool IsLinkHasCircle(Node* head, int& val)
{
    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast->next_ != nullptr)
    {
        slow = slow->next_;
        fast = fast->next_->next_;

        if (slow == fast)
        {
            // ����ָ���ٴ�������������ڻ�
            fast = head;
            while (fast != slow)
            {
                slow = slow->next_;
                fast = fast->next_;
            }
            val = slow->data_;
            return true;
        }
    }
    return false;
}

// �ж������������Ƿ��ཻ������ཻ�������ཻ�ڵ��ֵ
bool IsLinkHasMerge(Node* head1, Node* head2, int& val)
{
    int cnt1 = 0, cnt2 = 0;
    Node* p = head1->next_;
    Node* q = head2->next_;

    while (p != nullptr)
    {
        cnt1++;
        p = p->next_;
    }

    while (q != nullptr)
    {
        cnt2++;
        q = q->next_;
    }

    p = head1;
    q = head2;
    if (cnt1 > cnt2)
    {
        // ��һ������
        int offset = cnt1 - cnt2;
        while (offset-- > 0)
        {
            p = p->next_;
        }
    }
    else
    {
        // �ڶ�������
        int offset = cnt2 - cnt1;
        while (offset-- > 0)
        {
            q = q->next_;
        }
    }

    while (p != nullptr && q != nullptr)
    {
        if (p == q)
        {
            val = p->data_;
            return true;
        }
        p = p->next_;
        q = q->next_;
    }

    return false;
}

//int main()
//{
//    Node head1;
//    Node n1(25), n2(67), n3(32), n4(18);
//    head1.next_ = &n1;
//    n1.next_ = &n2;
//    n2.next_ = &n3;
//    n3.next_ = &n4;
//
//    Node head2;
//    Node n5(31);
//    head2.next_ = &n5;
//    n5.next_ = &n1;
//
//    int val;
//    if (IsLinkHasMerge(&head1, &head2, val))
//    {
//        cout << "�����ཻ���ཻ�ڵ��ǣ�" << val << endl;
//    }
//}

#if 0
int main()
{
    Node head;

    Node n1(25), n2(67), n3(32), n4(18);
    head.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;
    n4.next_ = &n4;

    int val;
    if (IsLinkHasCircle(&head, val))
    {
        cout << "������ڻ���������ڽڵ��ǣ�" << val << endl;
    }
}
#endif

#if 0
int main()
{
    int arr[] = { 25, 37, 52, 78, 88, 92, 98, 108 };
    int brr[] = { 13, 23, 40, 56, 62, 77, 109 };

    Clink link1;
    Clink link2;

    for (int v : arr)
    {
        link1.InsertTail(v);
    }

    for (int v : brr)
    {
        link2.InsertTail(v);
    }

    link1.Show();
    link2.Show();

    MergeLink(link1, link2);
    link1.Show();
    link2.Show();
}
#endif

//#if 0
int main()
{
    Clink link;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        link.InsertTail(val);
    }
    link.Show();

    ReverseLink(link);
    link.Show();

    //int kval;
    //int k = 10;
    //if (GetLaskKNode(link, k, kval))
    //{
    //    cout << "������" << k << "���ڵ��ֵ:" << kval << endl;
    //}
}
//#endif



#if 0     // ��������ӿ�
int main()
{
    Clink link;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        link.InsertHead(val);   // ͷ�巨����
        cout << val << " ";
    }
    cout << endl;

    link.InsertTail(23);
    link.InsertHead(23);
    link.InsertHead(23);

    link.Show();

    link.RemoveAll(23);
    link.Show();
}
#endif