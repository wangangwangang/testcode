#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
 int num;
 struct student *left;
 struct student *right;
}STU,*PSTU;

//创建二叉树
void creat_twotree(PSTU *ps)
{
  int n;
  printf("请输入学生学号");
  scanf("%d",&n);
  if(n<=0)
   (*ps)=NULL;
   else
   {
     (*ps)=malloc(sizeof(STU));
     (*ps)->num=n;
     creat_twotree(&(*ps)->left);
     creat_twotree(&(*ps)->right);
   }
}

//先序遍历
int preorder(PSTU ps)
{
 if(NULL==ps)
   return 0;
   else
   {
   printf("%-5d",ps->num);
   preorder(ps->left);
   preorder(ps->right);
   }
}

//中序遍历
int inorder(PSTU ps)
{
 if(NULL==ps)
   return 0;
   else
   {
   inorder(ps->left);
   printf("%-5d",ps->num);
   inorder(ps->right);
   }
}


//后序遍历
int afterorder(PSTU ps)
{
 if(NULL==ps)
   return 0;
   else
   {
   afterorder(ps->left);
   afterorder(ps->right);
   printf("%-5d",ps->num);
   }
}



int main()
{
  PSTU head;
  creat_twotree(&head);
  //先序遍历
  preorder(head);
  printf("\n");
  //中序遍历
  inorder(head);
  printf("\n");
  //后续遍历
  afterorder(head);
  printf("\n");

  return 0;
}
