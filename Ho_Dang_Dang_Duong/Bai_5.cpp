#include<stdio.h>
#include<math.h>
#include <string.h>

int main(){
	char input [1000]={0};
	int shift;
	
	scanf("%s %d", input, &shift);
	
	if(shift < 0){
		shift+=26;
	}
	
	for(int i=0; input[i] != '\0';i++){
		if(input[i] >='a' && input[i] <= 'z'){
			input[i]=(input[i] - 'a' + shift) % 26 + 'a';
		}
		else {
			input[i]=(input[i] - 'A' + shift) % 26 + 'A';
		}
	}
	printf("%s", input);
	return 0;
}
	

