#include <stdio.h>

int main(){
    char ten_not[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int X;
        scanf("%d", &X);
        int vi_tri = X % 12;
        int Quang = X / 12;
        printf("%s%d ", ten_not[vi_tri], Quang);
    }
    return 0;
}
