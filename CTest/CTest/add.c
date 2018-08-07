#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int last = 0;
	long int s = 0;
	long int a = 0;
	long int sum = 0;//用sum存储最后的结果
	int count = 0;//count记录循环的次数
	scanf("%ld", &s);//获取要操作的数
	a = s;//为了不改变s的值，用a来代替s
	while (a > 0)
	{
		last = (a / 10) % 10;//获取当前最近的偶数位数字
		a = a / 100;//丢弃已经取到的位置
		sum = last * (int)pow(10,count) + sum;
		count++;
	}
	printf("%ld\n", sum);
	system("pause");
	return 0;
}
#endif

/*
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100] = {0};
	char str2[100] = {0};
	char* str = NULL;
	gets(str1);
	gets(str2);
	str = strstr(str1, str2);
	if (NULL == str)
	{
		printf("无匹配字符串");
	}
	else
	{
		printf("%d\n", str - str1);
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int INT = 2;
	if (2)
	{
		printf("haha");
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdio.h>
#include<conio.h>
void draw(int n)
{
	int i, j, k, r, m;
	for (i = 1; i = n; i++)
	{
		for (j = 1; j = 2; j++)
		{
			for (r = 1; r=i; r++)printf('W');
			printf('W');
			for (k = 1; k = 2; k++)printf('W');
			printf('W');
			for (m = 1; m=i; m++)printf('W');
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	clrscr();
	printf("inout a number:");
	scanf("%d", &n);
	draw(n);
	return 0;
}
*/
/*
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int i, j, m, s, k, a[100];//我猜a[100]是用来记录完数的
	k = 0;
	for (i = 1; i <= 1000; i++)
	{
		m = i; s = 0;//m表示1-1000的每个数字 k是数组的下标也是完数的个数 s是判断条件
		for (j = 1; j < m; j++)//j<m是因为i的因子不能大于i 
		{
			if (m%j == 0)//m这里代表i 也就是查看j是不是m的因子
			{
				s += j;//如果是就把他加在s上
			}
		}
			if (s != 0 && s == m)//如果满足这个条件就说名s/m/i(同一个数字)是完数
			{
				a[k++] = s;//把满足条件的值放进数组
			}
	}
	for (j = 0; j < k; j++)//这个循环用来打印所求的完数
	{
		printf("%d\n", a[j]);
	}
	system("pause");
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a_opp, b_opp, c_opp;//假设a_opp是a的对手，b_opp是b的对手，c_opp是c的对手
	for (a_opp = 'x'; a_opp <= 'z'; a_opp++)//假设三个人都有可能是a的对手
	{
		for (b_opp = 'x'; b_opp <= 'z'; b_opp++)//假设三个人也有都可能是b的对手
		{
			if (a_opp != b_opp)//每个人的对手不能相同 排除a和b对手相同的情况
			{
				for (c_opp = 'x'; c_opp <= 'z'; c_opp++)//假设三个人都有可能是c的对手
				{
					if (c_opp != a_opp&&c_opp != b_opp)//排出c的对手与a和b的对手相同的情况
					{
						if ((c_opp != 'x'&&c_opp != 'z')&&a_opp != 'x')//c的对手不会是x和z a的对手不会是x
							printf("a_opp = %c , b_opp = %c , c_opp = %c\n", a_opp, b_opp, c_opp);
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//#define min(x,y) ((x)<(y)?(x):(y))//因为我包含的头文件里以经定义过这个了 所以这里不用写
int min_distance(int x[], int y[], int m, int n)
{
	int minnum = INT_MAX;//先将minnum设置为int类型可表示的最大数字
	int index_x = 0, index_y = 0;//index_x为数组x的下标 index_y为数组y的下标

	//因为要求任意两个值相减的最小值  所以我们就把所有的值都减一遍 找出最小的结果即可
	//先用x数组里的第一个值 跟y数组里面所有的值都减一遍 正着减一遍 反着减一遍 
	//如果剪下来的值小于minnum 就用剪下来的数更新minnum
	//当x数组里最后一个数与y数组里最后一个数相减时 minnum里面就是所求的最小值了
	for (index_x = 0; index_x < m; index_x++)
	{
		for (index_y = 0; index_y < n; index_y++)
		{
			minnum = min(minnum, x[index_x] - y[index_y]);
			minnum = min(minnum, y[index_y] - x[index_x]);
		}
	}
	return minnum;
}
int main()
{
	int x[] = { 1, 3, 7, 11, 18 };
	int m = sizeof(x) / sizeof(int);//m代表x数组内元素的个数
	int y[] = { 4, 5, 8, 13, 22 };
	int n = sizeof(y) / sizeof(int);//n代表y数组内元素的个数
	int minnum = min_distance(x, y, m, n);//用minnum接收这两个数组中任意一个值相减的最小值
	printf("%d\n", minnum);
	system("pause");
	return 0;
}
*/


/*
#include<stdio.h>
#include<stdlib.h>
long int fun(long int num)
{
	int num_10 = 1;
	int count = 0;
	int last = 0;//用last保存长整型最后一位的数值
	int ret = 0;//用ret来保存最后得到的数值
	while (num > 0)//当num不大于0时跳出循环 就说明已经把长整型的每一个奇数位都遍历完了
	{
		last = num % 10;// %10 可以计算出任何一个整数的个位数字 用last记下来
		num = num / 100;//然后让长整型的小数点向前挪动两位 因为奇数位我们已经保存 而偶数位我们并不需要
		while (count!=0)//先看是第几次循环 我们就可以确定下面得到的个位要做个位十位还是百位
		{
			num_10 = num_10 * 10;//如果count==0 就说明做个位 num_10就=1  count=1 说明做十位 num_10就=10
			count--;
		}
		ret = last*num_10 + ret;
		count++;
	}
	return ret;
}
int main()
{ //我没有定义t 我直接然函数返回所得到的值并把它打印出来
	long int num = 0;//初始化要计算的长整型
	printf("输入长整型数字：");
	scanf("%ld", &num);//输入长整型 我输入1234
	printf("%d\n", fun(num));//直接打印fun（num）函数的返回值
	system("pause");
	return 0;
}
*/



/*
#include<stdio.h>
int fun(int w)
{
	int last = 0;//用来保存个位
	int sum = 0;//用来保存每个位的平方之和
	do
	{
		last = w % 10;//求出w当前的个位数字 用last保存起来
		w = w / 10;//让w的小数点向前挪动一位
		sum = sum + last*last;//计算每一位的平方和 
	} while (w > 0);//当w不大于0时说明已经遍历w的每一位 就跳出循环
	
	if (sum % 5 == 0)//如果sum可以被5整除 就返回1
		return 1;
	return 0;//否则返回0
}
int main()
{
	int w = 0;
	printf("w = ");
	scanf("%d", &w);
	return 0;
}
*/


/*
#include<stdio.h>
void fun(int array[], int n)
{
	int i = 0;//外层循环变量
	int j = 0;
	for (i = 0; i < n-1; i++)//让i从0开始 一直到最后一位的前一位结束
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j]>array[j+1])//检查目前的这位数字与下一位数字大小
			{//如果前面的大于后面的 就把他们的位置交换 否则继续检测下一位  当检测到末尾的前一位时 末尾已经参与比较 
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int a[10], i;
	printf("输入10个数：");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	fun(a, 10);
	printf("结果：");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
*/

/*
#include<stdlib.h>
#include<stdio.h>
void fun(int tt[3][4], int pp[])
{
	int i = 0;
	int j = 0;
	int maxnum = INT_MIN;//先将maxnum标记为int表示的最小值 可以确保maxnum保存的数肯定是二维数组里面的数字
	for (i = 0; i < 3; i++)//控制行 先进行第一列内的比较
	{
		for (j = 0; j < 4; j++)//进行第一行内的比较
		{
			if (maxnum < tt[i][j])//找出第一行内最大的数字
				maxnum = tt[i][j];
		}//当跳出这个循环时 max保存的是第i行 最大的数字
		pp[i] = maxnum;//把这个数字用数字保存起来
		maxnum = INT_MIN;//将maxnum更新为int可表示的最小数字 进行下一次比较
	}
}

int main()
{
	int i = 0;
	int a[3][4] = { { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 5, 6, 7, 8 } };
	int pp[] = { 0 };
	fun(a, pp);
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", pp[i]);
	}
	system("pause");
	return 0;
}
*/
/*
#include<stdlib.h>
int main()
{
	for (int i = 1; i == 0; i++)
	{
		printf("hahah ");
	}
	system("pause");
	return 0;
}
*/

/*
double fun(int n)
{
	int i = 0;//i做循环变量
	double sum = 0;//保存最后的结果
	double first_m = 1;//第一个数字的分母
	double first_z = 2;//第一个数字的分子
	double second_m = 2;//第二个数字的分母
	double second_z = 3;//第二个数字的分子
	double third_m = 0;//第三个数字的分母
	double third_z = 0;//第三个数字的分子
	for (i = 0; i < n; i++)
	{
		if (i == 0)//如果i==0 说明函数第一次循环  这是只用加到第一个数字
		{
			sum = first_z / first_m;
		}
		else if (i == 1)//日过i==1说明循环第二次  这时就要加到第二个数字
		{
			sum = sum + second_z / second_m;
		}
		else
		{
			third_z = first_z + second_z;//用第一个和第二个数字的分母和分子计算出第三个数字的分母和分子
			third_m = first_m + second_m;

			first_m = second_m;//让第一个数字的分母和分子向后挪动一位  为下一次计算做好准备
			first_z = second_z;

			second_m = third_m;//让第二个数字向后挪动一位  为下一次计算做好准备
			second_z = third_z;

			sum = third_z / third_m + sum;
		}

		
	}
	//跳出循环时 就代表已经计算完成
	return sum;

}
int main()
{
	double ret = 0;
	int n = 0;
	printf("n=");
	scanf("%d", &n);
	ret = fun(n);
	printf("%f\n", ret);
	system("pause");
	return 0;
}
*/


/*

void fun(int array_1[3][3], int arrat_t[3][3])
{
	int i = 0;
	int j = 0;
	int temp[3][3];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
		}
	}
}
int main()
{
	int array_1[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int array_t[3][3];
	fun(array_1, array_t);
	system("pause");
	return 0;
}
*/
/*
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR line, int cmd)
{
	static TCHAR AppName[] = TEXT("99");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hinstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = AppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), AppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(AppName, TEXT("AHAOAHA_"), \
		WS_OVERLAPPEDWINDOW, \
		CW_USEDEFAULT, \
		CW_USEDEFAULT, \
		CW_USEDEFAULT, \
		CW_USEDEFAULT, \
		NULL, \
		NULL, \
		hinstance, \
		NULL);

	ShowWindow(hwnd, cmd);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	static x, y;
	int i, j;
	int len;
	TCHAR buf[50];
	TEXTMETRIC tm;

	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		x = tm.tmAveCharWidth;
		y = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hdc);
		//MessageBox(NULL,TEXT("Create Successed!"),TEXT("Successed"),MB_OK);
		//PlaySound(TEXT("hello.wav"),NULL,SND_FILENAME|SND_ASYNC);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		//DrawText(hdc,TEXT("Hello World!"),-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		//TextOut(hdc,rect.right/2-(strlen("Hello World!")/2)*x,rect.bottom/2-y/2,TEXT("Hello World!"),12);
		for (i = 1; i != 10; ++i)
		{
			for (j = 1; j != i + 1; ++j)
			{
				len = wsprintf(buf, TEXT("%dx%d=%-4d"), j, i, i*j);
				TextOut(hdc, j*len*x, i*y, buf, len);
			}
		}

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wparam, lparam);
}
*/
//#include<stdio.h>
//#include<stdlib.h>
//void Quicksort(int left, int right, int x[])
//{
//	int i = left;
//	int j = right;
//	int key = x[left];
//	if (left >= right)
//		return;
//
//	while (i<j)
//	{
//		while (i<j&&x[j] >= key)
//		{
//			j--;
//		}
//		x[i] = x[j];
//		while (i<j&&x[i]<key)
//		{
//			i++;
//		}
//		x[j] = x[i];
//	}
//	x[j] = key;
//
//	Quicksort(left, j - 1, x);
//	Quicksort(j + 1, right, x);
//}
//int main()
//{
//	int n;
//	int x[1000];
//	scanf("%d", &n);
//	while (n)
//	{
//		int i;
//		for (i = 1; i <= n; i++)
//		{
//			printf("%d", x[i]);
//		}
//		Quicksort(1, n, x);
//		for (i = 1; i <= n; i++)
//		{
//			printf("%d ", x[i]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//#include<stdlib.h>
//int QuickSort(int array[], int size/*数组的大小*/)
//{
//	int left = 0;
//	int right = size - 1;
//	int max = INT_MIN;
//	int min = INT_MAX;
//	
//}



#include<stdlib.h>
int main()
{
	char* p = "a";
	free(p);
	return 0;
}
