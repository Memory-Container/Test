#include <stdio.h>
#include <string.h>

int main() {
    char s[50];
    scanf("%s", s);

    if (strlen(s) != 15) {
        printf("Khong hop le");
        return 0;
    }

    if (strncmp(s, "#TBSO", 5) != 0) {
        printf("Khong hop le");
        return 0;
    }

    char tam[6];
    strncpy(tam, s + 5, 5);
    tam[5] = '\0';

    char sp[30];
    if (strcmp(tam, "CAKES") == 0) {
        strcpy(sp, "Banh ngot");
    } else if (strcmp(tam, "DRINK") == 0) {
        strcpy(sp, "Do uong");
    } else {
        printf("Khong hop le");
        return 0;
    }

    int a = s[10] - '0';
    int b = s[11] - '0';
    int c = s[12] - '0';
    int d = s[13] - '0';
    int e = s[14] - '0';

    if (a < 1 || a > 9 || b < 1 || b > 9 || e < 1 || e > 9 || c < 0 || c > 9 || d < 0 || d > 9) {
        printf("Khong hop le");
        return 0;
    }

    if (((a + b - c) * d) % e == 3 && (a + b + c + d + e) == 20) {
        printf("Hop le, %s", sp);
    } else {
        printf("Khong hop le");
    }

}