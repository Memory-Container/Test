#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    char tennot[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    for (int i = 0; i < N; i++) {
        int masonot;
        scanf("%d", &masonot);
        int quangtam = masonot / 12;
        int sodu = masonot % 12;
        printf("%s %d ", tennot[sodu], quangtam);
    }
    printf("\n");
    return 0;
}
