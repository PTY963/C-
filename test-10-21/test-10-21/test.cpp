#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class ListNode
{
public:
	ListNode(int x)
		:_next(nullptr)
		,_val(x)
	{}

	~ListNode()
	{
		cout << "��������������" << endl;
	}
private:
	int _val;
	ListNode* _next;
};
class Stack
{
public:
	//���캯��
	Stack(int capacity = 4)
		:_a(new int[capacity])
		, _size(0)
		,_capacity(capacity)
	{
		cout << "�����˹��캯��" << endl;
	}

	//��������
	~Stack()
	{
		delete[] _a;
		_size = _capacity = 0;
		cout << "��������������" << endl;
	}
private:
	int* _a;
	int _size;
	int _capacity;
};

int main()
{
	//Stack st1;
	//
	//Stack* p = new Stack;
	//delete p;//1���ȵ����������������ڶ����Ķ���ĳ�Ա����_a��ָ��Ŀռ��ͷŵ�
	//���ͷſռ䣬���ڶ����Ķ���Ŀռ��ͷŵ�

	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));//malloc������ù��캯��
	//�����Ҫ��ʾ�ĵ���
	new(n1)ListNode(6);
	//��ʾ�ĵ�����������
	n1->~ListNode();
	
	return 0;
}
