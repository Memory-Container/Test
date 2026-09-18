#include <stdio.h>
#include <string.h>
int main() {
    int x=1;
    char s[50], chucvu[30], A[][10]={"NV", "KHBT", "KHVIP"};
    scanf("%[^\n]", s);
    scanf(" %s", chucvu);
    
    int j=0;

    for (int i =0;s[i]!='\0';i++){
        if (s[i]>='0' && s[i]<='9'){
            x=0;
        }
        if (s[i] != ' ') {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';

    int role=0;
    for (int i=0;i<3;i++){
        if (strcmp(chucvu, A[i])==0){
            role=1;
            break; 
        }
    }
    if (role==0){
        x=0;
    }


    if (x==0) {
        printf("Khong the tao ID");
    } else {
        printf("%s#TB%s", s, chucvu);
    }
}