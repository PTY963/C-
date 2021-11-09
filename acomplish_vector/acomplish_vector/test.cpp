#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
#include "vector.h"

//编译器不会去全局域和命名空间去找，除非指定

//int main()
//{
//	//zsj::Test1();
//	zsj::Test2();
//	return 0;
//}


namespace std
{
	void Test1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator pos = find(v1.begin(), v1.end(), 2);
		if (pos != v1.end())//查找成功
		{
			v1.insert(pos, 200);
		}

		//在insert后，pos迭代器失效,因为insert扩容机制是重新开辟一块空间，pos指向的是原来的空间
		cout << *pos << endl;
		*pos = 400;
	}

	void Test2()
	{
		vector<int> v1;
		v1.reserve(7);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator pos = find(v1.begin(), v1.end(), 2);
		if (pos != v1.end())//查找成功
		{
			v1.insert(pos, 200);
		}
		
		//在insert的过程中，没有增容，pos还是指向原来的位置
		//但是，我们依旧认为pos失效了
		//原因是：pos的意义改变了，不再是指向原来的值
		cout << *pos << endl;
		*pos = 400;
	}
	void Test3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			v1.erase(pos);//erase导致了pos失效，因为pos的意义变了，在VS下进行了强制检查不能访问
		}

		cout << *pos << endl;
	}

	void Test4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		auto pos = v1.begin();
		while (pos != v1.end())
		{
			if (*pos % 2 == 0)
			{
				v1.erase(pos);
			}
			++pos;
		}

	}
	void Test5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		auto pos = v1.begin();
		while (pos != v1.end())
		{
			if (*pos % 2 == 0)
			{
				pos = v1.erase(pos);
			}
			++pos;
		}

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
	}
}

int main()
{
	zsj::Test4();
	return 0;
}
