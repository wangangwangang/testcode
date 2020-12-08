/*
  ================================================================
  =
  =
  =   文件名称：7_整数反转.c
  =   创 建 者：Ang Wang  
  =   创建日期：2020年12月08日
  =   描    述：
  =
  ===============================================================
*/


#include <stdio.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x)
{
	int pop=0;
	int rev=0;

	while(x)
	{
		pop=x%10;
		
		if(rev>INT_MAX/10||(rev==INT_MAX/10&&pop>7))
			return 0;
		if(rev<INT_MIN/10||(rev==INT_MIN/10&&pop<-8))
			return 0;
		
		rev=rev*10+pop;
		x=x/10;
	}

	return rev;
}

int main()
{
	int x=0;
	int rev=0;

	printf("please input x:");
	scanf("%d",&x);

	rev=reverse(x);

	printf("rev=%d\n",rev);

}
