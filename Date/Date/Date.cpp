#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

Date& Date::operator+=(int day)
{
	_day += day;

	while (_day > GetDayOfMonth(_year, _month))
	{
		_day -= GetDayOfMonth(_year, _month);
		++_month;
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
	}

	return *this;//���˺���������d1�����ڣ����Է������ã�����һ�ο�������

}

//���ı䵱ǰ����
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;

	while (_day <= 0)
	{
		--_month;
		if (_month <= 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetDayOfMonth(_year, _month);
	}

	return *this;

}

Date Date::operator-(int day)
{
	Date tmp(*this);//��������
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;

}


//2022-3-1 - 2021-10-14
int Date::operator-(const Date& d)
{
	Date max = *this, min = d;//��������
	int flag = 1;
	if (*this < d)
	{
		max = d;//��ֵ����
		min = *this;
		int flag = -1;
	}

	int count = 0;
	while (min != max)
	{
		++min;
		++count;
	}

	return count * flag;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;

}

