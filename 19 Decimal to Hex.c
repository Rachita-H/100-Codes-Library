#include <stdio.h>
#include <conio.h>

int main()
{
  int decimalnum, rem, i = 0;
  char hexanum[50];

  printf("Enter a Decimal number: ");
  scanf("%d", &decimalnum);

  while (decimalnum != 0)
  {
    rem = decimalnum % 16;
    if (rem < 10)
      rem = rem + 48;
    else
      rem = rem + 55;
    hexanum[i] = rem;
    i++;
    decimalnum /= 16;
  }

  printf("Equivalent Hexadecimal Value: ");
  for (i = i - 1; i >= 0; i--)
    printf("%c", hexanum[i]);

  getch();
  return 0;
  }
