#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	
	int GetDayOfMonth(int year, int month)
	{
		assert(month > 0 && month < 13);
		int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && year > 0
			&& (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
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

		//判断日期是否合理
		if (year <= 0 || month <= 0 || month >= 13 ||
			day <= 0 || day > GetDayOfMonth(year, month))
		{
			cout << _year << '/' << _month << '/' << _day << "-->";
			cout << "非法日期" << endl;
		}
	}

	//日期+= ,不是日期+，一个日期加上天数之后，自己本身是不改变的
	Date operator+=(int day);

	void Print()
	{
		cout << _year << '/' << _month << '/' << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


