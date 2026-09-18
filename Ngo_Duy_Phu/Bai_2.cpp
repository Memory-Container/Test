#include <stdio.h>
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    long long list[2*N-1];
    int c=0;
    for (int i=1; i<=(2*N-1); i++) {
        if (i<=N) {
            list[i-1]=i;
        } else {
            c+=2;
            list[i-1]=i-c;
        }
    }
    for (int i=1; i<=M; i++) {
        int A,B ;
        scanf("%d %d", &A, &B);
        for (int j=A; j<=(2*N-1); j++) {
            list[j-1] += B;
        }
    }
    for (int i=0; i<(2*N-1); i++) {
        if (list[i] < 1) {
            printf("%d ", 1);
        } else {
            printf("%d ", list[i]);
        }
    }
}