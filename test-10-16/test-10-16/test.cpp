#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//C���Զ�Ƶ�����õ�С���������뽨��ջ֡�������ú�����ɵ�
//#define Add(X, Y) ((X) + (Y))

//inline������C++���������ڵ������������ĵط�չ����û�е��ú�������ջ֡�Ŀ�����
//������߳������е�Ч��
//inline int Add(int x, int y)
//{
//	return x + y;
//}

//int main()
//{
//	Add(1, 2);//��debug�汾�£��ǻῪ��ջ֡�ģ���Ϊinline֧�ֵ���
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	char c = 'a';
//
//	//ͨ���ұ߸�ֵ�ı������Զ��Ƶ���߱���������
//	auto b = a;
//	auto d = c;
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;//int*
//	auto* b = &x;//int*����ʽ��ָ��b��ָ������
//	auto& c = x;//auto����int &��autoû��ϵ��c��int����x�ı���
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	auto i = 1, j = 2;
//	return 0;
//}

//C++11�ṩ���µķ�������ķ�ʽ����Χfor
//�����Զ�ȡarr�����е�ֵ��ֵ��e,�Զ��жϽ���
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5};
//	//����ȡarr��ֵ ��ֵ ������e
//	//e����һ��ռ䣬����e�ĸı䲻��Ӱ��arr
//	//for (auto e : arr)
//	//{
//	//	e *= 2;//������ı�����arr
//	//}
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//	return 0;
//}

void TestArr(int arr[])//int arr[] == int* pa;
{
	//û�и�for�ṩ��Χ
	/*for (auto e : arr)
	{

	}*/
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	TestArr(arr);
	return 0;
}