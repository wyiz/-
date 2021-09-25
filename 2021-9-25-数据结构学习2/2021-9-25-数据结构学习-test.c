#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)



//题目：消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数

//示例1：输入 3,0,1   输出： 2
//示例2：输入 9,6,4,2,3,5,7,0，1   输出： 8


//方法1：

//思路：如题目所说，数组中有0 - n 的所有整数，但是缺少了一个，所以还剩n个数
//      那我们可以先把这0 - n的所有整数先补齐，因为缺少的数是在0 - n之间，那我们可以先生成0 - n之间的所有数，即n+1个数
// 然后将这n+1个数相加求和，最后把求和的结果减去0 -n 之间的n个数的和。得到的就是缺少的那个数
//例如示例1中，n=3,一共是4个数 0 1 2 3，先生成出来，相加得6
//然后减去 0 1 3的和，即4，
//最后得到 6 - 4 = 2 就是缺少的那个数

//思路：由于0-n是一个等差数列，可以对完整的等差数列求和。然后减去数组中的数字，减出来的结果就是缺少的数字

/*
#include <stdio.h>

int main()
{
	int arr[] = { 0,1,3 };

	int sz = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int ret = 0;
	int sum = 0;
	for (i = 0;i<sz+1;i++)
	{
		sum += i;
	}
	for (i = 0;i<sz;i++)
	{
		sum -= arr[i];
	}

	printf("%d\n",sum);

	return 0;

}

*/



//方法2

//异或具有一个特性。相同为0，相异为1.（在任何进制都适用）因此让0 - n的数字和数组内的数字全部放在一起异或。结果就是消失的数字

#include <stdio.h>

int main()
{
	int arr[] = { 9,6,4,2,3,5,7,0,1 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz + 1; i++)
	{
		ret^= i;
	}
	for (i = 0; i < sz; i++)
	{
		ret^= arr[i];
	}

	printf("%d\n", ret);

	return 0;

}
