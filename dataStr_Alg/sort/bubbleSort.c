#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[]={21,25,49,25,16,8};
	int i,j,temp;
	for(i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n");
	for(j=0;j<5;j++)
		for(i=0;i<5-j;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	for(i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n");
}
