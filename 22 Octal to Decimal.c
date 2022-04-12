#include <stdio.h>
#include <math.h>

int main()
{
  int octalNum, decimalNum = 0, i = 0;

  printf("Enter an octal number: ");
  scanf("%d", &octalNum);

  while (octalNum != 0)
  {
    decimalNum = decimalNum + (octalNum % 10) *pow(8, i++);
    octalNum = octalNum / 10;
  }

  printf("Equivalent Decimal Value: %d", decimalNum);

  return 0;
}
