#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//string 是basic_string<char>的typedef
//int main()
//{
//	string s1("hello");
//	//迭代器
//	//可读可写
//	/*string::iterator it = s1.begin();*/
//	basic_string<char>::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		*it += 1;
//		++it;
//	}
//
//	it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//打印并不改变数据，所以加const，&可以减少一份拷贝构造
//string::iterator it = s1.begin(); 普通迭代器，可以读也可以写
void Print(const string& s1)
{
	string::const_iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void Test1()
{
	string s1("hello");
	Print(s1);
}
void Test2()
{
	string s2("innovation");
	//反着遍历
	/*string::reverse_iterator rit = s2.rbegin();*/
	auto rit = s2.rbegin();//auto的作用就体现出来了
	while (rit != s2.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
}
void Test3()
{
	string s3("hello world");
	cout << s3 << endl;
	cout << s3.size() << endl;
	cout << "----------------------" << endl;
	s3.resize(20, 'c');
	cout << s3 << endl;
	cout << s3.size() << endl;

	s3.resize(5);
	cout << s3 << endl;
	cout << s3.size() << endl;

	//resize调整size的大小，既可以增加也可以缩减
	cout << "----------------------" << endl;
	string s4("hello world");
	cout << s4 << endl;
	cout << s4.size() << endl;//size表示的是有效数据的大小，最后一个/0不包括
	cout << s4.capacity() << endl;
	cout << "----------------------" << endl;
	s4.reserve(30);
	cout << s4.capacity() << endl;
	cout << "----------------------" << endl;
	s4.reserve(10);
	cout << s4.capacity() << endl;


}
void Test4()
{
	string s1("hello");
	cout << s1 << endl;
	cout << s1.front() << endl;
	cout << s1.back() << endl;
	/*s1.clear();
	cout << s1 << endl;*/
}
void Test5()
{
	string s1("hello");
	string s2("world");

	s1 += ' ';//可以插入一个字符
	s1 += s2;//可以插入一个对象
	s1 += "!!!!!!!?";//可以插入一串字符
	cout << s1 << endl;
	cout << "----------------------" << endl;
	cout << s1 + 'c' << endl;
	cout << s1 << endl;
}
void Test6()
{
	//取文件名的后缀
	//string file1("test.txt");
	//size_t pos = file1.find('.');//找到了返回pos，找不到返回npos（-1）
	//if (pos != string::npos)
	//{
	//	cout << file1.substr(pos) << endl;
	//}

	string file("text.txt.zip");
	size_t pos = file.rfind('.');//rfind 倒着找
	if (pos != string::npos)
		cout << file.substr(pos) << endl;
}

void Test7()
{
	//取出url的协议、域名、uri
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	cout << "------------------------------------" << endl;
	//1、取协议
	size_t p1 = url.find(':');
	if (p1 != string::npos)
	{
		string protocol = url.substr(0, p1 - 0);
		cout << "protocol : " << protocol << endl;
	}
	//2、取域名
	size_t p2 = url.find('/', p1 + 3);
	if (p2 != string::npos)
	{
		string domine = url.substr(p1 + 3, p2-(p1 + 3));
		cout << "domine : " << domine << endl;
	}
	//取uri
	cout << "uri : " << url.substr(p2 + 1) << endl;
}
//int main()
//{
//	//Test1();
//	//Test2();
//	Test7();
//	return 0;
//}

int main()
{
	string s;
	getline(cin, s);

	size_t pos = s.rfind(' ');
	if (pos != string::npos)
	{
		string s1 = s.substr(pos + 1);
		cout << s1.size() << endl;
	}
	else
	{
		cout << s.size() << endl;
	}
	return 0;

}



