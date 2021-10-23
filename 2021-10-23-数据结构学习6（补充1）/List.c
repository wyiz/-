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
	printf("\n");
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


//βɾ

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



//ͷ�庯����ʵ��
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


//ͷɾ������ʵ��
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


//���ҽڵ�Ԫ�صĺ���ʵ��
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



//����ListFind���������ҵ���Ԫ��ǰ�����һ���ڵ�
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


//����ListFind������ɾ���ҵ����Ǹ���
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

