#include <stdio.h>
int main() 
{
    int N, M;
    scanf("%d %d", &N, &M);
    int step = 2*N - 1;
    int A, B;
    int gtrđ[100] = {0};
    int vtr[100] = {0};
    
    for(int j = 1; j <= step; j++)
    {
       if(j <= N)
       {
          gtrđ[j] = gtrđ[j] + j;
       }
       else
       {
          gtrđ[j] = 2 * N - j;
       }
       if(gtrđ[j] <= 0)
       {
          gtrđ[j] = gtrđ[j] + 1;
       }
    }
    for(int o = 1; o <= M; o++)
    {
       scanf("%d %d", &A, &B);
       vtr[A] = vtr[A] + B;
    }
    int sum = 0, kq;
    for(int y = 1; y <= step; y++)
    {
       sum = sum + vtr[y];
       kq = gtrđ[y] + sum;
       if(kq <= 1)
       {
          kq = 1;
       }
       printf("%d ", kq);
    }
    return 0;
}