#include"LinearListD.h"
void LinearListDInit(LinearListD* ps)
{
	int i = 0;
	ps->array = (DataType*)calloc(SIZE_INIT, sizeof(DataType));
	ps->capacity = SIZE_INIT;
	for (i = 0; i < SIZE_INIT; i++)
	{
		*(ps->array + i) = 0;
	}
	ps->size = 0;
}
void LinearListPushBack(LinearListD* ps, DataType data)
{
	int i = 0;
	assert(ps);
	if (CheckCapacity(ps))
	{
		ps->array = realloc(ps->array, (++ps->capacity) * sizeof(DataType));
		*(ps->array + ps->size) = data;
	}
	else
	{
		*(ps->array + ps->size) = data;
	}
	ps->size+=1;
}
void LinearListDPopBack(LinearListD* ps)
{
	assert(ps);
	if (LinearListDEmpty(ps))
		;
	else
		*(ps->array + ps->size - 1) = 0;
	ps->size--;
}
int LinearListDEmpty(LinearListD* ps)
{
	assert(ps);
	if (0 == ps->size)
		return 1;
	return 0;
}
void LinearListDClear(LinearListD* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		*(ps->array + i) = 0;
	}
	ps->size = 0;
}
int CheckCapacity(LinearListD* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
		return 1;
	else
		return 0;
}
void LinearListDDestroy(LinearListD* ps)
{
	assert(ps);
	free(ps->array);
	ps = NULL;
}