#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *list;
list getNode();
list AddFront(list);
void display(list );
void displayk(list);
void main()
{
   list first=NULL;
   int ch;
   while(1)
   {
       printf("\n\nenter your choice\n1.Add elements\n2.Display elements\n3.Display K th element\n4.exit\n");
       scanf("%d",&ch);
       switch(ch)

       {
       case 1:
        first=AddFront(first);
        break;
       case 2:
        display(first);
        break;
       case 3:
        displayk(first);
        break;
       case 4:
        exit(0);
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
     first=temp;
     return first;
    }
}
void display(list first)
{
    if(first==NULL)
        printf("list is empty");
    else
    {
        list t=first;
        printf("Forward display\t");
        while(t->next!=NULL)
        {
            printf("%d-->",t->data);
            t=t->next;
        }
        printf("%d",t->data);
    }
}
void displayk(list first)
{
    list p=first;
    int k,i,count=1;
    printf("enter k");
    scanf("%d",&k);
    if(k==0)
    {
        printf("Not available\n");
    }
    else
    {
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    if(count<k)
        printf("cannot display the element ");

    else
    {
        p=first;
        for(i=1;i!=k;i++)
            {
                p=p->next;
            }
        printf("\n** %d **",p->data);
    }
    }
}
