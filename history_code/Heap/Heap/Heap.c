#include"Heap.h"
//�ѵĳ�ʼ��
void InitHeap(Heap* hp, Compare com)
{
	assert(hp);
	hp->_array = NULL;
	hp->_size = 0;
	hp->_capacity = MAXSIZE;
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*hp->_capacity);
	hp->_com = com;
}

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
void CreateHeap(Heap* hp, HDataType* array, int size, Compare com)
{
	int i = 0;
	int Root = 0;
	if (NULL == hp)
	{
		assert(0);
		return;
	}
	//ָ���ѵĵ�����ʽ
	hp->_com = com;

	//���ѿ��ٿռ�
	hp->_capacity = MAXSIZE;
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*hp->_capacity);
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
	//comָ��Ҫ����һ��С��
	//�����
	Root = (size - 2) / 2;
	for (; Root >= 0; --Root)
	{
		_AdjustDown(hp, Root);
	}
}
int Less(HDataType Left, HDataType Right)
{
	return Left < Right;
}
int Greater(HDataType Left, HDataType Right)
{
	return Left>Right;
}
//С/��ѵ����µ������������µ�������
void _AdjustDown(Heap* hp, int Root)
{
	int Parent = 0;
	int Child = 0;
	Parent = Root;
	Child = Parent * 2 + 1;
	
	while (Child < hp->_size)
	{
		//�ж������Һ����Ƿ����
		if (Child + 1 <= hp->_size - 1)
		{
			//�ҳ����������н�С��һ��
			if (Child+1<hp->_size && hp->_com(hp->_array[Child + 1] , hp->_array[Child]))
				Child += 1;
		}

		//��С�ĺ�����˫�׽ڵ�Ƚϣ����˫�׽ڵ�ϴ�ͽ���
		if (hp->_com(hp->_array[Child], hp->_array[Parent]))
		{
			Swap(&hp->_array[Parent], &hp->_array[Child]);
		}
		Parent = Child;
		Child = Parent * 2 + 1;
	}
}

//���ϵ�����
void _AdjustUp(Heap* hp, int Root)
{
	int Parent = 0;
	int Child = 0;
	//��childָ���²����ָ��
	Child = Root;
	Parent = ((Child - 1) >> 1);

	//������
	while (0 <= Parent)
	{
		if (hp->_com(hp->_array[Child], hp->_array[Parent]))
		{
			Swap(&hp->_array[Child], &hp->_array[Parent]);
		}
		Child = Parent;
		Parent = ((Parent - 2) >> 1);
	}
}
//�������Ƿ��п��ÿռ�
void _CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		realloc(hp->_array, sizeof(HDataType)*(hp->_capacity * 2));
		if (NULL == hp->_array)
		{
			assert(0);
			return;
		}
	}
}
//�ڶ��в���һ��Ԫ��
void InsertHeap(Heap* hp, HDataType data)
{
	int Parent = 0;
	int Child = 0;
	assert(hp);
	if (hp->_size >= hp->_capacity)
		return;

	//����ʱ������Ҫ�������Ƿ��п��ÿռ�
	_CheckCapacity(hp);

	//��Ҫ��������������ڶѵ�ĩβ
	hp->_array[hp->_size] = data;
	hp->_size++;

	//������
	/*Parent = (hp->_size - 2) / 2;
	Child = Parent * 2 + 1;
	while (0 <= Parent)
	{
		_AdjustDown(hp, Parent);
		Parent = ((Parent - 1) >> 1);
	}*/
	
	//ʹ�����ϵ�����������
	Child = hp->_size - 1;
	while (Child > 0)
	{
		_AdjustUp(hp, Child);
		Child = ((Child - 1) >> 1);
	}
}
//���һ�����Ƿ�Ϊ�ն�
int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}
//��ȡ����Ԫ�ظ���
int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
//ɾ���Ѷ�Ԫ�� 
//ֱ��ɾ���Ѷ���Ԫ�أ�Ȼ��Ѷ�����ĩβ��Ԫ�ط��ڶѶ����ٽ��жѵ���
void DeleteHeapTop(Heap* hp)
{
	assert(hp);
	if (EmptyHeap(hp))
	{
		assert(0);
		return;
	}
	//�ö�ĩβ��Ԫ�ظ��ǶѶ���Ԫ��
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;

	//���жѵ���
	_AdjustDown(hp, 0);
}
void DestoryHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

//���ٶ�
void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_com = NULL;
}

//������
//1.�Ƚ����Ѷ�Ԫ����ĩβԪ�أ����Ѿ�������Ԫ�ط���ĩβ��
//2.�´ε����Ͳ��������е����һ��Ԫ��
void SortHeap(Heap* hp)
{
	int Parent = 0;
	int Child = 0;
	int size = 0;
	assert(hp);
	size = hp->_size;

	while (hp->_size > 0)
	{
		//������
		Parent = (hp->_size - 2) / 2;
		Child = Parent * 2 + 1;
		while (0 <= Parent)
		{
		_AdjustDown(hp, Parent);
		Parent = ((Parent - 1) >> 1);
		}
		//PrintHeap(*hp);
		//�����Ѷ�Ԫ�غ�ĩβԪ��
		Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);

		//�³����һ��Ԫ��
		--(hp->_size);
	}
	hp->_size = size;
}

//�öѽ��Top_k����
//�������ݵ�ǰK��Ԫ�ؽ���һ��С��
//ʣ���������Ѷ�Ԫ�رȽ�  
//������ڶѶ�Ԫ�ؾ͸��ǶѶ�Ԫ��Ȼ�����µ�����
//���С�ھͼ����鿴��һ��Ԫ��
//ѭ���˹���ֱ�����ݱ������
void TopKByHeap(HDataType* array, int K, int size)
{
	int i = 0;
	//��ʼ����
	Heap hp;
	InitHeap(&hp, Less);

	//������K���ڵ��С��
	while (hp._size < K)
	{
		InsertHeap(&hp, array[i]);
		i++;
	}

	//��������Ԫ��
	while (i < size)
	{
		//�������Ԫ�ش��ڶѶ�Ԫ��
		if (array[i]>hp._array[0])
		{
			//���ǶѶ�Ԫ��
			hp._array[0] = array[i];

			//������
			_AdjustDown(&hp, 0);
		}
		i++;
	}
	printf("Top-K:");
	PrintHeap(hp);
}
///////////////////////////////////////////////////////////////���Ժ���
void TestHeap()
{
	HDataType array[20] = { 1,2,3,4,5,6,7,8,9,10,99,88,77,66,55,44,33,22,11,34 };
	TopKByHeap(array, 10, sizeof(array) / sizeof(array[0]));
	//Heap hp;
	//HDataType array[] = {53,17,78,9,45,65,87,23,31};
	////CreateHeap_Personal(&hp, array, sizeof(array)/sizeof(array[0]));
	//CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]),Greater);
	//InsertHeap(&hp, 5);
	//PrintHeap(hp);
	//SortHeap(&hp);
	//PrintHeap(hp);
	////DeleteHeapTop(&hp);
	//PrintHeap(hp);
	
}

