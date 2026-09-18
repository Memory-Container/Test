#include <stdio.h>
#include <string.h>

int main() {
    char s[150];
    double loi_nhuan;
    
    if (scanf("%s %lf", s, &loi_nhuan) != 2) return 0;
    
    int count_x = 0;
    int count_d = 0;
    int count_c = 0;
    int count_xd = 0;
    
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'X') {
            count_x++;
            if (i + 1 < len && s[i+1] == 'D') {
                count_xd++;
            }
        } else if (s[i] == 'D') {
            count_d++;
        } else if (s[i] == 'C') {
            count_c++;
        }
    }
    
    double luong_ca = (count_x * 354.0) + (count_d * 482.0);
    double he_so = 1.0 + (count_xd * 0.02);
    double lua_chon_1 = (luong_ca * he_so) + (count_c * 604.0);
    
    double lua_chon_2 = (count_x + count_d) * 250.0 + (loi_nhuan * 0.005) + (count_c * 864.0);
    
    printf("%.2f\n", lua_chon_1);
    printf("%.2f\n", lua_chon_2);
    
    if (lua_chon_1 > lua_chon_2) {
        printf("Nen chon 1\n");
    } else {
        printf("Nen chon 2\n");
    }
    
    return 0;
}
