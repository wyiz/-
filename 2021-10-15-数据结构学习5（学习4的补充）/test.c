#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)


//2.顺序表：

//2.1 概念及结构：
      //顺序表是一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。在数组上完成数据的增删查改

//顺序表一般可以分为：
//1.静态顺序表：使用定长数组存储
//2.动态顺序表：使用动态开辟的数组存储


#include "SeqList.h"

//测试头尾的插入删除

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
