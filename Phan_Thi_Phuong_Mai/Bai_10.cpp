#include <stdio.h>

int main(){
    char bangma[] = "nightlysarbcdefjkmopquvwxz";
    char kytu;
    while ((kytu = getchar())!='\n'){
        if (kytu == ' ') {
        	
        } 
        else if (kytu >= 'a' && kytu <= 'z'){
            for (int i=0; i<26; i++) {
                if (bangma[i] == kytu) {
                    printf("%c", 'a' + i);
                    break; 
                }
            }
        } 
        else if (kytu >='A' && kytu <='Z'){
            char chuthuong = kytu + 32;
            for (int i=0; i<26; i++) {
                if (bangma[i] == chuthuong){
                    printf("%c", 'A'+ i);
                    break;
                }
            }
        }
    }
    printf("\n");
    return 0;
}
