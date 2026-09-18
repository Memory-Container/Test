#include <stdio.h>
#include <string.h>
int main(){
    char tenKhach[50];
    char chucVu[10];

    scanf(" %[^\n]", tenKhach);
    scanf(" %[^\n]", chucVu);       

    if (strpbrk(tenKhach, "0123456789")){
        printf("Khong the tao ID");
        return 0;}

    char suffix[10];  
    if (strcmp(chucVu, "NV") == 0){
        strcpy(suffix, "#TBNV");
    }
    else if (strcmp(chucVu, "BT") == 0){
        strcpy(suffix, "#TBKHBT");
    }
    else if (strcmp(chucVu, "VIP") == 0){
        strcpy(suffix, "#TBKHVIP");
    }
    else{
        printf("Khong the tao ID"); return 0;
    }

    for (int i = 0; tenKhach[i] != '\0'; i++) {
        if (tenKhach[i] != ' ') {
            printf("%c", tenKhach[i]);
        }
    }
        printf("%s", suffix);
    return 0;
}