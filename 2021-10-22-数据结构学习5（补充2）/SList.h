#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef int SListDateType;

//�������ʽ��ʵһ�οռ䣬ǰ�沿�ִ洢�������ݣ�����洢������һ������ĵ�ַ����ָ�룬ָ����һ���ṹ��
typedef struct SListNode
{
	SListDateType date;
	struct SListNode* next;//�����ŵ�����һ�����ݵĵ�ַ����ŵ�ַӦ��ָ�룬��һ����������Ҳ�ǽṹ�����͵ģ�������struct SListNode*
}SListNode;


//β��
void SListPushBack(SListNode** pphead,SListDateType x);

//βɾ
void SListPopBack(SListNode** pphead);

//ͷ��
void SListPushFront(SListNode** pphead,SListDateType x);

//ͷɾ
void SListPopFront(SListNode** pphead);


//��ӡ����
//������ӡ����

void SListPrint(SListNode** pphead);


//��������

SListNode* SListFind(SListNode* phead, SListDateType x);


