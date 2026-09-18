#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int n;
	if(scanf("%d", &n) != 1);
	for (int i=1; i <= n; i++){
		char s[10];
		scanf("%s", s);
		int note_idx = 0;
		int octave_start = 1;
		if (s[1] == '#'){
			octave_start = 2;
			if (s[0] == 'C') note_idx = 1;
			else if (s[0] == 'D') note_idx = 3;
			else if (s[0] == 'F') note_idx = 6;
			else if (s[0] == 'G') note_idx = 8;
			else if (s[0] == 'A') note_idx = 10;
		}else{
			if(s[0] == 'C') note_idx = 0;
			else if (s[0] == 'D') note_idx = 2;
			else if (s[0] == 'E') note_idx = 4;
			else if (s[0] == 'F') note_idx = 5;
			else if (s[0] == 'G') note_idx = 7;
			else if (s[0] == 'A') note_idx = 9;
			else if (s[0] == 'B') note_idx = 11;
		}
		int octave = atoi(&s[octave_start]);
		int val = octave * 12 +note_idx;
		if (val < 67){
			printf("%d %d\n", val, i);
		}
	}
	return 0;
}
