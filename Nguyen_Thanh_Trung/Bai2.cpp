#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int total_steps = 2 * N - 1;
    int cycle[200];

    for (int i = 1; i <= N; i++) {
        cycle[i] = i;
    }
    for (int i = N + 1; i <= total_steps; i++) {
        cycle[i] = 2 * N - i;
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        for (int j = A; j <= total_steps; j++) {
            cycle[j] += B;
            if (cycle[j] < 1) {
                cycle[j] = 1;
            }
        }
    }

    for (int i = 1; i <= total_steps; i++) {
        printf("%d%c", cycle[i], (i == total_steps) ? '\n' : ' ');
    }

    return 0;
}