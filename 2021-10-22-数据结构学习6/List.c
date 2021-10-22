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

