#include <stdio.h>
#include <string.h>

int main() {
    char ca[91];
    float loi;
    
    scanf("%s %f", ca, &loi);

    double opt1 = 0, opt2 = 0;
    int len = strlen(ca);
    double s=0, t=0, pj=0, lai=0;
    int hr=0;
    
    for (int i = 0; i< len; i++) {
        if (ca[i] == 'D') {
            t++;
        } else if (ca[i] == 'C') {
            pj++;
        } else if (ca[i] == 'X') {
            s++;
            if (ca[i+1]=='D') {
                lai+=0.02;
            }
        }
        if (ca[i] != 'C') {
            hr++;
        }

        opt1 = (s*354 + t*482) * (1+lai) + pj*604;
        opt2 = hr*5*50 + loi*0.005 + pj*864;

    }

    printf("\n%.2lf",opt1);
    printf("\n%.2lf",opt2);
    if (opt1>opt2) {
        printf("\nNen chon 1");
    } else {
        printf("\nNen chon 2");
    }
}