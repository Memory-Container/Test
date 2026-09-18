#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char Name[n][21];
    int Rank[n];
    
    // Tạo mảng full 0
    int Tluy[n];
        memset(Tluy, 0, sizeof(Tluy));
        
    float Total[n]; 
        memset(Total, 0, sizeof(Total));
        
    float sale[2]={0.1, 0.03};
    int tln[2]={5, 2};
    int tlb[2]={8, 4};
    int count=0;
    
    for (int i = 0; i < n; i++) {
        char name[21], type[6], id[10];
        int amount, rank=0;
        int vitri=count;

        scanf("%s %s %d", name, type, &amount);


        int len = strlen(name);
        int c = 0;
        while (name[c] != '\0' && name[c] != '#') {
            c++;
        }

        strcpy(id, name + c + 1);
        name[c] = '\0';
        

        int find = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(name, Name[j]) == 0) {
                find = 1;
                vitri = j;
                break;
            }
        }

        if (find == 0) {
            
            strcpy(Name[vitri], name);

            if (strcmp(id, "TBKHBT") == 0) {
                rank = 1;
            }

            Rank[vitri] = rank;

            count++;
        }  
        
        float total = Total[vitri];
        int tluy = Tluy[vitri];

        if (strcmp(type, "CAKES") == 0) {
            tluy += amount * tlb[Rank[vitri]];
            total += amount * 25 * (1.0 - sale[Rank[vitri]]);
        } else {
            tluy += amount * tln[Rank[vitri]];
            total += amount * 17 * (1.0 - sale[Rank[vitri]]);
        }

        Tluy[vitri] = tluy;
        Total[vitri] = total;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (Total[j] < Total[j + 1]) {

                float t_total = Total[j]; Total[j] = Total[j + 1]; Total[j + 1] = t_total;
                int t_tluy = Tluy[j]; Tluy[j] = Tluy[j + 1]; Tluy[j + 1] = t_tluy;
                int t_rank = Rank[j]; Rank[j] = Rank[j + 1]; Rank[j + 1] = t_rank;

                char t_name[21];
                strcpy(t_name, Name[j]);
                strcpy(Name[j], Name[j + 1]);
                strcpy(Name[j + 1], t_name);
            }
        }
    }



    printf("Top 5 khach hang co thanh tich cao nhat\n");
    int i=0;
    while (i<4) {
        if (i < count) {
           
            printf("%d. %s | %.0f Linh Thach | %d Diem TL \n", i + 1, Name[i], Total[i], Tluy[i]);
        } else {
            printf("%d. Khong co du lieu\n", i + 1);
        }
        i++;
    }
    if (i < count) {
           
            printf("%d. %s | %.0f Linh Thach | %d Diem TL ", i + 1, Name[i], Total[i], Tluy[i]);
        } else {
            printf("%d. Khong co du lieu", i + 1);
        }
    
}