//Reversing stack using recursion

#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

struct Stack
{
    int s[STACKSIZE];
    int top;
};

int isfull(struct Stack stk)
{
    return(stk.top == (STACKSIZE-1));
}

int isempty(struct Stack stk)
{
    return(stk.top == -1);
}

void push(struct Stack *ps,int data)
{
    ps->s[++(ps->top)] = data;
}

int pop(struct Stack *ps)
{
    return ps->s[(ps->top)--];
}

int stackTop(struct Stack stk)
{
    return stk.s[stk.top];
}

void displayStack(struct Stack stk)
{
    while(!isempty(stk))
    {
        printf(" %d ",pop(&stk));
    }
}

void pushBottom(struct Stack *ps,int data)
{
    int data2;
    if(isempty(*ps))
    {
        push(ps,data);
        return;
    }

    data2 = pop(ps);
    pushBottom(ps,data);
    push(ps,data2);
}

void reverseStack(struct Stack *ps)
{
    int data;
    if(isempty(*ps))
        return;

    data = pop(ps);
    reverseStack(ps);

    pushBottom(ps,data);
}


int main()
{
    struct Stack stk,tmpstk;
    int N,i,data;
    stk.top = -1;
    tmpstk.top = -1;
    printf("\nEnter number of elements : ");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&data);
        push(&stk,data);
    }

    reverseStack(&stk);

    printf("\nSorted data : ");
    displayStack(stk);

    return 0;
}

