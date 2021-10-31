#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include <stdlib.h>


//��Ŀ1 ���Ƴ�����Ԫ��

//ɾ�������е��ڸ���ֵval�����нڵ�

//ʾ����
//���룺1->2->6->3->4->5->6  val = 6
//�����1->2->3->4->5


//˼·��


struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL, * cur = head;

	while (cur)
	{
		if (cur->val == val)
		{

			//�������ж������һ��������Ҫɾ����ֵ�������Ļ���head ��ָ��ͻᷢ���ı�
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;  //����cur�Ѿ��ͷŵ��ˣ�Ȼ���head��ֵ��cur����ôcur����������

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












//��Ŀ2 ��ת����

//��תһ��������

//ʾ����
//���룺1->2->3->4->5->NULL
//�����5->4->3->2->1->NULL


//����1 ���÷�

//˼·��
// ����ָ�뷭ת������n2��nextָ��n1,Ȼ���n2����n1��n3 ����n2��n3=n3��next��Ȼ�����ѭ������
// 
// ���ǰ�1->2�ĸı�Ϊ2->1�ģ��Ǿ���Ҫ�ٴ���3���ڵ㣬��һ���ڵ㣨n1����ʼֵ��ΪNULL���ڶ����ڵ㣨n2������Ϊhead ���������ڵ㣨n3������Ϊhead->next
//Ϊʲô����3���ڵ㣺��Ϊ����һ���ڵ�ָ��ΪNULL��n2ָ��head����n2��nextָ��n1��ô����ʵ����1->NULL,����ʱ��n2��n3֮��ͶϿ�����ϵ�������n1��n2������ʱ��n2�Ҳ���n3,
//���Բ��ٴ���һ��n3������n2���������

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* n1 = NULL, * n2 = head, * n3 = head->next;

	while (n2)
	{
		//��ת
		n2->next = n1;

		//����
		n1 = n2;
		n2 = n3;
		if(n3)
		n3 = n3->next;

	}

	return n1;
}




//����2  ͷ�巨

//˼·���´���һ���ڵ㣬��������ڵ�ָ��NULL , ������� 1-> 2->... ������������ͷ�壬�õ��ľ������õĽ��


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





//��Ŀ3  ������м�ڵ�

//����һ��ͷ�ڵ�Ϊhead�ķѿص���������������м�ڵ㡣����������м�ڵ㣬�򷵻صڶ����м�ڵ�

//ʾ����
//���룺 [1,2,3,4,5]
//������������еĽڵ�3 �����صĽڵ�ֵΪ3

//ע�⣺���Ƿ�����һ��ListNode���͵Ķ���ans��������ans.val = 3��ans.next.val = 4


//ʾ��2
//���룺[1,2,3,4,5,6]
//������������еĽڵ�4�����صĽڵ��ֵΪ4

//˼·��ʹ�ÿ���ָ�룬����ָ��һ������������ָ��һ����һ������ô��ָ������ʱ����ָ��պ��ߵ��м�


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





//��Ŀ4  ����һ����������������е����� k ���ڵ�

//ʾ����

//���룺 1 [1,2,3,4,5]
//�����[5]

//˼·������fastָ����k����Ȼ��fast��slowһ���ߣ���fast= NULLʱ����ôslowָ��ľ��ǵ�����k��
//��Ϊfast��slow֮��ļ����k

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	struct ListNode* slow = pListHead;
	struct ListNode* fast = pListHead;

	//����fast��k������fast��slow�����k
	while (k--)  //����k��ֵ���ܴ��ڴ�������ĳ��ȵ����
	{
		if (fast)
		{
			fast = fast->next;
		}
		else
			return NULL;
		
	}


	//Ȼ����fast��slowһ���ߣ���fast = NULLʱ��slowָ��ľ��ǵ�����k���ڵ�
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;

}










//��Ŀ5  �ϲ�������������

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�

//ʾ��

//���룺1->2->4 ,  1->3->4
//�����1->1->2->3->4->4


//˼·��������ָ�룬�ֱ�ָ�����������ͷ��㣬Ȼ��Ƚ������ڵ��ֵ���ѽ�С�Ľڵ�������β��


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	//1.������ȡһ����С��ֵ����head��,�������β�壬���head = NULL����ôhead->next��������
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

	//2.������������ķ�ʽ�����ǿ���һ���ڱ�λ��ͷ��㣬�������β�壬���ǲ��洢��Ч����
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode*));

	//ȡС�Ľ���β��

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

	//1.���Ƿ���1�ķ���ֵ
	return head;

	//2.���Ƿ������ķ���ֵ
	struct ListNode* realHead = head->next;
	free(head);
	return realHead;

}