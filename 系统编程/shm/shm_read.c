#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int shmid;
	key_t key;
	void *pshm;

	key = ftok("./a",1);

	shmid = shmget(key,1024,IPC_CREAT|0777);

	pshm = shmat(shmid,NULL,0);

	printf("shm:%s\n",(char *)pshm);

	return 0;
}
