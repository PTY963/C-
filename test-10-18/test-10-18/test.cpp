#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//class Date
//{
//public:
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//�������Զ����ù��캯��
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//	//���캯��֧������
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Stack
//{
//public:
//	/*void Init()
//	{
//		_a = nullptr;
//		top = capacity = 0;
//	}*/
//
//	Stack()
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	Stack(int capacity)
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
//	}
//
//	
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

//���캯���������� - ������ṩ���ֳ�ʼ����ʽ
//int main()
//{
//	//���������ǵ���Init����
//	//�ܷ�����������������Ѿ���ʼ�����أ� --  ���캯��
//	Date d1;
//	Date d2(2021, 10, 18);
//	//d1.Init(2012, 4, 25);
//
//	Stack s1;
//	Stack s2(10);
//	//s1.Init();
//	return 0;
//}
class A
{
public:
	A()
	{
		_a1 = 0;
		_a2 = 12;
		cout << "A�Ĺ��캯��" << endl;
	}
private:
	int _a1;
	int _a2;
};

class Date
{
public:
	/*void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	//�������Զ����ù��캯��
	/*Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}*/
	//���캯��֧������
	/*Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	void Print()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}
private:
	//���ǲ�д���캯������������Ĭ������һ���޲εĹ��캯����
	//1�������������Ͳ����ʼ��
	//2�������Զ������ͣ�����������Ĺ��캯����ʼ��
	//�������ͣ��������ͣ��� �Զ�������
	//C++��Ĭ�Ϲ��캯����ƫ�Ĵ���ʽ����������C++�﷨�ϵ�ȱ�ݣ�����ƫ�ĵĴ��������﷨����
    //����Ҫ��ǰ���ݣ����Բ����ԸĶ�
	//C++11��ʱ���﷨ίԱ�����������һ������
	int _year = 0;//������Ĭ�����ɵĹ��캯�����������ȱʡֵ�����������ͳ�ʼ��
	int _month = 1;
	int _day = 1;
	A _aa;
};

int main()
{
	Date d1;//������ǲ�д��������Ĭ������һ���޲εĹ��캯��
	d1.Print();//-858993460--858993460--858993460
	return 0;
}

