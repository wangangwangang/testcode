#include <stdio.h>
#include <stdlib.h>
#define nstep  5
#define NUM    30

//定义增量数组
int  STEP[]={15,8,4,2,1};
//希尔排序
void shellsort(int *a,int n)
{
	int i;
	for(i=0;i<nstep;i++)
	{
		int step=STEP[i];
		int j;
		for(j=0;j<step;j++)
		{
			int m,temp;
			for(m=j+step;m<n;m+=step)
			{
				temp=a[m];
				int  k;
				for(k=m-step;k>=j;k-=step)
				{
					if(temp<a[k])
					{
						a[k+step]=a[k];
						a[k]=temp;
						break;
					}
				}
			}
		}
	}

}

int  main()
{
	int a[]={23,-56,34,78,9,-2,56,789,38,4,679,-567,0,345,93,68,39,-467,64,798,324,7,35,-765,78,546,84,547,-6};
	int i;
	printf("before sort:\n");
	for(i=0;i<NUM;i++)
	{
		printf("%-5d",a[i]);
	}
	printf("\n");
	shellsort(a,sizeof(a)/sizeof(a[0]));

	printf("after sort:\n");
	for(i=0;i<NUM;i++)
	{
		printf("%-5d",a[i]);
	}
	printf("\n");
}
