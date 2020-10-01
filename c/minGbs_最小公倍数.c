/*
	1.最小公倍数是同时可以整除几个数（a b  c ）的数字
	2.最小公倍数最小值为a b c中的最大值
*/

#include <stdio.h>

int main()
{
	int a,b;
	int max;

	printf("please input two numbers:");
	scanf("%d%d",&a,&b);

	max=a>b?a:b;

	while(1)
	{
		if(max%a==max%b&&max%a==0)
			break;
		else
			max++;
	}
	
	printf("%d是%d和%d的最小公倍数\n",max,a,b);
}
