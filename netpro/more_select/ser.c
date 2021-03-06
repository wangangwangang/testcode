#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include "common.h"


int main()
{
	int fd,sockfd,lenofaddr,cliport,ret;
	struct sockaddr_in seraddr,cliaddr;
	char buf[1024],cliip[16];
	struct pack *phead;
	fd_set set,rset;
	int maxfd;
	int tfd;

	//socket()
	fd=socket(AF_INET,SOCK_STREAM,0);

	//bind()
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9000);
	inet_pton(AF_INET,"192.168.159.129",&seraddr.sin_addr.s_addr); 
	bind(fd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	//listen()
	listen(fd,20);

	//set init
	FD_ZERO(&set);
	FD_SET(fd,&set);
	maxfd=fd;

	while(1)
	{
		rset=set;
		//select()
		printf("select.....\n");
		ret=select(maxfd+1,&rset,NULL,NULL,NULL);

		//低效率暴力遍历队列
		for(tfd=0;tfd<=maxfd;tfd++)
		{
			if(tfd==fd)
			{
				if(FD_ISSET(fd,&rset))
				{
					//accepe()
					printf("accept...\n");
					lenofaddr=sizeof(cliaddr);    //注意这里不要忘记赋值
					sockfd=accept(fd,(struct sockaddr *)&cliaddr,&lenofaddr);
					inet_ntop(AF_INET,&cliaddr.sin_addr.s_addr,cliip,16);
					cliport=ntohs(cliaddr.sin_port);
					printf("client connect:IP=[%s]\nport=[%d]\n",cliip,cliport);

					//FD_SET()
					FD_SET(sockfd,&set);
					if(sockfd>maxfd)
						maxfd=sockfd;
					continue;
				}
				else
				{
					continue;
				}

			}
			else
			{
				if(!FD_ISSET(tfd,&rset))
					continue;
				else
				{
					printf("read.....\n");
					phead=(struct pack*)malloc(sizeof(struct pack));

					//read()  read head
					ret=read(tfd,phead,sizeof(struct pack));
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
						close(tfd);
						FD_CLR(tfd,&set);
					}
					else
					{
						//read()  read buf
						switch(phead->type)
						{
							case 1:
								{
									printf("type[%d]\n",phead->type);
									ret=read(tfd,buf,phead->len);
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
										close(tfd);
										FD_CLR(tfd,&set);
									}
									break;
								}
							default :
								{
									printf("others type\n");
									ret=read(tfd,buf,phead->len);
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
										close(tfd);
										FD_CLR(tfd,&set);
									}
									break;
								}

						}
					}
					free(phead);
				}
			}
		}
	}

	close(fd);
	return 0;
}
