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
void SListPushBack(SListNode* phead,SListDateType x);

//βɾ
void SListPopBack(SListNode* phead);

//ͷ��
void SListPushFront(SListNode* phead,SListDateType x);

//ͷɾ
void SListPopFront(SListNode* phead);


//��ӡ����
//������ӡ����

void SListPrint(SListNode* phead);


