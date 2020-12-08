/*
  ================================================================
  =
  =
  =   文件名称：9_回文数.c
  =   创 建 者：Ang Wang  
  =   创建日期：2020年12月08日
  =   描    述：
  =
  ===============================================================
*/


#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
	int pop=0;
	int rev=0;
	
	if(x<0||(x>0&&x%10==0)) 
		return false;
	if(x==0)
		return true;
	
	while(x>rev)
	{
		pop=x%10;
		rev=rev*10+pop;

		x=x/10;
	}

	if(x==rev||x==rev/10)
		return true;
	else
		return false;

}

int main()
{
	int x;
	bool rev_bool;

	printf("please input x:");
	scanf("%d",&x);

	if(rev_bool=isPalindrome(x))
		printf("true\n");
	else
		printf("false\n");
}
