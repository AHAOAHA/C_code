#include"main.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int __stdcall wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd)
{
	static TCHAR szClassName[] = TEXT("AHAOAHA");//窗口类名
	HWND hwnd;//窗口句柄
	MSG msg;//消息
	WNDCLASS wndclass;//窗口类

	//1.注册窗口类
	wndclass.style = CS_HREDRAW | CS_VREDRAW;//窗口风格
	wndclass.lpfnWndProc = WndProc;//窗口处理过程
	wndclass.cbWndExtra = 0;
	wndclass.cbClsExtra = 0;
	wndclass.hInstance = hInstance;//当前窗口句柄
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//窗口图标
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//鼠标样式
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //窗口背景画刷
	wndclass.lpszMenuName = NULL;  //窗口菜单
	wndclass.lpszClassName = szClassName;  //窗口类名
	
	RegisterClass(&wndclass);

	//2. 创建窗口并显示
	hwnd = CreateWindow(
		szClassName,  //窗口类的名字
		TEXT("AHAOAHA"),  //窗口标题（出现在标题栏）
		WS_OVERLAPPEDWINDOW,  //窗口风格
		CW_USEDEFAULT,  //初始化时x轴的位置
		CW_USEDEFAULT,  //初始化时y轴的位置
		500,  //窗口宽度
		300,  //窗口高度
		NULL,  //父窗口句柄
		NULL,  //窗口菜单句柄
		hInstance,  //当前窗口的句柄
		NULL  //不使用该值
	);

	ShowWindow(hwnd, nShowCmd);//显示窗口

	UpdateWindow(hwnd);//更新窗口

	//3. 消息循环
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//翻译消息
		DispatchMessage(&msg);//分派消息
	}

	return msg.wParam;

	return 0;
}


//4. 窗口过程

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;//设备环境句柄
	PAINTSTRUCT ps;
	RECT rect;
	HWND hStatic;

	switch (message)
	{
		//窗口绘制消息
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, TEXT("hello"), -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		hStatic = CreateWindow(L"压缩"
			, L"解压缩"
			,WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | WS_BORDER /*带边框*/ | SS_CENTER /*水平居中*/ | SS_CENTERIMAGE /*垂直居中*/
			,20 /*X坐标*/, 20 /*Y坐标*/, 200 /*宽度*/, 100 /*高度*/,
			hwnd,  //父窗口句柄
			(HMENU)1//为控件指定一个唯一标识符
			,  //当前程序实例句柄
			,NULL);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}