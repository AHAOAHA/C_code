#include"AddressList.h"
int Size = 1000;
//初始化
void AddressListInit(PLinkManNode* PAddressList)
{
	PLinkManNode PList = NULL;
	assert(PAddressList);

	//为通讯录申请空间
	PList = (PLinkManNode)malloc(sizeof(LinkManNode)* MAXSIZE);
	if (NULL == PList)
	{
		assert(0);
		return;
	}

	*PAddressList = PList;
}
//输入联系人信息并保存
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
//添加联系人
void AddressListPush(PLinkManNode* PAddressList)
{
	assert(PAddressList);

	//判断是否有空间来存储联系人
	if (NULL == *PAddressList)
		return;
	
	//判断剩余空间大小
	if (Size <= 0)
	{
		printf("存储空间不足\n");
		return;
	}
	//输入联系人信息并保存
	InputLinkMan(*PAddressList);

	//给输入的联系人编号
	((*PAddressList) + (MAXSIZE - Size))->_order = MAXSIZE - Size + 1;

	//使剩余容量减1
	Size--;
}

//删除联系人
void CoverLinkMan(PLinkManNode AddressList, int order)
{
	//让要删除的联系人后面的联系人都向前挪动一次，覆盖掉要删除的联系人
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
//删除联系人（通过联系人序号）
void DeleteLinkMan(PLinkManNode* PAddressList,int order)
{
	assert(PAddressList);

	//判断通讯录中是否存在联系人
	if (Size == 1000)
	{
		printf("ENPTY\n");
		return;
	}

	//判断序号合法性
	if (order > (MAXSIZE - Size))
	{
		printf("HAVE NO THIS LINKMAN!\n");
		return;
	}

	//删除联系人
	CoverLinkMan(*PAddressList, order);

	//容量加1
	Size++;
}
//通过序号打印联系人信息
void PrintLinkManByOrder(PLinkManNode PAddressList, int order)
{
	printf("%d.\n", order);
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
//查找指定联系人信息
//姓名查找
void FindLinkManByName(PLinkManNode PAddressList, char name[20])
{
	int i = 1;

	//遍历联系人列表，通过姓名查找联系人
	for (i = 1; i <= MAXSIZE - Size; i++)
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
//序号查找
void FindLinkManByOrder(PLinkManNode PAddressList, int order)
{
	//判断联系人序号合法性
	if (order > MAXSIZE - Size)
	{
		printf("HAVE NO THIS LINKMAN!\n");
		return;
	}
	PrintLinkManByOrder(PAddressList, order);
}
//修改指定联系人信息
//通过序号修改
void AmendLinkManByOrder(PLinkManNode PAddressList, int order)
{
	//判断通讯录中是否有联系人
	if (1000 == Size)
	{
		printf("LinkMan enmty!\n");
		return;
	}

	//修改联系人信息
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
//通过姓名修改
void AmendLinkManByName(PLinkManNode PAddressList, char name[20])
{
	int i = 1;
	//通过姓名查找联系人
	for (i = 1; i <= MAXSIZE - Size; i++)
	{
		if (0 == strcmp(name, (PAddressList + i - 1)->_name))
		{
			//修改信息
			AmendLinkManByOrder(PAddressList, i);
			return;
		}
	}
	printf("No contact was found.\n");
}
//清空所有联系人
void ClearLinkMan()
{
	Size = 1000;
}
//打印所有联系人
void PrintAllLinkMan(PLinkManNode PAddressList)
{
	int i = 1;
	if (1000 == Size)
	{
		printf("LINKMAN EMPTY!\n");
		return;
	}
	for (i = 1; i <= MAXSIZE - Size; i++)
	{
		PrintLinkManByOrder(PAddressList, i);
	}
}
//交换两个联系人结点信息
void SwapLinkMan(PLinkManNode pLinkMan_1, PLinkManNode pLinkMan_2)
{
	long long int tel_tmp = 0;
	int Sex_tmp = 0;
	int age_tmp = 0;
	char name_tmp[20] = { '0' };
	char address_tmp[50] = { '0' };
	strcpy(name_tmp, pLinkMan_1->_name);
	strcpy(pLinkMan_1->_name, pLinkMan_2->_name);
	strcpy(pLinkMan_2->_name, name_tmp);
	strcpy(address_tmp, pLinkMan_1->_address);
	strcpy(pLinkMan_1->_address, pLinkMan_2->_address);
	strcpy(pLinkMan_2->_address, address_tmp);
	age_tmp = pLinkMan_1->_age;
	pLinkMan_1->_age = pLinkMan_2->_age;
	pLinkMan_2->_age = age_tmp;
	Sex_tmp = pLinkMan_1->Sex;
	pLinkMan_1->Sex = pLinkMan_2->Sex;
	pLinkMan_2->Sex = Sex_tmp;
	tel_tmp = pLinkMan_1->_Tel;
	pLinkMan_1->_Tel = pLinkMan_2->_Tel;
	pLinkMan_2->_Tel = tel_tmp;
}
//以姓名排序联系人列表
void SortByName(PLinkManNode *PAddressList)
{
	int i = 1;
	int j = 1;
	assert(PAddressList);
	if (NULL == *PAddressList)
	{
		printf("LinkMan is gone!\n");
		return;
	}
	if (1000 == Size)
	{
		printf("LINKMAN ENPTY!\n");
		return;
	}
	for (i = MAXSIZE-Size; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (strcmp(((*PAddressList) + j - 1)->_name, ((*PAddressList) + j)->_name)>0)
			{
				SwapLinkMan((*PAddressList) + j - 1, (*PAddressList) + j);
			}
		}
	}
	printf("DONE!\n");
}
//菜单
void Menu()
{
	printf("++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++1.AddLinkMan++++++++++++\n");
	printf("++++++++++++2.DeleteLinkMan+++++++++\n");
	printf("++++++++++++3.AmendLinkMan++++++++++\n");
	printf("++++++++++++4.FindLinkMan+++++++++++\n");
	printf("++++++++++++5.PrintAllLinkMan+++++++\n");
	printf("++++++++++++6.ClearAllLinkMan+++++++\n");
	printf("++++++++++++7.SortLinkManByName+++++\n");
	printf("++++++++++++8,Exit++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++\n");
}
//////////////////////////////////////
void TestAddressList()
{
	int num = 0;
	int amend = 0;
	int amendorder = 0;
	char amendname[20] = { '0' };
	int del = 0;
	PLinkManNode AddressList;//创建通讯录
	AddressListInit(&AddressList);//初始化

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
				scanf("%s", amendname);
				AmendLinkManByName(AddressList, amendname);
				break;
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
				scanf("%d", &amend);
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
		case 7:SortByName(&AddressList);
			break;
		case 8:free(AddressList);
			exit(1);
			break;
		default:printf("error\n");
			break;
		}
	}
}