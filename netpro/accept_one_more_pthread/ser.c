#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *fun(void *arg)
{
	int ret,sockfd;
	char buf[1024];
	int  *psockfd=(int *)arg;
	sockfd = *psockfd;

	while(1)
	{
		printf("read.....\n");

		//read()
		ret=read(sockfd,buf,sizeof(buf));
		if(ret==0)
		{
			printf("tcp broken!!!\n");
			close(sockfd);
			exit(-1);
		}
		if(ret<0)
		{
			printf("read error!!\n");
			close(sockfd);
			exit(-1);
		}
		if(ret>0)
		{
			buf[ret]='\0';
			printf("buf:%s\n",buf);
		}
	}

	close(sockfd);

}


int main()
{
	int fd,sockfd,lenofaddr,cliport;
	struct sockaddr_in seraddr,cliaddr;
	char cliip[16];
	pthread_t pthid;

	//socket()
	fd=socket(AF_INET,SOCK_STREAM,0);

	//bind()
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9000);
	inet_pton(AF_INET,"192.168.0.4",&seraddr.sin_addr.s_addr); 
	bind(fd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	//listen()
	listen(fd,20);

	while(1)
	{
		//accept()
		printf("accept...\n");
		sockfd=accept(fd,(struct sockaddr *)&cliaddr,&lenofaddr);
		inet_ntop(AF_INET,&cliaddr.sin_addr.s_addr,cliip,16);
		cliport=ntohs(cliaddr.sin_port);
		printf("TCP connect:IP=[%s]  port=[%d]\n",cliip,cliport);

		pthread_create(&pthid,NULL,fun,(void *)&sockfd);
	//	pthread_join(pthid,NULL);

	}
	close(fd);


	return 0;
}
