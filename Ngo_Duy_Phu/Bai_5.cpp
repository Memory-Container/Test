#include <stdio.h>

int main() {
    char s[100];
    int n;

    scanf("%s %d", s, &n);


    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'A' + (s[i] - 'A' + n + 26) % 26;
        } 

        else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = 'a' + (s[i] - 'a' + n + 26) % 26;
        }
    }

    printf("%s", s);

    return 0;
}