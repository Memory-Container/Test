#include <stdio.h>
#include <math.h>
int main() {
    int l, d;
    int tong = 0;
    scanf("%d", &d);
    
    if (d % 2 == 0) {
        l = d / 2;
        for (int y = 1; y <= l; y++) {
            tong += (int)floor(0.5 + 0.5 * sqrt(d * d - (2 * y - 1) * (2 * y - 1)));
        }
        tong = tong * 4;
    } else {
        l = (d - 1) / 2;
        for (int y = 1; y <= l; y++) {
            tong += (int)floor(1.0 + 0.5 * sqrt(d * d - 4 * y * y));
        }
        tong = tong * 4 + 1;
    }
    
    printf("%d", tong);

}