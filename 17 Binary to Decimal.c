#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
  int binaryNum, deciNum = 0, i = 0, rem;

  printf("Enter a binary number: ");
  scanf("%d", &binaryNum);

  while (binaryNum != 0)
  {
    rem = binaryNum % 10;
    deciNum = deciNum + rem* pow(2, i);
    i++;
    binaryNum = binaryNum / 10;
  }

  printf("Decimal Value: %d", deciNum);

  getch();
  return 0;
}
