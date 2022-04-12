 #include<stdio.h>
 int main()
 {
     int a=0,b=1,num,c,i;

     printf("Enter number of terms: ");
     scanf("%d",&num);

     for(i=0; i<num; i++)
     {
         printf("%d\t",a);
         c = a + b; //next term
         a = b;
         b = c;
     }

     return 0;
 }
