#include"Heap.h"
//�����ڵ����洢��ֵ
void Swap(HDataType* first, HDataType* second)
{
	HDataType tmp = 0;
	tmp = *first;
	*first = *second;
	*second = tmp;
}
//void CreateHeap_Personal(Heap* hp, HDataType* array, int size)
//{
//	HDataType Parent = 0;
//	HDataType Cur = 0;
//	assert(hp);
//	hp->_array = array;
//	hp->_size = size;
//	Parent = hp->_size / 2;//Ѱ�ҵ�һ��Ҷ�ӽڵ�
//	Cur = hp->_size;
//	//�ҵ��ĵ�һ��Ҷ�ӽڵ������ӣ�����Ҷ�ӽڵ�
//	if (Parent * 2 + 1 < hp->_size)
//	{
//		if (hp->_array[Parent] > hp->_array[Parent * 2 + 1])
//			Swap(&hp->_array[Parent], &hp->_array[Parent * 2 + 1]);
//	}
//
//	//����϶����������ӵ�˫�׽ڵ��е����һ��˫�׽ڵ�
//	Parent--;
//
//	while (Parent >= 0)//�Ӻ���ǰ�����ж�
//	{
//		//�ҳ��������ӽڵ��н�С��һ��
//		if (hp->_array[Parent * 2 + 1] < hp->_array[Parent * 2 + 2])
//		{
//			//����˵�����ӽ�С���ж�˫��������˭��˭С
//			if (hp->_array[Parent]>hp->_array[Parent * 2 + 1])
//			{
//				Swap(&hp->_array[Parent], &hp->_array[Parent * 2 + 1]);
//				Cur = Parent * 2 + 1;
//			}
//		}
//		else
//		{
//			if (hp->_array[Parent] > hp->_array[Parent * 2 + 2])
//			{
//				Swap(&hp->_array[Parent], &hp->_array[Parent * 2 + 2]);
//				Cur = Parent * 2 + 2;
//			}
//		}
//		//�ж������ǲ��Ǵ����Һ���
//	/*		if (hp->_array[Parent * 2 + 1] > hp->_array[Parent * 2 + 2])
//				Swap(&hp->_array[Parent * 2 + 1], &hp->_array[Parent * 2 + 2]);*/
//		//�ж������Ƿ�����ѵ�����	
//		while (Cur < hp->_size/2)
//		{
//			//����˫�������������н�С��һ��
//			if (hp->_array[Cur * 2 + 1]<hp->_array[Cur * 2 + 2])
//			{
//				if (hp->_array[Cur] > hp->_array[Cur * 2 + 1])
//				{
//					Swap(&hp->_array[Cur], &hp->_array[Cur * 2 + 1]);
//				}
//				if (Cur * 2 + 1 < hp->_size)
//					Cur = Cur * 2 + 1;
//				else
//					Cur = hp->_size;
//			}
//			else
//			{
//				if (hp->_array[Cur] > hp->_array[Cur * 2 + 2])
//				{
//					Swap(&hp->_array[Cur], &hp->_array[Cur * 2 + 2]);
//				}
//				if (Cur * 2 + 2 < hp->_size)
//					Cur = Cur * 2 + 2;
//				else
//					Cur = hp->_size;
//			}
//			//�ж������ǲ��Ǵ����Һ���
//		/*	if (hp->_array[Cur * 2 + 1] > hp->_array[Cur * 2 + 2])
//				Swap(&hp->_array[Cur * 2 + 1], &hp->_array[Cur * 2 + 2]);*/
//		} 
//		Parent--;
//	}
//}
void PrintHeap(Heap hp)
{
	int size = 0;
	size = hp._size;
	while (size > 0)
	{
		printf("%d   ", hp._array[hp._size - size]);
		size--;
	}
	printf("\n");
}
void CreateHeap(Heap* hp, HDataType* array, int size)
{
	int i = 0;
	int Root = 0;
	if (NULL == hp)
	{
		assert(0);
		return;
	}
	//���ѿ��ٿռ�
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*size);
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	//�����鸳����
	hp->_size = size;
	for (i = size - 1; i >= 0; i--)
	{
		hp->_array[i] = array[i];
	}
	
	//�����
	Root = (size - 2) / 2;
	for (; Root >= 0; --Root)
	{
		_AdjustDown(hp, Root);
	}
}
void _AdjustDown(Heap* hp, int Root)
{
	int Parent = 0;
	int Child = 0;
	Parent = Root;
	Child = Parent * 2 + 1;
	
	while (Child < hp->_size)
	{
		//�ҳ����������н�С��һ��
		if (hp->_array[Child] > hp->_array[Child + 1])
			Child += 1;

		//��С�ĺ�����˫�׽ڵ�Ƚϣ����˫�׽ڵ�ϴ�ͽ���
		if (hp->_array[Parent] > hp->_array[Child])
		{
			Swap(&hp->_array[Parent], &hp->_array[Child]);
		}
		Parent = Child;
		Child = Parent * 2 + 1;
	}
}
///////////////////////////////////////////////////////////////���Ժ���
void TestHeap()
{
	Heap hp;
	HDataType array[] = {53,17,78,9,45,65,87,23,31};
	//CreateHeap_Personal(&hp, array, sizeof(array)/sizeof(array[0]));
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	PrintHeap(hp);
}

