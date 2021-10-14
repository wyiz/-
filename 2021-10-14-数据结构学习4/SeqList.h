#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//˳�����Ч�����������б�����������

/*
struct SeqList
{
	int a[10];
	int size;//����size��ʾ�����������ж��ٸ���Ч����
};

*/

//�����������һ�������⣬��������ṹ�����������������int������˵����������Ҫ�޸�Ϊdouble�����ˣ���ô��������;���Ҫ����Ϊdouble����ô���溯���������ɾ��Ĵ��ݹ�ȥ�����Ͷ���Ҫ�޸�
//��ʱ��ͷǳ��鷳

//��ʱ����Ҫʹ��typedef��������������ͽ���������

//�����һ����̬˳������ǣ����飩�̶���С����һ��ʵ���в�ʹ�����ַ�ʽ

/*

typedef int SLDateType;
#define N 10

struct SeqList
{
	SLDateType a[N];
	int size;//����size��ʾ�����������ж��ٸ���Ч����
};





void SeqListPushBack(struct SeqList* ps, SLDateType x);
void SeqListPopBack(struct SeqList* ps);
void SeqListPushFront(struct SeqList* ps, SLDateType x);
void SeqListPopFront(struct SeqList* ps);

*/



//���Ƕ�̬���ݱ���С�ɱ䣩

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a ;//ָ��̬���ٵ�����
	int size;//����size��ʾ�����������ж��ٸ���Ч����
	int capacity; //���������Ĵ�С
}SL,SeqList;


void SeqListInit(SL* s);//�ṹ��ĳ�ʼ��


void SeqListPushBack(SL* ps, SLDateType x);//β��

void SeqListPopBack(SL* ps);               //βɾ     

void SeqListPushFront(SL* ps, SLDateType x);//ͷ��

void SeqListPopFront(SL* ps);               //ͷɾ

void SeqListInsert(SL* ps,int pos, SLDateType x);//����λ�ò���

void SeqListErase(SL* ps, int pos);//����λ��ɾ��

void SeqListPrint(SL* ps);//��ӡ����