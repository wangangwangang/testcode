/*
  ================================================================
  =
  =
  =   文件名称：2_两数相加.c
  =   创 建 者：Ang Wang  
  =   创建日期：2020年11月30日
  =   描    述：
  =
  ===============================================================
*/


#include <stdio.h>

typedef struct list
{
	int data;
	struct list * next;
}LIST,PLIST;

PLIST twoSum(PLIST l1,PLIST l2)
{
	PLIST pl1=l1,pl2=l2,pl3=NULL;

	
}

int main()
{
	int num1,num2;
	PLIST head1=NULL,head2=NULL,returnHead=NULL;	
	PLIST pl1=NULL,pl2=NULL,pl3=NULL;
	PLIST plist=NULL;

	printf("please input num1 and num2:");
	scanf("%d%d",&num1,&num2);

	while(num1)
	{
		plist=(PLIST)malloc(sizeof(LIST));
		plist->data=num1%10;
		plist->next=NULL:
		if(head1==NULL)
		{
			head1=plist;
			pl1=plist;
		}
		else
		{
			pl1->next=plist;
			pl1=plist;
		}

		num1=num1/10;
	}

	while(num2)
	{
		plist=(PLIST)malloc(sizeof(LIST));
		plist->data=num2%10;
		plist->next=NULL;
		if(head2==NULL)
		{
			head2=plist;
			pl2=plist;
		}
		else
		{
			pl2->next=plist;
			pl2=plist;
		}

		num2=num2/10;
	}

	returnHead=twoSum(head1,head2);
	
	pl3=returnHead;
	while(pl3)
	{
		printf("%d ",pl3->data);
		pl3=pl3->next;
	}

	return 0;

}
