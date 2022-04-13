#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *list;
list getNode();
list AddFront(list);
void display(list ,list);
void compare(list ,list);
void main()
{
   list first=NULL,second=NULL;
   int ch;
   while(1)
   {
       printf("\n\nenter your choice\n1.Add elements for list 1\n2.Display elements\n3.Compare the lists\n4.exit\n5.Add elements for list 2\n");
       scanf("%d",&ch);
       switch(ch)

       {
       case 1:
              first=AddFront(first);
              break;
        case 2:
              display(first,second);
              break;
       case 3:
             compare(first,second);
             break;
       case 4:
             exit(0);
             break;
        case 5 :
            second=AddFront(second);
            break;
       }
   }
}
list getNode()
{
    list temp=malloc(sizeof(*temp));
    if(temp==NULL)
    {
        printf("memory is not allocated");
    }
    else
    {
        printf("Enter the element ");
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp->prev=NULL;
        return temp;
    }
}
list AddFront(list first)
{
    list temp=getNode();

    if(first==NULL)
    {
        first=temp;
        return first;
    }
    else
    {
     temp->next=first;
     first->prev=temp;
     first=temp;
     return first;
    }
}
void display(list first,list second)
{
    if(first==NULL || second==NULL)
        printf("one of the list is empty");
    else
    {
        list t=first,r=second;
        printf("\nList 1 :");
        while(t!=NULL)
        {
            printf("%d-->",t->data);
            t=t->next;
        }
        printf("\nList 2 :");
        while(r!=NULL)
        {
            printf("%d-->",r->data);
            r=r->next;
        }

    }
}
void compare(list first,list second)
{
    int flag=0;
    list a=first,b=second;
    while(a!=NULL && b!=NULL)
    {
        if(a->data!=b->data)
        {
            flag=1;
            break;
        }
        a=a->next;
        b=b->next;
    }
         if(flag==1)
            printf("lists are not equal");
        if(flag==0)
            printf("list are equal");
}

