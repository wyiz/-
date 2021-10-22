#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef int SListDateType;

//链表的形式其实一段空间，前面部分存储的是数据，后面存储的是下一个链表的地址，即指针，指向下一个结构体
typedef struct SListNode
{
	SListDateType date;
	struct SListNode* next;//这个存放的是下一个数据的地址，存放地址应该指针，下一个数据类型也是结构体类型的，所以用struct SListNode*
}SListNode;


//尾插
void SListPushBack(SListNode** pphead,SListDateType x);

//尾删
void SListPopBack(SListNode** pphead);

//头插
void SListPushFront(SListNode** pphead,SListDateType x);

//头删
void SListPopFront(SListNode** pphead);


//打印函数
//遍历打印链表

void SListPrint(SListNode** pphead);


//查找链表

SListNode* SListFind(SListNode* phead, SListDateType x);


