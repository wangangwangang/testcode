#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int num;
	struct student *prev;
	struct student *next;
}STU,*PSTU;

void creat_link(PSTU *ps);
void print_link(PSTU ps);
PSTU judge_link(PSTU ps,int i);
void search_link(PSTU ps);
void insert_link(PSTU *ps);
void del_link(PSTU ps);

int main()
{
	PSTU head=malloc(sizeof(STU));
	head->next=NULL;
	head->prev=NULL;
	creat_link(&head);
	print_link(head);
//	search_link(head);
//	insert_link(&head);
//	del_link(&head);
	return 0;
}

//创建双向链表
void creat_link(PSTU *ps)
{
	system("clear");
	printf("*************欢迎来到学生信息添加界面*******************\n");
  	STU *p=*ps;
	int i;
	printf("输入学生学号:");
	scanf("%d",&i);
	while(i>0)
	{
		PSTU stu=malloc(sizeof(STU));
		stu->num=i;
		stu->next=NULL;
		while(p->next!=NULL)
			p=p->next;
		p->next=stu;
		stu->prev=p;
		printf("输入学生学号:");
		scanf("%d",&i);
	}
	printf("信息录入成功，按空格继续\n");
	setbuf(stdin,NULL);
	getchar();
}

//打印双向链表
void print_link(PSTU ps)
{
	system("clear");
	printf("*************欢迎来到学生信息打印界面*******************\n");
	STU *p=ps;
        //正向打印
         while(p->next!=NULL)
	 {
	  printf("%d ",p->next->num);
          p=p->next;
	 }
	 printf("\n");
	//反向打印
        while(p->prev!=NULL)
	{
	  printf("%d ",p->num);
	  p=p->prev;
	}
	printf("\n");
	printf("信息打印成功，按空格继续\n");
	setbuf(stdin,NULL);
	getchar();
}



























