#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include <iostream>
using namespace std;

//C������������̵�  -  ���ݺͷ����Ƿ����
//C++����������  -  ���ݺͷ����Ƿ�װ��һ���
//��C++�� struct�Ѿ��������ǽṹ���ˣ�ͬʱ����������
namespace Zsj
{
	//struct�����д�����޶�����Ĭ���ǹ��еģ���ΪҪ����C��
	struct Student
	{
		void SetStudentInfo(const char* name, const char* gender, int age)
		{
			strcpy(_name, name);
			strcpy(_gender, gender);
			_age = age;
		}

		void PrintStudentInfo()
		{
			cout << _name << " " << _gender << " " << _age << endl;
		}


		char _name[20];
		char _gender[3];
		int _age;
	};

//�����C void StackInit(Stack* ps); - ���ֺͲ���������ͬ

	//class�����д�����޶�����Ĭ����˽�е�
	class Stack
	{
	//�����޶���
	//���ñ��������������ֱ�ӷ��ʵĶ���ɹ���
	//�����ñ�����������ֱ�ӷ��ʵĶ����˽��
	public:
		void Init(){}
		void Push(int x){}
		void Pop(){}
		void Destory(){}
		//...

	private:
		int* _a;
		int _top;
		int _capcity;
	};
}
//int main()
//{
//	Zsj::Student s1;
//	s1.SetStudentInfo("Peter", "��", 19);
//	s1.PrintStudentInfo();
//
//	Zsj::Stack s2;
//	s2.Init();
//	return 0;
//}


//int main()
//{
//	Queue q1;//��Ա�������ڶ��󣬶���ʵ�����ǣ��������Ƕ���ĵط�
//	q1.Init();
//	q1.Push(1);
//	q1.Push(2);
//	q1.Push(3);
//
//	Queue q2;
//	q1.Init();
//	q1.Push(1);
//
//	//������(����)��С���߼�������С��ֻ���ǳ�Ա�����Ĵ�С
//	//��Ϊ�����У�ֻ���˳�Ա������û�д��Ա����
//	cout << sizeof(q1) << endl;//8
//	cout << sizeof(q2) << endl;//8
//	return 0;
//}

//û�г�Ա��������
class A
{
public:
	void Print()
	{}
};

//����
class B
{

};

int main()
{
	//���һ����û�г�Ա��������ô���Ķ�����Ҫ��һ�ֽڽ���ռλ����ʶ�������
	//��һ�ֽڲ��洢��Ч����
	cout << sizeof(A) << endl;//1
	cout << sizeof(B) << endl;//1
	return 0;
}