#include <stdio.h>
#include <string.h>

int main() 
{
   char name[200];
   char role[50];
   scanf("%[^\n]\n", name);
   scanf("%s", role);
   
   int len = strlen(name);
   for(int i = 0; i < len - 1; i++)
   {
      if(name[i] >= '0' && name[i] <= '9')
      {
         printf("Khong the tao ID");
         return 1;
      }
   }
   
   int j = 0;
   for (int i = 0; i < len; i++)
   {
      if (name[i] != ' ')
      {
         name[j] = name[i];
         j++;
      }
   }
   name[j] = '\0';
   
   printf("%s#TB%s", name, role);
   return 0;
}