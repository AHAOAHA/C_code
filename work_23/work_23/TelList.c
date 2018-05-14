#include"TelList.h"
void InitTelList(PTelList* ps)
{
	assert(ps);
	*ps = (PTelList)calloc(1000, sizeof(TelList));
	if (NULL == *ps)
	{
		printf("开辟空间失败\n");
		return 0;
	}
}
void PrintPage()
{
	printf("***********************************************\n");
	printf("*********************通讯录********************\n");
	printf("***********************************************\n");
	printf("****************1.添加一个联系人***************\n");
	printf("****************2.删除一个联系人***************\n");
	printf("****************3.查找指定联系人***************\n");
	printf("****************4.修改指定联系人信息***********\n");
	printf("****************5.显示所有联系人信息***********\n");
	printf("****************6.清空所有联系人***************\n");
	printf("****************7.以名字排序所有人*************\n");
	printf("***********************************************\n");
	printf("***********************************************\n");
}
void AddTelList(PTelList plist)
{
	if (NULL == plist)
	{
		printf("通讯录空间不存在\n");
		return 0;
	}
	printf("请输入姓名：");
	scanf("%s", plist->name);
	printf("请输入年龄：");
	scanf("%d", &plist->age);
	printf("0 男\n1 女\n2 保密\n请输入性别：");
	scanf("%d", &plist->sex);
	printf("请输入电话号码：");
	scanf("%d", &plist->tel);
	printf("请输入地址：");
	scanf("%s", plist->address);
	plist->size++;
	plist->num++;
}
void DelTelList(PTelList plist)
{
	int i = 0;
	char del_name[20] = {0};
	if (NULL == plist)
	{
		printf("通讯录不存在\n");
		return 0;
	}
	printf("请输入要删除的姓名：");
	scanf("%s", del_name);
	while (0 != strcmp(del_name, (plist + i)->name))
	{
		i++;
	}
	while ((plist+i+1)->size&&(plist+i+1)!=999)
	{
		(plist + i)->age = (plist + i + 1)->age;
		*(plist + i)->address = *(plist + i + 1)->address;
		*(plist + i)->name = *(plist + i + 1)->name;
		(plist + i)->num = (plist + i + 1)->num;
		(plist + i)->sex = (plist + i + 1)->sex;
		(plist + i)->size = (plist + i + 1)->size;
		(plist + i)->tel = (plist + i + 1)->tel;
		i++;
	}
}

void PrintTelList(PTelList plist)
{
	int i = 0;
	if (NULL == plist)
	{
		printf("通讯录不存在\n");
		return 0;
	}
	while ((plist + i)->size)
	{
		printf("姓名：%s\n", (plist + i)->name);
		printf("年龄：%d\n", (plist + i)->age);
		printf("性别：%d\n", (plist + i)->sex);
		printf("电话：%d\n", (plist + i)->tel);
		printf("地址：%d\n", (plist + i)->address);
		i++;
	}
}
