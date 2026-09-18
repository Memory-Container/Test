#include <stdio.h>

int main() {
    char pass[100];
    int N;
    scanf("%s %d", &pass, &N);
    
    for (int i = 0; pass[i] != '\0'; i++){
        if (pass[i] >= 'A' && pass[i] <= 'Z'){
            int cu= pass[i]-'A';             
            int moi =(cu+N +26)%26;    
            pass[i] = 'A'+moi;
        }
        else if (pass[i]>= 'a' && pass[i]<= 'z'){
            int cu =pass[i] - 'a';
            int moi = (cu+N+26)%26;
            pass[i] = 'a' +moi;
      }
    }
    printf("%s\n",pass);
    return 0;
}
