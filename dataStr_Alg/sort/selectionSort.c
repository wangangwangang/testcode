#include <stdio.h>

void choose_sort(int *a,int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(a[k]>a[j])
				k=j;
		if(k!=i)
		{
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}

}

int main()
{
	int a[10]={23,2,556,45,89,45,56,34,7,92};
	int i;
	printf("before sort:\n");
	for(i=0;i<10;i++)
	{
		printf("%-5d",a[i]);
	}
	printf("\n");
	choose_sort(a,sizeof(a)/sizeof(a[0]));
	printf("after sort:\n");
	for(i=0;i<10;i++)
	{
		printf("%-5d",a[i]);
	}
	printf("\n");

}
