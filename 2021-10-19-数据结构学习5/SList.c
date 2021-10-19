#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include "SList.h"


void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;

	while (cur != NULL)
	{
		printf("%d",cur->date);
		cur = cur->next;
	}
}