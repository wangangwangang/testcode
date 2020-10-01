#include <stdio.h>
#include <stdlib.h>
//结构体定义
typedef struct student 
{
	int num;
	struct student *next;
}STU,*PSTU;

//函数声明
void creat_link(PSTU head);              //增加带有头节点的链表，后插法
void print_link(PSTU head);              //打印一个链表
PSTU search_link(PSTU head);             //查询链表
void afterinsert_link(PSTU head);        //后插法插入节点
void del_link(PSTU head);                //删除节点

//主函数
int main()
{
	PSTU head=malloc(sizeof(STU));    //定义一个头指针指向头节点 
	head->next=NULL;
	creat_link(head);                //增加带有头节点的链表，后插法
	print_link(head);                //打印一个链表
	search_link(head);               //查询链表
	afterinsert_link(head);          //后插法插入节点
	del_link(head);                  //删除节点

}
//增加带有头节点的链表，后插法
void creat_link(PSTU head)
{
	system("clear");
	printf("************欢迎来到学生信息添加界面**************\n");
	STU *ps=head;
	int i;
	printf("请输入学生的学号:");
	scanf("%d",&i);
	while(i>0)
	{
		PSTU pstu=malloc(sizeof(STU));
		pstu->num=i;
		pstu->next=NULL;
		while(ps->next!=NULL)
			ps=ps->next;
		ps->next=pstu;
		printf("请输入学生的学号:");
		setbuf(stdin,NULL);
		scanf("%d",&i);
	}
	printf("输入信息成功,按空格键继续");
	setbuf(stdin,NULL);
	getchar();
} 

//打印链表元素
void print_link(PSTU head)
{
	system("clear");
	printf("************欢迎来到学生打印界面**************\n");
	STU *ps=head;
	while(ps->next!=NULL)
	{
		printf("%d ",ps->next->num);
		ps=ps->next;
	}
	printf("\n");
	printf("打印信息成功,按空格键继续");
	setbuf(stdin,NULL);
	getchar();
}

//查询链表元素,并返回查询节点的指针
PSTU search_link(PSTU head)
{
	system("clear");
	printf("************欢迎来到学生信息查询界面**************\n");
	STU *ps=head;
	int i;
	printf("请输入需要查询的学号:");
	scanf("%d",&i);
	while(ps->next!=NULL)
	{
		if(ps->next->num==i)
		{
			printf("学号为%d的学生存在,按空格键继续",ps->next->num);
			setbuf(stdin,NULL);
			getchar();
			return ps->next;
		}
		ps=ps->next;
	}
	if(ps->next==NULL)
	{
		printf("学号为%d的学生不存在,按空格键继续",ps->next->num);
		setbuf(stdin,NULL);
		getchar();
		return NULL;
	}
}

//插入链表
void afterinsert_link(PSTU head)
{
	system("clear");
	printf("************欢迎来到学生信息插入界面**************\n");
	STU *ps=head;
	printf("空格键查询插入地点是否存在");
	setbuf(stdin,NULL);
	getchar();
	PSTU ptr=search_link(head);
	if(ptr!=NULL)
	{
		int i;
		printf("请输入需要插入的学号:");
		scanf("%d",&i);
		PSTU pstu=malloc(sizeof(STU));
		pstu->num=i;
		pstu->next=ptr->next;
		ptr->next=pstu;
		print_link(head);
		printf("插入成功，按空格继续");
		setbuf(stdin,NULL);
		getchar();
	}
}


//删除链表
void del_link(PSTU head)
{
	system("clear");
	printf("************欢迎来到学生信息插入界面**************\n");
	STU *ps=head;
	printf("空格键查询插入地点是否存在");
	setbuf(stdin,NULL);
	getchar();
	PSTU ptr=search_link(head);
	if(ptr!=NULL)
	{
	        PSTU bptr=head;
		while(bptr->next!=ptr)
		      bptr=bptr->next;
		bptr->next=ptr->next;
		free(ptr);
		print_link(head);
		printf("删除成功，按空格继续");
		setbuf(stdin,NULL);
		getchar();
	}
}
