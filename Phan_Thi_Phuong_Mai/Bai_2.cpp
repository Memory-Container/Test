#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int tongbuoc = 2 * N - 1;
    long long thaydoi[200005] = {0}; 
    for (int y = 0; y < M; y++) {
        int A, B;
        scanf("%d %d", &A, &B);
        thaydoi[A] = B;
    }
    long long tongthaydoi = 0;
    for (int i = 1; i <= tongbuoc; i++) {
        long long anhsangcoban;
        if (i <= N) {
            anhsangcoban = i;
        } else {
            anhsangcoban = 2 * N - i;
        }
        tongthaydoi = tongthaydoi + thaydoi[i];
        long long anhsangthucte = anhsangcoban + tongthaydoi;
        if (anhsangthucte < 1) {
            anhsangthucte = 1;
        }
        printf("%lld ", anhsangthucte);
        if (i < tongbuoc) {
        }
    }
    return 0;
}
