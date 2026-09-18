#include <stdio.h>
#include <string.h>
int main(){

    char code[16];
    if (scanf("%s", code) != 1) return 0;

    if (strlen(code) != 15 || strncmp(code, "#TBSO", 5) != 0) {
        printf("Khong hop le");
        return 0;
    }

    char maSale[6];
    strncpy(maSale, code + 5, 5);
    maSale[5] = '\0';

    const char *tenSale;

    if (strcmp(maSale, "CAKES") == 0)
    {
        tenSale = "Banh ngot";
    }
    else if(strcmp(maSale, "DRINK") == 0){
        tenSale = "Do uong";
    }
    else{printf("Khong hop le"); return 0;}

    int A = code[10] - '0';
    int B = code[11] - '0';
    int C = code[12] - '0';
    int D = code[13] - '0';
    int E = code[14] - '0';

    if (A < 1 || A > 9 || B < 1 || B > 9 || E < 1 || E > 9){printf("Khong hop le"); return 0;}
    if (C < 0 || C > 9 || D < 0 || D > 9){printf("Khong hop le");return 0;} 

    int sum = A + B + C + D + E;
    int modResult = (((A + B - C) * D) % E + E) % E;

    if (sum == 20 && modResult == 3){{
            printf("Hop le, %s",tenSale);
        }
    }
    else{printf("Khong hop le");}
    
    return 0;
}