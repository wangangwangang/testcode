#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;		//输入变量
	int q;		//圈数
	int i;	        //圈数循环变量
	int a;		//边长循环变量
	int b[10][10];	//二维数组用于构建整个坐标体系

	while(1)
	{
		int x=0;	//行数控制，一维变量
		int y=0;	//列数控制，二维变量
		int s=1;	//元素值
		system("clear");
		printf("请输入一个不大于10的正整数(0结束):");
		scanf("%d",&n);

		if(n==0)
			return 0;

		if(n%2==0)
			q=n/2;
		else
			q=(n+1)/2;

		for(i=1;i<=q;i++)
		{
			for(a=1;a<=n-2*(i-1);a++,y++)
				b[x][y]=s++;
			y--;
			x++;
			for(a=1;a<=n-2*(i-1)-1;a++,x++)
				b[x][y]=s++;
			x--;
			y--;
			for(a=1;a<=n-2*(i-1)-1;a++,y--)
				b[x][y]=s++;
			y++;
			x--;
			for(a=1;a<=n-2*(i-1)-2;a++,x--)
				b[x][y]=s++;
			y++;
			x++;
		}
		for(x=0;x<n;x++)
		{
			for(y=0;y<n;y++)
				printf("%d\t",b[x][y]);
			printf("\n");
		}

		printf("打印成功，任意键继续：");
		setbuf(stdin,NULL);
		getchar();

	}
}

