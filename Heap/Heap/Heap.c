#include"Heap.h"
//堆的初始化
void InitHeap(Heap* hp, Compare com)
{
	assert(hp);
	hp->_array = NULL;
	hp->_size = 0;
	hp->_capacity = MAXSIZE;
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*hp->_capacity);
	hp->_com = com;
}

//交换节点所存储的值
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
//	Parent = hp->_size / 2;//寻找第一个叶子节点
//	Cur = hp->_size;
//	//找到的第一个叶子节点有左孩子，不是叶子节点
//	if (Parent * 2 + 1 < hp->_size)
//	{
//		if (hp->_array[Parent] > hp->_array[Parent * 2 + 1])
//			Swap(&hp->_array[Parent], &hp->_array[Parent * 2 + 1]);
//	}
//
//	//进入肯定有两个孩子的双亲节点中的最后一个双亲节点
//	Parent--;
//
//	while (Parent >= 0)//从后向前依次判断
//	{
//		//找出两个孩子节点中较小的一个
//		if (hp->_array[Parent * 2 + 1] < hp->_array[Parent * 2 + 2])
//		{
//			//进来说明左孩子较小，判断双亲与左孩子谁大谁小
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
//		//判断左孩子是不是大于右孩子
//	/*		if (hp->_array[Parent * 2 + 1] > hp->_array[Parent * 2 + 2])
//				Swap(&hp->_array[Parent * 2 + 1], &hp->_array[Parent * 2 + 2]);*/
//		//判断字树是否满足堆的性质	
//		while (Cur < hp->_size/2)
//		{
//			//交换双亲与两个孩子中较小的一个
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
//			//判断左孩子是不是大于右孩子
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
	//指明堆的调整方式
	hp->_com = com;

	//给堆开辟空间
	hp->_capacity = MAXSIZE;
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*hp->_capacity);
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	//将数组赋给堆
	hp->_size = size;
	for (i = size - 1; i >= 0; i--)
	{
		hp->_array[i] = array[i];
	}
	//com指明要创建一个小堆
	//整理堆
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
//小/大堆的向下调整函数（向下调整法）
void _AdjustDown(Heap* hp, int Root)
{
	int Parent = 0;
	int Child = 0;
	Parent = Root;
	Child = Parent * 2 + 1;
	
	while (Child < hp->_size)
	{
		//判断他的右孩子是否存在
		if (Child + 1 <= hp->_size - 1)
		{
			//找出两个孩子中较小的一个
			if (Child+1<hp->_size && hp->_com(hp->_array[Child + 1] , hp->_array[Child]))
				Child += 1;
		}

		//较小的孩子与双亲节点比较，如果双亲节点较大就交换
		if (hp->_com(hp->_array[Child], hp->_array[Parent]))
		{
			Swap(&hp->_array[Parent], &hp->_array[Child]);
		}
		Parent = Child;
		Child = Parent * 2 + 1;
	}
}

//向上调整法
void _AdjustUp(Heap* hp, int Root)
{
	int Parent = 0;
	int Child = 0;
	//让child指向新插入的指针
	Child = Root;
	Parent = ((Child - 1) >> 1);

	//调整堆
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
//检测堆中是否还有可用空间
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
//在堆中插入一个元素
void InsertHeap(Heap* hp, HDataType data)
{
	int Parent = 0;
	int Child = 0;
	assert(hp);
	if (hp->_size >= hp->_capacity)
		return;

	//插入时，首先要检测堆中是否还有可用空间
	_CheckCapacity(hp);

	//将要插入的数据连接在堆的末尾
	hp->_array[hp->_size] = data;
	hp->_size++;

	//调整堆
	/*Parent = (hp->_size - 2) / 2;
	Child = Parent * 2 + 1;
	while (0 <= Parent)
	{
		_AdjustDown(hp, Parent);
		Parent = ((Parent - 1) >> 1);
	}*/
	
	//使用向上调整法调整堆
	Child = hp->_size - 1;
	while (Child > 0)
	{
		_AdjustUp(hp, Child);
		Child = ((Child - 1) >> 1);
	}
}
//检测一个堆是否为空堆
int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}
//获取堆中元素个数
int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
//删除堆顶元素 
//直接删除堆顶的元素，然后把堆中最末尾的元素放在堆顶，再进行堆调整
void DeleteHeapTop(Heap* hp)
{
	assert(hp);
	if (EmptyHeap(hp))
	{
		assert(0);
		return;
	}
	//用堆末尾的元素覆盖堆顶的元素
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;

	//进行堆调整
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

//销毁堆
void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_com = NULL;
}

//堆排序
//1.先交换堆顶元素与末尾元素（即已经把最大的元素放在末尾）
//2.下次调整就不包括堆中的最后一个元素
void SortHeap(Heap* hp)
{
	int Parent = 0;
	int Child = 0;
	int size = 0;
	assert(hp);
	size = hp->_size;

	while (hp->_size > 0)
	{
		//调整堆
		Parent = (hp->_size - 2) / 2;
		Child = Parent * 2 + 1;
		while (0 <= Parent)
		{
		_AdjustDown(hp, Parent);
		Parent = ((Parent - 1) >> 1);
		}
		//PrintHeap(*hp);
		//交换堆顶元素和末尾元素
		Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);

		//吐出最后一个元素
		--(hp->_size);
	}
	hp->_size = size;
}

//用堆解决Top_k问题
//先用数据的前K个元素建立一个小堆
//剩余的数据与堆顶元素比较  
//如果大于堆顶元素就覆盖堆顶元素然后重新调整堆
//如果小于就继续查看下一个元素
//循环此过程直至数据遍历完成
void TopKByHeap(HDataType* array, int K, int size)
{
	int i = 0;
	//初始化堆
	Heap hp;
	InitHeap(&hp, Less);

	//建立有K个节点的小堆
	while (hp._size < K)
	{
		InsertHeap(&hp, array[i]);
		i++;
	}

	//调整后续元素
	while (i < size)
	{
		//如果后续元素大于堆顶元素
		if (array[i]>hp._array[0])
		{
			//覆盖堆顶元素
			hp._array[0] = array[i];

			//调整堆
			_AdjustDown(&hp, 0);
		}
		i++;
	}
	printf("Top-K:");
	PrintHeap(hp);
}
///////////////////////////////////////////////////////////////测试函数
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

