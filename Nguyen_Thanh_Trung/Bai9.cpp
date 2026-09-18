#include <stdio.h>
int main(){
    char S[90];
    float profit;
    scanf("%s %f", S, &profit); 
    
    if (profit < 30000) return 0;

    int X = 354;
    int D = 482;
    int C = 604;
    int hourly = 50;
    int C2 = 864;
    float opt1 = 0;
    float opt2 = 0;
    int bothShift = 0;
    int i = 0;
    float projectPay1 = 0;

    while (S[i] != '\0') {
        if (S[i] == 'X'){
            if (S[i + 1] == 'D')
            {
                opt1 += X + D;
                opt2 += 2 * (5 * hourly);
                bothShift++;
                i++;
            }
            else
                {opt1 += X;
                opt2 += 5 * hourly;}
            }
        else if (S[i] == 'D')
        {
            opt1 += D;
            opt2 += 5 * hourly;
        }
        else if (S[i] == 'C'){
            opt1 += C;
            opt2 += C2;
            projectPay1 += C;
        }
        i++;
    } 
    float total2 = (0.005 * profit) + opt2;
    opt1 = (opt1 - projectPay1) * (1 + 0.02 * bothShift) + projectPay1;

    printf("%.2f\n", opt1);
    printf("%.2f\n", total2);
    if (opt1 > total2) {
        printf("Nen chon 1");
    } else {
        printf("Nen chon 2");
    }
    return 0;
}