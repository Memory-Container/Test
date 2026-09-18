#include <stdio.h>
#include <string.h>
int main(){
    int N;
    scanf("%d", &N);
    char notes[100];
    
    int i = 0;
    for(int i = 0; i < N; i++){
        scanf("%s", notes);
    int value = 0;
    if (notes[0] == 'C'){
        value = 0;
    }
    else if (notes[0] == 'D'){
        value = 2;
    }
    else if (notes[0] == 'E'){
        value = 4;
    }
    else if (notes[0] == 'F'){
        value = 5;
    }
    else if (notes[0] == 'G'){
        value = 7;
    }
    else if (notes[0] == 'A'){
        value = 9;
    }
    else if (notes[0] == 'B'){
        value = 11;
    }

    int octave; 
    if (notes[1] == '#'){
        value++;
        octave = notes[2] - '0';
    }
    else{
        octave = notes[1] - '0';
    }
    value += octave * 12;
    
    if (value < 67) {
            printf("%d %d\n", value, i + 1);
        }
    }
    return 0;
}