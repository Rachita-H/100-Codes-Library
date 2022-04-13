#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 25
struct stack
{
	char data[SIZE];
	int top;
};
typedef struct stack STK;

int full(STK );
int empty(STK );
void PUSH(STK *,char );
char POP(STK *);
int check_parenthesis(STK *,char expression[20]);
void main()
{
	STK s;
	int flag=0;

	s.top=-1;//Initially stack top points to -1
    char expression[20];
    printf("Enter expression\n");
    scanf("%s",expression);
    flag=check_parenthesis(&s,expression);
    if(flag==1)
    {
        printf("Balanced parenthesis\n");
    }
    else
    {
        printf("Not Balanced parenthesis\n");
    }

}
int match(char a,char b) // To check popped and expression[i] brackets are same.
{
    if(a=='(' && b==')')
        return 1;
    else if(a=='{' && b=='}')
        return 1;
    else if(a=='[' && b==']')
        return 1;
    else
        return 0;
}

int check_parenthesis(STK *s,char expression[20]) // Check the parenthesis , if balanced returns 1 else 0
{
    int i;char temp;
    for(i=0;i<strlen(expression);i++)
    {
        if(expression[i]=='(' || expression[i]=='[' ||expression[i]=='{')
            {

                PUSH(s,expression[i]);
            }
        if(expression[i]==')' || expression[i]==']' || expression[i]=='}')
            {
                if(s->top==-1) // handles } or ) or ]
                {
                    printf("Right parenthesis are more, Its not balanced\n");
                    return 0;
                }
                else
                {
                        temp=POP(s);
                        if(!match(temp,expression[i]))
                        {
                              printf("The Mismatched Parentheses in the Expression are:\t%c and %c\n", temp, expression[i]);
                              return 0;
                        }
                }
            }
    }
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full(STK s)
{
	if(s.top==SIZE-1)
		return 1;
	else
		return 0;
}

int empty(STK s)
{
	if(s.top==-1)
		return 1;
	else
		return 0;
}

void PUSH(STK *ps,char e)
{
	if(full(*ps))
	{
		printf("\nStack Overflow!!");

	}
	else
    {
        ps->top++;
        ps->data[ps->top]=e;
    }
}

char POP(STK *ps)
{
	char temp;

	if(empty(*ps))
	{
		printf("\nStack Underflow");
		return -1;
	}
	else
    {
        temp=ps->data[ps->top];
        ps->top--;
        return temp;
    }
}





