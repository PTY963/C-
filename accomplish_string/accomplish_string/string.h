#pragma once
#include <iostream>
#include <string>
using namespace std;
//��ǳ����

//namespace zsj
//{
//	class string
//	{
//	public:
//		string(char* str)
//			:_str(new char[strlen(str) + 1])//�ڶ��Ͽ��٣�������ɾ���
//		{
//			strcpy(_str, str);
//		}
//		//����Ĵ�ͳд��
//		//string s2(s1)
//		//��s2����һ���s1һ����Ŀռ�
//		//�ٽ�s1�ռ�����ݿ�����s2
//		/*string(const string& str)
//			:_str(new char[strlen(str._str) + 1])
//		{
//			strcpy(_str, str._str);
//		}*/
//
//		//������ִ�д��
//		string(const string& str)
//			:_str(nullptr)//��ֹ��Ұָ����ͷ�
//		{
//			string tmp(str._str);
//			swap(_str, tmp._str);
//			
//			//_str���ڻ���һ�����ֵ��Ҳ����Ұָ��
//			//��tmp��_str����֮��tmp._str�������ֵ��Ұָ��
//			//tmp���������ڽ����ͻ�����������������Ƕ�Ұָ����ͷ�
//		}
//
//
//		//s1 = s3
//		//�ͷŵ�s1�Ŀռ䣬���¿���һ����s3һ����С�Ŀռ�
//		//��s3�ռ��ֵ������s1
//		//��s1ָ���¿ռ�
//		//string& operator=(const string& str)
//		//{
//		//	/*delete[] _str;
//		//	_str = new char[strlen(str._str) + 1];
//		//	strcpy(_str, str._str);*/
//		//	//����new�ռ�ʧ�ܣ���ô_str����û�õ��µĿռ䣬ԭ�ȵ�����Ҳ���ƻ�
//		//	if (this != &str)//��ֹ�Լ����Լ�����
//		//	{
//		//		char* tmp = new char[strlen(str._str) + 1];
//		//		delete[] _str;
//		//		_str = tmp;
//		//		strcpy(_str, str._str);
//		//	}
//
//		//��ֵ���ص��ִ�д��
//		//s3 = s1
//		//string& operator=(const string& str)
//		//{
//		//	if (this != &str)
//		//	{
//		//		string tmp(str._str);
//		//		swap(_str, tmp._str);
//		//		//_str��tmp._str������_str����Ķ�������tmp�������ڵĽ���������
//		//		return *this;
//		//	}
//		//}
//
//		//�򻯵ĸ�ֵ���ص��ִ�д��
//		//s1 = s2
//		string& operator=(string s)//�β���s2�Ŀ������죬�Ǿֲ�����
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//
//
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//		size_t _size;//��ǰ�������Ч���ݵĸ���
//		size_t _capacity;//��ǰ�ܴ�ŵ���Ч���ݵĸ�����������'\0'
//	};
//
//	void test1()
//	{
//		/*char ch[] = "hello";
//		string s1(ch);
//		s1[0] = 'x';
//
//		string s2(s1);*/
//		/*s2[0] = 'y';
//
//		char ch2[] = "hello world";
//		string s3(ch2);
//		s1 = s3;*/
//		char ch[] = "hello world";
//		string s1(ch);
//		char ch1[] = "hello bit";
//		string s2(ch1);
//
//		s2 = s1;
//	}
//


namespace zsj
{
	class string
	{
	public:
		//���캯��
		string(char* str)
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		//�������캯�� - ��ʵ���
		/*string(const string& s)
			:_str(new char[strlen(s._str) + 1])
			, _size(strlen(_str))
		    ,_capacity( _size)
		{
			strcpy(_str, s._str);
		}*/
		//�������� - �ִ������
		string(const string& s)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//��ֵ���� - ���
		//string& operator=(const string& s)
		//{
		//	//1����_str��ָ��Ŀռ��ͷŵ�
		//	delete[] _str;
		//	//2������һ���s._strһ����С�Ŀռ�
		//	_str = new char[strlen(s._str) + 1];
		//	//3����s._str��ָ������ݿ�����_str
		//	strcpy(_str, s._str);

		//	return *this;
		//}
		//��������ĳ������������
		//����newһ��ռ�ʧ�ܣ��¿ռ䲻��û�����ɣ�_strԭ��ָ��Ŀռ�Ҳ���ͷŵ���
		//string& operator=(const string& s)
		//{
		//	//�ȿ���һ��ռ�������ʱָ�����tmp�У�����newʧ�ܣ��ͻ��׳��쳣
		//	char* tmp = new char[strlen(s._str) + 1];
		//	delete[] _str;
		//	strcpy(tmp, s._str);
		//	_str = tmp;

		//	return *this;
		//}

		//�ִ�д���ĸ�ֵ����
		//tmp��Ϊ��ʱ����,tmp._str��_str����֮��_strԭ�ȵ����ݱ�tmp._strָ����
		//tmpһ�������������������ھͽ����ˣ�_strԭ�ȵĿռ�Ҳ��������
		//
		/*string& operator=(const string& s)
		{
			string tmp(s);
			swap(_str, tmp._str);
		}*/

		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}


		void reverse(size_t capacity)
		{
			if (_capacity < capacity)
			{
				_str = new char[2 * capacity];
			}
			
		}
		//β��һ���ַ�
		void push_back(char ch)
		{
			if (_size + 1 >= _capacity)
			{
				reverse(2 * _capacity);
			}
			_str[_size] = ch;
			_size++;
			_capacity *= 2;
		}
		//β��һ���ַ���
		void append(char* str)
		{
			if (_size + strlen(str) + 1 >= _capacity)
			{
				reverse(strlen(str) + 1);
			}
			strcpy(_str + _size, str);
			_size += strlen(str) + 1;
			_capacity += strlen(str) + 1;
		}


		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;            //��ǰ��ŵ���Ч���ݵĸ���
		size_t _capacity;        //��ǰ�ܹ���ŵ���Ч���ݵĸ���
	};

	void TestString()
	{
		char ch1[] = "hello";
		char ch2[] = "world";
		string s1(ch1);
		s1.push_back(' ');
		s1.append(ch2);
	}
}