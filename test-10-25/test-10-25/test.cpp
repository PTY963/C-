#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//		cout << "������A�Ĺ��캯��" << endl;
//	}
//
//	A& operator=(const A& a)
//	{
//		cout << "�����˸�ֵ����" << endl;
//		return *this;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int b)
//		:_b(b)
//		,_aa(a)
//	{}
//private:
//	int _b = 1;//��������
//	A _aa;//�Զ�������
//};
//
//int main()
//{
//	B b(10, 20);
//	return 0;
//}

//��ʼ���б�������Ϊ����ĳ�Ա����һ��һ������ĵط�


//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};

//class B
//{
//public:
//	B(int b, int& ref, int aa)
//		:_b(b)
//		,_ref(ref)
//		,_aa(aa)
//	{}
//private:
//	const int _b;
//	int& _ref;
//	A _aa;
//};
//
//int main()
//{
//	int ref = 100;
//	B b1(10, ref, 1000);
//	return 0;
//}

//class A
//{
//public:
//	//explicit ��������ʽ����ת���ķ���
//	A(int a, int b)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//int main()
//{
//	//A a1(4);
//	//A a2 = 2;//������һ����ʽ����ת��
//	//2��int��a2��A���ͣ����Ƚ�2ת����һ��A���͵���ʱ����
//	//���������ʱ����ȥ��������a2
//	//���ǵ�ǰ�������������Ż�ֱ����2ȥ������a2
//
//	//C++98֧�ֵ�������ʽ����ת�������ǲ�֧�ֶ����
//	//C++11֧�ֶ������ʽ����ת��
//	A a3 = { 1, 2 };
//
//	return 0;
//}

 
//class A
//{
//public:
//	//��̬��Ա����û��thisָ��
//	static int Get_b()//��̬��Ա����
//	{
//		return _b;
//	}
//		
//private:
//	int _a;
//	static int _b;//����
//};
//static�������������࣬��ȫ��λ�ö���ͳ�ʼ��
//static��Ա����������ĳ�����������޷�ͨ�����캯����ʼ��
//����������ʼ�������Ǿ�̬��Ա������һ������
//int A::_b = 10;
//int main()
//{
//	A a1;
//	cout << sizeof(A) << endl;//sizeof(A)�����A��������Ķ���Ĵ�С
//	cout << sizeof(a1) << endl;//4 - ���ֳ�static���������ھ����ĳ������
//	/*cout << a1.Get_b() << endl;
//	cout << A().Get_b() << endl;*///����������� - ֻ��Ϊ�˵��ú��� - ��������ֻ����һ��
//	cout << A::Get_b() << endl;//������������������Ϊstatic����������
//	return 0;
//}


//��1+2+3+...+n�����ó˳�����if else while for
class Sum
{
public:
	Sum()
	{
		_ret += _i;
		++_i;
	}
	int GetRet()
	{
		return _ret;
	}
private:
	static int _i;//�±�
	static int _ret;//���ص�ֵ
};

int Sum::_i = 1;
int Sum::_ret = 0;
int main()
{
	Sum* p = new Sum[100];//newһ�ٸ�Sum��С�Ŀռ䣬����һ�ٴι��캯��
	cout << p->GetRet() << endl;
	return 0;
}