#include <stdio.h>
#include <string.h>

int main(){
	char name[1000]={0};
	char index[1000];
	int valid=1;
	
	scanf("%[^\n]", name);
	scanf("%s", index);
	
	for(int i=0; i<= strlen(name); i++){
		if(name[i] >= '0' && name[i] <= '9'){
			valid=0;
			break;
		}
	}
	
	if (strcmp(index, "NV") != 0 && strcmp(index, "KHBT") != 0 && strcmp(index, "KHVIP") !=0){
		valid=0;
	}
	
	if(valid==0){
		printf("Khong the tao ID");
	}
	
	else {
		for(int i=0; i< strlen(name);i++){
			if(name[i] != ' '){
				printf ("%c", name[i]);
			}
		}
		printf("#TB%s", index);
	}
	return 0;
}
