#pragma once
#include <iostream>
#include <string>
using namespace std;
//深浅拷贝

//namespace zsj
//{
//	class string
//	{
//	public:
//		string(char* str)
//			:_str(new char[strlen(str) + 1])//在对上开辟，方便增删查改
//		{
//			strcpy(_str, str);
//		}
//		//深拷贝的传统写法
//		//string s2(s1)
//		//给s2开辟一块和s1一样大的空间
//		//再将s1空间的内容拷贝给s2
//		/*string(const string& str)
//			:_str(new char[strlen(str._str) + 1])
//		{
//			strcpy(_str, str._str);
//		}*/
//
//		//深拷贝的现代写法
//		string(const string& str)
//			:_str(nullptr)//防止对野指针的释放
//		{
//			string tmp(str._str);
//			swap(_str, tmp._str);
//			
//			//_str现在还是一个随机值，也就是野指针
//			//将tmp和_str交换之后，tmp._str就是随机值，野指针
//			//tmp的生命周期结束就会调用析构函数，就是对野指针的释放
//		}
//
//
//		//s1 = s3
//		//释放掉s1的空间，重新开辟一个和s3一样大小的空间
//		//将s3空间的值拷贝给s1
//		//将s1指向新空间
//		//string& operator=(const string& str)
//		//{
//		//	/*delete[] _str;
//		//	_str = new char[strlen(str._str) + 1];
//		//	strcpy(_str, str._str);*/
//		//	//假设new空间失败，那么_str不仅没得到新的空间，原先的内容也被破坏
//		//	if (this != &str)//防止自己给自己拷贝
//		//	{
//		//		char* tmp = new char[strlen(str._str) + 1];
//		//		delete[] _str;
//		//		_str = tmp;
//		//		strcpy(_str, str._str);
//		//	}
//
//		//赋值重载的现代写法
//		//s3 = s1
//		//string& operator=(const string& str)
//		//{
//		//	if (this != &str)
//		//	{
//		//		string tmp(str._str);
//		//		swap(_str, tmp._str);
//		//		//_str和tmp._str交换后，_str本身的东西随着tmp声明周期的结束而结束
//		//		return *this;
//		//	}
//		//}
//
//		//简化的赋值重载的现代写法
//		//s1 = s2
//		string& operator=(string s)//形参是s2的拷贝构造，是局部对象
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//
//
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//		size_t _size;//当前数组的有效数据的个数
//		size_t _capacity;//当前能存放的有效数据的个数，不包含'\0'
//	};
//
//	void test1()
//	{
//		/*char ch[] = "hello";
//		string s1(ch);
//		s1[0] = 'x';
//
//		string s2(s1);*/
//		/*s2[0] = 'y';
//
//		char ch2[] = "hello world";
//		string s3(ch2);
//		s1 = s3;*/
//		char ch[] = "hello world";
//		string s1(ch);
//		char ch1[] = "hello bit";
//		string s2(ch1);
//
//		s2 = s1;
//	}
//


namespace zsj
{
	class string
	{
	public:
		//构造函数
		string(char* str)
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		//拷贝构造函数 - 现实深拷贝
		/*string(const string& s)
			:_str(new char[strlen(s._str) + 1])
			, _size(strlen(_str))
		    ,_capacity( _size)
		{
			strcpy(_str, s._str);
		}*/
		//拷贝构造 - 现代简化深拷贝
		string(const string& s)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//赋值重载 - 深拷贝
		//string& operator=(const string& s)
		//{
		//	//1、将_str所指向的空间释放掉
		//	delete[] _str;
		//	//2、开辟一块和s._str一样大小的空间
		//	_str = new char[strlen(s._str) + 1];
		//	//3、将s._str所指向的内容拷贝给_str
		//	strcpy(_str, s._str);

		//	return *this;
		//}
		//但是上面的程序是有问题的
		//假设new一块空间失败，新空间不仅没有生成，_str原先指向的空间也被释放掉了
		//string& operator=(const string& s)
		//{
		//	//先开辟一块空间存放在临时指针变量tmp中，假设new失败，就会抛出异常
		//	char* tmp = new char[strlen(s._str) + 1];
		//	delete[] _str;
		//	strcpy(tmp, s._str);
		//	_str = tmp;

		//	return *this;
		//}

		//现代写法的赋值重载
		//tmp作为临时对象,tmp._str和_str交换之后，_str原先的内容被tmp._str指向着
		//tmp一旦出了作用域生命周期就结束了，_str原先的空间也就销毁了
		//
		/*string& operator=(const string& s)
		{
			string tmp(s);
			swap(_str, tmp._str);
		}*/

		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}


		void reverse(size_t capacity)
		{
			if (_capacity < capacity)
			{
				_str = new char[2 * capacity];
			}
			
		}
		//尾插一个字符
		void push_back(char ch)
		{
			if (_size + 1 >= _capacity)
			{
				reverse(2 * _capacity);
			}
			_str[_size] = ch;
			_size++;
			_capacity *= 2;
		}
		//尾插一个字符串
		void append(char* str)
		{
			if (_size + strlen(str) + 1 >= _capacity)
			{
				reverse(strlen(str) + 1);
			}
			strcpy(_str + _size, str);
			_size += strlen(str) + 1;
			_capacity += strlen(str) + 1;
		}


		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;            //当前存放的有效数据的个数
		size_t _capacity;        //当前能够存放的有效数据的个数
	};

	void TestString()
	{
		char ch1[] = "hello";
		char ch2[] = "world";
		string s1(ch1);
		s1.push_back(' ');
		s1.append(ch2);
	}
}