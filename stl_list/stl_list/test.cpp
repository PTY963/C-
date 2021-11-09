#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
#include "list.h"

namespace std
{
	void test1()
	{
		list<int> lt;
		list<int> lt1(10, 5);
		list<int> lt2(lt1.begin(), lt1.end());
		vector<int> v = { 1, 2, 3, 4, 5 };
		list<int> lt3(v.begin(), v.end()); //֧�����������ĵ���������Ϊ���õ���ģ�����

		list<int>::reverse_iterator it = lt3.rbegin();
		while (it != lt3.rend())//������ֻ����!=����Ϊ�����ַ�ǲ�������
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		//�﷨��
		for (auto e : lt3)
		{
			cout << e << ' ';
		}
		cout << endl;

	}

	void test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);

		for (auto e : lt)
		{
			cout << e << ' ';
		}
		cout << endl;

		lt.pop_back();
		lt.pop_back();
		lt.pop_back();
		lt.pop_back();
		lt.pop_front();
		for (auto e : lt)
		{
			cout << e << ' ';
		}
		cout << endl;
	}

	void test3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		//list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
		//if (pos != lt.end())    //find����ʧ�ܻ᷵��end()- ��Ч���ݵ���һ��λ��
		//{
		//	lt.insert(pos, 20); //ע�⣺insert����pos֮ǰ��λ�ò�������
		//}

		////��insert֮��pos�������Ƿ��ʧЧ - ����ʧЧ
		//cout << *pos << endl;//2
		//*pos = 200;

		//for (auto e : lt)//1 20 200 3 4
		//{
		//	cout << e << ' ';
		//}
		//cout << endl;
		list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
		if (pos != lt.end())
		{
			lt.erase(pos);
		}

		//erase֮�󣬵�������ʧЧ����Ϊposλ�õĽ�㱻�ͷţ�pos��ΪҰָ��
		//��Ұָ��ķ����Ǵ����
		cout << *pos << endl;



	}
}

int main()
{
	//test3();
	zsj::Test1();
	return 0;
}

