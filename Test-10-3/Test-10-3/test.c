#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//void BubbleSort(int* a, int n)
//{
//	//i�Ǵ�0��ʼ�����Խ������±���n-2
//	for (int i = 0; i < n - 1; ++i)
//	{
//      int flag = 0;
//		for (int j = 0; j < n - 1 - i; ++j)
//		{
//			if (a[j] > a[j + 1])
//			{
//				Swap(&a[j], &a[j + 1]);
//				flag = 1;
//			}
//		}
//
//		if (flag == 0)
//		{
//			return;
//		}
//	}
//}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange = 0)
		{
			return;
		}
	}
	
}
//ð���������ڽ�������
void TestBubbleSort()
{
	int arr[] = { 23, 19, 25, 32, 1, 48, 12, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	Print(arr, size);
}

//int main()
//{
//	TestBubbleSort();
//	return 0;
//}

//ֱ�Ӳ��������ð��������õ�����µ�ʱ�临�Ӷȶ���O(N)
// 1 2 3 4 5 6 7 - ����
// 1 2 3 4 5 8 7 - �ӽ�����
//���ڽӽ����������£�ֱ�Ӳ�������ıȽϴ�������һЩ
int PartSort(int* a, int left, int right)
{
	int key = left;//key��������±�Ļ������һ���Ľ����ͳ��˸�ֵ��

	while (left < right)
	{
		//rightָ������
		//����Ҫ����=
		//1��������ӵ��ڣ�key�ͻᱻ����
		//2����������ж����key��ȵ�ֵ����������ѭ��
		while (a[right] >= a[key] && left < right)
		{
			--right;
		}
		//left����
		while (a[left] <= a[key] && left < right)
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[key], &a[right]);
	return right;
}
void QuickSort(int* a, int left, int right)
{
	//left>=right - ������һ��Ԫ�ض�û�л���ֻʣһ��Ԫ��
	if (left >= right)
	{
		return;
	}

	int keyi = PartSort(a, left, right);
	//[left keyi - 1] keyi [keyi + 1 right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}
//������right���ߣ�����ܱ�֤left��right�������keyֵС
//1��left��right - right����С��rightͣ������λ��һ����С��key��ֵ��
//2��right��left - right��left��һ���ǽ�������right��С��ʱ��������
//��������leftһ����Сֵ

//ͬ���ĵ������ѡ�ұߵ�ֵ��key������Ҫ��left����

//������Ž��� ��left��С��right�Ҵ�

