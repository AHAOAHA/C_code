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
	long int sum = 0;//��sum�洢���Ľ��
	int count = 0;//count��¼ѭ���Ĵ���
	scanf("%ld", &s);//��ȡҪ��������
	a = s;//Ϊ�˲��ı�s��ֵ����a������s
	while (a > 0)
	{
		last = (a / 10) % 10;//��ȡ��ǰ�����ż��λ����
		a = a / 100;//�����Ѿ�ȡ����λ��
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
		printf("��ƥ���ַ���");
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
	int i, j, m, s, k, a[100];//�Ҳ�a[100]��������¼������
	k = 0;
	for (i = 1; i <= 1000; i++)
	{
		m = i; s = 0;//m��ʾ1-1000��ÿ������ k��������±�Ҳ�������ĸ��� s���ж�����
		for (j = 1; j < m; j++)//j<m����Ϊi�����Ӳ��ܴ���i 
		{
			if (m%j == 0)//m�������i Ҳ���ǲ鿴j�ǲ���m������
			{
				s += j;//����ǾͰ�������s��
			}
		}
			if (s != 0 && s == m)//����������������˵��s/m/i(ͬһ������)������
			{
				a[k++] = s;//������������ֵ�Ž�����
			}
	}
	for (j = 0; j < k; j++)//���ѭ��������ӡ���������
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
	char a_opp, b_opp, c_opp;//����a_opp��a�Ķ��֣�b_opp��b�Ķ��֣�c_opp��c�Ķ���
	for (a_opp = 'x'; a_opp <= 'z'; a_opp++)//���������˶��п�����a�Ķ���
	{
		for (b_opp = 'x'; b_opp <= 'z'; b_opp++)//����������Ҳ�ж�������b�Ķ���
		{
			if (a_opp != b_opp)//ÿ���˵Ķ��ֲ�����ͬ �ų�a��b������ͬ�����
			{
				for (c_opp = 'x'; c_opp <= 'z'; c_opp++)//���������˶��п�����c�Ķ���
				{
					if (c_opp != a_opp&&c_opp != b_opp)//�ų�c�Ķ�����a��b�Ķ�����ͬ�����
					{
						if ((c_opp != 'x'&&c_opp != 'z')&&a_opp != 'x')//c�Ķ��ֲ�����x��z a�Ķ��ֲ�����x
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
//#define min(x,y) ((x)<(y)?(x):(y))//��Ϊ�Ұ�����ͷ�ļ����Ծ����������� �������ﲻ��д
int min_distance(int x[], int y[], int m, int n)
{
	int minnum = INT_MAX;//�Ƚ�minnum����Ϊint���Ϳɱ�ʾ���������
	int index_x = 0, index_y = 0;//index_xΪ����x���±� index_yΪ����y���±�

	//��ΪҪ����������ֵ�������Сֵ  �������ǾͰ����е�ֵ����һ�� �ҳ���С�Ľ������
	//����x������ĵ�һ��ֵ ��y�����������е�ֵ����һ�� ���ż�һ�� ���ż�һ�� 
	//�����������ֵС��minnum ���ü�������������minnum
	//��x���������һ������y���������һ�������ʱ minnum��������������Сֵ��
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
	int m = sizeof(x) / sizeof(int);//m����x������Ԫ�صĸ���
	int y[] = { 4, 5, 8, 13, 22 };
	int n = sizeof(y) / sizeof(int);//n����y������Ԫ�صĸ���
	int minnum = min_distance(x, y, m, n);//��minnum��������������������һ��ֵ�������Сֵ
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
	int last = 0;//��last���泤�������һλ����ֵ
	int ret = 0;//��ret���������õ�����ֵ
	while (num > 0)//��num������0ʱ����ѭ�� ��˵���Ѿ��ѳ����͵�ÿһ������λ����������
	{
		last = num % 10;// %10 ���Լ�����κ�һ�������ĸ�λ���� ��last������
		num = num / 100;//Ȼ���ó����͵�С������ǰŲ����λ ��Ϊ����λ�����Ѿ����� ��ż��λ���ǲ�����Ҫ
		while (count!=0)//�ȿ��ǵڼ���ѭ�� ���ǾͿ���ȷ������õ��ĸ�λҪ����λʮλ���ǰ�λ
		{
			num_10 = num_10 * 10;//���count==0 ��˵������λ num_10��=1  count=1 ˵����ʮλ num_10��=10
			count--;
		}
		ret = last*num_10 + ret;
		count++;
	}
	return ret;
}
int main()
{ //��û�ж���t ��ֱ��Ȼ�����������õ���ֵ��������ӡ����
	long int num = 0;//��ʼ��Ҫ����ĳ�����
	printf("���볤�������֣�");
	scanf("%ld", &num);//���볤���� ������1234
	printf("%d\n", fun(num));//ֱ�Ӵ�ӡfun��num�������ķ���ֵ
	system("pause");
	return 0;
}
*/



/*
#include<stdio.h>
int fun(int w)
{
	int last = 0;//���������λ
	int sum = 0;//��������ÿ��λ��ƽ��֮��
	do
	{
		last = w % 10;//���w��ǰ�ĸ�λ���� ��last��������
		w = w / 10;//��w��С������ǰŲ��һλ
		sum = sum + last*last;//����ÿһλ��ƽ���� 
	} while (w > 0);//��w������0ʱ˵���Ѿ�����w��ÿһλ ������ѭ��
	
	if (sum % 5 == 0)//���sum���Ա�5���� �ͷ���1
		return 1;
	return 0;//���򷵻�0
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
	int i = 0;//���ѭ������
	int j = 0;
	for (i = 0; i < n-1; i++)//��i��0��ʼ һֱ�����һλ��ǰһλ����
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j]>array[j+1])//���Ŀǰ����λ��������һλ���ִ�С
			{//���ǰ��Ĵ��ں���� �Ͱ����ǵ�λ�ý��� ������������һλ  ����⵽ĩβ��ǰһλʱ ĩβ�Ѿ�����Ƚ� 
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
	printf("����10������");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	fun(a, 10);
	printf("�����");
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
	int maxnum = INT_MIN;//�Ƚ�maxnum���Ϊint��ʾ����Сֵ ����ȷ��maxnum��������϶��Ƕ�ά�������������
	for (i = 0; i < 3; i++)//������ �Ƚ��е�һ���ڵıȽ�
	{
		for (j = 0; j < 4; j++)//���е�һ���ڵıȽ�
		{
			if (maxnum < tt[i][j])//�ҳ���һ������������
				maxnum = tt[i][j];
		}//���������ѭ��ʱ max������ǵ�i�� ��������
		pp[i] = maxnum;//��������������ֱ�������
		maxnum = INT_MIN;//��maxnum����Ϊint�ɱ�ʾ����С���� ������һ�αȽ�
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
	int i = 0;//i��ѭ������
	double sum = 0;//�������Ľ��
	double first_m = 1;//��һ�����ֵķ�ĸ
	double first_z = 2;//��һ�����ֵķ���
	double second_m = 2;//�ڶ������ֵķ�ĸ
	double second_z = 3;//�ڶ������ֵķ���
	double third_m = 0;//���������ֵķ�ĸ
	double third_z = 0;//���������ֵķ���
	for (i = 0; i < n; i++)
	{
		if (i == 0)//���i==0 ˵��������һ��ѭ��  ����ֻ�üӵ���һ������
		{
			sum = first_z / first_m;
		}
		else if (i == 1)//�չ�i==1˵��ѭ���ڶ���  ��ʱ��Ҫ�ӵ��ڶ�������
		{
			sum = sum + second_z / second_m;
		}
		else
		{
			third_z = first_z + second_z;//�õ�һ���͵ڶ������ֵķ�ĸ�ͷ��Ӽ�������������ֵķ�ĸ�ͷ���
			third_m = first_m + second_m;

			first_m = second_m;//�õ�һ�����ֵķ�ĸ�ͷ������Ų��һλ  Ϊ��һ�μ�������׼��
			first_z = second_z;

			second_m = third_m;//�õڶ����������Ų��һλ  Ϊ��һ�μ�������׼��
			second_z = third_z;

			sum = third_z / third_m + sum;
		}

		
	}
	//����ѭ��ʱ �ʹ����Ѿ��������
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
//int QuickSort(int array[], int size/*����Ĵ�С*/)
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
