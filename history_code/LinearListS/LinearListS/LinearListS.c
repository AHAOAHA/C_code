#include"LinearListS.h"
void InitList(LinearList* ps)
{
	if (NULL == ps)
		return 0;
	int i = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		(ps->array)[i] = 0;
	}
	ps->size = 0;
}
void InputList(LinearList* ps)
{
	if (NULL == ps)
		return 0;
	int i = 0;
	printf("请输入列表元素个数size = ");
	scanf("%d", &(ps->size));
	printf("请输入列表数据：");
	for (i = 0; i < ps->size; i++)
	{
		scanf("%d", &(ps->array)[i]);
	}
}
void LinearListPushBack(LinearList* ps, DataType data)
{
	if (NULL == ps)
		return 0;
	if (LinearListCheck(ps))
	{
		printf("列表已经存满\n");
		return 0;
	}
	ps->array[ps->size] = data;
	ps->size += 1;
}
void LinearListPopBack(LinearList* ps)
{
	if (NULL == ps)
		return 0;
	ps->array[ps->size - 1] = 0;
	ps->size -= 1;
}
void LinearListPushFront(LinearList* ps, DataType data)
{
	if (NULL == ps)
		return 0;
	int i = 0;
	if (LinearListCheck(ps))
	{
		printf("列表已满，不能进行头插\n");
		return 0;
	}
	for (i = ps->size-1; i >= 0; i--)
	{
		Move(&ps->array[i], &ps->array[i + 1]);
	}
	ps->array[i+1] = data;
	ps->size += 1;

}
void LinearListPopFront(LinearList* ps)
{
	if (NULL == ps)
		return 0;
	int i = 0;
	for (i = 0; i < ps->size-1; i++)
	{
		Move(&ps->array[i + 1], &ps->array[i]);
	}
	ps->array[ps->size - 1] = 0;
	ps->size -= 1;
}
void LinearListInsert(LinearList* ps, size_t pos, DataType data)
{
	if (NULL == ps)
		return 0;
	if (LinearListCheck(ps))
	{
		printf("列表已满无法插入\n");
		return 0;
	}
	size_t i = 0;
	for (i = ps->size-1; i >= pos; i--)
	{
		Swap(&ps->array[i], &ps->array[i + 1]);
	}
	ps->array[i+1] = data;
	ps->size += 1;
}
void LinearListErase(LinearList* ps, size_t pos)
{
	if (NULL == ps)
		return 0;
	int i = 0;
	for (i = pos; i < ps->size-1; i++)
	{
		Move(&ps->array[i + 1], &ps->array[i]);
	}
	ps->array[i] = 0;
	ps->size -= 1;
}
int LinearListFind(LinearList* ps, DataType data)
{
	if (NULL == ps)
		exit(1);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == data)
			return i;
	}
	return -1;
}
void LinearListRemove(LinearList* ps, DataType data)
{
	if (NULL == ps)
		return 0;
	int i = 0;
	i = LinearListFind(ps, data);
	if (-1 == i)
	{
		printf("列表中没有这个数据\n");
		return 0;
	}
	LinearListErase(ps, i);
	ps->size -= 1;
}
void LinearListRemoveAll(LinearList* ps, DataType data)
{
	if (NULL == ps)
		return 0;
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == data)
		{
			LinearListErase(ps, i);
			i = 0;
		}
	}
}
int LinearListCheck(LinearList* ps)
{
	if (NULL == ps)
		return 0;
	if (ps->size == SIZE_MAX)
		return 1;
	else
		return 0;
}
void Swap(DataType* pa, DataType* pb)
{
	DataType tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void Move(DataType* pa, DataType* pb)
{
	*pb = *pa;
}
void BubbleSort(LinearList* ps)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		for (j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->array[j]>ps->array[j + 1])
			{
				Swap(&ps->array[j], &ps->array[j + 1]);
			}
		}
	}
}
void PrintList(LinearList* ps)
{
	int i = 0;
	printf("顺序表元素打印：");
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
void SelectSort(LinearList* ps)
{
	int *left = NULL;
	int *right = NULL;
	int *i = NULL;
	int *pmin = NULL;
	int *pmax = NULL;
	pmin = ps->array + 0;
	pmax = ps->array + 0;
	left = ps->array + 0;
	right = ps->array + ps->size - 1;
	while (left <= right)
	{
		for (i = left; i <= right; i++)
		{
			if (*pmax < *i)
			{
				pmax = i;
			}
			if (*pmin > *i)
			{
				pmin = i;
			}
		}
		if (pmin != left)
		{
			Swap(pmin, left);
		}
		if (pmax != right)
		{
			Swap(pmax, right);
		}
		pmax = ++left;
		pmin = left;
		right--;
	}
}