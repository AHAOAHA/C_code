#include"TelList.h"
int main()
{
	int n = 0;
	PTelList tellist;
	InitTelList(&tellist);
	while (1)
	{
		PrintPage();
		printf("ÇëÑ¡Ôñ¶ÔÓ¦ÐòºÅ£º");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			AddTelList(tellist + tellist->size);
			break;
		case 2:
			DelTelList(tellist);
			break;
		case 3://Search(tellist);
			break;
		case 4:
			
			break;
		case 5:
			PrintTelList(tellist);
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
