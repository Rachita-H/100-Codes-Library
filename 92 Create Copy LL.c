#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node* list;
list AddRear(list ,int);
list getNode();
void display(list);
list createCopy(list,list);
void main()
{
    list first=NULL,second=NULL;
    int ch,element;
    while(1)
    {
        printf("\n1.Add elements\n2.Display\n3.Create Copy\n4.Display both\n5.exit");
        printf("\nEnter your choice  ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the element");
            scanf("%d",&element);
            first=AddRear(first,element);
            break;
        case 2:
            display(first);
            break;
        case 3:
            second=createCopy(first,second);
            break;
        case 4:
            printf("\nOriginal List\t");
            display(first);
            printf("\nCopied List\t");
            display(second);
            break;
        case 5:
            exit(0);
        }
    }
}
list AddRear(list first,int element)
{
    list temp=getNode();
    temp->data=element;
    temp->next=NULL;
    if(first==NULL)
        {
            first=temp;
            return first;
        }
    else
    {
        list t=first;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
        return first;
    }
}
list getNode()
{
    list temp=malloc(sizeof(*temp));
    if(temp==NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {
        return temp;
    }
}
void display(list first)
{
    list p=first;
    if(first==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(p!=NULL)
        {
            printf("-->%d",p->data);
            p=p->next;
        }
    }
}
list createCopy(list first,list second)
{
    list q=first;
    while(q!=NULL)
    {
        second=AddRear(second,q->data);
        q=q->next;
    }
    return second;
}

