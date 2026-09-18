#include<stdio.h>
#include<string.h>

int main(){
	char s[91];
	float LN;
	scanf("%s %f", s, &LN);
	
	int count_x=0;
	int count_d=0;
	int count_c=0;
	int count_xd=0;
	
	for (int i=0; s[i] != '\0'; i++){
		if(s[i] == 'X'){
			count_x++;	
	  	}
	  	
	  	else if (s[i] == 'D'){
	  		count_d++;
		}
		
		else if(s[i] == 'C'){
			count_c++;
		} 
		
		if (s[i] == 'X' && s[i+1] == 'D'){
			count_xd++;
		}  
	}
	
	double opt_1_base = count_x * 354.0 + count_d * 482.0;
	double opt_1_total = opt_1_base * (1.0 + 0.02 * count_xd) + (count_c * 604.0);
	
	double hours = (count_x + count_d) * 5.0;
	double opt_2_total = (hours * 50) + (LN * 0.005) + (count_c * 864.0);
	
	printf("%.2lf\n", opt_1_total);
	printf("%.2lf\n", opt_2_total);
	
	if(opt_1_total > opt_2_total){
		printf("Nen chon 1");
	}
	else {
		printf("Nen chon 2");
	}
	return 0;
}
