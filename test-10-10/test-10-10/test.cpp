#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;
//class Stack
//{
//public:
//	//���캯��
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//
//	}
//
//	//�������� �޲��޷� ֻ��һ����������
//	//�����캯��һ�������������Գ�Ա����Ҳ����ƫ�ĵĴ���
//	//1���������͵ĳ�Ա������������
//	//2���Զ������͵ĳ�Ա����������������������
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

//����ջʵ�ֶ���
//class MyQueue
//{
//private:
//	Stack _push;
//	Stack _pop;
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
//	//�������캯��
//	//�����������ݹ� �β���ʵ�εĿ���������ʵ����Ҫ���ÿ�������
//	/*Date(Date d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	//�β�d����ʵ��d2��һ��������d��ʵҲ����d2�����ε�ʱ������追��
//	//���ô��ν�������ﴫֵ����ݹ������
//	//��������ô��Σ�������������Ͳ���������const
//	/*Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//int main()
//{
//	//Stack st;//�Զ����ù��캯������������
//	MyQueue q;
//	return 0;
//}


//int main()
//{
//	Date d1;
//	Date d2(2021, 10, 10);
//	/*d1.Print();
//	d2.Print();*/
//	//Date d3(d2);//��������
//	Date d3 = d2;
//	d3.Print();
//	return 0;
//}

class A
{
public:
	A()
	{
		cout << "A�Ĺ��캯��" << endl;
	}

	A(const A& a)
	{
		cout << "A�Ŀ������캯��" << endl;
	}

};
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;

	A _a;
};

//int main()
//{
//	//���д�˹��캯���������������Զ������͵ı��������ɻ�������Ĺ��캯��
//	Date d1(2001, 9, 24);
//	//Date d2 = d1;
//	Date d2(d1);
//	return 0;
//}

class Stack
{
public:
	//���캯��
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		if (_a == nullptr)
		{
			cout << "malloc fail" << endl;
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;

	}

	//��������
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack s1;
	Stack s2(s1);
	return 0;
}