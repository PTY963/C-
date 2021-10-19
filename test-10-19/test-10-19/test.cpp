#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;

//前置声明
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
//	//缺省值
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
//	class B//B天生就是A的友元，B可以访问A的私有成员
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << a._k << endl;
//			cout << _s << endl;//可以直接访问外部类的静态成员，突破类的限制
//		}
//	private:
//		//缺省值
//		int _a = 10;
//		int* _p = (int*)malloc(sizeof(int) * 10);
//
//	};
//};

//int A::_s = 100;
//int main()
//{
//	//B类是A类的内部类，虽然受到A的类域限制，但是和普通类没有区别
//	cout << sizeof(A) << endl;
//	A a1;
//	//A::B b1;//B还收到访问限定符的限制
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
//	static int _ret;//加起来的结果
//	static int _i;//下标
//};
//
//int Sum::_ret = 0;
//int Sum::_i = 1;
//
//int main()
//{
//	Sum arr[100];//对象在定义的时候，就已经完成了初始化
//	cout << Sum::GetRet() << endl;
//	return 0;
//}

//并不是C++就一定需要写一个类，它是兼容C的
//int main()
//{
//    int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//    int year, month, day;
//
//    //输入一行
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
//	free(p1);//free掉了之后p1还是指向这块空间
//	
//
//	int* p2 = new int;
//	delete p2;//delete之后，p2原先存储的地址换了
//	
//	return 0;
//}

//class A
//{
//public:
//	//构造函数
//	A(int a, int b)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "调用了A的构造函数" << endl;
//	}
//
//	~A()
//	{
//		cout << "调用了A的析构函数" << endl;
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


//如果我们不写拷贝构造函数，编译器默认生成的对内置类型完成浅拷贝(memcopy)
int main()
{
	//s1先定义 - 生命周期后结束 - 后调用析构函数 - 对_a所指向的空间进行第二次free
	//程序崩溃
	Stack s1;
	//s2后定义 - 生命周期先结束 - 先调用析构函数 -  对_a所指向的空间free
	Stack s2(s1);
	return 0;
}