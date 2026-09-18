#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    long long list[n];
    char Note[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }


    for (int i = 1; i <= n; i++) {
        int vitri = list[i-1];
        int quang = vitri / 12, note = vitri % 12;
        printf("%s%d ", Note[note], quang);
         
    }
}