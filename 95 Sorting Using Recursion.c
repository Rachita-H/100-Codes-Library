

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


//Sorting using recursion
struct Stack sortStack(struct Stack *ps1,struct Stack *ps2)
{
    struct Stack tmpstk;
    int data;

    if(isempty(*ps1))
        return;

    data = pop(ps1);
    while(!isempty(*ps2) && data>stackTop(*ps2))
    {
        push(ps1,pop(ps2));
    }
    push(ps2,data);
    sortStack(ps1,ps2);
}


//Main for sorting using recursion
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

    sortStack(&stk,&tmpstk);

    printf("\nSorted data : ");
    displayStack(tmpstk);

    return 0;
}

