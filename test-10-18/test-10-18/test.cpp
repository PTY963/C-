#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//class Date
//{
//public:
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//编译器自动调用构造函数
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//	//构造函数支持重载
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Stack
//{
//public:
//	/*void Init()
//	{
//		_a = nullptr;
//		top = capacity = 0;
//	}*/
//
//	Stack()
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	Stack(int capacity)
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
//	}
//
//	
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

//构造函数可以重载 - 你可以提供多种初始化方式
//int main()
//{
//	//经常会忘记调用Init函数
//	//能否做到对象定义出来就已经初始化了呢？ --  构造函数
//	Date d1;
//	Date d2(2021, 10, 18);
//	//d1.Init(2012, 4, 25);
//
//	Stack s1;
//	Stack s2(10);
//	//s1.Init();
//	return 0;
//}
class A
{
public:
	A()
	{
		_a1 = 0;
		_a2 = 12;
		cout << "A的构造函数" << endl;
	}
private:
	int _a1;
	int _a2;
};

class Date
{
public:
	/*void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	//编译器自动调用构造函数
	/*Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}*/
	//构造函数支持重载
	/*Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	void Print()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}
private:
	//我们不写构造函数，编译器会默认生成一个无参的构造函数：
	//1、对于内置类型不会初始化
	//2、对于自定义类型，它会调用它的构造函数初始化
	//内置类型（基本类型）和 自定义类型
	//C++的默认构造函数的偏心处理方式，算是早期C++语法上的缺陷，这种偏心的处理导致了语法复杂
    //但是要向前兼容，所以不可以改动
	//C++11的时候，语法委员会在这里打了一个补丁
	int _year = 0;//编译器默认生成的构造函数，会用这个缺省值来对内置类型初始化
	int _month = 1;
	int _day = 1;
	A _aa;
};

int main()
{
	Date d1;//如果我们不写编译器会默认生成一个无参的构造函数
	d1.Print();//-858993460--858993460--858993460
	return 0;
}

