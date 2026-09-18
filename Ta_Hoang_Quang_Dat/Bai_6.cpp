#include<stdio.h>
#include<string.h>
int main(){
	char name[100];
	char type[20];
	if(scanf("%[^\n]", name) != 1);
	scanf("%s", type);
	int valid = 1;
	int len = strlen(name);
	for(int i=0; i<len; i++){
		if(name[i]>='0'&& name[i]<='9'){
			valid = 0;
			break;
		}
	}
	if (strcmp(type, "NV") != 0&&strcmp(type, "BT") !=0 && strcmp(type, "VIP")!=0){
		valid =0;
	}
	if(!valid){
		printf("Khong the tao ID");
	}else{
		for (int i=0; i<len; i++){
			if (name[i]!=' ')printf("%c", name[i]);
		}
		printf("#TB");
		if (strcmp(type, "NV") ==0) printf("NV");
		else if (strcmp(type, "BT")== 0)printf("KHBT");
		else if (strcmp(type, "VIP") == 0)printf("KHVIP");
	}
	return 0;
}
