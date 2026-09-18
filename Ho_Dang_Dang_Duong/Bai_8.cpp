#include <stdio.h>
#include <string.h>

struct Customer{
	char name[100];
	char type[20];
	int base_cost;
	int points;
	int final_cost;
};

int main(){
	int n;
	scanf("%d", &n);
	struct Customer arr[100];
	int count = 0;
	
	for(int i = 0; i < n; i++){
		char raw_id[100], item[20];
		int qty;
		scanf("%s %s %d", raw_id, item, &qty);
		
		char name[100], type[20];
		
		int j=0, k=0;
		while(raw_id[j] != '#'){
			name[j]=raw_id[j];
			j++;
		}
		name[j] = '\0';
		
		j++;
		
		while(raw_id[j] != '\0'){
			type[k] = raw_id[j];
			j++;
			k++;
		}
		type[k] = '\0';
		
		int pos=-1;
		for(int m=0; m < count; m++){
			if (strcmp(arr[m].name, name) == 0){
				pos = m;
				break;
			}
		}
		
		if(pos == -1){
			pos = count;
			strcpy(arr[pos].name, name);
			strcpy(arr[pos].type, type);
			arr[pos].base_cost = 0;
			arr[pos].points = 0;
			count++;
		}
		
		if(strcmp(item, "CAKES") == 0){
			arr[pos].base_cost += qty * 25;
			if(strcmp(type, "TBKHVIP") == 0){
				arr[pos].points += qty * 8;
			}
			else{
				arr[pos].points += qty * 4;
			}
		}else if(strcmp(item, "DRINK") == 0){
			arr[pos].base_cost += qty * 17;
			if(strcmp(type, "TBKHVIP") == 0){
				arr[pos].points += qty * 5;
			} else {
				arr[pos].points += qty * 2;
			}
		}
	}
	for(int i=0; i < count; i++){
		if(strcmp(arr[i].type, "TBKHVIP") == 0){
			arr[i].final_cost = (int)(arr[i].base_cost * 0.90 + 0.5);
		}
		else{
			arr[i].final_cost = (int)(arr[i].base_cost * 0.97 + 0.5);
		}
	}
	
	for(int i = 0; i < count - 1; i++){
		for (int j = i + 1; j < count; j++){
			int can_doi_cho = 0;
			
			if(arr[i].points < arr[j].points){
				can_doi_cho = 1;
			}
			else if(arr[i].points == arr[j].points){
				if(arr[i].final_cost < arr[j].final_cost){
					can_doi_cho = 1;
				}
				else if (arr[i].final_cost == arr[j].final_cost){
					if(strcmp(arr[i].name, arr[j].name) > 0){
						can_doi_cho = 1;
					}
				}
			}
			if(can_doi_cho == 1){
				struct Customer temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Top 5 khach hang co thanh tich cao nhat\n");
	for(int i = 0; i < 5; i++){
		if(i<count){
			char display_name[100];
			int idx = 0;
			for(int k = 0; arr[i].name[k] != '\0'; k++){
				if(k > 0 && arr[i].name[k] >= 'A' && arr[i].name[k] <= 'Z') {
					display_name[idx] = ' ';
					idx++;
				}
				display_name[idx] = arr[i].name[k];
				idx++;
			}
			display_name[idx] = '\0';
			
			char cost_str[50];
			printf("%d. %s | %d Linh thach | %d Diem TL\n", i + 1, display_name, arr[i].final_cost, arr[i].points );
		}
		else {
			printf("%d. Khong co du lieu\n", i+1);
		}	
	}
	
	return 0;
}
