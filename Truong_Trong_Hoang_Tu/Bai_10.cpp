#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[] = "Nightily Star";
    int shift = 0;

    char cipherAlphabet[26];
    int used[26] = {0};
    int idx = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        if (isalpha((unsigned char)key[i])) {
            int pos = toupper((unsigned char)key[i]) - 'A';
            if (!used[pos]) {
                used[pos] = 1;
                cipherAlphabet[idx++] = 'A' + pos;
            }
        }
    }

    char remaining[26];
    int rIdx = 0;
    for (int i = 0; i < 26; i++) {
        if (!used[i]) remaining[rIdx++] = 'A' + i;
    }
    for (int i = 0; i < rIdx; i++) {
        cipherAlphabet[idx++] = remaining[(i + shift) % rIdx];
    }

    char decodeTable[26];
    for (int i = 0; i < 26; i++) {
        int pos = cipherAlphabet[i] - 'A';
        decodeTable[pos] = 'A' + i;
    }

    char input[1000];
    if (fgets(input, sizeof(input), stdin) == NULL) return 0;

    int len = strlen(input);
    while (len > 0 && (input[len - 1] == '\n' || input[len - 1] == '\r')) {
        input[--len] = '\0';
    }

    for (int i = 0; input[i] != '\0'; i++) {
        unsigned char c = input[i];
        if (isalpha(c)) {
            int isLower = islower(c);
            char up = toupper(c);
            char plain = decodeTable[up - 'A'];
            putchar(isLower ? tolower((unsigned char)plain) : plain);
        } else {
            putchar(c);
        }
    }
    printf("\n");

    return 0;
}
