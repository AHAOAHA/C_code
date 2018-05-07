#include"AddressList.h"
int Size = 1000;
//��ʼ��
void AddressListInit(PLinkManNode* PAddressList)
{
	PLinkManNode PList = NULL;
	assert(PAddressList);
	PList = (PLinkManNode)malloc(sizeof(LinkManNode)* MAXSIZE);
	if (NULL == PList)
	{
		assert(0);
		return;
	}
	*PAddressList = PList;
}
void InputLinkMan(PLinkManNode AddressList)
{
	printf("NAME:");
	scanf("%s", &(AddressList+(MAXSIZE-Size))->_name);
	printf("AGE:");
	scanf("%d", &(AddressList + (MAXSIZE - Size))->_age);
	printf("SEX:0.MAN,1.WOMAN,2.SECERT");
	scanf("%d", &(AddressList + (MAXSIZE - Size))->Sex);
	printf("TEL:");
	scanf("%lld", &(AddressList + (MAXSIZE - Size))->_Tel);
	printf("ADDRESS:");
	scanf("%s", &(AddressList + (MAXSIZE - Size))->_address);
}
//�����ϵ��
void AddressListPush(PLinkManNode* PAddressList)
{
	assert(PAddressList);
	if (NULL == *PAddressList)
		return;
	if (Size <= 0)
	{
		printf("�洢�ռ䲻��\n");
		return;
	}
	InputLinkMan(*PAddressList);
	((*PAddressList) + (MAXSIZE - Size))->_order = MAXSIZE - Size + 1;
	Size--;
}
//ɾ����ϵ��
void CoverLinkMan(PLinkManNode AddressList, int order)
{
	while (order <= (MAXSIZE - Size - 1))
	{
		strcpy((AddressList + order - 1)->_name, (AddressList + order)->_name);
		strcpy((AddressList + order - 1)->_address, (AddressList + order)->_address);
		(AddressList + order - 1)->_age = (AddressList + order)->_age;
		(AddressList + order - 1)->Sex = (AddressList + order)->Sex;
		(AddressList + order - 1)->_Tel = (AddressList + order)->_Tel;
		order++;
	}
}
void DeleteLinkMan(PLinkManNode* PAddressList,int order)
{
	assert(PAddressList);
	if (Size == 1000)
	{
		printf("ENPTY\n");
		return;
	}
	if (order > (MAXSIZE - Size))
		return;
	CoverLinkMan(*PAddressList, order);
	Size++;
}
//ͨ����Ŵ�ӡ��ϵ����Ϣ
void PrintLinkManByOrder(PLinkManNode PAddressList, int order)
{
	printf("NAME:%s", (PAddressList + order - 1)->_name);
	printf("\n");
	printf("AGE:%d", (PAddressList + order - 1)->_age);
	printf("\n");
	switch ((PAddressList + order - 1)->Sex)
	{
	case 0:printf("SEX:MAN\n");break;
	case 1:printf("SEX:WOMAN\n"); break;
	case 2:printf("SEX:SECERT\n"); break;
	default:printf("SEX:SECERT\n"); break;
	}
	printf("TEL:%lld", (PAddressList + order - 1)->_Tel);
	printf("\n");
	printf("ADDRESS:%s", (PAddressList + order - 1)->_address);
	printf("\n");
}
//����ָ����ϵ����Ϣ
//��������
void FindLinkManByName(PLinkManNode PAddressList, char name[20])
{
	int i = 1;
	for (i = 1; i < MAXSIZE - Size; i++)
	{
		if (0 == strcmp(name, (PAddressList + i - 1)->_name))
		{
			printf("The contact person's order to look for is %d.\n", i);
			PrintLinkManByOrder(PAddressList, i);
			return;
		}
	}
	printf("No contact was found.\n");
}
//��Ų���
void FindLinkManByOrder(PLinkManNode PAddressList, int order)
{
	PrintLinkManByOrder(PAddressList, order);
}
//�޸�ָ����ϵ����Ϣ
//ͨ������޸�
void AmendLinkManByOrder(PLinkManNode PAddressList, int order)
{
	printf("Old value:\n");
	PrintLinkManByOrder(PAddressList, order);
	printf("amend:\n");
	printf("NAME:");
	scanf("%s", &(PAddressList+order-1)->_name);
	printf("AGE:");
	scanf("%d", &(PAddressList + order - 1)->_age);
	printf("SEX:0.MAN,1.WOMAN,2.SECERT");
	scanf("%d", &(PAddressList + order - 1)->Sex);
	printf("TEL:");
	scanf("%lld", &(PAddressList + order - 1)->_Tel);
	printf("ADDRESS:");
	scanf("%s", &(PAddressList + order - 1)->_address);
}
//ͨ�������޸�
void AmendLinkManByName(PLinkManNode PAddressList, char name[20])
{
	int i = 1;
	for (i = 1; i < MAXSIZE - Size; i++)
	{
		if (0 == strcmp(name, (PAddressList + i - 1)->_name))
		{
			AmendLinkManByOrder(PAddressList, i);
			return;
		}
	}
	printf("No contact was found.\n");
}
//���������ϵ��
void ClearLinkMan()
{
	Size = 1000;
}
//��ӡ������ϵ��
void PrintAllLinkMan(PLinkManNode PAddressList)
{
	int i = 1;
	for (i = 1; i <= MAXSIZE - Size; i++)
	{
		PrintLinkManByOrder(PAddressList, i);
	}
}
//�˵�
void Menu()
{
	printf("++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++1.AddLinkMan++++++++++++\n");
	printf("++++++++++++2.DeleteLinkMan+++++++++\n");
	printf("++++++++++++3.AmendLinkMan++++++++++\n");
	printf("++++++++++++4.FindLinkMan+++++++++++\n");
	printf("++++++++++++5.PrintAllLinkMan+++++++\n");
	printf("++++++++++++6.ClearAllLinkMan+++++++\n");
	printf("++++++++++++++++++++++++++++++++++++\n");
}
//////////////////////////////////////���Ժ���
void TestAddressList()
{
	int num = 0;
	int amend = 0;
	int amendorder = 0;
	char amendname[20] = { '0' };
	int del = 0;
	PLinkManNode AddressList;
	AddressListInit(&AddressList);
	while (1)
	{
		Menu();
		printf("choose:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:AddressListPush(&AddressList);
			break;
		case 2:printf("please show your order:");
			scanf("%d", &del);
			DeleteLinkMan(&AddressList, del);
			break;
		case 3:printf("1.by order.2.by name:");
			scanf("%d", &amend);
			switch (amend)
			{
			case 1:printf("show our order:");
				scanf("%d", &amendorder);
				AmendLinkManByOrder(AddressList, amendorder);
				break;
			case 2:printf("show your name:");
				scanf("&s", amendname);
				AmendLinkManByName(AddressList, amendname);
			default:
				printf("error\n");
				break;
			}
			break;
		case 4:printf("1.by order.2.by name:");
			scanf("%d", &num);
			switch (num)
			{
			case 1:printf("please show your order:");
				scanf("%d", amend);
				FindLinkManByOrder(AddressList, amend);
				break;
			case 2:printf("please show your name:");
				scanf("%s", amendname);
				FindLinkManByName(AddressList, amendname);
				break;
			default:printf("error\n");
				break;
			}
			break;
		case 5:PrintAllLinkMan(AddressList);
			break;
		case 6:ClearLinkMan();
			break;
		default:printf("error\n");
		}
	}
}