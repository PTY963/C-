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
//	//i是从0开始，所以结束的下标是n-2
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
//冒泡排序属于交换排序
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

//直接插入排序和冒泡排序最好的情况下的时间复杂度都是O(N)
// 1 2 3 4 5 6 7 - 有序
// 1 2 3 4 5 8 7 - 接近有序
//但在接近有序的情况下，直接插入排序的比较次数更少一些
int PartSort(int* a, int left, int right)
{
	int key = left;//key如果不是下标的话，最后一步的交换就成了赋值了

	while (left < right)
	{
		//right指针先走
		//必须要加上=
		//1、如果不加等于，key就会被换走
		//2、如果数组有多个与key相等的值，会陷入死循环
		while (a[right] >= a[key] && left < right)
		{
			--right;
		}
		//left再走
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
	//left>=right - 子区间一个元素都没有或者只剩一个元素
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
//必须让right先走，这才能保证left和right相遇点比key值小
//1、left遇right - right是找小，right停下来的位置一定是小于key的值的
//2、right遇left - right遇left，一定是交换过后，right找小的时候遇见的
//交换过后，left一定是小值

//同样的道理，如果选右边的值做key，必须要让left先走

//如果是排降序 让left找小，right找大

