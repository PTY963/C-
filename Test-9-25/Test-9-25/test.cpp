#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
////�����ռ�ؼ���
//namespace bit
//{
//	//���Զ������������������
//	int rand = 10;
//
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//
//	struct Node
//	{
//		int val;
//		struct Node* next;
//	};
//}

//int main()
//{
//	printf("%d\n", bit::rand);
//	bit::Add(1, 2);
//	struct bit::Node node;
//	return 0;
//}

//#include <iostream>
//using namespace std; 
//���Ƽ�����д����ԭ��CPP�н���׼���������ȫ������std��������ռ���
//Ŀ�ľ��ǲ��ó���Ա����Ķ����Ϳ����ͻ��ȫ��չ����std�����ƾ�û����

//������Ŀ�г����������ռ���÷�
//�����õ�չ��
//using std::cout;
//using std::endl;
//int main()
//{
//	//��׼д��
//	//std::cout << "hello world" << std::endl;//����cout��endl�Ǿ���Ҫ�õ���
//	//������д��̫�鷳
//	cout << "hello world" << endl;
//
//	
//	return 0;
//}

/*#include <iostream>
using namespace std;*/ //�ճ���ϰ������ȫ��չ��

//int main()
//{
//	int n;
//	cin >> n;// >> ������������ٷ��Ľз�������ȡ�����
//
//	//int* arr = (int*)malloc(sizeof(int) * n);
//	double* arr = (double*)malloc(sizeof(double) * n);
//	
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << arr[i] << " ";
//	}
//
//	cout << endl;//endlҲ�Ƕ��󣬻��е���˼
//	cout << '\n';
//	return 0;
//}

//int main()
//{
//	char ch = 'A';
//	int i = 10;
//	double d = 2.0;//������С��������λ�����ָ�������λ������printf
//	int* p = &i;
//
//	//cout�����Զ�ʶ�����������
//	cout << ch << endl;
//	cout << i << endl;
//	cout << d << endl;
//	cout << p << endl;
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//void TestFunc(int a = 0)//����ȱʡֵ
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc();//��������������0
//	TestFunc(10);//�� ���������Լ�����
//	return 0;
//}

//#include "Add.h"
//#include <iostream>
//using namespace std;
//
////ȱʡ�����ĺ����������������Ͷ��岻����ͬʱ����
////Ϊ�˷�ֹȱʡֵ��ͬ�����(���ֵ��ͬ����ô��������֪������һ��ȱʡֵ)
////����ȱʡֵ������ͬҲ������ͬʱ����
////���������ʱ�򣬲�����ȱʡֵ������������ʱ�����
//int main()
//{
//	int sum = Add(3);
//	cout << sum << endl;
//}

//��������
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);
	return 0;
}

