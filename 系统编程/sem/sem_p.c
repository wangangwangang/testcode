#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
	int semid;
	struct sembuf sops;
	
	//create sem
	semid = semget(0x2000,1,IPC_CREAT|0777);
	
	//init sem
	semctl(semid,0,SETVAL,1);

	//p操作，生产
	sops.sem_num=0;
	sops.sem_op=-1;
	sops.sem_flg=0;
	
	while(1)
	{
		printf("p.....\n");
		semop(semid,&sops,1);
	}
}
