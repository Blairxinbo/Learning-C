/*negation of x*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(){
          int x = 10;
          int p = 4;
          int n = 3;
          int y;
          y = invert(x, p, n);
         printf("%d\n", y);
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~ (~ 0 << n) << (p+1-n));
}
