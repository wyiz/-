#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include <stdlib.h>


//题目1 ：移除链表元素

//删除链表中等于给定值val的所有节点

//示例：
//输入：1->2->6->3->4->5->6  val = 6
//输出：1->2->3->4->5


//思路：


struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL, * cur = head;

	while (cur)
	{
		if (cur->val == val)
		{

			//这里是判断如果第一个数就是要删除的值，这样的话，head 的指向就会发生改变
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;  //上面cur已经释放掉了，然后把head赋值给cur，那么cur就往后走了

			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
			
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}


	return head;

}












//题目2 翻转链表

//翻转一个单链表

//示例：
//输入：1->2->3->4->5->NULL
//输出：5->4->3->2->1->NULL


//方法1 逆置法

//思路：
// 三个指针翻转：即把n2的next指向n1,然后把n2给到n1，n3 给到n2，n3=n3的next，然后进行循环迭代
// 
// 就是把1->2的改变为2->1的，那就需要再创建3个节点，第一个节点（n1）初始值设为NULL，第二个节点（n2）设置为head ，第三个节点（n3）设置为head->next
//为什么创建3个节点：因为当第一个节点指向为NULL，n2指向head，把n2的next指向n1那么，就实现了1->NULL,而此时，n2与n3之间就断开了联系，如果让n1和n2往后走时，n2找不到n3,
//所以才再创建一个n3来保存n2后面的数据

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* n1 = NULL, * n2 = head, * n3 = head->next;

	while (n2)
	{
		//翻转
		n2->next = n1;

		//迭代
		n1 = n2;
		n2 = n3;
		if(n3)
		n3 = n3->next;

	}

	return n1;
}




//方法2  头插法

//思路：新创建一个节点，首先这个节点指向NULL , 将上面的 1-> 2->... 拷贝下来进行头插，得到的就是逆置的结果


struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* cur = head;
	struct ListNode* next = head->next;
	struct ListNode* newhead = NULL;

	while (cur)
	{
		cur->next = newhead;
		newhead = cur;

		cur = next;
		if(next)
		next = next->next;



	}

	return newhead;



}





//题目3  链表的中间节点

//给定一个头节点为head的费控单链表，返回链表的中间节点。如果有两个中间节点，则返回第二个中间节点

//示例：
//输入： [1,2,3,4,5]
//输出：此链表中的节点3 ，返回的节点值为3

//注意：我们返回了一个ListNode类型的对象ans，这样：ans.val = 3，ans.next.val = 4


//示例2
//输入：[1,2,3,4,5,6]
//输出：此链表中的节点4，返回的节点的值为4

//思路：使用快慢指针，即快指针一次走两步，慢指针一次走一步，那么快指针走完时，慢指针刚好走到中间


struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}


	return slow;


}





//题目4  输入一个链表，输出该链表中倒数第 k 个节点

//示例：

//输入： 1 [1,2,3,4,5]
//输出：[5]

//思路：先让fast指针走k步，然后fast与slow一起走，当fast= NULL时，那么slow指向的就是倒数第k个
//因为fast和slow之间的间隔是k

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	struct ListNode* slow = pListHead;
	struct ListNode* fast = pListHead;

	//先让fast走k步，让fast与slow间隔是k
	while (k--)  //这里k的值可能存在大于链表的长度的情况
	{
		if (fast)
		{
			fast = fast->next;
		}
		else
			return NULL;
		
	}


	//然后让fast与slow一起走，当fast = NULL时，slow指向的就是倒数第k个节点
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;

}










//题目5  合并两个有序链表

//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的

//示例

//输入：1->2->4 ,  1->3->4
//输出：1->1->2->3->4->4


//思路：用两个指针，分别指向两个链表的头结点，然后比较两个节点的值，把较小的节点拿下来尾插


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	//1.这里是取一个较小的值放在head中,方便进行尾插，如果head = NULL，那么head->next就有问题
	if (l1->val < l2->val)
	{
		head = tail = l1;
		l1 = l1->next;

	}
	else
	{
		head = tail = l2;
		l2 = l2->next;

	}

	//2.还可以用另外的方式，就是开辟一个哨兵位的头结点，方便进行尾插，但是不存储有效数据
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode*));

	//取小的进行尾插

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	if (l1)
	{
		tail->next = l1;

	}

	else
	{
		tail->next = l2;
	}

	//1.这是方法1的返回值
	return head;

	//2.这是方法二的返回值
	struct ListNode* realHead = head->next;
	free(head);
	return realHead;

}