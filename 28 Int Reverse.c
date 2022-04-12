#include <stdio.h>
int main()
{
    int n, rev_num = 0, rem = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while(n != 0)
    {
        rem = n % 10;
        rev_num = rev_num *10 + rem;
        n = n / 10;
    }

    printf("Reversed Integer = %d", rev_num);
    return 0;
}

