#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include "SList.h"

//打印函数的实现

void SListPrint(SListNode** pphead)
{
	SListNode* cur = *pphead;     //这里是pList传过来的地址重新赋值给一个指针变量

	while (cur != NULL)
	{
		printf("%d->",cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}



//这是动态开辟一块节点

SListNode* BuySListNode(SListDateType x)   
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请节点失败！");
		exit(-1);
	}

	newNode->date = x;
	newNode->next = NULL;

	return newNode;

}





//尾插函数的实现

void SListPushBack(SListNode** pphead, SListDateType x)
{
	SListNode* newNode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newNode;

	}

	else
	{
		//先找到尾部

		SListNode* tail = *pphead;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}

	
}



//尾删

void SListPopBack(SListNode** pphead)
{
	//删除时要考虑三种情况

	//1.这个节点本身就是空的，即phead = NULL
	if (*pphead == NULL)   //*pphead
	{
		return 0;
	}


	//2.只有一个节点
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;

	}


	//3.有一个以上的节点
	else
	{
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		
		free(tail);
		prev->next = NULL;

	}



}
