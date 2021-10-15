#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)*4);



		if (ps->a == NULL)
		{
			printf("申请内存失败！");
			exit(-1);
		}

		ps->size = 0;
		ps->capacity = 4;//这里的4是4个数据的意思，不是字节数，这个数要与上面的*4对应

}


//尾插
void SeqListPushBack(SL* ps, SLDateType x)
{
	assert(ps);

	//在这里需要判断空间是否满了，如果满了就需要增容
	SeqListCheckCapacity(ps);
	

	ps->a[ps->size] = x;
	ps->size++;
}


void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0;i<ps->size;i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}



//尾删  

void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}


//头插

void SeqListPushFront(SL* ps, SLDateType x)
{
	SeqListCheckCapacity(ps);

	//要想在头部插入一个数据，就要把前面的size个数据往后移
	//往后移的办法是，先把最后一个往后移，然后再依次把size--个数据往后移

	int end = ps->size - 1;
	while (end >=0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	//把第一个数组内容修改为插入的数据
	ps->a[0] = x;
	ps->size++;

}

void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		//这里增容的大小，一般是增2倍
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);

		if (ps->a == NULL)
		{
			printf("增容失败\n");
			exit(-1);
		}
	}

}


//头删

void SeqListPopFront(SL* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;

	}

	ps->size--;

}

//任意位置插入

void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);


	int y = ps->size - 1;
	
	if (pos <= ps->size - 1)
	{
		for (int i = 0; i <= ps->size - 1 - pos; i++)
		{

			ps->a[y + 1] = ps->a[y];
			y--;


		}

		ps->a[pos] = x;
		ps->size++;
	}

	else
	{
		ps->a[ps->size] = x;
		ps->size++;
	}

	

}

//任意位置删除

void SeqListErase(SL* ps, int pos)
{
	assert(ps);

	int m = pos;

	if (pos<=ps->size-1)
	{

		for (int i = 0; i <= ps->size - 1 - pos; i++)
		{
			ps->a[m] = ps->a[m + 1];
			m++;
		}
		ps->size--;
	}


}