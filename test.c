#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTRING    10000
#define BIGINTEGER   999999
#define MIN_QUANTITY 0
#define LOW_STOCK    5

typedef struct item {
    int id;
    char name[51];
    char category[51];
    int quantity;
} item;

typedef struct tmpItem {
    char *id;
    char *name;
    char *category;
    char *quantity;
} tmpItem;

int itemCount = 0;

void clearScreen(void) {
    for (int i = 0; i < 50; i++) printf("\n");
}

void waitEnter(void) {
    int c;
    printf("Nhan enter de tiep tuc...");
    while ((c = getchar()) != '\n' && c != EOF);
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

int readInt(const char *prompt, int *value) {
    char buffer[MAXSTRING];
    readString(prompt, buffer, sizeof(buffer));
    char *end;
    long v = strtol(buffer, &end, 10);
    if (*end != '\0' || end == buffer) return 0;
    *value = (int)v;
    return 1;
}

tmpItem splitInputedData(char singleData[]) {
    tmpItem tmp;
    if (singleData[0] == '|') {
        tmp.id = NULL;
        tmp.name = strtok(singleData, "|\n");
        tmp.category = strtok(NULL, "|\n");
        tmp.quantity = strtok(NULL, "|\n");
    } else {
        tmp.id = strtok(singleData, "|\n");
        tmp.name = strtok(NULL, "|\n");
        tmp.category = strtok(NULL, "|\n");
        tmp.quantity = strtok(NULL, "|\n");
    }
    return tmp;
}

void expandMemory(item **storeData, int memoryChange) {
    int newCount = itemCount + memoryChange;
    if (newCount <= 0) {
        free(*storeData);
        *storeData = NULL;
        return;
    }
    item *temp = (item *)realloc(*storeData, newCount * sizeof(item));
    if (temp == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    *storeData = temp;
}

int checkIDValid(const char id[]) {
    if (id == NULL) return 0;
    size_t len = strlen(id);
    if (len != 8) return 0;
    if (id[0] != '9' || id[1] != '7') return 0;
    for (size_t i = 0; i < len; i++) {
        if (!isdigit((unsigned char)id[i])) return 0;
    }
    return 1;
}

int checkNameValid(const char name[]) {
    if (name == NULL) return 0;
    size_t len = strlen(name);
    if (len == 0 || len > 30) return 0;
    int digitCount = 0;
    for (size_t i = 0; i < len; i++) {
        char c = name[i];
        if (!(isalnum((unsigned char)c) || c == '_')) return 0;
        if (isdigit((unsigned char)c)) digitCount++;
    }
    return digitCount != (int)len;
}

int checkCategoryValid(const char category[]) {
    if (category == NULL) return 0;
    size_t len = strlen(category);
    if (len == 0 || len > 15) return 0;
    int digitCount = 0;
    for (size_t i = 0; i < len; i++) {
        char c = category[i];
        if (!(islower((unsigned char)c) || isdigit((unsigned char)c))) return 0;
        if (isdigit((unsigned char)c)) digitCount++;
    }
    return digitCount != (int)len;
}

int checkQuantityValid(const char quantity[]) {
    if (quantity == NULL) return 0;
    size_t len = strlen(quantity);
    if (len == 0 || len > 5) return 0;
    for (size_t i = 0; i < len; i++) {
        if (!isdigit((unsigned char)quantity[i])) return 0;
    }
    return 1;
}

int checkQuantityChangeValid(int delta, int currentQuantity) {
    if (delta < 0) return 0;
    long result = (long)currentQuantity + delta;
    return result >= MIN_QUANTITY && result <= BIGINTEGER;
}

int idToIndex(item *storeData, int id) {
    for (int i = 0; i < itemCount; i++) {
        if (storeData[i].id == id) return i;
    }
    return -1;
}

int nameToIndex(item *storeData, const char name[]) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(storeData[i].name, name) == 0) return i;
    }
    return -1;
}

int findByField(item *storeData, const char *field, const char *value, int *listFound) {
    if (strcmp(field, "category") == 0) {
        int foundCount = 0;
        for (int i = 0; i < itemCount; i++) {
            if (strcmp(storeData[i].category, value) == 0) {
                listFound[foundCount++] = i;
            }
        }
        return foundCount;
    }
    if (strcmp(field, "quantity") == 0) {
        int q = atoi(value);
        int foundCount = 0;
        for (int i = 0; i < itemCount; i++) {
            if (storeData[i].quantity == q) {
                listFound[foundCount++] = i;
            }
        }
        return foundCount;
    }
    return 0;
}

void addNewItem(item **storeData, tmpItem newItem) {
    expandMemory(storeData, 1);
    (*storeData)[itemCount].id = atoi(newItem.id);
    strncpy((*storeData)[itemCount].name, newItem.name, 50);
    (*storeData)[itemCount].name[50] = '\0';
    strncpy((*storeData)[itemCount].category, newItem.category, 50);
    (*storeData)[itemCount].category[50] = '\0';
    (*storeData)[itemCount].quantity = atoi(newItem.quantity);
    itemCount++;
}

void deleteItem(item **storeData, int itemIndex) {
    if (itemIndex < 0 || itemIndex >= itemCount) return;
    for (int i = itemIndex; i < itemCount - 1; i++) {
        (*storeData)[i] = (*storeData)[i + 1];
    }
    itemCount--;
    if (itemCount == 0) {
        free(*storeData);
        *storeData = NULL;
        return;
    }
    item *temp = (item *)realloc(*storeData, itemCount * sizeof(item));
    if (temp != NULL) *storeData = temp;
}

void updateItemData(item *it, const char newName[], const char newCategory[], int newQuantity) {
    strncpy(it->name, newName, 50);
    it->name[50] = '\0';
    strncpy(it->category, newCategory, 50);
    it->category[50] = '\0';
    it->quantity = newQuantity;
}

int importFromFile(item **storeData, const char fileName[]) {
    char buffer[MAXSTRING];
    tmpItem tmp;
    char fullName[MAXSTRING + 4];

    snprintf(fullName, sizeof(fullName), "%s.txt", fileName);
    FILE *file = fopen(fullName, "r");
    if (file == NULL) return 1;

    while (fgets(buffer, MAXSTRING, file) != NULL) {
        tmp = splitInputedData(buffer);
        if (checkIDValid(tmp.id) && checkNameValid(tmp.name) &&
            checkCategoryValid(tmp.category) && checkQuantityValid(tmp.quantity)) {
            addNewItem(storeData, tmp);
        } else {
            fclose(file);
            return -(itemCount + 1);
        }
    }
    fclose(file);
    return 0;
}

void exportToFile(item *storeData, const char fileName[]) {
    char fullName[MAXSTRING + 4];
    snprintf(fullName, sizeof(fullName), "%s.txt", fileName);
    FILE *file = fopen(fullName, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d|%s|%s|%d\n",
                storeData[i].id, storeData[i].name,
                storeData[i].category, storeData[i].quantity);
    }
    fclose(file);
    printf("Xuat file thanh cong.\n");
}

void printHeader(void) {
    printf("   ID   |             Name             |   Category    |Quantity\n");
}

void printItemLine(item *it) {
    printf("%8d|%-30s|%-15s|%-5d\n", it->id, it->name, it->category, it->quantity);
}

void printFromIDList(item *storeData, int idList[], int listCount) {
    if (listCount == 0) return;
    printHeader();
    for (int i = 0; i < listCount; i++) printItemLine(&storeData[idList[i]]);
}

void printAllItem(item *storeData) {
    if (itemCount == 0) {
        printf("Khong co du lieu trong kho.\n");
        return;
    }
    printHeader();
    for (int i = 0; i < itemCount; i++) printItemLine(&storeData[i]);
}

void alarm(item *storeData) {
    int firstTime = 0;
    for (int i = 0; i < itemCount; i++) {
        if (storeData[i].quantity < LOW_STOCK) {
            if (firstTime == 0) {
                printf("\n=== CANH BAO MAT HANG SAP HET (SO LUONG < %d) ===\n", LOW_STOCK);
                printHeader();
                firstTime = 1;
            }
            printItemLine(&storeData[i]);
        }
    }
}

int findItemByName(item *storeData, const char *prompt, int *idxOut) {
    char name[MAXSTRING];
    readString(prompt, name, sizeof(name));
    if (!checkNameValid(name)) {
        printf("Ten khong hop le!\n");
        return 0;
    }
    int idx = nameToIndex(storeData, name);
    if (idx == -1) {
        printf("Khong tim thay mat hang trong kho.\n");
        return 0;
    }
    *idxOut = idx;
    return 1;
}

int readValidQuantity(const char *prompt, int *valueOut) {
    char buffer[MAXSTRING];
    readString(prompt, buffer, sizeof(buffer));
    if (!checkQuantityValid(buffer)) {
        printf("So luong khong hop le!\n");
        return 0;
    }
    *valueOut = atoi(buffer);
    return 1;
}

void showItem(item *storeData, int idx) {
    int tmp[] = { idx };
    printFromIDList(storeData, tmp, 1);
}

void handleAddQuantity(item *storeData) {
    int idx;
    if (!findItemByName(storeData, "Nhap ten mat hang: ", &idx)) return;

    int delta;
    if (!readValidQuantity("Nhap so luong tang: ", &delta)) return;

    if (!checkQuantityChangeValid(delta, storeData[idx].quantity)) {
        printf("So luong vuot qua gioi han cho phep!\n");
        return;
    }
    storeData[idx].quantity += delta;
    showItem(storeData, idx);
    alarm(storeData);
}

void handleDecreaseQuantity(item *storeData) {
    int idx;
    if (!findItemByName(storeData, "Nhap ten mat hang: ", &idx)) return;

    int delta;
    if (!readValidQuantity("Nhap so luong giam: ", &delta)) return;

    if (delta > storeData[idx].quantity) {
        printf("So luong giam vuot qua so luong hien co!\n");
        return;
    }
    storeData[idx].quantity -= delta;
    showItem(storeData, idx);
    alarm(storeData);
}

void handleUpdateItem(item *storeData) {
    int idx;
    if (!findItemByName(storeData, "Nhap ten mat hang: ", &idx)) return;

    char newName[MAXSTRING], newCategory[MAXSTRING];
    readString("Nhap ten moi: ", newName, sizeof(newName));
    if (!checkNameValid(newName)) {
        printf("Ten khong hop le!\n");
        return;
    }
    readString("Nhap loai hang moi: ", newCategory, sizeof(newCategory));
    if (!checkCategoryValid(newCategory)) {
        printf("Loai hang khong hop le!\n");
        return;
    }

    int newQty;
    if (!readValidQuantity("Nhap so luong moi: ", &newQty)) return;

    updateItemData(&storeData[idx], newName, newCategory, newQty);
    printf("Cap nhat mat hang thanh cong.\n");
    showItem(storeData, idx);
}

void handleDeleteItem(item **storeDataPtr) {
    int idx;
    if (!findItemByName(*storeDataPtr, "Nhap ten mat hang: ", &idx)) return;
    deleteItem(storeDataPtr, idx);
    printf("Xoa du lieu cua mat hang thanh cong.\n");
}

void handleFindById(item *storeData) {
    char id[MAXSTRING];
    readString("Nhap id: ", id, sizeof(id));
    if (!checkIDValid(id)) {
        printf("Id khong hop le.\n");
        return;
    }
    int idx = idToIndex(storeData, atoi(id));
    if (idx == -1) {
        printf("Khong tim thay mat hang trong kho.\n");
        return;
    }
    showItem(storeData, idx);
}

void handleFindByName(item *storeData) {
    int idx;
    if (!findItemByName(storeData, "Nhap ten: ", &idx)) return;
    showItem(storeData, idx);
}

void handleFindByList(item *storeData, const char *field, const char *prompt,
                      int (*validator)(const char *)) {
    char value[MAXSTRING];
    readString(prompt, value, sizeof(value));
    if (!validator(value)) {
        printf("Du lieu khong hop le.\n");
        return;
    }
    int *listFound = (int *)malloc(itemCount * sizeof(int));
    if (listFound == NULL) {
        printf("Loi bo nho!\n");
        return;
    }
    int foundCount = findByField(storeData, field, value, listFound);
    if (foundCount == 0) {
        printf("Khong tim thay mat hang trong kho.\n");
    } else {
        printFromIDList(storeData, listFound, foundCount);
    }
    free(listFound);
}

void handleFindItem(item *storeData) {
    char findBy[MAXSTRING];
    readString("Nhap cach tim mat hang (id/name/category/quantity): ", findBy, sizeof(findBy));

    if (strcmp(findBy, "id") == 0) {
        handleFindById(storeData);
    } else if (strcmp(findBy, "name") == 0) {
        handleFindByName(storeData);
    } else if (strcmp(findBy, "category") == 0) {
        handleFindByList(storeData, "category", "Nhap loai hang: ", checkCategoryValid);
    } else if (strcmp(findBy, "quantity") == 0) {
        handleFindByList(storeData, "quantity", "Nhap so luong: ", checkQuantityValid);
    } else {
        printf("Lua chon khong hop le!\n");
    }
}

void handleImportFile(item **storeDataPtr) {
    char fileName[MAXSTRING];
    readString("Nhap ten file txt: ", fileName, sizeof(fileName));
    int error = importFromFile(storeDataPtr, fileName);
    if (error == 0) {
        printf("Nhap file thanh cong.\n");
        alarm(*storeDataPtr);
    } else if (error == 1) {
        printf("File khong ton tai hoac khong the mo.\n");
    } else {
        printf("File co du lieu loi tai dong thu: %d\n", -error);
    }
}

void handleExportFile(item *storeData) {
    char fileName[MAXSTRING];
    readString("Nhap ten file txt: ", fileName, sizeof(fileName));
    exportToFile(storeData, fileName);
}

int main(void) {
    item *storeData = NULL;
    int choose = -1;

    while (choose != 0) {
        printf("---He thong quan ly kho hang---\n");
        printf("1. In ra danh sach hang trong kho\n"
               "2. Tra cuu thong tin hang\n"
               "3. Tang so luong hang\n"
               "4. Giam so luong hang\n"
               "5. Cap nhat thong tin hang\n"
               "6. Xoa thong tin hang\n"
               "7. Nhap thong tin tu file txt\n"
               "8. Xuat thong tin ra file txt\n"
               "0. Thoat\n");

        if (!readInt("Nhap lua chon cua ban: ", &choose)) {
            printf("Lua chon khong hop le!\n");
            waitEnter();
            clearScreen();
            continue;
        }

        switch (choose) {
            case 0: free(storeData); break;
            case 1: printAllItem(storeData); break;
            case 2: handleFindItem(storeData); break;
            case 3: handleAddQuantity(storeData); break;
            case 4: handleDecreaseQuantity(storeData); break;
            case 5: handleUpdateItem(storeData); break;
            case 6: handleDeleteItem(&storeData); break;
            case 7: handleImportFile(&storeData); break;
            case 8: handleExportFile(storeData); break;
            default: printf("Lua chon khong hop le! Vui long nhap lai.\n"); break;
        }

        if (choose != 0) waitEnter();
        clearScreen();
    }
    return 0;
}