//0是偶数

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int n;

	while(1)
	{
		system("clear");
		printf("input(0退出):");
		scanf("%d",&n);

		if(n%2==0)
		{
			if(n==0)
			{
				printf("%d为偶数\n",n);
				sleep(2);
				return 0;
			}
			printf("%d为偶数，任意键继续\n",n);
			setbuf(stdin,NULL);
			getchar();
		}
		else
		{
			printf("%d为奇数，任意键继续\n",n);
			setbuf(stdin,NULL);
			getchar();
		}



	}
}
