#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

//int main()
//{
//	Date d1(2021, 2, 29);
//	//d1 += 100;//d1.operator+=(100)
//	//d1.Print();
//
//	Date d2(2021, 10, 14);
//	Date ret = d2 + 100;//øΩ±¥ππ‘Ï
//	ret.Print();
//	//d2.Print();
//
//	ret -= 100;
//	ret.Print();
//
//	
//	return 0;
//}

void Testoperatior1()
{
	Date d1(2012, 4, 13);
	Date ret = d1 - 24;
	ret.Print();
	d1.Print();//2012-4-13
}
void Test2()
{
	Date d1(2031, 3, 28);
	++d1;
	d1.Print();//3-29

	Date ret = d1++;//3-29
	ret.Print();
	d1.Print();
}

void Test3()
{
	Date d1(2021, 10, 14);
	Date d2(2022, 1, 1);
	Date d3(2022, 3, 1);

	
	cout << d2 - d1 << endl;
}
int main()
{
	//Testoperatior1();
	//Test2();
	Test3();
	return 0;
}

