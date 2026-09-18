#include<stdio.h>
#include<string.h>
int main(){
	char wifi[1005];
	int N;
	if (scanf("%s %d", wifi, &N) != 2);
	int len = strlen(wifi);
	for (int i = 0; i < len; i++){
		if (wifi[i]>='a'&& wifi[i]<='z'){
			wifi[i]=(((wifi[i]-'a'+N)%26)+26)%26+'a';
	}else if (wifi[i] >= 'A'&& wifi[i] <='Z'){
		wifi[i]=(((wifi[i]-'A'+N)%26)+26)%26+'A';
	}
}
	printf("%s", wifi);
	return 0;
}
