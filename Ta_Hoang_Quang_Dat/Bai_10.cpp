#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char chuoi_duoc_ma_hoa[1005];
    if (scanf("%[^\n]", chuoi_duoc_ma_hoa) != 1) return 0;
    char key_str[] = "NIGHTLYSARBCDEFJKMOPQUVWXZ";
    char map[256];
    for (int i = 0; i < 256; i++) map[i] = i;
    for (int i = 0; i < 26; i++) {
        map[key_str[i]] = 'A' + i;
        map[tolower(key_str[i])] = 'a' + i;
    }
    int len = strlen(chuoi_duoc_ma_hoa);
    for (int i = 0; i < len; i++){
        if (isalpha(chuoi_duoc_ma_hoa[i])) {
            printf("%c", map[chuoi_duoc_ma_hoa[i]]);
        } else {
            printf("%c", chuoi_duoc_ma_hoa[i]);
        }
    }
    return 0;
}
