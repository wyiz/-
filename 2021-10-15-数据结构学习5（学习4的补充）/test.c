#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)


//2.˳���

//2.1 ����ṹ��
      //˳�����һ�������ַ�����Ĵ洢��Ԫ���δ洢����Ԫ�ص����Խṹ��һ������²�������洢����������������ݵ���ɾ���

//˳���һ����Է�Ϊ��
//1.��̬˳���ʹ�ö�������洢
//2.��̬˳���ʹ�ö�̬���ٵ�����洢


#include "SeqList.h"

//����ͷβ�Ĳ���ɾ��

void TestSeqList1()
{
    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    SeqListPushBack(&s, 6);
    SeqListPushBack(&s, 7);
    SeqListPushBack(&s, 8);
    SeqListPushBack(&s, 9);        
    SeqListPrint(&s);

    SeqListPopBack(&s);
    SeqListPrint(&s);

    //SeqListPushFront(&s,-1);
    //SeqListPushFront(&s, -2);
    //SeqListPrint(&s);

    //SeqListPopFront(&s);
    //SeqListPrint(&s);

    SeqListInsert(&s,4,0);
    SeqListPrint(&s);

    SeqListErase(&s,3);
    SeqListPrint(&s);


}


int main()
{
    TestSeqList1();



    return 0;
}
