#include <stdio.h>

int stack[50], stackSize, topElmt;

void push(void);
void pop(void);
void display(void);

int main()
{
  int choices;
  topElmt = -1;
  printf("Enter the size for STACK:");
  scanf("%d", &stackSize);

  printf("--------------------------------");
  printf("\n STACK OPERATIONS USING ARRAY");
  printf("\n--------------------------------");

  printf("\nPress 1 to PUSH");
  printf("\nPress 2 to POP");
  printf("\nPress 3 to DISPLAY");
  printf("\nPress 4 to EXIT");

  do {
    printf("\nEnter Your Choice:");
    scanf("%d", &choices);

    switch (choices)
    {
      case 1:
        {
         //calling PUSH() Function
          push();
          break;
        }

      case 2:
        {
         //calling POP() Function
          pop();
          break;
        }

      case 3:
        {
         //calling DISPLAY() Function
          display();
          break;
        }

      case 4:
        {
          printf("\n---------END----------");
          break;
        }

      default:
        {
          printf("\nWrong Choice.");
        }
    }
  }

  while (choices != 4);
  return 0;
}

//PUSH Function
void push()
{
  int x;

 //Checkfor if STACK is FULL or NOT
  if (topElmt >= stackSize - 1)
  {
    printf("\nSTACK is OVERFLOW");

  }
  else
  {
    printf("Enter an Integer that you want to insert: ");
    scanf("%d", &x);
    topElmt++;
    stack[topElmt] = x;
  }
}

//POP Function
void pop()
{
 //Check if STACK is EMPTY or NOT
  if (topElmt <= -1)
  {
    printf("\nSTACK is UNDERFLOW");
  }
  else
  {
   //displaying removed element from top oa a STACK
    printf("\nThe popped(removed) elements is %d", stack[topElmt]);
    topElmt--;
  }
}

//DISPLAY Function
void display()
{
  int i;
  if (topElmt >= 0)
  {
    printf("The Elements present in a STACK are: ");

    for (i = topElmt; i >= 0; i--)
    {
      printf("\n%d", stack[i]);
    }

    printf("\nEnter Your Choice");
  }
  else
  {
    printf("\n The STACK is empty");
  }
}
