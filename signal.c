#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fun(int a)
{
	printf("\nsig=%d\n",a);
	return;
}

int main()
{
	signal(15,fun);
	while(1)
	{
		printf(".");
		fflush(stdout);
		fflush(stdout);
		sleep(5);
	}

	return 0;
}
