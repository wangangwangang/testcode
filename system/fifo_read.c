#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <erron.h>

int main()
{
	int fd,ret;
	char buf[1024];

	mkfifo("./fa",0777);

	printf("open_read...\n");
	fd=open("./fa",O_RDONLY);
	if(fd<0)
	{
		printf("open error...,ret=%d,erron=%d\n",ret,erron);
	}

	while(1)
	{
		printf("read...\n");
		
		ret=read(fd,buf,1024);

		if(ret>0)
		{
			buf[ret]='\0';
			printf("read success...ret=%d,buf=%s\n",ret,buf);
		}
		if(ret<0)
		{
			printf("read error...,ret=%d,erron=%d\n",ret,erron);
			break;
		}
		if(ret==0)
		{
			printf("fifo broken...,ret=%d,erron=%d\n",ret,erron);
			break;
		}
	}

	close(fd);

	return 0;
}
