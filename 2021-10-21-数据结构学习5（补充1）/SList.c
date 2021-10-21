#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include "SList.h"

//��ӡ������ʵ��

void SListPrint(SListNode** pphead)
{
	SListNode* cur = *pphead;     //������pList�������ĵ�ַ���¸�ֵ��һ��ָ�����

	while (cur != NULL)
	{
		printf("%d->",cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}



//���Ƕ�̬����һ��ڵ�

SListNode* BuySListNode(SListDateType x)   
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("����ڵ�ʧ�ܣ�");
		exit(-1);
	}

	newNode->date = x;
	newNode->next = NULL;

	return newNode;

}





//β�庯����ʵ��

void SListPushBack(SListNode** pphead, SListDateType x)
{
	SListNode* newNode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newNode;

	}

	else
	{
		//���ҵ�β��

		SListNode* tail = *pphead;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}

	
}



//βɾ

void SListPopBack(SListNode** pphead)
{
	//ɾ��ʱҪ�����������

	//1.����ڵ㱾����ǿյģ���phead = NULL
	if (*pphead == NULL)   //*pphead
	{
		return 0;
	}


	//2.ֻ��һ���ڵ�
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;

	}


	//3.��һ�����ϵĽڵ�
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
