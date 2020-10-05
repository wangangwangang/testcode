#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main ()
{
	system("clear");
	pid_t rpid;
	int status;

	printf("fork start...\n");
	
	//fork()
	rpid=fork();

	if(rpid>0)
	{
	    
		//wait()
		wait(&status);
		printf("return1=%d\n",WEXITSTATUS(status));
		
		while(1)
		{
			printf("father1:pid=%d\n",getpid());
			sleep(3);
		}
	}
	else if(rpid==0)
	{
		while(1)
		{
			printf("son:pid=%d,ppid=%d\n",getpid(),getppid());
			
			sleep(2);
			//exit()
			exit(123);
		}
	}
}
