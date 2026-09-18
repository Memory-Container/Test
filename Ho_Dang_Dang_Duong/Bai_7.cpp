#include <stdio.h>
#include <string.h>

int main(){
	char inp[16];
	scanf("%s", inp);
	int valid=1;
	int count;
	char id[6] = "#TBSO";
	int isCakes = 0;
	int isDrink = 0;
	
	if(strlen(inp)!=15){
		valid=0;
	}
	
	else{
		for(int i=0; i< 5; i++){
			if(inp[i]!=id[i]){
				valid=0;
				break;
			}
		}
		if(inp[5] == 'C' && inp[6] == 'A' && inp[7] == 'K' && inp[8] == 'E' && inp[9] == 'S'){
			isCakes=1;					
		}
		else if(inp[5] == 'D' && inp[6] == 'R' && inp[7] == 'I' && inp[8] == 'N' && inp[9] == 'K'){
			isDrink=1;
		}
		else{
			valid=0;
		}
		if (valid == 1){
			int A = inp[10] - '0';
			int B = inp[11] - '0';
			int C = inp[12] - '0';
			int D = inp[13] - '0';
			int E = inp[14] - '0';
			int cal = (((A+B-C)*D)%E);
			if(cal<0){
				cal+=E;
			}
			if(A==0 || B==0 || E==0 || cal != 3|| A+B+C+D+E != 20){
				valid=0;
			}
		}
	}
	if(valid == 1 && isCakes == 1){
		printf("Hop le, Banh ngot");
	}
	else if (valid == 1 && isDrink == 1){
		printf("Hop le, Do uong");
	}
	else {
		printf("Khong hop le");
	}
	return 0;
}
