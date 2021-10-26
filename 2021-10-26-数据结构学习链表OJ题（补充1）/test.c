#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)



//题目1
//给你一个数组nums和一个值val，你需要原地移除所有数组等于val的元素，并返回移除后数组的新长度


//要求：
//不需要使用额外的数组空间，你必须仅使用O(1)额外空间并原地修改输入数组
//元素的顺序可以改变，你不需要考虑数组中超出新长度后面的元素

//示例：

//给定nums=[3,2,2,3]  ,val = 3
//函数返回新的长度2 ，并且nums中的前两个元素均为2

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



//题目2    删除排序数组中的重复项

//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度

//要求：
//不要使用额外的数组空间，你必须在原地修改输入数组，并在使用O(1)额外空间的条件下完成


//示例：
//给定数组nums = [1,1,2]
//函数应该返回新长度2，并且原数组nums的前两个元素被修改为1,2


//思路：定义3个数，分别是 prev cur dst  ，prev指向数组中第一个数，cur指向数组中第二个数 ，dst也指向数组中第一个数，当prev和cur相同时，prev和cur往后移动一位
//dst不变，当prev和cur不同时，把prev的值给到dst，以此类推。当prev指向最后一个数，此时cur已经越界，那么就把prev指向的最后一个数给到dst
//那么dst的值就是新数组的长度

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




//题目3   合并两个有序数组

//要求：
//给你两个有序数组nums1 和nums2 ，请你将nums2合并到nums1中，使nums1成为一个有序数组


//说明：
//1.初始化nums1 和nums2 的元素数量分别为m n
//2.你可以假设nums1 有足够的空间来保存nums2 中的元素


//示例：



















//题目5   数组形式的整数加法

//对于非负整数X而言，X的数组形式是每位数字按从左到右的顺序形成的数组。例如：如果X = 1231
//那么其数组形式为 [1,2,3,1]

//给定非负整数X的数组形式A，返回 X+K的数组形式


//示例：
//输入：A = [1,2,0,0],K = 34;
//输出：[1,2,3,4]
//解释：1200 + 34 = 1234



int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int KSize = 0;  //这里KSize 表示的是K这个数有多少位数字

	//假设K = 134
	int KNum = K;
	while (KNum)
	{
		KNum /= 10;
		KSize++;
	}

	int len = ASize > KSize ? ASize  : KSize ;

	int* retArr =(int*) malloc(sizeof(int) *(len + 1) );

	int Ai = ASize - 1;//表示数组A的最后一位的下标

	int reti = 0;//表示第i个计算的结果

	int NextNum = 0;//表示的是进位

	while (len--)
	{
		int a = 0;
		if (Ai >= 0)//这是判断数组的长度比数字K的长度小
		{
			a = A[Ai];
			Ai--;
		}

		int ret = a + K % 10 + NextNum; //ret是用来存放A数组最后一个数与数字K的最后一个数字的和
		
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