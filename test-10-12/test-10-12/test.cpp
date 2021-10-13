#define _CRT_SECURE_NO_WARNINGS 1

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
//	//对于日期类的析构函数和拷贝构造函数不需要写
//
//	//运算符重载函数
//	bool operator==(const Date& d)
//	{
//		return _year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator<(const Date& d)
//	{
//		if (this->_year < d._year)
//			return true;
//		else if (_year == d._year && _month < d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day < d._day)
//			return true;
//		else
//			return false;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
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
//	//对于日期类的析构函数和拷贝构造函数不需要写
//	//这里的赋值重载并不够好
//	/*void operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;
//		//this指针是一个形参，出了函数生命周期就结束了
//	}
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2021, 10, 27);
//	Date d2(2021, 10, 11);
//
//	//赋值重载，是用于两个已经定义出来的对象之间的拷贝
//	d1 = d2;
//	d1.Print();
//
//	//拷贝构造函数，准备定义一个对象时，用另一个对象来初始化它
//	Date d3(d2);
//	d3.Print();
//	d1 = d2 = d3;
//	/*int i = 1;
//	int j = 2;
//	int k = 3;
//	i = j = k;*///赋值运算符支持连续赋值
//	Date d4 = d3;//这里虽然用了=，但是是拷贝构造函数
//	return 0;
//}
//赋值运算符重载和拷贝构造函数虽然完成的都是拷贝构造，但是应用的场景是不一样的


//class A
//{
//public:
//	void operator=(const A& a)
//	{
//		cout << "调用了自定义类型的赋值重载函数" << endl;
//	}
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
//	//拷贝构造
//	Date(const Date& d)
//	{
//		cout << "拷贝构造" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//	}
//	//如果我们不写赋值重载函数，编译器会默认生成一个
//	//它和拷贝构造函数的行为类似：
//	//1、对于内置类型，它会完成浅拷贝也就是值拷贝
//	//2、对于自定义类型，它会调用自定义类型的赋值重载函数
//	/*Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;	
//	}*/
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//};

//int main()
//{
//	Date d1(2021);
//	Date d2(2021, 2, 2);
//	Date d3(2021, 3, 3);
//
//	//d1 = d2 = d3;
//	//d1 = d1;//有人写这种幺蛾子代码
//
//	d1 = d2;
//	d1.Print();
//	return 0;
//}

//对于这几个编译器生成的默认函数：构造函数、析构函数、拷贝构造函数和赋值重载函数
//原则：如果编译器自己生成的够用就不写，不够用就自己写


//更深入的学习运算符重载
#include "Date.h"
int main()
{
	Date d1(2021, 2, 28);
	Date d2(2021, 13, 29);
	
	Date ret = d1 += 1000;
	ret.Print();
	d1.Print();

	return 0;
}