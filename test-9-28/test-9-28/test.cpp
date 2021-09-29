#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//这里的返回属于传值返回
//返回的并不是变量c，而是是一个临时变量(如过返回值较小就是寄存器，反之则在main函数中开辟
//一块空间)，这里的传值返回就会多一份临时拷贝
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}

//这叫传引用返回，此时没有临时变量的拷贝，传的是c变量这块空间的内容
//这时返回的内容是不确定的，取决于平台在销毁栈帧的时候会不会清理栈帧空间
//不会清理就是30，但已存在非法访问(c已经销毁)，但编译器检查不出来，因为是只读
//int& Add1(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);
//	cout << ret << endl;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	double d = 20.0;
//
//	int& ra = a;
//	double& rd = d;
//	cout << sizeof(ra) << endl;//结果为引用类型的大小
//	cout << sizeof(rd) << endl;
//	return 0;
//}

#define ADD(X, Y) ((X) + (Y))
//宏虽有价值，但也有缺点
//1、注意事项很多，容易出错
//2、没有类型检查
//3、不可以调试

//内联函数就是来解决宏的缺点的


//int main()
//{
//	int a = 1;
//	char c = 'a';
//
//	//通过右边赋值对象，自动推导变量类型
//	//类型太复杂太长，auto自动推导，简化代码
//	//缺点：牺牲了代码的可读性
//	auto d = a;
//	auto b = c;
//
//	//查看auto变量d和b的类型
//	cout << typeid(d).name() << endl;
//	cout << typeid(b).name() << endl;
//	return 0;
//}

//int main()
//{
//	/*int x = 10;
//	auto a = &x;//auto正常推导
//	auto* b = &x;//显式的说明是指针类型
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;*/
//
//	//C++11提供了一种新的访问数组的方式 -- 范围for
//	//自动依次取数组中的值赋值给e,自动判断结束
//	int array[] = { 1,2,3,4,5 };
//	//array数组中的值依次拷贝给e,所以e的改变并不会影响数组
//	//for (auto e : array)
//	//{
//	//	e *= 2;
//	//}
//	//for (auto e : array)
//	//{
//	//	cout << e << " ";//1,2,3,4,5
//	//}
//
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//	for (auto e : array)
//	{
//		cout << e << " ";//2,4,6,8,10
//	}
//	cout << endl;
//	
//	
//	return 0;
//}


void Fun(int a)
{
	cout << "int" << endl;
}
void Fun(int* a)
{
	cout << "int*" << endl;
}
int main()
{
	//C++98的用法
	int* p1 = NULL;
	//#define NULL 0;
	int* p3 = 0;

	//C++11
	int* p2 = nullptr;
	Fun(0);//int，0被当做字面常量
	Fun(NULL);//int
	//原因就在于C++中#define NULL 0;
	return 0;
}