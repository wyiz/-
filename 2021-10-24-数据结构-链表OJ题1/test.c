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


//思路：定义3个数，分别是 prev cur dst  ，prev指向数组中第一个数，cur指向数组中第二个数 ，dst也指向数组中第一个数