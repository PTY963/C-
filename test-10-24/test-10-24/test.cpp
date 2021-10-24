#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//函数模板
template<class T>
void Swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;

}

//int main()
//{
//	int a = 10, b = 20;
//	double c = 16.3, d = 20.5;
//	Swap(a, b);
//	Swap(c, d);
//}

//类模板
template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_a(new T[capacity])
		,_top(0)
		,_capacity(0)
	{}

	void Push(const T& x);
	

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	T* _a;
	int _top;
	int _capacity;
};

//类模板声明 - 类外面定义
template<class T>
void Stack<T>::Push(const T& x)
{

}
//int main()
//{
//	//类模板必须显示实例化
//	Stack<int> s1;
//	return 0;
//}


//函数模板实例化：1、通过实参来推演形参的类型 2、实例化生成具体函数
//template<class T>
//void Func(int x)
//{
//	T a(x);//调用构造函数
//}
//
//
//int main()
//{
//	Func<int>(10);
//	return 0;
//}

//int main()
//{
//	char arr[] = "郑州";
//	//cout << arr << endl;
//
//	arr[0] = -65;
//	cout << arr << endl;
//	return 0;
//}

#include <string>

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3("郑州");
//	string s4(16, 'a');
//	string s5(s2);
//
//	/*cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;*/
//
//	//string类重载了[]
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		cout << s2[i] << ' ';
//	}
//	cout << endl;
//
//	for (auto& e : s2)//依次取s2中的元素拷贝到e中
//	{
//		e += 1;
//	}
//	for (auto e : s2)
//	{
//		cout << e;
//	}
//	cout << endl;
//	
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	s1.push_back('+');//尾插一个字符
//	s1.append("world");//插入一个字符串
//
//	//但是，更推荐大家用 +=
//	s1 += '!';
//	s1 += "张思佳";
//
//	cout << s1 << endl;
//	return 0;
//}

class Weight
{
public:
	Weight(){}
	Weight(const Weight& w)
	{
		cout << "调用了拷贝构造";
	}

};

Weight func()
{
	Weight W;
	return W;//返回一个临时对象 - 调用了一次拷贝构造
}
//调用了几次拷贝构造？- 理论上有两次拷贝构造 但是编译器进行了优化
int main()
{
	Weight ret = func();//一次拷贝构造
	
	return 0;
}


