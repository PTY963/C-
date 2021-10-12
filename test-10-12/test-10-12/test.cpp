#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Date
{
public:
	//构造函数
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//对于日期类的析构函数和拷贝构造函数不需要写

	//运算符重载函数
	bool operator==(const Date& d)
	{
		return _year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator<(const Date& d)
	{
		if (this->_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1(2021, 10, 27);
	Date d2(2021, 10, 11);

	d1 == d2;//d1.operator==(d2) --  operator==(&d1, d2)
	d1 < d2;//d1.operator<(d2) -- operator<(&d1, d2)
	return 0;
}

