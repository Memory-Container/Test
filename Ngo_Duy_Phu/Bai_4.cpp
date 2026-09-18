#include <stdio.h>
#include <string.h>
// Bài này eim đọc k hiểu đề T-T, xin phép eim dùng AI T-T
int get_note_val(char *s) {
    int base = 0;
    if (s[0] == 'C') base = 0;
    else if (s[0] == 'D') base = 2;
    else if (s[0] == 'E') base = 4;
    else if (s[0] == 'F') base = 5;
    else if (s[0] == 'G') base = 7;
    else if (s[0] == 'A') base = 9;
    else if (s[0] == 'B') base = 11;

    int idx = 1;
    if (s[idx] == '#') {
        base += 1;
        idx++;
    }

    int octave = s[idx] - '0';
    return (octave + 1) * 12 + base - 55;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int pos = 1; pos <= N; pos++) {
        char s[10];
        scanf("%s", s);

        int len = strlen(s);
        int octave = s[len - 1] - '0';

        if (octave < 5 || (octave == 5 && s[0] < 'G')) {
            int note_val = get_note_val(s);
            printf("%d %d\n", note_val, pos);
        }
    }
}