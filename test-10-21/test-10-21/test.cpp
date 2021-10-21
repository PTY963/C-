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
		cout << "调用了析构函数" << endl;
	}
private:
	int _val;
	ListNode* _next;
};
class Stack
{
public:
	//构造函数
	Stack(int capacity = 4)
		:_a(new int[capacity])
		, _size(0)
		,_capacity(capacity)
	{
		cout << "调用了构造函数" << endl;
	}

	//析构函数
	~Stack()
	{
		delete[] _a;
		_size = _capacity = 0;
		cout << "调用了析构函数" << endl;
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
	//delete p;//1、先调用析构函数，将在堆区的对象的成员变量_a所指向的空间释放掉
	//再释放空间，将在堆区的对象的空间释放掉

	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));//malloc不会调用构造函数
	//如果想要显示的调用
	new(n1)ListNode(6);
	//显示的调用析构函数
	n1->~ListNode();
	
	return 0;
}
