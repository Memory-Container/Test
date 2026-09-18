#include<stdio.h>
#include<string.h>
int main(){
	char s[50];
	if (scanf("%s", s) != 1) return 0;
	if (strlen(s) != 15 || strncmp(s, "#TBSO", 5) != 0){
	printf("Khong hop le");
	return 0;	
	}
	int is_cakes = (strncmp(s + 5, "CAKES", 5) == 0);
	int is_drink = (strncmp(s + 5, "DRINK", 5) == 0);
	if (!is_cakes && !is_drink) {
		printf("Khong hop le");
		return 0;
	}
	char nums[6];
	strncpy(nums, s + 10, 5);
	nums[5] = '\0';
	for (int i = 0; i < 5; i++){
		if (nums[i] < '0' || nums[i] > '9'){
			printf("Khong hop le");
			return 0;
		}
	}
	int A = nums[0] - '0';
	int B = nums[1] - '0';
	int C = nums[2] - '0';
	int D = nums[3] - '0';
	int E = nums[4] - '0';
	if (A < 1 || B < 1 || E < 1){
		printf ("Khong hop le");
		return 0;
	}
	int math_mod = ((A + B - C) * D) % E;
	if (math_mod < 0){
		math_mod += E;
	}
	if (math_mod == 3 && (A + B + C + D + E) == 20){
		if (is_cakes) printf("Hop le, Banh ngot");
		else printf("Hop le, Do uong");
	} else {
		printf("Khong hop le");
	}
	return 0;
}
