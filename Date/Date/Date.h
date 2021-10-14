#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
	
	//获取某年某月的天数
	int GetDayOfMonth(int year, int month)
	{
		//assert(month <= 0 && month > 12);
		assert(month > 0 && month < 13);
		assert(year > 0);
		int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
		{
			return 29;
		}

		return day[month];
	}
	//构造函数
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		//判断日期是否合法
		//2021-2-29
		if (_year <= 0 || _month <= 0 || _month > 12 || _day <= 0 || _day > GetDayOfMonth(year, month))
		{
			cout << _year << '/' << _month << '/' << _day << "-->";
			cout << "非法日期" << endl;
		}
	}
	//打印函数
	void Print()
	{
		cout << _year << '/' << _month << '/' << _day << endl;
	}

	//运算符重载函数
	//日期 + 天数 日期 += 天数
	Date& operator+=(int day);
	Date operator+(int day);

	//日期 - 天数 日期 -= 天数
	Date& operator-= (int day);
	Date operator-(int day);
	//日期++  ++日期
	Date& operator++();//前置++
	Date operator++(int);//后置++

	//日期 - 日期
	int operator-(const Date& d);

	bool operator>(const Date& d);
	

	
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//取地址重载
	Date* operator&()
	{
		return this;
	}

	const Date* operator&() const
	{
		return this;
	}


private:
	int _year;
	int _month;
	int _day;
};
