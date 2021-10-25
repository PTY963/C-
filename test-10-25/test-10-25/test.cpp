#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//		cout << "调用了A的构造函数" << endl;
//	}
//
//	A& operator=(const A& a)
//	{
//		cout << "调用了赋值重载" << endl;
//		return *this;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int b)
//		:_b(b)
//		,_aa(a)
//	{}
//private:
//	int _b = 1;//内置类型
//	A _aa;//自定义类型
//};
//
//int main()
//{
//	B b(10, 20);
//	return 0;
//}

//初始化列表可以理解为对象的成员变量一个一个定义的地方


//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};

//class B
//{
//public:
//	B(int b, int& ref, int aa)
//		:_b(b)
//		,_ref(ref)
//		,_aa(aa)
//	{}
//private:
//	const int _b;
//	int& _ref;
//	A _aa;
//};
//
//int main()
//{
//	int ref = 100;
//	B b1(10, ref, 1000);
//	return 0;
//}

//class A
//{
//public:
//	//explicit 不允许隐式类型转换的发生
//	A(int a, int b)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//int main()
//{
//	//A a1(4);
//	//A a2 = 2;//本质是一个隐式类型转换
//	//2是int，a2是A类型，首先将2转换成一个A类型的临时变量
//	//再用这个临时变量去拷贝构造a2
//	//但是当前编译器进行了优化直接让2去构造了a2
//
//	//C++98支持单参数隐式类型转换，但是不支持多参数
//	//C++11支持多参数隐式类型转换
//	A a3 = { 1, 2 };
//
//	return 0;
//}

 
//class A
//{
//public:
//	//静态成员函数没有this指针
//	static int Get_b()//静态成员函数
//	{
//		return _b;
//	}
//		
//private:
//	int _a;
//	static int _b;//声明
//};
//static变量属于整个类，在全局位置定义和初始化
//static成员变量不属于某个对象，所以无法通过构造函数初始化
//在类的外面初始化，算是静态成员变量的一个特例
//int A::_b = 10;
//int main()
//{
//	A a1;
//	cout << sizeof(A) << endl;//sizeof(A)算的是A定义出来的对象的大小
//	cout << sizeof(a1) << endl;//4 - 体现出static变量不属于具体的某个对象
//	/*cout << a1.Get_b() << endl;
//	cout << A().Get_b() << endl;*///匿名对象调用 - 只是为了调用函数 - 生命周期只在这一行
//	cout << A::Get_b() << endl;//可以用类来调用是因为static属于整个类
//	return 0;
//}


//求1+2+3+...+n，不用乘除法、if else while for
class Sum
{
public:
	Sum()
	{
		_ret += _i;
		++_i;
	}
	int GetRet()
	{
		return _ret;
	}
private:
	static int _i;//下标
	static int _ret;//返回的值
};

int Sum::_i = 1;
int Sum::_ret = 0;
int main()
{
	Sum* p = new Sum[100];//new一百个Sum大小的空间，调用一百次构造函数
	cout << p->GetRet() << endl;
	return 0;
}