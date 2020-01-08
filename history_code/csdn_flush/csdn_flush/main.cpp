#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	while (1)
	{
		system("start https://blog.csdn.net/h___q/article/details/82108238");
		Sleep(1000);
		system("taskkill /f /im chrome.exe");
	}
	return 0;
}