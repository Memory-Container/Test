#include<stdio.h>
int main(){
	long long N, M;
	if(scanf("%lld %lld", &N, &M) != 1);
	long long max_steps= 2*N-1;
	long long changes[20000] = {0};
	for (long long i = 0; i < M; i++){
		long long A, B;
		scanf("%lld %lld", &A, &B);
		if (A <= max_steps){
			changes[A] +=  B;
		}
	}
	long long offset = 0;
	for (long long i =1; i <= max_steps; i++){
		long long base_val;
		if (i <= N) base_val = i;
		else base_val = 2*N -i;
		offset += changes[i];
		long long val = base_val + offset;
		if (val < 1) val = 1;
		printf("%lld", val);
		if (i < max_steps)printf("");
	}
	return 0;
}
