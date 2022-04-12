#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 'a';
    int x = 32;
    c = c & ~32;
    printf("%c\n", c);
}

