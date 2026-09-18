#include <stdio.h>
#include <string.h>

int main() {
    char S[200];
    double profit;
    if (scanf("%s %lf", S, &profit) != 2) return 0;
    int c_count = 0;
    char s_no_c[200];
    int len = 0;
    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == 'C') c_count++;
        else s_no_c[len++] = S[i];
    }
    s_no_c[len] = '\0';
    int x_count = 0, d_count = 0, xd_count = 0;
    for (int i = 0; i < len; ) {
        if (i + 1 < len && s_no_c[i] == 'X' && s_no_c[i+1] == 'D') {
            xd_count++;
            i += 2;
        } else if (s_no_c[i] == 'X') {
            x_count++;
            i++;
        } else if (s_no_c[i] == 'D') {
            d_count++;
            i++;
        }
    }
    double base_op1 = (x_count + xd_count) * 354.0 + (d_count + xd_count) * 482.0;
    double op1 = base_op1 * (1.0 + 0.02 * xd_count) + c_count * 604.0;
    int total_shifts = x_count + d_count + 2 * xd_count;
    int total_hours = total_shifts * 5;
    double op2 = (total_hours * 50.0) + (profit * 0.005) + (c_count * 864.0); 
    printf("%.2lf\n%.2lf\n", op1, op2);
    if (op1 >= op2) {
        printf("Nen chon 1");
    } else {
        printf("Nen chon 2");
    }
    return 0;
}

