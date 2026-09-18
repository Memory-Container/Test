#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[100];
    char loai_khach[50];
    int tong_banh;
    int tong_nuoc;
    int linh_thach;
    int diem_tl;
} Khach_hang;

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    Khach_hang danh_sach[100];
    int so_khach_hien_co = 0;

    for (int i = 0; i < N; i++) {
        char id[150], loai_hang[50];
        int so_luong;
        scanf("%s %s %d", id, loai_hang, &so_luong);

        int len_id = strlen(id);
        char ten_goc[100];
        int j;
        for (j = 0; j < len_id; j++) {
            if (id[j] != '#') {
                ten_goc[j] = id[j];
            } else {
                break;
            }
        }
        ten_goc[j] = '\0';

        char loai_khach[50];
        int k = 0;
        for (int y = j + 1; y < len_id; y++) {
            loai_khach[k++] = id[y];
        }
        loai_khach[k] = '\0';

        char ten_moi[100];
        ten_moi[0] = ten_goc[0];
        int p = 1;
        int len_ten_goc = strlen(ten_goc);
        
        for (int o = 1; o < len_ten_goc; o++) {
            if (ten_goc[o] >= 'A' && ten_goc[o] <= 'Z') {
                ten_moi[p++] = ' ';
                ten_moi[p++] = ten_goc[o];
            } else {
                ten_moi[p++] = ten_goc[o];
            }
        }
        ten_moi[p] = '\0';

        int vi_tri = -1;
        for (int t = 0; t < so_khach_hien_co; t++) {
            if (strcmp(danh_sach[t].ten, ten_moi) == 0) {
                vi_tri = t;
                break;
            }
        }

        if (vi_tri == -1) {
            vi_tri = so_khach_hien_co;
            strcpy(danh_sach[vi_tri].ten, ten_moi);
            strcpy(danh_sach[vi_tri].loai_khach, loai_khach);
            danh_sach[vi_tri].tong_banh = 0;
            danh_sach[vi_tri].tong_nuoc = 0;
            so_khach_hien_co++;
        }

        if (strcmp(loai_hang, "DRINK") == 0) {
            danh_sach[vi_tri].tong_nuoc += so_luong;
        } else if (strcmp(loai_hang, "CAKES") == 0) {
            danh_sach[vi_tri].tong_banh += so_luong;
        }
    }

    for (int i = 0; i < so_khach_hien_co; i++) {
        int chi_phi_goc = (danh_sach[i].tong_banh * 25) + (danh_sach[i].tong_nuoc * 17);
        
        if (strcmp(danh_sach[i].loai_khach, "TBKHVIP") == 0) {
            danh_sach[i].linh_thach = (int)(chi_phi_goc * 0.90 + 0.5);
            danh_sach[i].diem_tl = (danh_sach[i].tong_banh * 8) + (danh_sach[i].tong_nuoc * 5);
        } else {
            danh_sach[i].linh_thach = (int)(chi_phi_goc * 0.97 + 0.5);
            danh_sach[i].diem_tl = (danh_sach[i].tong_banh * 4) + (danh_sach[i].tong_nuoc * 2);
        }
    }

    for (int i = 0; i < so_khach_hien_co - 1; i++) {
        for (int j = i + 1; j < so_khach_hien_co; j++) {
            if (danh_sach[j].linh_thach > danh_sach[i].linh_thach) {
                Khach_hang tam = danh_sach[i];
                danh_sach[i] = danh_sach[j];
                danh_sach[j] = tam;
            }
        }
    }

    printf("Top 5 khach hang co thanh tich cao nhat\n");
    for (int i = 0; i < 5; i++) {
        if (i < so_khach_hien_co) {
            printf("%d. %s | %d Linh Thach | %d Diem TL", 
                   i + 1, 
                   danh_sach[i].ten, 
                   danh_sach[i].linh_thach, 
                   danh_sach[i].diem_tl);
        } else {
            printf("%d. Khong co du lieu", i + 1);
        }
        
        if (i < 4) {
            printf("\n");
        }
    }

    return 0;
}
