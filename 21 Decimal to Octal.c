#include <stdio.h>

int main()
{
  int deciNum, octalNum = 0, rem, i = 1;

  printf("Enter a Decimal number: ");
  scanf("%d", &deciNum);

  while (deciNum != 0)
  {
    rem = deciNum % 8;
    octalNum = (rem *i) + octalNum;
    deciNum /= 8;

    i *= 10;
  }

  printf("Equivalent Octal Value: %d", octalNum);

  return 0;
}
