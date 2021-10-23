#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
	int GetDaysOfMonth(int year, int month)
	{
		//ÿ�ε��ö��Ὺ��һ�����飬���鷳
		static int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2
			&& (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}

		return arr[month];
		
	}
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		//�ж������Ƿ���� - �жϲ�����ſ����õ����
		if (_year < 0 || _month <= 0 || _month > 13
			|| _day <= 0 || _day > GetDaysOfMonth(_year, _month))
		{
			cout << _year << '-' << _month << '-' << _day << "-->";
			cout << "�Ƿ�����" << endl;

		}
	}
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	//d1 += -100
	Date& operator+=(int day)
	{
		//*this = *this + day;
		if (day < 0)
		{
			return *this -= -day;
		}
		else
		{
			_day += day;
			while (_day > GetDaysOfMonth(_year, _month))
			{
				_day -= GetDaysOfMonth(_year, _month);
				++_month;
				if (_month == 13)
				{
					++_year;
					_month = 1;
				}
			}
			return *this;
		}
		
		
		

	}
	//+ ȥ����+= ����һ�θ�ֵ����
	Date operator+(int day)
	{
		//Date ret = *this;//�������� Date ret(*this);
		//ret._day += day;

		//while (ret._day > GetDaysOfMonth(ret._year, ret._month))
		//{
		//	ret._day -= GetDaysOfMonth(ret._year, ret._month);
		//	++ret._month;
		//	if (ret._month == 13)
		//	{
		//		++ret._year;
		//		ret._month = 1;
		//	}
		//}
		Date ret(*this);
		ret += day;
		return ret;
	}
	
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		else
		{
			_day -= day;
			while (_day <= 0)
			{
				_day += GetDaysOfMonth(_year, _month);
				--_month;
				if (_month == 0)
				{
					--_year;
					_month = 12;
				}
			}
			return *this;
		}
		
	}
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
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


int main()
{
	/*Date d1(2021, 10, 23);
	d1 -= 100;
	d1.Print();*/
	Date d1(2021, 10, 23);
	d1 += -100;//+ -100 ��ʵ���� d1-=100
	//d1.Print();

	Date d2(d1);
	d2 -= -100;//d2 += 100
	d2.Print();
	return 0;
}


