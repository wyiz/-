#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)



//��Ŀ1
//����һ������nums��һ��ֵval������Ҫԭ���Ƴ������������val��Ԫ�أ��������Ƴ���������³���


//Ҫ��
//����Ҫʹ�ö��������ռ䣬������ʹ��O(1)����ռ䲢ԭ���޸���������
//Ԫ�ص�˳����Ըı䣬�㲻��Ҫ���������г����³��Ⱥ����Ԫ��

//ʾ����

//����nums=[3,2,2,3]  ,val = 3
//���������µĳ���2 ������nums�е�ǰ����Ԫ�ؾ�Ϊ2

/*

int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}

	}


	return dst;

}

*/



//��Ŀ2    ɾ�����������е��ظ���

//����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³���

//Ҫ��
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������飬����ʹ��O(1)����ռ�����������


//ʾ����
//��������nums = [1,1,2]
//����Ӧ�÷����³���2������ԭ����nums��ǰ����Ԫ�ر��޸�Ϊ1,2


//˼·������3�������ֱ��� prev cur dst  ��prevָ�������е�һ������curָ�������еڶ����� ��dstҲָ�������е�һ��������prev��cur��ͬʱ��prev��cur�����ƶ�һλ
//dst���䣬��prev��cur��ͬʱ����prev��ֵ����dst���Դ����ơ���prevָ�����һ��������ʱcur�Ѿ�Խ�磬��ô�Ͱ�prevָ������һ��������dst
//��ôdst��ֵ����������ĳ���

int removeDuplicates(int* nums, int numsSize)
{
	int prev = 0, cur = 1, dst = 0;

	if (numsSize == 0)
	{
		return 0;
	}

	while (cur < numsSize)
	{
		if (nums[prev] != nums[cur])
		{
			nums[dst] = nums[prev];
			prev++;
			cur++;
			dst++;

		}

		else
		{
			prev++;
			cur++;
		}

	}

	nums[dst] = nums[prev];
	dst++;
	prev++;

	return dst;

}




//��Ŀ3   �ϲ�������������

//Ҫ��
//����������������nums1 ��nums2 �����㽫nums2�ϲ���nums1�У�ʹnums1��Ϊһ����������


//˵����
//1.��ʼ��nums1 ��nums2 ��Ԫ�������ֱ�Ϊm n
//2.����Լ���nums1 ���㹻�Ŀռ�������nums2 �е�Ԫ��


//ʾ����



















//��Ŀ5   ������ʽ�������ӷ�

//���ڷǸ�����X���ԣ�X��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣���磺���X = 1231
//��ô��������ʽΪ [1,2,3,1]

//�����Ǹ�����X��������ʽA������ X+K��������ʽ


//ʾ����
//���룺A = [1,2,0,0],K = 34;
//�����[1,2,3,4]
//���ͣ�1200 + 34 = 1234



int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int KSize = 0;  //����KSize ��ʾ����K������ж���λ����

	//����K = 134
	int KNum = K;
	while (KNum)
	{
		KNum /= 10;
		KSize++;
	}

	int len = ASize > KSize ? ASize  : KSize ;

	int* retArr =(int*) malloc(sizeof(int) *(len + 1) );

	int Ai = ASize - 1;//��ʾ����A�����һλ���±�

	int reti = 0;//��ʾ��i������Ľ��

	int NextNum = 0;//��ʾ���ǽ�λ

	while (len--)
	{
		int a = 0;
		if (Ai >= 0)//�����ж�����ĳ��ȱ�����K�ĳ���С
		{
			a = A[Ai];
			Ai--;
		}

		int ret = a + K % 10 + NextNum; //ret���������A�������һ����������K�����һ�����ֵĺ�
		
		K /= 10;

		if (ret > 9)
		{
			ret -= 10;
			NextNum = 1;
		}

		else
		{
			NextNum = 0;
		}

		retArr[reti] = ret;
		reti++;

	}

	if (NextNum == 1)
	{
		retArr[reti] = 1;
		reti++;
	}

	int left = 0;
	int right = reti - 1;

	while (left < right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = tmp;
		left++;
		right--; 
	}

	*returnSize = reti;

	return retArr;

}