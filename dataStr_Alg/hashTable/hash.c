#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 11

typedef struct student
{
	int num;
	char name[100];
	struct student *next;
}STU;

STU *Hashtable[MAX_NUM];

int hashfun(int k)
{
	return k%11;
}

STU *Search(STU *ps,int x)
{
	STU *ptr=ps;
	while(ptr!=NULL)
	{
		if(ptr->num==x)
			return ptr;
		ptr=ptr->next;
	}
	return  NULL;
}

void Insert()
{
	STU *newnode;
	int index;
	do
	{
		system("clear");
		printf("=======添加界面=========\n");
		newnode=malloc(sizeof(STU));
		printf("请输入学号(按0结束):");
		scanf("%d",&newnode->num);
		if(newnode->num>0)
		{
			printf("请输入姓名:");
			scanf("%s",newnode->name);
			index=hashfun(newnode->num);
			if(Hashtable[index]==NULL)
			{
				newnode->next=Hashtable[index];
				Hashtable[index]=newnode;
				printf("插入成功！\n");
			}
			else
			{
				if(Search(Hashtable[index],newnode->num)==NULL)
				{
					newnode->next=Hashtable[index];
					Hashtable[index]=newnode;
					printf("插入成功!\n");
				}
				else
				{
					printf("该学生学号已存在\n");
					free(newnode);
				}

			}
		}
		else
			free(newnode);
	}while(newnode->num>0);
	printf("添加成功，按空格继续。\n");
	setbuf(stdin,NULL);
	getchar();

}


void Show()
{
        system("clear");
	printf("============打印界面===========\n");
	int i;
	STU *ptr;
	for(i=0;i<MAX_NUM;i++)
	{
		if(Hashtable[i]!=NULL)
		{
			ptr=Hashtable[i];
			while(ptr!=NULL)
			{
				printf("%-5d%-15s\n",ptr->num,ptr->name);
				ptr=ptr->next;
			}
		}
	}
	printf("打印成功，按空格继续。\n");
	setbuf(stdin,NULL);
	getchar();
}

//查询学生编号是否存在
void Search2()
{
	int i,index;
	do
	{
		system("clear");
		printf("=========查询界面=========\n");
		printf("请输入需要查询的学生编号(按0结束):");
		scanf("%d",&i);
		if(i>0)
		{
			index=hashfun(i);
			if(Hashtable[index]==NULL)
			{
				printf("学生信息不存在,按空格结束\n");
				setbuf(stdin,NULL);
				getchar();
			}
			else
				if(Search(Hashtable[index],i)==NULL)
				{
					printf("学生信息不存在,按空格结束\n");
					setbuf(stdin,NULL);
					getchar();
				}
				else
				{
					printf("学号:%-5d姓名:%-15s\n",Search(Hashtable[index],i)->num,Search(Hashtable[index],i)->name);
					setbuf(stdin,NULL);
					getchar();
				}
		}
	}while(i>0);


}


//删除学生信息
STU  *Del()
{
	int i,index;
	do
	{
		system("clear");
		printf("=========删除界面=========\n");
		printf("请输入需要删除的学生编号(按0结束):");
		scanf("%d",&i);
		if(i>0)
		{
			index=hashfun(i);
			if(Hashtable[index]==NULL)
			{
				printf("学生信息不存在,按空格结束\n");
				setbuf(stdin,NULL);
				getchar();
			}
			else
				if(Search(Hashtable[index],i)==NULL)
				{
					printf("学生信息不存在,按空格结束\n");
					setbuf(stdin,NULL);
					getchar();
				}
				else
				{
					if(Search(Hashtable[index],i)==Hashtable[index])
						Hashtable[index]=Hashtable[index]->next;
					else
					{
						STU *ptr=Hashtable[index];
						while(ptr->next!=Search(Hashtable[index],i))
							ptr=ptr->next;
						ptr->next=Search(Hashtable[index],i)->next;
					}
					free(Search(Hashtable[index],i)); 
					Show();
				}
		}
	}while(i>0);


}

int main()
{
	char *menu_prompt=
		"========================哈希表=========================\n"
		"=                    1.添加成员                       =\n"
		"=                    2.显示所有成员                   =\n"
		"=                    3.搜索成员                       =\n"
		"=                    4.删除成员                       =\n"
		"=                    5.返回                           =\n"
		"=======================================================\n"
		"功能选择:";
	int menusele;
	int i;
	for(i=0;i<MAX_NUM;i++)
		Hashtable[i]=NULL;
	do
	{
		system("clear");
		printf("%s",menu_prompt);
		scanf("%d",&menusele);
		switch(menusele)
		{
			case 1:Insert();break;
			case 2:Show();break;
			case 3:Search2();break;
			case 4:Del();break;
			case 5:
			       {
				       printf("按空格退出\n");
				       setbuf(stdin,NULL);
				       getchar();
				       break;
			       }
			default:
			       {
				       printf("无效输入,按空格重新输入\n\n");
				       setbuf(stdin,NULL);
				       getchar();
				       break;
			       }

		}
	}while(menusele!=5);


}
