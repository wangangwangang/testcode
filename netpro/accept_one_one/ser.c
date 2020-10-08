#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"


int main()
{
	int fd,sockfd,lenofaddr,cliport,ret;
	struct sockaddr_in seraddr,cliaddr;
	char buf[1024],cliip[16];
	struct pack *phead;

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
		phead=(struct pack*)malloc(sizeof(struct pack));

		//read()  read head
		ret=read(sockfd,phead,sizeof(struct pack));
		if(ret<=0)
		{
			if(ret==0)
			{
				printf("tcp broken!!!\n");
			}
			else
			{
				printf("read error\n");
			}
			close(sockfd);
			close(fd);
			exit(-1);
		}
		else
		{
			//read()  read buf
			switch(phead->type)
			{
				case 1:
					{
						printf("type[%d]\n",phead->type);
						ret=read(sockfd,buf,phead->len);
						if(ret>0)
						{
							buf[ret]='\0';
							printf("buf:%s\n",buf);
						}
						else
						{
							if(ret==0)
							{
								printf("tcp broken!!!\n");
							}
							else
							{
								printf("read error\n");
							}
							close(sockfd);
							close(fd);
							exit(-1);
						}
						break;
					}
				default :
					{
						printf("others type\n");
						ret=read(sockfd,buf,phead->len);
						if(ret>0)
						{
							buf[ret]='\0';
							printf("buf:%s\n",buf);
						}
						else
						{
							if(ret==0)
							{
								printf("tcp broken!!!\n");
							}
							else
							{
								printf("read error\n");
							}
							close(sockfd);
							close(fd);
							exit(-1);
						}
						break;
					}

			}
		}
		free(phead);
	}

	close(sockfd);
	close(fd);
	return 0;
}
