#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

             //˫����

// ˫������Ҳ�������һ�֣���ÿ�����ݽ���ж���������㣬�ֱ�ָ����ֱ��ǰ����ֱ�Ӻ�̡��������Ǵ�˫�����������һ����㿪ʼ�����Ժܷ���ķ�����ǰ��Ԫ�غͺ��Ԫ�ء�
//˫����˷��˵�����ֻ����һ�������ϱ��������ơ� �����б��ÿ����㶼��������ǰ���ĵ�ַ����˿���ͨ��ʹ�ô洢��ÿ������ǰһ�����ڵ���ǰ��ַ���ҵ�����ǰһ��������ϸ�ڡ�
//��ˣ�˫�����뵥������������������ƣ�����ɾ������Ҫ�ƶ�Ԫ�أ�����ԭ�ز���ɾ��������˫�����


//˫������ص��ǣ��ṹ���ӣ�������



#include "List.h"

void TestList1()
{
    //��ʽ1 �ڵ��ʼ��
   /* ListNode* phead = NULL;
    ListInit(&phead);
    */

    //��ʽ2 �ڵ��ʼ��
    ListNode* phead = ListInit();

    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);

    ListPrint(phead);

}



int main()
{
    TestList1();


    return 0;
}
