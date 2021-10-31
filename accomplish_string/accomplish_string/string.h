#pragma once
#include <iostream>
#include <string>
#include <assert.h>
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
		typedef char* interator;
		typedef const char* const_interator;
		interator begin()
		{
			return _str;
		}
		interator end()
		{
			return _str + _size;
		}

		const_interator begin() const
		{
			return _str;
		}
		const_interator end() const
		{
			return _str + _size;
		}

		//���캯��
		string(const char* str =(char*) "") 
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		
		string(const string& s)
		{
			string tmp(s._str);
			swap(tmp);
		}

		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		
		//���ݣ���ԭ�ȵĻ���������
		void reverse(size_t capacity)
		{
			if (capacity > _capacity)
			{
				char* tmp = new char[capacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = capacity;
			}
		}

		
		//β��һ���ַ�
		/*void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reverse(newcapacity);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}*/
		//β��һ���ַ���
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reverse(_size + len);
			}
			strcpy(_str, str);
			_size +=len;
		}
		//s2.swap(s1)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		void operator+=(char ch)
		{
			push_back(ch);
		}
		void operator+=(char* str)
		{
			append(str);
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		//�޸�size����ʼ��
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reverse(n);
				}

				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}

				_size = n;
				_str[_size] = '\0';
			}
		}
		//����size
		size_t size() const
		{
			return _size;
		}
		//��ӡ
		void print(const string& str)
		{
			for (size_t i = 0; i < str.size(); ++i)
			{
				cout << str[i] << ' ';
			}
			cout << endl;

			const_interator it = str.begin();
			while (it != str.end())
			{
				cout << *it << ' ';
				++it;
			}
		}
		//����һ���ַ�
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reverse(newcapacity);
			}

			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/
			//-1 
			int end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;

		}
		//����һ���ַ���
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reverse(len + _size);
			}

			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}

			for (size_t i = 0; i < len; ++i)
			{
				_str[pos + i] = str[i];
			}
		}
		//ɾ���ַ����������
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);// = ������
			if (len == npos || pos + len >= _size)
			{
				//1��posλ�ú�����ַ�ȫ��ɾ��
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				//2��posλ�ú��������ɾ��һ����
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}
		void push_back(char ch)
		{
			insert(_size, ch);
		}
		
		char* C_str() const
		{
			return _str;
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

		static size_t npos;
	};

//��̬��Ա������ȫ��λ�ö����ʼ��
size_t string::npos = -1;

ostream& operator<<(ostream& out, const string& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i];
	}

	return out;
}

istream& operator>>(istream& in, string& s)
{
	char ch;
	//in >> ch;
	ch = in.get();
	while (ch != ' ' && ch != '\n')
	{
		s += ch;
		//in >> ch;
		ch = in.get();
	}

	return in;
}
	void TestString1()
	{
		char ch1[] = "hello";
		string s1(ch1);

		s1 += ' ';
		char ch2[] = "world";
		s1 += ch2;
	}

	void TestString2()
	{
		string s1;
		s1 += 'y';
		s1.resize(5, 'x');
	}

	void Teststring3()
	{
		//���� ���
		char ch[] = "hello world";
		string s1(ch);

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << ' ';
		}
		cout << endl;

		string::interator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		s1.print(s1);

	}

	void TestString4()
	{
		char ch[] = "hello";
		string s1(ch);
		s1.insert(1, 'x');
		cout << s1.C_str() << endl;

		s1.insert(0, 'z');
	}

	void TestString5()
	{
		char ch[] = "helloworld";
		string s1(ch);
		s1.insert(5, "bit");
		cout << s1.C_str() << endl;
	}

	void TestString6()
	{
		char ch[] = "helloworld";
		string s1(ch);
		s1.erase(5, 3);
		cout << s1.C_str() << endl;
	}

	void TestString7()
	{
		
		string s1("hello world");
		//cin >> s1;
		cout << s1 << endl;
		cout << s1.C_str() << endl;

		cout << "-------------------------------" << endl;

		string s2("hello world");
		s2.resize(20);
		s2[19] = 'x';

		cout << s2 << endl;
		cout << s2.C_str() << endl;
		cout << "-------------------------------" << endl;

		string s3;
		cin >> s3;
		cout << s3;


	
	}
}



