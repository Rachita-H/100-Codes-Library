#include <stdio.h>
#include <conio.h>

int main()
{
  int deciNum, binaryNum[30], i = 0;

  printf("Enter a decimal number: ");
  scanf("%d", &deciNum);

  while (deciNum != 0)
  {
    binaryNum[i] = deciNum % 2;
    i++;
    deciNum = deciNum / 2;
  }

  printf("Equivalent Binary Value: ");
  for (i = (i - 1); i >= 0; i--)
    printf("%d", binaryNum[i]);

  getch();
  return 0;
}
