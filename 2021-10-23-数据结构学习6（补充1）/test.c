#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

             //˫����

// ˫������Ҳ�������һ�֣���ÿ�����ݽ���ж���������㣬�ֱ�ָ����ֱ��ǰ����ֱ�Ӻ�̡��������Ǵ�˫�����������һ����㿪ʼ�����Ժܷ���ķ�����ǰ��Ԫ�غͺ��Ԫ�ء�
//˫����˷��˵�����ֻ����һ�������ϱ��������ơ� �����б��ÿ����㶼��������ǰ���ĵ�ַ����˿���ͨ��ʹ�ô洢��ÿ������ǰһ�����ڵ���ǰ��ַ���ҵ�����ǰһ��������ϸ�ڡ�
//��ˣ�˫�����뵥������������������ƣ�����ɾ������Ҫ�ƶ�Ԫ�أ�����ԭ�ز���ɾ��������˫�����


//˫������ص��ǣ��ṹ���ӣ�������

//�����˳������飩���������ϵ
//1.˳������������Ļ�����ʵ����ɾ��ģ����Ҳ���ʱ���Զ�̬����
//˳����ȱ�ݣ�1.���ܴ���һ���Ŀռ��˷�   2.������һЩЧ����ʧ  3.�м����ͷ������ɾ��ʱ��ʱ�临�Ӷ�ΪO(N)����ΪѽŲ������

//��Щ����������������

//�����ȱ�ݣ������������

//�����˳�����Ի���




#include "List.h"

void TestList1()
{
    //��ʽ1 �ڵ��ʼ��
   /* ListNode* phead = NULL;
    ListInit(&phead);
    */

    //��ʽ2 �ڵ��ʼ��
    ListNode* phead = ListInit();  //phead�ڵ�������ʵ����������ģ������Ǵ�����һ��phead�Ľڵ㣬phead������Ǹ����ǵ�һ���ڵ�

    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);

    ListPrint(phead);

    ListPopBack(phead);
    ListPopBack(phead);
    
    ListPrint(phead);

    ListPushFront(phead, 9);
    ListPushFront(phead, 8);

    ListPrint(phead);
    ListPopFront(phead);
    ListPopFront(phead);
    ListPrint(phead);

    ListPushFront(phead, 4);
    ListPushFront(phead, 3);
    ListPrint(phead);

    ListInsert(phead, 1, 7);
    ListPrint(phead);

    ListErase(phead,2);
    ListPrint(phead);


}



int main()
{
    TestList1();


    return 0;
}
