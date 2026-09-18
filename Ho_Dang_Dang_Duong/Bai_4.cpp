#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int j = 1; j <= n; j++) {
        char s[10];
        scanf("%s", s);
        
        int note_idx = 0;
        
        if (s[0] == 'C') {
            note_idx = 0;
        } else if (s[0] == 'D') {
            note_idx = 2;
        } else if (s[0] == 'E') {
            note_idx = 4;
        } else if (s[0] == 'F') {
            note_idx = 5;
        } else if (s[0] == 'G') {
            note_idx = 7;
        } else if (s[0] == 'A') {
            note_idx = 9;
        } else if (s[0] == 'B') {
            note_idx = 11;
        }
        
        int i = 1;
        if (s[1] == '#') {
            note_idx++;
            i++;
        }
        
        int octave = 0;
        
        while (s[i] != '\0') {
            octave = (octave * 10) + (s[i] - '0');
            i++;
        }
        
        int k = (octave * 12) + note_idx;
        
        if (k < 67) {
            printf("%d %d\n", k, j);
        }
    }
    
    return 0;
}
