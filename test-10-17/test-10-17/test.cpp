#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A()
//	{
//		++_count;
//	}
//
//	A(const A& a)
//	{
//		++_count;
//	}
//
//    static int GetCount()
//	{
//		return _count;
//	}
//
//private:
//	int _a;
//	static int _count;//����
//};

//����ͳ�ʼ��
//int A::_count = 0;
//int main()
//{
//	A a1;
//	//cout << sizeof(A) << endl;
//	/*cout << A::_count << endl;*/
//	/*cout << a1._count << endl;*/
//
//	//��Ҳ�����������һ���÷�
//	//cout << A().GetCount() - 1 << endl;
//	//cout << A::GetCount() << endl;//ֱ�����������
//
//	//����ֻ�ǹ����������沢������static
//	cout << sizeof(a1) << endl;
//
//	return 0;
//}


class Date
{
	//��Ԫ�������Է�������λ�ã�һ�������ǰ��
	//�з���ֵ��֧��������ֵ
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	//��ʼ���б��ʼ��
	Date(int year = 2001, int month = 9, int day = 24)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	//<<���������������
	//<<������������м�������������������غ������м�������
	//���ǣ���һ������Ĭ���Ƕ����thisָ�룬Ҳ����˵d1ռ�������������λ��
	//�����ԣ�������������
	/*void operator<<(ostream& out)
	{
		out << _year << '/' << _month << '/' << _day << endl;
	}*/

	
private:
	int _year;
	int _month;
	int _day;
};

//����ȫ�֣����ǳ�Ա������˽�еģ���Ȼ������Get������ã����Ǻ��鷳
//����C++���˷�϶����Ԫ����
//void operator<<(ostream& out)
//{
//	out << _year << '/' << _month << '/' << _day << endl;
//}

//��������غ���Ĭ�����������ָ��ǰ�����thisָ�룬���thisָ�벻������ʽ��д����
ostream& operator<<(ostream& out, const Date &d)
{
	out <<d. _year << '/' << d._month << '/' <<d. _day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//int main()
//{
//	Date d1;
//	Date d2;
//	//������������
//	//d1 << cout;//d1���ǳ�Ա�������Ƕ���������Ҫ���������
//
//	//cout << d1;// << ������ d1�������� cout 
//
//	//�������Ҹ�ֵ�� ����cout << d1 ���ڷ���ֵ��void ����d2û���������
//	cout << d1 << d2 << endl;
//
//
//
//	return 0;
//}


//int main()
//{
//	//cout �� cin �������Ϊ����
//	Date d1;
//	cin >> d1;// >> ����ȡ�����
//	cout << d1;
//	return 0;
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	//��C++�У�NULLʵ������һ���� #define NULL 0,NULL == 0
	//C++98
	int* p1 = NULL;
	int* p3 = 0;//Ҳ������0����ʼ��ָ�룬ֻ�ǲ����淶
	//C++11�Ժ���nullptr����ָ��
	int* p2 = nullptr;

	f(0);
	f(NULL);
	return 0;
}
