/*
  ================================================================
  =
  =
  =   文件名称：14_最长公共前缀.c
  =   创 建 者：Ang Wang  
  =   创建日期：2020年12月08日
  =   描    述：
  =
  ===============================================================
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *longestCommonPrefix(char ** strs,int strsSize)
{
	char *rev=NULL;

	
	if(strsSize==0)
		return "";
	
	for(int i=0;i<strlen(strs[0]);i++)
	{
		for(int j=1;j<strsSize;j++ )
		{
			if(strs[0][i]!=strs[j][i])
			{
				memcpy(rev,strs,i);
				rev[i]='\0';

				return rev;
			}
		}
	}
}


int main()
{
	char strs[128][128];
	int  strsSize=0;
	char *rev=NULL;

	printf("please input strsSize:");
	scanf("%d",&strsSize);

	for(int i=0;i<strsSize;i++)
	{
		printf("请输入第%d个字符串:",i+1);
		scanf("%s",strs[i]);
	}

	for(int i=0;i<strsSize;i++)
	{
		printf("第%d个字符串为%s\n",i+1,strs[i]);
	}

	rev=longestCommonPrefix(strs,strsSize);

	printf("the longest conmmon prefix is %s\n",rev);

}
