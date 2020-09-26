//added by wanga
//function:消息队列的发送

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
	

	msgid = msgget(0x100,IPC_CREAT|0777);

	while(1)
	{
		printf("please input:");
		scanf("%ld %s",&ms.type,ms.buf);
		msgsnd(msgid,&ms,sizeof(ms)-sizeof(long),0);
	}

	return 0;
}
