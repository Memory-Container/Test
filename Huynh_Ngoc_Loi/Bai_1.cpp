#include <stdio.h>
#include <math.h> 

int main(){
	int d;
	scanf("%d",&d);
	int kq;
	int sum = 0; 
	if(d % 2 != 0){
		int l = (d - 1) / 2;
		for(int y =1; y <= l; y= y + 1){
			int pn = 1 + 0.5 * sqrt(d*d - 4 * y *y);
			sum = sum + pn;
		} 
		kq = 1 + 4 * sum;
	} 
	else{
		int l = d / 2;
		for(int y = 1; y<= l; y = y + 1){
			int pn = 0.5 + 0.5 * sqrt(d*d - (2 * y - 1)*(2 * y - 1));
			sum = sum + pn; 
		}
		kq = 4 * sum; 
	}
	printf("%d",kq);
	return 0; } 
