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
	SeqListCheckCapacity(ps);
	

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
	SeqListCheckCapacity(ps);

	//Ҫ����ͷ������һ�����ݣ���Ҫ��ǰ���size������������
	//�����Ƶİ취�ǣ��Ȱ����һ�������ƣ�Ȼ�������ΰ�size--������������

	int end = ps->size - 1;
	while (end >=0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	//�ѵ�һ�����������޸�Ϊ���������
	ps->a[0] = x;
	ps->size++;

}

void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		//�������ݵĴ�С��һ������2��
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);

		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}

}


//ͷɾ

void SeqListPopFront(SL* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;

	}

	ps->size--;

}

//����λ�ò���

void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);


	int y = ps->size - 1;
	
	if (pos <= ps->size - 1)
	{
		for (int i = 0; i <= ps->size - 1 - pos; i++)
		{

			ps->a[y + 1] = ps->a[y];
			y--;


		}

		ps->a[pos] = x;
		ps->size++;
	}

	else
	{
		ps->a[ps->size] = x;
		ps->size++;
	}

	

}

//����λ��ɾ��

void SeqListErase(SL* ps, int pos)
{
	assert(ps);

	int m = pos;

	if (pos<=ps->size-1)
	{

		for (int i = 0; i <= ps->size - 1 - pos; i++)
		{
			ps->a[m] = ps->a[m + 1];
			m++;
		}
		ps->size--;
	}


}