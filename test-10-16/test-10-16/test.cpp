#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//C语言对频繁调用的小函数（不想建立栈帧），是用宏来完成的
//#define Add(X, Y) ((X) + (Y))

//inline函数，C++编译器会在调用内联函数的地方展开，没有调用函数建立栈帧的开销，
//可以提高程序运行的效率
//inline int Add(int x, int y)
//{
//	return x + y;
//}

//int main()
//{
//	Add(1, 2);//在debug版本下，是会开辟栈帧的，因为inline支持调试
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	char c = 'a';
//
//	//通过右边赋值的变量，自动推导左边变量的类型
//	auto b = a;
//	auto d = c;
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;//int*
//	auto* b = &x;//int*，显式的指明b是指针类型
//	auto& c = x;//auto等于int &更auto没关系，c是int，是x的别名
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	auto i = 1, j = 2;
//	return 0;
//}

//C++11提供的新的访问数组的方式：范围for
//依次自动取arr数组中的值赋值给e,自动判断结束
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5};
//	//依次取arr的值 赋值 给变量e
//	//e是另一块空间，所以e的改变不会影响arr
//	//for (auto e : arr)
//	//{
//	//	e *= 2;//并不会改变数组arr
//	//}
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//	return 0;
//}

void TestArr(int arr[])//int arr[] == int* pa;
{
	//没有给for提供范围
	/*for (auto e : arr)
	{

	}*/
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	TestArr(arr);
	return 0;
}