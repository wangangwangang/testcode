#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	int num;
	char name[128];
}STU,*PSTU;

void *fun(void *arg)
{
	int i=0;
	PSTU pstu;

	pstu=(PSTU)malloc(sizeof(STU));

	pstu->num=1;
	strcpy(pstu->name,"wangwu");

	while(1)
	{
		if(i>2)
		{
			printf("son1 exit...\n");
			pthread_exit((void *)pstu);
		}
		printf("son1 run...,pthid_son=%ld\n",pthread_self());
		sleep(2);
		i++;
	}
}

int main()
{
	pthread_t pth_id;
	int ret;
	PSTU res;

	ret = pthread_create(&pth_id,NULL,fun,NULL);

	pthread_join(pth_id,(void **)&res);
	printf("--------num=%d,name=%s\n",res->num,res->name);
	free(res);

	while(1)
	{
		printf("father run...,pthid_father=%ld,pth_id=%ld\n",pthread_self(),pth_id);
		sleep(2);
	}

	return 0;
}
