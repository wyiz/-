#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)



       //����

//���������һ������洢�ṹ�Ϸ������ģ����߼��洢��ʱ�����ġ�����Ԫ�ص��߼�˳����ͨ�������е�ָ�����Ӵ���ʵ�ֵ�

#include "SList.h"


void testSList()
{
    SListNode* pList = NULL;//�����Ƕ�����һ��ͷָ�룬��������һ������

    SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);

    SListPrint(&pList);

    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);

    SListPrint(&pList);

    SListPushFront(&pList, 1);
    SListPushFront(&pList, 2);
    SListPushFront(&pList, 3);
    SListPushFront(&pList, 4);

    SListPrint(&pList);

    SListPopFront(&pList);

    SListPrint(&pList);



}

void testSList2()
{
    SListNode* pList = NULL;
    SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);
    SListPrint(&pList);


    SListNode* pos = SListFind(pList,3);

    if (pos != NULL)
    {
        pos->date = 30;
    }
    SListPrint(&pList);


}



int main()
{
    //testSList();

    testSList2();

    return 0;
}