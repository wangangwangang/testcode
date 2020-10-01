//ASCII码表：A-Z[65-90]  a-z[97-122]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	char c;

	while(1)
	{
		system("clear");
		printf("判断是否为字母，请输入：");
		c=getchar();

		if((c>=65&&c<=90)||(c>=97&&c<=122))
		{
			printf("%c为字母，任意键继续\n",c);
			sleep(2);
	//		setbuf(stdin,NULL);
	//		getchar();
		}
		else
		{
			printf("%c不是字母，任意键继续\n",c);
			sleep(2);
	//		setbuf(stdin,NULL);
	//		getchar();
		}
	}

}
