#include <stdio.h>

int main(){
    int N;
    int M; 
    scanf("%d %d", &N, &M);
    long tong = 2 * N - 1;
    long dosang[10000];
    for(long i = 1; i <= N; i++){
        dosang[i] = i;
    }
    long giam = N - 1;
    for(long i = N + 1 ; i <= tong; i = i + 1){
        dosang[i] = giam;
        giam = giam - 1;
    }
    for(long k = 1; k <= M; k++){
        long A, B;
        scanf("%ld %ld", &A, &B);
        for(long i = A; i <= tong; i++){
            dosang[i] = dosang[i] + B;
        }
    }
    for(long i = 1; i <= tong; i++){
        if(dosang[i] < 1){
            dosang[i] = 1;
        }
    }
    for(long i = 1; i <= tong; i++){
        printf("%ld ", dosang[i]);
    }
    return 0;
}
