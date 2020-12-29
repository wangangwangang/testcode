/*
	描述：冒泡排序
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[]={21,25,49,25,16,8};
	int i,j,temp;
	
	for(i=0;i<6;i++)				//打印原数组元素
		printf("%d ",a[i]);
	printf("\n");
	
	for(j=0;j<5;j++)				//第一层循环约定需要确定几个位置
		for(i=0;i<5-j;i++)			//第二层循环约定确定哪个位置
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	
	for(i=0;i<6;i++)				//打印排序后数组元素
		printf("%d ",a[i]);
	printf("\n");

}
