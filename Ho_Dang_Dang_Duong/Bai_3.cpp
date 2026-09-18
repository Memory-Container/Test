#include <stdio.h>

int main() {
    char notes[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    
    int n;
    scanf("%d", &n)
    
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        
        int note_index = k % 12;
        int octave = k / 12;
        
        printf("%s%d ", notes[note_index], octave);
    }
    return 0;
}
