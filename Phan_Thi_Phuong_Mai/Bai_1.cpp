#include <stdio.h>
#include <math.h>

int main(){
	long long d;
	scanf("%lld", &d);
	long long N;
	int l;
	if (d % 2 != 0){
		l=(d-1)/2;
		long long tong=0;
		for (int y=1; y<=l; y++){
			long long s= (long long)sqrt(d*d-4*y*y);
			tong=tong + (2+s)/2;
		}
		N=1+4*tong;
	}
	else {
		l=d/2;
		long long tong=0;
		for (int y=1; y<=l; y++){
			long long s= (long long)sqrt(d*d-(2*y-1)*(2*y-1));
			tong= tong + (1+s)/2;
		}
		N=4*tong;
	}
	printf("%lld", N);
	return 0;
}
