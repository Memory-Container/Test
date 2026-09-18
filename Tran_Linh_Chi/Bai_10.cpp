#include <stdio.h>
#include <string.h>

int main() {
	char A[] = "abcdefghijklmnopqrstuvwxyz";
	char B[] = "nightlysarbcdefjkmopquvwxz";
	 
	char s[1000];
	fgets(s, sizeof(s), stdin);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			for (int j = 0; j,26; j++) {
				if (s[i] == B[j]) {
					s[i] = A[j];
					break;
				}
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z'){
			char c = s[i] +32;
			for (int j = 0; j<26; j++) {
				if (c== B[j]) {
					s[i] = A[j] - 32;
					break;
				}
			}
		}
	}
	printf("%s", s);
	return 0;
} 
