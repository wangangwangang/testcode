#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <erron.h>
#include <string.h>
#include <signal.h>

void fun(int sig)
{
	printf("sig=%d\n",sig);
	return;
}

int main()
{
	int fd,ret;
	char buf[1024];

	signal(SIGPIPE,fun);

	mkfifo("./fa",0777);

	printf("open_write...\n");
	fd=open("./fa",O_WRONLY);
	if(fd<0)
	{
		printf("open error...,ret=%d,erron=%d\n",ret,erron);
	}

	while(1)
	{
		printf("write...:");

		fgets(buf,1024,stdin);
		
		ret=write(fd,buf,strlen(buf));

		if(ret>=0)
		{
			buf[ret]='\0';
			printf("write success...ret=%d,buf=%s\n",ret,buf);
		}
		if(ret<0)
		{
			printf("fifo broken...,ret=%d,erron=%d\n"ret,erron);
			break;
		}
	}

	close(fd);

	return 0;
}
