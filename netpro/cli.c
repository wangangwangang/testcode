#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
//#include <netinet/in.h>
#include <arpa/inet.h>

void fun(int seg)
{
	printf("tcp broken!!!\n");
}

int main()
{
	int fd,ret;
	struct sockaddr_in seraddr;
	char buf[1024];


	fd=socket(AF_INET,SOCK_STREAM,0);
	
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9000);
	inet_pton(AF_INET,"127.0.0.1",&seraddr.sin_addr.s_addr);
	ret=connect(fd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	if(ret<0)
	{
		printf("connect errpr\n");
		exit(-1);
	}
	signal(SIGPIPE,fun);

	while(1)
	{
		printf("please input:");
		fgets(buf,1024,stdin);

		ret=write(fd,buf,strlen(buf));
		if(ret>=0)
		{
			printf("write succeed! buf=[%s]\n",buf);
		}
		if(ret<0)
		{
			close(fd);
			return -1;
		}
	}

}
