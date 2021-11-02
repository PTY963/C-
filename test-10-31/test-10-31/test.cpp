#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class ListNode
//{
//public:
//	ListNode(int val = 0)
//		:_val(val)
//		, next(nullptr)
//	{
//		cout << "调用了构造函数" << endl;
//	}
//
//
//private:
//	int _val;
//	ListNode* next;
//
//};

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "调用了构造函数" << endl;
//	}
//
//	A(const A& a)
//	{
//		cout << "调用了拷贝构造函数" << endl;
//	}
//
//	void operator=(const A& a)
//	{
//		cout << "调用了赋值重载函数" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A a[5];
//	A* pb = new A[5];
//	//想把a数组赋值一份给b
//	for (int i = 0; i < 5; ++i)
//	{
//		pb[i] = a[i];
//	}
//	//十次构造函数，五次赋值重载
//	cout << "------------------------" << endl;
//
//	//能不能直接拷贝构造
//	//五次构造函数，五次拷贝构造
//	A* pb2 = (A*)malloc(sizeof(A) * 5);
//	for (int i = 0; i < 5; ++i)
//	{
//		new(pb2)A(a[i]);
//	}
//	return 0;
//}

