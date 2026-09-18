#include <stdio.h>
#include <string.h>

int main(){
    char ten[49];
    char loai[10];
    scanf("%[^\n]", ten);
    getchar();
    scanf("%[^\n]", loai);
    int tenhople = 1;
    for(int i = 0; i < strlen(ten); i++){
        if(ten[i] >= '0' && ten[i] <= '9'){
            tenhople = 0;
            break;
        }
    }
        int ploaihople = 0;
        if(strcmp(loai, "NV") == 0 || strcmp(loai, "KHBT") == 0 || strcmp(loai, "KHVIP") == 0){
            ploaihople = 1;
        }
        if(!tenhople || !ploaihople){
            printf("Khong the tao ID\n");
        }
        else {
            for(int i = 0; i < strlen(ten); i++){
                if(ten[i] != ' '){
                    printf("%c", ten[i]);
                }
            }
            printf("#TB%s\n", loai);
        }
        return 0;
    }