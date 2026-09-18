#include <stdio.h>
#include <math.h>

int main() {
	long long d, l, y;
	long long result = 0;
	scanf("%lld", &d);
	l = d / 2;
	if (d % 2 ==1) 
	{ result = 1;
	  for (y=1; y <=1;y++)
	  { 
	    double x;
	    x = 1.0 + 0.5 * sqrt((double)d * d -4.0 * y * y);
	    result +=4 * (long long)x;
	  }
	}
	else
	{ 
	   for (y=1; y <= l; y++)
	{
		double x;
		x = 0.5 +0.5 * sqrt(
		     (double)d * d
			 - (2.0 * y - 1) * (2.0 * y - 1));
			 result += 4 * (long long)x;
     	}
	}
	printf("%lld",result);
	return 0;
} 
