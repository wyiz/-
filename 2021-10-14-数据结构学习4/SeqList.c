#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)*4);



		if (ps->a == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�");
			exit(-1);
		}

		ps->size = 0;
		ps->capacity = 4;//�����4��4�����ݵ���˼�������ֽ����������Ҫ�������*4��Ӧ

}


//β��
void SeqListPushBack(SL* ps, SLDateType x)
{
	assert(ps);

	//��������Ҫ�жϿռ��Ƿ����ˣ�������˾���Ҫ����

	if (ps->size >= ps->capacity)
	{
		//�������ݵĴ�С��һ������2��
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a,sizeof(SLDateType)*ps->capacity);

		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}


	ps->a[ps->size] = x;
	ps->size++;
}


void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0;i<ps->size;i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}



//βɾ  

void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}


//ͷ��

void SeqListPushFront(SL* ps, SLDateType x)
{
	//Ҫ����ͷ������һ�����ݣ���Ҫ��ǰ���size������������
	//�����Ƶİ취�ǣ��Ȱ����һ�������ƣ�Ȼ�������ΰ�size--������������


}

void SeqListPopFront(SL* ps);               //ͷɾ

void SeqListInsert(SL* ps, int pos, SLDateType x);//����λ�ò���

void SeqListErase(SL* ps, int pos);//����λ��ɾ��