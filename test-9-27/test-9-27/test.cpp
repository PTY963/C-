#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//���� - ���Ѵ��ڵı����������ã����Ὺ�ٿռ䣬ֻ��ȡһ�����ְ���
//int main()
//{
//	int a = 10;
//	int& b = a;//������a��һ����ƽ�b
//	int& c = a;//������a��һ����ƽ�c ,û�����ƿ���ȡ�ܶ�����
//	int& d = b;//Ҳ���Ը�a�ı��ȡ����
//
//
//	//int& e;//�����ڶ���ʱ�����ʼ��
//	return 0;
//}


//����һ��������һ��ʵ��Ͳ�������������ʵ��
//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	int c = 10;
//	b = c;//�������˼�ǽ�����c��ֵ���Ƹ�b,������b������c
//
//	return 0;
//}


//�βα����ĸı���ҪӰ��ʵ�Σ�����ѡ��ʵ�εĵ�ַ��Ҳ���Կ���������
//void Swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
////�����ǲ����ٿռ�ģ��õ���ԭ�����Ŀռ�
//void Swap(int& rx, int& ry)
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//int main()
//{
//	int x = 10;
//	int y = 20;
//	Swap(&x, &y);
//	Swap(x, y);
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	int* p1 = &x;//������x�ĵ�ַ�����ָ�����p1��
//	int*& p2 = p1;//��ָ�����p1ȡ����p2
//	return 0;
//}

//������ - const����
//�ұ����ı�����������������С���߲��ı���Ķ�дȨ�ޣ��������ԷŴ���Ķ�дȨ��
//int main()
//{
//	const int a = 10;
//	//int& b = a;
//	const int& b = a;
//	//b = 20;//����ͻᱨ��
//
//
//	int c = 20;
//	const int& d = c;
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int ret = Add(2, 3);
//	cout << ret << endl;
//	return 0;
//}

//�ȿ��Խ��ձ���Ҳ���Խ��ճ���
//void Func(const int& ra)
//{
//	cout << ra << endl;
//}
//int main()
//{
//	int a = 10;
//	Func(a);
//	Func(20);
//	
//	const int& c = 30;
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	double& ri = i;
//	return 0;
//}

//int main()
//{
//	char ch = 0xff;
//	int i = 0xff;
//	//1111 1111
//	//00000000 00000000 00000000 1111 1111
//
//	//chҪ������int 
//	//11111111 11111111 11111111 11111111 - ch
//	//00000000 00000000 00000000 11111111 - i
//	//�����ch������int,��ı�ch�� - ���ᣬch����char����
//	if (ch == i)
//	{
//		cout << "��ͬ" << endl;
//	}
//	else
//	{
//		cout << "����ͬ" << endl;
//	}
//	return 0;
//}


int Add(int a, int b)
{
	int c = a + b;
	return c;
}
//����c�ڷ��ص�ʱ���Ѿ������٣�ret���յĲ����Ǳ���c��ֵ
//���Զ�c���������Ǵ����
//����c��ǰ��ֵ��һ����ʱ����(���ֵ��С���ͷ��ڼĴ����У����ֵ�ܴ󣬾���ǰ��main������
//����һ����ʱ�ռ�)
//��ʱ�����������ԣ����������Ƕ���ʱ���������ã���Ҫ����const
int main()
{
	//int ret = Add(2, 3);
	//int& ret = Add(2, 3); //���� - ��c�������ɷ���ֵ�ˣ���ʵ����ֵ����ʱ����
	const int& ret = Add(2, 3);
	return 0;
}