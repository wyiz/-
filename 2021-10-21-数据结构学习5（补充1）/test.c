#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)



       //����

//���������һ������洢�ṹ�Ϸ������ģ����߼��洢��ʱ�����ġ�����Ԫ�ص��߼�˳����ͨ�������е�ָ�����Ӵ���ʵ�ֵ�

#include "SList.h"

int main()
{
    SListNode* pList = NULL;//�����Ƕ�����һ��ͷָ�룬��������һ������

    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,3);

    SListPrint(&pList);

    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);

    SListPrint(&pList);



    return 0;
}