#include <stdio.h>
#include <string.h>

int main(){
    char SoCaVaDuAn[90];
    float loinhuan;
    scanf("%s %f", SoCaVaDuAn, &loinhuan);
    int CaSang = 0;
    int CaToi = 0;
    int CaNgay = 0;
    int SoDuAn = 0;
    int TGLV = strlen(SoCaVaDuAn);
    int i = 0;
    while(i < TGLV){
        if(SoCaVaDuAn[i] == 'X' && i + 1 < TGLV && SoCaVaDuAn[i + 1] == 'D'){
            CaNgay++;
            i += 2;
        }
        else{
            if(SoCaVaDuAn[i] == 'X'){
                CaSang++;
            }
            else if(SoCaVaDuAn[i] == 'D'){
                CaToi++;
            }
            else if(SoCaVaDuAn[i] == 'C'){
                SoDuAn++;
            }
            i++;
        }
    }
        float TongLuongCa = (CaSang * 354) + (CaToi * 482) + CaNgay * (354 +482);
        float ThuongCaNgay = TongLuongCa * (CaNgay *0.02);
        float ThuongDuAn1 = SoDuAn * 604;
        float LuaChon1 = TongLuongCa + ThuongCaNgay + ThuongDuAn1;
        int TongSoCaLamViec = CaSang + CaToi +(CaNgay * 2);
        float LuongTheoGio = TongSoCaLamViec * 5 *50;
        float ThuongLoiNhuan = loinhuan * 0.005;
        float ThuongDuAn2 = SoDuAn * 864;
        float LuaChon2 = LuongTheoGio + ThuongLoiNhuan + ThuongDuAn2;
        printf ("%.2f", LuaChon1);
        printf ("\n%.2f", LuaChon2);
        if (LuaChon1 > LuaChon2){
            printf("\nNen chon 1");
        }
        else{
            printf("\nNen chon 2");
        }
    return 0;
}
