#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;
//class Stack
//{
//public:
//	//构造函数
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//
//	}
//
//	//析构函数 无参无返 只有一个析构函数
//	//跟构造函数一样，析构函数对成员变量也做了偏心的处理：
//	//1、内置类型的成员变量不做处理
//	//2、自定义类型的成员变量，调用它的析构函数
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

//两个栈实现队列
//class MyQueue
//{
//private:
//	Stack _push;
//	Stack _pop;
//};

//class Date
//{
//public:
//	//构造函数
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数
//	//这里会出现死递归 形参是实参的拷贝，拷贝实参需要调用拷贝构造
//	/*Date(Date d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	//形参d就是实参d2的一个别名，d其实也就是d2，传参的时候就无需拷贝
//	//引用传参解决了这里传值无穷递归的问题
//	//如果是引用传参，参数不是输出型参数，就用const
//	/*Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//int main()
//{
//	//Stack st;//自动调用构造函数和析构函数
//	MyQueue q;
//	return 0;
//}


//int main()
//{
//	Date d1;
//	Date d2(2021, 10, 10);
//	/*d1.Print();
//	d2.Print();*/
//	//Date d3(d2);//拷贝构造
//	Date d3 = d2;
//	d3.Print();
//	return 0;
//}

class A
{
public:
	A()
	{
		cout << "A的构造函数" << endl;
	}

	A(const A& a)
	{
		cout << "A的拷贝构造函数" << endl;
	}

};
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;

	A _a;
};

//int main()
//{
//	//如果写了构造函数，对象里面有自定义类型的变量，依旧会调用它的构造函数
//	Date d1(2001, 9, 24);
//	//Date d2 = d1;
//	Date d2(d1);
//	return 0;
//}

class Stack
{
public:
	//构造函数
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		if (_a == nullptr)
		{
			cout << "malloc fail" << endl;
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;

	}

	//析构函数
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack s1;
	Stack s2(s1);
	return 0;
}