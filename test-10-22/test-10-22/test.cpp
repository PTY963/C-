#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 10)
		:_a(a)
	{
		cout << "�����˹��캯��" << endl;
	}

	A(const A& a1)
	{
		cout << "�����˿�������" << endl;
	}

	A& operator=(const A &a)
	{
		cout << "�����˸�ֵ����" << endl;
		return *this;
	}
private:
	int _a;
};
int main()
{
	A a[5];//5�ι��캯��
	cout << endl;
	A* p1 = new A[5];//5�ι��캯��
	cout << endl;
	//����һ��a���鵽p1
	for (int i = 0; i < 5; ++i)
	{
		p1[i] = a[i];//5�θ�ֵ����
	}
	//5�θ�ֵ����
	cout << endl;

	delete[] p1;//5����������

	A* p2 = (A*)malloc(sizeof(A) * 5);
	for (int i = 0; i < 5; ++i)
	{
		//5�ο�������
		new(p2 + i)A(a[i]);//��λnew replacement new 
		//���ѷ�����ڴ�ռ���ù��캯���򿽱���������ʼ������һ������ڴ��ʹ��
		//���ڴ������Ŀռ��ǲ����ʼ����
	}

	return 0;
}

