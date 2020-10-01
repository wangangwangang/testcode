#include <stdio.h>
#include <stdlib.h>

//结构体定义
typedef struct student
{
	int num;
	struct student *next;
}STU,*PSTU;

//函数声明
void creat_link(PSTU *ps);         //创建无头节点链表
void print_link(PSTU ps);          //打印链表
PSTU search_link(PSTU ps);         //查找功能
void beforeinsert_link(PSTU *ps);  //前插入功能
void del_link(PSTU *ps);           //删除链表
//主函数
int main()
{
	PSTU head=NULL;
	creat_link(&head);         //创建无头节点链表
	print_link(head);          //打印链表
	search_link(head);         //查找链表
	beforeinsert_link(&head);  //前插入功能
	del_link(&head);           //删除链表
}

//创建无头节点链表
void  creat_link(PSTU *ps)
{
	system("clear");
	printf("***********欢迎来到学生添加界面*************\n");
	int i;
	printf("please input num of student:");
	scanf("%d",&i);
	while(i>0)
	{
		PSTU pstu=malloc(sizeof(STU));
		pstu->num=i;
		pstu->next=*ps;
		*ps=pstu;
		printf("please input num of student:");
		scanf("%d",&i);
	}
	printf("信息添加成功，按空格继续");
	setbuf(stdin,NULL);
	getchar();
}

//打印链表
void  print_link(PSTU ps)
{
	system("clear");
	printf("***********欢迎来到学生信息打印界面*************\n");
	while(ps)
	{
		printf("%d ",ps->num);
		ps=ps->next;
	}
	printf("\n");
	printf("信息打印成功，按空格继续");
	setbuf(stdin,NULL);
	getchar();
}

//查询链表
PSTU search_link(PSTU ps)
{
	system("clear");
	printf("***********欢迎来到学生信息查询界面*************\n");
	int i;
	printf("请输入想要查询的学号:");
	scanf("%d",&i);
	PSTU p;
	p=ps;
	while(p!=NULL)
	{
		if(p->num==i)
		{
			printf("有学号为%d的学生,按空格键继续\n",p->num);
			setbuf(stdin,NULL);
			getchar();
			return p; 
		}
		p=p->next;
	}
	if(p==NULL)
	{
		printf("查无此人,按空格键继续");
		setbuf(stdin,NULL);
		getchar();
		return NULL;
	}

}

//前插入功能
void beforeinsert_link(PSTU *ps)  
{
	system("clear");
	printf("***********欢迎来到学生信息前插入界面*************\n");
	printf("查找在哪个学号之前插入，按空格继续");
	setbuf(stdin,NULL);
	getchar();
	PSTU ptr=search_link(*ps);
	if(ptr!=NULL)
	{
		PSTU pstu=malloc(sizeof(STU));
		int i;
		printf("请输入插入的学号:");
		scanf("%d",&i);
		pstu->num=i;
		if(ptr==*ps)
		{
			pstu->next=*ps;
			*ps=pstu;
		}
		else
		{
			PSTU bptr=*ps;
			while(bptr->next!=ptr)
				bptr=bptr->next;
			pstu->next=ptr;
			bptr->next=pstu;
		}

		print_link(*ps);
		printf("插入成功，按空格结束");
		setbuf(stdin,NULL);
		getchar();
	}
	else
	{
		printf("插入失败，按空格结束");
		setbuf(stdin,NULL);
		getchar();
	}
}
//删除链表
void del_link(PSTU *ps)
{

	system("clear");
	printf("***********欢迎来到学生信息删除界面*************\n");
	printf("查找需要删除哪个学号，按空格继续");
	setbuf(stdin,NULL);
	getchar();
	PSTU ptr=search_link(*ps);
	if(ptr==NULL)
	{}
	else
	{
		PSTU  bptr=*ps;
		if(ptr!=*ps)
		{
			while(bptr->next!=ptr)
				bptr=bptr->next;
			bptr->next=ptr->next;
		}
		else
		{
			*ps=ptr->next;
		}
		free(ptr);
		print_link(*ps);
		printf("删除信息成功，按空格结束");
		setbuf(stdin,NULL);
		getchar();
	}

}
