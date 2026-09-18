#include <stdio.h>
#include <string.h>
int main() {
    char ten[100];
    char chuc_vu[50];
    scanf("%[^\n]", ten);
    getchar();
    scanf("%[^\n]", chuc_vu);

    int hop_le = 1;
    for (int i = 0; ten[i] != '\0'; i++) {
        if (ten[i] >= '0' && ten[i] <= '9') {
            hop_le = 0;
            break;
        }
    }
    int la_NV    = (strcmp(chuc_vu, "NV") == 0);
    int la_KHBT  = (strcmp(chuc_vu, "KHBT") == 0);
    int la_KHVIP = (strcmp(chuc_vu, "KHVIP") == 0);

    if (!la_NV && !la_KHBT && !la_KHVIP) {
        hop_le = 0;
    }
    if (hop_le == 0) {
        printf("Khong the tao ID\n");
    } else {
        printf("%s#TB%s\n", ten, chuc_vu);
    }
    return 0;
}
