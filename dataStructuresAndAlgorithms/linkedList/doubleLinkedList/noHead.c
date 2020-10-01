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
PSTU judge_link_two(PSTU ps,int x);
void search_link(PSTU ps);
void search_link_two(PSTU ps);
int insert_link(PSTU *ps);
void del_link(PSTU *ps);

int main()
{
	PSTU head=NULL;
	creat_link(&head);
	print_link(head);
	search_link(head);
	search_link_two(head);
	insert_link(&head);
	del_link(&head);
}

//创建双链表
void creat_link(PSTU *ps)
{
	system("clear");
	printf("*******欢迎来到学生信息添加界面*******\n");
	printf("please input a number of student:");
	int i;
	scanf("%d",&i);
	STU *p;
	while(i>0)
	{
		p=*ps;
		PSTU pp=judge_link(p,i);
		if(pp==NULL)
		{
			PSTU stu=(PSTU)malloc(sizeof(STU));
			stu->num=i;
			stu->prev=NULL;
			stu->next=*ps;
			if(*ps!=NULL)
				(*ps)->prev=stu;
			*ps=stu;
			printf("信息已录入，请继续添加:");
			scanf("%d",&i);
		}
		else
		{
			printf("信息已存在，请输入别的数字:");
			scanf("%d",&i);
		}

	}
	printf("添加成功，按空格继续\n");
	setbuf(stdin,NULL);
	getchar();
}

//打印双链表(需要修正空链表)
void print_link(PSTU ps)
{
	system("clear");
	printf("*******欢迎来到学生信息打印界面*******\n");
	PSTU p=ps;
	if(p==NULL)
	{
		printf("空链表\n");

	}
	else
	{
		//正向打印
		while(p)
		{
			printf("%d ",p->num);
			p=p->next;
		}
		printf("\n");
		//反向打印
		p=ps;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		while(p) 
		{
			printf("%d ",p->num);
			p=p->prev;
		}
		printf("\n");
	}
	printf("打印成功，按空格继续\n");
	setbuf(stdin,NULL);
	getchar();
}

//根据学号判断是否存在节点，并返回所查找的节点(需要修正空链表)
PSTU judge_link(PSTU ps,int i)
{
	PSTU p=ps;
	while(p)
	{
		if(p->num==i)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;

}

//根据学号查询链表（修正空链表）
void search_link(PSTU ps)
{
	system("clear");
	printf("******欢迎来到学生信息查询界面******\n");
	printf("请输入需要查询的学生号：");
	int i;
	scanf("%d",&i);
	PSTU p=judge_link(ps,i);
	if(p!=NULL)
	{
		printf("学号为%d的学生存在，按空格结束\n",p->num);
		setbuf(stdin,NULL);
		getchar();
	}
	else
	{
		printf("学号为%d的学生不存在，按空格结束\n",p->num);
		setbuf(stdin,NULL);
		getchar();
	}
}

//根据位置判断是否存在，并返回当前位置的指针
PSTU judge_link_two(PSTU ps,int x)
{
	while(ps&&x>1)
	{
		ps=ps->next;
		x--;
	}
	return ps;
}

//根据位置查询链表（修正空链表）
void search_link_two(PSTU ps)
{
	system("clear");
	printf("******欢迎来到学生信息查询界面2******\n");
	printf("请输入需要查询的学生顺序号：");
	int x;
	scanf("%d",&x);
	PSTU p=judge_link_two(ps,x);
	if(ps=NULL)
	{
		printf("查无此人,按空格结束\n");
		setbuf(stdin,NULL);
		getchar();
	}
	else
	{
		printf("查有此人,按空格结束\n");
		setbuf(stdin,NULL);
		getchar();
	}
}


//链表中插入节点(先连后再连前,需要修正头)
int insert_link(PSTU *ps)
{
	system("clear");
	printf("******欢迎来到学生信息插入界面******\n");
	printf("请输入需要插入位置的学生号：");
	int i;
	scanf("%d",&i);
	STU *p=*ps;
	PSTU  pp=judge_link(p,i);
	if(pp==NULL)
	{
		printf("插入位置不存在,按空格继续\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	else 
	{
		int j;
		printf("请输入需要插入的学生信息:");
		scanf("%d",&j);
		PSTU stu=malloc(sizeof(STU));
		stu->num=j;
		if(pp==*ps)
		{
			stu->prev=NULL;
			stu->next=*ps;
			(*ps)->prev=stu;
			*ps=stu;
		}
		else
		{
			PSTU bpp=*ps;
			while(bpp->next!=pp)
				bpp=bpp->next;
			bpp->next=stu;
			stu->prev=bpp;
			stu->next=pp;
			pp->prev=stu;

		}
		print_link(*ps);
		printf("信息插入成功,按空格继续\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}


}

//删除链表节点(双链表删除节点不需要找前一个节点，需要修正空节点 ，需要修正头和尾)
void del_link(PSTU *ps)
{
	system("clear");
	printf("*****欢迎来到信息删除界面******\n");
	int i;
	printf("请输入需要删除的学生学号：");
	scanf("%d",&i);
	STU *p=*ps;
	PSTU ptr=judge_link(p,i);
	while(ptr==NULL)
	{
		printf("学生信息不存在，请重新输入\n");
		scanf("%d",&i);
		ptr=judge_link(p,i);
	}
	if(ptr->prev==NULL)
	{
		(*ps)->prev=NULL;
		*ps=ptr->next;
	}
	else
		if(ptr->next==NULL)
			ptr->prev->next=NULL;
		else
		{
			/*	PSTU bptr=*ps;
				while(bptr->next!=ptr)
				bptr=bptr->next;
				bptr->next=ptr->next; */
			ptr->next->prev=ptr->prev;
			ptr->prev->next=ptr->next;
		}
	free(ptr);

	if(*ps==NULL)
	{
		printf("空链表,按空格结束\n");
		setbuf(stdin,NULL);
		getchar();
	}
	else
	{
		print_link(*ps);
		printf("删除成功,按空格继续\n");
		setbuf(stdin,NULL);
		getchar();
	}
}
























