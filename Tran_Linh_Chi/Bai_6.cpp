#include <stdio.h>
#include <string.h>

int main()
{
    char ten[50];
    char loai[10];
    int sai = 0;

    scanf("%[^\n]", ten);

    scanf("%s", loai);

    for (int i = 0; ten[i] != '\0'; i++)
    {
        if (ten[i] >= '0' && ten[i] <= '9')
        {
            sai = 1;
            break;
        }
    }

    if (strcmp(loai, "NV") == 0)
    {

    }
    else if (strcmp(loai, "BT") == 0)
    {

    }
    else if (strcmp(loai, "VIP") == 0)
    {
  
    }
    else
    {
        sai = 1;
    }

    if (sai)
    {
        printf("Khong the tao ID");
        return 0;
    }

    for (int i = 0; ten[i] != '\0'; i++)
    {
        if (ten[i] != ' ')
        {
            printf("%c", ten[i]);
        }
    }

    // Tao ID
    if (strcmp(loai, "NV") == 0)
    {
        printf("#TBNV");
    }
    else
    {
        printf("#TBKH%s", loai);
    }

    return 0;
}
