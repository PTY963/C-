#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//引用 - 对已存在的变量进行引用，不会开辟空间，只是取一个名字罢了
//int main()
//{
//	int a = 10;
//	int& b = a;//给变量a换一个别称叫b
//	int& c = a;//给变量a换一个别称叫c ,没有限制可以取很多名字
//	int& d = b;//也可以给a的别称取名字
//
//
//	//int& e;//引用在定义时必须初始化
//	return 0;
//}


//引用一旦引用了一个实体就不可以引用其他实体
//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	int c = 10;
//	b = c;//代码的意思是将变量c的值复制给b,而不是b引用了c
//
//	return 0;
//}


//形参变量的改变想要影响实参，可以选择传实参的地址，也可以考虑用引用
//void Swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
////引用是不开辟空间的，用的是原变量的空间
//void Swap(int& rx, int& ry)
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//int main()
//{
//	int x = 10;
//	int y = 20;
//	Swap(&x, &y);
//	Swap(x, y);
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	int* p1 = &x;//将变量x的地址存放在指针变量p1中
//	int*& p2 = p1;//给指针变量p1取别名p2
//	return 0;
//}

//常引用 - const引用
//我变成你的别名的条件：可以缩小或者不改变你的读写权限，但不可以放大你的读写权限
//int main()
//{
//	const int a = 10;
//	//int& b = a;
//	const int& b = a;
//	//b = 20;//程序就会报错
//
//
//	int c = 20;
//	const int& d = c;
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int ret = Add(2, 3);
//	cout << ret << endl;
//	return 0;
//}

//既可以接收变量也可以接收常量
//void Func(const int& ra)
//{
//	cout << ra << endl;
//}
//int main()
//{
//	int a = 10;
//	Func(a);
//	Func(20);
//	
//	const int& c = 30;
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	double& ri = i;
//	return 0;
//}

//int main()
//{
//	char ch = 0xff;
//	int i = 0xff;
//	//1111 1111
//	//00000000 00000000 00000000 1111 1111
//
//	//ch要提升成int 
//	//11111111 11111111 11111111 11111111 - ch
//	//00000000 00000000 00000000 11111111 - i
//	//这里把ch提升成int,会改变ch吗？ - 不会，ch还是char类型
//	if (ch == i)
//	{
//		cout << "相同" << endl;
//	}
//	else
//	{
//		cout << "不相同" << endl;
//	}
//	return 0;
//}


int Add(int a, int b)
{
	int c = a + b;
	return c;
}
//变量c在返回的时候，已经被销毁，ret接收的并不是变量c的值
//所以对c进行引用是错误的
//变量c提前将值给一个临时变量(如果值很小，就放在寄存器中，如果值很大，就提前在main函数中
//开辟一块临时空间)
//临时变量具有属性，所以引用是对临时变量的引用，需要加上const
int main()
{
	//int ret = Add(2, 3);
	//int& ret = Add(2, 3); //错误 - 将c变量当成返回值了，其实返回值是临时变量
	const int& ret = Add(2, 3);
	return 0;
}