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
	//���캯��
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		//�ж������Ƿ����
		if (year <= 0 || month <= 0 || month >= 13 ||
			day <= 0 || day > GetDayOfMonth(year, month))
		{
			cout << _year << '/' << _month << '/' << _day << "-->";
			cout << "�Ƿ�����" << endl;
		}
	}

	//����+= ,��������+��һ�����ڼ�������֮���Լ������ǲ��ı��
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


