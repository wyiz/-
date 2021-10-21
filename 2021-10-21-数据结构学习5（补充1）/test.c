#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)



       //链表

//概念：链表是一种物理存储结构上非连续的，在逻辑存储上时连续的。数据元素的逻辑顺序是通过链表中的指针链接次序实现的

#include "SList.h"

int main()
{
    SListNode* pList = NULL;//这里是定义了一个头指针，表明这是一个链表

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