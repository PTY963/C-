#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main()
//{
//	cout << sizeof(long) << endl;//0-3
//	cout << sizeof(short) << endl;//4-5
//	cout << sizeof(int) << endl;//8-11
//	cout << sizeof(int*) << endl;//16 - 23
//
//	return 0;
//}

//class W
//{
//public:
//	//构造函数
//	W(){}
//	
//
//	//拷贝构造
//	W(const W& w)
//	{
//		cout << "调用了拷贝构造函数" << endl;
//	}
//	//赋值重载
//	void operator=(const W& w)
//	{
//		cout << "调用了赋值重载" << endl;
//	}
//	//析构函数
//	~W(){}
//private:
//	
//};
//
//W f1()
//{
//	W w1;
//	return w1;//调用拷贝构造一次
//}
//int main()
//{
//	W ret = f1();//本来还需要一次拷贝构造，但是编译器优化了，只需要一次
//	return 0;
//}

//引用做返回值
//传值返回
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//	//编译器会将c的内容拷贝到一个临时变量里(寄存器或者main函数的一块空间)
//	//临时变量具有常属性
//}
//int main()
//{
//	const int& ret = Add(3, 5);//临时变量具有常属性，对一个常属性的变量引用，类型不匹配
//	return 0;
//}

//传引用返回
//但是结果是不确定的，取决于编译器在销毁栈帧的时候是否会清理栈帧空间
//如果不清理，答案就是8，如果清理就是随机值，但这样的行为是非法访问
//VS是不会清理栈帧的，但即使运行结果对了，程序也是错误的
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//	
//}
//int main()
//{
//	int ret = Add(3, 5);
//	cout << ret << endl;
//	return 0;
//}

//传值返回和传引用返回的区别就是：传值返回会有一份临时拷贝，传引用没有
//但是传引用返回可能会有非法访问的行为


//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//
//}
//int main()
//{
//	int& ret = Add(3, 5);//此时ret是c的别名(但是c已经还给操作系统了)
//	//Add(4, 10);//再次调用Add函数，c这块空间的内容被改成了14
//	cout << "Hello World" << endl;//调用cout函数，也会开辟一块栈帧，
//	/*会将Add函数的栈帧覆盖掉，也就将c变量这块空间修改掉*/
//	cout << ret << endl;//14
//	return 0;
//}

//非法访问，编译器一般查不出来

//出了函数的作用域，变量销毁，就不可以用引用返回，只能值返回（多一次拷贝）
//出了函数的作用域，变量不会销毁，就可以用引用返回，减少一次拷贝



