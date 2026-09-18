#include <stdio.h>
#include <string.h>

int main() {
    char code[100];
    scanf("%s", code);
    if (strlen(code) != 15){
        printf("Khong hop le");
    }
    if (strncmp(code, "#TBSO", 5) != 0){
        printf("Khong hop le");
    }
    int loai = 0;
    if (strncmp(code+5, "CAKES", 5) == 0){
        loai = 1;
    } else if (strncmp(code+5, "DRINK", 5) == 0){
        loai = 2;
    } else {
        printf("Khong hop le");
    }
    int A = code[10] -'0';
    int B = code[11] -'0';
    int C = code[12] -'0';
    int D = code[13] -'0';
    int E = code[14] -'0';
    if (A < 0 || A > 9 || B < 0 || B > 9 || C < 0 || C > 9 || D < 0 || D > 9 || E < 0 || E > 9){
        printf("Khong hop le");
    }
    int dk1 =(A+B+C+D+E==20);
    int bieuthuc=(A+B-C)*D;
    int phandu=(bieuthuc%E+E)%E; 
    int dk2=(phandu == 3);
    if (dk1 && dk2) {
        if (loai == 1) {
            printf("Hop le, Banh ngot");
        } else if (loai == 2) {
            printf("Hop le, Do uong");
        }
    } else {
        printf("Khong hop le");
    }
    return 0;
}
