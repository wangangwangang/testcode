#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int i,j;
	while(1)
	{
		system("clear");
		printf("---------------N阶金字塔-----------------\n");
		printf("请输入阶数N(按0结束):");
		scanf("%d",&n);
		if(n==0)
			break;
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=2*n-1;j++)
			{
				if(j>=n-(i-1)&&j<=n+(i-1))
					printf("%d",i);
				else 
					printf(" ");
			}
			printf("\n");
		}
		printf("打印成功，任意键继续\n");
		setbuf(stdin,NULL);
		getchar();
	}

	return 0;

}
