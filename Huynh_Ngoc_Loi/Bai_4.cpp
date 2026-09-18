#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%d", &N);
    char ten_not[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    for(int i = 1; i <= N; i++){
        char note[10];
        scanf("%s", note);
        int dodai = strlen(note);
        int Quang8 = note[dodai - 1]-'0';
        if(Quang8 < 5){          
            char ten[3] ="";
            strncpy(ten, note, dodai - 1);
            ten[dodai - 1] = '\0';
            int GiaTriNot = -1;
            for (int j = 0; j < 12; j++) {
                if (strcmp(ten, ten_not[j]) == 0){
                    GiaTriNot = j;
                    break;
                }
            }
            int maso = Quang8 * 12 + GiaTriNot;
            printf("%d %d\n", maso, i);
        }
    }
    return 0;
}