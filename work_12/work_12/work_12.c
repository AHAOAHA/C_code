#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	unsigned int ret = 0;
//	unsigned int num_1 = 0;
//	for (i = 0; i < 31; i++)
//	{
//		ret = value & 1;//保存目标数值二进制比特位的最后一位
//		num_1 = num_1 + ret;//将上面保存的最后一位赋给num_1
//		num_1 <<= 1;//赋值之后将num_1左移一位，让num_1最后一位为0，等待接收下一次的值
//		value >>= 1;//丢弃已经使用过的二进制比特位的最后一位
//	}
//	return num_1;
//}
//int main()
//{
//	unsigned int num = 0;
//	unsigned int ret = 0;
//	printf("输入一个数字：");
//	scanf("%u", &num);
//	ret = reverse_bit(num);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 5;
//	int b = 3;
//	int num = 0;
//	num = a + (a-b)>>1;
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		ret ^= arr[i];
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
int main()
{
	char arr[] = "student a am i";
	int sz = strlen(arr);
	int tmp = 0;
	int i = 0;
	int left = 0;
	int right = 0;
	char *p = NULL;
	p = arr;
	int count = 0;
	for (i = 0; i < sz / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[sz - i - 1];
		arr[sz - i - 1] = tmp;
	}
	while ('\0' != *p)
	{
		p += 1;
		count++;
		if (*p == ' '||*p=='\0')
		{
			right = count - 1;
			if (right == left)
			{
				left = count + 1;
			}
			else
			{
				while (right>left)
				{
					tmp = arr[right];
					arr[right] = arr[left];
					arr[left] = tmp;
					left++;
					right--;
				}
				left = count + 1;
			}
		}
	}
	printf("%s\n", arr);
	system("pause");
	return 0;
}