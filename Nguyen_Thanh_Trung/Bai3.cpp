#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    if (N >= 132) return 0;    
    
    const char *note[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    int octaves[131];
    int indexes[131];
    
    int Note;

    for (int i = 0; i < N; i++)
        {
            scanf("%d", &Note);
            octaves[i] = Note / 12;
            indexes[i] = Note % 12;
        }

    for (int i = 0; i < N; i++) {
        printf("%s%d ", note[indexes[i]], octaves[i]);}
    return 0;
}