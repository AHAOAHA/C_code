#include"TelList.h"
void InitTelList(PTelList* ps)
{
	assert(ps);
	*ps = (PTelList)calloc(1000, sizeof(TelList));
	if (NULL == *ps)
	{
		printf("���ٿռ�ʧ��\n");
		return 0;
	}
}
void PrintPage()
{
	printf("***********************************************\n");
	printf("*********************ͨѶ¼********************\n");
	printf("***********************************************\n");
	printf("****************1.���һ����ϵ��***************\n");
	printf("****************2.ɾ��һ����ϵ��***************\n");
	printf("****************3.����ָ����ϵ��***************\n");
	printf("****************4.�޸�ָ����ϵ����Ϣ***********\n");
	printf("****************5.��ʾ������ϵ����Ϣ***********\n");
	printf("****************6.���������ϵ��***************\n");
	printf("****************7.����������������*************\n");
	printf("***********************************************\n");
	printf("***********************************************\n");
}
void AddTelList(PTelList plist)
{
	if (NULL == plist)
	{
		printf("ͨѶ¼�ռ䲻����\n");
		return 0;
	}
	printf("������������");
	scanf("%s", plist->name);
	printf("���������䣺");
	scanf("%d", &plist->age);
	printf("0 ��\n1 Ů\n2 ����\n�������Ա�");
	scanf("%d", &plist->sex);
	printf("������绰���룺");
	scanf("%d", &plist->tel);
	printf("�������ַ��");
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
		printf("ͨѶ¼������\n");
		return 0;
	}
	printf("������Ҫɾ����������");
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
		printf("ͨѶ¼������\n");
		return 0;
	}
	while ((plist + i)->size)
	{
		printf("������%s\n", (plist + i)->name);
		printf("���䣺%d\n", (plist + i)->age);
		printf("�Ա�%d\n", (plist + i)->sex);
		printf("�绰��%d\n", (plist + i)->tel);
		printf("��ַ��%d\n", (plist + i)->address);
		i++;
	}
}
