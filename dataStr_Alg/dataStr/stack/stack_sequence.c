/*
  ================================================================
  =
  =
  =   文件名称：stack_sequence.c
  =   创 建 者：Ang Wang  
  =   创建日期：2020年12月14日
  =   描    述：顺序栈的使用
  =
  ===============================================================
*/


#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//顺序栈的存储定义
typedef struct stack_sequence
{
	int data[MAXSIZE];
	int top;
}seqStack;

//创建空栈
seqStack* create()
{
	seqStack* stack=(seqStack*)malloc(sizeof(seqStack));
	stack->top=-1;
	return stack;
}

//入栈操作
void push(seqStack* stack,int elem)
{
	stack->top++;
	stack->data[stack->top]=elem;
}

//出栈操作
void pop(seqStack* stack,int *elem)
{
	*elem=stack->data[stack->top];
	stack->top--;
}

//遍历栈并出栈
void list_pop(seqStack* stack)
{
	int temp;

	while(stack->top>=0)
	{
		pop(stack,&temp);
		printf("%d\n",temp);
	}
}

//遍历栈不出栈
void list_nopop(seqStack* stack)
{
	int temp,top1=stack->top;

	while(top1>=0)
	{
		printf("%d\n",stack->data[top1]);
		top1--;
	}
}

//销毁栈
void destroy(seqStack* stack)
{
	free(stack);
	stack=NULL;
}

//主函数
int main()
{
	int a=1;
	seqStack* stack=(seqStack*)malloc(sizeof(seqStack));

	
	stack=create();								//创建空栈
	
	while(a)									//循环入栈
	{
		printf("please input[0 quit]:");
		scanf("%d",&a);
		push(stack,a);
	}

	list_nopop(stack);							//遍历栈且元素不出栈
	list_pop(stack);							//遍历栈且元素出栈
	destroy(stack);								//销毁栈
	return 0;


}
