#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>

MYSQL mysql;
typedef struct student 
{
	int num;
	char name[30];
	int  score;
}STU;

//初始化链接数据库
int init()
{

	if(mysql_init(&mysql)==NULL)
	{
		printf("初始化失败\n");
		return -1;
	}
	if(NULL==(mysql_real_connect(&mysql,"localhost","root","123456","stu",0,NULL,0)))
	{
		printf("%s\n",mysql_error(&mysql));
		return -1;
	}
	printf("连接数据库成功\n");
	mysql_set_character_set(&mysql,"utf8");
}

// 显示数据库
int show()
{
	char sql[128]="select * from data1 order by num asc";
	if(0!=mysql_query(&mysql,sql))
	{
		printf("执行语句失败\n");
		printf("sql:%s",sql);
		return -1;                                              
	}

	MYSQL_RES * result =mysql_store_result(&mysql);
	int num_rows=0,num_fields=0;
	num_rows=mysql_num_rows(result);
	num_fields=mysql_num_fields(result);
	printf("%d行%d列\n",num_rows,num_fields);
	MYSQL_FIELD * field=NULL;
	MYSQL_ROW row;
	for(int i=0;i<num_fields;i++)
	{
		field=mysql_fetch_field(result);
		printf("%s\t",field->name);
	}
	printf("\n");
	while((row=mysql_fetch_row(result))!=NULL)
	{
		int i;
		for(i=0;i<num_fields;i++)
			printf("%s\t",row[i]);
		printf("\n");
	}
	mysql_free_result(result);
	printf("打印成功，按空格继续\n");
	setbuf(stdin,NULL);
	getchar();
	return 0;

}


//判断编号是否存在
int judge(int num)
{
	char sql[128];
	sprintf(sql,"select * from data1 where num=%d",num);
	if(0!=mysql_query(&mysql,sql))
	{
		printf("执行语句失败\n");
		printf("sql:%s",sql);
		return -1;
	}

	MYSQL_RES * result =mysql_store_result(&mysql);
	int num_rows=0;
	num_rows=mysql_num_rows(result);
	return num_rows;


}



//增加学生信息
int insert()
{
	char sql[128];
	STU s1;
	printf("输入学生编号:");
	scanf("%d",&s1.num);
	while(s1.num>0)
	{
		int jud=judge(s1.num);
		if(jud==0)
		{
			printf("请输入姓名:");
			scanf("%s",s1.name);
			printf("请输入分数:");
			scanf("%d",&s1.score);
			sprintf(sql,"insert into data1 values (%d,'%s',%d)",s1.num,s1.name,s1.score);
			if(0!=mysql_query(&mysql,sql))
			{
				printf("执行语句失败\n");
				printf("sql:%s",sql);
				return -1;
			}
			printf("输入学生编号:");
			scanf("%d",&s1.num);
		}
		else
		{
			printf("编号存在，请重新输入:");
			scanf("%d",&s1.num);
		}

	}
	return 0;
}

//按编号删除
int delete()
{
	char sql[128];
	int a;
	char name[32];
	printf("输入需要删除的学生编号:");
	scanf("%d",&a);
	while(a>0)
	{
		int jud=judge(a);
		if(jud>0)
		{
			printf("输入需要删除的学生姓名:");
			scanf("%s",name);
			sprintf(sql,"delete from data1 where num=%d and  name='%s'",a,name);
			if(0!=mysql_query(&mysql,sql))
			{
				printf("执行语句失败\n");
				printf("sql:%s",sql);
				return -1;                                              
			}
			printf("输入需要删除的学生编号:");
			scanf("%d",&a);
		}
		else
		{
			printf("学生编号不存在,请重新选择:");
			scanf("%d",&a);
		}

	}

	return 0;
}

//根据编号更改分数
int change()
{
	char sql[128];
	int a;
	int score;
	printf("输入需要更改的学生编号:");
	scanf("%d",&a);
	while(a>0)
	{
		int jud=judge(a);
		if(jud>0)
		{
			printf("输入需要更改的学生分数:");
			scanf("%d",&score);
			sprintf(sql,"update data1 set score='%d' where num=%d",score,a);
			if(0!=mysql_query(&mysql,sql))
			{
				printf("执行语句失败\n");
				printf("sql:%s",sql);
				return -1;                                              
			}
			printf("输入需要更改的学生编号:");
			scanf("%d",&a);
		}
		else
		{
			printf("学生编号不存在,请重新选择:");
			scanf("%d",&a);
		}

	}
	return 0;

}


//根据学生编号查询
int search()
{
	printf("请输入需要查询学生的编号:");
	int number;
	scanf("%d",&number);
	while(number>0)
	{
		char sql[128];
		sprintf(sql,"select * from data1 where num=%d",number);
		if(0!=mysql_query(&mysql,sql))
		{
			printf("执行语句失败\n");
			printf("sql:%s",sql);
			return -1;                                              
		}

		MYSQL_RES * result =mysql_store_result(&mysql);
		int num_rows=0,num_fields=0;
		num_rows=mysql_num_rows(result);
		num_fields=mysql_num_fields(result);
		MYSQL_FIELD * field=NULL;
		MYSQL_ROW row;
		for(int i=0;i<num_fields;i++)
		{
			field=mysql_fetch_field(result);
			printf("%s\t",field->name);
		}
		printf("\n");
		while((row=mysql_fetch_row(result))!=NULL)
		{
			int i;
			for(i=0;i<num_fields;i++)
				printf("%s\t",row[i]);
			printf("\n");
		}

		printf("请输入需要查询学生的编号:");
		scanf("%d",&number);
		mysql_free_result(result);
	}


}

int main()
{

	init();
	char * menu="=======学生管理系统=======\n"
		"      1.添加学生信息      \n"
		"      2.删除学生信息      \n"
		"      3.修改学生信息      \n"
		"      4.查询学生信息      \n"
		"      5.显示所有学生信息  \n"
		"      0.退出              \n"
		"                          \n"
		"请选择:";
	int key;
	do
	{
		system("clear");
		printf("%s",menu); 
		scanf("%d",&key);
		switch(key)
		{
			case 1:insert();break;
			case 2:delete();break;
			case 3:change();break;
			case 4:search();break;
			case 5:show();break;
			case 0:break;
			default :printf("重新输入:");
		}
	}while(key>0);
	return 0;

}


