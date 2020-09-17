#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void fun(int sig)
{
	printf("sig=%d\n",sig);
	return;
}
int main()
{
	pid_t pid_ret;
	int ret;
	char buf[1024];
	int fds[2];

	pipe(fds);

	pid_ret = fork();

	if(pid_ret>0)
	{
		signal(SIGPIPE,fun);

		close(fds[0]);
		while(1)
		{
			printf("please input:\n");
			fgets(buf,1024,stdin);

			ret = write(fds[1],buf,strlen(buf));
			if(ret<0)
			{
				printf("pipe broken...ret_write=%d\n",ret);
				break;
			}
			if(ret>=0)
			{
				printf("write sucess...ret_write=%d\n",ret);
			}
		}

		close(fds[1]);
	}
	else if(pid_ret==0)
	{
		close(fds[1]);
		while(1)
		{
			printf("read....\n");
			ret = read(fds[0],buf,1024);
			if(ret<0)
			{
				printf("read error...ret_read=%d\n",ret);
				break;
			}
			if(ret>0)
			{
				buf[ret]='\0';
				printf("read sucess...ret_read=%d,buf=%s\n",ret,buf);
			}
			if(ret==0)
			{
				printf("pipe broken...ret_read=%d\n",ret);
				break;
			}
		}

		close(fds[0]);
	}
}
