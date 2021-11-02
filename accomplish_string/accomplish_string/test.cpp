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

	//库里的拷贝构造采用的不是引用计数+写时拷贝技术
	printf("%p\n", s1.c_str());
	printf("%p\n", s2.c_str());
}
