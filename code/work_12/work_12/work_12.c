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
//		ret = value & 1;//����Ŀ����ֵ�����Ʊ���λ�����һλ
//		num_1 = num_1 + ret;//�����汣������һλ����num_1
//		num_1 <<= 1;//��ֵ֮��num_1����һλ����num_1���һλΪ0���ȴ�������һ�ε�ֵ
//		value >>= 1;//�����Ѿ�ʹ�ù��Ķ����Ʊ���λ�����һλ
//	}
//	return num_1;
//}
//int main()
//{
//	unsigned int num = 0;
//	unsigned int ret = 0;
//	printf("����һ�����֣�");
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