#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;

//ǰ������
class B;
//class A
//{
//friend void f(const A& a1, const B& b1);
//private:
//	int _aa = 0;	
//};
//
//class B
//{
//friend void f(const A& a1, const B& b1);
//private:
//	//ȱʡֵ
//	int _a = 10;
//	int* _p = (int*)malloc(sizeof(int) * 10);
//	
//};

//void f(const A& a1, const B& b1)
//{
//	cout << a1._aa << endl;
//	cout << b1._a << endl;
// }
//
//int main()
//{
//	A a1;
//	B b1;
//	f(a1, b1);
//	return 0;
//}

//class A
//{
//private:
//	int _k = 10;
//	static int _s;
//public:
//	class B//B��������A����Ԫ��B���Է���A��˽�г�Ա
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << a._k << endl;
//			cout << _s << endl;//����ֱ�ӷ����ⲿ��ľ�̬��Ա��ͻ���������
//		}
//	private:
//		//ȱʡֵ
//		int _a = 10;
//		int* _p = (int*)malloc(sizeof(int) * 10);
//
//	};
//};

//int A::_s = 100;
//int main()
//{
//	//B����A����ڲ��࣬��Ȼ�ܵ�A���������ƣ����Ǻ���ͨ��û������
//	cout << sizeof(A) << endl;
//	A a1;
//	//A::B b1;//B���յ������޶���������
//	A::B d1;
//	d1.foo(a1);
//	return 0;
//}

//1 + 2 + ... + n
//class Sum
//{
//public:
//	Sum()
//	{
//		_ret += _i;
//		++_i;
//	}
//	static int GetRet()
//	{
//		return _ret;
//	}
//private:
//	static int _ret;//�������Ľ��
//	static int _i;//�±�
//};
//
//int Sum::_ret = 0;
//int Sum::_i = 1;
//
//int main()
//{
//	Sum arr[100];//�����ڶ����ʱ�򣬾��Ѿ�����˳�ʼ��
//	cout << Sum::GetRet() << endl;
//	return 0;
//}

//������C++��һ����Ҫдһ���࣬���Ǽ���C��
//int main()
//{
//    int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//    int year, month, day;
//
//    //����һ��
//    cin >> year >> month >> day;//2000/2/1
//
//    int n = days[month - 1] + day;
//
//    //month == 2
//    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//    {
//        ++n;
//    }
//
//    cout << n;
//
//    return 0;
//}


//int main()
//{
//	int* p1 =(int*)malloc(sizeof(int));
//	free(p1);//free����֮��p1����ָ�����ռ�
//	
//
//	int* p2 = new int;
//	delete p2;//delete֮��p2ԭ�ȴ洢�ĵ�ַ����
//	
//	return 0;
//}

//class A
//{
//public:
//	//���캯��
//	A(int a, int b)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "������A�Ĺ��캯��" << endl;
//	}
//
//	~A()
//	{
//		cout << "������A����������" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//int main()
//{
//	/*int* p1 = (int*)malloc(sizeof(int) * 10);
//	free(p1);
//
//	int* p2 = new int [10];
//	delete[] p2;*/
//
//	A* p1 = new A(10, 20);
//	delete p1;
//	return 0;
//}

class Stack
{
public:
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


//������ǲ�д�������캯����������Ĭ�����ɵĶ������������ǳ����(memcopy)
int main()
{
	//s1�ȶ��� - �������ں���� - ������������� - ��_a��ָ��Ŀռ���еڶ���free
	//�������
	Stack s1;
	//s2���� - ���������Ƚ��� - �ȵ����������� -  ��_a��ָ��Ŀռ�free
	Stack s2(s1);
	return 0;
}