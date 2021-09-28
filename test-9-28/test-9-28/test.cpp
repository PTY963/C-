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
