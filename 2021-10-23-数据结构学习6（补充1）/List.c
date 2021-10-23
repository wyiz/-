#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include "List.h"


//节点创建函数
ListNode* BuyListNode(LTDateType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		printf("开辟节点失败！");
		exit(-1);
	}

	node->next = NULL;
	node->prev = NULL;
	node->date = x;

	return node;

}

//尾插函数
void ListPushBack(ListNode* phead, LTDateType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

}

//节点数据打印函数
void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ",cur->date);
		cur = cur->next;
	}
	printf("\n");
}


//节点初始化函数
//方式1
/*
void ListInit(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;

}
*/

//方式2

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}


//尾删

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;

}



//头插函数的实现
void ListPushFront(ListNode* phead, LTDateType x)
{
	ListNode* pheadNext = phead->next;
	ListNode* newphead = BuyListNode(x);
	phead->next = newphead;
	newphead->prev = phead;
	newphead->next = pheadNext;
	pheadNext->prev = newphead;
	newphead->date = x;

}


//头删函数的实现
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* Fist = phead->next;
	phead->next = Fist->next;
	Fist->next->prev = phead;
	free(Fist);
	Fist = NULL;

}


//查找节点元素的函数实现
ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
			
		cur = cur->next;
	}

	return NULL;

}



//利用ListFind函数，在找到的元素前面插入一个节点
void ListInsert(ListNode* phead, LTDateType x,LTDateType y)
{
	assert(phead);
	
	ListNode* pos = ListFind(phead,x);
	ListNode* posPrev = pos->prev;
	ListNode* newNode = BuyListNode(y);

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
	newNode->date = y;
	
}


//利用ListFind函数，删除找到的那个数
void ListErase(ListNode* phead,LTDateType x)
{
	assert(phead);

	ListNode* pos = ListFind(phead, x);
	ListNode* posPrve = pos->prev;
	ListNode* posNext = pos->next;

	posPrve->next = posNext;
	posNext->prev = posPrve;
	free(pos);
	pos = NULL;


}

