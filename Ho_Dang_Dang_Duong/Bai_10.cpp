#include <stdio.h>
#include <string.h>

int main(){
	char str[1005];
	char dec[] = "IKLMNOCDBPQFRASTUJHEVWXYGZ";
	
	scanf("%[^\n]", str);
	for(int i=0; str[i] != '\0' && str[i] != '\n'; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			printf("%c", dec[str[i]- 'A']);
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			printf("%c", dec[str[i] - 'a'] + 32);
		}
		else{
			printf("%c", str[i]);
		}
	}	
	return 0;
}
