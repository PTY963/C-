#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//����ģ��
template<class T>
void Swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;

}

//int main()
//{
//	int a = 10, b = 20;
//	double c = 16.3, d = 20.5;
//	Swap(a, b);
//	Swap(c, d);
//}

//��ģ��
template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_a(new T[capacity])
		,_top(0)
		,_capacity(0)
	{}

	void Push(const T& x);
	

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	T* _a;
	int _top;
	int _capacity;
};

//��ģ������ - �����涨��
template<class T>
void Stack<T>::Push(const T& x)
{

}
//int main()
//{
//	//��ģ�������ʾʵ����
//	Stack<int> s1;
//	return 0;
//}


//����ģ��ʵ������1��ͨ��ʵ���������βε����� 2��ʵ�������ɾ��庯��
//template<class T>
//void Func(int x)
//{
//	T a(x);//���ù��캯��
//}
//
//
//int main()
//{
//	Func<int>(10);
//	return 0;
//}

//int main()
//{
//	char arr[] = "֣��";
//	//cout << arr << endl;
//
//	arr[0] = -65;
//	cout << arr << endl;
//	return 0;
//}

#include <string>

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3("֣��");
//	string s4(16, 'a');
//	string s5(s2);
//
//	/*cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;*/
//
//	//string��������[]
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		cout << s2[i] << ' ';
//	}
//	cout << endl;
//
//	for (auto& e : s2)//����ȡs2�е�Ԫ�ؿ�����e��
//	{
//		e += 1;
//	}
//	for (auto e : s2)
//	{
//		cout << e;
//	}
//	cout << endl;
//	
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	s1.push_back('+');//β��һ���ַ�
//	s1.append("world");//����һ���ַ���
//
//	//���ǣ����Ƽ������ +=
//	s1 += '!';
//	s1 += "��˼��";
//
//	cout << s1 << endl;
//	return 0;
//}

class Weight
{
public:
	Weight(){}
	Weight(const Weight& w)
	{
		cout << "�����˿�������";
	}

};

Weight func()
{
	Weight W;
	return W;//����һ����ʱ���� - ������һ�ο�������
}
//�����˼��ο������죿- �����������ο������� ���Ǳ������������Ż�
int main()
{
	Weight ret = func();//һ�ο�������
	
	return 0;
}


