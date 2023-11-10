#include<stdio.h>
#include<stdlib.h>
#define NODEALLOC (struct node *)malloc(sizeof(struct node))
struct node
{
   int data;
   struct node *next;
}*front,*rear,*newnode;

void init()
{
    front=rear=NULL;
}

int isempty()
{
   if(front==NULL||front>rear)
    return 1;
   else
     return 0;
}

void enqueue(int num)
{
   newnode=NODEALLOC;
   newnode->data=num;
   if(front==NULL)
    {
       front=rear=newnode;
    }
   else
   {
      rear->next=newnode;
      rear=newnode;
   }
}

void dequeue()
{
    struct node *temp;
    int val;
    if(isempty())
     printf("\n queue is undeflow:");
   else
    {
       val=front->data;
      temp=front;
      front=front->next;
      free(temp);

     printf("\n deleted value=%d",val);
    }
}
void peek()
{
   printf("\ntop element=%d",front->data);
}

int main()
{
   int ch,num;
   do
   {
     printf("\n1-enqueue \n2-dequeue \n3-peek");
    printf("\n enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("\n enter the number:");
              scanf("%d",&num);
              enqueue(num);
              break;
       case 2:dequeue();
               break;
       case 3:peek();
              break;
        default :printf("\n invalid choice:");
    }
  }while(ch<4);
}
