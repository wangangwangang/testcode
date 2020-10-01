//function:同构数,一个数,如果它出现在它的平方数的尾部,就称它为同构数,如5它们的平方是25。

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int sum=0;

	system("clear");
	printf("【实现1-100之间同构数的查找并输出同构数的个数】\n");
	for(i=1;i<=100;i++)
	{
		if(i<10)
		{
			if(i*i%10==i)
			{
				printf("(%d,%d)  ",i,i*i);
				sum++;
			}
		}
		else
		{
			if(i*i%100==i)
			{

				printf("(%d,%d)  ",i,i*i);
				sum++;

			}


		}





	}


	printf("\n同构数有%d个\n",sum);



}

