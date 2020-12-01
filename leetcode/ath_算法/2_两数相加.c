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
#include <stdlib.h>

typedef struct list
{
	int val;
	struct list * next;
}LIST,*PLIST;

PLIST addTwoNumbers(PLIST l1,PLIST l2)
{
	PLIST head=NULL;
	PLIST plist=NULL;
	PLIST p=NULL;
	PLIST llong=NULL;
	int sum=0;
	int count=0;

	for(;l1&&l2;l1=l1->next,l2=l2->next)
	{
		sum=l1->val+l2->val+count;

		if(sum>9)
		{
			sum=sum-10;
			count=1;
		}
		else
			count=0;

		plist=(PLIST)malloc(sizeof(LIST));
		plist->next=NULL;
		plist->val=sum;

		if(head==NULL)
		{
			head=plist;
			p=plist;
		}
		else
		{
			p->next=plist;
			p=plist;
		}
	}

	llong=l1?l1:l2;
	for(;llong;llong=llong->next)
	{
		sum=llong->val+count;

		if(sum>9)
		{
			sum=sum-10;
			count=1;
		}
		else
			count=0;

		plist=(PLIST)malloc(sizeof(LIST));
		plist->next=NULL;
		plist->val=sum;

		p->next=plist;
		p=plist;
	}

	if(count)
	{
		plist=(PLIST)malloc(sizeof(LIST));
		plist->next=NULL;
		plist->val=1;

		p->next=plist;
		p=plist;
	}

	return head;
}

int main()
{
	int num1,num2;
	PLIST head1=NULL,head2=NULL,returnHead=NULL;	
	PLIST p1=NULL,p2=NULL,p3=NULL;
	PLIST plist=NULL;

	printf("please input num1 and num2:");
	scanf("%d%d",&num1,&num2);

	for(;num1;num1/=10)
	{
		plist=(PLIST)malloc(sizeof(LIST));
		plist->val=num1%10;
		plist->next=NULL;
		
		//无头节点后插法
		if(head1==NULL)
		{
			head1=plist;
			p1=plist;
		}
		else
		{
			p1->next=plist;
			p1=plist;
		}
	}

	while(;num2;num2/=10)
	{
		plist=(PLIST)malloc(sizeof(LIST));
		plist->val=num2%10;
		plist->next=NULL;
		
		if(head2==NULL)
		{
			head2=plist;
			p2=plist;
		}
		else
		{
			p2->next=plist;
			p2=plist;
		}
	}

	returnHead=addTwoNumbers(head1,head2);
	
	p3=returnHead;
	while(p3)
	{
		printf("%d ",p3->val);
		p3=p3->next;
	}

	return 0;
}
