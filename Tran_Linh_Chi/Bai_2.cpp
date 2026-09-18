#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    int b[100005] = {0};

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        b[A] = B;
    }

    int x = 1;

    for (int i = 1; i <= 2 * N - 1; i++) {
        if (i > 1) {
            if (i <= N)
                x++;
            else
                x--;
        }

        x += b[i];

        if (x < 1)
            x = 1;

        printf("%d ", x);
    }

    return 0;
}

