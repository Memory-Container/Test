#include <stdio.h>
#include <string.h>

int main() 
{
    const int low_to_upper_delta = 32;
    const int alphabet_length = 26;
    
    char string_input[1000] = {0};
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int isUpper = 0;
    int shift = 0;
    
    if (scanf("%s %d", string_input, &shift) != 2) return 0;
    shift = (shift % alphabet_length + alphabet_length) % alphabet_length;
    
    for (int i = 0; string_input[i] != '\0'; i++, isUpper = 0)
    {
        if ((string_input[i] >= 'a' && string_input[i] <= 'z') || 
            (string_input[i] >= 'A' && string_input[i] <= 'Z'))
        {
            if (string_input[i] >= 'A' && string_input[i] <= 'Z')
            {
                isUpper = 1;
                string_input[i] += low_to_upper_delta;
            }
            
            int index = (string_input[i] - 'a' + shift) % alphabet_length;
            string_input[i] = alphabet[index];
            
            if (isUpper)
            {
                string_input[i] -= low_to_upper_delta;
            }
        }
    }
    
    printf("%s", string_input);
    return 0;
}