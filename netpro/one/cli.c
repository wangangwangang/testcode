#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include "common.h"

void fun(int seg)
{
	printf("tcp(read/server) broken!!!\n");
}

int main()
{
	//signal()
	signal(SIGPIPE,fun);
	
	int fd,ret;
	struct sockaddr_in seraddr;
	char buf[1024];
	struct pack *pmsg;

	//socket()
	fd=socket(AF_INET,SOCK_STREAM,0);
	
	//connect()
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9000);
	inet_pton(AF_INET,"192.168.159.129",&seraddr.sin_addr.s_addr);
	connect(fd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	while(1)
	{

		printf("input buf:");
		scanf("%s",buf);
		pmsg = (struct pack *)malloc(sizeof(struct pack)+strlen(buf));
		printf("input type:");
		scanf("%d",&pmsg->type);
		pmsg->len=strlen(buf);
		pmsg->ver=0;
		memcpy(pmsg->data,buf,strlen(buf));

		//write()
		ret=write(fd,pmsg,sizeof(struct pack)+strlen(buf));
		if(ret>=0)
		{
			printf("write succeed!\n");
		}
		if(ret<0)
		{
			close(fd);
			return -1;
		}

		free(pmsg);
	}

}
