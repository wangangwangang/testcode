#include <stdio.h>
#include <stdlib.h>

int parter(int *a,int low,int high)
{
  int temp;
  temp=a[low];
  while(low<high)
  {
   while(low<high&&a[high]>=temp)
      high--;
      a[low]=a[high];
   while(low<high&&a[low]<=temp)
      low++;
      a[high]=a[low];
  }
  a[low]=temp;
  return low;
}

void sort(int *a,int low,int high)
{
 int keyword;
 if(low<high)
   { 
     keyword=parter(a,low,high);
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
 printf("before sort:\n");
 for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
   printf("%-5d",a[i]);
  printf("\n");
  return 0;
}
