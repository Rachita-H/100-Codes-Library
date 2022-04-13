#include<stdio.h>
#include<stdlib.h>
#define MAX 4
typedef struct queue
{
    int data[MAX];
    int count;
    int f,r;
}queue;
void init(queue *);
void enqueue(queue *,int );
void dequeue(queue *);
void display(queue *,int );
int isfull(queue *);
int isempty(queue *);
void main()
{
    queue q[3];
    int ch,item,i,qn;
    for(i=0;i<3;i++)
        init(&q[i]);
    for(;;)
    {
        printf("1.enqueue\t2.Dequeue\t3.Display\t4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the queue no (<3) ; ");
            scanf("%d",&qn);
            printf("enter the number : ");
            scanf("%d",&item);
            if(qn<=3 && qn !=0)
                enqueue(&q[qn-1],item);
            else
                printf("enter queue no <3 \n");
            break;
        case 2:
             printf("Enter the queue no (<3) ; ");
            scanf("%d",&qn);
               if(qn<=3 && qn!=0)
                dequeue(&q[qn-1]);
            else
                printf("enter queue no <3 \n");
            break;
        case 3:
            for(i=0;i<3;i++)
                display(&q[i],i);
                break;
        case 4:
            exit(0);
        }
    }
}
void init(queue *q)
{
    q->count=0;
    q->f=-1;
    q->r=-1;
}

void enqueue(queue *q,int item)
{
    if(isfull(q))
    {
        printf("Queue overflow\n");
        return;
    }
   q->data[++q->r]=item;
   if(q->r==0)
    q->f=0;
}
int isfull(queue *q)
{
    if(q->r==MAX-1)
        return 1;
    return 0;
}
void dequeue(queue *q)
{
    if(isempty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    q->f++;
    if(q->f>q->r)
        {
            q->f=-1;
            q->r=-1;
        }
}
int isempty(queue *q)
{
     if(q->f>q->r)
        return 1;
     return 0;
}
void display(queue *q,int i)
{
    int m,n,j;
    m=q->f;
    n=q->r;
    if(m>n)
    {
        printf("Queue is empty ");
        return ;
    }
    printf("Elements in the Queue are :\n");
    printf("Queue %d : ",i+1);
    for(j=m;j<=n;j++)
    printf("%d\t",q->data[j]);
    printf("\n");
}
