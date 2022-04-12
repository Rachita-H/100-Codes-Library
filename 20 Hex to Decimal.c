#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
  int decimal = 0, rem, i = 0, len = 0;
  char hexadecimal[20];

  printf("Enter a Hexadecimal number: ");
  scanf("%s", hexadecimal);

  while (hexadecimal[i] != '\0')
  {
    len++;
    i++;
  }

  len--;
  i = 0;
  while (len >= 0)
  {
    rem = hexadecimal[len];
    if (rem >= 48 && rem <= 57)
      rem = rem - 48;
    else if (rem >= 65 && rem <= 70)
      rem = rem - 55;
    else if (rem >= 97 && rem <= 102)
      rem = rem - 87;

    decimal = decimal + (rem* pow(16, i));
    len--;
    i++;
  }

  printf("Equivalent Decimal Value: %d", decimal);

  getch();
  return 0;
}
