/*
  ================================================================
  =
  =
  =   文件名称：3_无重复字符的最长子串.c
  =   创 建 者：Ang Wang  
  =   创建日期：2020年12月02日
  =   描    述：
  =
  ===============================================================
*/


#include <stdio.h>

int lengthOfLongestSubstring(char * s){

}

int main()
{
	char s[128];
	int	 len;

	//将键盘输入的字符串保存在字符数组中
	printf("please input str:");
    gets(s);

	len=lengthOfLongestSubstring(s);

	printf("不重复子串的长度是%d\n",len);

	return 0;

}
