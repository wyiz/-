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

//���룺
//num1 = [1,2,3,0,0,0], m = 3  //����m = 3 ��ʾ������3����Ч����
//nums2 = [2,5,6],      n = 3  //����n = 3 ��ʾ������3����Ч����

//�����
//[1,2,2,3,5,6]


//˼·��
//����һ���µĿռ䣬�����������ֱ�ָ��nums1 ��nums2���Ƚ����������н�С�ģ�Ȼ��ŵ����ٵ�������
//��һ����������ʱ���Ͱ�����һ��������ʣ�µ��������ݶ����������ٵ�������
//Ȼ��ѿ��ٵ������е�Ԫ���ٿ�����nums1��
//�����Ļ���ʱ�临�Ӷ�ΪO(m+n)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int* tmp= (int*)malloc(sizeof(int) * (m + m));

	int i1 = 0, i2 = 0;
	int i = 0;
	while (i1 <m && i2< n)
	{
		if (nums1[i1] < nums2[i2])
		{
			tmp[i] = nums1[i1];
			i++;
			i1++;
		}
		else
		{
			tmp[i] = nums2[i2];
			i++;
			i2++;
		}
	}

	while (i1<m)
	{
		tmp[i] = nums1[i1];
		i++;
		i1++;
	}

	while (i2<n)
	{
		tmp[i] = nums2[i2];
		i++;
		i2++;
	}


	memcpy(nums1, tmp, sizeof(int) * (m + n));
	free(tmp);


}




//��Ŀ4  ��ת����

//����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����kΪ�Ǹ���

//����д��3�ֽ������

//ʾ����

//���룺nums = [1,2,3,4,5,6,7], k = 3
//�����[5,6,7,1,2,3,4]

//���ͣ�
//������ת1����[7,1,2,3,4,5,6]
//������ת2����[6,7,1,2,3,4,5]
//������ת3����[5,6,7,1,2,3,4]



//�Ȱ����ú�������

void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		right--;
		left++;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	//����1
	//ÿ����ת1�����������һ����ǰn-1������������Ų�������һ�����ŵ���һ��λ����ȥ
	//��תk��
	//ʱ�临�Ӷ�ΪO(N*K)

	//����һ��k����С����ʱ���飬��k����������ݷŵ����ٵ���ʱ�ռ���ȥ��Ȼ���ٰ�numsSize - k���������ƶ�
	//������ʱ�������������ݷŵ�nums������ȥ

	//ʱ�临�Ӷȣ�O(N) 

	//����3 
	//[1,2,3,4,5,6,7]  ��ǰn-k������ ����k������
	//[4,3,2,1,7,6,5]  �ٽ�����������
	//[5,6,7,1,2,3,4]

	//ʱ�临�Ӷȣ�O(N)
	//�ռ临�Ӷȣ�O(1)

	k %= numsSize;  //���������k����numsSize ������numsSize = 6  ���� k ����ȡ 13

	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);





}


















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