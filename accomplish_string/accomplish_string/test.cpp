#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

//int main()
//{
//	zsj::TestString8();
//
//	
//}

int main()
{
	std::string s1("hello world");
	std::string s2(s1);

	//����Ŀ���������õĲ������ü���+дʱ��������
	printf("%p\n", s1.c_str());
	printf("%p\n", s2.c_str());
}
