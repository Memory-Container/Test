#include<stdio.h>
#include<math.h>

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	int step [2*n-1]={0};
	int current;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a, &b );
		step[a-1]=b;
	}
	for(int i=1;i<=2*n-1;i++){
		if(i<=n){
			current+=step[i-1]+1;
		}
		else {
			current+= step[i-1]-1;
		}
		current=current < 1 ? 1 : current;
		printf("%d ", current);
	}
	return 0;
}
