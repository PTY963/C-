#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//	friend class Date;
//private:
//	int _a;
//};
//class Date
//{
//	friend ostream& operator<<(ostream& out,  const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	//成员函数默认this指针是左操作数
//	/*void operator<<(ostream& cout)
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}*/
//	void f()
//	{
//		_aa._a = 10;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _aa;
//};
////不是成员函数，就没有this指针，参数的顺序就可以遵循流的特性
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << '-' << d._month << '-' << d._day << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//int main()
//{
//	Date d1;
//	Date d2;
//	cin >> d1 >> d2;//流是对象
//	cout << d1 << d2;
//	//d1 << cout;
//	
//	return 0;
//}

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//class A
//{
//private:
//	int _a = 10;
//	int* p1 =(int*)malloc(sizeof(int) * 10);
//	B _b1;
//};
//int main()
//{
//	A a1;
//	return 0;
//}


//class A
//{
//private:
//	static int _a1;
//	int _a2;
//public:
//	//B作为A的内部类，跟普通类没有区别
//	//只是受到A类类域的限制(A::B b)和访问限定符的限制(public private)
//	//B天生就是A的友元，B可以访问A的私有成员变量
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _a1 << endl;
//			cout << a._a2 << endl;
//		}
//		
//	private:
//		int _b1;
//		int _b2;
//	};
//};
//int A::_a1 = 0;
//int main()
//{
//	A aa;
//	A::B bb;
//	bb.foo(aa);
//}

//class Sum
//{
//	friend class Solution;
//public:
//	Sum()
//	{
//		_ret += _i;
//		++_i;
//	}
//private:
//	static int _i;
//	static int _ret;
//};
//int Sum::_i = 1;
//int Sum::_ret = 0;
//class Solution
//{
//public:
//	int Sum_Solution(int n)
//	{
//		Sum* p = new Sum[n];//调用n次构造函数
//		return Sum::_ret;
//	}
//};

//class Solution
//{
//private:
//	//Sum是专门来服务Solution类的
//	//Sum作为Solution类的内部类，天生就是Solution类的友元，
//	//可以访问Solution类的成员变量
//	class Sum
//	{
//		friend class Solution;
//	public:
//		Sum()
//		{
//			_ret += _i;
//			++_i;
//		}
//	};
//
//public:
//	int Sum_Solution(int n)
//	{
//		Sum* p = new Sum[n];//调用n次构造函数
//		return _ret;
//	}
//private:
//	static int _i;
//	static int _ret;
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;
//int main()
//{
//	Solution s;
//	cout << s.Sum_Solution(100) << endl;
//	return 0;
//}

//实现日期到天数的转换
//int main()
//{
//
//	int DayOfMonth[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int year, month, day;
//	cin >> year >> month >> day;//2021 10 27
//
//	int days = DayOfMonth[month - 1] + day;
//
//	if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		cout <<  days + 1 << endl;
//	}
//
//	cout << days << endl;
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "调用了构造函数" << endl;
//	}
//	~A()
//	{
//		cout << "调用了析构函数" << endl;
//	}
//private:
//	int _a;
//};
//#include <stdlib.h>
//int main()
//{
//	//int* p1 = (int*)malloc(sizeof(int));
//	//free(p1);
//
//	//int* p2 = new int;
//	//delete p2;
//	////对于内置类型，malloc/free 、new/delete 没啥区别
//	cout << "-----------------------------" << endl;
//
//	A* p1 = (A*)malloc(sizeof(A));
//	free(p1);
//
//	/*A* p2 = new A;*/
//	A* p2 = new A(10);
//	delete p2;
//
//	A* p3 = new A[10];
//	delete[] p3;
//	return 0;
//}

int main()
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;
	int size_pos = 0;
	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);//How_ 
		cout << strResult << " ";//How_are_
		size_prev_pos = ++size_pos;//4 8
	}

	if (size_prev_pos != strText.size())
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";// you?
	}

	cout << endl;

	return 0;
}