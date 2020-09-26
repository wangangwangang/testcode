#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int shmid;
	key_t key;
	char buf[1024];
	void *pshm;

	key = ftok("./a",1);

	shmid = shmget(key,1024,IPC_CREAT|0777);

	pshm = shmat(shmid,NULL,0);
	printf("rnd=%d,rdonly=%d\n",SHM_RND,SHM_RDONLY);
	while(1)
	{
		printf("input:");
		fgets(buf,1024,stdin);
		strcpy((char *)pshm,buf);
	}

	return 0;
}
