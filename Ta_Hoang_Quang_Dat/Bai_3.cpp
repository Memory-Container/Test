#include<stdio.h>
int main(){
    int N;
	if(scanf("%d", &N) >= 1);
	const char* not_nhac[]={"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
	for(int i = 0; i < N; i++){
		int val;
		scanf("%d", &val);
		int octave = val/12;
		int note = val %12;
		printf("%s%d", not_nhac[note], octave);
		if(i < N - 1)printf(" ");
	}
	return 0;
}
