#include <stdio.h>
#include <string.h>

int main() 
{
    char ma_giam_gia[150];
    char dau[] = {"#TBSO"};
    char giua1[] = {"CAKES"};
    char giua2[] = {"DRINK"};
    int so_luu_tru[50];
    int hop_le = 0;
    int loai = 0;
    
    scanf("%s", ma_giam_gia);
    
    int len = strlen(ma_giam_gia);
    if(len != 15)
    {
       printf("Khong hop le");
       return 1;
    }
    
    for(int i = 0; i <= 4; i++)
    {
       if(ma_giam_gia[i] != dau[i] )
       {
          printf("Khong hop le");
          return 2;
       }
    }
    
    int k = 0;
    for(int j = 5; j <= 9; j++)
    {
       if(ma_giam_gia[j] != giua1[k] && ma_giam_gia[j] != giua2[k])
       {
          printf("Khong hop le");
          return 3;
       }
       else if(ma_giam_gia[j] == giua1[k] )
       {
          ++hop_le;
          loai = 1;
       }
       else if(ma_giam_gia[j] == giua2[k])
       {
          ++hop_le;
          loai = 2;
       }
       ++k;
    }
    
    int l = 0;
    for(int y = 10; y <= 14; y++)
    {
       so_luu_tru[l] = ma_giam_gia[y] - '0';
       ++l;
    }
    
    if(so_luu_tru[0] == 0 || so_luu_tru[1] == 0 || so_luu_tru[4] == 0)
    {
       printf("Khong hop le");
       return 4;
    }
    else if((((so_luu_tru[0] + so_luu_tru[1] - so_luu_tru[2]) * so_luu_tru[3]) % so_luu_tru[4] + so_luu_tru[4]) % so_luu_tru[4] != 3)
    {
       printf("Khong hop le");
       return 5;
    }
    else if(so_luu_tru[0] + so_luu_tru[1] + so_luu_tru[2] + so_luu_tru[3] + so_luu_tru[4] != 20)
    {
       printf("Khong hop le");
       return 6;
    }
    else
    {
       ++hop_le;
    }
    
    if(hop_le == 6)
    {
       if(loai == 1)
       {
          printf("Hop le, Banh ngot");
       }
       else if(loai == 2)
       {
          printf("Hop le, Do Uong");
       }
    }
    return 0;
}