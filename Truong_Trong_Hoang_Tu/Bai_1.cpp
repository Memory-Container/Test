#include <stdio.h>
#include <math.h>
int main() 
{
    int d, sums = 0, sumn;
    scanf("%d", &d);
    if(d % 2 == 0)
    {
       int l = d/2;
       for(int i = 1; i <= l; i++)
       {
          sumn = 0.5 + 0.5 * sqrt(d*d - (2 * i - 1) * (2 * i - 1));
          sums = sums + sumn;
       }
       printf("%d", 4 * sums);
    }
    else
    {
       int l = (d - 1)/2;
       for(int i = 1; i <= l; i++)
       {
          sumn = 1 + 0.5 * sqrt(d*d -4*i*i);
          sums = sums +sumn;
       }
       printf("%d", 1 + 4 * sums);
    }
    return 0;
}