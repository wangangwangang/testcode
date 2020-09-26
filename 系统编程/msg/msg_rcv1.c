//added by wanga
//function:消息队列的接受，类型为1的

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
	
	printf("msgget_rcv1:\n");
	msgid = msgget(0x100,IPC_CREAT|0777);

	while(1)
	{
		printf("rc1:\n");
		msgrcv(msgid,&ms,sizeof(ms),1,0);
		printf("type:%ld,buf:%s\n",ms.type,ms.buf);
	}

	return 0;
}
