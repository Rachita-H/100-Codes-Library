
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct node
{
    int data;
    struct node *next;
}node;
typedef struct queue
{
    int count;
    node *f;
    node *r;
}queue;
void init(queue *);
void enqueue(queue *,int );
int isfull(queue *);
int isempty(queue *);
void dequeue(queue *);
void display(node *);
void main()
{
   queue q;
   int ch,item,item_deleted;
   init(&q);
   for(;;)
   {
       printf("\n1.Enqueue\t2.Dequeue\t3.Display\n");
       scanf("%d",&ch);

       switch(ch)
       {
       case 1:
        printf("Enter the element ");
        scanf("%d",&item);
        enqueue(&q,item);
        break;
       case 2:
        dequeue(&q);
        break;
       case 3:
        display(q.f);
        break;
       case 4:
        exit(0);
       }
   }
}
void init(queue *q)
{
    q->count=0;
    q->f=NULL;
    q->r=NULL;
}
void enqueue(queue *q,int item)
{
    node* temp=malloc(sizeof(*temp));
    temp->data=item;
    temp->next=NULL;
    if(isfull(q))
    {
        printf("Queue overflow\n");
        return;
    }
    if(!isempty(q))
    {
     q->r->next=temp;
     q->r=temp;
    }
    else
    {
        q->r=q->f=temp;
    }
        q->count++;
}
int isfull(queue *q)
{
    if(q->count==MAX)
        return 1;
    return 0;
}
int isempty(queue *q)
{
    if(q->count==0)
        return 1;
    return 0;
}
void dequeue(queue *q)
{
    int t;
    node *temp;
    if(isempty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
       t=q->f->data;
       temp=q->f;
       q->f=q->f->next;
       printf("The element dequeued is %d",t);
       free(temp);
    }
}
void display(node *t)
{
    if(t==NULL)
    {
        printf("NULL");
        return ;
    }
    else
    {
        printf("%d\n",t->data);
        display(t->next);
    }
}
