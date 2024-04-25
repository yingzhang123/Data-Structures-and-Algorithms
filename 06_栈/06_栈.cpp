// 06_ջ.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
using namespace std;

// ˳��ջ  C++���������� stack    push   pop   top   empty  size
class SeqStack
{
public:
	SeqStack(int size = 10)
		: mtop(0)
		, mcap(size)
	{
		mpStack = new int[mcap];
	}
	~SeqStack()
	{
		delete[]mpStack;
		mpStack = nullptr;
	}

public:
	// ��ջ
	void push(int val)
	{
		if (mtop == mcap)   // ջ��
		{
			// ջ����
			expand(2 * mcap);
		}
		mpStack[mtop++] = val;  // ���ݺ�����ջ
	}
	// ��ջ
	void pop()
	{
		if (mtop == 0)
			throw "stack is empty!";
		mtop--;
	}

	// ��ȡջ��Ԫ��
	int top() const
	{
		if (mtop == 0)
			throw "stack is empty!";
		return mpStack[mtop - 1];
	}

	// ջ��
	bool empty() const
	{
		return mtop == 0;
	}

	int size() const { return mtop; }

private:
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, mpStack, mtop * sizeof(int));
		delete[]mpStack;
		mpStack = p;
		mcap = size;
	}

private:
	int* mpStack;
	int mtop;       // ջ��λ��
	int mcap;       // ջ�ռ��С
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	SeqStack s;

	for (int v : arr)
	{
		s.push(v);
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}