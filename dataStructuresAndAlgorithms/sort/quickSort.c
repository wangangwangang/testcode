#include <stdio.h>
#include <stdlib.h>

int partion(int *l,int low,int high)
{
	int temp;
	temp=l[low];
	while(low<high)
	{
		while(low<high&&l[high]>=temp)
			high--;
		l[low]=l[high];
		while(low<high&&l[low]<=temp)
			low++;
		l[high]=l[low];
	}
	l[low]=temp;
	return low;
}

void sort(int *a,int low,int high)
{
	int keyword;
	if(low<high)
	{
		keyword=partion(a,low,high);
		sort(a,low,keyword-1);
		sort(a,keyword+1,high);
	}
}

int main()
{
	int a[]={6,5,4,3,2,1};
	int i;
	printf("before sort:\n");
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		printf("%-5d",a[i]);
	printf("\n");
	sort(a,0,sizeof(a)/sizeof(a[0])-1);
		printf("after sort:\n");
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		printf("%-5d",a[i]);
	printf("\n");
	return 0;
}
