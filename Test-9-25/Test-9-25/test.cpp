#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
////命名空间关键字
//namespace bit
//{
//	//可以定义变量、函数、类型
//	int rand = 10;
//
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//
//	struct Node
//	{
//		int val;
//		struct Node* next;
//	};
//}

//int main()
//{
//	printf("%d\n", bit::rand);
//	bit::Add(1, 2);
//	struct bit::Node node;
//	return 0;
//}

//#include <iostream>
//using namespace std; 
//不推荐这种写法，原因：CPP中将标准库里的名字全包在了std这个命名空间里
//目的就是不让程序员定义的东西和库里冲突，全部展开后std的优势就没有了

//工程项目中常见的命名空间的用法
//将常用的展开
//using std::cout;
//using std::endl;
//int main()
//{
//	//标准写法
//	//std::cout << "hello world" << std::endl;//但是cout和endl是经常要用到的
//	//这样的写法太麻烦
//	cout << "hello world" << endl;
//
//	
//	return 0;
//}

/*#include <iostream>
using namespace std;*/ //日常练习，可以全部展开

//int main()
//{
//	int n;
//	cin >> n;// >> 输入运算符，官方的叫法：流提取运算符
//
//	//int* arr = (int*)malloc(sizeof(int) * n);
//	double* arr = (double*)malloc(sizeof(double) * n);
//	
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << arr[i] << " ";
//	}
//
//	cout << endl;//endl也是对象，换行的意思
//	cout << '\n';
//	return 0;
//}

//int main()
//{
//	char ch = 'A';
//	int i = 10;
//	double d = 2.0;//最多输出小数点后的五位，如果指定输出几位建议用printf
//	int* p = &i;
//
//	//cout可以自动识别变量的类型
//	cout << ch << endl;
//	cout << i << endl;
//	cout << d << endl;
//	cout << p << endl;
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//void TestFunc(int a = 0)//参数缺省值
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc();//不传，参数就是0
//	TestFunc(10);//传 参数就是自己传的
//	return 0;
//}

//#include "Add.h"
//#include <iostream>
//using namespace std;
//
////缺省参数的函数，函数的声明和定义不可以同时出现
////为了防止缺省值不同的情况(如果值不同，那么编译器不知道用那一个缺省值)
////但是缺省值就算相同也不可以同时出现
////函数定义的时候，不给出缺省值，函数声明的时候给出
//int main()
//{
//	int sum = Add(3);
//	cout << sum << endl;
//}

//函数重载
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);
	return 0;
}

