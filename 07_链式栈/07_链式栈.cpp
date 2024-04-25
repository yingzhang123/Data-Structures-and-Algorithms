// 07_��ʽջ.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//// �ȽϷ������ȼ���
//bool Priority(char ch, char topch)
//{
//	if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
//		return true;
//	if (topch == '(' && ch != ')')
//		return true;
//	return false;
//}
//
//// ��׺���ʽ => ��׺���ʽ
//string MiddleToEndExpr(string expr)
//{
//	string result;
//	stack<char> s;
//
//	for (char ch : expr)
//	{
//		if (ch >= '0' && ch <= '9')
//		{
//			result.push_back(ch);
//		}
//		else
//		{
//			for (;;)
//			{
//				// ���������
//				if (s.empty() || ch == '(')
//				{
//					s.push(ch);
//					break;
//				}
//
//				// �Ƚϵ�ǰ����ch��ջ������top�����ȼ�
//				char topch = s.top();
//				// Priority:true ch > topch   false ch <= topch
//				if (Priority(ch, topch))
//				{
//					s.push(ch);
//					break;
//				}
//				else
//				{
//					s.pop();
//					if (topch == '(') // �������)��һֱ��ջ��ֱ��(
//						break;
//					result.push_back(topch);
//				}
//			}
//		}
//	}
//
//	// �������ջ���������ţ�ֱ���������׺���ʽ����     + /
//	while (!s.empty())
//	{
//		result.push_back(s.top());
//		s.pop();
//	}
//
//	return result;
//}
//
//int main()
//{
//	cout << MiddleToEndExpr("(1+2)*(3+4)") << endl;
//	cout << MiddleToEndExpr("2+(4+6)/2+6/3") << endl;
//	cout << MiddleToEndExpr("2+6/(4-2)+(4+6)/2") << endl;
//}


// ��ʽջ
class LinkStack
{
public:
	LinkStack() : size_(0)
	{
		head_ = new Node;
	}
	~LinkStack()
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
	// ��ջ O(1)   ������ͷ�ڵ���棬��һ����Ч�ڵ��λ�ã�����ջ��λ��
	void push(int val)
	{
		// head_ -> 1
		// head_ -> 2 -> 1
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
		size_++;
	}
	// ��ջ O(1)
	void pop()
	{
		if (head_->next_ == nullptr)
			throw "stack is empty!";
		Node* p = head_->next_;
		head_->next_ = p->next_;
		delete p;
		size_--;
	}
	// ��ȡջ��Ԫ��
	int top() const
	{
		if (head_->next_ == nullptr)
			throw "stack is empty!";
		return head_->next_->data_;
	}
	// �п�
	bool empty() const
	{
		return head_->next_ == nullptr;
	}
	// ����ջԪ�ظ���   ����һ��������¼�ڵ����O(n)    ��ﵽO(1)
	int size() const
	{
		return size_;
	}

private:
	struct Node
	{
		Node(int data = 0) : data_(data), next_(nullptr) {}
		int data_;
		Node* next_;
	};

	Node* head_;
	int size_;
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	LinkStack s;

	for (int v : arr)
	{
		s.push(v);
	}

	cout << s.size() << endl;

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

	cout << s.size() << endl;
}
