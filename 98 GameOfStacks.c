#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct stack
{
    int data[SIZE];
    int top;
};
typedef struct stack STK;


void PUSH(STK *s,int num)
{
    if(isFull(s))
    {
        printf("\nStack Overflow!!");

    }
    else
    {
        s->top++;
        s->data[s->top]=num;
    }
}

int POP(STK *s)
{
    int temp;
    if(isEmpty(s))
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        temp=s->data[s->top];
        s->top--;
        return temp;
    }
}

int isFull(STK *s)
{
    if(s->top==SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty(STK *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

int isprime(int n)
{
    int i,c=0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
            c++;

    }
    if(c==2)
        return 1;
    else
        return 0;
}


void main()
{
    STK A,B;
    int ch,t,e;
    static int f=0,c=0;

    A.top=-1;
    B.top=-1;

    void GAME()
    {
        while(1)
        {
            printf("\nGAME MENU:\n\n1. Pop elements from A\n2. Pop elements from B\n");
            printf("\nSelect your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: t=POP(&A);
                    if(!isprime(t) && !isEmpty(&A))
                    {
                        f++;
                        printf("Popped successfully!\n");
                    }
                    if(isprime(t) || isEmpty(&A))
                    {
                         printf("GAME OVER!!!\n");
                         t=c+f;
                         printf("\nFinal score is: %d",t);
                         exit(0);
                    }
                    break;
                 case 2: t=POP(&B);
                    if(!isprime(t) && !isEmpty(&B))
                    {
                        c++;
                        printf("Popped successfully!\n");
                    }
                    if(isprime(t) || isEmpty(&B))
                    {
                         printf("GAME OVER!!!\n");
                         t=c+f;
                         printf("\nFinal score is: %d",t);
                         exit(0);
                    }
                    break;
                default: printf("Wrong Choice\n");
            }}}
    printf("First enter some elements in both the stacks then start the game.\n");
    while(1)
    {
        printf("\nMENU:\n\n1. Push elements in A\n2. Push elements in B\n3. Start the Game\n");
        printf("\nSelect your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element: ");
                    scanf("%d",&e);
                    PUSH(&A,e);
                    break;
            case 2: printf("\nEnter element: ");
                    scanf("%d",&e);
                    PUSH(&B,e);
                    break;
            case 3: printf("\nENJOY THE GAME!\n");
                    GAME();
                    break;
            default: printf("Wrong Choice\n");
        }

    }

    }




