#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define true 1
#define false 0
#define LeftHigh 1
#define EqualHigh 0
#define RightHigh -1

typedef int bool;
typedef struct {
    int key;
    char* name;
}EleType;
typedef struct BalanceBinaryStruct{
    EleType data;
    int balance;
    struct BalanceBinaryStruct* lChild;
    struct BalanceBinaryStruct* rChild;
}BalanceBinary;

void rightRotate(BalanceBinary** currentRoot) {
    BalanceBinary* leftChild = (*currentRoot)->lChild;
    (*currentRoot)->lChild = leftChild->rChild;
    leftChild->rChild = *currentRoot;
    *currentRoot = leftChild;
}

void leftRotate(BalanceBinary** currentRoot) {
    BalanceBinary* rightChild = (*currentRoot)->rChild;
    (*currentRoot)->rChild = rightChild->lChild;
    rightChild->lChild = *currentRoot;
    *currentRoot = rightChild;
}

void leftBalance(BalanceBinary** root) {
    BalanceBinary* lChild =  (*root)->lChild;
    switch (lChild->balance) {
        case LeftHigh:
            (*root)->balance = lChild->balance = EqualHigh;
            rightRotate(root);
            break;
        case RightHigh: {
            BalanceBinary* rd = lChild->rChild;
            switch (rd->balance) {
                case LeftHigh:
                    (*root)->balance = RightHigh;
                    lChild->balance = EqualHigh;
                    break;
                case EqualHigh:
                    (*root)->balance = lChild->balance = EqualHigh;
                    break;
                case RightHigh:
                    (*root)->balance = EqualHigh;
                    lChild->balance = LeftHigh;
                    break;
            }
            rd->balance = EqualHigh;
            leftRotate(&((*root)->lChild));
            rightRotate(root);
        }
            break;
    }
}

void rightBalance(BalanceBinary** root) {
    BalanceBinary* rChild =  (*root)->rChild;
    switch (rChild->balance) {
        case RightHigh:
            (*root)->balance = rChild->balance = EqualHigh;
            leftRotate(root);
            break;
        case LeftHigh: {
            BalanceBinary* rd = rChild->lChild;
            switch (rd->balance) {
                case RightHigh:
                    (*root)->balance = LeftHigh;
                    rChild->balance = EqualHigh;
                    break;
                case EqualHigh:
                    (*root)->balance = rChild->balance = EqualHigh;
                    break;
                case LeftHigh:
                    (*root)->balance = EqualHigh;
                    rChild->balance = RightHigh;
                    break;
            }
            rd->balance = EqualHigh;
            rightRotate(&((*root)->rChild));
            leftRotate(root);
        }
            break;
    }
}

bool insertAVL(BalanceBinary** root, EleType eleType, bool* taller) {
    if (*root == NULL) {
        *root = (BalanceBinary*)malloc(sizeof(BalanceBinary));
        (*root)->lChild = NULL;
        (*root)->rChild = NULL;
        (*root)->data = eleType;
        (*root)->balance = EqualHigh;
        *taller = true;
    } else {
        if (eleType.key == ((*root)->data).key) {
            *taller = false;
            return false;
        }
        if (eleType.key < ((*root)->data).key) {
            if (!insertAVL(&((*root)->lChild), eleType, taller)) {
                return false;
            }
            if (*taller) {
                switch ((*root)->balance) {
                    case LeftHigh:
                        leftBalance(root);
                        *taller = false;
                        break;
                    case EqualHigh:
                        (*root)->balance = LeftHigh;
                        *taller = true;
                        break;
                    case RightHigh:
                        (*root)->balance = EqualHigh;
                        *taller = false;
                        break;
                }
            }
        } else {
            if (!insertAVL(&((*root)->rChild), eleType, taller)) {
                return false;
            }
            if (*taller) {
                switch ((*root)->balance) {
                    case LeftHigh:
                        (*root)->balance = EqualHigh;
                        *taller = false;
                        break;
                    case EqualHigh:
                        (*root)->balance = RightHigh;
                        *taller = true;
                        break;
                    case RightHigh:
                        rightBalance(root);
                        *taller = false;
                        break;
                }
            }
        }
    }
    return true;
}

void inPrint(BalanceBinary* pTree) {
    if (pTree != NULL) {
        inPrint(pTree->lChild);
        printf("key=%d,name=%s\n", (pTree->data).key, (pTree->data).name);
        inPrint(pTree->rChild);
    }
}

int main() {
    BalanceBinary* root = NULL;
    bool taller;

    EleType data0;
    data0.key = 10;
    data0.name = "name10";
    EleType data1;
    data1.key = 11;
    data1.name = "name11";
    EleType data2;
    data2.key = 5;
    data2.name = "name5";
    EleType data3;
    data3.key = 8;
    data3.name = "name8";
    EleType data4;
    data4.key = 7;
    data4.name = "name7";
    insertAVL(&root, data0, &taller);
    insertAVL(&root, data1, &taller);
    insertAVL(&root, data2, &taller);
    insertAVL(&root, data3, &taller);
    insertAVL(&root, data4, &taller);
    inPrint(root);
    return true;
}