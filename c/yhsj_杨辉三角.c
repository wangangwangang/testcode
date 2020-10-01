#include <stdio.h>

int main()
{
	int n,i,j,a[100][100];
	printf("请输入一个正整数:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
		{
			if(j==0||j==i)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}
