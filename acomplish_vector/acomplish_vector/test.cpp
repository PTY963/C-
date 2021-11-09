#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
#include "vector.h"

//����������ȥȫ����������ռ�ȥ�ң�����ָ��

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
		if (pos != v1.end())//���ҳɹ�
		{
			v1.insert(pos, 200);
		}

		//��insert��pos������ʧЧ,��Ϊinsert���ݻ��������¿���һ��ռ䣬posָ�����ԭ���Ŀռ�
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
		if (pos != v1.end())//���ҳɹ�
		{
			v1.insert(pos, 200);
		}
		
		//��insert�Ĺ����У�û�����ݣ�pos����ָ��ԭ����λ��
		//���ǣ�����������ΪposʧЧ��
		//ԭ���ǣ�pos������ı��ˣ�������ָ��ԭ����ֵ
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
			v1.erase(pos);//erase������posʧЧ����Ϊpos��������ˣ���VS�½�����ǿ�Ƽ�鲻�ܷ���
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
