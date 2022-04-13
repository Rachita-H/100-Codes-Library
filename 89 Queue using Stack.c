#include<stdio.h>
#include<stdlib.h>
# define MAX 5
typedef struct stack
{
    int data[MAX];
    int top;
}stack ;
typedef struct queue
{
    stack s1;
    stack s2;
}queue;
void initQ(queue *);
void initS(stack *);
int isfullQ(queue *);
int isfullS(stack *);
int isemptyQ(queue *);
int isemptyS(stack *);
void push(stack *,int);
int pop(stack *);
void enqueue(queue *,int);
void dequeue(queue *);
void displayQ(queue *q);
void displayS(stack *s);
void main()
{
    int ch,item;
    queue q;
    initQ(&q);
    for(;;)
    {
        printf("Enter your choice\n 1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            scanf("%d",&item);
            enqueue(&q,item);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            displayQ(&q);
            break;
        case 4:
            exit(0);
        }
    }
}
void initQ(queue *q)
{
    initS(&(q->s1));
    initS(&(q->s2));
}
void initS(stack *s)
{
    s->top=-1;
}
void enqueue(queue *q,int item)
{
    int x;
    if(isfullQ(q))
    {
        printf("Queue overflow\n");
        return;
    }
    while(!isemptyS(&(q->s1)))
        push(&(q->s2),x=pop(&(q->s1)));

    push(&(q->s1),item);

    while(!isemptyS(&(q->s2)))
        push(&(q->s1),x=pop(&(q->s2)));
}
int isfullQ(queue *q)
{
    if(isfullS((&q->s1)))
        return 1;
    if(isfullS((&q->s2)))
        return 1;
    return 0;
}
int isfullS(stack *s)
{
    if(s->top==MAX-1)
        return 1;
    return 0;
}
void push(stack *s,int item)
{
    if(isfullS(s))
    {
        printf("stack is full\n");
        return;
    }
    s->data[++s->top]=item;
}
void dequeue(queue *q)
{
    if(isemptyQ(q))
    {
        printf("Queue underflow");
        return;
    }
    pop(&(q->s1));
}
int isemptyQ(queue *q)
{
    if(isemptyS(&(q->s1)))
        return 1;
    return 0;
}
int isemptyS(stack *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
int pop(stack *s)
{
    int x;
    if(isemptyS(s))
    {
        printf("stack is empty ");
        return ;
    }
    x=s->data[s->top];
    s->top--;
    return x;
}
void displayQ(queue *q)
{
    if(isemptyS(&(q->s1)))
    {
        printf("Queue is empty ");
        return;
    }
    displayS(&(q->s1));
}
void displayS(stack *s)
{
    int t=s->top;
    while(s->top!=-1)
    {
        printf("%d\n",s->data[s->top]);
        s->top--;
    }
    s->top=t;
}

