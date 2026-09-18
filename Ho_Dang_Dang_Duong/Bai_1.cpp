#include<stdio.h>
#include<math.h>

int main(){
	int d;
	int summ,l;
	scanf("%d",&d);
	if(d%2==0){
		l=d/2;
		for(int i=1; i<=l; i++){
			summ+= (int)floor((0.5+0.5*sqrt(d*d-((2.0*i-1)*(2.0*i-1)))));
		}
		summ=summ*4;
	}
	else {
		l=(d-1)/2;
		for(int i=1; i<=l;i++){
			summ+= (int)floor((1.0+0.5*sqrt(d*d-4.0*i*i)));
		}
		summ=summ*4+1;
	}
	printf("%d",summ);
	return 0;
}
