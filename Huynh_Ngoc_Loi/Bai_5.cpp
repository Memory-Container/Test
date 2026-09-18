#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    const int LOWER_TO_UPPER_DELTA = 32;
    const int ALPHABET_LENGTH = 26;
    char stringInput[1000] = {0};
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int isUpper = 0;
    int shift = 0;
    scanf("%s %d", &stringInput, &shift);
    shift = shift < 0 ? shift += ALPHABET_LENGTH : shift;
    for (int i = 0; stringInput[i] != '\0';i++, isUpper = 0){
        if (stringInput[i] >= 'A' && stringInput[i] <= 'Z'){
            isUpper = 1;
            stringInput[i] += LOWER_TO_UPPER_DELTA;
        }
        int index = (stringInput[i] - 'a' + shift) % ALPHABET_LENGTH;
        stringInput[i] = alphabet[index];
        if (isUpper) {
            stringInput[i] -= LOWER_TO_UPPER_DELTA;
        }
    }
    printf("%s", stringInput);
    return 0;
}
