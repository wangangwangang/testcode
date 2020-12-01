/*
  ================================================================
  =
  =
  =   文件名称：1_两数之和.c
  =   创 建 者：Ang Wang  
  =   创建日期：2020年11月30日
  =   描    述:
  =
  ===============================================================
*/


#include <stdio.h>

int twoSum(int *nums,int numsSize,int target,int *result)
{
	int i,j;

	for(i=0;i<numsSize-1;i++)
	{
		for(j=i+1;j<numsSize;j++)
			{
				if(nums[i]+nums[j]==target)
				{
					result[0]=i;
					result[1]=j;
					return 1;
				}
				else
					continue;
			}
	}

	printf("the target error\n");
	return 0;

}

int main()
{
	int i;
	int nums[10];
	int numsSize;
	int target;
	int result[2];

	printf("please input numsSize:");
	scanf("%d",&numsSize);

	for(i=0;i<numsSize;i++)
	{
		printf("请输入第%d个数字：",i+1);
		scanf("%d",&nums[i]);
	}
	
    printf("please input target:");
	scanf("%d",&target);

	twoSum(nums,numsSize,target,result);

	printf("所求下标为:[%d],[%d]\n",result[0],result[1]);

	return 0;
	
}
