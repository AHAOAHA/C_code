/*C语言实现简单的航班管理系统（单个文件）*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<assert.h>

#define PERSON_MAXNUM 100
#define PERSONNOTICKET_MAX 10
#define MAX_SIZE 10
int _size = 0;
int _person_size = 0;
int _personnoticket_size = 0;

//定义航班信息结构体
typedef struct plane
{
	char ID[10];
	char Start_Place[10];
	char End_Place[10];
	float price;
	int Buy_num;
	int Max_num;
	char time[20];
}Plane;

//定义乘客信息结构体
typedef struct Person
{
	int AirPlane_Num;
	char person_name[20];

}Person;




void home(Plane* p,Person* person, Person* person_noticket);//初始页面
void InitAirPlane(Plane** p);//初始化航班信息内存
void InputAirPlane(Plane* p);//输入航班信息
void CheckAirPlane(Plane* p);//查看航班信息
void DelAirPlane(Plane* p);//删除航班信息
void CheckAirPlaneOrder(Plane* p,Person* person);//查看航班订单
void PrintPerson(Plane* p, Person* person, int i);//打印航班乘客

void InitPerson(Person** person);//初始化乘客信息内存
void BookAirPlane(Plane* p, Person* person,Person* person_noticket);//预定航班
int CheckPerson(Plane* p, Person* person);//查看乘客订单信息
void ChangeAirPlane(Plane* p, Person* person);//改签
void ReturnTicket(Plane* p, Person* person);//退票


void PrintPerson(Plane* p, Person* person, int i);
void CheckPersonNoTicket(Plane* p, Person* person_noticket);//查看候补名单
///////////////////////////////////////

void home(Plane* p, Person* person, Person* person_noticket)
{
	int a, i, j;
	printf("\n*****************************欢迎进入飞机票务系统*****************************\n");
	printf("\n*************您好，现在要确认您的身份！票务人员请按 1 ，旅客请按 0 ***********\n");
	printf("请选择：");
	scanf("%d", &a);
	//航班管理人员操作
	if (a == 1)
		do{
			printf("\n****************** 1.输入航班信息 *******************\n");
			printf("\n****************** 2.删除航班信息 *******************\n");
			printf("\n****************** 3.浏览航班信息 *******************\n");
			printf("\n****************** 4.浏览目前已订票信息 *************\n");
			printf("\n****************** 5.查看候补名单 *******************\n");
			printf("\n****************** 0.退出        ********************\n");
			printf("请选择：");
			scanf("%d", &i);
			switch (i)
			{
				case 0: break;
				case 1:InputAirPlane(p);break;
				case 2:DelAirPlane(p);break;
				case 3:CheckAirPlane(p);break;
				case 4:CheckAirPlaneOrder(p, person); break;
				case 5:CheckPersonNoTicket(p, person_noticket); break;
				default:
					printf("输入错误！\n");
					break;
			}
		} while (i != 0);
	//乘客操作
	if (a == 0)
		do{

			printf("\n*********************** 1.订票 **********************\n");
			printf("\n*********************** 2.改签 **********************\n");
			printf("\n*********************** 3.退票 **********************\n");
			printf("\n*********************** 4.浏览航班信息 **************\n");
			printf("\n*********************** 5.查询个人订票信息 **********\n");
			printf("\n*********************** 0.退出 **********************\n");
			printf("请选择：");
			scanf("%d", &j);
			switch (j)
			{
				case 0:break;
				case 1:BookAirPlane(p, person,person_noticket);break;
				case 2:ChangeAirPlane(p, person);break;
				case 3:ReturnTicket(p, person);break;
				case 4:CheckAirPlane(p);break;
				case 5:CheckPerson(p, person); break;
			}
		} while (j != 0);
}

//初始化
void InitAirPlane(Plane** p)
{
	assert(p);

	//申请空间
	*p = (Plane*)malloc(sizeof(Plane)*MAX_SIZE);
	if (NULL == *p)
	{
		printf("开辟空间失败！\n");
		return;
	}
	(*p)->Buy_num = 0;
}
//输入航班信息
void InputAirPlane(Plane* p)
{
	if (_size <= MAX_SIZE)
	{
		printf("航班编号：%d\n", _size);
		printf("输入航班ID:");
		scanf("%s", (p+_size)->ID);
		printf("输入始发地：");
		scanf("%s", (p + _size)->Start_Place);
		printf("输入目的地：");
		scanf("%s", (p + _size)->End_Place);
		printf("输入航班起飞时间：");
		scanf("%s", (p + _size)->time);
		printf("输入价格：");
		scanf("%f", &(p + _size)->price);
		printf("输入航班可乘坐最大人数：");
		scanf("%d", &(p + _size)->Max_num);
		do
		{
			printf("目前卖出机票数量：");
			scanf("%d", &(p + _size)->Buy_num);
			if ((p + _size)->Buy_num > (p + _size)->Max_num)
			{
				printf("输入已卖出机票数量错误！\n");
				printf("请重新输入！\n\n");
			}
		} while ((p + _size)->Buy_num > (p + _size)->Max_num);
		_size++;
		printf("添加航班信息完成！\n\n");
	}
	else
	{
		printf("内存已满！\n");
		return;
	}
}

//浏览航班信息
void CheckAirPlane(Plane* p)
{
	int i = 0;
	printf("目前在售的航班信息：\n\n");
	for (i = 0; i < _size; i++)
	{
		printf("航班编号：%d\n", i);
		printf("ID:%s\n", (p+i)->ID);
		printf("始发地：%s\n", (p + i)->Start_Place);
		printf("目的地:%s\n", (p + i)->End_Place);
		printf("起飞时间：%s\n", (p + i)->time);
		printf("机票价格：%2f\n", (p + i)->price);
		printf("剩余机票：%d\n", ((p + i)->Max_num - (p + i)->Buy_num) );
		printf("\n");
	}
}

//删除航班信息
void DelAirPlane(Plane* p)
{
	int j = 0;
	int i = -1;
	assert(p);
	printf("请输入要删除的航班编号：");
	scanf("%d", &i);
	for (j = i; j < _size; j++)
	{
		strcpy((p + j)->ID, (p + j + 1)->ID);
		strcpy((p + j)->Start_Place, (p + j + 1)->Start_Place);
		strcpy((p + j)->End_Place, (p + j)->End_Place);
		strcpy((p + j)->time, (p + j + 1)->time);
		(p + j)->price = (p + j + 1)->price;
		(p + j)->Max_num = (p + j + 1)->Max_num;
		(p + j)->Buy_num = (p + j + 1)->Buy_num;
	}
	_size--;
}

//初始化订票信息
void InitPerson(Person** person)
{
	assert(person);
	*person = (Person*)malloc(sizeof(Person)*PERSON_MAXNUM);
	if (NULL == *person)
	{
		printf("开辟空间失败！\n");
		return;
	}
}

//订票
void BookAirPlane(Plane* p, Person* person, Person* person_noticket)
{
	int i = -1;
	CheckAirPlane(p);
	printf("请选择你要预定的航班编号：");
	scanf("%d", &i);
	if ((p + i)->Max_num == (p + i)->Buy_num)
	{
		printf("对不起，该航班机票已售完！\n");
		printf("请输入您的姓名（我们将把您添加进候补名单）：");
		scanf("%s", (person_noticket+_personnoticket_size)->person_name);
		(person_noticket + _personnoticket_size)->AirPlane_Num = i;
		_personnoticket_size++;
		printf("添加候补名单成功！\n\n");
		return;
	}
	else
	{
		if (_person_size > PERSON_MAXNUM)
		{
			printf("存储容量不足！\n");
			return;
		}
		printf("请输入姓名：");
		scanf("%s", (person + _person_size)->person_name);
		(person + _person_size)->AirPlane_Num = i;
		_person_size++;
		(p + i)->Buy_num++;
		printf("预定成功！\n");
	}

}

//查看个人订票信息
int CheckPerson(Plane* p, Person* person)
{
	int flag = 0;
	int i = 0;
	char _name[20] = { 0 };
	printf("请输入您的姓名：");
	scanf("%s", &_name);
	printf("您的个人订票信息：\n\n");
	for (i = 0; i < _person_size; i++)
	{
		if (0 == strcmp(_name, (person + i)->person_name))
		{
			flag = 1;
			printf("订单编号：%d\n", i);
			printf("姓名：%s\n", (person + i)->person_name);
			printf("航班编号：%d\n", (person + i)->AirPlane_Num);
			printf("航班ID:%s\n", (p + (person + i)->AirPlane_Num)->ID);
			printf("始发地：%s\n", (p + (person + i)->AirPlane_Num)->Start_Place);
			printf("目的地：%s\n", (p + (person + i)->AirPlane_Num)->End_Place);
			printf("起飞时间:%s\n", (p + (person + i)->AirPlane_Num)->time);
			printf("机票价格：%f\n", (p + (person + i)->AirPlane_Num)->price);
			printf("\n");
		}
	}
	if (0 == flag)
	{
		printf("未找到该乘客订票信息！\n");
		return 0;
	}
	return 1;
}

//改签
void ChangeAirPlane(Plane* p, Person* person)
{
	int i = -1;
	int j = -1;
	if (0 == CheckPerson(p, person))
	{
		return;
	}
	printf("请输入要改签的订单编号：");
	printf("\n");
	scanf("%d", &i);
	(p + i)->Buy_num--;
	CheckAirPlane(p);
	do
	{
		printf("请输入要改签的航班编号：");
		scanf("%d", &j);
		if ((p + j)->Buy_num >= (p + j)->Max_num)
		{
			printf("该次航班已满员，请重新选择！\n");
		}
	} while ((p + j)->Buy_num >= (p + j)->Max_num);
	(person + i)->AirPlane_Num = j;
	(p + j)->Buy_num++;
	printf("改签成功！\n\n");
}


//删除订单
void ReturnTicket(Plane* p, Person* person)
{
	int i = -1;
	int j = 0;
	CheckPerson(p, person);
	printf("请输入要删除的订单编号：");
	scanf("%d", &i);
	for (j = i; j < _person_size; j++)
	{
		(person + j)->AirPlane_Num = (person + j + 1)->AirPlane_Num;
		strcpy((person + j)->person_name, (person + j + 1)->person_name);
	}
	printf("退票成功！\n");
}


//查看目前订票信息
void CheckAirPlaneOrder(Plane* p, Person* person)
{
	int i = -1;
	for (i = 0; i < _size; i++)
	{
		printf("航班编号：%d\n", i);
		printf("ID:%s\n", (p + i)->ID);
		printf("始发地：%s\n", (p + i)->Start_Place);
		printf("目的地:%s\n", (p + i)->End_Place);
		printf("起飞时间：%s\n", (p + i)->time);
		printf("机票价格：%2f\n", (p + i)->price);
		printf("剩余机票：%d\n", ((p + i)->Max_num - (p + i)->Buy_num));
		printf("买票人信息："); PrintPerson(p,person, i);
	}
}
void PrintPerson(Plane* p, Person* person,int i)
{
	int ticket_num = 0;
	int j = 0;
	for (j = 0; j < _person_size; j++)
	{
		if ((person + j)->AirPlane_Num == i)
		{
			printf("%s ,", (person + j)->person_name);
			ticket_num++;
		}
	}
	printf("\n\n");
}

//候补名单初始化
void InitPersonNoTicket(Person** person_noticket)
{
	assert(person_noticket);
	*person_noticket = (Person*)malloc(sizeof(Person)*PERSONNOTICKET_MAX);
	if (NULL == *person_noticket)
	{
		printf("开辟空间失败！\n");
		return;
	}
}

//查看候补名单
void CheckPersonNoTicket(Plane* p, Person* person_noticket)
{
	int i = 0;
	printf("候补名单：\n\n");
	if (0 == _personnoticket_size)
	{
		printf("候补名单为空！\n\n");
		return;
	}
	for (i = 0; i < _personnoticket_size; i++)
	{
		printf("姓名：%s\n", (person_noticket + i)->person_name);
		printf("所需要航班编号：%d\n", (person_noticket + i)->AirPlane_Num);
		printf("航班ID:%s\n", (p + ((person_noticket + i)->AirPlane_Num))->ID);
		printf("始发地：%s\n", ((p + ((person_noticket + i)->AirPlane_Num))->Start_Place));
		printf("目的地：%s\n", (p + ((person_noticket + i)->AirPlane_Num))->End_Place);
	}
}
//主函数
int main()
{
	Plane* p=NULL;
	Person* person=NULL;
	Person* person_noticket = NULL;
	InitPersonNoTicket(&person_noticket);
	InitAirPlane(&p);
	InitPerson(&person);
	while (1)
	{
		home(p, person, person_noticket);
	}
 	system("pause");
	return 0;
}