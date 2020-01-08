#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>//实现可变参数列表时，必须使用此头文件
int Avarage(int n, ...)
{
	va_list arg;
	int i = 0;
	int sum = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg);
	return sum / n;
}
int main()
{
	int ret = 0;
	ret = Avarage(3, 3,3,9);
	printf("avarage = %d\n", ret);
	system("pause");
	return 0;
}




int Max(int n, ...)
{
	va_list arg;
	int i = 0;
	int max = 0;
	int tmp = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		tmp = max;
		max = va_arg(arg, int);
		if (tmp>max)
		{
			max = tmp;
		}
	}
	va_end(arg);
	return max;

}
int main()
{
	int max = 0;
	max = Max(5, 1, 2, 3, 4, 1);
	printf("MAX = %d\n", max);
	system("pause");
	return 0;
}


void Print(char *format, ...)
{
	int num = 0;
	char* str = NULL;
	va_list arg;
	va_start(arg, format);
	str = va_arg(arg, char*);
	while (*format != '\0')
	{
		switch (*format)
		{
		case 's'://puts(str);//puts函数会默认将字符串末尾的'\0'转换为'\n'	
			fputs(str, stdout);
			str = arg;
			va_arg(arg, char*);
			break;
		case 'c':putchar(*str);
			str = arg;
			va_arg(arg, char*);
			break;
		case 'd': //num = (int)(*str);
			//putchar('num');
			printf("100");
			str = arg;
			va_arg(arg, char*);
			break;
		case 92:
			switch (*format)
			{
			case 'n':putchar('\n');
				break;
			default:
				putchar(92);
				break;
			}
			break;
		default:putchar(*format);
			break;
			}
			format++;		
	}
	va_end(arg);
}
int main()
{
	Print("s ccc d.\n","hello",  'b', 'i', 't', 100);
	system("pause");
	return 0;
}

