#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/types.h>
#include "common.h"


int main()
{
	int fd,sockfd,lenofaddr,cliport,ret;
	struct sockaddr_in seraddr,cliaddr;
	char buf[1024],cliip[16];
	struct pack *phead;
	int tfd;						//响应队列循环变量
	int epfd;						//epoll文件描述符
	int count;						//存放已响应的文件描述符个数
	struct epoll_event ev;			//对被操作的文件描述符作事件描述
	struct epoll_event evs[100];	//存放已相应的文件描述符事件


	//socket()
	fd=socket(AF_INET,SOCK_STREAM,0);

	//bind()
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(9000);
	inet_pton(AF_INET,"192.168.159.129",&seraddr.sin_addr.s_addr); 
	bind(fd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	//listen()
	listen(fd,20);

	//epoll_create()
	epfd=epoll_create(100);

	//epoll_ctl()   add epoll
	ev.events=EPOLLIN;
	ev.data.fd=fd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev);

	while(1)
	{
		//epoll_wait()
		printf("epoll wait.....\n");
	    count=epoll_wait(epfd,evs,100,-1);

		//低效率暴力遍历队列
		for(tfd=0;tfd<count;tfd++)
		{
			if(evs[tfd].data.fd==fd)
			{
				//accepe()
				printf("accept...\n");
				lenofaddr=sizeof(cliaddr);    //注意这里不要忘记赋值
				sockfd=accept(fd,(struct sockaddr *)&cliaddr,&lenofaddr);
				inet_ntop(AF_INET,&cliaddr.sin_addr.s_addr,cliip,16);
				cliport=ntohs(cliaddr.sin_port);
				printf("client connect:IP=[%s]\nport=[%d]\n",cliip,cliport);

				//epoll_ctl()  add epoll
				ev.events=EPOLLIN;
				ev.data.fd=sockfd;
				epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev);
			}
			else
			{
				printf("read.....\n");
				phead=(struct pack*)malloc(sizeof(struct pack));

				//read()  read head
				ret=read(evs[tfd].data.fd,phead,sizeof(struct pack));
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

					//epoll_ctl()  del epoll
					ev.events=EPOLLIN;
					ev.data.fd=evs[tfd].data.fd;
					epoll_ctl(epfd,EPOLL_CTL_DEL,evs[tfd].data.fd,&ev);
				}
				else
				{
					//read()  read buf
					switch(phead->type)
					{
						case 1:
							{
								printf("type[%d]\n",phead->type);
								ret=read(evs[tfd].data.fd,buf,phead->len);
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

									//epoll_ctl()  del epoll
									ev.events=EPOLLIN;
									ev.data.fd=evs[tfd].data.fd;
									epoll_ctl(epfd,EPOLL_CTL_DEL,evs[tfd].data.fd,&ev);
								}
								break;
							}
						default :
							{
								printf("others type\n");
								ret=read(evs[tfd].data.fd,buf,phead->len);
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
									//epoll_ctl()  del epoll
									ev.events=EPOLLIN;
									ev.data.fd=evs[tfd].data.fd;
									epoll_ctl(epfd,EPOLL_CTL_DEL,evs[tfd].data.fd,&ev);
								}
								break;
							}

					}
				}
				free(phead);
			}
		}
	}

	close(epfd);
	close(fd);
	return 0;
}
