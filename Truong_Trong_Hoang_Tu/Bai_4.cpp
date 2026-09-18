#include <stdio.h>
#include <string.h>
int main() 
{
    int N;
    char *goc[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    char not_nhac[100];
    char phim[5];
    scanf("%d", &N);
    for(int o = 1; o <= N; o++)
    {
       scanf("%s", not_nhac);
       int len = strlen(not_nhac);
       for(int k = 0; k <= len - 1; k++)
       {
          phim[k] = not_nhac[k];
       }
       phim[len - 1] = '\0';
       int val_phim = -1;
       for(int i = 0; i <= 11; i++)
       {
          if(strcmp(phim, goc[i]) == 0)
          {
             val_phim = i;
             break;
          }
       }
       int quang = not_nhac[len - 1] - '0';
       int val = quang * 12 + val_phim;
       if (val < 67) 
       {
          printf("%d %d\n", val, o);
       }
   }
   return 0;
}