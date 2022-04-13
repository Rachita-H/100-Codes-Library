#include <stdio.h>
#include <malloc.h>

struct queue
{
    int Rear, Front,size;
    int queue_array[30];
};

struct queue * create_queue(struct queue *, int);
void insert (struct queue *, int);
int del (struct queue *);
void display(struct queue *);
int isempty(struct queue *);
int isfull(struct queue *);

int main()
{
  struct queue *Q;
  int x,ch=0,sz;
  printf("Enter size of the Queue: ");
  scanf("%d",&sz);
  Q=create_queue(Q,sz);
  while (ch!=4)
  {
      printf("\n1:InsertRear\n2:Display\n3:DeleteFront\n4:Exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: printf("enter the element\n");
                  scanf("%d",&x);
                  insert(Q,x);
                  break;
          case 2: printf("elements in queue\n");
                  display(Q);
                  break;
          case 3: x=del(Q);
                   if (x>0)
                       printf("element deleted %d\n",x);
                   else
                       printf("queue is empty\n");
                   break;
          case 4: printf("end\n");
                  exit(0);
        default : printf("Enter Correct Choices\n");
                    break;
      }//void insert (struct queue *, int); switch
  }// while
}

struct queue * create_queue(struct queue *q, int s)
{
    q=malloc(sizeof(struct queue));
    q->Rear =-1;
    q->Front=0;
    q->size =s;
    return (q);
};

int isfull(struct queue *q)
{
    if(q->Rear== (q->size-1) && q->Front==0)
        return 1;
    else
        return 0;
}

void insert (struct queue *q, int m)
{
    if (isfull(q))
        printf("queue is full can not insert\n");
    else
        {

        if ( q->Front == -1)
                q->Front = q->Rear = 0;
        else
            q->Rear++;

        q->queue_array[q->Rear]=m;
        }
}

int del (struct queue *q)
{
    int m=-1;
    if(isempty(q))
       printf("queue empty\n");

   else
   {
       m=q->queue_array[q->Front];
       q->Front++;

   }
    return m;
}

void display(struct queue *q)
{
    int i;
    if(isempty(q))
        printf("queue is empty can not display\n");
    else
      for(i=q->Front;i<=q->Rear;++i)
         printf("%4d",q->queue_array[i]);
}

int isempty(struct queue *q)
{
    if (q->Rear < q->Front)
      return 1;
    else
       return 0;
}

