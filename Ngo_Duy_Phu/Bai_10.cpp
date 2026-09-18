#include <stdio.h>
#include <string.h>

int main() {
    char n[100];
    char A[27] = "abcdefghijklmnopqrstuvwxyz";
    char B[27] = "nightlysarbcdefjkmopquvwxz";

    scanf("%[^\n]", n);
    int len = strlen(n);

    for (int i = 0; i < len; i++) {
        if (n[i] == ' ') {
            printf(" ");
            continue;
        }

        int c = 0, hoa = 0;
        char chu = n[i];

        if (n[i] >= 'A' && n[i] <= 'Z') {
            hoa = -32;
            chu = chu + 32;
        }

        while (chu != B[c] && c < 26) {
            c++;
        }

        printf("%c", A[c] + hoa);
    }

    return 0;
}