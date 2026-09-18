#include <stdio.h>
int main() 
{
    int N;
    int Ni[100] = {0};
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
       scanf("%d", &Ni[i]);
    }
    for(int j = 1; j <= N; j++)
    {
       if(Ni[j] % 12 == 0)
       {
          printf("C");
       }
       if(Ni[j] % 12 == 1)
       {
          printf("C#");
       }
       if(Ni[j] % 12 == 2)
       {
          printf("D");
       }
       if(Ni[j] % 12 == 3)
       {
          printf("D#");
       }
       if(Ni[j] % 12 == 4)
       {
          printf("E");
       }
       if(Ni[j] % 12 == 5)
       {
          printf("F");
       }
       if(Ni[j] % 12 == 6)
       {
          printf("F#");
       }
       if(Ni[j] % 12 == 7)
       {
          printf("G");
       }
       if(Ni[j] % 12 == 8)
       {
          printf("G#");
       }
       if(Ni[j] % 12 == 9)
       {
          printf("A");
       }
       if(Ni[j] % 12 == 10)
       {
          printf("A#");
       }
       if(Ni[j] % 12 == 11)
       {
          printf("B");
       }
       if(Ni[j] >= 0 && Ni[j] <= 11)
       {
          printf("0 ");
       }
       if(Ni[j] >= 12 && Ni[j] <= 23)
       {
          printf("1 ");
       }
       if(Ni[j] >= 24 && Ni[j] <= 35)
       {
          printf("2 ");
       }
       if(Ni[j] >= 36 && Ni[j] <= 47)
       {
          printf("3 ");
       }
       if(Ni[j] >= 48 && Ni[j] <= 59)
       {
          printf("4 ");
       }
       if(Ni[j] >= 60 && Ni[j] <= 71)
       {
          printf("5 ");
       }
       if(Ni[j] >= 72 && Ni[j] <= 83)
       {
          printf("6 ");
       }
       if(Ni[j] >= 84 && Ni[j] <= 95)
       {
          printf("7 ");
       }
       if(Ni[j] >= 96 && Ni[j] <= 107)
       {
          printf("8 ");
       }
       if(Ni[j] >= 108 && Ni[j] <= 119)
       {
          printf("9 ");
       }
       if(Ni[j] >= 120 && Ni[j] <= 131)
       {
          printf("10 ");
       }
    }
    return 0;
}