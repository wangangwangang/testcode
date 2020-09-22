#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd,ret,i;
	char buf[1024];
	struct flock lock;

	printf("open...\n");
	fd = open("./flck.txt",O_WRONLY);
	printf("open over...\n");

	printf("fcntl...\n");
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=100;
	fcntl(fd,F_SETLKW,&lock);
	printf("fcntl over...\n");
	
	printf("write...\n");
	ret = write(fd,"123",4);
	sleep(10);
	printf("write over...\n");
	
	printf("unlock...\n");
	lock.l_type=F_UNLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=100;
	fcntl(fd,F_SETLKW,&lock);
	printf("unlock over...\n");

	close(fd);

	return 0;
	


	
}
