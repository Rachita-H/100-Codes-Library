#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionsort(int a[], int n)
{
  int i,j;
  for (i=0;i<n-1;i++)
  {
    int min=i;
    for (j=i+1;j<n;j++)
    {
      if (a[j]<a[min])
      {
        min=j;
      }
    }

    swap(&a[min],&a[i]);
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

  selectionsort(a,n);
  printarray(a,n);
}

