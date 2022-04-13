#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int prio;
    struct node* next;
}node;
typedef struct queue
{
    int count;
    node* f,*r;
}queue;
node* display(queue *);
int isempty(queue *);
void dequeue(queue *);
void enqueue(queue *,int ,int);
void main()
{
   int ch,item,p;
   queue q;
   q.count=0;
   q.f=NULL;
   q.r=NULL;
   while(1)
   {
       printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.exit");
       scanf("%d",&ch);
       switch(ch)
       {
       case 1:
        printf("Enter the number : ");
        scanf("%d",&item);
        printf("Enter the priority : ");
        scanf("%d",&p);
        enqueue(&q,item,p);
        break;
       case 2:
        dequeue(&q);
        break;
       case 3:
        q.f=display(&q);
        break;
       case 4:
        exit(0);
       }
   }
}
void enqueue(queue *q,int item,int p)
{
    node *cur,*pre;
    node *temp=malloc(sizeof(*temp));
    if(temp==NULL)
        return;

    temp->data=item;
    temp->prio=p;
    temp->next=NULL;

    if(q->f==NULL)
    {
        q->f=temp;
        q->r=temp;
    }
    else
    {
       cur=q->f;
       pre=NULL;
       while(cur!=NULL && p > cur->prio)
       {
           pre=cur;
           cur=cur->next;

       }
       if(pre!=NULL)
       {
          pre->next=temp;
          temp->next=cur;
          printf("A");
       }
       else if(pre==NULL)
       {
           q->f=temp;
           temp->next=cur;
              printf("B");
       }
       else if(cur==NULL)
       {
           pre->next=temp;
           q->r=temp;
           printf("C");
       }
    }
    q->count++;
}
void dequeue(queue *q)
{
    if(isempty(q))
    {
        printf("Queue is empty ");
        return;
    }
    node*temp=q->f;
    q->f=q->f->next;
    printf("The deleted item is %d \n",temp->data);
    free(temp);
}
int isempty(queue *q)
{
    if(q->count==0)
        return 1;
    return 0;
}
node* display(queue *q)
{
    node *temp;
    temp=q->f;
    if(isempty(q))
    {
        printf("the queue is empty ");
        return temp;
    }
    while(q->f!=NULL)
    {
        printf("%d-->",q->f->data);
        q->f=q->f->next;
    }
    return temp;
}

