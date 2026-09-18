#include <stdio.h>
#include <string.h>

int main(){
    char chuoi[100];
    float loiNhuan;
    scanf ("%s %f", &chuoi, &loiNhuan);
    
    int X=0,D=0, XD=0, C=0; 
    for (int i=0; chuoi[i] != '\0';i++ ) {
    	char c= chuoi[i]; 
      if (c == 'X'){
           X++;
           if (chuoi[i+1]=='D'){
            XD++;
            }
      }
	    else if (c=='D'){
		D++; 
	    }
	    else if (c=='C'){
		C++;
	    }
     }
    float luonggoc=(X*354)+(D*482);
     float luongthuong = luonggoc + (luonggoc*0.02*XD);
    float luong1= luongthuong + (C*604);
      printf("%.2f\n", luong1);
    int tongca=X+D;
    int tonggio=tongca*5;
    float luong2=(tonggio*50)+(0.005* loiNhuan)+(C*864);


    printf("%.2f\n", luong2);

    if(luong1>luong2){
          printf("Nen chon 1");
    }
          else{
               printf("Nen chon 2");
          }

return 0;
}
