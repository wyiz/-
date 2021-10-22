#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDateType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDateType date;

}ListNode;


//尾插
void ListPushBack(ListNode* phead,LTDateType x);

//创建新的节点函数
ListNode* BuyListNode(LTDateType x);


//双链表打印函数
void ListPrint(ListNode* phead);

//初始化函数
// 方式1：传过来的是phead的地址，解引用之后就能对phead进行修改，这样在ListIit函数中创建一个新的节点之后，phead里面存的就是创建的节点的地址
//void ListInit(ListNode** pphead);

//方式2：传过来的是phead，然后返回一个值，将返回值带入到phead中也是可以的

ListNode* ListInit();

