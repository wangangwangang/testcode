#include <stdio.h>
#include <stdlib.h>
#define nstep  5
#define NUM    30

//定义增量数组
int  STEP[]={15,8,4,2,1};
//希尔排序
void shellsort(int *s,int n)
{
	int i,j,k;
	for(i=0;i<nstep;i++)
	{
		int step=STEP[i];
		for(j=0;j<step;j++)
		{
			for(k=0;k<(int)(n/step);k++)
			{
				int l,m,index=j+k*step;
				if(!k) 
					continue;
				for(l=0;l<k;l++)
				{
					int index2=j+l*step;
					if(s[index]<s[index2])
						break;
				}
				if(l>=k)
					continue;
				else 
				{
					int temp=s[index];
					m=k;
					while(m>l)
					{
						s[j+m*step]=s[j+(m-1)*step];
						m--;
					}
					s[j+l*step]=temp;
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
