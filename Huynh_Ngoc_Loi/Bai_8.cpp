#include <stdio.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	int SLKH = 0; 
	int DiemNhanDc = 0;
	struct KH{
		char ID[50];
		int Diem;
		float TongTien; 
	}; 
	struct PL {
		char ID[50];
		char LoaiHang[10];
		int SL;
	};
	 struct KH ds[100];
	 for (int i = 0; i < N; i++){
	 	struct PL GD;
		 scanf ("%s %s %d", GD.ID, GD.LoaiHang, &GD.SL);
		 float Gia = 0; 
		 if (strcmp(GD.LoaiHang, "CAKES") ==0){ 
		 	Gia = 25;
		 }
		 else {
		 	Gia = 17;		 	
		 }
		 float Giam = 0;
		 if(strstr(GD.ID, "TBKHVIP") != NULL){
		 	Giam = 0.1; 
		 }
		 else {
		 	Giam = 0.03; 
		 } 
		 float TienGiaoDich = (GD.SL * Gia) * (1 - Giam);
		  if (strstr(GD.ID, "TBKHVIP") != NULL){
		  	if (strcmp(GD.LoaiHang, "CAKES") == 0){
		  	DiemNhanDc = GD.SL * 8; 
		  } 
		  else{
		  	DiemNhanDc = GD.SL * 5;
		} 
		}
		  else{
		  	if(strcmp(GD.LoaiHang, "CAKES") ==0){
		  		DiemNhanDc = GD.SL * 4; 
			  } 
			  else{
			  	DiemNhanDc = GD.SL * 2; 
			  } 
		  }
		  int T = 0;
		  for(int j = 0; j < SLKH; j++){
		  	if (strcmp(ds[j].ID, GD.ID) == 0){
		  		ds[j].Diem += DiemNhanDc;
				  ds[j].TongTien += TienGiaoDich;
				  T = 1;
				  break; 
			  } 
		  }
		  if(T == 0){
		  	strcpy(ds[SLKH].ID, GD.ID);
			  ds[SLKH].Diem = DiemNhanDc;
			  ds[SLKH].TongTien = TienGiaoDich;
			  SLKH++; 
		  } 
	 }
	  for(int i = 0; i < SLKH - 1; i++){
	  	for(int j = j + 1; j < SLKH; j++){
	  		if(ds[i].Diem < ds[j].Diem){
	  			struct KH temp = ds[i];
				  ds[i] = ds[j];
				  ds[j] = temp; 
			  } 
		  } 
	  }
	  printf("Top 5 khach hang co thanh tich cao nhat\n");
	  for(int i = 0; i < 5; i++){
	  	if(i < SLKH){
	  		char ten[50];
			strcpy(ten, ds[i].ID);
			char *m = strchr(ten, '#');
			if(m != NULL){
				m = '\0'; 
			}
			printf ("%d %-12s | %.0f Linh Thach | %d Diem TL\n", i + 1, ten, ds[i].TongTien, ds[i].Diem); 
		  }
		  else{
		  	printf("%d. Khong co du lieu\n", i + 1); 
		  } 
	  } 
	  return 0; 
} 
