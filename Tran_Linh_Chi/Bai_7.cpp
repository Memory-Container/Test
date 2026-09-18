#include <stdio.h>
#include <string.h>

int main() {
    char s[30];
    scanf("%s", s);

    if (strlen(s) != 15 || strncmp(s, "#TBSO", 5) != 0) {
        printf("Khong hop le");
        return 0;
    }

    if (strncmp(s + 5, "CAKES", 5) != 0 &&
        strncmp(s + 5, "DRINK", 5) != 0) {
        printf("Khong hop le");
        return 0;
    }

    for (int i = 10; i < 15; i++) {
        if (s[i] < '0' || s[i] > '9') {
            printf("Khong hop le");
            return 0;
        }
    }

    int A = s[10] - '0';
    int B = s[11] - '0';
    int C = s[12] - '0';
    int D = s[13] - '0';
    int E = s[14] - '0';

    int x = (A + B - C) * D;
    int mod = x % E;

    if (mod < 0)
        mod += E;

    if (A + B + C + D + E != 20 || mod != 3) {
        printf("Khong hop le");
        return 0;
    }

    if (s[5] == 'C')
        printf("Hop le, Banh ngot");
    else
        printf("Hop le, Do uong");

    return 0;
}
