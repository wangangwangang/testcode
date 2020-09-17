#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid1;
	
	printf("fork start...,pid=%d\n",getpid());
	pid1 = fork();
	
	if(pid1>0)
	{
		while(1)
		{
			printf("father...pid1 = %d,getpid=%d,getppid=%d\n",pid1,getpid(),getppid());
			sleep(2);
		}
	}
	else if(pid1==0)
	{
		while(1)
		{
			printf("son...pid1 = %d,getid=%d,getppid=%d\n",pid1,getpid(),getppid());
			sleep(3);
		}
	}

}
