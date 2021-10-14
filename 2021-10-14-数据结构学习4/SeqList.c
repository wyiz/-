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

	if (ps->size >= ps->capacity)
	{
		//这里增容的大小，一般是增2倍
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a,sizeof(SLDateType)*ps->capacity);

		if (ps->a == NULL)
		{
			printf("增容失败\n");
			exit(-1);
		}
	}


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
	//要想在头部插入一个数据，就要把前面的size个数据往后移
	//往后移的办法是，先把最后一个往后移，然后再依次把size--个数据往后移


}

void SeqListPopFront(SL* ps);               //头删

void SeqListInsert(SL* ps, int pos, SLDateType x);//任意位置插入

void SeqListErase(SL* ps, int pos);//任意位置删除