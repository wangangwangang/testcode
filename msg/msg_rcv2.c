#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf
{
	long type;
	char buf[1024];
};

int main()
{
	int msgid;
	struct msgbuf ms;
	
	printf("msgget_rcv2\n");
	msgid = msgget(0x100,IPC_CREAT|0777);

	while(1)
	{
		printf("rcv2:\n");
		msgrcv(msgid,&ms,sizeof(ms),2,0);
		printf("type:%ld,buf:%s\n",ms.type,ms.buf);
	}

	return 0;
}
