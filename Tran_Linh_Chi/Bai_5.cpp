#include <stdio.h>

int main() {
    char s[100];
    int N;

    scanf("%s %d", s, &N);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' + N + 26) % 26 + 'A';

        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' + N + 26) % 26 + 'a';
    }

    printf("%s", s);

    return 0;
}
