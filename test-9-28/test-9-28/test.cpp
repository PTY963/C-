#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//����ķ������ڴ�ֵ����
//���صĲ����Ǳ���c��������һ����ʱ����(�������ֵ��С���ǼĴ�������֮����main�����п���
//һ��ռ�)������Ĵ�ֵ���ؾͻ��һ����ʱ����
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}

//��д����÷��أ���ʱû����ʱ�����Ŀ�����������c�������ռ������
//��ʱ���ص������ǲ�ȷ���ģ�ȡ����ƽ̨������ջ֡��ʱ��᲻������ջ֡�ռ�
//�����������30�����Ѵ��ڷǷ�����(c�Ѿ�����)������������鲻��������Ϊ��ֻ��
//int& Add1(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);
//	cout << ret << endl;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	double d = 20.0;
//
//	int& ra = a;
//	double& rd = d;
//	cout << sizeof(ra) << endl;//���Ϊ�������͵Ĵ�С
//	cout << sizeof(rd) << endl;
//	return 0;
//}

#define ADD(X, Y) ((X) + (Y))
//�����м�ֵ����Ҳ��ȱ��
//1��ע������ܶ࣬���׳���
//2��û�����ͼ��
//3�������Ե���

//��������������������ȱ���


//int main()
//{
//	int a = 1;
//	char c = 'a';
//
//	//ͨ���ұ߸�ֵ�����Զ��Ƶ���������
//	//����̫����̫����auto�Զ��Ƶ����򻯴���
//	//ȱ�㣺�����˴���Ŀɶ���
//	auto d = a;
//	auto b = c;
//
//	//�鿴auto����d��b������
//	cout << typeid(d).name() << endl;
//	cout << typeid(b).name() << endl;
//	return 0;
//}

//int main()
//{
//	/*int x = 10;
//	auto a = &x;//auto�����Ƶ�
//	auto* b = &x;//��ʽ��˵����ָ������
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;*/
//
//	//C++11�ṩ��һ���µķ�������ķ�ʽ -- ��Χfor
//	//�Զ�����ȡ�����е�ֵ��ֵ��e,�Զ��жϽ���
//	int array[] = { 1,2,3,4,5 };
//	//array�����е�ֵ���ο�����e,����e�ĸı䲢����Ӱ������
//	//for (auto e : array)
//	//{
//	//	e *= 2;
//	//}
//	//for (auto e : array)
//	//{
//	//	cout << e << " ";//1,2,3,4,5
//	//}
//
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//	for (auto e : array)
//	{
//		cout << e << " ";//2,4,6,8,10
//	}
//	cout << endl;
//	
//	
//	return 0;
//}


void Fun(int a)
{
	cout << "int" << endl;
}
void Fun(int* a)
{
	cout << "int*" << endl;
}
int main()
{
	//C++98���÷�
	int* p1 = NULL;
	//#define NULL 0;
	int* p3 = 0;

	//C++11
	int* p2 = nullptr;
	Fun(0);//int��0���������泣��
	Fun(NULL);//int
	//ԭ�������C++��#define NULL 0;
	return 0;
}