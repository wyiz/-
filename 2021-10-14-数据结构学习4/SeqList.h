#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//顺序表，有效数据在数组中必须是连续的

/*
struct SeqList
{
	int a[10];
	int size;//这里size表示的是数组中有多少个有效数据
};

*/

//上述代码存在一定的问题，就是这个结构体里面数组的类型是int，假如说后续类型需要修改为double类型了，那么里面的类型就需要更改为double，那么下面函数里面的增删查改传递过去的类型都需要修改
//这时候就非常麻烦

//这时就需要使用typedef来解决，即把类型进行重命名

//这就是一个静态顺序表（就是（数组）固定大小），一般实际中不使用这种方式

/*

typedef int SLDateType;
#define N 10

struct SeqList
{
	SLDateType a[N];
	int size;//这里size表示的是数组中有多少个有效数据
};





void SeqListPushBack(struct SeqList* ps, SLDateType x);
void SeqListPopBack(struct SeqList* ps);
void SeqListPushFront(struct SeqList* ps, SLDateType x);
void SeqListPopFront(struct SeqList* ps);

*/



//这是动态数据表（大小可变）

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a ;//指向动态开辟的数组
	int size;//这里size表示的是数组中有多少个有效数据
	int capacity; //数组容量的大小
}SL,SeqList;


void SeqListInit(SL* s);//结构体的初始化


void SeqListPushBack(SL* ps, SLDateType x);//尾插

void SeqListPopBack(SL* ps);               //尾删     

void SeqListPushFront(SL* ps, SLDateType x);//头插

void SeqListPopFront(SL* ps);               //头删

void SeqListInsert(SL* ps,int pos, SLDateType x);//任意位置插入

void SeqListErase(SL* ps, int pos);//任意位置删除

void SeqListPrint(SL* ps);//打印函数