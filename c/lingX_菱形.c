#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int i,j;
	while(1)
	{
		system("clear");
		printf("---------------N阶菱形----------------\n");
		printf("请输入阶数N(N为奇数,按0结束):");
		while(!scanf("%d",&n)||(n%2)==0)
		{
			if(n==0)
				return 0;
			system("clear");
			printf("---------------N阶菱形----------------\n");
			printf("请输入阶数N(N为奇数,按0结束):");
			setbuf(stdin,NULL);
		}

		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i>=1&&i<=(n+1)/2)
				{
					if(j>=(n+1)/2-(i-1)&&j<=(n+1)/2+(i-1))
						printf("*");
					else
						printf(" ");
				}
				if(i>(n+1)/2&&i<=n)
				{
					if(j>=(n+1)/2-(n-i)&&j<=(n+1)/2+(n-i))
						printf("*");
					else
						printf(" ");
				} 

			}

			printf("\n");
		}




		printf("打印成功，任意键继续\n");
		setbuf(stdin,NULL);
		getchar();
	}



}

