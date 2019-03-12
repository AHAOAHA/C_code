#include"main.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int __stdcall wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd)
{
	static TCHAR szClassName[] = TEXT("AHAOAHA");//��������
	HWND hwnd;//���ھ��
	MSG msg;//��Ϣ
	WNDCLASS wndclass;//������

	//1.ע�ᴰ����
	wndclass.style = CS_HREDRAW | CS_VREDRAW;//���ڷ��
	wndclass.lpfnWndProc = WndProc;//���ڴ������
	wndclass.cbWndExtra = 0;
	wndclass.cbClsExtra = 0;
	wndclass.hInstance = hInstance;//��ǰ���ھ��
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//����ͼ��
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//�����ʽ
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //���ڱ�����ˢ
	wndclass.lpszMenuName = NULL;  //���ڲ˵�
	wndclass.lpszClassName = szClassName;  //��������
	
	RegisterClass(&wndclass);

	//2. �������ڲ���ʾ
	hwnd = CreateWindow(
		szClassName,  //�����������
		TEXT("AHAOAHA"),  //���ڱ��⣨�����ڱ�������
		WS_OVERLAPPEDWINDOW,  //���ڷ��
		CW_USEDEFAULT,  //��ʼ��ʱx���λ��
		CW_USEDEFAULT,  //��ʼ��ʱy���λ��
		500,  //���ڿ��
		300,  //���ڸ߶�
		NULL,  //�����ھ��
		NULL,  //���ڲ˵����
		hInstance,  //��ǰ���ڵľ��
		NULL  //��ʹ�ø�ֵ
	);

	ShowWindow(hwnd, nShowCmd);//��ʾ����

	UpdateWindow(hwnd);//���´���

	//3. ��Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//������Ϣ
		DispatchMessage(&msg);//������Ϣ
	}

	return msg.wParam;

	return 0;
}


//4. ���ڹ���

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;//�豸�������
	PAINTSTRUCT ps;
	RECT rect;
	HWND hStatic;

	switch (message)
	{
		//���ڻ�����Ϣ
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
		hStatic = CreateWindow(L"ѹ��"
			, L"��ѹ��"
			,WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | WS_BORDER /*���߿�*/ | SS_CENTER /*ˮƽ����*/ | SS_CENTERIMAGE /*��ֱ����*/
			,20 /*X����*/, 20 /*Y����*/, 200 /*���*/, 100 /*�߶�*/,
			hwnd,  //�����ھ��
			(HMENU)1//Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
			,  //��ǰ����ʵ�����
			,NULL);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}