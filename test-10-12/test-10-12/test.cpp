#define _CRT_SECURE_NO_WARNINGS 1

//class Date
//{
//public:
//	//���캯��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//��������������������Ϳ������캯������Ҫд
//
//	//��������غ���
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
//	//���캯��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//��������������������Ϳ������캯������Ҫд
//	//����ĸ�ֵ���ز�������
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
//		//thisָ����һ���βΣ����˺����������ھͽ�����
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
//	//��ֵ���أ������������Ѿ���������Ķ���֮��Ŀ���
//	d1 = d2;
//	d1.Print();
//
//	//�������캯����׼������һ������ʱ������һ����������ʼ����
//	Date d3(d2);
//	d3.Print();
//	d1 = d2 = d3;
//	/*int i = 1;
//	int j = 2;
//	int k = 3;
//	i = j = k;*///��ֵ�����֧��������ֵ
//	Date d4 = d3;//������Ȼ����=�������ǿ������캯��
//	return 0;
//}
//��ֵ��������غͿ������캯����Ȼ��ɵĶ��ǿ������죬����Ӧ�õĳ����ǲ�һ����


//class A
//{
//public:
//	void operator=(const A& a)
//	{
//		cout << "�������Զ������͵ĸ�ֵ���غ���" << endl;
//	}
//};
//class Date
//{
//public:
//	//���캯��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//��������
//	Date(const Date& d)
//	{
//		cout << "��������" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//	}
//	//������ǲ�д��ֵ���غ�������������Ĭ������һ��
//	//���Ϳ������캯������Ϊ���ƣ�
//	//1�������������ͣ��������ǳ����Ҳ����ֵ����
//	//2�������Զ������ͣ���������Զ������͵ĸ�ֵ���غ���
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
//	//d1 = d1;//����д�����۶��Ӵ���
//
//	d1 = d2;
//	d1.Print();
//	return 0;
//}

//�����⼸�����������ɵ�Ĭ�Ϻ��������캯���������������������캯���͸�ֵ���غ���
//ԭ������������Լ����ɵĹ��þͲ�д�������þ��Լ�д


//�������ѧϰ���������
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