#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    int carry = 0;//��λ
    string retstr;
    //ѭ����ֹ�����������е�һ���ַ����ߵ���β
    //num1 = 11 num2 = 123
    while (end1 >= 0 || end2 >= 0)
    {
        //�������ַ�ת��������
        int val1 = 0, val2 = 0;
        if (end1 >= 0)
        {
            val1 = num1[end1] - '0';//'9' - '0' --> 57 - 48 = 9
            --end1;
        }

        if (end2 >= 0)
        {
            val2 = num2[end2] - '0';
            --end2;
        }
        //���мӷ�����
        int sum = val1 + val2 + carry;
        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;//û����10�������λ
        }

        //retstr.insert(0, 1, sum + '0');//�����ͷ��O(N)��ʱ�临�Ӷ�Ӳ���������O(N^2)
        retstr += sum + '0';
    }

    if (carry == 1)
    {
        retstr += 1 + '0';
    }

    reverse(retstr.begin(), retstr.end());//����ҿ�
    return retstr;
}

//int main()
//{
//    string s1 = "1";
//    string s2 = "9";
//   
//    cout << addStrings(s1, s2);
//}

int main()
{
    int i = 234;
    string s1 = to_string(i);
    cout << s1 << endl;
    int a = stoi(s1);
    cout << a << endl;
    return 0;
}