#include <stdio.h>
#include <string.h>

int main (){
    char MaGiamGia[20];
    scanf("%s", MaGiamGia);
    if (strlen(MaGiamGia) != 15){
        printf("Khong hop le");
        return 0;
    }
    if (strncmp(MaGiamGia, "#TBSO", 5) != 0){
        printf ("Khong hop le");
        return 0;
    }
    int PhanLoai = 0;
    if (strncmp(MaGiamGia + 5, "CAKES", 5) == 0){
        PhanLoai = 1;
    }
    else if (strncmp(MaGiamGia + 5, "DRINK", 5) == 0){
        PhanLoai = 2;
    }
    if (PhanLoai != 1 && PhanLoai != 2){
        printf ("Khong hop le");
        return 0;
    }
    int A = MaGiamGia[10] - '0';
    int B = MaGiamGia[11] - '0';
    int C = MaGiamGia[12] - '0';
    int D = MaGiamGia[13] - '0';
    int E = MaGiamGia[14] - '0';
    int MienGiaTri = (A >= 1 && A <= 9)&& 
                    (B >= 1 && B <= 9)&&
                    (C >= 0 && C <= 9)&&
                    (D >= 0 && D <= 9)&&
                    (E >= 1 && E <=9);
    if (MienGiaTri && A + B + C + D + E && ((A + B - C) * D) % E){
        if (PhanLoai == 1){
            printf("Hop le, Banh Ngot");
        }
        else if (PhanLoai == 2){
            printf("Hop le, Do uong");
        }
    }
    else {
        printf("Khong hop le");
    }
    return 0;
}
