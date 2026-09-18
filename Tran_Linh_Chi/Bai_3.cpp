#include <stdio.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    const char *note_names[] = {
        "C", "C#", "D", "D#", "E", "F", 
        "F#", "G", "G#", "A", "A#", "B"
    };

    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);

        int note_idx = val % 12;
        int octave = val / 12; // Thay (val + 9) / 12 thành val / 12

        printf("%s%d", note_names[note_idx], octave);

        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
