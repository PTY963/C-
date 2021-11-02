#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void TestVector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//1���±� + []
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��Χfor
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;

}

void TestVector2()
{
	vector<int> v;//�޲ε�
	vector<int> v1(8, 10);//ָ�����ٶ��Ŀռ䣬��ʼ����ʲô����Ĭ�ϳ�ʼ����0
	vector<int>::const_iterator cit = v1.begin();
	vector<int> v2(v1.begin(), v1.begin() + 6);//������
	vector<int> v3(v2);//����
}

void TestVector3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	int* ret = find(array, array + 5, 2);
	if (ret != array + 5)
	{
		*ret = 200;
	}

	for (auto e : array)
	{
		cout << e << ' ';
	}
	cout << endl;

	
}

void TestVector4()
{
	vector<int> v1;
	v1.push_back(12);
	v1.push_back(12);
	v1.push_back(56);
	v1.push_back(37);
	v1.push_back(4);

	/*sort(v1.begin(), v1.end());*///Ĭ��������
	sort(v1.begin(), v1.end(), greater<int>());
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;
}
void TestVector5()
{
	/*vector<int> v1;
	v1.resize(5);
	for (auto& e : v1)
	{
		e += 1;
	}

	v1.resize(10);*/

	/*vector<int> v1(10, 100);
	vector<int> v2(5, 120);
	v1.swap(v2);*/

	/*vector<int> v1(10, 100);
	v1.clear();*/

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << ' ';
		++rit;
	}
	cout << endl;

	

}
int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	TestVector5();
	return 0;
}

