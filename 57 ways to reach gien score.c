#include <stdio.h>
int count_number_of_ways(int n, int points[], int tot)
{
int arr[n + 1], i, j;
for(j = 0; j < n + 1; j++)
arr[j] = 0;
arr[0] = 1;
while(tot--)
{
for (i = points[tot]; i <= n; i++)
arr[i] += arr[i - points[tot]];
}
return arr[n];
}
int main()
{
int n, tot;
printf("Enter the score : ");
scanf("%d", &n);
printf("Enter the total number of points : ");
scanf("%d", &tot);
int points[tot];
printf("Enter the points per move : ");
int i;
for(i = 0; i < tot; i++)
{
scanf("%d", &points[i]);
}
printf("Number of ways to get the score %d is %d",n, count_number_of_ways(n, points, tot));
return 0;
}
