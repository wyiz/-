#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include "List.h"


//�ڵ㴴������
ListNode* BuyListNode(LTDateType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		printf("���ٽڵ�ʧ�ܣ�");
		exit(-1);
	}

	node->next = NULL;
	node->prev = NULL;
	node->date = x;

	return node;

}

//β�庯��
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

//�ڵ����ݴ�ӡ����
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


//�ڵ��ʼ������
//��ʽ1
/*
void ListInit(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;

}
*/

//��ʽ2

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

