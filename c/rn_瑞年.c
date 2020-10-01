//added by wanga 20200930
/*
   瑞年条件：
            1.可以被4整除，不可以被100整除
	    2.可以被100整除，但是也可以被400整除
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int year;

	while(1)
	{
		
		system("clear");
		printf("请输入一个年份(0退出):");
		scanf("%d",&year);

		if(year==0)
			return 0;

		if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
		{
			printf("%d是瑞年,任意键继续\n",year);
			setbuf(stdin,NULL);
			getchar();
		}
		else
		{
			printf("%d不是瑞年,任意键继续\n",year);
			setbuf(stdin,NULL);
			getchar();
		}

	}
}
