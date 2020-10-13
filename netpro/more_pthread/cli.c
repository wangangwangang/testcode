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

	signal(SIGPIPE,fun);

	int fd,ret;
	struct sockaddr_in seraddr;
	char buf[1024];

	//socket()
	fd=socket(AF_INET,SOCK_STREAM,0);

	//connect()
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9000);
	inet_pton(AF_INET,"192.168.0.4",&seraddr.sin_addr.s_addr);
	connect(fd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	while(1)
	{
		printf("write:");
		scanf("%s",buf);;

		//write()
		ret=write(fd,buf,strlen(buf));
		if(ret>=0)
		{
			printf("write succeed!\n");
		}
		if(ret<0)
		{
			close(fd);
			return -1;
		}

	}

	close(fd);

	return 0;


}
