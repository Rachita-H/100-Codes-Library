#include <stdio.h>

void bubblesort(int a[], int n)
{
  int i,j;
  for (i=0;i<n-1;i++)
  {
    for (j=0;j<n-i-1;j++)
    {
      if (a[j]>a[j+1])
      {
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1] = temp;
      }
    }
  }
}

void printarray(int a[], int n)
{
  int i;
  for (i=0;i<n;i++)
  {
    printf("%d  ", a[i]);
  }
  printf("\n");
}

int main()
{
  int n,i;
  scanf("%d",&n);
  int a[n];

  for(i=0;i<n;i++)
        scanf("%d",&a[i]);

  bubblesort(a,n);
  printarray(a,n);
}
