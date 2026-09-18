#include <stdio.h>
#include <math.h>

int main() {
    long long d;
	if(scanf("%lld", &d) >= 1);
	long long total_squares = 0;
	//So o vuong 1x1 duoc to den = total_squares
	if(d % 2 != 0){
		long long l = (d - 1) / 2;
		long long sum = 0;
		for (long long y = 1; y <= l; y++){
			double val = sqrt((double)(d * d)-4.0*(y*y));
			sum += 1 +floor(0.5*val); 
		}
		total_squares = 1 + 4*sum;
	}else{
		long long l = d/2;
		long long sum = 0;
		for (long long y = 1; y <= l; y++){
			double val = sqrt((double)(d*d) -(2.0*y-1.0)*(2.0*y-1.0));
			sum += floor(0.5+0.5 * val);
		}
		total_squares = 4*sum;
	}
	printf("%lld", total_squares);
	return 0;
}
