#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//函数名： operator运算符
//函数参数：运算符有几个操作数函数就有几个参数，参数的类型就是你要操作的对象的类型
//返回值：运算符运算后的返回值
//运算符重载函数是具有特殊函数名的函数

class Date
{
public:
	int GetDaysOfMonth(int year, int month)
	{
		//防止每次调用函数都要创建数组
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return monthDays[month];
	}
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		//判断日期是否合法(合法什么也做不了，所以要判断是否非法)
		if (_year < 0
			|| _month <= 0 || _month > 12
			|| _day <= 0 || _day > GetDaysOfMonth(_year, _month))
		{
			cout << _year << '-' << _month << '-' << _day << "-->";
			cout << "非法日期" << endl;
		}
	}
	//拷贝构造
	Date(const Date& d)
	{
		cout << "调用了拷贝构造" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//赋值重载函数，支持连续赋值
	//this指针是一个形参，出了作用域就销毁
	//*this是d1，d1在main函数里，出了作用域d1也不会销毁，所以可以用传引用返回
	Date& operator=(const Date& d)
	{
		if (this != &d)//防止自己给自己赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		

		//*this是传值返回，会调用一次拷贝构造
		return *this;//返回的是左操作数
	}
	//d1 < d2 --> d1.operator<(d2) --> operator<(&d1, const Date& d2)
	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}

	//只需写一个参数，因为成员函数，默认有一个this指针
	//bool operator== (Date* d1, const Date& y)
	//默认左操作数是第一个参数（也就是this），有操作数是第二个参数
	
	bool operator== (const Date& y)
	{
		return _year == y._year
			&& _month == y._month
			&& _day == y._day;
	}

	//日期+天数
	//d1 + 100 ,不改变d1
	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;

		//判断_day是否溢出
		while (ret._day > GetDaysOfMonth(ret._year, ret._month))
		{
			ret._day -= GetDaysOfMonth(ret._year, ret._month);
			++ret._month;

			if (ret._month == 13)
			{
				++ret._year;
				ret._month = 1;
			}

		}

		return ret;
	}

	void Print()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//运算符重载可以定义成全局的，但是面临访问私有成员变量的问题
//全局函数，没有this指针，所以要把参数写全
//bool operator== (const Date& x, const Date& y)
//{
//	return x._year == y._year
//		&& x._month == y._month
//		&& x._day == y._day;
//}
//int main()
//{
//	Date d1(2021, 10, 20);
//	Date d2(2001, 9, 24);
//	Date d3(2021, 11, 11);
//
//
//	//operator==(d1, d2);//不推荐这种函数调用的方式，如果还是这种函数调用，其实
//	//可以直接写一个EqualDate(判断两个日期类相等)函数，既然引入了operator关键字
//	//就是为了增加C++代码的可读性，让自定义类型的对象和内置类型的变量用一样的方式来
//	//用运算符
//	//d1 == d1;//编译器默认转换成 d1.operator==(d2) --> operator==(&d1, d2)
//	//d1 < d2;
//
//	//cout << (d1 == d2)<< endl;// << 流插入符，将d1插入到标准输出流,优先级高于==
//	//cout << (d1 < d2) << endl;
//
//	/*d1 = d2;
//	d1.Print();
//	d2.Print();*/
//
//	d1 = d2 = d3;
//	return 0;
//}

int main()
{
	Date d1(2021, 10, 20);
	Date d2(2000, 2, 29);
	Date d3(2001, 13, 12);
	Date d4(2001, 2, 29);

	Date ret = d1 + 100;
	ret.Print();
	return 0;
}




