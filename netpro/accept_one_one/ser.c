#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
	int fd,sockfd,lenofaddr,cliport,ret;
	struct sockaddr_in seraddr,cliaddr;
	char buf[1024],cliip[16];

	//socket()
    fd=socket(AF_INET,SOCK_STREAM,0);

	//bind()
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9000);
	inet_pton(AF_INET,"192.168.0.4",&seraddr.sin_addr.s_addr); 
	bind(fd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	//listen()
	listen(fd,20);
	
	//accepe()
	printf("accept...\n");
	sockfd=accept(fd,(struct sockaddr *)&cliaddr,&lenofaddr);
	

	inet_ntop(AF_INET,&cliaddr.sin_addr.s_addr,cliip,16);
	cliport=ntohs(cliaddr.sin_port);
	printf("client connect:IP=[%s]\nport=[%d]\n",cliip,cliport);
	
	while(1)
	{
		printf("read.....\n");
		
		//read()
		ret=read(sockfd,buf,sizeof(buf));
		if(ret==0)
		{
			printf("tcp broken!!!\n");
			close(sockfd);
			close(fd);
			exit(-1);
		}
		if(ret<0)
		{
			printf("read error!!\n");
			close(sockfd);
			close(fd);
			exit(-1);
		}
		if(ret>0)
		{
			buf[ret]='\0';
			printf("buf:%s\n",buf);
		}


	}

	close(sockfd);
	close(fd);

	
	return 0;
}
