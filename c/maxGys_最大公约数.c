/*
   	1.最大公约数，就是同时能被两个数（a b）整除的数字
	2.最大公约数最大为a b 中的最小值
 */
#include <stdio.h>

int main()
{
	int x,y,i;
	printf("实现求出两个正整数的最大公约数:");
	scanf("%d%d",&x,&y);
	i=x<y?x:y;
	while(i>=1)
	{
		if(x%i==y%i&&x%i==0)
		{
			printf("%d是%d与%d的最大公约数\n",i,x,y);
			break;
		}
		else
			i--;


	}
}
