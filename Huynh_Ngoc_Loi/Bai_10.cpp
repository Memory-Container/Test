#include <stdio.h>
#include <string.h>

int main() {
    char key[] = "Nightily Star";
    char cipherAlphabet[26];
    int used[26] = {0};
    int count = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        char c = key[i];
        if (c >= 'a' && c <= 'z') c -= 32;   
        if (c >= 'A' && c <= 'Z') {
            int idx = c - 'A';
            if (!used[idx]) {
                used[idx] = 1;
                cipherAlphabet[count++] = c;
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        int idx = c - 'A';
        if (!used[idx]) {
            cipherAlphabet[count++] = c;
        }
    }
    char str[500];
    if (scanf(" %[^\n]", str) != 1) return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            for (int pos = 0; pos < 26; pos++) {
                if (cipherAlphabet[pos] == str[i]) {
                    str[i] = 'A' + pos;
                    break;
                }
            }
        } 
        else if (str[i] >= 'a' && str[i] <= 'z') {
            char upper = str[i] - 32;
            for (int pos = 0; pos < 26; pos++) {
                if (cipherAlphabet[pos] == upper) {
                    str[i] = 'a' + pos;
                    break;
                }
            }
        }
    }
    printf("%s", str);
    return 0;
}
