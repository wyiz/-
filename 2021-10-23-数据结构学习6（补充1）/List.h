#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDateType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDateType date;

}ListNode;


//β��
void ListPushBack(ListNode* phead,LTDateType x);

//�����µĽڵ㺯��
ListNode* BuyListNode(LTDateType x);


//˫�����ӡ����
void ListPrint(ListNode* phead);

//��ʼ������
// ��ʽ1������������phead�ĵ�ַ��������֮����ܶ�phead�����޸ģ�������ListIit�����д���һ���µĽڵ�֮��phead�����ľ��Ǵ����Ľڵ�ĵ�ַ
//void ListInit(ListNode** pphead);

//��ʽ2������������phead��Ȼ�󷵻�һ��ֵ��������ֵ���뵽phead��Ҳ�ǿ��Ե�

ListNode* ListInit();



//βɾ
void ListPopBack(ListNode* phead);

//ͷ��
void ListPushFront(ListNode* phead,LTDateType X);


//ͷɾ
void ListPopFront(ListNode* phead);

//����
ListNode* ListFind(ListNode* phead, LTDateType x);

//����λ�ò���,������������ҵ���Ԫ��ǰ�����
void ListInsert(ListNode* phead, LTDateType x,LTDateType y);

//����λ��ɾ��
void ListErase(ListNode* phead,LTDateType x);
