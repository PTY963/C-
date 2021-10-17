#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A()
//	{
//		++_count;
//	}
//
//	A(const A& a)
//	{
//		++_count;
//	}
//
//    static int GetCount()
//	{
//		return _count;
//	}
//
//private:
//	int _a;
//	static int _count;//声明
//};

//定义和初始化
//int A::_count = 0;
//int main()
//{
//	A a1;
//	//cout << sizeof(A) << endl;
//	/*cout << A::_count << endl;*/
//	/*cout << a1._count << endl;*/
//
//	//这也是匿名对象的一个用法
//	//cout << A().GetCount() - 1 << endl;
//	//cout << A::GetCount() << endl;//直接用类域访问
//
//	//对象只是共享，对象里面并不包括static
//	cout << sizeof(a1) << endl;
//
//	return 0;
//}


class Date
{
	//友元函数可以放在任意位置，一般放在最前面
	//有返回值，支持连续赋值
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	//初始化列表初始化
	Date(int year = 2001, int month = 9, int day = 24)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	//<<流插入运算符重载
	//<<流插入运算符有几个操作数，运算符重载函数就有几个参数
	//但是，第一个参数默认是对象的this指针，也就是说d1占据了左操作数的位置
	//很明显，不符合流特性
	/*void operator<<(ostream& out)
	{
		out << _year << '/' << _month << '/' << _day << endl;
	}*/

	
private:
	int _year;
	int _month;
	int _day;
};

//放在全局，但是成员变量是私有的，虽然可以用Get函数获得，但是很麻烦
//但是C++留了缝隙：友元函数
//void operator<<(ostream& out)
//{
//	out << _year << '/' << _month << '/' << _day << endl;
//}

//运算符重载函数默认左操作数是指向当前对象的this指针，这个this指针不可以显式的写出来
ostream& operator<<(ostream& out, const Date &d)
{
	out <<d. _year << '/' << d._month << '/' <<d. _day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//int main()
//{
//	Date d1;
//	Date d2;
//	//不符合流特性
//	//d1 << cout;//d1不是成员变量，是对象，所以需要运算符重载
//
//	//cout << d1;// << 流插入 d1对象流向到 cout 
//
//	//从左往右赋值， 先算cout << d1 由于返回值是void 所以d2没有左操作数
//	cout << d1 << d2 << endl;
//
//
//
//	return 0;
//}


//int main()
//{
//	//cout 和 cin 可以理解为对象
//	Date d1;
//	cin >> d1;// >> 流提取运算符
//	cout << d1;
//	return 0;
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	//在C++中，NULL实际上是一个宏 #define NULL 0,NULL == 0
	//C++98
	int* p1 = NULL;
	int* p3 = 0;//也可以用0来初始化指针，只是不够规范
	//C++11以后，用nullptr当空指针
	int* p2 = nullptr;

	f(0);
	f(NULL);
	return 0;
}
