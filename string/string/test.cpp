#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//string ��basic_string<char>��typedef
//int main()
//{
//	string s1("hello");
//	//������
//	//�ɶ���д
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

//��ӡ�����ı����ݣ����Լ�const��&���Լ���һ�ݿ�������
//string::iterator it = s1.begin(); ��ͨ�����������Զ�Ҳ����д
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
	//���ű���
	/*string::reverse_iterator rit = s2.rbegin();*/
	auto rit = s2.rbegin();//auto�����þ����ֳ�����
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

	//resize����size�Ĵ�С���ȿ�������Ҳ��������
	cout << "----------------------" << endl;
	string s4("hello world");
	cout << s4 << endl;
	cout << s4.size() << endl;//size��ʾ������Ч���ݵĴ�С�����һ��/0������
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

	s1 += ' ';//���Բ���һ���ַ�
	s1 += s2;//���Բ���һ������
	s1 += "!!!!!!!?";//���Բ���һ���ַ�
	cout << s1 << endl;
	cout << "----------------------" << endl;
	cout << s1 + 'c' << endl;
	cout << s1 << endl;
}
void Test6()
{
	//ȡ�ļ����ĺ�׺
	//string file1("test.txt");
	//size_t pos = file1.find('.');//�ҵ��˷���pos���Ҳ�������npos��-1��
	//if (pos != string::npos)
	//{
	//	cout << file1.substr(pos) << endl;
	//}

	string file("text.txt.zip");
	size_t pos = file.rfind('.');//rfind ������
	if (pos != string::npos)
		cout << file.substr(pos) << endl;
}

void Test7()
{
	//ȡ��url��Э�顢������uri
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	cout << "------------------------------------" << endl;
	//1��ȡЭ��
	size_t p1 = url.find(':');
	if (p1 != string::npos)
	{
		string protocol = url.substr(0, p1 - 0);
		cout << "protocol : " << protocol << endl;
	}
	//2��ȡ����
	size_t p2 = url.find('/', p1 + 3);
	if (p2 != string::npos)
	{
		string domine = url.substr(p1 + 3, p2-(p1 + 3));
		cout << "domine : " << domine << endl;
	}
	//ȡuri
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



