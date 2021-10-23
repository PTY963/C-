#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 10)
		:_a(a)
	{
		cout << "调用了构造函数" << endl;
	}

	A(const A& a1)
	{
		cout << "调用了拷贝构造" << endl;
	}

	A& operator=(const A &a)
	{
		cout << "调用了赋值重载" << endl;
		return *this;
	}
private:
	int _a;
};
int main()
{
	A a[5];//5次构造函数
	cout << endl;
	A* p1 = new A[5];//5次构造函数
	cout << endl;
	//复制一份a数组到p1
	for (int i = 0; i < 5; ++i)
	{
		p1[i] = a[i];//5次赋值重载
	}
	//5次赋值重载
	cout << endl;

	delete[] p1;//5次析构函数

	A* p2 = (A*)malloc(sizeof(A) * 5);
	for (int i = 0; i < 5; ++i)
	{
		//5次拷贝构造
		new(p2 + i)A(a[i]);//定位new replacement new 
		//对已分配的内存空间调用构造函数或拷贝构造来初始化对象，一般配合内存池使用
		//在内存池申请的空间是不会初始化的
	}

	return 0;
}

