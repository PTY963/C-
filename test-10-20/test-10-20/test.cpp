#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//�������� operator�����
//����������������м����������������м������������������;�����Ҫ�����Ķ��������
//����ֵ������������ķ���ֵ
//��������غ����Ǿ������⺯�����ĺ���

class Date
{
public:
	int GetDaysOfMonth(int year, int month)
	{
		//��ֹÿ�ε��ú�����Ҫ��������
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

		//�ж������Ƿ�Ϸ�(�Ϸ�ʲôҲ�����ˣ�����Ҫ�ж��Ƿ�Ƿ�)
		if (_year < 0
			|| _month <= 0 || _month > 12
			|| _day <= 0 || _day > GetDaysOfMonth(_year, _month))
		{
			cout << _year << '-' << _month << '-' << _day << "-->";
			cout << "�Ƿ�����" << endl;
		}
	}
	//��������
	Date(const Date& d)
	{
		cout << "�����˿�������" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//��ֵ���غ�����֧��������ֵ
	//thisָ����һ���βΣ����������������
	//*this��d1��d1��main���������������d1Ҳ�������٣����Կ����ô����÷���
	Date& operator=(const Date& d)
	{
		if (this != &d)//��ֹ�Լ����Լ���ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		

		//*this�Ǵ�ֵ���أ������һ�ο�������
		return *this;//���ص����������
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

	//ֻ��дһ����������Ϊ��Ա������Ĭ����һ��thisָ��
	//bool operator== (Date* d1, const Date& y)
	//Ĭ����������ǵ�һ��������Ҳ����this�����в������ǵڶ�������
	
	bool operator== (const Date& y)
	{
		return _year == y._year
			&& _month == y._month
			&& _day == y._day;
	}

	//����+����
	//d1 + 100 ,���ı�d1
	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;

		//�ж�_day�Ƿ����
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

//��������ؿ��Զ����ȫ�ֵģ��������ٷ���˽�г�Ա����������
//ȫ�ֺ�����û��thisָ�룬����Ҫ�Ѳ���дȫ
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
//	//operator==(d1, d2);//���Ƽ����ֺ������õķ�ʽ������������ֺ������ã���ʵ
//	//����ֱ��дһ��EqualDate(�ж��������������)��������Ȼ������operator�ؼ���
//	//����Ϊ������C++����Ŀɶ��ԣ����Զ������͵Ķ�����������͵ı�����һ���ķ�ʽ��
//	//�������
//	//d1 == d1;//������Ĭ��ת���� d1.operator==(d2) --> operator==(&d1, d2)
//	//d1 < d2;
//
//	//cout << (d1 == d2)<< endl;// << �����������d1���뵽��׼�����,���ȼ�����==
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




