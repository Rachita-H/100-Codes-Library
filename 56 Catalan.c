#include <stdio.h>

unsigned long int catalan(unsigned int n) {

   if (n <= 1) return 1;
   // catalan(n) is sum of catalan(i)*catalan(n-i-1)
   unsigned long int res = 0;
   int i;
   for (i=0; i<n; i++)
      res += catalan(i)*catalan(n-i-1);
   return res;
}

int main() {
   int n = 6;
   printf("catalan is :%ld\n", catalan(n));
   return 0;
}
