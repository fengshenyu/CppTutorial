#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define true 1
#define false 0
#define MAX_SIZE 50

typedef int bool;
typedef struct {
    int key;
    char* name;
}EleType;
typedef struct BinarySortStruct{
    EleType data;
    struct BinarySortStruct* lChild;
    struct BinarySortStruct* rChild;
}BinarySort;

bool searchBinarySort(BinarySort* pCurrentRoot, int key, 
    BinarySort* pParent, BinarySort** ppResult) {
    if (pCurrentRoot == NULL) {
        *ppResult = pParent;
        return false;
    } else if (key == (pCurrentRoot->data).key) {
        *ppResult = pParent;
        return true;
    } else if (key < (pCurrentRoot->data).key){
        return searchBinarySort(pCurrentRoot->lChild, 
            key, pCurrentRoot, ppResult);
    } else {
        return searchBinarySort(pCurrentRoot->rChild, 
            key, pCurrentRoot, ppResult);
    }
}

bool insertBinarySort(BinarySort** ppBinarySort, EleType eleType) {
    BinarySort* pResult;
    if (searchBinarySort(*ppBinarySort, eleType.key, NULL, &pResult)) {
        return false;
    }
    BinarySort* pNew = (BinarySort*)malloc(sizeof(BinarySort));
    pNew->data = eleType;
    pNew->lChild = pNew->rChild = NULL;
    if (pResult == NULL) {
        *ppBinarySort = pNew;
    } else if (eleType.key < (pResult->data).key) {
        pResult->lChild = pNew;
    } else {
        pResult->rChild = pNew;
    }
    return true;
}

void prePrint(BinarySort* pBinarySort) {
    if (pBinarySort != NULL) {
        printf("num=%d,name=%s\n", (pBinarySort->data).key, (pBinarySort->data).name);
        prePrint(pBinarySort->lChild);
        prePrint(pBinarySort->rChild);
    }
}

void initData(EleType* pEle, char* line, char* delim) {
    int key = atoi(strtok(line, delim));
    char* lineName = strtok(NULL, delim);
    char* name = (char*)malloc(sizeof(char) * (strlen(lineName) + 1));
    *name = '\0';
    strcat(name, lineName);

    pEle->key = key;
    pEle->name = name;
}

void test() {
    BinarySort* root = NULL;
    char filename[] = 
        "D:\\Github\\CppTutorial\\C\\DS\\DataGenerator\\string.data"; 
    FILE *fp; 
    if((fp = fopen(filename, "r")) == NULL) { 
          printf("error!"); 
    } 
    while (!feof(fp)) { 
        char strLine[MAX_SIZE] = "";
        fgets(strLine, MAX_SIZE, fp);
        int last = strlen(strLine);
        if (last == 0) {
            continue;
        }
        if (strLine[last - 1] == '\n') {
            strLine[last - 1] = '\0';
        }
        EleType eleType;
        initData(&eleType, strLine, ",");
        insertBinarySort(&root, eleType);
    }
    fclose(fp);
    prePrint(root); 
}

int main() {
    test();
    return 0;
}