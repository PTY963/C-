#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include <iostream>
using namespace std;

//C语言是面向过程的  -  数据和方法是分离的
//C++是面向对象的  -  数据和方法是封装在一起的
//在C++中 struct已经不仅仅是结构体了，同时升级成了类
namespace Zsj
{
	//struct如果不写访问限定符，默认是共有的（因为要兼容C）
	struct Student
	{
		void SetStudentInfo(const char* name, const char* gender, int age)
		{
			strcpy(_name, name);
			strcpy(_gender, gender);
			_age = age;
		}

		void PrintStudentInfo()
		{
			cout << _name << " " << _gender << " " << _age << endl;
		}


		char _name[20];
		char _gender[3];
		int _age;
	};

//如果是C void StackInit(Stack* ps); - 名字和参数有所不同

	//class如果不写访问限定符，默认是私有的
	class Stack
	{
	//访问限定符
	//想让别人在类外面可以直接访问的定义成共有
	//不想让别人在类外面直接访问的定义成私有
	public:
		void Init(){}
		void Push(int x){}
		void Pop(){}
		void Destory(){}
		//...

	private:
		int* _a;
		int _top;
		int _capcity;
	};
}
//int main()
//{
//	Zsj::Student s1;
//	s1.SetStudentInfo("Peter", "男", 19);
//	s1.PrintStudentInfo();
//
//	Zsj::Stack s2;
//	s2.Init();
//	return 0;
//}


//int main()
//{
//	Queue q1;//成员变量属于对象，对象实例化是，才是它们定义的地方
//	q1.Init();
//	q1.Push(1);
//	q1.Push(2);
//	q1.Push(3);
//
//	Queue q2;
//	q1.Init();
//	q1.Push(1);
//
//	//计算类(类型)大小或者计算对象大小，只考虑成员变量的大小
//	//因为对象中，只存了成员变量，没有存成员函数
//	cout << sizeof(q1) << endl;//8
//	cout << sizeof(q2) << endl;//8
//	return 0;
//}

//没有成员变量的类
class A
{
public:
	void Print()
	{}
};

//空类
class B
{

};

int main()
{
	//如果一个类没有成员变量，那么它的对象需要给一字节进行占位，标识对象存在
	//这一字节不存储有效数据
	cout << sizeof(A) << endl;//1
	cout << sizeof(B) << endl;//1
	return 0;
}