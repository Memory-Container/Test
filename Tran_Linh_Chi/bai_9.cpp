#include <stdio.h>

int main() {
    char S[100];
    double loi_nhuan;

    scanf("%s %lf", S, &loi_nhuan);

    int X = 0, D = 0, C = 0, XD = 0;

    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == 'X')
            X++;
        else if (S[i] == 'D')
            D++;
        else if (S[i] == 'C')
            C++;
    }

    for (int i = 0; S[i + 1] != '\0'; i++) {
        if (S[i] == 'X' && S[i + 1] == 'D')
            XD++;
    }

    double luong1 = X * 354 + D * 482 + C * 604;
    luong1 = luong1 * (1 + XD * 0.02);

    int gio = (X + D) * 5;
    double luong2 = gio * 50 + loi_nhuan * 0.005 + C * 864;

    printf("%.2f\n", luong1);
    printf("%.2f\n", luong2);

    if (luong1 >= luong2)
        printf("Nen chon 1");
    else
        printf("Nen chon 2");

    return 0;
}
