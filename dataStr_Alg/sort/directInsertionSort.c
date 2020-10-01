#include <stdio.h>
#include <stdlib.h>

void sort_a(int *a,int sum)
{
	int i,j,n,temp;
	for(i=1;i<sum;i++)
	{  
	        n=a[i];
		for(j=i;j>0;j--)
		{
			if(n<a[j-1])
			{
				a[j]=a[j-1];
				a[j-1]=n;
			}
			else
			break;
		}
	}
}
int main()
{
	int a[]={1,5,2,3,8,5,7,9};
	int i,sum;
	sum=sizeof(a)/sizeof(a[0]);
	for(i=0;i<sum;i++)
		printf("%d ",a[i]);
	printf("\n");

	sort_a(a,sum);
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
